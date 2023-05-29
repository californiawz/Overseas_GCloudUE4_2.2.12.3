//
// Created by hakimhuang on 2018/4/12.
//

#ifndef MSDK_MSDKLOGBASE_H
#define MSDK_MSDKLOGBASE_H

#include "MSDKMacros.h"
#include "MSDKMutex.h"
#if MSDK_ENGINE_UE4_PLATFORM_WINDOWS
#else
#include <unistd.h>
#include "zlib.h"
#endif



#ifndef ILOG_TAG
#define ILOG_TAG "[MSDK]"
#endif

#define MAX_LOGFILE_SIZE 1024 * 1024  // 文件大小
#define MAX_LOG_BUFFER_SIZE 4906
#define MAX_EVERYLOG_SIZE 2048            // 每一条日志的大小
#define MAX_HTTP_EVERYLOG_SIZE 48 * 1024  // 每次上传的上传文件大小
#define MAX_THEAD_COUNT 40960             // 线程执行的最大循环次数
#define THEAD_SLEEP_UMS 40000             // 休眠40ms
#define MAX_QUEUE_SIZE 1024               // 大于1024返回失败
#define MAX_FILE_NUMBER 10                // 文件的最大number数
#define MAX_EXIST_FILE_NUMBER 3           // 存在文件的最大个数
#define MAX_RETRY_TIMES 2                 // 块上报重试次数（一周期内）
#define MAX_RETRY_PRIODS_TIMES 2          // 块上报重试周期数


typedef struct {
    int mode;                             // 模式，判断为console, http
    int level;                            // 打印的日志level
    char mapPtr[MAX_EVERYLOG_SIZE + 1];   // 分配1024字节
    long mapLength;
} LogQueueNode;

typedef struct {
    int length;
    char bufferArr[MAX_HTTP_EVERYLOG_SIZE + 2 * MAX_EVERYLOG_SIZE + 2];
} LogHttpNode;

typedef struct {
    bool isValid;
    int retryTimes;
    int periodTimes;
    int logSeqId;
    std::string postData, url;
} RetryPostData;


typedef enum {
    kLevelDebug = 0,  // 调试使用日志  精简日志，kLevelVerbose、kLevelInfo、kLevelWarn 都合并成Debug
    kLevelError,  // 错误日志
} ILogLevel;


// 前三种模式可共存 使用 & 操作
typedef enum {
    kConsole = 0x1,       // 打印控制台
    kFile = 0x2,          // 打印文件
    kHttp = 0x4,          // 文件上报
    kRealTimeHttp = 0x8,  // 实时上报
} ULogMode;

typedef struct {
    ILogLevel level;
    const char *tag;
    const char *fileName;
    const char *funcName;
    int line;
#if MSDK_ENGINE_UE4_PLATFORM_WINDOWS
#else
    struct timeval timeval;
#endif
    long long pid;
    long long tid;
    long long mainTid;
    bool usingGCloudLog;
} ILogInfo;


class MSDKLogUtil {
public:

    // 日志打印锁
    static GCloud::MSDK::MSDKMutex lock;

    static long long getMainTid() {
#if MSDK_ENGINE_UE4_PLATFORM_WINDOWS
        return -1;
#else
#ifdef __APPLE__
        return -1;
#else
        return gettid();
#endif
#endif
    }

    static long long getTid() {
#if MSDK_ENGINE_UE4_PLATFORM_WINDOWS
        return -1;
#else
#ifdef __APPLE__
        return -1;
#else
        return pthread_self();
#endif
#endif
    }

    static long long getPid() {
#if MSDK_ENGINE_UE4_PLATFORM_WINDOWS
        return -1;
#else
        return getpid();
#endif
    }

    static void consoleLog(const int level, const char *resultLog, ...);

    static void consoleFormatLogVA(const ILogInfo *info, const char *message);

    static void consoleFormatLog(const ILogInfo *info, const char *format);

    static void writeLog(const ILogInfo *info, const char *log);

    static bool compressLog(std::string &originalLog);

    static bool decompressLog(std::string &compressLog);
    
    // 设置日志：日志级别和日志模式（MSDK or GCloud）
    static void resetLogSetting();
    
    static ILogLevel curLogLevel;
    
    static bool getGCloudLogEnable();
    static bool getIsDisableLog();

    // MSDK 日志测试代码
    static void runMSDKLogTest();
    
private:
    static bool gcloudLogEnable;
    static bool isDisableLog;
};

#endif //ANDROID_MSDKLOGDEFINE_H
