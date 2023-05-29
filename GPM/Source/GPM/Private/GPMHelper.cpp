//------------------------------------------------------------------------------
//
// File: GPMHelper.cpp
// Module: GPM
// Version: 1.0
// Author: vincentwgao
//
//------------------------------------------------------------------------------
#include "GPMHelper.h"
#include "TGPAHelper.h"
#include "Kismet/KismetSystemLibrary.h"

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include "GPMAosNative.h"
#endif

#if PLATFORM_IOS
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "Misc/Paths.h"
#include "HAL/FileManager.h"
#include "GPMObserver.h"
#include "MyObserver.h"
#include "GPMApiInterfaceObject.h"
#endif
namespace GCloud
{
    namespace GPM
    {
        enum GameDataKey
        {
            OpenID = 0, // openid
            MainVersion = 1, // 游戏的主版本号
            SubVersion = 2, // 游戏的资源版本号
            TimeStamp = 3, // 时间戳, deprecated
            Scene = 4, // 游戏侧需要保障的游戏场景
            FPS = 5, // 游戏的FPS
            FrameMiss = 6, // 游戏丢帧数
            FPSTarget = 7, // 游戏的相应地图限制的最高帧率
            PictureQuality = 8, // 游戏的画面质量
            EffectQuality = 9, // 游戏的特效质量
            Resolution = 10, // 游戏的分辨率
            RoleCount = 11, // 游戏的同屏人数
            NetDelay = 12, // 游戏的网络延迟
            Recording = 13, // 录屏状态
            UrgentSignal = 14, // 紧急信号, deprecated
            ServerIP = 15, // 服务器IP
            RoleStatus = 16, // 角色状态
            SceneType = 40, // 场景类型, 标记游戏模式
            LoadTrunk = 41, // 局部地图加载
            BloomArea = 42, // 吃鸡模式的轰炸区标记
            MTR = 43, // 多核多线程渲染开启状态
            KillReport = 44, // 游戏的杀人数播报类型
            LightThreadTid = 50, // 游戏的轻负载线程
            HeavyThreadTid = 51, // 游戏的重负载线程
            RoleOutline = 52, // 角色描边状态
            PictureStyle = 53, // 画面风格，鲜艳、写实等
            AntiAliasing = 54, // 抗锯齿是否开启
            ServerPort = 55, // 服务器地址端口
            SocketType = 56, // 数据包类型
            Shadow = 57 // 阴影是否开启
        };

        const char* ValueKeyCoordinates = "##ValueKeyCoordinates##";

        const int TAPM_GEM = 1;
        const int TAPM_TGPA = 2;

        const char* GPMHelper::TUPLE_KEY = "#KEY#";
        const char* GPMHelper::TUPLE_VALUE = "#VALUE#";
        bool GPMHelper::bEnableGPM = false;
        GPMCallback *GPMHelper::sCallback = NULL;
#if PLATFORM_ANDROID
        // cache some methods, according to jni specification, jmethod can be cached
        static jmethodID gPostStepEventMethod = 0;
        static jmethodID gPostStreamEventMethod = 0;
        static jmethodID gPostInfoToTGPAIS = 0;
        static jmethodID gPostInfoToTGPASS = 0;
#endif

        typedef struct _deviceLevelContext
        {
            char* fileDirPath;
            char* configName;
            GPMCallback* callBack;

            _deviceLevelContext()
            {
                configName = NULL;
                fileDirPath = NULL;
                callBack = NULL;
            }
        }DeviceLevelContext;

        static void* device_level_thread(void* ptr)
        {
#if PLATFORM_IOS
            DeviceLevelContext* context = (DeviceLevelContext*)ptr;
            if (context != NULL)
            {
                int deviceLevel = gpm_checkDCLSByQccSync(context->fileDirPath, context->configName);

                if (context->fileDirPath != NULL)
                {
                    free((void*)context->fileDirPath);
                }

                if (context->configName != NULL)
                {
                    free((void*)context->configName);
                }

                if (context->callBack != NULL)
                {
                    context->callBack->OnDeviceLevel(deviceLevel);
                }

                delete context;
            }
#endif

            return NULL;
        }

        /* 获取SDK的版本信息 */
        const char* GPMHelper::GetSDKVersion()
        {
#if PLATFORM_ANDROID
            char* retValue = NULL;
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {

                jmethodID GetErrorMsgMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_getSDKVersion", "()Ljava/lang/String;", false);
                jobject jret = FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, GetErrorMsgMethod);

                if (jret != nullptr)
                {
                    jstring jstr = (jstring)jret;
                    const char *cstr = NULL;

                    jboolean isCopy;   // 返回JNI_TRUE表示原字符串的拷贝，返回JNI_FALSE表示返回原字符串的指针
                    cstr = Env->GetStringUTFChars(jstr, &isCopy);

                    if (cstr != NULL)
                    {
                        retValue = (char*)malloc(strlen(cstr) + 1);
                        strcpy(retValue, cstr);
                        Env->ReleaseStringUTFChars(jstr, cstr);
                    }
                }
            }
            return retValue;
#endif

#if PLATFORM_IOS
            return gpm_getSDKVersion();
#endif

            return NULL;
        }

        LogObserver GPMHelper::sLogObserver = nullptr;

        void GPMHelper::SetLogObserver(LogObserver logObserver) {
            sLogObserver = logObserver;
        }

        /*depreacted*/
        int GPMHelper::InitContext(const char *appId, const char* engine, bool debug)
        {
            return InitContext(appId, debug);
        }

