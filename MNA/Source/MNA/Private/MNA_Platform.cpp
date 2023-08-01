#include "MNA_Platform.h"

#include "CoreMinimal.h"
#include "Engine.h"
#include "MNAMessageCenter.h"
#include "MNAUtils.h"
#include "Modules/ModuleManager.h"
#include "MNAExportCAPI.h"

#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidPlatform.h"
#endif

#if PLATFORM_IOS
#include "MyMNAObserver.h"
#include <MNA/MNAPublic.h>
#endif

bool MNA_Platform::isFirstSetObserver = true;
bool MNA_Platform::isInit = false;
SpeedObserver MNA_Platform::sSpeedObserver = nullptr;
KartinObserver MNA_Platform::sKartinObserver = nullptr;
BatteryObserver MNA_Platform::sBatteryObserver = nullptr;
QueryPreciseKartinObserver MNA_Platform::sQueryPreciseKartinObserver = nullptr;
GetIpGroupDelaysObserver MNA_Platform::sGetIpGroupDelaysObserver = nullptr;
GetIpGroupDelaysObserver MNA_Platform::sGetIpGroupDelaysTCPObserver = nullptr;
GetIpGroupDelaysObserver MNA_Platform::sGetIpGroupDelaysWithBindingObserver = nullptr;
MNAPingObserver MNA_Platform::sMNAPingObserver = nullptr;
QueryConnectionInfoObserver MNA_Platform::sQueryConnectionInfoObserver = nullptr;



void MNA_Platform::MNA_SetControlDomain(std::string controlDomain, int controlPort)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID SetControlDomainMethod =
          FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID,
                                   "MNA_SetControlDomain", "(Ljava/lang/String;I)V", false);
      jstring jcontrolDomain = Env->NewStringUTF(controlDomain.c_str());
      FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,
                                   SetControlDomainMethod, jcontrolDomain, controlPort);
      Env->DeleteLocalRef(jcontrolDomain);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    plat->MNASetControlDomain(controlDomain.c_str(), controlPort);
#endif
}

void MNA_Platform::MNA_Init(std::string qqappid, bool debug, int zoneid,
                            ReportChannelType reportChannelType)
{
    MNA_Init(qqappid, debug, zoneid, true, false, reportChannelType, "");
}

void MNA_Platform::MNA_Init(std::string qqappid, bool debug, int zoneid,
                            bool isReleaseEnv, bool useBatteryNotify,
                            ReportChannelType reportChannelType,
                            std::string tCloudKey)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID InitMethod =
          FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID,
                                   "MNA_Init", "(Ljava/lang/String;ZIZZILjava/lang/String;)V", false);
      jstring jqqappid = Env->NewStringUTF(qqappid.c_str());
      jstring jtCloudKey = Env->NewStringUTF(tCloudKey.c_str());
      FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,
                                   InitMethod, jqqappid, debug, zoneid,
                                   isReleaseEnv, useBatteryNotify,
                                   (int)reportChannelType,
                                   jtCloudKey);
      Env->DeleteLocalRef(jqqappid);
      Env->DeleteLocalRef(jtCloudKey);

      // Android setBridge
      MNAMessageCenter::MNASetBridge(MNAMessageCenter::MNAMessageConsumer);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    plat->MNAInit(qqappid.c_str(), debug, zoneid, isReleaseEnv, useBatteryNotify,
                  (int)reportChannelType, tCloudKey.c_str());
#endif
    // set init to true
    isInit = true;
}

void MNA_Platform::MNA_SetUserName(int userType, std::string openid)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID SetUserNameMethod = FJavaWrapper::FindMethod(
          Env, FJavaWrapper::GameActivityClassID, "MNA_SetUserName",
          "(ILjava/lang/String;)V", false);
      jstring jopenid = Env->NewStringUTF(openid.c_str());
      FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,
                                   SetUserNameMethod, userType, jopenid);
      Env->DeleteLocalRef(jopenid);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    plat->MNASetUserName(userType, openid.c_str());
#endif
}

void MNA_Platform::MNA_SetUserName(int userType, std::string openid,
                                   std::string userId, std::string worldId)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID SetUserNameWithUserIdMethod = FJavaWrapper::FindMethod(
          Env, FJavaWrapper::GameActivityClassID, "MNA_SetUserName",
          "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", false);
      jstring jopenid = Env->NewStringUTF(openid.c_str());
      jstring juserId = Env->NewStringUTF(userId.c_str());
      jstring jworldId = Env->NewStringUTF(worldId.c_str());
      FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,
                                   SetUserNameWithUserIdMethod, userType, jopenid,
                                   juserId, jworldId);
      Env->DeleteLocalRef(jopenid);
      Env->DeleteLocalRef(juserId);
      Env->DeleteLocalRef(jworldId);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    plat->MNASetUserNameWithUserID(userType, openid.c_str(), userId.c_str(),
                                   worldId.c_str());
#endif
}

