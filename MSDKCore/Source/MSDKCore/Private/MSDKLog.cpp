//
// Created by mikefu on 2021/8/11.
// Copyright (c) 2021 Epic Games, Inc. All rights reserved.
//


#include "MSDKLog.h"

#if MSDK_ENGINE_UE4_SIMULATE_LOGIN

NS_MSDK_BEGIN

MSDKLogger::MSDKLogger(ILogLevel level, const char *tag, const char *fileName, const char *funcName, int line) {}

MSDKLogger::~MSDKLogger() {}

MSDKLogger& MSDKLogger::console() {return *this;}

MSDKLogger& MSDKLogger::writeLog(const char *fmt, ...) {return *this;}

NS_MSDK_END
#endif