        int GPMHelper::InitContext(const char *appId, bool debug,int disable)
        {
            if (GPMHelper::bEnableGPM)
            {
                return -1;
            }

            GCloud::TGPA::TGPAHelper::EnableLog(debug);
            GCloud::TGPA::TGPAHelper::Init();
            int retValue = -1;

#if PLATFORM_ANDROID

            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {
                FString engineVerison = UKismetSystemLibrary::GetEngineVersion();
                jstring jEngineVersion = Env->NewStringUTF(TCHAR_TO_UTF8(*engineVerison));
                jstring jNAPhrase = Env->NewStringUTF("NA");

                    jmethodID SetEngineInfoMethod = FJavaWrapper::FindMethod(Env,
                         FJavaWrapper::GameActivityClassID,
                         "AndroidThunkJava_setEngineMetaInfo",
                         "(ILjava/lang/String;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;IIII)V",
                         false);
                    FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, SetEngineInfoMethod, 2, jEngineVersion, 0,
                         jNAPhrase, jNAPhrase, jNAPhrase, 0, 0, 0, (!FAndroidMisc::ShouldUseVulkan())?1:0);
                         Env->DeleteLocalRef(jEngineVersion);
                         Env->DeleteLocalRef(jNAPhrase);

                jstring jAppID = Env->NewStringUTF(appId);
                jmethodID InitContextMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_initContext", "(Ljava/lang/String;Ljava/lang/String;ZI)I", false);
                retValue = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, InitContextMethod, jAppID, jAppID, debug,disable);
                Env->DeleteLocalRef(jAppID);

                GPMHelper::bEnableGPM = true;
            }
            else
            {
                UE_LOG(LogInit, Warning, TEXT("gpm_sdk ENV IS NULL"));
            }
#endif

#if PLATFORM_IOS
            FString engineVerison = UKismetSystemLibrary::GetEngineVersion();
			gpm_setEngineMetaInfo(2, TCHAR_TO_UTF8(*engineVerison), 0, "NA", "NA", "NA", 0, 0, 0, 1);

            retValue = gpm_initContext(appId, "unreal", debug,disable );
            GPMHelper::bEnableGPM = true;

            MyObserver *observer = MyObserver::GetInstance();

            gpm_setObserver(observer);

            //gpm_setObserver(observer);

           // GCloud::TGPA::TGPAHelper::Init();
#endif

#ifdef APM_WIN64
            PerfSight::PerfSightBridge::InitContext(appId, debug);
			GPMHelper::bEnableGPM = true;
#endif
            return retValue;
        }

        void GPMHelper::SyncServerTime(unsigned time){
#if PLATFORM_ANDROID
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {
                jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_syncServerTime", "(J)V", false);
                FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, (long)time);
            }
#endif
#if PLATFORM_IOS
            gpm_syncServerTime(time);
#endif

        }

        void GPMHelper::DisableDomCDNDomain(){
#if PLATFORM_ANDROID
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {
                jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_disableDomCDNDomain", "()V", false);
                FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
            }
#endif
#if PLATFORM_IOS
            gpm_blockDomesticCDNURL();
#endif
        }

        int GPMHelper::GetDiskStorageAvailableSizeInKiB()
        {
            if (!GPMHelper::bEnableGPM)
            {
                return -1;
            }

#if PLATFORM_ANDROID
            int retValue = -1;
                if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
                {
                    jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_getDiskStorageAvailableSizeInKiB", "()I", false);
                    retValue = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
                }
                return retValue;
#endif
#if PLATFORM_IOS
            return gpm_getAvailableDiskSize();
#endif

            return 0;
        }

        int GPMHelper::GetApmInfo(ApmInfoType type, bool useAPMCache)
        {
            if (!GPMHelper::bEnableGPM)
            {
                return -1;
            }
#if PLATFORM_ANDROID
            int retValue = -1;
			if (type == CpuTemperature) {
				retValue = tapmNativeGetCpuTemp(useAPMCache);
			}
			else {
				if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
				{
					jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_getApmInfo", "(IZ)I", false);
					retValue = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, type, useAPMCache);
				}
			}
			return retValue;
#endif
#if PLATFORM_IOS
            return gpm_getApmInfo(type, useAPMCache);
#endif
            return 0;
        }




        void GPMHelper::SetOpenId(const char* openId)
        {
            if(openId == nullptr) return;
            if (!GPMHelper::bEnableGPM)
            {
                return;
            }

#if PLATFORM_ANDROID
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {
                jstring jUserId = Env->NewStringUTF(openId);
                jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_setOpenId", "(Ljava/lang/String;)V", false);
                FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, jUserId);
                Env->DeleteLocalRef(jUserId);
            }
#endif

#if PLATFORM_IOS
            gpm_setOpenId(openId);
#endif

#ifdef APM_WIN64
            PerfSight::PerfSightBridge::SetOpenId(openId);
#endif
        }

        void GPMHelper::MarkLevelLoad(const char* levelName)
        {

            if (levelName == NULL) return;
            if (!GPMHelper::bEnableGPM)
            {
                return;
            }

#if PLATFORM_ANDROID
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {
                jstring jLevelName = Env->NewStringUTF(levelName);
                jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_markLevelLoad", "(Ljava/lang/String;)V", false);
                FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, jLevelName);
                Env->DeleteLocalRef(jLevelName);
            }
#endif

#if PLATFORM_IOS
            gpm_markLevelLoad(levelName);
#endif

#ifdef APM_WIN64
            PerfSight::PerfSightBridge::MarkLevelLoad(levelName);
#endif
        }

        void GPMHelper::MarkLevelLoadCompleted()
        {
            if (!GPMHelper::bEnableGPM)
            {
                return;
            }

#if PLATFORM_ANDROID
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {
                jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_markLevelLoadCompleted", "()V", false);
                FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
            }
#endif

#if PLATFORM_IOS
            gpm_markLevelLoadCompleted();

#endif

#ifdef APM_WIN64
            PerfSight::PerfSightBridge::MarkLevelLoadCompleted();
#endif
        }

        void GPMHelper::MarkLevelFin()
        {
            if (!GPMHelper::bEnableGPM)
            {
                return;
            }
#if PLATFORM_ANDROID
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {
                do {
                    FString gpu_model = FAndroidMisc::GetGPUFamily();
                    auto ConvertedStr = StringCast<ANSICHAR>(*gpu_model);
                    const char* cgpu_model = ConvertedStr.Get();

                    if (cgpu_model == NULL) break;

                    jmethodID saveGpuInfoMethodId = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_saveGpuInfo", "(Ljava/lang/String;)V", false);
                    if (saveGpuInfoMethodId == 0) break;

                    jstring jModel = Env->NewStringUTF(cgpu_model);
                    FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, saveGpuInfoMethodId, jModel);
                    Env->DeleteLocalRef(jModel);

                    jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_markLevelFin", "()V", false);

                    if (Method == 0) break;
                    FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
                } while (false);
            }
