#pragma once
#if defined(PLATFORM_WINDOWS) && defined(_WIN64)
#include <Windows/WindowsHWrapper.h>
#define APM_WIN64
#endif

namespace PerfSight {
    struct Strategy {
        bool process_info_enable  = true;
        bool gpu_info_enable      = true;
        bool cpu_info_enbale      = true;
        bool mem_info_enable      = true;
        bool graphics_info_enable = true;

        int process_info_interval = 1;
        int gpu_info_interval     = 1;
        int cpu_info_interval     = 1;
        int mem_info_interval     = 1;
    };
#ifdef APM_WIN64
    typedef int (*PS_InitContext)(const char *app_id, bool debug);
typedef int (*PS_MarkLevelLoad)(const char *scene_id);
typedef int (*PS_MarkLevelLoadCompleted)();
typedef int (*PS_MarkLevelFin)();

typedef void (*PS_SetOpenId)(const char *open_id);
typedef void (*PS_SetQuality)(int quality);
typedef void (*PS_SetAppVersion)(const char *app_version);
typedef void (*PS_SetStrategy)(Strategy& strategy);
typedef void (*PS_SetServerUrl)(const char *url);
typedef void (*PS_SetDefinedDeviceClass)(int device_class);
typedef void (*PS_SetVersionName)(const char *version_name);

typedef void (*PS_BeginTag)(const char *tag_name);
typedef void (*PS_EndTag)();
typedef void (*PS_BeginExtTag)(const char *tag_name);
typedef void (*PS_EndExtTag)(const char *tag_name);
typedef void (*PS_BeginExclude)();
typedef void (*PS_EndExclude)();

typedef void (*PS_PostFrame)(float delta_time);

typedef void (*PS_BeginTupleWrap)(const char *tag_name);
typedef void (*PS_EndTupleWrap)();
typedef void (*PS_PostValueF1)(const char *category, const char *key, float a);
typedef void (*PS_PostValueF2)(const char *category, const char *key, float a, float b);
typedef void (*PS_PostValueF3)(const char *category, const char *key, float a, float b, float c);
typedef void (*PS_PostValueI1)(const char *category, const char *key, int a);
typedef void (*PS_PostValueI2)(const char *category, const char *key, int a, int b);
typedef void (*PS_PostValueI3)(const char *category, const char *key, int a, int b, int c);
typedef void (*PS_PostValueS)(const char *category, const char *key, const char *value);
typedef void (*PS_PostEvent)(int key, const char *value);
typedef void (*PS_PostNetworkLatency)(int latency);

class PerfSightBridge {
   private:
    static HINSTANCE perfsight_dll_;
    static bool      is_inited_;

    static PS_InitContext init_context_ptr_;

    static PS_MarkLevelLoad          mark_level_load_ptr_;
    static PS_MarkLevelLoadCompleted mark_level_load_completed_ptr_;
    static PS_MarkLevelFin           mark_level_fin_ptr_;

    static PS_SetOpenId             set_open_id_ptr_;
    static PS_SetQuality            set_quality_ptr_;
    static PS_SetAppVersion         set_app_version_ptr_;
    static PS_SetStrategy           set_strategy_ptr_;
    static PS_SetServerUrl          set_server_url_ptr_;
    static PS_SetDefinedDeviceClass set_defined_device_class_ptr_;
    static PS_SetVersionName        set_version_name_ptr_;

    static PS_BeginExtTag  begin_ext_tag_ptr_;
    static PS_EndExtTag    end_ext_tag_ptr_;
    static PS_BeginTag     begin_tag_ptr_;
    static PS_EndTag       end_tag_ptr_;
    static PS_BeginExclude begin_exclude_ptr_;
    static PS_EndExclude   end_exclude_ptr_;

    static PS_PostFrame post_frame_ptr_;

    static PS_BeginTupleWrap     begin_tuple_wrap_ptr_;
    static PS_EndTupleWrap       end_tuple_wrap_ptr_;
    static PS_PostValueF1        post_value_f1_ptr_;
    static PS_PostValueF2        post_value_f2_ptr_;
    static PS_PostValueF3        post_value_f3_ptr_;
    static PS_PostValueI1        post_value_i1_ptr_;
    static PS_PostValueI2        post_value_i2_ptr_;
    static PS_PostValueI3        post_value_i3_ptr_;
    static PS_PostValueS         post_value_s_ptr_;
    static PS_PostEvent          post_event_ptr_;
    static PS_PostNetworkLatency post_network_latency_ptr_;

   public:
    static int InitBridge();
    static int InitContext(const char *app_id, bool debug);

	// 场景开始
    static void MarkLevelLoad(const char *scene_id);
    // 场景加载结束
    static void MarkLevelLoadCompleted();
    // 场景结束
    static void MarkLevelFin();

	// 设置用户名
    static void SetOpenId(const char *open_id);
    // 设置应用版本号
    static void SetAppVersion(const char *app_version);
	// 设置画质
    static void SetQuality(int quality);
	// 设置自定义机型档位
    static void SetDefinedDeviceClass(int device_class);
	// 设置版本号
    static void SetVersionName(const char *version_name);
	// 设置数据采集策略
    static void SetStrategy(Strategy& strategy);
	// 设置数据上报域名
    static void SetServerUrl(const char *url);

	// 开始，结束自定义标记
    static void BeginTag(const char *tag_name);
    static void EndTag();
    static void BeginExtTag(const char *tag_name);
    static void EndExtTag(const char *tag_name);

    // 开始，结束数据剔除时间段
    static void BeginExclude();
    static void EndExclude();

    // 记录帧结束标记
    static void PostFrame(float delta_time);

	// 记录自定义数据， 事件
	static void BeginTupleWrap(const char *category);
    static void EndTupleWrap();
    static void PostValueF(const char *category, const char *key, float a);
    static void PostValueF(const char *category, const char *key, float a, float b);
    static void PostValueF(const char *category, const char *key, float a, float b, float c);
    static void PostValueI(const char *category, const char *key, int a);
    static void PostValueI(const char *category, const char *key, int a, int b);
    static void PostValueI(const char *category, const char *key, int a, int b, int c);
    static void PostValueS(const char *category, const char *key, const char *value);
    static void PostEvent(int key, const char *value = "NA");
	// 记录网络延时
    static void PostNetworkLatency(int latency);


};

#endif

}  // namespace perfsight
