#include "CrashSightBridgeWin.h"

#define CS_INVOKE_CHECK(is_inited, function_ptr) \
    if (!is_inited || function_ptr == nullptr) { \
        return;                                  \
    }

namespace CrashSight {

#if PLATFORM_WINDOWS
#pragma warning (disable:4191)
    HINSTANCE CrashSightBridge::crashsight_dll_ = nullptr;
#else
    void *CrashSightBridge::crashsight_dll_ = nullptr;
#endif

    bool CrashSightBridge::is_inited_ = false;

    CS_InitContext     CrashSightBridge::init_context_ptr_     = nullptr;
    CS_ReportException CrashSightBridge::report_exception_ptr_ = nullptr;
    CS_ReportCrash     CrashSightBridge::report_crash_ptr_     = nullptr;
    CS_ReportDump      CrashSightBridge::report_dump_ptr_      = nullptr;

    CS_SetCrashCallback CrashSightBridge::set_crash_callback_ptr_ = nullptr;
    CS_SetUserValue     CrashSightBridge::set_user_value_ptr_     = nullptr;
    CS_SetVehEnable     CrashSightBridge::set_veh_enable_ptr_     = nullptr;
    CS_SetExtraHandler  CrashSightBridge::set_extra_handler_ptr_  = nullptr;
    CS_SetCustomLogDir  CrashSightBridge::set_custom_log_dir_ptr_ = nullptr;
    CS_SetUserId        CrashSightBridge::set_user_id_ptr_        = nullptr;

    CS_MonitorEnable             CrashSightBridge::monitor_enable_ptr_               = nullptr;
    CS_PrintLog                  CrashSightBridge::print_log_ptr_                    = nullptr;
    CS_UploadGivenPathDump       CrashSightBridge::upload_given_path_dump_ptr_       = nullptr;
    CS_UnrealCriticalErrorEnable CrashSightBridge::unreal_critical_error_enable_ptr_ = nullptr;

    int CrashSightBridge::InitBridge() {
#if PLATFORM_WINDOWS
        crashsight_dll_ = LoadLibrary(L"CrashSight64.dll");
    if (crashsight_dll_ != nullptr) {
        init_context_ptr_     = (CS_InitContext)GetProcAddress(crashsight_dll_, "CS_InitContext");
        report_exception_ptr_ = (CS_ReportException)GetProcAddress(crashsight_dll_, "CS_ReportException");
        report_crash_ptr_     = (CS_ReportCrash)GetProcAddress(crashsight_dll_, "CS_ReportCrash");
        report_dump_ptr_      = (CS_ReportDump)GetProcAddress(crashsight_dll_, "CS_ReportDump");

        set_crash_callback_ptr_ = (CS_SetCrashCallback)GetProcAddress(crashsight_dll_, "CS_SetCrashCallback");
        set_user_value_ptr_     = (CS_SetUserValue)GetProcAddress(crashsight_dll_, "CS_SetUserValue");
        set_veh_enable_ptr_     = (CS_SetVehEnable)GetProcAddress(crashsight_dll_, "CS_SetVehEnable");
        set_extra_handler_ptr_  = (CS_SetExtraHandler)GetProcAddress(crashsight_dll_, "CS_SetExtraHandler");
        set_custom_log_dir_ptr_ = (CS_SetCustomLogDir)GetProcAddress(crashsight_dll_, "CS_SetCustomLogDir");
        set_user_id_ptr_        = (CS_SetUserId)GetProcAddress(crashsight_dll_, "CS_SetUserId");

        monitor_enable_ptr_         = (CS_MonitorEnable)GetProcAddress(crashsight_dll_, "CS_MonitorEnable");
        print_log_ptr_              = (CS_PrintLog)GetProcAddress(crashsight_dll_, "CS_PrintLog");
        upload_given_path_dump_ptr_ = (CS_UploadGivenPathDump)GetProcAddress(crashsight_dll_, "CS_UploadGivenPathDump");
        unreal_critical_error_enable_ptr_ =
            (CS_UnrealCriticalErrorEnable)GetProcAddress(crashsight_dll_, "CS_UnrealCriticalErrorEnable");

        is_inited_ = true;
        return 0;
    } else {
        return -1;
    }
#else
        return -1;
#endif
    }

    int CrashSightBridge::InitContext(const char *user_id, const char *version, const char *key) {
        if (!is_inited_) {
            InitBridge();
        }

        if (is_inited_ && init_context_ptr_ != nullptr) {
            if (monitor_enable_ptr_ != nullptr) {
                monitor_enable_ptr_(false);
            }
            init_context_ptr_(user_id, version, key);
            return 0;
        }
        return -1;
    }
    void CrashSightBridge::ReportException(int type, const char *exp_name, const char *exp_message, const char *stack_trace,
                                           const char *extras, bool is_async = true) {
        CS_INVOKE_CHECK(is_inited_, report_exception_ptr_)
        report_exception_ptr_(type, exp_name, exp_message, stack_trace, extras, true);
    }
    void CrashSightBridge::ReportCrash() {
        CS_INVOKE_CHECK(is_inited_, report_crash_ptr_)
        report_crash_ptr_();
    }
    void CrashSightBridge::ReportDump(const char *dump_path, bool is_async) {
        CS_INVOKE_CHECK(is_inited_, report_dump_ptr_)
        report_dump_ptr_(dump_path, is_async);
    }

    void CrashSightBridge::SetCrashCallback(CrashCallbackFuncPtr callback) {
        CS_INVOKE_CHECK(is_inited_, set_crash_callback_ptr_)
        set_crash_callback_ptr_(callback);
    }
    void CrashSightBridge::SetUserValue(const char *key, const char *value) {
        CS_INVOKE_CHECK(is_inited_, set_user_value_ptr_)
        set_user_value_ptr_(key, value);
    }
    void CrashSightBridge::SetVehEnable(bool enable) {
        CS_INVOKE_CHECK(is_inited_, set_veh_enable_ptr_)
        set_veh_enable_ptr_(enable);
    }
    void CrashSightBridge::SetExtraHandler(bool extra_handle_enable) {
        CS_INVOKE_CHECK(is_inited_, set_extra_handler_ptr_)
        set_extra_handler_ptr_(extra_handle_enable);
    }
    void CrashSightBridge::SetCustomLogDir(const char *log_path) {
        CS_INVOKE_CHECK(is_inited_, set_custom_log_dir_ptr_)
        set_custom_log_dir_ptr_(log_path);
    }
    void CrashSightBridge::SetUserId(const char *user_id) {
        CS_INVOKE_CHECK(is_inited_, set_user_id_ptr_)
        set_user_id_ptr_(user_id);
    }

    void CrashSightBridge::MonitorEnable(bool enable) {
        CS_INVOKE_CHECK(is_inited_, monitor_enable_ptr_)
        monitor_enable_ptr_(enable);
    }
    void CrashSightBridge::PrintLog(LogSeverity level, const char *tag, const char *format, ...) {
        CS_INVOKE_CHECK(is_inited_, print_log_ptr_)
        print_log_ptr_(level, tag, format);
    }
    void CrashSightBridge::UploadGivenPathDump(const char *dump_dir, bool is_extra_check) {
        CS_INVOKE_CHECK(is_inited_, upload_given_path_dump_ptr_)
        upload_given_path_dump_ptr_(dump_dir, is_extra_check);
    }

    void CrashSightBridge::UnrealCriticalErrorEnable(bool enable) {
        CS_INVOKE_CHECK(is_inited_, unreal_critical_error_enable_ptr_)
        unreal_critical_error_enable_ptr_(enable);
    }

}  // namespace CrashSight