#endif


#if PLATFORM_IOS
            gpm_markLevelFin();
#endif

#ifdef APM_WIN64
            PerfSight::PerfSightBridge::MarkLevelFin();
#endif
        }

        void GPMHelper::PostNTL(int latency)
        {
            if (!GPMHelper::bEnableGPM)
            {
                return;
            }


#if PLATFORM_ANDROID
            tapmNativePostNTL(latency);
#endif

#if PLATFORM_IOS
            gpm_postNetLatency(latency);
#endif
#ifdef APM_WIN64
            PerfSight::PerfSightBridge::PostNetworkLatency(latency);
#endif
        }
        void GPMHelper::PostNetworkLatency(int latency){
            PostNTL(latency);
        }

        void GPMHelper::BeginExtTag(const char* tagName)
        {
            if (!GPMHelper::bEnableGPM)
            {
                return;
            }
            if (tagName == NULL) return;
#if PLATFORM_ANDROID
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {
                jstring jTagName = Env->NewStringUTF(tagName);
                jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_beginExtTag", "(Ljava/lang/String;)V", false);
                FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, jTagName);
                Env->DeleteLocalRef(jTagName);
            }
#endif

#if PLATFORM_IOS
            gpm_beginExtTag(tagName);
#endif
#ifdef APM_WIN64
            PerfSight::PerfSightBridge::BeginExtTag(tagName);
#endif
        }

        void GPMHelper::EndExtTag(const char* tagName)
        {
            if (!GPMHelper::bEnableGPM)
            {
                return;
            }
            if (tagName == NULL) return;

#if PLATFORM_ANDROID
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {
                jstring jTagName = Env->NewStringUTF(tagName);
                jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_endExtTag", "(Ljava/lang/String;)V", false);
                FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, jTagName);
                Env->DeleteLocalRef(jTagName);
            }
#endif

#if PLATFORM_IOS
            gpm_endExtTag(tagName);
#endif
#ifdef APM_WIN64
            PerfSight::PerfSightBridge::EndExtTag(tagName);
#endif

        }

        void GPMHelper::BeginTag(const char* tagName)
        {
            if (tagName == NULL) return;
            if (!GPMHelper::bEnableGPM)
            {
                return;
            }
#if PLATFORM_ANDROID
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {
                jstring jTagName = Env->NewStringUTF(tagName);
                jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_beginTag", "(Ljava/lang/String;)V", false);
                FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, jTagName);
                Env->DeleteLocalRef(jTagName);
            }
#endif

#if PLATFORM_IOS
            gpm_beginTag(tagName);
#endif
#ifdef APM_WIN64
            PerfSight::PerfSightBridge::BeginTag(tagName);
#endif
        }

        void GPMHelper::EndTag()
        {
            if (!GPMHelper::bEnableGPM)
            {
                return;
            }


#if PLATFORM_ANDROID
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {
                jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_endTag", "()V", false);
                FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
            }
#endif

#if PLATFORM_IOS
            gpm_endTag();
#endif
#ifdef APM_WIN64
            PerfSight::PerfSightBridge::EndTag();
#endif
        }

#if PLATFORM_IOS
        int GPMHelper::GetDeviceLevelByQcc(const char* configName, const char* filePath)
        {
            if (!GPMHelper::bEnableGPM)
            {
                return 0;
            }

            if (configName == NULL || filePath == NULL)
            {
                return 0;
            }
            FString contentPath = FString(filePath);
            FString fullPath = FPaths::ConvertRelativePathToFull(contentPath);
            FString diskPath = IFileManager::Get().GetFilenameOnDisk(*fullPath);
            FString absolutePath = IFileManager::Get().ConvertToAbsolutePathForExternalAppForRead(*diskPath);
            return gpm_checkDCLSByQcc(TCHAR_TO_UTF8(*absolutePath), configName);
        }

        int GPMHelper::GetDeviceLevelByString(const char* configName,const char* json)
        {
                if (!GPMHelper::bEnableGPM)
                {
                    return 0;
                }

                if (configName == NULL || json == NULL)
                {
                    return 0;
                }
                return gpm_checkDCLSByString(configName, json);
        }
#else

        int GPMHelper::GetDeviceLevelByString(const char* configName, const char* gpuFamily,const char* json)
        {
            if (!GPMHelper::bEnableGPM)
            {
                return 0;
            }

            if (configName == NULL || json == NULL || gpuFamily == NULL)
            {
                return 0;
            }
#if PLATFORM_ANDROID
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {
                jstring jConfigName = Env->NewStringUTF(configName);
                jstring jGpuFamily = Env->NewStringUTF(gpuFamily);
                jstring jJson = Env->NewStringUTF(json);
                jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_getDeviceLevelByString", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)I", false);
                int retValue = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, jConfigName, jGpuFamily, jJson);
                Env->DeleteLocalRef(jConfigName);
                Env->DeleteLocalRef(jGpuFamily);
                Env->DeleteLocalRef(jJson);

                return retValue;
            }
            else
            {
                return 0;
            }
