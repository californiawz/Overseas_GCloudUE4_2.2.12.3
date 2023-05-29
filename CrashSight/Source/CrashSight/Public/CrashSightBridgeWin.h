#pragma once
#if PLATFORM_WINDOWS
#include "Windows/WindowsHWrapper.h"
#endif
namespace CrashSight {

enum LogSeverity { Log, LogDebug, LogInfo, LogWarning, LogAssert, LogError, LogException };
typedef void (*CrashCallbackFuncPtr)(int type, const char *guid);

typedef void (*CS_InitContext)(const char *id, const char *version, const char *key);
typedef void (*CS_ReportException)(int type, const char *name, const char *message, const char *stackTrace,
                                   const char *extras, bool is_async);
typedef void (*CS_ReportCrash)();
typedef void (*CS_ReportDump)(const char *dump_path, bool is_async);

typedef void (*CS_SetCrashCallback)(CrashCallbackFuncPtr callback);
typedef void (*CS_SetUserValue)(const char *key, const char *value);
typedef void (*CS_SetVehEnable)(bool enable);
typedef void (*CS_SetExtraHandler)(bool extra_handle_enable);
typedef void (*CS_SetCustomLogDir)(const char *log_path);
typedef void (*CS_SetUserId)(const char *log_path);

typedef void (*CS_MonitorEnable)(bool enable);
typedef void (*CS_PrintLog)(LogSeverity level, const char *tag, const char *format, ...);
typedef void (*CS_UploadGivenPathDump)(const char *dump_dir, bool is_extra_check);
typedef void (*CS_UnrealCriticalErrorEnable)(bool enable);

class CRASHSIGHT_API CrashSightBridge {
   private:
#if PLATFORM_WINDOWS
    static HINSTANCE crashsight_dll_;
#else
    static void *crashsight_dll_;
#endif
    static bool is_inited_;

    static CS_InitContext     init_context_ptr_;
    static CS_ReportException report_exception_ptr_;
    static CS_ReportCrash     report_crash_ptr_;
    static CS_ReportDump      report_dump_ptr_;

    static CS_SetCrashCallback set_crash_callback_ptr_;
    static CS_SetUserValue     set_user_value_ptr_;
    static CS_SetVehEnable     set_veh_enable_ptr_;
    static CS_SetExtraHandler  set_extra_handler_ptr_;
    static CS_SetCustomLogDir  set_custom_log_dir_ptr_;
    static CS_SetUserId        set_user_id_ptr_;

    static CS_MonitorEnable             monitor_enable_ptr_;
    static CS_PrintLog                  print_log_ptr_;
    static CS_UploadGivenPathDump       upload_given_path_dump_ptr_;
    static CS_UnrealCriticalErrorEnable unreal_critical_error_enable_ptr_;

public:
    static int  InitBridge();
    static void MonitorEnable(bool enable);
    static void SetVehEnable(bool enable);

    static int  InitContext(const char *user_id, const char *version, const char *key);
    static void ReportException(int type, const char *exp_name, const char *exp_message, const char *stack_trace,
                                const char *extras, bool is_async);
    static void ReportCrash();
    static void ReportDump(const char *dump_path, bool is_async);

    static void SetCrashCallback(CrashCallbackFuncPtr callback);
    static void SetUserValue(const char *key, const char *value);
    static void SetExtraHandler(bool extra_handle_enable);
    static void SetCustomLogDir(const char *log_path);
    static void SetUserId(const char *user_id);

    static void PrintLog(LogSeverity level, const char *tag, const char *format, ...);
    static void UploadGivenPathDump(const char *dump_dir, bool is_extra_check);
    static void UnrealCriticalErrorEnable(bool enable);
};

}  // namespace CrashSight
