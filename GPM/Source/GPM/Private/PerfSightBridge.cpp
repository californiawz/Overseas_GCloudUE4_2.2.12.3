#include "PerfSightBridge.h"

#if PLATFORM_WINDOWS
#define PS_INVOKE_CHECK(is_inited, function, param) \
    if (is_inited_ && function != nullptr) {        \
        function(param);                            \
    }

#define PS_INVOKE_CHECK_NO_PARAM(is_inited, function) \
    if (is_inited_ && function != nullptr) {          \
        function();                                   \
    }
namespace PerfSight {

HINSTANCE PerfSightBridge::perfsight_dll_ = nullptr;
bool      PerfSightBridge::is_inited_     = false;

PS_InitContext PerfSightBridge::init_context_ptr_ = nullptr;

PS_MarkLevelLoad          PerfSightBridge::mark_level_load_ptr_           = nullptr;
PS_MarkLevelLoadCompleted PerfSightBridge::mark_level_load_completed_ptr_ = nullptr;
PS_MarkLevelFin           PerfSightBridge::mark_level_fin_ptr_            = nullptr;

PS_SetOpenId             PerfSightBridge::set_open_id_ptr_              = nullptr;
PS_SetQuality            PerfSightBridge::set_quality_ptr_              = nullptr;
PS_SetAppVersion         PerfSightBridge::set_app_version_ptr_          = nullptr;
PS_SetStrategy           PerfSightBridge::set_strategy_ptr_             = nullptr;
PS_SetServerUrl          PerfSightBridge::set_server_url_ptr_           = nullptr;
PS_SetDefinedDeviceClass PerfSightBridge::set_defined_device_class_ptr_ = nullptr;
PS_SetVersionName        PerfSightBridge::set_version_name_ptr_         = nullptr;

PS_BeginTag     PerfSightBridge::begin_tag_ptr_     = nullptr;
PS_EndTag       PerfSightBridge::end_tag_ptr_       = nullptr;
    PS_BeginExtTag     PerfSightBridge::begin_ext_tag_ptr_     = nullptr;
    PS_EndExtTag       PerfSightBridge::end_ext_tag_ptr_       = nullptr;
PS_BeginExclude PerfSightBridge::begin_exclude_ptr_ = nullptr;
PS_EndExclude   PerfSightBridge::end_exclude_ptr_   = nullptr;

PS_PostFrame PerfSightBridge::post_frame_ptr_ = nullptr;

