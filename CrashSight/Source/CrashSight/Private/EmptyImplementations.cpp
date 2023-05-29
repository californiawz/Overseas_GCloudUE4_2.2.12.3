#include"UQMCrash.h"
#include"CrashSightAgent.h"

using namespace GCloud::CrashSight;
using namespace UQM;

#if PLATFORM_WINDOWS || PLATFORM_MAC
void CrashSightAgent::SetGameType(int gameType) {}
void CrashSightAgent::ConfigCallbackType(int32_t callbackType) {}
void CrashSightAgent::ConfigDefault(const char* channel, const char* version, const char* user, long delay) {}
void CrashSightAgent::ConfigCrashServerUrl(const char* crashServerUrl) {}
void CrashSightAgent::ConfigCrashReporter(int logLevel) {}
void CrashSightAgent::ConfigDebugMode(bool enable) {}
void CrashSightAgent::SetDeviceId(const char* deviceId) {}
void CrashSightAgent::SetCustomizedDeviceID(const char* deviceId) {}
void CrashSightAgent::GetSDKDefinedDeviceID(void* data, int len) {}
void CrashSightAgent::SetCustomizedMatchID(const char* matchId) {}
void CrashSightAgent::GetSDKSessionID(void* data, int len) {}
void CrashSightAgent::SetDeviceModel(const char* deviceModel) {}
void CrashSightAgent::SetLogPath(const char* logPath) {}
void CrashSightAgent::InitWithAppId(const char* appId) {}

void CrashSightAgent::ReportExceptionPRV(int type, const char* exceptionName, 
							   const char* exceptionMsg, 
								const char* exceptionStack, 
								const UQM::UQMVector<UQM::UQMKVPair>& extInfo, 
								const char* extInfoJsonStr, bool quit,
								int dumpNativeType) {}
void CrashSightAgent::ReportException(int type, const char* name, const char* reason, const char* stackTrace, const char* extras, bool quit, int dumpNativeType) {}
void CrashSightAgent::ReportExceptionJson(int type, const char* exceptionName, const char* exceptionMsg, const char* exceptionStack, const char* paramsJson, int dumpNativeType) {}
void CrashSightAgent::ReportLogInfo(const char* msgType, const char* msg) {}
void CrashSightAgent::SetUserId(const char* userId) {}
void CrashSightAgent::SetScene(int sceneId) {}
void CrashSightAgent::AddSceneData(const char* key, const char* value) {}
void CrashSightAgent::PrintLog(LogSeverity level, const char* format, ...) {}
int CrashSightAgent::GetPlatformCode() { return -1; }
void CrashSightAgent::CloseCrashReport() {}
void CrashSightAgent::StartCrashReport() {}
void CrashSightAgent::RestartCrashReport() {}
void CrashSightAgent::SetAppVersion(const char* appVersion) {}
void CrashSightAgent::SetCatchMultiSignal(bool enable) {}
void CrashSightAgent::SetUnwindExtraStack(bool enable) {}
long CrashSightAgent::GetCrashThreadId() { return -1; }
void CrashSightAgent::TestOomCrash() {}
void CrashSightAgent::TestJavaCrash() {}
void CrashSightAgent::TestOcCrash() {}
void CrashSightAgent::TestNativeCrash() {}
void CrashSightAgent::GetCrashUuid(void* data, int len) {}
const char* CrashSightAgent::GetCsVersion() { return NULL; }


void UQMCrash::CrashDataObserver(const UQMInnerCrashRet& crashRet, const char* seqID) {}
void UQMCrash::CrashMessageObserver(const UQMInnerCrashRet& crashRet, const char* seqID) {}
void UQMCrash::CrashSetLogPathObserver(const UQMInnerCrashRet& crashRet, const char* seqID) {}
void UQMCrash::CrashLogUploadResultObserver(const UQMInnerCrashRet& crashRet, const char* seqID) {}
UQMCrash::~UQMCrash() {}
void UQMCrash::SetPRVCrashObserver(T<UQMInnerCrashRet>::UQMInnerRetCallback crashObserver) {}
void UQMCrash::SetExtraMessageCrashObserver(T<UQMInnerCrashRet>::UQMInnerRetCallback crashObserver) {}
void UQMCrash::SetLogPathObserver(T<UQMInnerCrashRet>::UQMInnerRetCallback crashObserver) {}
void UQMCrash::SetLogUploadResultObserver(T<UQMInnerCrashRet>::UQMInnerRetCallback crashObserver) {}
void UQMCrash::SetCrashObserver(UQMCrashObserver* crashObserver) {}
void UQMCrash::SetCrashLogObserver(UQMCrashLogObserver* crashObserver) {}
void UQMCrash::ConfigCallbackTypeBeforeInit(int32_t callbackType) {}
void UQMCrash::ConfigCrashHandleTimeout(int32_t timeout) {}
void UQMCrash::Init(const UQMString& appId, bool unexpectedTerminatingDetectionEnable, bool debugMode, const UQMString& serverUrl) {}
void UQMCrash::LogInfo(int level, const UQMString& tag, const UQMString& log) {}
void UQMCrash::SetUserValue(const UQMString& key, const UQMString& value) {}
void UQMCrash::SetUserId(const UQMString& userId) {}
void UQMCrash::SetAppId(const UQMString& appId) {}
void UQMCrash::EntrySubMap(const UQMString& appId) {}
void UQMCrash::SetUserSceneTag(const UQMString& userSceneTag) {}
void UQMCrash::ReportExceptionPRV(int type, const UQMString& exceptionName, const UQMString& exceptionMsg, const UQMString& exceptionStack, const UQMVector<UQMKVPair>& extInfo, const UQMString& extInfoJsonStr, bool quit, int dumpNativeType) {}
void UQMCrash::SetIsAppForeground(bool isAppForeground) {}
void UQMCrash::SetAppVersion(const UQMString& appVersion) {}
void UQMCrash::InitWithAppId(const UQMString& appId) {}
void UQMCrash::ConfigDefaultBeforeInit(const UQMString& channel, const UQMString& version, const UQMString& user, long delay) {}
void UQMCrash::ConfigCrashServerUrlBeforeInit(const UQMString& crashServerUrl) {}
void UQMCrash::ConfigCrashReporterLogLevelBeforeInit(int logLevel) {}
void UQMCrash::ConfigDebugModeBeforeInit(bool enable) {}
void UQMCrash::SetDeviceId(const UQMString& deviceId) {}
void UQMCrash::SetCustomizedDeviceID(const UQMString& deviceId) {}
void UQMCrash::SetCustomizedMatchID(const UQMString& matchId) {}
void UQMCrash::SetDeviceModel(const UQMString& deviceModel) {}
void UQMCrash::SetLogPath(const UQMString& logPath) {}
void UQMCrash::SetCurrentScene(int sceneId) {}
void UQMCrash::LogRecord(int level, const UQMString& message) {}
#endif