void MNA_Platform::MNA_SetZoneId(int zoneid)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID SetZoneIdMethod = FJavaWrapper::FindMethod(
          Env, FJavaWrapper::GameActivityClassID, "MNA_SetZoneId", "(I)V", false);
      FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,
                                   SetZoneIdMethod, zoneid);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    plat->MNASetZoneId(zoneid);
#endif
}

void MNA_Platform::MNA_StartSpeed(std::string vip, int vport, int htype,
                                  std::string hookModules, int zoneid,
                                  int stopMNA, std::string pvpid, int timeout)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID StartSpeedMethod = FJavaWrapper::FindMethod(
          Env, FJavaWrapper::GameActivityClassID, "MNA_StartSpeed",
          "(Ljava/lang/String;IILjava/lang/String;IIILjava/lang/String;)V",
          false);
      jstring jvip = Env->NewStringUTF(vip.c_str());
      jstring jhookModules = Env->NewStringUTF(hookModules.c_str());
      jstring jpvpid = Env->NewStringUTF(pvpid.c_str());
      FJavaWrapper::CallVoidMethod(
          Env, FJavaWrapper::GameActivityThis, StartSpeedMethod, jvip, vport,
          htype, jhookModules, zoneid, stopMNA, timeout, jpvpid);
      Env->DeleteLocalRef(jvip);
      Env->DeleteLocalRef(jhookModules);
      Env->DeleteLocalRef(jpvpid);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    plat->MNAStartSpeed(vip.c_str(), vport, htype, hookModules.c_str(), zoneid,
                        stopMNA, pvpid.c_str(), timeout);
#endif
}

void MNA_Platform::MNA_SetGameIp(std::string gameIp)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID SetGameIpMethod = FJavaWrapper::FindMethod(
          Env, FJavaWrapper::GameActivityClassID, "MNA_SetGameIp",
          "(Ljava/lang/String;)V", false);
      jstring jvip = Env->NewStringUTF(gameIp.c_str());
      FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,
                                   SetGameIpMethod, jvip);
      Env->DeleteLocalRef(jvip);
    }
#endif
#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    plat->MNASetGameIp(gameIp.c_str());
#endif
}

void MNA_Platform::MNA_StopMNA(std::string vip, int vport)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID StopMNAMethod = FJavaWrapper::FindMethod(
          Env, FJavaWrapper::GameActivityClassID, "MNA_StopMNA",
          "(Ljava/lang/String;I)V", false);
      jstring jvip = Env->NewStringUTF(vip.c_str());
      FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,
                                   StopMNAMethod, jvip, vport);
      Env->DeleteLocalRef(jvip);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    plat->MNAStopMNA(vip.c_str(), vport);
#endif
}

void MNA_Platform::MNA_EndSpeed(std::string vip, int vport)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID EndSpeedMethod = FJavaWrapper::FindMethod(
          Env, FJavaWrapper::GameActivityClassID, "MNA_EndSpeed",
          "(Ljava/lang/String;I)V", false);
      jstring jvip = Env->NewStringUTF(vip.c_str());
      FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,
                                   EndSpeedMethod, jvip, vport);
      Env->DeleteLocalRef(jvip);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    plat->MNAEndSpeed(vip.c_str(), vport);
#endif
}

void MNA_Platform::MNA_EndSpeed(std::string vip, int vport,
                                std::string extrainfo)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID EndSpeedMethod = FJavaWrapper::FindMethod(
          Env, FJavaWrapper::GameActivityClassID, "MNA_EndSpeed",
          "(Ljava/lang/String;ILjava/lang/String;)V", false);
      jstring jvip = Env->NewStringUTF(vip.c_str());
      jstring jinfo = Env->NewStringUTF(extrainfo.c_str());
      FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,
                                   EndSpeedMethod, jvip, vport, jinfo);
      Env->DeleteLocalRef(jvip);
      Env->DeleteLocalRef(jinfo);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    plat->MNAEndSpeed(vip.c_str(), vport, extrainfo.c_str());
#endif
}

void MNA_Platform::MNA_EndSpeed(std::string vip, int vport,
                                std::string extrainfo, int gameWin)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID EndSpeedMethod = FJavaWrapper::FindMethod(
          Env, FJavaWrapper::GameActivityClassID, "MNA_EndSpeed",
          "(Ljava/lang/String;ILjava/lang/String;I)V", false);
      jstring jvip = Env->NewStringUTF(vip.c_str());
      jstring jinfo = Env->NewStringUTF(extrainfo.c_str());
      FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,
                                   EndSpeedMethod, jvip, vport, jinfo, gameWin);
      Env->DeleteLocalRef(jvip);
      Env->DeleteLocalRef(jinfo);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    plat->MNAEndSpeed(vip.c_str(), vport, extrainfo.c_str(), gameWin);
#endif
}

int MNA_Platform::MNA_IsQOSWork()
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID IsQOSWorkMethod = FJavaWrapper::FindMethod(
          Env, FJavaWrapper::GameActivityClassID, "MNA_IsQOSWork", "()I", false);
      return (int)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis,
                                              IsQOSWorkMethod);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    int isQosWork = plat->MNAIsQOSWork();
    return isQosWork;
#endif

    // TODO what -1 means
    return -1;
}