#endif

            return 0;
        }


        int GPMHelper::GetDeviceLevelByQcc(const char* configName, const char* gpuFamily)
        {
            if (!GPMHelper::bEnableGPM)
            {
                return 0;
            }

            if (configName == NULL || gpuFamily == NULL)
            {
                return 0;
            }
#if PLATFORM_ANDROID
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {
                jstring jConfigName = Env->NewStringUTF(configName);
                jstring jGpuFamily = Env->NewStringUTF(gpuFamily);
                jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_getDeviceLevelByQcc", "(Ljava/lang/String;Ljava/lang/String;)I", false);
                int retValue = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, jConfigName, jGpuFamily);
                Env->DeleteLocalRef(jConfigName);
                Env->DeleteLocalRef(jGpuFamily);

                return retValue;
            }
            else
            {
                return 0;
            }
#endif

            return 0;
        }
#endif

        void GPMHelper::SetQuality(int quality)
        {
#if PLATFORM_ANDROID
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {
                jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_setQuality", "(I)V", false);
                FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, quality);
            }
#endif

#if PLATFORM_IOS
            //gpm_setQuality(quality);
            gpm_setQulaity(quality);
#endif

#ifdef APM_WIN64
            PerfSight::PerfSightBridge::SetQuality(quality);
#endif
        }

        void GPMHelper::PostEventSS(const char* key, const char* value)
        {
            if (key == NULL) return;

            if (value == NULL) return;

#if PLATFORM_ANDROID
            /*   if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
               {
                   jstring jKey = Env->NewStringUTF(key);
                    jstring jValue = Env->NewStringUTF(value);
                   jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_MarkLevelLoad", "(Ljava/lang/String;)V", false);
                   retValue = FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, jLevelName);
                   Env->DeleteLocalRef(jLevelName);
               }*/
#endif

#if PLATFORM_IOS
            //gpm_postEventSS(key, value);
#endif
        }

        void GPMHelper::PostEventIS(int key, const char* info)
        {
            if (info == NULL) return;
#if PLATFORM_ANDROID
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {
                jstring jeventkey = Env->NewStringUTF(info);
                jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_postMarkEvent", "(ILjava/lang/String;)V", false);
                FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, key, jeventkey);
                Env->DeleteLocalRef(jeventkey);
            }
#endif

#if PLATFORM_IOS
            gpm_postEventIS(key, info);
#endif

#ifdef APM_WIN64
            PerfSight::PerfSightBridge::PostEvent(key, info);
#endif
        }

        void GPMHelper::SetVersionIden(const char* versionName)
        {
            if (versionName == NULL) return;
#if PLATFORM_ANDROID
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {
                jstring jVersionName = Env->NewStringUTF(versionName);
                jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_setVersionIden", "(Ljava/lang/String;)V", false);
                FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, jVersionName);
                Env->DeleteLocalRef(jVersionName);
            }
#endif

#if PLATFORM_IOS
            gpm_setVersionIden(versionName);
