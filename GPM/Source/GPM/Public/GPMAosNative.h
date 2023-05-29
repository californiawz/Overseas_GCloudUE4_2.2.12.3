#define GPM_JNIEXPORT  __attribute__ ((visibility ("default")))

extern "C"
{

#define PARAM_TYPE_INT                 1
#define PARAM_TYPE_INT_INT             2
#define PARAM_TYPE_INT_INT_INT         3
#define PARAM_TYPE_FLOAT               4
#define PARAM_TYPE_FLOAT_FLOAT         5
#define PARAM_TYPE_FLOAT_FLOAT_FLOAT   6
#define PARAM_TYPE_STR                 7

GPM_JNIEXPORT void tapmNativePostVFloat(int type, const char *category, const char *key, float a, float b, float c, unsigned int frameIdx);
GPM_JNIEXPORT void tapmNativePostVInt(int type, const char *category, const char *key, int a, int b, int c, unsigned int frameIdx);
GPM_JNIEXPORT void tapmNativePostV1S(const char *category, const char *key, const char *value, unsigned int frameIdx);
GPM_JNIEXPORT void
tapmNativePostValueCoordinate(const char *category, const char *key, float x, float y, float z, float pitch, float yaw, float roll, unsigned int frameIdx);
GPM_JNIEXPORT void tapmNativeBeginTupleWrap(const char *key);
GPM_JNIEXPORT void tapmNativeEndTupleWrap();
GPM_JNIEXPORT void tapmNativePostFrame(int frameTime, unsigned int frameIdx);
GPM_JNIEXPORT void tapmNativePostNTL(int latency);
GPM_JNIEXPORT void tapmNativePostCoordinate(float x, float y, float z, float pitch, float yaw, float roll);
GPM_JNIEXPORT bool tapmNativeSetPostValueQueueLength(int length);
GPM_JNIEXPORT void tapmNativeGetCpuAffinity();
GPM_JNIEXPORT int  tapmNativeGetCpuTemp(bool useCache);
GPM_JNIEXPORT void tapmNativeSetMatchId(const char * matchId);
GPM_JNIEXPORT void tapmNativeSetCustomizedDeviceID(const char * deviceId);
GPM_JNIEXPORT void tapmNativeAddTraceThread(const char* threadName);
GPM_JNIEXPORT void tapmNativeRemoveTraceThread(const char* threadName);
GPM_JNIEXPORT bool tapmNativeIsKvMsgFull();
}