void MNA_Platform::MNA_GoBack()
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID GoBackMethod = FJavaWrapper::FindMethod(
          Env, FJavaWrapper::GameActivityClassID, "MNA_GoBack", "()V", false);
      FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,
                                   GoBackMethod);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    plat->MNAGoBack();
#endif
}

void MNA_Platform::MNA_GoFront()
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID GoFrontMethod = FJavaWrapper::FindMethod(
          Env, FJavaWrapper::GameActivityClassID, "MNA_GoFront", "()V", false);
      FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,
                                   GoFrontMethod);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    plat->MNAGoFront();
#endif
}

void MNA_Platform::MNA_SetObserver(SpeedObserver speedObserver,
                                   KartinObserver kartinObserver)
{
    sSpeedObserver = speedObserver;
    sKartinObserver = kartinObserver;
#if PLATFORM_ANDROID
    // Android setBridge
    MNAMessageCenter::MNASetBridge(MNAMessageCenter::MNAMessageConsumer);
#endif
#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    MyMNAObserver *observer = MyMNAObserver::GetInstance();
    plat->MNASetObserver(observer);
#endif
}

void MNA_Platform::MNA_SetBatteryObserver(BatteryObserver batteryObserver)
{
    sBatteryObserver = batteryObserver;
}

void MNA_Platform::MNA_QueryKartin(std::string tag)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID MNA_QueryKartinMethod = FJavaWrapper::FindMethod(
          Env, FJavaWrapper::GameActivityClassID, "MNA_QueryKartin",
          "(Ljava/lang/String;)V", false);
      jstring jtag = Env->NewStringUTF(tag.c_str());
      FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,
                                   MNA_QueryKartinMethod, jtag);
      Env->DeleteLocalRef(jtag);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    plat->MNARealTimeQuery(tag.c_str());
#endif
}

void MNA_Platform::MNA_TransportInfo(TransportInfoMsgType msgType,
                                     std::string msg)
{
#if PLATFORM_ANDROID
    mna_api_TransportInfo((int)msgType, msg.c_str());
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    plat->MNATransportInfo((int)msgType, msg.c_str());
#endif
}

void MNA_Platform::MNA_SetQueryPreciseKartinObserver(QueryPreciseKartinObserver observer)
{
    sQueryPreciseKartinObserver = observer;
}

void MNA_Platform::MNA_QueryPreciseKartin(int64_t curServTime,
                                          int64_t pvpDurationTime,
                                          std::string triggerDelay)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID MNA_QueryPreciseKartinMethod = FJavaWrapper::FindMethod(
          Env, FJavaWrapper::GameActivityClassID, "MNA_QueryPreciseKartin",
          "(JJLjava/lang/String;)V", false);
      jstring jtriggerDelay = Env->NewStringUTF(triggerDelay.c_str());
      FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,
                                   MNA_QueryPreciseKartinMethod, curServTime,
                                   pvpDurationTime, jtriggerDelay);
      Env->DeleteLocalRef(jtriggerDelay);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    plat->MNAQueryPreciseKartin(curServTime, pvpDurationTime,
                                triggerDelay.c_str());
#endif
}

void MNA_Platform::MNA_AddData(std::string fps)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID MNA_AddDataMethod =
          FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID,
                                   "MNA_AddData", "(Ljava/lang/String;)V", false);
      jstring jfps = Env->NewStringUTF(fps.c_str());
      FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,
                                   MNA_AddDataMethod, jfps);
      Env->DeleteLocalRef(jfps);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    plat->MNAAddFpsData(fps.c_str(), "", "");
#endif
}

void MNA_Platform::MNA_SetGetIpGroupDelaysObserver(GetIpGroupDelaysObserver observer)
{
    sGetIpGroupDelaysObserver = observer;
}

void MNA_Platform::MNA_SetGetIpGroupDelaysTCPObserver(GetIpGroupDelaysObserver observer)
{
    sGetIpGroupDelaysTCPObserver = observer;
}

void MNA_Platform::MNA_SetGetIpGroupDelaysWithBindingObserver(GetIpGroupDelaysObserver observer)
{
    sGetIpGroupDelaysWithBindingObserver = observer;
}

void MNA_Platform::MNA_GetIpGroupDelays(std::string tag,
                                        std::string ipPortGroup,
                                        int intervalMills, int count,
                                        int pkgTimeoutMills)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID GetIpGroupDelaysMethod = FJavaWrapper::FindMethod(
          Env, FJavaWrapper::GameActivityClassID, "MNA_GetIpGroupDelays",
          "(Ljava/lang/String;Ljava/lang/String;III)V", false);
      jstring jtag = Env->NewStringUTF(tag.c_str());
      jstring jipPortGroup = Env->NewStringUTF(ipPortGroup.c_str());
      FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,
                                   GetIpGroupDelaysMethod, jtag, jipPortGroup,
                                   intervalMills, count, pkgTimeoutMills);
      Env->DeleteLocalRef(jtag);
      Env->DeleteLocalRef(jipPortGroup);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    plat->MNAGetIpGroupDelays(tag.c_str(), ipPortGroup.c_str(), intervalMills,
                              count, pkgTimeoutMills);
