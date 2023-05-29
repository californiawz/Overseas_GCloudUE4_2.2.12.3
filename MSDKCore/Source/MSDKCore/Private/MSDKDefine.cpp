//
// Created by mikefu on 2021/8/11.
// Copyright (c) 2021 Epic Games, Inc. All rights reserved.
//


#include "MSDKDefine.h"

#if MSDK_ENGINE_UE4_SIMULATE_LOGIN

NS_MSDK_BEGIN

InnerLocalNotification::InnerLocalNotification() {}

MSDKTrace::MSDKTrace(const char *fileName, const char *funcName, int line, const char *seqID, const char *extra) {}

void MSDKTrace::sendByTDM(const char *category, const std::map<std::string, std::string> &value) {}

void MSDKTrace::fillCommonValue(std::map<std::string, std::string> &value) {}

void MSDKTrace::tracePlugin(const char *pluginName, const char *pluginVer, const char *sdkName, const char *sdkVer) {}

void MSDKTrace::traceLog(const char *log) {}

void MSDKTrace::traceMonitorBegin(MSDKBaseParams &baseParams) {}

void MSDKTrace::traceMonitorEnd(const InnerBaseRet &ret) {}

void MSDKTrace::tracePluginMonitorBegin(MSDKBaseParams &baseParams, std::string postfix) {}

void MSDKTrace::tracePluginMonitorEnd(const InnerBaseRet &ret, std::string postfix) {}

void MSDKTrace::traceHTTPBegin(const char*url) {}

void MSDKTrace::traceHTTPEnd(const char*url, unsigned int retcode, const char *reponseBody) {}

void MSDKTrace::traceHTTPDNSBegin(const std::string url) {}

void MSDKTrace::traceHTTPDNSEnd(const std::string url, InnerBaseRet &ret) {}

NS_MSDK_END

#endif




