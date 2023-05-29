#ifndef AllLifecycleRegister_h
#define AllLifecycleRegister_h


#import <GCloudCore/GCloudAppLifecycleObserver.h>

//TDM
#import "PluginReportLifecycle.h"
REGISTER_LIFECYCLE_OBSERVER(PluginReportLifecycle);

//CrashSight
#import "CSLifecycle.h"
REGISTER_LIFECYCLE_OBSERVER(CSLifecycle);

//GCloud_Ano
#import "GCloudAppLifecycleListener.h"
REGISTER_LIFECYCLE_OBSERVER(GCloudAppLifecycleListener);

//GPM_Ano
#import "GPMLifecycle.h"
REGISTER_LIFECYCLE_OBSERVER(GPMLifecycle);

//GVoice_Ano
#import "PluginGVoiceLifecycle.h"
REGISTER_LIFECYCLE_OBSERVER(PluginGVoiceLifecycle);

//MSDKCore_Ano
#import "PluginMSDKLifecycle.h"
REGISTER_LIFECYCLE_OBSERVER(PluginMSDKLifecycle);

//TssSDKAno
#import "PluginTssSDKLifecycle.h"
REGISTER_LIFECYCLE_OBSERVER(PluginTssSDKLifecycle);


#endif