#endif
}

void MNA_Platform::MNA_GetIpGroupDelaysForTest(std::string tag,
                                        std::string ipPortGroup,
                                        int intervalMills, int count,
                                        int pkgTimeoutMills)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID GetIpGroupDelaysForTestMethod = FJavaWrapper::FindMethod(
          Env, FJavaWrapper::GameActivityClassID, "MNA_GetIpGroupDelaysForTest",
          "(Ljava/lang/String;Ljava/lang/String;III)V", false);
      jstring jtag = Env->NewStringUTF(tag.c_str());
      jstring jipPortGroup = Env->NewStringUTF(ipPortGroup.c_str());
      FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,
                                   GetIpGroupDelaysForTestMethod, jtag, jipPortGroup,
                                   intervalMills, count, pkgTimeoutMills);
      Env->DeleteLocalRef(jtag);
      Env->DeleteLocalRef(jipPortGroup);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    plat->MNAGetIpGroupDelaysForTest(tag.c_str(), ipPortGroup.c_str(), intervalMills,
                              count, pkgTimeoutMills);
#endif
}

void MNA_Platform::MNA_GetIpGroupDelaysUseTCP(std::string tag,
                                        std::string ipPortGroup,
                                        int intervalMills, int count,
                                        int pkgTimeoutMills)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID GetIpGroupDelaysUseTCPMethod = FJavaWrapper::FindMethod(
          Env, FJavaWrapper::GameActivityClassID, "MNA_GetIpGroupDelaysUseTCP",
          "(Ljava/lang/String;Ljava/lang/String;III)V", false);
      jstring jtag = Env->NewStringUTF(tag.c_str());
      jstring jipPortGroup = Env->NewStringUTF(ipPortGroup.c_str());
      FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,
                                   GetIpGroupDelaysUseTCPMethod, jtag, jipPortGroup,
                                   intervalMills, count, pkgTimeoutMills);
      Env->DeleteLocalRef(jtag);
      Env->DeleteLocalRef(jipPortGroup);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    plat->MNAGetIpGroupDelaysUseTCP(tag.c_str(), ipPortGroup.c_str(), intervalMills,
                              count, pkgTimeoutMills);
#endif
}

void MNA_Platform::MNA_GetIpGroupDelaysForTestUseTCP(std::string tag,
                                               std::string ipPortGroup,
                                               int intervalMills, int count,
                                               int pkgTimeoutMills)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID GetIpGroupDelaysForTestUseTCPMethod = FJavaWrapper::FindMethod(
          Env, FJavaWrapper::GameActivityClassID, "MNA_GetIpGroupDelaysForTestUseTCP",
          "(Ljava/lang/String;Ljava/lang/String;III)V", false);
      jstring jtag = Env->NewStringUTF(tag.c_str());
      jstring jipPortGroup = Env->NewStringUTF(ipPortGroup.c_str());
      FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,
                                   GetIpGroupDelaysForTestUseTCPMethod, jtag, jipPortGroup,
                                   intervalMills, count, pkgTimeoutMills);
      Env->DeleteLocalRef(jtag);
      Env->DeleteLocalRef(jipPortGroup);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    plat->MNAGetIpGroupDelaysForTestUseTCP(tag.c_str(), ipPortGroup.c_str(), intervalMills,
                              count, pkgTimeoutMills);
#endif
}

void MNA_Platform::MNA_GetIpGroupDelaysWithBinding(std::string tag,
                                        std::string ipPortGroup,
                                        int intervalMills, int count,
                                        int pkgTimeoutMills,
                                       IpProto ipProto, BindNetType bindNetType)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID GetIpGroupDelaysMethod = FJavaWrapper::FindMethod(
          Env, FJavaWrapper::GameActivityClassID, "MNA_GetIpGroupDelaysWithBinding",
          "(Ljava/lang/String;Ljava/lang/String;IIIII)V", false);
      jstring jtag = Env->NewStringUTF(tag.c_str());
      jstring jipPortGroup = Env->NewStringUTF(ipPortGroup.c_str());
      FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,
                                   GetIpGroupDelaysMethod, jtag, jipPortGroup,
                                   intervalMills, count, pkgTimeoutMills,
                                   (int)ipProto, (int)bindNetType);
      Env->DeleteLocalRef(jtag);
      Env->DeleteLocalRef(jipPortGroup);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    plat->MNAGetIpGroupDelaysWithBinding(tag.c_str(), ipPortGroup.c_str(), intervalMills,
                              count, pkgTimeoutMills, (int)ipProto, (int)bindNetType);
#endif
}

void MNA_Platform::MNA_SetMNAPingObserver(
        MNAPingObserver observer)
{
    sMNAPingObserver = observer;
}