#endif
        }

        void GPMHelper::PostFrame(float deltatime, unsigned int frameIdx)
        {
#if PLATFORM_ANDROID
            tapmNativePostFrame((int)(deltatime * 1000), frameIdx);
            tapmNativeGetCpuAffinity();
#endif

#if PLATFORM_IOS
            gpm_postFrame(deltatime, frameIdx);
#endif
//#ifdef APM_WIN64
//			PerfSight::PerfSightBridge::PostFrame(deltatime);
//#endif
        }

        void GPMHelper::PostCoordinates(float x, float y, float z, float pitch, float yaw, float roll)
        {
#if PLATFORM_ANDROID
            tapmNativePostCoordinate(x, y, z, pitch, yaw, roll);
#endif

#if PLATFORM_IOS
            gpm_postCoordinates(x, y, z, pitch, yaw, roll);
#endif
        }

        void GPMHelper::CheckPostValue()
        {
            bool ret = false;
#if PLATFORM_IOS
            ret = gpm_isKvMsgFull();
#elif PLATFORM_ANDROID
            ret = tapmNativeIsKvMsgFull();
#endif
            if (ret && sPostValueFullEvent)
            {
                sPostValueFullEvent();
            }
        }

        void GPMHelper::PostValueF(const char* category, const char* key, float a, unsigned int frameIdx)
        {
            if (category == NULL || key == NULL) return;
            CheckPostValue();
#if PLATFORM_ANDROID
            tapmNativePostVFloat(PARAM_TYPE_FLOAT,category, key, a, 0.0f, 0.0f, frameIdx);
#endif

#if PLATFORM_IOS
            gpm_postValueF1(category, key, a, frameIdx);
#endif

#ifdef APM_WIN64
            PerfSight::PerfSightBridge::PostValueF(category, key, a);
#endif
        }

        void GPMHelper::PostValueF(const char* category, const char* key, float a, float b, unsigned int frameIdx)
        {
            if (category == NULL || key == NULL) return;
            CheckPostValue();
#if PLATFORM_ANDROID
            tapmNativePostVFloat(PARAM_TYPE_FLOAT_FLOAT,category, key, a, b, 0.0f, frameIdx);
#endif


#if PLATFORM_IOS
            gpm_postValueF2(category, key, a, b, frameIdx);
#endif

#ifdef APM_WIN64
            PerfSight::PerfSightBridge::PostValueF(category, key, a, b);
#endif
        }


        void GPMHelper::PostValueF(const char* category, const char* key, float a, float b, float c, unsigned int frameIdx)
        {
            if (category == NULL || key == NULL) return;
            CheckPostValue();
#if PLATFORM_ANDROID

            tapmNativePostVFloat(PARAM_TYPE_FLOAT_FLOAT_FLOAT,category, key, a, b, c, frameIdx);

#endif

#if PLATFORM_IOS
            gpm_postValueF3(category, key, a, b, c, frameIdx);
#endif

#ifdef APM_WIN64
            PerfSight::PerfSightBridge::PostValueF(category, key, a, b, c);
#endif
        }

        void GPMHelper::PostValueI(const char* category, const char* key, int a, unsigned int frameIdx)
        {
            if (category == NULL || key == NULL) return;
            CheckPostValue();
#if PLATFORM_ANDROID

            tapmNativePostVInt(PARAM_TYPE_INT,category, key, a, 0 ,0, frameIdx);
#endif

#if PLATFORM_IOS
            gpm_postValueI1(category, key, a, frameIdx);
#endif

#ifdef APM_WIN64
            PerfSight::PerfSightBridge::PostValueI(category, key, a);
#endif
        }
        void GPMHelper::PostValueI(const char* category, const char* key, int a, int b, unsigned int frameIdx)
        {
            if (category == NULL || key == NULL) return;
            CheckPostValue();
#if PLATFORM_ANDROID

            tapmNativePostVInt(PARAM_TYPE_INT_INT,category, key, a, b, 0, frameIdx);
#endif

#if PLATFORM_IOS
            gpm_postValueI2(category, key, a, b, frameIdx);
#endif

#ifdef APM_WIN64
            PerfSight::PerfSightBridge::PostValueI(category, key, a, b);
#endif

        }
        void GPMHelper::PostValueI(const char* category, const char* key, int a, int b, int c, unsigned int frameIdx)
        {
            if (category == NULL || key == NULL) return;
            CheckPostValue();
#if PLATFORM_ANDROID
            tapmNativePostVInt(PARAM_TYPE_INT_INT_INT,category, key, a, b, c, frameIdx);
#endif

#if PLATFORM_IOS
            gpm_postValueI3(category, key, a, b, c, frameIdx);
#endif

#ifdef APM_WIN64
            PerfSight::PerfSightBridge::PostValueI(category, key, a, b, c);
#endif
        }

        void GPMHelper::PostValueS(const char* category, const char* key, const char* value, unsigned int frameIdx)
        {
            if (category == NULL || key == NULL) return;
            CheckPostValue();
#if PLATFORM_ANDROID
            tapmNativePostV1S(category, key, value, frameIdx);
#endif

#if PLATFORM_IOS
            gpm_postValueS(category, key, value, frameIdx);
#endif
#ifdef APM_WIN64
            PerfSight::PerfSightBridge::PostValueS(category, key, value);
#endif
        }

        void GPMHelper::PostValueCoordinate(const char *category, const char *key, float x, float y, float z, float pitch, float yaw, float roll, unsigned int frameIdx)
        {
            if (category == NULL || key == NULL) return;
            CheckPostValue();
#if PLATFORM_ANDROID
            tapmNativePostValueCoordinate(category, key, x, y, z, pitch, yaw, roll, frameIdx);
#endif

#if PLATFORM_IOS
            gpm_postValueCoordinate(category, key, x, y, z, pitch, yaw, roll, frameIdx);
#endif

        }

        bool GPMHelper::SetPostValueQueueLength(int length)
        {
#if PLATFORM_ANDROID
            return tapmNativeSetPostValueQueueLength(length);
#endif

#if PLATFORM_IOS
            return gpm_setPostValueQueueLength(length);
#endif
            return false;
        }


        void GPMHelper::BeginTupleWrap(const char* key)
        {
            if (key == NULL) return;
            CheckPostValue();
#if PLATFORM_ANDROID
            tapmNativeBeginTupleWrap(key);
#endif

#if PLATFORM_IOS
            gpm_beginTupleWrap(key);
#endif
#ifdef APM_WIN64
            PerfSight::PerfSightBridge::BeginTupleWrap(key);
#endif
        }
        void GPMHelper::EndTupleWrap()
        {
            CheckPostValue();
#if PLATFORM_ANDROID
            tapmNativeEndTupleWrap();
#endif

#if PLATFORM_IOS
            gpm_endTupleWrap();
#endif
#ifdef APM_WIN64
            PerfSight::PerfSightBridge::EndTupleWrap();
#endif
        }

        void GPMHelper::BeginExclude()
        {
#if PLATFORM_ANDROID

            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {
                jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_beginExclude", "()V", false);
                FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
            }

#endif

#if PLATFORM_IOS
            //gpm_beginExclude();
            gpm_beignExclude();
#endif
#ifdef APM_WIN64
            PerfSight::PerfSightBridge::BeginExclude();
#endif
        }
        void GPMHelper::EndExclude()
        {
#if PLATFORM_ANDROID

            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {
                jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_endExclude", "()V", false);
                FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
            }

#endif

#if PLATFORM_IOS
            gpm_endExclude();
#endif
#ifdef APM_WIN64
            PerfSight::PerfSightBridge::EndExclude();
#endif
        }

        void GPMHelper::SetAppVersion(const char *app_version) {
#ifdef APM_WIN64
            PerfSight::PerfSightBridge::SetAppVersion(app_version);
#endif
        }
        // 设置数据采集策略
        void GPMHelper::SetStrategy(PerfSight::Strategy& strategy) {
#ifdef APM_WIN64
            PerfSight::PerfSightBridge::SetStrategy(strategy);
#endif
        }
        // 设置数据上报域名
        void GPMHelper::SetServerUrl(const char *url) {
#ifdef APM_WIN64
            PerfSight::PerfSightBridge::SetServerUrl(url);
#endif
        }
        void GPMHelper::InitStepEventContext()
        {
#if PLATFORM_ANDROID
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {
                jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_initStepEventContext", "()V", false);
                FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
            }
#endif

#if PLATFORM_IOS
            gpm_initStepEventContext();
#endif
        }

        void GPMHelper::LinkLastStepEventSession(FString eventCategory)
        {
#if PLATFORM_ANDROID
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {
                jstring jEventCategory = Env->NewStringUTF(TCHAR_TO_UTF8(*eventCategory));
                jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_linkLastStepCategorySession", "(Ljava/lang/String;)V", false);
                FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, jEventCategory);
                Env->DeleteLocalRef(jEventCategory);
            }
#endif

#if PLATFORM_IOS
            gpm_linkSession(TCHAR_TO_UTF8(*eventCategory));
