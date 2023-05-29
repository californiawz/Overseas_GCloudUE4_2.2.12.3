/**
 * @file MSDKLog.h
 *
 * @date  2018/4/8
 * @author developer
 *
 * @section DESCRIPTION
 *
 * MSDK 日志入口类
 *
 * Copyright © company. All rights reserved.
 */

#ifndef MSDK_MSDKLOG_h
#define MSDK_MSDKLOG_h

#include "MSDKMacros.h"

#if MSDK_PLATFORM_WINDOWS

#include <iostream>
#include <ostream>
#include <fstream>
#include <stdio.h>
#include <string>


NS_MSDK_BEGIN

class MSDKLogCrypt;
class MSDKMutex;

typedef enum {
	kLevelDebug = 0,
	kLevelInfo,
	kLevelWarn,
	kLevelError,
} MSDKLogLevel;

#define __FILENAME1__ (strrchr(__FILE__, '/') ? (strrchr(__FILE__, '/') + 1):__FILE__)
#define __FILENAME2__ (strrchr(__FILE__, '\\') ? (strrchr(__FILE__, '\\') + 1):__FILE__)
#define __FILENAME__ (strrchr(__FILE__, '/') ? (__FILENAME1__):(__FILENAME2__))
#define __MSDKFILE__ (char *)(strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#define __MSDKFUNCTION__ (char *)__FUNCTION__
#define LOG_DEBUG(fmt, ...) MSDKLog::GetInstance()->PrintLog(kLevelDebug, __MSDKFILE__, __MSDKFUNCTION__, __LINE__,(char *)fmt,##__VA_ARGS__);
#define LOG_INFO(fmt, ...) MSDKLog::GetInstance()->PrintLog(kLevelInfo, __MSDKFILE__, __MSDKFUNCTION__, __LINE__,(char *)fmt,##__VA_ARGS__);
#define LOG_WARN(fmt, ...) MSDKLog::GetInstance()->PrintLog(kLevelWarn, __MSDKFILE__, __MSDKFUNCTION__, __LINE__,(char *)fmt,##__VA_ARGS__);
#define LOG_ERROR(fmt, ...) MSDKLog::GetInstance()->PrintLog(kLevelError, __MSDKFILE__, __MSDKFUNCTION__, __LINE__,(char *)fmt,##__VA_ARGS__);
#define LOG_INFO_IF(exp, fmt, ...)      if (exp) LOG_INFO((char *)fmt, ##__VA_ARGS__)
#define LOG_ERROR_IF(exp, fmt, ...)      if (exp) LOG_ERROR((char *)fmt, ##__VA_ARGS__)


class MSDKLog
{
private:
	static MSDKLog *instance_;
	std::string path_;
	MSDKLogCrypt *logCrypt;
	MSDKMutex *logMutex;
	MSDKLog();
	~MSDKLog();
	
public:
	MSDK_EXPORT_UE static MSDKLog *GetInstance();
	MSDK_EXPORT_UE void PrintLog(MSDKLogLevel level, char* file_name, char* function_name, int line_number, char * fmt, ...);
};

NS_MSDK_END

#else

#include <string>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MSDKLogUtil.h"
#include "MSDKCompatLayer.h"
#if MSDK_ENGINE_UE4_PLATFORM_WINDOWS
#else
#include <sys/cdefs.h>
#include <sys/time.h>
#endif


// 定义此宏 会在 release 日志宏中打印日志到控制台
//#ifndef DEBUG
//#define DEBUG
//#endif

#define MSDKLOG_INIT()                                                              \
    do {                                                                            \
        MSDKLogManager::GetInstance()->init();                                                     \
    } while (0)                                                                     \

#define MSDKLOG_UNINIT()                                                            \
    do {                                                                            \
        MSDKLogManager::getInstance()->::unInit();                                                   \
    } while (0)                                                                     \

#define SET_MSDKLOG_LEVEL(level)                                                    \
    do {                                                                            \
        MSDKLogManager::GetInstance()->gLogLevel = level;                                          \
    } while (0)                                                                     \

#define SET_MSDKLOG_MODE(mode)                                                      \
    do {                                                                            \
        MSDKLogManager::GetInstance()->gLogMode = mode;                                            \
    } while (0)                                                                     \

#define SET_MSDKLOG_FILE(name, size)                                        \
    do {                                                                            \
        MSDKLogManager::GetInstance()->baseFileName = name;                                        \
        MSDKLogManager::GetInstance()->fileSize = size;                                        \
    } while (0)                                                                     \

#define MSDKLOG_OFFLINE_UPLOAD()                                                    \
    do {                                                                            \
        if ((MSDKLogManager::GetInstance()->gLogMode & kHttp) == kHttp) {           \
            MSDKLogManager::GetInstance()->offlineUpload();                         \
        }                                                                           \
    } while (0)                                                                     \


#define __FILENAME1__ (strrchr(__FILE__, '/') ? (strrchr(__FILE__, '/') + 1):__FILE__)
#define __FILENAME2__ (strrchr(__FILE__, '\\') ? (strrchr(__FILE__, '\\') + 1):__FILE__)
#define __FILENAME__ (strrchr(__FILE__, '/') ? (__FILENAME1__):(__FILENAME2__))

#ifdef NO_LOG_DEBUG
#define LOG_DEBUG(...)
#define LOG_ERROR(...)
#define LOG_JSON(level, ...)
#else
#define LOG_DEBUG(...)          MSDKLogger(kLevelDebug, ILOG_TAG, __FILENAME__, __FUNCTION__, __LINE__).console().writeLog(__VA_ARGS__)
#define LOG_ERROR(...)          MSDKLogger(kLevelError, ILOG_TAG, __FILENAME__, __FUNCTION__, __LINE__).console().writeLog(__VA_ARGS__)
#define LOG_JSON(level, ...)    MSDKLogger(level, ILOG_TAG, __FILENAME__, __FUNCTION__, __LINE__).console().json().writeLog(__VA_ARGS__)

#define LOG_JNI(level, tag, file, func, line, ...)  \
    MSDKLogger(level, tag, file, func, line).console().writeLog(__VA_ARGS__)

#define LOG_ERROR_IF(exp, ...)    \
    if (!(exp))                   \
        ;                         \
    else MSDKLogger(kLevelError, ILOG_TAG, __FILENAME__, __FUNCTION__, __LINE__).console().writeLog(__VA_ARGS__)


NS_MSDK_BEGIN
    class MSDK_EXPORT MSDKLogger {
    public:
        MSDK_EXPORT_UE MSDKLogger(ILogLevel level, const char *tag, const char *fileName, const char *funcName, int line);

        MSDK_EXPORT_UE ~MSDKLogger();

        // 是否打印日志到控制台
        MSDK_EXPORT_UE MSDKLogger &console();

        // 若是JSON日志，需格式化
        MSDKLogger &json() ;
#if MSDK_ENGINE_UE4_SIMULATE_LOGIN
        MSDK_EXPORT_UE MSDKLogger &writeLog(const char *fmt, ...);
#else
        // 此接口独立出来 - 方便后续格式化
        MSDKLogger &writeLog(const char *fmt, ...)__attribute__((format(printf, 2, 3)));
#endif

    private:
        ILogInfo info;
        bool isConsole;
        bool isJson;
        String curLogMsg;
    };

NS_MSDK_END

NS_MSDK_SPACE_NO_STL_BEGIN

using MSDKLogger = MSDK::MSDKLogger;

NS_MSDK_SPACE_NO_STL_END

#endif
#endif
#endif