void MNA_Platform::MNA_PingGateway(std::string tag, int intervalMills, int count,
                                   int pkgTimeoutMills, bool onlyWifi)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID PingGatewayMethod = FJavaWrapper::FindMethod(
          Env, FJavaWrapper::GameActivityClassID, "MNA_PingGateway",
          "(Ljava/lang/String;IIIZ)V", false);
      jstring jtag = Env->NewStringUTF(tag.c_str());
      FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,
                                   PingGatewayMethod, jtag, intervalMills,
                                   count, pkgTimeoutMills, onlyWifi);
      Env->DeleteLocalRef(jtag);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    plat->MNAPingGateway(tag.c_str(), intervalMills, count,
                         pkgTimeoutMills, onlyWifi);
#endif
}

void MNA_Platform::MNA_Ping(std::string ip, std::string tag, int intervalMills, int count,
                            int pkgTimeoutMills, bool onlyWifi)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID PingMethod = FJavaWrapper::FindMethod(
          Env, FJavaWrapper::GameActivityClassID, "MNA_Ping",
          "(Ljava/lang/String;Ljava/lang/String;IIIZ)V", false);
      jstring jip = Env->NewStringUTF(ip.c_str());
      jstring jtag = Env->NewStringUTF(tag.c_str());
      FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,
                                   PingMethod, jip, jtag, intervalMills, count,
                                   pkgTimeoutMills, onlyWifi);
      Env->DeleteLocalRef(jip);
      Env->DeleteLocalRef(jtag);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    plat->MNAPing(ip.c_str(), tag.c_str(), intervalMills, count,
                  pkgTimeoutMills, onlyWifi);
#endif
}

void MNA_Platform::MNA_SetPvpSpeedIp(std::string speedIp, int port)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID SetPvpSpeedIpMethod =
          FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID,
                                   "MNA_SetPvpSpeedIp", "(Ljava/lang/String;I)V", false);
      jstring jspeedIp = Env->NewStringUTF(speedIp.c_str());
      FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,
                                   SetPvpSpeedIpMethod, jspeedIp, port);
      Env->DeleteLocalRef(jspeedIp);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    plat->MNASetPvpSpeedIp(speedIp.c_str(), port);
#endif
}

bool MNA_Platform::MNA_IsAnyVPNOpen()
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID IsAnyVPNOpenMethod =
          FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID,
                                   "MNA_IsAnyVPNOpen", "()Z", false);
      return (bool)FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis,
                                   IsAnyVPNOpenMethod);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    return plat->IsAnyVpnOpen();
#endif

    // default
    return false;
}

bool MNA_Platform::MNA_IsHarmonyOS()
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID IsHarmonyOSMethod =
          FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID,
                                   "MNA_IsHarmonyOS", "()Z", false);
      return (bool)FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis,
                                   IsHarmonyOSMethod);
    }
#endif

    // not support in ios
    // default
    return false;
}

bool MNA_Platform::MNA_IsAuxWifiAccelerated()
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID IsAuxWifiAcceleratedMethod =
          FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID,
                                   "MNA_IsAuxWifiAccelerated", "()Z", false);
      return (bool)FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis,
                                   IsAuxWifiAcceleratedMethod);
    }
#endif

    // not support in ios
    // default
    return false;
}

AuxWifiSupportFlag MNA_Platform::MNA_GetAuxWifiSupportFlag()
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID GetAuxWifiSupportFlagMethod =
          FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID,
                                   "MNA_GetAuxWifiSupportFlag", "()I", false);
      return (AuxWifiSupportFlag)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis,
                                   GetAuxWifiSupportFlagMethod);
    }
#endif

    // not support in ios
    // default
    return AuxWifiSupportFlag::MNA_AUX_WIFI_SUPPORT_FLAG_NOT_SUPPORT;
}

void MNA_Platform::MNA_SetAuxWifiUserAllow(bool isAllow)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID SetAuxWifiUserAllowMethod =
          FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID,
                                   "MNA_SetAuxWifiUserAllow", "(Z)V", false);
      FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,
                                   SetAuxWifiUserAllowMethod, isAllow);
    }
#endif

    // not support in ios
    // default
}

void MNA_Platform::MNA_SetDualTunnelBindNetType(BindNetType bindNetType, bool useSaveFlow)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID SetDualTunnelBindNetTypeMethod =
          FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID,
                                   "MNA_SetDualTunnelBindNetType", "(IZ)V", false);
      FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,
                                   SetDualTunnelBindNetTypeMethod, (int)bindNetType, useSaveFlow);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    plat->MNASetDualTunnelBindNetType((int)bindNetType, useSaveFlow);
#endif
}

void MNA_Platform::MNA_SetAuxFlowEnable(bool enableSend, bool enableRecv)
{
    // 需要先初始化
    if (!isInit)
    {
        return;
    }
#if PLATFORM_ANDROID
    mna_api_SetAuxFlowEnable(enableSend, enableRecv);
#endif

#if PLATFORM_IOS
    mna_api_SetAuxFlowEnable(enableSend, enableRecv);
#endif
}

void MNA_Platform::MNA_SetQueryConnectionInfoObserver(QueryConnectionInfoObserver observer)
{
    sQueryConnectionInfoObserver = observer;
}

void MNA_Platform::MNA_QueryConnectionInfo()
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID QueryConnectionInfoMethod =
          FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID,
                                   "MNA_QueryConnectionInfo", "()V", false);
      FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,
                                   QueryConnectionInfoMethod);
    }