#endif
        }

        void GPMHelper::PostStepEvent(FString eventCategory, int stepId, int status, int code, FString msg, FString extraKey, bool authorize, bool finish)
        {
#if PLATFORM_ANDROID
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {
                if (gPostStepEventMethod == 0)
                {
                    gPostStepEventMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_postStepEvent", "(Ljava/lang/String;IIILjava/lang/String;Ljava/lang/String;ZZ)V", false);

                }

                if (gPostStepEventMethod == 0)
                {
                    return;
                }

                jstring jEventCategory = Env->NewStringUTF(TCHAR_TO_UTF8(*eventCategory));
                jstring jMsg = Env->NewStringUTF(TCHAR_TO_UTF8(*msg));
                jstring jExtraKey = Env->NewStringUTF(TCHAR_TO_UTF8(*extraKey));
                FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, gPostStepEventMethod, jEventCategory, stepId, status, code, jMsg, jExtraKey, authorize, finish);
                Env->DeleteLocalRef(jEventCategory);
                Env->DeleteLocalRef(jMsg);
                Env->DeleteLocalRef(jExtraKey);
            }
#endif

#if PLATFORM_IOS
            gpm_postStepEvent(TCHAR_TO_UTF8(*eventCategory), stepId, status, code, TCHAR_TO_UTF8(*msg), TCHAR_TO_UTF8(*extraKey), authorize, finish);

#endif
        }

        void GPMHelper::AddCustomParamsInStepEvent(FString eventCategory, const std::map<std::string, std::string> &eventInfo)
        {
#if PLATFORM_ANDROID
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv()) {
                jmethodID reportEventMethodId = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_AddCustomParamsInStepEvent", "(Ljava/lang/String;Ljava/util/Map;)V", false);

                int infoSize = eventInfo.size();
                jobject jEventInfo = nullptr;
                if (infoSize) {
                    jmethodID createMapMethodId = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_createMap", "(I)Ljava/util/Map;", false);
                    jEventInfo = FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, createMapMethodId, infoSize);
                    jclass mapClassId = FJavaWrapper::FindClass(Env, "java/util/Map", false);
                    jmethodID putMethodId = FJavaWrapper::FindMethod(Env, mapClassId, "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", false);
                    for (std::map<std::string, std::string>::const_iterator it = eventInfo.begin(); it != eventInfo.end(); ++it) {
                        jstring jKey = Env->NewStringUTF(it->first.c_str());
                        jstring jValue = Env->NewStringUTF(it->second.c_str());
                        FJavaWrapper::CallObjectMethod(Env, jEventInfo, putMethodId, jKey, jValue);
                        Env->DeleteLocalRef(jKey);
                        Env->DeleteLocalRef(jValue);
                    }
                }

                jstring jEventCategory = Env->NewStringUTF(TCHAR_TO_UTF8(*eventCategory));
                FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, reportEventMethodId, jEventCategory, jEventInfo);
                Env->DeleteLocalRef(jEventInfo);
                Env->DeleteLocalRef(jEventCategory);
            }
#elif PLATFORM_IOS
            std::string jsonString = "{";
            for (std::map<std::string, std::string>::const_iterator it = eventInfo.begin(); it != eventInfo.end(); ++it) {
                jsonString.append("\"");
                jsonString.append(it->first);
                jsonString.append("\":\"");
                jsonString.append(it->second);
                jsonString.append("\",");
            }
            if (jsonString.size() > 1) {
                jsonString.pop_back();
            }
            jsonString.append("}");
            gpm_addCustomParamsInStepEvent(TCHAR_TO_UTF8(*eventCategory), jsonString.c_str());
#endif
        }

        void GPMHelper::AddCustomParamsInGame(const std::map<std::string, std::string> &eventInfo)
        {
#if PLATFORM_ANDROID
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv()) {
                jmethodID reportEventMethodId = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_AddCustomParamsInGame", "(Ljava/util/Map;)V", false);

                int infoSize = eventInfo.size();
                jobject jEventInfo = nullptr;
                if (infoSize) {
                    jmethodID createMapMethodId = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_createMap", "(I)Ljava/util/Map;", false);
                    jEventInfo = FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, createMapMethodId, infoSize);
                    jclass mapClassId = FJavaWrapper::FindClass(Env, "java/util/Map", false);
                    jmethodID putMethodId = FJavaWrapper::FindMethod(Env, mapClassId, "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", false);
                    for (std::map<std::string, std::string>::const_iterator it = eventInfo.begin(); it != eventInfo.end(); ++it) {
                        jstring jKey = Env->NewStringUTF(it->first.c_str());
                        jstring jValue = Env->NewStringUTF(it->second.c_str());
                        FJavaWrapper::CallObjectMethod(Env, jEventInfo, putMethodId, jKey, jValue);
                        Env->DeleteLocalRef(jKey);
                        Env->DeleteLocalRef(jValue);
                    }
                }

                FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, reportEventMethodId, jEventInfo);
                Env->DeleteLocalRef(jEventInfo);
            }
#elif PLATFORM_IOS
            std::string jsonString = "{";
            for (std::map<std::string, std::string>::const_iterator it = eventInfo.begin(); it != eventInfo.end(); ++it) {
                jsonString.append("\"");
                jsonString.append(it->first);
                jsonString.append("\":\"");
                jsonString.append(it->second);
                jsonString.append("\",");
            }
            if (jsonString.size() > 1) {
                jsonString.pop_back();
            }
            jsonString.append("}");
            gpm_addCustomParamsInGame(jsonString.c_str());
#endif
        }

        void GPMHelper::ReleaseStepEventContext()
        {
#if PLATFORM_ANDROID
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {
                jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_releaseStepEventContext", "()V", false);
                FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
            }
#endif

#if PLATFORM_IOS
            gpm_releaseStepEventContext();
#endif

        }

        void GPMHelper::MarkAppFinishLaunch(){}

        void GPMHelper::SetTragetFrameRate(int target){}

        void GPMHelper::SetTargetFramerate(int target){
#if PLATFORM_ANDROID
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {
                jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_setTargetFramerate", "(I)V", false);
                FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, target);
            }
#endif

#if PLATFORM_IOS
            gpm_setTargetFramerate(target);