    PS_BeginTupleWrap     PerfSightBridge::begin_tuple_wrap_ptr_     = nullptr;
    PS_EndTupleWrap       PerfSightBridge::end_tuple_wrap_ptr_       = nullptr;
PS_PostValueF1        PerfSightBridge::post_value_f1_ptr_        = nullptr;
PS_PostValueF2        PerfSightBridge::post_value_f2_ptr_        = nullptr;
PS_PostValueF3        PerfSightBridge::post_value_f3_ptr_        = nullptr;
PS_PostValueI1        PerfSightBridge::post_value_i1_ptr_        = nullptr;
PS_PostValueI2        PerfSightBridge::post_value_i2_ptr_        = nullptr;
PS_PostValueI3        PerfSightBridge::post_value_i3_ptr_        = nullptr;
PS_PostValueS         PerfSightBridge::post_value_s_ptr_         = nullptr;
PS_PostEvent          PerfSightBridge::post_event_ptr_           = nullptr;
PS_PostNetworkLatency PerfSightBridge::post_network_latency_ptr_ = nullptr;

int PerfSightBridge::InitBridge() {
    perfsight_dll_ = LoadLibrary(L"PerfSight.dll");
    if (perfsight_dll_ != nullptr) {
        init_context_ptr_ = (PS_InitContext)GetProcAddress(perfsight_dll_, "PS_InitContext");

        mark_level_load_ptr_ = (PS_MarkLevelLoad)GetProcAddress(perfsight_dll_, "PS_MarkLevelLoad");
        mark_level_load_completed_ptr_ =
            (PS_MarkLevelLoadCompleted)GetProcAddress(perfsight_dll_, "PS_MarkLevelLoadCompleted");
        mark_level_fin_ptr_ = (PS_MarkLevelFin)GetProcAddress(perfsight_dll_, "PS_MarkLevelFin");

        set_open_id_ptr_ = (PS_SetOpenId)GetProcAddress(perfsight_dll_, "PS_SetOpenId");
        set_quality_ptr_ = (PS_SetQuality)GetProcAddress(perfsight_dll_, "PS_SetQuality");
        set_defined_device_class_ptr_ =
            (PS_SetDefinedDeviceClass)GetProcAddress(perfsight_dll_, "PS_SetDefinedDeviceClass");
        set_strategy_ptr_     = (PS_SetStrategy)GetProcAddress(perfsight_dll_, "PS_SetStrategy");
        set_server_url_ptr_   = (PS_SetServerUrl)GetProcAddress(perfsight_dll_, "PS_SetServerUrl");
        set_version_name_ptr_ = (PS_SetVersionName)GetProcAddress(perfsight_dll_, "PS_SetVersionName");
        set_app_version_ptr_  = (PS_SetAppVersion)GetProcAddress(perfsight_dll_, "PS_SetAppVersion");

        begin_ext_tag_ptr_     = (PS_BeginExtTag)GetProcAddress(perfsight_dll_, "PS_BeginExtTag");
        end_ext_tag_ptr_       = (PS_EndExtTag)GetProcAddress(perfsight_dll_, "PS_EndExtTag");
        begin_tag_ptr_     = (PS_BeginTag)GetProcAddress(perfsight_dll_, "PS_BeginTag");
        end_tag_ptr_       = (PS_EndTag)GetProcAddress(perfsight_dll_, "PS_EndTag");
        begin_exclude_ptr_ = (PS_BeginExclude)GetProcAddress(perfsight_dll_, "PS_BeginExclude");
        end_exclude_ptr_   = (PS_EndExclude)GetProcAddress(perfsight_dll_, "PS_EndExclude");

        post_frame_ptr_ = (PS_PostFrame)GetProcAddress(perfsight_dll_, "PS_PostFrame");

        begin_tuple_wrap_ptr_     = (PS_BeginTupleWrap)GetProcAddress(perfsight_dll_, "PS_BeginTupleWrap");
        end_tuple_wrap_ptr_       = (PS_EndTupleWrap)GetProcAddress(perfsight_dll_, "PS_EndTupleWrap");
        post_value_f1_ptr_        = (PS_PostValueF1)GetProcAddress(perfsight_dll_, "PS_PostValueF1");
        post_value_f2_ptr_        = (PS_PostValueF2)GetProcAddress(perfsight_dll_, "PS_PostValueF2");
        post_value_f3_ptr_        = (PS_PostValueF3)GetProcAddress(perfsight_dll_, "PS_PostValueF3");
        post_value_i1_ptr_        = (PS_PostValueI1)GetProcAddress(perfsight_dll_, "PS_PostValueI1");
        post_value_i2_ptr_        = (PS_PostValueI2)GetProcAddress(perfsight_dll_, "PS_PostValueI2");
        post_value_i3_ptr_        = (PS_PostValueI3)GetProcAddress(perfsight_dll_, "PS_PostValueI3");
        post_value_s_ptr_         = (PS_PostValueS)GetProcAddress(perfsight_dll_, "PS_PostValueS");
        post_event_ptr_           = (PS_PostEvent)GetProcAddress(perfsight_dll_, "PS_PostEvent");
        post_network_latency_ptr_ = (PS_PostNetworkLatency)GetProcAddress(perfsight_dll_, "PS_PostNetworkLatency");
        is_inited_                = true;
        return 0;
    } else {
        return -1;
    }
}

int PerfSightBridge::InitContext(const char *app_id, bool debug) {
    InitBridge();
    if (is_inited_ && init_context_ptr_ != nullptr) {
        init_context_ptr_(app_id, debug);
        return 0;
    }
    return -1;
}

void PerfSightBridge::MarkLevelLoad(const char *scene_id) {
    PS_INVOKE_CHECK(is_inited_, mark_level_load_ptr_, scene_id)
}
void PerfSightBridge::MarkLevelLoadCompleted() { PS_INVOKE_CHECK_NO_PARAM(is_inited_, mark_level_load_completed_ptr_) }
void PerfSightBridge::MarkLevelFin() { PS_INVOKE_CHECK_NO_PARAM(is_inited_, mark_level_fin_ptr_) }

void PerfSightBridge::SetOpenId(const char *open_id) { PS_INVOKE_CHECK(is_inited_, set_open_id_ptr_, open_id) }
void PerfSightBridge::SetAppVersion(const char *app_version) {
    PS_INVOKE_CHECK(is_inited_, set_app_version_ptr_, app_version)
}
void PerfSightBridge::SetQuality(int quality) { PS_INVOKE_CHECK(is_inited_, set_quality_ptr_, quality) }
void PerfSightBridge::SetDefinedDeviceClass(int device_class) {
    PS_INVOKE_CHECK(is_inited_, set_defined_device_class_ptr_, device_class)
}
void PerfSightBridge::SetVersionName(const char *version_name) {
    PS_INVOKE_CHECK(is_inited_, set_version_name_ptr_, version_name)
}
void PerfSightBridge::SetStrategy(Strategy &strategy) { PS_INVOKE_CHECK(is_inited_, set_strategy_ptr_, strategy) }
void PerfSightBridge::SetServerUrl(const char *url) { PS_INVOKE_CHECK(is_inited_, set_server_url_ptr_, url) }

void PerfSightBridge::PostValueF(const char *category, const char *key, float a) {
    if (is_inited_ && post_value_f1_ptr_ != nullptr) {
        post_value_f1_ptr_(category, key, a);
    }
}
void PerfSightBridge::PostValueF(const char *category, const char *key, float a, float b) {
    if (is_inited_ && post_value_f2_ptr_ != nullptr) {
        post_value_f2_ptr_(category, key, a, b);
    }
}
void PerfSightBridge::PostValueF(const char *category, const char *key, float a, float b, float c) {
    if (is_inited_ && post_value_f3_ptr_ != nullptr) {
        post_value_f3_ptr_(category, key, a, b, c);
    }
}
void PerfSightBridge::PostValueI(const char *category, const char *key, int a) {
    if (is_inited_ && post_value_i1_ptr_ != nullptr) {
        post_value_i1_ptr_(category, key, a);
    }
}
void PerfSightBridge::PostValueI(const char *category, const char *key, int a, int b) {
    if (is_inited_ && post_value_i2_ptr_ != nullptr) {
        post_value_i2_ptr_(category, key, a, b);
    }
}
void PerfSightBridge::PostValueI(const char *category, const char *key, int a, int b, int c) {
    if (is_inited_ && post_value_i3_ptr_ != nullptr) {
        post_value_i3_ptr_(category, key, a, b, c);
    }
}
void PerfSightBridge::PostValueS(const char *category, const char *key, const char *value) {
    if (is_inited_ && post_value_s_ptr_ != nullptr) {
        post_value_s_ptr_(category, key, value);
    }
}