#endif

    // not support in ios
    // default
}

int MNA_Platform::MNA_GetWifiLinkSpeed()
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID GetWifiLinkSpeedMethod =
          FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID,
                                   "MNA_GetWifiLinkSpeed", "()I", false);
      return (int)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis,
                                   GetWifiLinkSpeedMethod);
    }
#endif

    // not support in ios
    // default
    return 0;
}

std::string MNA_Platform::MNA_GetMobileActiveSimCountInfo()
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID GetMobileActiveSimCountInfoMethod =
          FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID,
                                   "MNA_GetMobileActiveSimCountInfo", "()Ljava/lang/String;", false);
      jstring jresult = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis,
                                   GetMobileActiveSimCountInfoMethod);
      std::string result;
      const char *cstr = Env->GetStringUTFChars(jresult, 0);
      if (cstr != nullptr)
      {
          result.assign(cstr);
      }
      Env->ReleaseStringUTFChars(jresult, cstr);
      Env->DeleteLocalRef(jresult);
      return result;
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    const char *cstr = plat->MNAGetMobileActiveSimCountInfo();
    return MNAUtils::CPtrToStringThenFree(cstr);
#endif

    // default
    return "";
}

int MNA_Platform::MNA_GetNetworkType()
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID GetNetworkTypeMethod =
          FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID,
                                   "MNA_GetNetworkType", "()I", false);
      return (int)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis,
                                   GetNetworkTypeMethod);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    return plat->MNAGetNetworkType();
#endif

    // default
    return 0;
}

int MNA_Platform::MNA_GetTelephonyType()
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID GetTelephonyTypeMethod =
          FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID,
                                   "MNA_GetTelephonyType", "()I", false);
      return (int)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis,
                                   GetTelephonyTypeMethod);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    return plat->MNAGetTelephonyType();
#endif

    // default
    return 0;
}

void MNA_Platform::MNA_EnterMapLoading()
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID EnterMapLoadingMethod =
          FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID,
                                   "MNA_EnterMapLoading", "()V", false);
      FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,
                                   EnterMapLoadingMethod);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    plat->MNAEnterMapLoading();
#endif
}

int MNA_Platform::MNA_GetSpeedDelay() {
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID GetSpeedDelayMethod =
          FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID,
                                   "MNA_GetSpeedDelay", "()I", false);
      return (int)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis,
                                   GetSpeedDelayMethod);
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    return plat->MNAGetSpeedDelay();
#endif

    // default
    return -1;
}

BatteryInfo MNA_Platform::MNA_GetBatteryLevelAndCharging() {
    BatteryInfo batteryInfo;
    batteryInfo.level = -1;
    batteryInfo.charging = 0;
#if PLATFORM_ANDROID
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
      jmethodID GetBatteryLevelAndChargingMethod =
          FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID,
                                   "MNA_GetBatteryLevelAndCharging", "()Ljava/lang/Object;", false);
      Env->ExceptionClear();
      // andorid is int[]
      jintArray jresult = (jintArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis,
                                   GetBatteryLevelAndChargingMethod);
      Env->ExceptionClear();
      if (jresult) {
        jsize len = Env->GetArrayLength(jresult);
        jint *res = Env->GetIntArrayElements(jresult, 0);
        if (res) {
          if (len >= 2) {
              batteryInfo.level = res[0];
              batteryInfo.charging = res[1];
          }
          Env->ReleaseIntArrayElements(jresult, res, 0);
        }
        Env->DeleteLocalRef(jresult);
      }
    }
#endif

#if PLATFORM_IOS
    MNAPublic *plat = MNAPublic::GetInstance();
    std::string resultStr = MNAUtils::CPtrToStringThenFree(plat->MNAGetBatteryLevelAndCharging());
    std::vector<std::string> array;
    MNAUtils::Split(resultStr, ";", &array);
    if (array.size() >= 2)
    {
        batteryInfo.level = atoi(array[0].c_str());
        batteryInfo.charging = atoi(array[1].c_str());
    }
#endif
    // default
    return batteryInfo;
}

// ------------------------------------------
// others
// -------------------------------------------

void startFps(const char *config)
{
    UE_LOG(LogTemp, Log, TEXT("startFps: %s"), *FString(config));

    // Convert const char to string
    std::string configStr = std::string(config);
    if (configStr.empty())
    {
        return;
    }
    // parse string to vector
    std::stringstream ss;
    std::vector <std::string> configList;
    std::string configItem;
    ss.str(configStr);
    while (std::getline(ss, configItem, '|'))
    {
        configList.push_back(configItem);
    }
    // retrieve fps_cycle
    if (configList.size() != 4)
    {
        return;
    }

    int saveInterval = atoi(configList[0].c_str());
    // int moveMin = atoi(configList[1].c_str());
    int fpsDotInterval = atoi(configList[2].c_str());
    // int touchDotInterval = atoi(configList[3].c_str());
}