#endif
        }

        void GPMHelper::SetDeviceLevel(int level)
        {
#if PLATFORM_ANDROID
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {
                jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_setDeviceLevel", "(I)V", false);
                FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, level);
            }
#endif

#if PLATFORM_IOS
            gpm_setDefinedDeviceClass(level);
#endif
#ifdef APM_WIN64
            PerfSight::PerfSightBridge::SetDefinedDeviceClass(level);
#endif
        }

        void GPMHelper::SetMatchId(const char* matchId) {
#if PLATFORM_ANDROID
            tapmNativeSetMatchId(matchId);
#endif

#if PLATFORM_IOS
            gpm_setMatchId(matchId);
#endif
        }

        void GPMHelper::SetCustomizedDeviceID(const char* deviceId) {
#if PLATFORM_ANDROID
            tapmNativeSetCustomizedDeviceID(deviceId);
#endif

#if PLATFORM_IOS
            gpm_setCustomizedDeviceID(deviceId);
#endif
        }


        const char* GPMHelper::GetSDKDefinedDeviceID()
        {
#if PLATFORM_ANDROID
            char* retValue = NULL;
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {

                jmethodID GetErrorMsgMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_getSDKDefinedDeviceID", "()Ljava/lang/String;", false);
                jobject jret = FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, GetErrorMsgMethod);

                if (jret != nullptr)
                {
                    jstring jstr = (jstring)jret;
                    const char *cstr = NULL;

                    jboolean isCopy;   // 返回JNI_TRUE表示原字符串的拷贝，返回JNI_FALSE表示返回原字符串的指针
                    cstr = Env->GetStringUTFChars(jstr, &isCopy);

                    if (cstr != NULL)
                    {
                        retValue = (char*)malloc(strlen(cstr) + 1);
                        strcpy(retValue, cstr);
                        Env->ReleaseStringUTFChars(jstr, cstr);
                    }
                }
            }
            return retValue;
#endif

#if PLATFORM_IOS
            return gpm_getSDKDefinedDeviceID();
#endif

            return NULL;
        }

        void GPMHelper::AddTraceThread(const char* threadName)
        {
            if(threadName == nullptr) {
                return;
            }
#if PLATFORM_ANDROID
            tapmNativeAddTraceThread(threadName);
#endif
        }

        PostValueFullCallBack GPMHelper::sPostValueFullEvent = nullptr;

        void GPMHelper::SetPostValueFullCallBack(PostValueFullCallBack callback)
        {
            sPostValueFullEvent = callback;
        }

        void GPMHelper::RemoveTraceThread(const char* threadName)
        {
            if(threadName == nullptr) {
                return;
            }
#if PLATFORM_ANDROID
            tapmNativeRemoveTraceThread(threadName);
#endif
        }

        void GPMHelper::MarkStartUpFinish()
        {
#if PLATFORM_ANDROID
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {
                jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_markStarUpFinish", "()V", false);
                FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
            }
#endif

#if PLATFORM_IOS
            gpm_startUpFinish();
#endif
        }


        char* GPMHelper::GetErrorMsg(int code)
        {
#if PLATFORM_ANDROID
            char* retValue = NULL;
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {

                jmethodID GetErrorMsgMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_getErrorMsg", "(I)Ljava/lang/String;", false);
                jobject jret = FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, GetErrorMsgMethod, code);

                if (jret != nullptr)
                {
                    jstring jstr = (jstring)jret;
                    const char *cstr = NULL;

                    jboolean isCopy;   // 返回JNI_TRUE表示原字符串的拷贝，返回JNI_FALSE表示返回原字符串的指针
                    cstr = Env->GetStringUTFChars(jstr, &isCopy);

                    if (cstr != NULL)
                    {
                        retValue = (char*)malloc(strlen(cstr) + 1);
                        strcpy(retValue, cstr);
                        Env->ReleaseStringUTFChars(jstr, cstr);
                    }
                }
            }
            return retValue;
#elif PLATFORM_IOS
            return (char*)gpm_getErrorMsg(code);
#else
            return NULL;
#endif

        }


        void GPMHelper::detectInTimeout() {

#if PLATFORM_ANDROID
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {
                jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_detectInTimeout", "()V", false);
                FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
            }

#endif

#if PLATFORM_IOS
            gpm_detectInTimeout();
#endif

        }

        void GPMHelper::StartTCPDetect()
        {
#if PLATFORM_ANDROID


#endif

#if PLATFORM_IOS

#endif

        }

        const char* GPMHelper::StartUDPDetect()
        {
#if PLATFORM_ANDROID

#endif

#if PLATFORM_IOS

#endif

            return NULL;
        }

        void GPMHelper::SetServerInfo(const char* zoneId, const char* roomIp)
        {
#if PLATFORM_ANDROID
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
            {
                jstring jZone = Env->NewStringUTF(zoneId);
                jstring jRoomIp = Env->NewStringUTF(roomIp);
                jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_setServerInfo", "(Ljava/lang/String;Ljava/lang/String;)V", false);
                FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, jZone, jRoomIp);
                Env->DeleteLocalRef(jZone);
                Env->DeleteLocalRef(jRoomIp);
            }

#endif

#if PLATFORM_IOS
            gpm_setServerInfo(zoneId, roomIp);