    void PerfSightBridge::BeginTupleWrap(const char *category) { PS_INVOKE_CHECK(is_inited_, begin_tuple_wrap_ptr_, category) }
    void PerfSightBridge::EndTupleWrap() { PS_INVOKE_CHECK_NO_PARAM(is_inited_, end_tuple_wrap_ptr_) }

void PerfSightBridge::PostEvent(int key, const char *value) {
    if (is_inited_ && post_event_ptr_ != nullptr) {
        post_event_ptr_(key, value);
    }
}
void PerfSightBridge::PostFrame(float delta_time) {
	PS_INVOKE_CHECK(is_inited_, post_frame_ptr_, delta_time)
}
void PerfSightBridge::PostNetworkLatency(int latency) {
    PS_INVOKE_CHECK(is_inited_, post_network_latency_ptr_, latency)
}

void PerfSightBridge::BeginTag(const char *tag_name) { PS_INVOKE_CHECK(is_inited_, begin_tag_ptr_, tag_name) }
void PerfSightBridge::EndTag() { PS_INVOKE_CHECK_NO_PARAM(is_inited_, end_tag_ptr_) }
    void PerfSightBridge::BeginExtTag(const char *tag_name) { PS_INVOKE_CHECK(is_inited_, begin_ext_tag_ptr_, tag_name) }
    void PerfSightBridge::EndExtTag(const char *tag_name) { PS_INVOKE_CHECK(is_inited_, end_ext_tag_ptr_, tag_name) }

void PerfSightBridge::BeginExclude() { PS_INVOKE_CHECK_NO_PARAM(is_inited_, begin_exclude_ptr_) }
void PerfSightBridge::EndExclude() { PS_INVOKE_CHECK_NO_PARAM(is_inited_, end_exclude_ptr_) }

}  // namespace PerfSight
#endif//windows