#if PLATFORM_ANDROID
JNI_METHOD void
Java_com_tencent_mna_base_jni_MnaJni_startUe4Fps(JNIEnv *env, jobject thiz,
                                                 jstring config) {
  UE_LOG(LogTemp, Log, TEXT("java call native startFps"));
  if (env->ExceptionOccurred()) {
    env->ExceptionDescribe();
    env->ExceptionClear();
  }
  const char *cConfig = env->GetStringUTFChars(config, 0);
  startFps(cConfig);
  env->ReleaseStringUTFChars(config, cConfig);
}
#endif

// ------------------------------------------
// notify
// -------------------------------------------

void MNA_Platform::OnStartSpeedNotify(const char *str)
{
    if (!sSpeedObserver)
    {
        return;
    }
    std::string msg(str);
    if (msg.empty())
    {
        return;
    }
    std::vector <std::string> msgArray;
    MNAUtils::Split(msg, "_", &msgArray);
    if (msgArray.empty())
    {
        MNAUtils::Split(msg, ";", &msgArray);
    }
    if (msgArray.size() < 3)
    {
        return;
    }
    StartSpeedRet ret;
    ret.type = atoi(msgArray[0].c_str());
    ret.flag = atoi(msgArray[1].c_str());
    ret.desc.assign(msgArray[2]);
    sSpeedObserver(ret);
}

void MNA_Platform::OnQueryKartinNotify(const char *str)
{
    if (!sKartinObserver)
    {
        return;
    }
    std::string msg(str);
    if (msg.empty())
    {
        return;
    }
    std::vector <std::string> msgArray;
    MNAUtils::Split(msg, "_", &msgArray);
    if (msgArray.empty())
    {
        MNAUtils::Split(msg, ";", &msgArray);
    }

    if (msgArray.size() < 22)
    {
        return;
    }

    std::string tag = msgArray[0];
    int flag = atoi(msgArray[1].c_str());
    std::string desc = msgArray[2];
    int jump_network = atoi(msgArray[3].c_str());
    int jump_signal = atoi(msgArray[4].c_str());
    int jump_router = atoi(msgArray[5].c_str());
    int router_status = atoi(msgArray[6].c_str());
    std::string router_desc = msgArray[7];
    int jump_export = atoi(msgArray[8].c_str());
    int export_status = atoi(msgArray[9].c_str());
    std::string export_desc = msgArray[10];
    int jump_terminal = atoi(msgArray[11].c_str());
    int terminal_status = atoi(msgArray[12].c_str());
    std::string terminal_desc = msgArray[13];
    int jump_proxy = atoi(msgArray[14].c_str());
    int jump_edge = atoi(msgArray[15].c_str());
    std::string signal_desc = msgArray[16];
    int signal_status = atoi(msgArray[17].c_str());
    int jump_direct = atoi(msgArray[18].c_str());
    int direct_status = atoi(msgArray[19].c_str());
    std::string direct_desc = msgArray[20];
    int network_status = 0;
    std::string network_desc = "";
    int wifi_num = 0;
    if (msgArray.size() >= 24)
    {
        network_status = atoi(msgArray[21].c_str());
        network_desc = msgArray[22];
        wifi_num = atoi(msgArray[23].c_str());
    } else
    {
        wifi_num = atoi(msgArray[21].c_str());
    }

    KartinRet ret;
    ret.tag = tag;
    ret.flag = flag;
    ret.desc = desc;
    ret.jump_network = jump_network;
    ret.jump_signal = jump_signal;
    ret.jump_router = jump_router;
    ret.router_status = router_status;
    ret.router_desc = router_desc;
    ret.jump_export = jump_export;
    ret.export_status = export_status;
    ret.export_desc = export_desc;
    ret.jump_terminal = jump_terminal;
    ret.terminal_status = terminal_status;
    ret.terminal_desc = terminal_desc;
    ret.jump_proxy = jump_proxy;
    ret.jump_edge = jump_edge;
    ret.signal_desc = signal_desc;
    ret.signal_status = signal_status;
    ret.jump_direct = jump_direct;
    ret.direct_status = direct_status;
    ret.direct_desc = direct_desc;
    ret.network_status = network_status;
    ret.network_desc = network_desc;
    ret.wifi_num = wifi_num;
    sKartinObserver(ret);
}

void MNA_Platform::MNA_ReceiveInfoFromMNA(const char *fpsString)
{
    UE_LOG(LogTemp, Log, TEXT("iOS call UE4 "));
    startFps(fpsString);
}

void MNA_Platform::MNA_KartinNotifyFromMNA(const KartinRet &ret)
{
    if (sKartinObserver)
    {
        sKartinObserver(ret);
    }
}

void MNA_Platform::MNA_StartNotifyFromMNA(const StartSpeedRet &ret)
{
    if (sSpeedObserver)
    {
        sSpeedObserver(ret);
    }
}