#endif
        }

        void GPMHelper::PostMarkEvent(int key, const char* value)
        {
#if PLATFORM_ANDROID

#endif

#if PLATFORM_IOS

#endif

        }

        void GPMHelper::ReportEvent(const std::string &eventName, const std::map<std::string, std::string> &eventInfo) {
#if PLATFORM_ANDROID
            if (JNIEnv* Env = FAndroidApplication::GetJavaEnv()) {
                jmethodID reportEventMethodId = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_postEvent", "(Ljava/lang/String;Ljava/util/Map;)V", false);
                jstring jEventName = Env->NewStringUTF(eventName.c_str());

                int infoSize = eventInfo.size();
                jobject jEventInfo = nullptr;
                if (infoSize) {
                    jmethodID createMapMethodId = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_createMap", "(I)Ljava/util/Map;", false);
                    jEventInfo = FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, createMapMethodId, infoSize);
                    jclass mapClassId = FJavaWrapper::FindClass(Env, "java/util/Map", false);
                    jmethodID putMethodId = FJavaWrapper::FindMethod(Env, mapClassId, "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", false);
                    for (std::map<std::string, std::string>::const_iterator it = eventInfo.begin(); it != eventInfo.end(); ++it) {
                        jstring jKey = Env->NewStringUTF(it->first.c_str());
                        jstring jValue = Env->NewStringUTF(it->second.c_str());
                        FJavaWrapper::CallObjectMethod(Env, jEventInfo, putMethodId, jKey, jValue);
                        Env->DeleteLocalRef(jKey);
                        Env->DeleteLocalRef(jValue);
                    }
                }

                FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, reportEventMethodId, jEventName, jEventInfo);
                Env->DeleteLocalRef(jEventName);
                Env->DeleteLocalRef(jEventInfo);
            }
#elif PLATFORM_IOS
            std::string jsonString = "{";
            for (std::map<std::string, std::string>::const_iterator it = eventInfo.begin(); it != eventInfo.end(); ++it) {
                jsonString.append("\"");
                jsonString.append(it->first);
                jsonString.append("\":\"");
                jsonString.append(it->second);
                jsonString.append("\",");
            }
            if (jsonString.size() > 1) {
                jsonString.pop_back();
            }
            jsonString.append("}");
            gpm_postEventSS(eventName.c_str(), jsonString.c_str());
#endif
        }

        void GPMHelper::UpdateGameFps(float value) {
            GCloud::TGPA::TGPAHelper::UpdateGameFps(value);
        }

        void GPMHelper::UpdateGameInfo(int key, int value) {
            GCloud::TGPA::TGPAHelper::UpdateGameInfo(key, value);
        }

        void GPMHelper::UpdateGameInfo(int key, FString value) {
            GCloud::TGPA::TGPAHelper::UpdateGameInfo(key, value);
        }

        void GPMHelper::UpdateGameInfo(FString key, FString value) {
            GCloud::TGPA::TGPAHelper::UpdateGameInfo(key, value);
        }

        void GPMHelper::UpdateGameInfo(FString key, TMap<FString, FString> mapData) {
            GCloud::TGPA::TGPAHelper::UpdateGameInfo(key, mapData);
        }

        FString GPMHelper::GetOptCfgStr() {
            return GCloud::TGPA::TGPAHelper::GetOptCfgStr();
            //return FString(TEXT("-1"));
        }

        FString GPMHelper::CheckDeviceIsReal() {
            return GCloud::TGPA::TGPAHelper::CheckDeviceIsReal();
            //return FString(TEXT("-1"));
        }

        FString GPMHelper::GetDataFromTGPA(FString key, FString value) {
            return GCloud::TGPA::TGPAHelper::GetDataFromTGPA(key, value);
            //return FString(TEXT("-1"));
        }
    }
}



#if PLATFORM_ANDROID
#include <android/log.h>

//ENGINE_API DECLARE_LOG_CATEGORY_EXTERN(TRILOGGER, Log, All);

JNI_METHOD void Java_com_perfsight_gpm_jni_GPMNativeHelper_GPMOnLog(JNIEnv* LocalJNIEnv, jclass LocalThiz, jstring data)
{

    UE_LOG(LogTemp, Log, TEXT("Java call UE4 to log"));

    const char *rspInfoCStr = LocalJNIEnv->GetStringUTFChars(data, NULL);

    UE_LOG(LogTemp, Log, TEXT("Java call UE4 to log: %s"), UTF8_TO_TCHAR(rspInfoCStr));

    std::string rspInfoStr = std::string(rspInfoCStr);
    if (GCloud::GPM::GPMHelper::sLogObserver) {
        GCloud::GPM::GPMHelper::sLogObserver(rspInfoStr.c_str());
    }
    LocalJNIEnv->ReleaseStringUTFChars(data, rspInfoCStr);


}

JNI_METHOD void Java_com_perfsight_gpm_jni_GPMNativeHelper_GPMOnFpsNotify(JNIEnv* LocalJNIEnv, jclass LocalThiz, jstring data)
{
    UE_LOG(LogTemp, Log, TEXT("Java call UE4 to log"));

    const char *rspInfoCStr = LocalJNIEnv->GetStringUTFChars(data, NULL);

    UE_LOG(LogTemp, Log, TEXT("Java call UE4 to log: %s"), UTF8_TO_TCHAR(rspInfoCStr));

    LocalJNIEnv->ReleaseStringUTFChars(data, rspInfoCStr);
    // TODO: start UE4 fps
}

JNI_METHOD void Java_com_perfsight_gpm_jni_GPMNativeHelper_GPMOnMarkLevelLoad(JNIEnv* LocalJNIEnv, jclass LocalThiz, jstring data)
{
    //__android_log_print(ANDROID_LOG_ERROR, "[gpm] Java_com_perfsight_gpm_jni_GPMNativeHelper_GPMOnMarkLevelLoad: ", "empty");
}


JNI_METHOD void Java_com_perfsight_gpm_jni_GPMNativeHelper_GPMOnSetQuality(JNIEnv* LocalJNIEnv, jclass LocalThiz, jstring data)
{
    //_android_log_print(ANDROID_LOG_ERROR, "[gpm] Java_com_perfsight_gpm_jni_GPMNativeHelper_GPMOnSetQuality: ", "empty");
}

#endif



#ifdef PLATFORM_IOS

#if defined(__cplusplus)
extern "C" {
#endif
    
unsigned long il2cpp_gc_get_heap_size(){
    return 0;
}


unsigned long il2cpp_gc_get_used_size(){
    return 0;
}
    
#if defined(__cplusplus)
}
#endif

#endif

