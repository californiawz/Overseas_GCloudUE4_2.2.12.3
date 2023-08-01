//
// Created by jaredhuang on 2023/2/20.
//
#if PLATFORM_ANDROID

#include "MNAMessageCenter.h"

#include "CoreMinimal.h"
#include "Engine.h"
#include "MNA_Platform.h"
#include "MNAUtils.h"

#include <string>
#include <sstream>
#include <vector>

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include "Android/AndroidPlatform.h"
#endif

void MNAMessageCenter::MNASetBridge(MNASendToUnreal ptr) {
    if (JNIEnv *Env = MNAUtils::WrapGetJavaEnv())
    {
        jmethodID SetBridgeMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "MNA_SetBridge", "(J)V", false);
        int64_t bridgePtr = reinterpret_cast<int64_t>(ptr);
        FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, SetBridgeMethod, bridgePtr);
    }
}

int MNAMessageCenter::MNAMessageConsumer(const char *str)
{
    if (!str)
    {
        return -1;
    }
    return MNAParseCallbackString(str);
}

int MNAMessageCenter::MNAParseCallbackString(const char *str)
{
    if (!str)
    {
        return -1;
    }
    UE_LOG(LogTemp, Log, TEXT("MNAParseCallbackString -- %s"), UTF8_TO_TCHAR(str));
    // OnQueryKartinNotify, OnStartSpeedNotify, OnBatteryChangedNotify
    // onBinding, OnQueryNetworkNotify, OnQueryRouterNotify
    std::string orginStr(str);
    if (MNAUtils::StartsWith(orginStr, "OnStartSpeedNotify"))
    {
        std::string subStr = orginStr.substr(strlen("OnStartSpeedNotify") + 1);
        MNA_Platform::OnStartSpeedNotify(subStr.c_str());
    }
    else if (MNAUtils::StartsWith(orginStr, "OnQueryKartinNotify"))
    {
        std::string subStr = orginStr.substr(strlen("OnQueryKartinNotify") + 1);
        MNA_Platform::OnQueryKartinNotify(subStr.c_str());
    }
    else if (MNAUtils::StartsWith(orginStr, "OnGetIpGroupDelaysNotify"))
    {
        std::string subStr = orginStr.substr(strlen("OnGetIpGroupDelaysNotify") + 1);
        MNA_Platform::OnGetIpGroupDelaysNotify(subStr.c_str());
    }
    else if (MNAUtils::StartsWith(orginStr, "OnGetIpGroupDelaysTCPNotify"))
    {
        std::string subStr = orginStr.substr(strlen("OnGetIpGroupDelaysTCPNotify") + 1);
        MNA_Platform::OnGetIpGroupDelaysTCPNotify(subStr.c_str());
    }
    else if (MNAUtils::StartsWith(orginStr, "OnGetIpGroupDelaysWithBindingNotify"))
    {
        std::string subStr = orginStr.substr(strlen("OnGetIpGroupDelaysWithBindingNotify") + 1);
        MNA_Platform::OnGetIpGroupDelaysWithBindingNotify(subStr.c_str());
    }
    else if (MNAUtils::StartsWith(orginStr, "OnPingNotify"))
    {
        std::string subStr = orginStr.substr(strlen("OnPingNotify") + 1);
        MNA_Platform::OnMNAPingNotify(subStr.c_str());
    }
    else if (MNAUtils::StartsWith(orginStr, "OnQueryPreciseKartinNotify"))
    {
        std::string subStr = orginStr.substr(strlen("OnQueryPreciseKartinNotify") + 1);
        MNA_Platform::OnQueryPreciseKartinNotify(subStr.c_str());
    }
    else if (MNAUtils::StartsWith(orginStr, "OnConnectionInfoNotify"))
    {
        std::string subStr = orginStr.substr(strlen("OnConnectionInfoNotify") + 1);
        MNA_Platform::OnConnectionInfoNotify(subStr.c_str());
    }
    else if (MNAUtils::StartsWith(orginStr, "OnBatteryChangedNotify"))
    {
        std::string subStr = orginStr.substr(strlen("OnBatteryChangedNotify") + 1);
        MNA_Platform::OnBatteryChangedNotify(subStr.c_str());
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("MNAParseCallbackString parse exception"));
    }
    return 0;
}



#endif