void MNA_Platform::OnQueryPreciseKartinNotify(const char *str)
{
    if (!sQueryPreciseKartinObserver)
    {
        return;
    }
    if (!str)
    {
        return;
    }
    std::string msg(str);
    if (msg.empty())
    {
        return;
    }
    int index = msg.find("#");
    if (index == std::string::npos)
    {
        return;
    }
    // parse
    int errCode = atoi(msg.substr(0, index).c_str());
    std::string jsonResult = "";
    if ((index + 1) < msg.size())
    {
        jsonResult = msg.substr(index + 1);
    }
    QueryPreciseKartinRet ret;
    ret.errCode = errCode;
    ret.jsonResult.assign(jsonResult);
    sQueryPreciseKartinObserver(ret);
}

void MNA_Platform::HandleOnGetIpGroupDelays(const char *str, GetIpGroupDelaysObserver observer)
{
    if (!observer)
    {
        return;
    }
    if (!str)
    {
        return;
    }
    std::string msg(str);
    if (msg.empty())
    {
        return;
    }
    std::vector <std::string> msgArray;
    MNAUtils::Split(msg, "%%", &msgArray);
    if (msgArray.size() < 2)
    {
        return;
    }
    GetIpGroupDelaysRet ret;
    ret.tag.assign(msgArray[0]);
    ret.ipGroupDelaysResult.assign(msgArray[1]);
    observer(ret);
}

void MNA_Platform::OnGetIpGroupDelaysNotify(const char *str)
{
    HandleOnGetIpGroupDelays(str, sGetIpGroupDelaysObserver);
}

void MNA_Platform::OnGetIpGroupDelaysTCPNotify(const char *str)
{
    HandleOnGetIpGroupDelays(str, sGetIpGroupDelaysTCPObserver);
}

void MNA_Platform::OnGetIpGroupDelaysWithBindingNotify(const char *str)
{
    HandleOnGetIpGroupDelays(str, sGetIpGroupDelaysWithBindingObserver);
}

void MNA_Platform::OnMNAPingNotify(const char *str)
{
    if (!sMNAPingObserver)
    {
        return;
    }
    if (!str)
    {
        return;
    }
    std::string msg(str);
    if (msg.empty())
    {
        return;
    }
    std::vector <std::string> msgArray;
    MNAUtils::Split(msg, "%%", &msgArray);
    if (msgArray.size() < 4)
    {
        return;
    }
    MNAPingRet ret;
    ret.tag.assign(msgArray[0]);
    ret.flag = atoi(msgArray[1].c_str());
    ret.ip.assign(msgArray[2]);
    ret.pingResult.assign(msgArray[3]);
    sMNAPingObserver(ret);
}

void MNA_Platform::OnConnectionInfoNotify(const char *str)
{
    if (!sQueryConnectionInfoObserver)
    {
        return;
    }
    if (!str)
    {
        return;
    }
    std::string msg(str);
    if (msg.empty())
    {
        return;
    }
    std::vector <std::string> msgArray;
    MNAUtils::Split(msg, ";", &msgArray);
    if (msgArray.size() < 3)
    {
        return;
    }
    QueryConnectionInfoRet ret;

    // 网络类型
    ret.netType = atoi(msgArray[0].c_str());
    // wifi
    std::string wifiStr = msgArray[1];
    std::vector <std::string> wifiArray;
    MNAUtils::Split(wifiStr, ",", &wifiArray);
    if (wifiArray.size() >= 7)
    {
        ret.bssID = wifiArray[0];
        ret.rssi = atoi(wifiArray[1].c_str());
        ret.rssiLevel = atoi(wifiArray[2].c_str());
        ret.frequency = atoi(wifiArray[3].c_str());
        ret.channel = atoi(wifiArray[4].c_str());
        ret.linkSpeed = atoi(wifiArray[5].c_str());
        ret.wifiStandard = atoi(wifiArray[6].c_str());
    }
    // mobile
    std::string mobileStr = msgArray[2];
    std::vector <std::string> mobileArray;
    MNAUtils::Split(mobileStr, ",", &mobileArray);
    if (mobileArray.size() >= 7)
    {
        ret.cellID = mobileArray[0];
        ret.dbm = atoi(mobileArray[1].c_str());
        ret.dbmLevel = atoi(mobileArray[2].c_str());
        ret.rsrp = atoi(mobileArray[3].c_str());
        ret.rsrq = atoi(mobileArray[4].c_str());
        ret.sinr = atoi(mobileArray[5].c_str());
        ret.cqi = atoi(mobileArray[6].c_str());
    }
    sQueryConnectionInfoObserver(ret);
}

void MNA_Platform::OnBatteryChangedNotify(const char *str) {
    if (!sBatteryObserver) {
        return;
    }
    if (!str) {
        return;
    }
    std::string msg(str);
    if (msg.empty()) {
        return;
    }
    std::vector <std::string> msgArray;
#if PLATFORM_ANDROID
    // 安卓的分隔符是"_"
    const char *token = "_";
#else
    // iOS的分隔符是";"
    const char *token = ";";
#endif
    MNAUtils::Split(msg, token, &msgArray);
    if (msgArray.size() < 2) {
        return;
    }
    BatteryInfo ret;
    ret.level = atoi(msgArray[0].c_str());
    ret.charging = atoi(msgArray[1].c_str());
    sBatteryObserver(ret);
}
