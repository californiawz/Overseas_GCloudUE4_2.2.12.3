#include "TGPAServiceAndroid.h"
#include "Android/AndroidApplication.h"
#include "Android/AndroidJava.h"
#include "Runtime/Launch/Public/Android/AndroidJNI.h"

ITGPACallback* TGPAServiceAndroid::sTGPACallback = nullptr;

TGPAServiceAndroid::TGPAServiceAndroid()
    : FJavaClassObject(TGPAServiceAndroid::GetPerformanceAjusterClassName(), "()V")
    , EnableLogMethod(GetClassMethod("setLogAble", "(Z)V"))
    , EnableDebugModeMethod(GetClassMethod("enableDebugMode", "()V"))
    , InitMethod(GetClassMethod("initForUE4", "()V"))
    , RegisterCallbackMethod(GetClassMethod("registerCallback", "()V"))
    , UpdateGameInfoISMethod(GetClassMethod("updateGameInfo", "(ILjava/lang/String;)V"))
    , UpdateGameInfoIIMethod(GetClassMethod("updateGameInfo", "(II)V")) 
    , UpdateGameInfoIFArrayMethod(GetClassMethod("updateGameInfo", "(I[F)V"))
    , UpdateGameInfoSSMethod(GetClassMethod("updateGameInfo", "(Ljava/lang/String;Ljava/lang/String;)V"))
    , GetDataFromTGPAMethod(GetClassMethod("getDataFromTGPA", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;"))
    , HapticSupportMethod(GetClassMethod("hapticSupport", "()I"))
    , HapticAmplitudeSupportMethod(GetClassMethod("hapticAmplitudeSupport", "()I"))
    , HapticPlayMethod(GetClassMethod("hapticPlay", "(Ljava/lang/String;III)V"))
    , hapticPlayWithFileMethod(GetClassMethod("hapticPlayWithFile", "(Ljava/lang/String;III)V"))
    , hapticStopMethod(GetClassMethod("hapticStop", "()V"))
    {}
    

void TGPAServiceAndroid::EnableLog(bool enable) 
{
    JNIEnableLog(enable);
}

void TGPAServiceAndroid::EnableDebugMode() 
{
    JNIEnableDebugMode();
}

void TGPAServiceAndroid::Init() {
    JNIInit();
}

void TGPAServiceAndroid::RegisterCallback(ITGPACallback *callback) 
{
    TGPAServiceAndroid::sTGPACallback = callback;
    JNIRegisterCallback();
}

void TGPAServiceAndroid::UpdateGameFps (float value)
{
    if (CheckGameFps (value))
    {
        JNIUpdateGameInfoII(FPS, (int)value);
    }
    fpsArr[fpsCount] = value;
    fpsCount += 1;
    if (fpsCount == 5)
    {
        JNIUpdateGameInfoIF(FPS, fpsArr);
        fpsCount = 0;
    }
}

void TGPAServiceAndroid::UpdateGameInfo(const int key, const FString& value) 
{
    JNIUpdateGameInfoIS(key, value);
}

void TGPAServiceAndroid::UpdateGameInfo(const int key, const int value) 
{
    JNIUpdateGameInfoII(key, value);
}

void TGPAServiceAndroid::UpdateGameInfo(const FString& key, const FString& value) 
{
    JNIUpdateGameInfoSS(key, value);
}

void TGPAServiceAndroid::UpdateGameInfo(const FString& key, const TMap<FString, FString>& mapData) 
{
    JNIUpdateGameInfoSS(key, ConvertTMap2JsonStr(mapData));
}

FString TGPAServiceAndroid::GetOptCfgStr() 
{
    return GetDataFromTGPA("GetOptCfg", "");
}

FString TGPAServiceAndroid::CheckDeviceIsReal() {
    return GetDataFromTGPA("CheckDevice", "");
}

FString TGPAServiceAndroid::GetDataFromTGPA(const FString& key, const FString& value) 
{
    return JNIGetDataFromTGPA(key, value);
}

int TGPAServiceAndroid::CheckHapticPlayerSupport(HapticPlayerType playerType) {
    int status = JNIHapticSupport();
    if (playerType == AndroidPatternPlayer) 
    {
        if (status == 3 || status == 1) {
            return 1;
        } else if (status == -1) {
            return -1;
        }
        return 0;
    } else if (playerType == StandardHapticPlayer) {
        if (status == 1) {
            return 1;
        } else if (status == -1) {
            return -1;
        }
        return 0;
    }
    return 0;
}

int TGPAServiceAndroid::CheckHapticAmplitudeSupport() {
    return JNIHapticAmplitudeSupport();
}

void TGPAServiceAndroid::SetCurrentHapticPlayerType(HapticPlayerType playerType) {
    if (playerType == AndroidPatternPlayer) {
        UpdateGameInfo("UseNonRichTap", "1");
    } else {
        UpdateGameInfo("UseNonRichTap", "0");
    }
}

void TGPAServiceAndroid::HapticPlay(const FString& heJson, int loop, int interval, int amplitude) {
    JNIHapticPlay(heJson, loop, interval, amplitude);
}

void TGPAServiceAndroid::HapticPlayWithFile(const FString& heFilePath, int loop, int interval, int amplitude) {
    JNIHapticPlayWithFile(heFilePath, loop, interval, amplitude);
}

void TGPAServiceAndroid::HapticStop() {
    JNIHapticStop();
}

FName TGPAServiceAndroid::GetPerformanceAjusterClassName() 
{
    if (FAndroidMisc::GetAndroidBuildVersion() >= 1) {
        return FName("com.ihoc.mgpa.MgpaManager");
    } else {
        return FName("");
    }
}

void TGPAServiceAndroid::JNIEnableLog(bool enable)
{
    CallMethod<void>(EnableLogMethod, enable);
}

void TGPAServiceAndroid::JNIEnableDebugMode()
{
    CallMethod<void>(EnableDebugModeMethod);
}

void TGPAServiceAndroid::JNIInit()
{
    CallMethod<void>(InitMethod, FJavaWrapper::GameActivityThis);
}

void TGPAServiceAndroid::JNIRegisterCallback()
{
    CallMethod<void>(RegisterCallbackMethod);
}

void TGPAServiceAndroid::JNIUpdateGameInfoII(const int key, const int value)
{
    CallMethod<void>(UpdateGameInfoIIMethod, key, value);
}

void TGPAServiceAndroid::JNIUpdateGameInfoIF(const int key, float* value)
{
    if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
    {
        jfloatArray fpsArray = Env->NewFloatArray(SIZE);

        if (fpsArray != NULL)  
        {
            float buff[SIZE];
            for (int i = 0; i < SIZE; i++)  
            {  
                buff[i] = value[i];
            }
            Env->SetFloatArrayRegion(fpsArray, 0, SIZE , buff);
            CallMethod<void>(UpdateGameInfoIFArrayMethod, FPS, fpsArray);
            Env->DeleteLocalRef(fpsArray);
        }
    }
}

void TGPAServiceAndroid::JNIUpdateGameInfoIS(const int key, const FString& value)
{
    if (JNIEnv* Env = FAndroidApplication::GetJavaEnv()) {
        jstring localValue = Env->NewStringUTF(TCHAR_TO_UTF8(*value));
        CallMethod<void>(UpdateGameInfoISMethod, key, localValue);
        Env->DeleteLocalRef(localValue);
    }
}

void TGPAServiceAndroid::JNIUpdateGameInfoSS(const FString& key, const FString& value)
{
    if (JNIEnv* Env = FAndroidApplication::GetJavaEnv()) {
        jstring localKey = Env->NewStringUTF(TCHAR_TO_UTF8(*key));
        jstring localValue = Env->NewStringUTF(TCHAR_TO_UTF8(*value));
        CallMethod<void>(UpdateGameInfoSSMethod, localKey, localValue);
        Env->DeleteLocalRef(localKey);
        Env->DeleteLocalRef(localValue);
    }
}

FString TGPAServiceAndroid::JNIGetDataFromTGPA(const FString& key, const FString& value) 
{
    FString ret = FString(TEXT("-1"));
    if (JNIEnv* Env = FAndroidApplication::GetJavaEnv()) {
        jstring localKey = Env->NewStringUTF(TCHAR_TO_UTF8(*key));
        jstring localValue = Env->NewStringUTF(TCHAR_TO_UTF8(*value));
        ret = CallMethod<FString>(GetDataFromTGPAMethod, localKey, localValue);
        Env->DeleteLocalRef(localKey);
        Env->DeleteLocalRef(localValue);
    }
    return ret;
}

int TGPAServiceAndroid::JNIHapticSupport() {
    return CallMethod<int>(HapticSupportMethod);
}

int TGPAServiceAndroid::JNIHapticAmplitudeSupport() {
    return CallMethod<int>(HapticAmplitudeSupportMethod);
}

void TGPAServiceAndroid::JNIHapticPlay(const FString& heJson, int loop, int interval, int amplitude) {
    if (JNIEnv* Env = FAndroidApplication::GetJavaEnv()) {
        jstring localValue = Env->NewStringUTF(TCHAR_TO_UTF8(*heJson));
        CallMethod<void>(HapticPlayMethod, localValue, loop, interval, amplitude);
        Env->DeleteLocalRef(localValue);
    }
}

void TGPAServiceAndroid::JNIHapticPlayWithFile(const FString& heFilePath, int loop, int interval, int amplitude) {
    if (JNIEnv* Env = FAndroidApplication::GetJavaEnv()) {
        jstring localValue = Env->NewStringUTF(TCHAR_TO_UTF8(*heFilePath));
        CallMethod<void>(hapticPlayWithFileMethod, localValue, loop, interval, amplitude);
        Env->DeleteLocalRef(localValue);
    }
}

void TGPAServiceAndroid::JNIHapticStop() {
    CallMethod<void>(hapticStopMethod);
}

FString TGPAServiceAndroid::ConvertTMap2JsonStr (const TMap<FString, FString>& mapData)
{
    FString result = FString(TEXT("{"));
    for (const TPair<FString, FString>& element : mapData)
    {
        result += FString::Printf(TEXT("\"%s\":\"%s\","), *element.Key, *element.Value);
    }
    result.RemoveFromEnd(FString(TEXT(",")), ESearchCase::IgnoreCase);
    return FString::Printf(TEXT("%s}"), *result);
}

// 帧率上下波动超过3帧，就通知给厂商
bool TGPAServiceAndroid::CheckGameFps (float fps)
{
    bool result = false;
    if ((fps - lastFps > 3) || (fps - lastFps < -3))
    {
        result = true;
    }
    lastFps = fps;
    return result;
}



#if PLATFORM_ANDROID
#include <android/log.h>
// JNI_METHOD
// extern "C"
JNI_METHOD void Java_com_ihoc_mgpa_MgpaManager_nativeNotifySystemInfo(JNIEnv *LocalJNIEnv, jobject LocalThiz, jstring retJson) 
{
    if (TGPAServiceAndroid::sTGPACallback == nullptr) {
        __android_log_print(ANDROID_LOG_WARN, "TGPA NotifySystemInfo: ", "nullptr");
        return;
    }
    jboolean result;
    const char *json = LocalJNIEnv->GetStringUTFChars(retJson, &result);
    if (json == NULL) {
        __android_log_print(ANDROID_LOG_WARN, "TGPA NotifySystemInfo: ", "json is null!");
        return;
    }
    TGPAServiceAndroid::sTGPACallback->notifySystemInfo(ANSI_TO_TCHAR(json));
    LocalJNIEnv->ReleaseStringUTFChars(retJson, json);
}
#endif
