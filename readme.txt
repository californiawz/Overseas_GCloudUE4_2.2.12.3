1. GCloudSDK导入本地工程的详细步骤参见以下地址：

【GCloudSDK产品使用说明>接入指引】http://sdk.gcloud.oa.com/documents

如有任何疑问，欢迎咨询企业微信服务号： GCloud人工服务


2. 各个组件简单介绍

GCloudCore : GCloudSDK的核心，负责所有组件管理、以及App生命周期管理
GCloud : Connect, Maple, Dolphin, LockStep，Puffer等组件的集合，他们的底层都一样，已经合成一个。
APM : 手游客户端性能管理,手游用户体验监测工具
GEM : 游戏体验管理SDK
GVoice : 是一款支持多样玩法、全面覆盖游戏应用场景的语音服务SDK。
HttpDNS(DNS_OneSDK) : 智营解析,使用http协议代替传统解析域名
MidasLocal: 移动支付平台(国内版)
MidasOversea : 移动支付平台(海外版)
TDM: 组件内部数据上报通道。
TGPA: 腾讯游戏官方性能技术解决方案
GPM(TRI) :游戏体验管理大师 （Game Performance Master）,致力于提供一站式用户体验优化解决方案。(APM、GEM、TGPA三合一的组件)
TssSDKLocal: 手游安全SDK（国内版），致力于为游戏提供全面的安全防护
TssSDKOversea : 手游安全SDK（海外版）
GameBot(GRobot) : 游戏智能AI伴侣，以玩家伴侣身份在游戏各个阶段向玩家提供多场景、个性化的游戏陪伴服务。
MSDKCore : 是为游戏提供公共组件和服务库的平台，旨在加快游戏接入各公共组件和海外开放平台。
MSDKAdjust : MSDK子组件，主要用于海外数据上报Adjust平台
MSDKAppsFlyer : MSDK子组件，主要用于海外数据上报AppsFlyer平台
MSDKBeacon : MSDK子组件，主要用于数据上报灯塔平台
MSDKBugly : MSDK子组件，crash数据上报
MSDKFacebook : MSDK子组件，用于Facebook渠道相关功能
MSDKGameCenter : MSDK子组件，用于iOS gamecenter渠道登录等相关功能
MSDKGoogle : MSDK子组件，用于Google渠道相关功能
MSDKLBS : MSDK子组件，用于LBS定位服务相关功能
MSDKQQ : MSDK子组件，用于QQ渠道相关功能
MSDKTDM : MSDK子组件，主要用于数据上报TDM平台
MSDKTwitter : MSDK子组件，主要用于Twitter渠道相关功能
MSDKFirebase : MSDK子组件，主要用于Firebase推送和数据上报相关功能
MSDKGarena : MSDK子组件，主要用于Garena渠道相关登录、好友、以及其他扩展功能
MSDKWeChat : MSDK子组件，主要用于微信渠道相关功能
MSDKWebView : MSDK子组件，内置浏览器功能
MSDKXG : MSDK子组件，主要用于信鸽推送和数据上报
MSDKXGFCM : MSDK子组件，主要用于海外信鸽推送和数据上报
VideoRecord : 屏幕录制VideoRecord是一款稳定且具有高品质的录屏应用，玩家可在游戏中自由录制流畅清晰的视频， 并截取所需素材保存在本地。
GMall : 游戏商城 GMall 是一个连接前端和道聚城后台的轻量化框架，提供数据请求、响应、管理以及道具获取和购买等基础功能，提供商城管理以及道具获取和购买等服务。
KingCard : 王卡组件用于识别当前用户使用的上网卡是否为王卡。识别后给王卡用户以相应的免流状态提示和王卡身份感知。


====================集成信息====================
Package Time : 2023-05-20 11:35:19

GCloudSDK大版本号:  V2.2.12.3

PluginsVersion(各组件版本号):
CrashSight          : 4.2.14.831
GCloudCore          : 1.5.11.2664
GCloud_Ano          : 2.12.01.201236-Oversea
GPM_Ano             : 3.0.0202.540_ano
GVoice_Ano          : 3.7.00.1480.1
MSDKApple_Ano       : 5.10.001.5880
MSDKCore_Ano        : 5.30.002.7208
MSDKFacebook_Ano    : 5.30.001.7206
MSDKGameCenter_Ano  : 5.21.001.5880
MSDKGoogle_Ano      : 5.30.001.7206
MSDKLBS_Ano         : 5.29.000.6677
MSDKSystem_Ano      : 5.27.001.6215
MSDKTDM_Ano         : 5.29.000.6677
MSDKTwitter_Ano     : 5.30.001.7206
TDM                 : 1.28.005.2077
TssSDKAno           : 6.4.014.52877

PackageParam:{
    "AndroidLibType": "libscpp", 
    "AndroidSupportArchitecture": [
        "armeabi-v7a", 
        "x86", 
        "arm64-v8a", 
        "x86_64"
    ], 
    "AndroidSupportLib": "AndroidX", 
    "AnoPackageType": "Ano", 
    "BuildSystem": "Gradle", 
    "Config": {
        "{ADJUST_APP_TOKEN_ANDROID}": "{ADJUST_APP_TOKEN_ANDROID}", 
        "{ADJUST_APP_TOKEN_IOS}": "{ADJUST_APP_TOKEN_IOS}", 
        "{APPSFLYER_APPID}": "{APPSFLYER_APPID}", 
        "{APPSFLYER_APP_KEY_ANDROID}": "{APPSFLYER_APP_KEY_ANDROID}", 
        "{APPSFLYER_APP_KEY_IOS}": "{APPSFLYER_APP_KEY_IOS}", 
        "{BEACON_APP_KEY_ANDROID}": "ANDROID1112219381", 
        "{BEACON_APP_KEY_IOS}": "IOS1112219381", 
        "{BUGLY_APP_ID_ANDROID}": "1112219381", 
        "{BUGLY_APP_ID_IOS}": "i1112219381", 
        "{BUNDLE_ID}": "com.sixjoy.letsgo", 
        "{FACEBOOK_APPID}": "624009219651454", 
        "{FACEBOOK_DISPLAYNAME}": "{FACEBOOK_DISPLAYNAME}", 
        "{FIREBASE_SENDER_ID}": "{FIREBASE_SENDER_ID}", 
        "{GAME_ID}": "745065090", 
        "{GAME_KEY}": "bc66f98c11c67ffda74e9cbb4dee5459", 
        "{GOOGLE_APPID}": "{GOOGLE_APPID}", 
        "{GOOGLE_CLIENT_KEY}": "{GOOGLE_CLIENT_KEY}", 
        "{HW_APPID}": "{HW_APPID}", 
        "{KWAI_APP_ID}": "{KWAI_APP_ID}", 
        "{MAIN_ACTIVITY}": "MainActivity", 
        "{MSDK_GAME_ID}": "28045", 
        "{MSDK_GAME_KEY}": "c853b36c7d626eef3720cfdbe2158a82", 
        "{QQ_APPID}": "1112219381", 
        "{TDM_APPID}": "745065090", 
        "{TDM_SECRET_KEY}": "{TDM_SECRET_KEY}", 
        "{TDM_SOURCE_ID}": "{TDM_SOURCE_ID}", 
        "{TDM_SRC_ID}": "745065090", 
        "{TWITTER_KEY_ANDROID}": "{TWITTER_KEY_ANDROID}", 
        "{TWITTER_KEY_IOS}": "{TWITTER_KEY_IOS}", 
        "{TWITTER_KEY}": "{TWITTER_KEY}", 
        "{TWITTER_SECRET_ANDROID}": "{TWITTER_SECRET_ANDROID}", 
        "{TWITTER_SECRET_IOS}": "{TWITTER_SECRET_IOS}", 
        "{TWITTER_SECRET}": "{TWITTER_SECRET}", 
        "{WX_APPID}": "wx4e7fd29bf29f3e79", 
        "{XG_ACCESS_ID_ANDROID}": "{XG_ACCESS_ID_ANDROID}", 
        "{XG_ACCESS_KEY_ANDROID}": "G7aNfd3ODOaoJKSw", 
        "{XG_APPID}": "{XG_APPID}", 
        "{XG_APPKEY}": "G7aNfd3ODOaoJKSw", 
        "{XG_FCM_ENABLE}": "0", 
        "{XG_FLYME_APP_ID}": "{XG_FLYME_APP_ID}", 
        "{XG_FLYME_APP_KEY}": "{XG_FLYME_APP_KEY}", 
        "{XG_OTHER_ENABLE}": "1", 
        "{XG_XIAOMI_APP_ID}": "{XG_XIAOMI_APP_ID}", 
        "{XG_XIAOMI_APP_KEY}": "{XG_XIAOMI_APP_KEY}", 
        "{XY_GAME_ID}": "{XY_GAME_ID}"
    }, 
    "CppVersion": "C11", 
    "Dynamic": "YES", 
    "Engine": "UE4", 
    "GCloudSDKVersion": "2.2.12.3", 
    "ITOPSubplugins": [], 
    "InputPlugins": {
        "CrashSight": "/data1/gcloud_plugins/release_plugins/master/CrashSight/4.2.14.831", 
        "GCloudCore": "/data1/gcloud_plugins/release_plugins/master/GCloudCore_Ano/1.5.11.2664", 
        "GCloud_Ano": "/data1/gcloud_plugins/release_plugins/2.2.12hotfix/GCloud_Ano/2.12.01.201236-Oversea", 
        "GPM_Ano": "/data1/gcloud_plugins/release_plugins/master/GPM_Ano/3.0.0202.540_ano", 
        "GVoice_Ano": "/data1/gcloud_plugins/release_plugins/master/GVoice_Ano/3.7.00.1480.1", 
        "MSDKApple_Ano": "/data1/gcloud_plugins/release_plugins/master/MSDKApple_Ano/5.10.001.5880", 
        "MSDKCore_Ano": "/data1/gcloud_plugins/release_plugins/2.2.12.3hotfix/MSDKCore_Ano/5.30.002.7208", 
        "MSDKFacebook_Ano": "/data1/gcloud_plugins/release_plugins/2.2.11hotfix/MSDKFacebook_Ano/5.30.001.7206", 
        "MSDKGameCenter_Ano": "/data1/gcloud_plugins/release_plugins/master/MSDKGameCenter_Ano/5.21.001.5880", 
        "MSDKGoogle_Ano": "/data1/gcloud_plugins/release_plugins/2.2.11hotfix/MSDKGoogle_Ano/5.30.001.7206", 
        "MSDKLBS_Ano": "/data1/gcloud_plugins/release_plugins/master/MSDKLBS_Ano/5.29.000.6677", 
        "MSDKSystem_Ano": "/data1/gcloud_plugins/release_plugins/master/MSDKSystem_Ano/5.27.001.6215", 
        "MSDKTDM_Ano": "/data1/gcloud_plugins/release_plugins/master/MSDKTDM_Ano/5.29.000.6677", 
        "MSDKTwitter_Ano": "/data1/gcloud_plugins/release_plugins/2.2.11hotfix/MSDKTwitter_Ano/5.30.001.7206", 
        "TDM": "/data1/gcloud_plugins/release_plugins/master/TDM_Ano/1.28.005.2077", 
        "TssSDKAno": "/data1/gcloud_plugins/release_plugins/master/TssSDKAno/6.4.014.52877"
    }, 
    "OutputDir": "/data1/tmp/sdkcompress/1330cc74598ad5731c4dc25a8a8c4a76", 
    "PackType": "ano", 
    "PluginVersion": "2.2.12.3", 
    "Plugins": [
        "CrashSight", 
        "GCloudCore", 
        "GCloud_Ano", 
        "GPM_Ano", 
        "GVoice_Ano", 
        "MSDKApple_Ano", 
        "MSDKCore_Ano", 
        "MSDKFacebook_Ano", 
        "MSDKGameCenter_Ano", 
        "MSDKGoogle_Ano", 
        "MSDKLBS_Ano", 
        "MSDKSystem_Ano", 
        "MSDKTDM_Ano", 
        "MSDKTwitter_Ano", 
        "TDM", 
        "TssSDKAno"
    ], 
    "SDKVersions": {
        "CrashSight": "2.2.12.3", 
        "GCloudCore_Ano": "2.2.12.3", 
        "GPM_Ano": "2.2.12.3", 
        "GVoice_Ano": "2.2.12.3", 
        "MSDKApple_Ano": "2.2.12.3", 
        "MSDKCore_Ano": "2.2.12.3", 
        "MSDKFacebook_Ano": "2.2.12.3", 
        "MSDKGameCenter_Ano": "2.2.12.3", 
        "MSDKGoogle_Ano": "2.2.12.3", 
        "MSDKLBS_Ano": "2.2.12.3", 
        "MSDKSystem_Ano": "2.2.12.3", 
        "MSDKTDM_Ano": "2.2.12.3", 
        "MSDKTwitter_Ano": "2.2.12.3", 
        "TDM_Ano": "2.2.12.3", 
        "TssSDK_DeTencent": "2.2.12.3", 
        "connector_Ano": "2.2.12.3", 
        "dolphin_Ano": "2.2.12.3", 
        "puffer_Ano": "2.2.12.3"
    }, 
    "SupportPlatform": [
        "iOS", 
        "Android", 
        "Win", 
        "Mac"
    ], 
    "TDMType": "oversea", 
    "UnityVersion": ""
}

root:[/data1/tmp/sdkcompress/1330cc74598ad5731c4dc25a8a8c4a76/GCloudUE4_2.2.12.3]
+-AAInfo4Copy.txt(md5:e3ea3ae3f4ab3e326569c1ef86cf70af)
+-CrashSight
|    +-CrashSight.uplugin(md5:aa25beff8dc4b1cba0d8e9a9638f6230)
|    +-Resources
|    |    +-Icon128.png(md5:7b15f15f14b3399e42fed1a64d9f0cb4)
|    +-Source
|    |    +-CrashSight
|    |    |    +-CrashSight.Build.cs(md5:1f4ff64ba69cfc6fe10556247b11be38)
|    |    |    +-CrashSight_APL.xml(md5:153e607ce75f1b4202eb9f07371ea75e)
|    |    |    +-Private
|    |    |    |    +-CrashSightBridgeWin.cpp(md5:55f9dd1246e053fcf939a2dc72197826)
|    |    |    |    +-CrashSightModule.cpp(md5:f0556d8f50ec97ce22c629bf6e3c3787)
|    |    |    |    +-EmptyImplementations.cpp(md5:1252abce1aa0a57e1b7957517f123e40)
|    |    |    +-Public
|    |    |    |    +-CSLogger.h(md5:b79c2f4820ba6a5c26acd3ee9df05e39)
|    |    |    |    +-CrashSightAgent.h(md5:28b8cd6d0ab789e7f799ecfd92c6d8fe)
|    |    |    |    +-CrashSightAgent.h-e(md5:28b8cd6d0ab789e7f799ecfd92c6d8fe)
|    |    |    |    +-CrashSightBridgeWin.h(md5:bf58d4752b87c0f42ab6e6457044ac4f)
|    |    |    |    +-CrashSightModule.h(md5:72ce41395e69d46e0af299baa522c39d)
|    |    |    |    +-UQMCompatLayer.h(md5:a31cc5ec81f671823a3cbd32748a6535)
|    |    |    |    +-UQMCrash.h(md5:48ca301c9252190a4c61b0ccf30cfb79)
|    |    |    |    +-UQMDefine.h(md5:b8823a51a5385fd49c9adce834d27ee3)
|    |    |    |    +-UQMMacroExpand.h(md5:47f21951e73ddd2848815a64f7d0e042)
|    |    |    |    +-UQMMacros.h(md5:32256fb7f9ba541ede9e9d6f29198433)
|    |    +-CrashSightLib
|    |    |    +-Android
|    |    |    |    +-AndroidManifest.xml(md5:5400403a039b6b0e36d66924a6777d0a)
|    |    |    |    +-additions.gradle(md5:9a3abd2ee8e73c1cf769d39fcb13ae1a)
|    |    |    |    +-libs
|    |    |    |    |    +-CrashSight_crash_release.jar(md5:3dc4c19f8e98cef8a03127d1dc9c3a88)
|    |    |    |    |    +-arm64-v8a
|    |    |    |    |    |    +-libCrashSight.so(md5:79fbf3602892f1bb899006efbaa782ec)
|    |    |    |    |    |    +-libCrashSightPlugin.so(md5:3c4a0f9ea75e1e57d38b7512f06c54e9)
|    |    |    |    |    +-armeabi-v7a
|    |    |    |    |    |    +-libCrashSight.so(md5:4f06f469b2eb89e8c861b37a2c7b7418)
|    |    |    |    |    |    +-libCrashSightPlugin.so(md5:3f70ea08c9d3314951c5daef018a013a)
|    |    |    |    |    +-x86
|    |    |    |    |    |    +-libCrashSight.so(md5:09b884d2f4c0ffc77767a734912954d2)
|    |    |    |    |    |    +-libCrashSightPlugin.so(md5:15d13b94f1b2a41cf5c783f12a573a95)
|    |    |    |    |    +-x86_64
|    |    |    |    |    |    +-libCrashSight.so(md5:fdad0b6f7a49f6b8ecafe5b77dc2a386)
|    |    |    |    |    |    +-libCrashSightPlugin.so(md5:465451429e2143af8b4fab0da1db89ef)
|    |    |    |    +-proguard-project.txt(md5:bd057b89f302a0040476ac50acecb1b7)
|    |    |    |    +-project.properties(md5:a5a956b33ad64ff3dbb8f03a40d58b5c)
|    |    |    +-iOS
|    |    |    |    +-CrashSight.embeddedframework.zip(md5:95387341f0c9690f26813416b0823f94)
|    |    |    |    +-CrashSightAdapter.embeddedframework.zip(md5:0cbe8a4e7cc12541e358a0d4380d18d8)
|    |    |    |    +-CrashSightCore.embeddedframework.zip(md5:de95b41c99a93991fe29cfd737efa0a2)
|    |    |    |    +-CrashSightPlugin.embeddedframework.zip(md5:0c93ef4acc90d69eaa39d64590ae64ae)
+-GCloud
|    +-GCloud.uplugin(md5:65c6a8d9994f9e32ff6e2e9570a32f88)
|    +-Resources
|    |    +-Icon128.png(md5:7b15f15f14b3399e42fed1a64d9f0cb4)
|    +-Source
|    |    +-GCloud
|    |    |    +-GCloud.Build.cs(md5:b92f09bb360eeb95442ede2ce7a90cba)
|    |    |    +-GCloudSDK_APL.xml(md5:b2da693e9bad0c27a981173bed025d99)
|    |    |    +-Private
|    |    |    |    +-GCloudAppDelegate.cpp(md5:9395132acd0d48cffe586e2e053cf4fd)
|    |    |    |    +-GCloudAppDelegate.h(md5:7d811f07e6361b7b73c9b038c74c8297)
|    |    |    |    +-GCloudSDKModule.cpp(md5:f4efcd3823f0cf5e2e4ac4a583f3301e)
|    |    |    |    +-iOS
|    |    |    |    |    +-GCloudAppDelegate.mm(md5:665c47917b1c28b78a32b9ca060ee9d4)
|    |    |    +-Public
|    |    |    |    +-AArray.h(md5:2ba713c6705ae8375cf279f9df1be390)
|    |    |    |    +-AData.h(md5:cfe7e4422e1befebbce53989565d75a1)
|    |    |    |    +-ADictionary.h(md5:34bc1c225ba6b2b22228120d37edc806)
|    |    |    |    +-ANumber.h(md5:52bb63e29d138cf7e5a83213754738cf)
|    |    |    |    +-AObject.h(md5:877c9e02f9950b3a2ffe4d353102ae55)
|    |    |    |    +-AString.h(md5:c68521d16446cbc306720da425475024)
|    |    |    |    +-AValue.h(md5:fa68f2bc2481d553f363b0e9d2e89a86)
|    |    |    |    +-Access.h(md5:10102aecf451a952ec94cad69b71cd7c)
|    |    |    |    +-ApolloBuffer.h(md5:0b778d24248df038552f088ffd4c4e4b)
|    |    |    |    +-ApolloBufferReader.h(md5:21950e1ecaae74eb663d8212432f2a3d)
|    |    |    |    +-ApolloBufferWriter.h(md5:7c760422dca12121f42216305513e05f)
|    |    |    |    +-ConnectorPublicDefine.h(md5:f4bd1170da295f79186cf1f57661f2d7)
|    |    |    |    +-DolphinHelper.h(md5:4bebb7a73560c4d55a1339cf24ab9a2d)
|    |    |    |    +-G6ConnectorDefine.h(md5:132ffba30c03217ad6e615eab758bb16)
|    |    |    |    +-GCloudApplication.h(md5:7e0a3d71f3a02e59f3936d30f2416170)
|    |    |    |    +-GCloudDataIFSInterface.h(md5:ab08b583785d0aa2482d81d1728d88af)
|    |    |    |    +-GCloudDolphinInterface.h(md5:4c7ca53281ca53fb97e8b8ba8dda7875)
|    |    |    |    +-GCloudDolphinUtility.h(md5:2dc2ffb9740e233606548159994eb9bd)
|    |    |    |    +-GCloudInnerDefine.h(md5:1d641c3edc052887db0c145d37e87f20)
|    |    |    |    +-GCloudPal.h(md5:940539d4f05120e97f585bd572a780cd)
|    |    |    |    +-GCloudPublicDefine.h(md5:be04286b1181205a1966f4d063b2230b)
|    |    |    |    +-GCloudPufferInterface.h(md5:f7295babbb95fa43943364fbb0feb7e5)
|    |    |    |    +-GCloudSDKModule.h(md5:0ee3eeec8ca7f743160e8827cf777168)
|    |    |    |    +-GCloudVersion.h(md5:81300fb4b85ebee88cf7b148a31119dc)
|    |    |    |    +-GFile.h(md5:6d915bd55fccdfbf10362aadc91e9d98)
|    |    |    |    +-GPath.h(md5:653fad32f2870655e6b8258d8de27ed7)
|    |    |    |    +-GTargetBase.h(md5:51b8549c8380874822047d047d953183)
|    |    |    |    +-IConnector.h(md5:736769f1c5f3bb0503c9b297363c326a)
|    |    |    |    +-IConnectorFactory.h(md5:2e9c33a289f680c7601715ca152d7b37)
|    |    |    |    +-IG6Connector.h(md5:051edba8ca923cc6c1a6be66def422dc)
|    |    |    |    +-IG6ConnectorFactory.h(md5:bdad663e543a13ba490ff186865befa2)
|    |    |    |    +-IGCloud.h(md5:e133a2bef6c84029e78951cc8fecabbf)
|    |    |    |    +-IGCloudExtend.h(md5:c0d8c524262330373d622c3f9fb21b86)
|    |    |    |    +-IGFMConnector.h(md5:779f67e259dd46fb4fc59a279ca65f12)
|    |    |    |    +-IGFMConnectorFactory.h(md5:64e8ad631d2890f786fc5b15c0fe5d73)
|    |    |    |    +-ILockStep.h(md5:06e598a3ff1f3e861817e2b7d754b681)
|    |    |    |    +-INameService.h(md5:b26ae7bf53dc1681e3ed996881de18cc)
|    |    |    |    +-INetwork.h(md5:11644a4fbde0713fc88a99ef29d6c437)
|    |    |    |    +-IQRCodeService.h(md5:00cca9a0a6c0e2a9c1e2bcbf39b52424)
|    |    |    |    +-IRPC.h(md5:742419db526497ce71a0e2e69924308b)
|    |    |    |    +-ITDir.h(md5:fa7979d2b5bd97c5f2bd7a615f0ba3c5)
|    |    |    |    +-LockStepPublicDefine.h(md5:c84b3327dc5c09b9fbb647298a206076)
|    |    |    |    +-TDirPublicDefine.h(md5:ab0c13e7a9daae0c834b706ae657b6f4)
|    |    |    |    +-gcloud_dolphin_errorcode_check.h(md5:2e4b1bb7789d6f9dbc74abe471af33a8)
|    |    +-GCloudLib
|    |    |    +-Android
|    |    |    |    +-GCloud
|    |    |    |    |    +-AndroidManifest.xml(md5:9e921efb58d550825c45954c37aa3ac0)
|    |    |    |    |    +-additions.gradle(md5:14c34fce6472c2c21b3409c705976f07)
|    |    |    |    |    +-libs
|    |    |    |    |    |    +-GCloud.jar(md5:3cc3b26014133793dc06631e8d4b2696)
|    |    |    |    |    |    +-android-support-v4.jar(md5:a373357c77b3be76070d82bc0f5a503d)
|    |    |    |    |    |    +-arm64-v8a
|    |    |    |    |    |    |    +-libgcloud.so(md5:8b9db9ec938d89344b981dc74909dabf)
|    |    |    |    |    |    +-armeabi-v7a
|    |    |    |    |    |    |    +-libgcloud.so(md5:5e8278d1d744ce9026b101212d8c8322)
|    |    |    |    |    |    +-x86
|    |    |    |    |    |    |    +-libgcloud.so(md5:dd32c222a8273d8d2e1c8fa412dbb80f)
|    |    |    |    |    |    +-x86_64
|    |    |    |    |    |    |    +-libgcloud.so(md5:8dd1a49ef981c1d3ff61879a8921e60d)
|    |    |    |    |    +-proguard-project.txt(md5:cc17807fe395b44dd1c485d87bc76b22)
|    |    |    |    |    +-project.properties(md5:bc20596d957d714759ee019b59304d1c)
|    |    |    |    |    +-res
|    |    |    |    |    |    +-xml
|    |    |    |    |    |    |    +-apollo_file_paths.xml(md5:01e9000ee398ea097f4510169e44ed7c)
|    |    |    +-Mac
|    |    |    |    +-libGCloud.dylib(md5:d267fa8828b41819be1222e757fe2664)
|    |    |    +-Win
|    |    |    |    +-X86
|    |    |    |    |    +-GCloud.dll(md5:e4d6245b769c99ff1b6d976246141446)
|    |    |    |    |    +-GCloud.lib(md5:cc78bc53189ce104ee47694d0d3578ca)
|    |    |    |    |    +-GCloud.pdb(md5:c7f797bab1d12cd77326af29ce385949)
|    |    |    |    +-X86_64
|    |    |    |    |    +-GCloud.dll(md5:897f6c2dcff7be75e7b95b5acf0060ad)
|    |    |    |    |    +-GCloud.lib(md5:ae9402de387ae80f9fb341f5a4ef8f8b)
|    |    |    |    |    +-GCloud.pdb(md5:e59a865ca8aa67e6e4a6f7494eff6873)
|    |    |    +-X64
|    |    |    |    +-GCloud_static.lib(md5:c849d2e9120672bbe7e36474781ceef0)
|    |    |    |    +-atls.lib(md5:8290e7ec9ad8428ca79301d57b573a05)
|    |    |    +-iOS
|    |    |    |    +-GCloud.embeddedframework.zip(md5:2339071882813d5176c4d4dbc4246f8b)
+-GCloudCore
|    +-GCloudCore.uplugin(md5:9ac3a083ad2bad8fcab3828798dc066f)
|    +-Resources
|    |    +-Icon128.png(md5:7b15f15f14b3399e42fed1a64d9f0cb4)
|    +-Source
|    |    +-GCloudCore
|    |    |    +-GCloudCore.Build.cs(md5:aae0167d8c5196fda67c96ba62c05b08)
|    |    |    +-GCloudCore_APL.xml(md5:306bae1b1cbf3b2e169552c0241a89fb)
|    |    |    +-Private
|    |    |    |    +-GCloudAppLifecycle.h(md5:682fc36cfa1ef43888d31758a7c2c9b1)
|    |    |    |    +-GCloudCoreAppDelegate.cpp(md5:6d871a58403beac6e1bc72887f99e8a9)
|    |    |    |    +-GCloudCoreAppDelegate.h(md5:90621eba5ffeb3c19142ce22a1e0e642)
|    |    |    |    +-GCloudCoreModule.cpp(md5:89e663343c4288171e814358375f9b51)
|    |    |    |    +-iOS
|    |    |    |    |    +-AllLifecycleRegister.h(md5:ce25cf423a58a757e8ccc41ca81f9ba7)
|    |    |    |    |    +-CSLifecycle.h(md5:17448a5b0cc55fe3f944be65fc21a434)
|    |    |    |    |    +-GCloudAppLifecycleListener.h(md5:de8c3606c58d43e1a2e8257279ffd279)
|    |    |    |    |    +-GCloudCoreAppDelegate.mm(md5:92996e28a4ee655ead384cbf15ed658a)
|    |    |    |    |    +-GPMLifecycle.h(md5:51d0325238b8eb255504c2a9fadb8e59)
|    |    |    |    |    +-PluginGVoiceLifecycle.h(md5:18e78fe67cd98b7bf078cd432641c294)
|    |    |    |    |    +-PluginMSDKLifecycle.h(md5:94403edd03dca0d42ff014dab0e186a5)
|    |    |    |    |    +-PluginReportLifecycle.h(md5:a88ae3ea54b6a725b85476ec36b6cd30)
|    |    |    |    |    +-PluginTssSDKLifecycle.h(md5:6b99661be17e92bc9b41e8dc58d43e13)
|    |    |    +-Public
|    |    |    |    +-GCloudCore
|    |    |    |    |    +-AArray.h(md5:2959978bb0b2c7ac6e5eedcdd3ca7cd3)
|    |    |    |    |    +-AAtomic.h(md5:16518b17c00c8b7b75049cb7a5b03453)
|    |    |    |    |    +-ABase.h(md5:503782df1b444cf1017111ed5093f3fe)
|    |    |    |    |    +-ABaseApplication.h(md5:5726837da3ecd7798772c5ffff49ca74)
|    |    |    |    |    +-ABaseCommon.h(md5:d203cc8c00935f7a18affde3ff3858c2)
|    |    |    |    |    +-ABaseJVM.h(md5:b24145ea9b11250a04cbbaf099847876)
|    |    |    |    |    +-ABasePal.h(md5:f5008986ef997014cfee9c08c9b0aa70)
|    |    |    |    |    +-ACondition.h(md5:2d617ca2da4ee5e5035bd0b3c6093688)
|    |    |    |    |    +-ACritical.h(md5:85f64d857b4bd1298e25dea3798d0ea9)
|    |    |    |    |    +-AData.h(md5:818d150a2884a309ad576510b878c07c)
|    |    |    |    |    +-ADictionary.h(md5:55ba9067b316de4cad750ab9fd463ddc)
|    |    |    |    |    +-AEvent.h(md5:ecfb1e22d4182e38d4aa7ff24fc2734e)
|    |    |    |    |    +-AFile.h(md5:4200ab14f335fe028bcf31e609c7c5d3)
|    |    |    |    |    +-AJniTool.h(md5:336b4f69cb3e8410ce398acec06af277)
|    |    |    |    |    +-ALog.h(md5:6f325de0fcaba2c4c7c64c86391736ed)
|    |    |    |    |    +-AMutex.h(md5:7b1bebc7b7a675e28d0c4ac2c7444eac)
|    |    |    |    |    +-ANumber.h(md5:af919490161b82cedf682af8f7112099)
|    |    |    |    |    +-AObject.h(md5:b85ca4fe764b15ee69a915e2d1e252ed)
|    |    |    |    |    +-APath.h(md5:e8c101d4e678d1dc724713113c1d26a5)
|    |    |    |    |    +-ASelectorManager.h(md5:656201ab6e30b3882c726e854b690cdd)
|    |    |    |    |    +-ASocket.h(md5:b22c4a033567456e5507be1254d699b6)
|    |    |    |    |    +-AString.h(md5:907a756b5fdbef2933e068a1d41bb527)
|    |    |    |    |    +-AStringBuilder.h(md5:3d050043b5abe8fd1e720387d694f4e2)
|    |    |    |    |    +-ASystem.h(md5:f0acc34067fa188dcc8a6567171df1e8)
|    |    |    |    |    +-ATargetBase.h(md5:5004fafd43c4dc8888096cc675709937)
|    |    |    |    |    +-AThreadBase.h(md5:8abe5e6eb59525e4ae64b3cbc6c5511a)
|    |    |    |    |    +-ATime.h(md5:0ea2ae76dbc5e75bc4c4921c8bbec008)
|    |    |    |    |    +-ATimeWin.h(md5:efe4184349a325748258b27688747d59)
|    |    |    |    |    +-ATimer.h(md5:a277c26db74ac9c6fd4cac828167387c)
|    |    |    |    |    +-AValue.h(md5:233cb7f3414e46d63016e3108e717948)
|    |    |    |    |    +-ApolloBuffer.h(md5:a2108181a347fb578ac8470a206ac59a)
|    |    |    |    |    +-ApolloBufferReader.h(md5:3283f3998a99d0d55eb295e7bde8bdd5)
|    |    |    |    |    +-ApolloBufferWriter.h(md5:ab53f8546c61a97760783a22cd77f813)
|    |    |    |    |    +-Application.h(md5:b5c7b98a4c668ded615a976bcaa420ee)
|    |    |    |    |    +-Bundle.h(md5:288ee28860bccaf91c572141e81b222c)
|    |    |    |    |    +-BundleFactory.h(md5:3e8b75e10702cde7c6728ac5754d3874)
|    |    |    |    |    +-COSUploadTask.h(md5:438801d790680c06f3f341afd3e7a782)
|    |    |    |    |    +-Configure.h(md5:36e76e98f5ce8b75ab4eb5c02804e69b)
|    |    |    |    |    +-GCloudAppLifecycle.h(md5:dbe03e22d60700faa82888549952f8f4)
|    |    |    |    |    +-GCloudAppLifecycleObserver.h(md5:75a473029b4e0ca852d40c6d7cf2a589)
|    |    |    |    |    +-GCloudCoreVersion.h(md5:91a9c45c8c0ac43d12a870e286d807b1)
|    |    |    |    |    +-IGCloudCore.h(md5:cff0554048fc8969cc360ebabe269a79)
|    |    |    |    |    +-INetwork.h(md5:111dd93d96a268db3e22bf4e4a104390)
|    |    |    |    |    +-INetworkChecker.h(md5:032d3a53e69b5715b6a05c7da2125226)
|    |    |    |    |    +-IOneTraceService.h(md5:62de211fa38ef4c62c63ce80fd403ad4)
|    |    |    |    |    +-IPlatformObject.h(md5:2b0749cdcd0684daaa5ba361939f1c12)
|    |    |    |    |    +-IPlatformObjectManager.h(md5:8f1bad1eceb02e231cbadce66a6124b1)
|    |    |    |    |    +-IniFile.h(md5:2e7b7ba9e174e8727dcf4878f3c4d4f2)
|    |    |    |    |    +-Operation.h(md5:4fe1f2195335c127bf1ad6ca81118e0e)
|    |    |    |    |    +-OperationQueue.h(md5:75d6fafe1eb70a3737238690713a6d07)
|    |    |    |    |    +-PlatformObject.h(md5:c1e13c859cc61cfd4e0ba239f3158bfa)
|    |    |    |    |    +-PlatformObjectManager.h(md5:3b2aedb5af5acef553736ca2b47735eb)
|    |    |    |    |    +-PlatformObjectRegister.h(md5:e29e58bd97b6bb5a86de261062dc8d85)
|    |    |    |    |    +-PlatformObjectWrapper.h(md5:3322533b878c371cf2b75f880abc3b74)
|    |    |    |    |    +-StatisticTools.h(md5:47726bb235fd7a6ccf100188f7d164f4)
|    |    |    |    |    +-TdrBuf.h(md5:2ad648989012d58191ae1aaf1baa8347)
|    |    |    |    |    +-TdrBufUtil.h(md5:6a9a016905dd70d0ca54de5ba0e7d57e)
|    |    |    |    |    +-TdrError.h(md5:b2aa0263bba154edf22a7daae70f96a4)
|    |    |    |    |    +-TdrIO.h(md5:c2cf654990e6c426996b9d96fe4da027)
|    |    |    |    |    +-TdrObject.h(md5:6f7dadab067eb8ad89720bd1350d906c)
|    |    |    |    |    +-TdrPal.h(md5:8c60dc0c89a8f58aadd24d5997fd67e8)
|    |    |    |    |    +-TdrParse.h(md5:81594d4503c8267636b23fa0c7a4c104)
|    |    |    |    |    +-TdrTLV.h(md5:3232177fd8267167618457a379dc70f4)
|    |    |    |    |    +-TdrTime.h(md5:abc9cb7df2dda6768de56979f373821b)
|    |    |    |    |    +-TdrTypeUtil.h(md5:787d5e7dd8d193f9837617a746701d46)
|    |    |    |    |    +-TdrXml.h(md5:59da83f18d40412f0a6a8dfae07cd60b)
|    |    |    |    |    +-WWW.h(md5:5237714f82401b3b4a03c65cfe36a43b)
|    |    |    |    |    +-ZipArchive.h(md5:79bd0600c82df211c27d0748b3cfd51a)
|    |    |    |    |    +-rapidxml.h(md5:ad61152262a182947c46329aa7d31b8f)
|    |    |    |    |    +-rapidxml_iterators.hpp(md5:15c0baba4b8afd604a83d49bf5e98003)
|    |    |    |    |    +-rapidxml_print.hpp(md5:b54ac3b7cc9e21ed653c646e64b2cefc)
|    |    |    |    |    +-rapidxml_utils.hpp(md5:6a25cd513fd85c5fb02bf9cfbbaf8085)
|    |    |    |    |    +-zconf.h(md5:38986959d2d56fe8430a3a17b182cbe8)
|    |    |    |    |    +-zlib.h(md5:317649926f3383a869c3532d49f9a8b2)
|    |    |    |    +-GCloudCoreModule.h(md5:f79f4cd9cb70dace276f54b29b9ae16f)
|    |    |    |    +-GCloudPluginManager
|    |    |    |    |    +-GCloudAppLifecycleObserver.h(md5:75a473029b4e0ca852d40c6d7cf2a589)
|    |    |    |    |    +-GCloudPluginPublicDefine.h(md5:d38def9208cd7f214b9cdaf87179985a)
|    |    |    |    |    +-IPlugin.h(md5:5120bc2f978f7b8119139ab0e58cbc94)
|    |    |    |    |    +-IPluginManager.h(md5:31b1da66b2f919e877854849d680ecf2)
|    |    |    |    |    +-IPluginService.h(md5:0bfc1a2b5a229169c4c93734b687832b)
|    |    |    |    |    +-IServiceManager.h(md5:f0aa3cdd5e90ec2eacd603bf596f11c1)
|    |    |    |    |    +-PluginBase
|    |    |    |    |    |    +-PluginBase.h(md5:5cde197366f5ed0ee980b4a246e73b3d)
|    |    |    |    |    |    +-PluginBase_Android.h(md5:62d62161f61f1b8e2eb6bb27ba5e807b)
|    |    |    |    |    |    +-PluginBase_iOS.h(md5:356956d39125fa005982c7be15f176f4)
|    |    |    |    |    |    +-PluginInnerDefine.h(md5:c8e2407ecc3d5aadeec079ff7ed6c77b)
|    |    |    |    |    +-Service
|    |    |    |    |    |    +-Account
|    |    |    |    |    |    |    +-AccountHelper.h(md5:bcafd9879f6987996be83dea3b7264d6)
|    |    |    |    |    |    |    +-IServiceAccount.h(md5:5524a01e659248a1b5799cf653aac460)
|    |    |    |    |    |    +-CSScript
|    |    |    |    |    |    |    +-ICSScript.h(md5:7d4c51517148441a54b61784e4c2f62a)
|    |    |    |    |    |    |    +-ICSScriptService.h(md5:327695598f7e3d67afdb8ff28faf44fe)
|    |    |    |    |    |    +-ConfigFile
|    |    |    |    |    |    |    +-IConfigFile.h(md5:e114d205e1a77ccf1fedf17b9f875832)
|    |    |    |    |    |    |    +-IConfigFileService.h(md5:c587ffcafe9da1d3d765f31375658efb)
|    |    |    |    |    |    +-Connector
|    |    |    |    |    |    |    +-IConnectorService.h(md5:9ed1450b6b396c34365935a841534f2d)
|    |    |    |    |    |    +-GTrace
|    |    |    |    |    |    |    +-GTraceClient.h(md5:aa845bcff85400e90fd6cae83b893b11)
|    |    |    |    |    |    |    +-ITraceService.h(md5:2f877a8be84160de31325ec1b58d7fbf)
|    |    |    |    |    |    +-GVoice
|    |    |    |    |    |    |    +-IGVoiceService.h(md5:fd37053cd5c9c2d24b1bfec33ae376b7)
|    |    |    |    |    |    +-Log
|    |    |    |    |    |    |    +-ILogService.h(md5:e5d431d8a5fc8d5de4fa0b31d38720fb)
|    |    |    |    |    |    |    +-ILogger.h(md5:22220adcf95c056af8d385ddfd99541b)
|    |    |    |    |    |    +-MKV
|    |    |    |    |    |    |    +-IKV.h(md5:0c0aedc2bff4333263fdff8b5381ea76)
|    |    |    |    |    |    +-PluginCrosCurl
|    |    |    |    |    |    |    +-ICurlFunc.h(md5:67b343f76a6555f7c6fd6130ead8ea44)
|    |    |    |    |    |    |    +-ICurlFuncQueryService.h(md5:849d5beae0dc0a65c5bef26b134df27d)
|    |    |    |    |    |    |    +-IOpenSSLFunc.h(md5:2cffccf733d32c8c61b961233ef54519)
|    |    |    |    |    |    |    +-IOpenSSLFuncQueryService.h(md5:13948a826f7d7ef4b85f672fbbb22c7a)
|    |    |    |    |    |    |    +-PluginCrosCurlLifecycle.h(md5:433a1079f9143f5408381ac538937a39)
|    |    |    |    |    |    |    +-crosCurl.h(md5:54ec327d84e5f4303934b454ee86d8e4)
|    |    |    |    |    |    |    +-crosCurlDefine.h(md5:ab9bc7834a4b8272d6d4207a3815612e)
|    |    |    |    |    |    +-RemoteConfig
|    |    |    |    |    |    |    +-IRemoteConfig.h(md5:329785cf074798ee3bb8682cecf5595b)
|    |    |    |    |    |    |    +-IRemoteConfigService.h(md5:8d7c21ad7b37a108846018b56153c86c)
|    |    |    |    |    |    +-Report
|    |    |    |    |    |    |    +-DeviceInfoDefine.h(md5:ab52fab8f85d60aacba850da828eeb3b)
|    |    |    |    |    |    |    +-GCloudCoreReporter.h(md5:f415fd2d5d89128ae844bdca7b5e1ac0)
|    |    |    |    |    |    |    +-IReportService.h(md5:7f585b21afe80750568c57a38f1f2043)
|    |    |    |    |    |    +-ThreadPool
|    |    |    |    |    |    |    +-IFdListener.h(md5:564c577ecd19cb5e546fcb4c9363794c)
|    |    |    |    |    |    |    +-IThreadPool.h(md5:0e0ba1ff38de329d8ecb68abd95640af)
|    |    |    |    |    |    |    +-IThreadPoolService.h(md5:15c990812913f84c5682a710e8b49bf8)
|    |    |    |    |    |    |    +-IThreadRunnable.h(md5:9b71d38479138f45dfd3a220747c4d89)
|    |    +-GCloudCoreLib
|    |    |    +-Android
|    |    |    |    +-GCloudCore
|    |    |    |    |    +-AndroidManifest.xml(md5:aa4e5ad5a3191e372bf7e38c3dcdcce9)
|    |    |    |    |    +-additions.gradle(md5:93d3f09b3c2d1d41fd84672fb96124f0)
|    |    |    |    |    +-libs
|    |    |    |    |    |    +-GCloudCore.jar(md5:7919678089745cced6515786f8c0a964)
|    |    |    |    |    |    +-android-support-v4.jar(md5:a373357c77b3be76070d82bc0f5a503d)
|    |    |    |    |    |    +-arm64-v8a
|    |    |    |    |    |    |    +-libgcloudcore.so(md5:466aaf38c319c6d10a6a01d05786034f)
|    |    |    |    |    |    +-armeabi-v7a
|    |    |    |    |    |    |    +-libgcloudcore.so(md5:6a5847d96adf371e2be8824cfddc872f)
|    |    |    |    |    |    +-x86
|    |    |    |    |    |    |    +-libgcloudcore.so(md5:d48ed30925c5e664a389bc67c2820e91)
|    |    |    |    |    |    +-x86_64
|    |    |    |    |    |    |    +-libgcloudcore.so(md5:0042e19a5041113e4f3b3d45d1ccea04)
|    |    |    |    |    +-proguard-project.txt(md5:6b88347fafc87383853af501f3bb89e1)
|    |    |    |    |    +-project.properties(md5:bc20596d957d714759ee019b59304d1c)
|    |    |    |    |    +-res
|    |    |    |    |    |    +-values
|    |    |    |    |    |    |    +-string.xml(md5:ea8cdc79bfa07d802ca9402077d1d059)
|    |    |    |    |    |    +-xml
|    |    |    |    |    |    |    +-network_security_config.xml(md5:2c09fc106591eb269b38e037cdede31e)
|    |    |    +-Mac
|    |    |    |    +-libGCloudCore.dylib(md5:660622c199a620ce94af6ec669bc4b76)
|    |    |    +-Win
|    |    |    |    +-X86
|    |    |    |    |    +-GCloudCore.dll(md5:c78ef689c9af7a90065a10e5866f6b4a)
|    |    |    |    |    +-GCloudCore.exp(md5:3b175ea7bc885daba35dc881c7711b79)
|    |    |    |    |    +-GCloudCore.lib(md5:01405cdb0bcd9234c3088d810cdc2ca1)
|    |    |    |    |    +-GCloudCore.pdb(md5:fa156cbf4a098c1e6b1a03c199ccf599)
|    |    |    |    |    +-vc140.pdb(md5:562ac3435f2c76b8c90c2d72f02b0880)
|    |    |    |    +-X86_64
|    |    |    |    |    +-GCloudCore.dll(md5:8a4ff6c9fe936c26db4509f308f42a0e)
|    |    |    |    |    +-GCloudCore.exp(md5:4fbbcb5eaeac46391aaba57bfce80235)
|    |    |    |    |    +-GCloudCore.lib(md5:6edaa7165bcf3e5df67abfecad9c1abf)
|    |    |    |    |    +-GCloudCore.pdb(md5:64e02ddedddf3f62ed1a7718de2d6319)
|    |    |    |    |    +-vc140.pdb(md5:8b217a99cc8852c8087b3a84f212d2aa)
|    |    |    +-X64
|    |    |    |    +-GCloudCore_static.lib(md5:baca620bb0c964f7444670664eb66fb5)
|    |    |    +-iOS
|    |    |    |    +-GCloudCore.embeddedframework.zip(md5:457d2cb3c2b2af58155b0419cea21e5f)
|    |    +-GCloudInfo(md5:7da48bb8d20b6ee47dd36299c2be6d31)
+-GPM
|    +-GPM.uplugin(md5:6170e070796befb0d726fa0388193cad)
|    +-Resources
|    |    +-Icon128.png(md5:7b15f15f14b3399e42fed1a64d9f0cb4)
|    +-Source
|    |    +-GPM
|    |    |    +-GPM.Build.cs(md5:f3d50c8bc1b1b4e9b97b588f1b39cf40)
|    |    |    +-GPM_APL.xml(md5:2a094c7146a82cb577c2af26e11daf8f)
|    |    |    +-Private
|    |    |    |    +-Android
|    |    |    |    |    +-TGPAServiceAndroid.cpp(md5:af542adea58a377d910ac23ca2e6ab66)
|    |    |    |    |    +-TGPAServiceAndroid.h(md5:3131e7a51fa6e01a8aae9a43fbdeeb5e)
|    |    |    |    +-GPM.cpp(md5:9336757bbb6b2c97617c29b1635bc8a5)
|    |    |    |    +-GPMHelper.cpp(md5:b8a29cca63eeaad24fd9c6f92e1d735e)
|    |    |    |    +-MyObserver.cpp(md5:72481d35133e3e757e478173dc98179f)
|    |    |    |    +-PerfSightBridge.cpp(md5:f7fa0753c3b5bd466ba47afdcf7b22fb)
|    |    |    |    +-TGPAHelper.cpp(md5:af923f809745f694782055cc2fa1ba3c)
|    |    |    |    +-iOS
|    |    |    |    |    +-TGPAServiceiOS.cpp(md5:0d9563f42a40b0a80cd09106368b9637)
|    |    |    |    |    +-TGPAServiceiOS.h(md5:10d9ce9d5b93deba1fd470ddc839b6cc)
|    |    |    +-Public
|    |    |    |    +-GPM.h(md5:30bff43468b9cd6eacc24b4bdd232561)
|    |    |    |    +-GPMAosNative.h(md5:c3133a66e30dc28e1504b9b6ede90003)
|    |    |    |    +-GPMApiInterfaceObject.h(md5:6de03d9d45f7a63ffbb696dced5620aa)
|    |    |    |    +-GPMHelper.h(md5:6b2ba2109462950d297fe2d4d58262c9)
|    |    |    |    +-GPMObserver.h(md5:6a2b325aec9a1551346a14d4b6fc8d2f)
|    |    |    |    +-ITGPAService.h(md5:b93fa05e3e9a7a2d9863a14d8449348b)
|    |    |    |    +-MyObserver.h(md5:d024877319ad84240bb59977fc6bd146)
|    |    |    |    +-PerfSightBridge.h(md5:d2d40b30f18121a0e36c8d9e86bdf3a2)
|    |    |    |    +-TGPAHelper.h(md5:ee2beb7dd5a23134f04a1c511b7c2d56)
|    |    +-GPMSDKLib
|    |    |    +-Android
|    |    |    |    +-AndroidManifest.xml(md5:69883bfc686e4fb338267ec27daf9a4b)
|    |    |    |    +-additions.gradle(md5:9d6a8937e3669ecf793f5910700de14a)
|    |    |    |    +-libs
|    |    |    |    |    +-GPMRelease.jar(md5:713604ae3285961727fe282b0c8827df)
|    |    |    |    |    +-arm64-v8a
|    |    |    |    |    |    +-.gitignore(md5:d41d8cd98f00b204e9800998ecf8427e)
|    |    |    |    |    |    +-libApmBacktrace.so(md5:51545f9d74e7495d8923cbbba20723de)
|    |    |    |    |    |    +-libApmInterceptor.so(md5:c1dbc4368392044734f85561e4fc1ac3)
|    |    |    |    |    |    +-libGPM.so(md5:c38e749d60bd671b28c2ac194cd777dc)
|    |    |    |    |    |    +-libtgpa.so(md5:231ea35b97bf25eaf1ef0d7407585d07)
|    |    |    |    |    +-armeabi-v7a
|    |    |    |    |    |    +-.gitignore(md5:d41d8cd98f00b204e9800998ecf8427e)
|    |    |    |    |    |    +-libApmBacktrace.so(md5:e387f30c07fea72f98a8b0ee9a8e32e3)
|    |    |    |    |    |    +-libApmInterceptor.so(md5:7842f906762609a86b4ca4bf2b517ffc)
|    |    |    |    |    |    +-libGPM.so(md5:0fde05b6e74f4bf1d4072a631e0a5f5b)
|    |    |    |    |    |    +-libtgpa.so(md5:c22a9111700ae7e76ee502590e5b44e9)
|    |    |    |    |    +-tgpa_4.0.3.7_20230321.jar(md5:a8abee8106e0617def348fc58f44184b)
|    |    |    |    |    +-x86
|    |    |    |    |    |    +-.gitignore(md5:d41d8cd98f00b204e9800998ecf8427e)
|    |    |    |    |    |    +-libGPM.so(md5:5d7c00552ed8be98ee3c6467d842ffb2)
|    |    |    |    |    |    +-libtgpa.so(md5:9cd1a4da4b1fa12b7abc8186b71af5f3)
|    |    |    |    |    +-x86_64
|    |    |    |    |    |    +-.gitignore(md5:d41d8cd98f00b204e9800998ecf8427e)
|    |    |    |    |    |    +-libGPM.so(md5:076edc3a04dd4cfd0c0e3931be533fbe)
|    |    |    |    |    |    +-libtgpa.so(md5:032893209e8cc3799e4cd4bff6b7926e)
|    |    |    |    +-proguard-project.txt(md5:69da88d1d5e16dbf2c6182f8b7390976)
|    |    |    |    +-project.properties(md5:a5a956b33ad64ff3dbb8f03a40d58b5c)
|    |    |    +-iOS
|    |    |    |    +-GPM_dylib.embeddedframework.zip(md5:0823030451d9bf0ea01e0f22cba16f8f)
|    |    |    |    +-kgvmp_dy.embeddedframework.zip(md5:9effbac8b134c9d01219cc5ea4ebf9a3)
+-GVoice
|    +-GVoice.uplugin(md5:074dfe6ad9f106df6d7207989bb29612)
|    +-Resources
|    |    +-Icon128.png(md5:7b15f15f14b3399e42fed1a64d9f0cb4)
|    +-Source
|    |    +-GVoice
|    |    |    +-GVoice.Build.cs(md5:d2ce97c1de20eecc8de44d1641853413)
|    |    |    +-GVoice_APL.xml(md5:3d7d51fc8103ea2446723d78e3652a14)
|    |    |    +-Private
|    |    |    |    +-GVoice.cpp(md5:ab509d2e292a473c80792da52997bee2)
|    |    |    |    +-GVoiceAppDelegate.cpp(md5:a74ee60ab5ad68851df21b9e81b956fb)
|    |    |    |    +-GVoiceAppDelegate.h(md5:2c6ed1c8e692b84dc56f9aaf45293556)
|    |    |    |    +-iOS
|    |    |    |    |    +-GVoiceAppDelegate.mm(md5:7ebd802c1ca9073f44f268eeb0319741)
|    |    |    +-Public
|    |    |    |    +-GCloudVoiceErrno.h(md5:5f9163019d6735dd0cc9244e35b3d041)
|    |    |    |    +-GCloudVoiceVersion.h(md5:9d3fee8075e68cb568c06d63367a1c62)
|    |    |    |    +-GVoice.h(md5:11b6175e503b2dc79f8c5086ac4ac582)
|    |    |    |    +-IGCloudVoiceEngine.h(md5:274b36a0408b020e9683ed9d5cc177f4)
|    |    |    |    +-IGCloudVoiceEngineNotify.h(md5:6551068643b3e85105ae9d7ad5fedeec)
|    |    |    |    +-IGCloudVoiceExtension.h(md5:82cb7dc3f0fe054ae62bc4e3f1215b25)
|    |    |    +-additions.gradle(md5:14c34fce6472c2c21b3409c705976f07)
|    |    +-GVoiceLib
|    |    |    +-Android
|    |    |    |    +-assets
|    |    |    |    |    +-GCloudVoice
|    |    |    |    |    |    +-cldnn_spkvector.mnn(md5:c40dc24bb7b8f780906b84ffc8eb0672)
|    |    |    |    |    |    +-config.json(md5:e06bb3624057a1d30b1469b02e610697)
|    |    |    |    |    |    +-decoder_v4_small.nn(md5:23d4366963047bfb03941e23222aea50)
|    |    |    |    |    |    +-encoder_v4_small.nn(md5:73a2912df2386c79f4a680c753852a49)
|    |    |    |    |    |    +-libgvoicensmodel.bin(md5:3dd9e79d008513dfeb9369aa1845dcd7)
|    |    |    |    |    |    +-libwxvoiceembed.bin(md5:282b06afa1a0f5c07e73b87a0756fe95)
|    |    |    |    |    |    +-wave_3d_data.bin(md5:7746ba475230edbc56123ee36f7b9329)
|    |    |    |    |    |    +-wave_dafx_data.bin(md5:7746ba475230edbc56123ee36f7b9329)
|    |    |    |    +-libs
|    |    |    |    |    +-GVoice.jar(md5:613a5407ad6fb6c4f57dc64badd9ef36)
|    |    |    |    |    +-arm64-v8a
|    |    |    |    |    |    +-libGVoice.so(md5:0f96280b83c64fbd7fc542b584806825)
|    |    |    |    |    |    +-libGvoiceNN.so(md5:64d4d6934435c361419b1ebc34f3ae13)
|    |    |    |    |    +-armeabi-v7a
|    |    |    |    |    |    +-libGVoice.so(md5:d5a165b99fae9913d78952ac552e80de)
|    |    |    |    |    |    +-libGvoiceNN.so(md5:c854f76396b0a8547e18c6e887f5c3f3)
|    |    |    |    |    +-wwise
|    |    |    |    |    |    +-arm64-v8a
|    |    |    |    |    |    |    +-libGVoicePlugin.so(md5:a626c96c4ea8adb5c11d36af7e8142a0)
|    |    |    |    |    |    +-armeabi-v7a
|    |    |    |    |    |    |    +-libGVoicePlugin.so(md5:150d6ee952e94e64a61fb702fdd12763)
|    |    |    |    |    |    +-x86
|    |    |    |    |    |    |    +-libGVoicePlugin.so(md5:4517cfd61ce17702750ffd67e36a3721)
|    |    |    |    |    +-x86
|    |    |    |    |    |    +-libGVoice.so(md5:4213f4c3c020c6b4120b400a8aac416e)
|    |    |    |    |    +-x86_64
|    |    |    |    |    |    +-libGVoice.so(md5:74ac4d0a63d15f64f59ac72a0da1b9d2)
|    |    |    +-Mac
|    |    |    |    +-libGVoice.a(md5:e4374c5365da3ef8936baeeec75a8ba8)
|    |    |    +-Win
|    |    |    |    +-X86
|    |    |    |    |    +-GVoice.dll(md5:8fb554f2063c0b7a0001f8a5322861a4)
|    |    |    |    |    +-GVoice.lib(md5:8961d16c7214e9d6f506860dcb4f5cfe)
|    |    |    |    |    +-GVoice.pdb(md5:5cef7f3f96063582feaabc4b92e25d26)
|    |    |    |    |    +-config.json(md5:09884fc18a2aa7f78fcb9a5ea43f12b0)
|    |    |    |    |    +-gvoice_decoder.md(md5:a5667b3630270b3dcd62c19effe6a818)
|    |    |    |    |    +-gvoice_encoder.md(md5:8ae4a6690ab579fc91c9b66cf496a7e7)
|    |    |    |    |    +-libgvoicensmodel.bin(md5:3dd9e79d008513dfeb9369aa1845dcd7)
|    |    |    |    |    +-libwxvoiceembed.bin(md5:282b06afa1a0f5c07e73b87a0756fe95)
|    |    |    |    |    +-pthreadVC2.dll(md5:f15437966f35398921004fae059c59f2)
|    |    |    |    |    +-wave_3d_data.bin(md5:7746ba475230edbc56123ee36f7b9329)
|    |    |    |    |    +-wave_dafx_data.bin(md5:7746ba475230edbc56123ee36f7b9329)
|    |    |    |    +-X86_64
|    |    |    |    |    +-GVoice.dll(md5:9831fabc62f4abde136cbe251ec28c2e)
|    |    |    |    |    +-GVoice.lib(md5:da94f595c279b4dc28526652dcf2c11c)
|    |    |    |    |    +-GVoice.pdb(md5:6cc626e92e14f312e3ab46bff9d27f9c)
|    |    |    |    |    +-config.json(md5:09884fc18a2aa7f78fcb9a5ea43f12b0)
|    |    |    |    |    +-gvoice_decoder.md(md5:a5667b3630270b3dcd62c19effe6a818)
|    |    |    |    |    +-gvoice_encoder.md(md5:8ae4a6690ab579fc91c9b66cf496a7e7)
|    |    |    |    |    +-libgvoicensmodel.bin(md5:3dd9e79d008513dfeb9369aa1845dcd7)
|    |    |    |    |    +-libwxvoiceembed.bin(md5:282b06afa1a0f5c07e73b87a0756fe95)
|    |    |    |    |    +-pthreadVC2.dll(md5:b131c071a3f3cb4865ebda1247c1c8c7)
|    |    |    |    |    +-wave_3d_data.bin(md5:7746ba475230edbc56123ee36f7b9329)
|    |    |    |    |    +-wave_dafx_data.bin(md5:7746ba475230edbc56123ee36f7b9329)
|    |    |    +-iOS
|    |    |    |    +-GVoice_dylib.embeddedframework.zip(md5:7a69a3711947566c82201e0b8cbca2b3)
|    |    |    |    +-wwise
|    |    |    |    |    +-GVoicePluginFactory.h(md5:ca56f2147ec266905d9b77ceaad19e58)
|    |    |    |    |    +-libGVoicePlugin.a(md5:bfcbdc9341d316cdae1a12a73f81a7dc)
+-MSDKApple
|    +-MSDKApple.uplugin(md5:3d44d6add38b4ee6c1e40866881104c0)
|    +-Resources
|    |    +-Icon128.png(md5:7b15f15f14b3399e42fed1a64d9f0cb4)
|    +-Source
|    |    +-MSDKApple
|    |    |    +-MSDKApple.Build.cs(md5:9dceb80d81cd3a9c9c81e12afb4a89f1)
|    |    |    +-MSDKApple_UPL.xml(md5:4a35de0d657fb71dfb4f2cdaae4524c1)
|    |    |    +-Private
|    |    |    |    +-MSDKApple.cpp(md5:279068801671028c8f16c3111555e50b)
|    |    |    +-Public
|    |    |    |    +-MSDKApple.h(md5:000f5ce160e62cc7d213c348debe6884)
|    |    |    +-lib
|    |    |    |    +-iOS
|    |    |    |    |    +-MSDKApple
|    |    |    |    |    |    +-MSDKApple.embeddedframework.zip(md5:607411e52afe7d85dc87d45897de9b41)
+-MSDKCore
|    +-MSDKCore.uplugin(md5:9b4ec0f2f64edc5687b95070db6a155f)
|    +-Resources
|    |    +-Icon128.png(md5:7b15f15f14b3399e42fed1a64d9f0cb4)
|    +-Source
|    |    +-MSDKCore
|    |    |    +-MSDKCore.Build.cs(md5:44deccdc52539769c0346675ae2ab8f8)
|    |    |    +-MSDKCore_UPL.xml(md5:0e249ada6a45e460c5d90fa3008ce287)
|    |    |    +-Private
|    |    |    |    +-.msdk_core(md5:f90dedece38170fdbafb21305cb9dfea)
|    |    |    |    +-MSDKAccount.cpp(md5:d5e48b680e083842e0b6e7e7d1a36709)
|    |    |    |    +-MSDKCore.cpp(md5:5c85f0cab4283b73df805e42e16c1eba)
|    |    |    |    +-MSDKCrash.cpp(md5:d69595890bd1e71cee9b1035eef786f7)
|    |    |    |    +-MSDKDefine.cpp(md5:550c02bbbdf71ee3dfc5c9570416535a)
|    |    |    |    +-MSDKExtend.cpp(md5:e8a7043d950e9e883c9c0b2faa0129b3)
|    |    |    |    +-MSDKFriend.cpp(md5:b327c5ba73fc6be67b48eb6c997bac9c)
|    |    |    |    +-MSDKGame.cpp(md5:a9b9d3d0a9cc88cd9d7da32194904375)
|    |    |    |    +-MSDKGroup.cpp(md5:d7a66fea57f3622c3f43c8104a017045)
|    |    |    |    +-MSDKLBS.cpp(md5:2a9be7fcc9838e0cbc4940fc4f6e952c)
|    |    |    |    +-MSDKLog.cpp(md5:f4becd1c5eb9e1e67587c4ef8e080051)
|    |    |    |    +-MSDKLogin.cpp(md5:6765825357ce5d3a34455a8375aa7493)
|    |    |    |    +-MSDKNotice.cpp(md5:e5add9317eda3d873fc41b96d0505c77)
|    |    |    |    +-MSDKPush.cpp(md5:925e6eb8b37a6da3d20c0610746d0b5b)
|    |    |    |    +-MSDKReport.cpp(md5:b09d9427acbc33640bcbc9fd1de4f889)
|    |    |    |    +-MSDKWebView.cpp(md5:694e77cd71bea1116ff8cb14908cc26f)
|    |    |    |    +-iOS
|    |    |    |    |    +-IOSAppDelegate+MSDK.mm(md5:b8ef66301f6dc30f23a3a77b5d62ecdc)
|    |    |    +-Public
|    |    |    |    +-.msdk_pthread(md5:587bf4de0721b6e31a0a5f9be9ec7cd6)
|    |    |    |    +-.msdk_sched(md5:a288e2b1c1674b226da7e1663a8e4b66)
|    |    |    |    +-.msdk_semaphore(md5:055ca7bda23c3d3bcac4bf631e7ab5e6)
|    |    |    |    +-IServeiceAccount.h(md5:7fd090bcf98d660cffad8dc8b39cb6b8)
|    |    |    |    +-IServiceAccount.h(md5:554766bfb170a1e4c668017bb080dc97)
|    |    |    |    +-MSDK.h(md5:e41389ec96824d71f217c29e058508c7)
|    |    |    |    +-MSDKAccount.h(md5:757fb5597dd9d68b7826a51322db7e1a)
|    |    |    |    +-MSDKApplicationDelegate.h(md5:f120960ac7ba9f7b43a2aa0e3db9b4b9)
|    |    |    |    +-MSDKCompatLayer.h(md5:f9476ddcd64a5285b8a29982b7eec6f0)
|    |    |    |    +-MSDKConfig.h(md5:12953ee6756e434679cbe9615c1bfa73)
|    |    |    |    +-MSDKConfigManager.h(md5:d8b360ed5385c182bf17ef5a0e40964a)
|    |    |    |    +-MSDKCore.h(md5:0a917590176636cf88cd7550baa3f828)
|    |    |    |    +-MSDKCrash.h(md5:9a2d30b27e3a0d638323e84d1a494916)
|    |    |    |    +-MSDKCrashDelegate.h(md5:6aaf549dfc217b3c2b6bc8750616a1a1)
|    |    |    |    +-MSDKDefine.h(md5:fb73660ea45f149e2d52df3c763fdf41)
|    |    |    |    +-MSDKError.h(md5:e46a5ded051f93edfbde9cfb62d693cf)
|    |    |    |    +-MSDKExtend.h(md5:63c80889dbac57379a03246b912e637b)
|    |    |    |    +-MSDKFileUtils.h(md5:4b314187b705a0a33bf4fa5af5ac4b7c)
|    |    |    |    +-MSDKFriend.h(md5:867879efd5a808f3f88c892ef9a698fd)
|    |    |    |    +-MSDKFriendDelegate.h(md5:636ccf755392339be406b5bc3c6a2bd6)
|    |    |    |    +-MSDKGame.h(md5:cdd63a4a600987238dfdec3e2f355ba5)
|    |    |    |    +-MSDKGameDelegate.h(md5:142f41f01df4679fc48655f5af3ac7ab)
|    |    |    |    +-MSDKGroup.h(md5:81691d02c15b9c48040a084de6c9bb69)
|    |    |    |    +-MSDKGroupDelegate.h(md5:d60ddf83510fdabf48c474dcf8c5e0b8)
|    |    |    |    +-MSDKJsonManager.h(md5:312d3e3e11f91d237e4e442058a0f434)
|    |    |    |    +-MSDKJsonReader.h(md5:c588d65d1de01ce326a2aaa778ada8d5)
|    |    |    |    +-MSDKJsonWriter.h(md5:468db7e033d62b7babc445b8a43259a8)
|    |    |    |    +-MSDKLBS.h(md5:6cc030aa3c39396c75013d3eec88f717)
|    |    |    |    +-MSDKLBSDelegate.h(md5:b4f2eff4c41eb115561963840f94d906)
|    |    |    |    +-MSDKLifeCycleAble.h(md5:083d2465057d66165612bb4165f62255)
|    |    |    |    +-MSDKLifeCycleManager.h(md5:7128c200fdde30cce6806fcb80e43971)
|    |    |    |    +-MSDKLog.h(md5:7fce064aaa5c894b40d0f86e02ecfa53)
|    |    |    |    +-MSDKLogUtil.h(md5:d1b9513b894a882a898f93c4a72f31fc)
|    |    |    |    +-MSDKLogin.h(md5:fad06037fade378645dd6dbfe1af9294)
|    |    |    |    +-MSDKLoginDelegate.h(md5:c51d1db76c4f4cdd5712fc20045e37a2)
|    |    |    |    +-MSDKLoginIMPL.h(md5:9d9cc81ffdcda24f59d76c369e106140)
|    |    |    |    +-MSDKMacroExpand.h(md5:a3387d7c29d22a3769408c820fa10e06)
|    |    |    |    +-MSDKMacros.h(md5:29fe33ac60979a6a4464c213b68d3c49)
|    |    |    |    +-MSDKMutex.h(md5:d98ab35f20937ab88ffcdbac38a2329c)
|    |    |    |    +-MSDKNetworkUtils.h(md5:45325e90b8ba7795548167363390ad77)
|    |    |    |    +-MSDKNotice.h(md5:5815f787d288f47d0c6f0f977ea4348d)
|    |    |    |    +-MSDKObserverManager.h(md5:354f821ab8b05a5c9177577e88eb9cfc)
|    |    |    |    +-MSDKProtocol.h(md5:484fe738c0ce9e077da05d18823b0666)
|    |    |    |    +-MSDKPush.h(md5:e6c775aaf50150d13e737abb6af224fb)
|    |    |    |    +-MSDKPushDelegate.h(md5:29cdcbee751b0c48ab9a875e450111c1)
|    |    |    |    +-MSDKQrcodeVC.h(md5:a0157e434cb02df0b6502947057b189e)
|    |    |    |    +-MSDKRename.h(md5:6f071dd19493b3839d369399898573b4)
|    |    |    |    +-MSDKReport.h(md5:3b2c32216aebbf7bf9b9a3a7387da6b0)
|    |    |    |    +-MSDKReportDelegate.h(md5:d82980016a9979d507aa4747b0c8a04d)
|    |    |    |    +-MSDKSensitive.h(md5:c54aee7f675d7c7b6f6d4623462f698b)
|    |    |    |    +-MSDKSensitiveOc.h(md5:0d07b421522ff93695d25b810d10eb44)
|    |    |    |    +-MSDKSensitivityDelegate.h(md5:c3c09e1c2b88bdd955e4687e2fd33591)
|    |    |    |    +-MSDKSingleton.h(md5:2c45b4e99cc56a3275184eb9ade707ea)
|    |    |    |    +-MSDKSynthesizeSingleton.h(md5:713b6da93c9fd6f50e831f544d46b327)
|    |    |    |    +-MSDKTools.h(md5:94721ae735741b213df9994a5fbfdfdf)
|    |    |    |    +-MSDKUtils.h(md5:8b675109f34402e2d6b06f9789134273)
|    |    |    |    +-MSDKUtilsIOS.h(md5:948b6e6fcfce787ea36ef010a147013d)
|    |    |    |    +-MSDKWebView.h(md5:7ae94916dd923de7cf8ae134b1c0f103)
|    |    |    |    +-MSDKWebViewDelegate.h(md5:2d3f6bd35da3efaa61b6f38a2a76cb99)
|    |    |    +-lib
|    |    |    |    +-Android
|    |    |    |    |    +-assets
|    |    |    |    |    |    +-MSDKBuglyConfig.json(md5:b5b82f0a2ed7c2a60d005448c7c8e606)
|    |    |    |    |    |    +-MSDKConfig.ini(md5:512d4f3a51e59c8bd99b00309d541d5c)
|    |    |    |    |    |    +-MSDKRetMsg.json(md5:631f0cf1af9d47ff6eac49387edfb189)
|    |    |    |    |    +-msdk-core
|    |    |    |    |    |    +-AndroidManifest.xml(md5:cfcf8775f4f069a6d0ed1880a3db56b6)
|    |    |    |    |    |    +-R.txt(md5:9a86da1579144cd6440ea148f592e4b2)
|    |    |    |    |    |    +-additions.gradle(md5:ffa49636af5c5b43c5fcd3c9ad27a9a8)
|    |    |    |    |    |    +-assets
|    |    |    |    |    |    |    +-msdk_permission_content.html(md5:7a020054dad3a6c6ac30aed7363ce7e2)
|    |    |    |    |    |    |    +-msdk_policy_content.html(md5:a33f7f5a5f5e3386b6fb61c6eb73d9a4)
|    |    |    |    |    |    |    +-popup
|    |    |    |    |    |    |    |    +-MSDKPopupLocal.config(md5:6eccb05d613176b421e83e1859f72fb7)
|    |    |    |    |    |    |    |    +-MSDKPopup_0_2_2_0bba847357668ad690aef018a6771fa6.html(md5:0bba847357668ad690aef018a6771fa6)
|    |    |    |    |    |    |    |    +-MSDKPopup_0_2_2_f2e8f5050690e378955d1278b331cfb2.html(md5:f2e8f5050690e378955d1278b331cfb2)
|    |    |    |    |    |    +-libs
|    |    |    |    |    |    |    +-MSDKPopup.jar(md5:814231f6afcabc76d1b16d1a96758351)
|    |    |    |    |    |    |    +-arm64-v8a
|    |    |    |    |    |    |    |    +-libMSDKCore.so(md5:1f1ccd1fb82801d9309219aeaea36b5b)
|    |    |    |    |    |    |    +-armeabi-v7a
|    |    |    |    |    |    |    |    +-libMSDKCore.so(md5:4f5270c8c0f3f2dbf9fcf61f07b757ba)
|    |    |    |    |    |    |    +-msdk-core.jar(md5:d8a2eb93742625bbc46833b265c93af2)
|    |    |    |    |    |    |    +-x86
|    |    |    |    |    |    |    |    +-libMSDKCore.so(md5:599098b7dc4d6f58085ab21b227029f0)
|    |    |    |    |    |    |    +-x86_64
|    |    |    |    |    |    |    |    +-libMSDKCore.so(md5:24991c47cd078555e0a04b5d66c2d996)
|    |    |    |    |    |    +-proguard-project.txt(md5:f9ab6f2b448dce9689e223a27945f2c9)
|    |    |    |    |    |    +-project.properties(md5:404765ee5cc019975e97b7e6ba7afdf0)
|    |    |    |    |    |    +-res
|    |    |    |    |    |    |    +-anim
|    |    |    |    |    |    |    |    +-msdkpopup_dialog_enter_anim.xml(md5:562af5dd9eb264dfdc2f49da270257eb)
|    |    |    |    |    |    |    |    +-msdkpopup_dialog_exit_anim.xml(md5:54c73dc72c73f30cade21050d7fdea62)
|    |    |    |    |    |    |    +-color
|    |    |    |    |    |    |    |    +-msdk_button_color.xml(md5:8d91e0c4822a4d8279368f3e276f54f5)
|    |    |    |    |    |    |    +-drawable
|    |    |    |    |    |    |    |    +-msdk_bind_checkbox_selector.xml(md5:79cc3a75715b577f19a13428ddefd170)
|    |    |    |    |    |    |    |    +-msdk_bind_ui_button_disabled_bg.xml(md5:3734e6ddf9c3d5243c33dc8ba719dadf)
|    |    |    |    |    |    |    |    +-msdk_bind_ui_button_enabled_bg.xml(md5:275e25fa331178133965f1de2055ae6a)
|    |    |    |    |    |    |    |    +-msdk_bind_ui_button_selector.xml(md5:7df8c761ac71bdda0bc96320f827d974)
|    |    |    |    |    |    |    |    +-msdk_bind_ui_circle_checked.xml(md5:81e9adbd42c2930f1f87ce82f83720c6)
|    |    |    |    |    |    |    |    +-msdk_bind_ui_gradient_bg.xml(md5:9c5149fda0f3532b09c5a013033e1b9a)
|    |    |    |    |    |    |    |    +-msdk_bind_ui_inner_window_bg.xml(md5:467ed765ca45264330b121fc86869f28)
|    |    |    |    |    |    |    |    +-msdk_bind_ui_text_line.xml(md5:c16b784037b91bbde373b9ce56b30894)
|    |    |    |    |    |    |    |    +-msdk_policy_bg.png(md5:66268dd5cfd7614afb903c799aa0e858)
|    |    |    |    |    |    |    |    +-msdk_policy_confirm_button_bg.xml(md5:086ed3b6dbcf01085da19361b7bae8a0)
|    |    |    |    |    |    |    |    +-msdk_policy_confirm_button_bg_pressed.xml(md5:3c49cd450593c41e60e4ea86f5f1780b)
|    |    |    |    |    |    |    |    +-msdk_policy_confirm_button_selector.xml(md5:13843ce67a8c53f3727707bc2c2a8508)
|    |    |    |    |    |    |    |    +-msdk_policy_dialog_bg.png(md5:66268dd5cfd7614afb903c799aa0e858)
|    |    |    |    |    |    |    |    +-msdk_policy_dialog_grey_bg.xml(md5:4030e3f729a3246d25f75cbde22f4652)
|    |    |    |    |    |    |    |    +-msdk_policy_grey_bg.xml(md5:26541b32aedda9a96b8aaa69497e3778)
|    |    |    |    |    |    |    |    +-msdk_policy_layout_button_group_bg.xml(md5:13c9f57876e65bd21f0f2c8693891333)
|    |    |    |    |    |    |    |    +-msdk_policy_layout_inner_window_bg.xml(md5:7458f9d58b35622af1d11a1edbb54208)
|    |    |    |    |    |    |    |    +-msdk_policy_other_button_bg.xml(md5:fed3d0e2b83b2ad0759717ea7e66a4c1)
|    |    |    |    |    |    |    |    +-msdk_policy_other_button_bg_pressed.xml(md5:9e517287f8bd78e3bb61d84f5278b733)
|    |    |    |    |    |    |    |    +-msdk_policy_other_button_selector.xml(md5:2beb31b799462568c06f54073f7373e6)
|    |    |    |    |    |    |    |    +-msdk_popup_back.png(md5:17dd081a7cb72b98a6007797c2d6d7b3)
|    |    |    |    |    |    |    |    +-msdk_popup_close.png(md5:f7d90894ad6e4054f9240780750c8536)
|    |    |    |    |    |    |    |    +-msdk_popup_refresh.png(md5:b11646bb18f4c5b88facee7d96a19b72)
|    |    |    |    |    |    |    |    +-msdknotify.png(md5:4b38865b4502732e4681f786f78f0d08)
|    |    |    |    |    |    |    |    +-msdkpopup_dialog_button_bg.xml(md5:0a1c31581bfe517e9bba47eb92014179)
|    |    |    |    |    |    |    |    +-msdkpopup_dialog_other_button_bg.xml(md5:7c3f76aaa17bea437ec2c0d1c9cccb35)
|    |    |    |    |    |    |    |    +-msdkpopup_dialog_window_write_bg.xml(md5:9a6b6490746e4196d6a715e23fb54f14)
|    |    |    |    |    |    |    +-drawable-land
|    |    |    |    |    |    |    |    +-msdk_policy_bg.png(md5:f4dd9b6f8f927ffb5fb69f2901871839)
|    |    |    |    |    |    |    +-drawable-xxhdpi-v4
|    |    |    |    |    |    |    |    +-msdk_img_icon_bind_back.png(md5:bee2d6717ed3a17fda486de764348a0a)
|    |    |    |    |    |    |    |    +-msdk_img_icon_bind_cancel.png(md5:c89593b60ba1ac1b572baab1be54a738)
|    |    |    |    |    |    |    |    +-msdk_img_icon_check_white.png(md5:f779d70449754282259efab2e2c9c234)
|    |    |    |    |    |    |    |    +-msdk_img_icon_checkbox_checked.png(md5:5c1045ac1aa379c444ba7af74f4de5cd)
|    |    |    |    |    |    |    |    +-msdk_img_icon_checkbox_unchecked.png(md5:ada9b778f9bf5f9f41951936d00ef3a8)
|    |    |    |    |    |    |    +-layout
|    |    |    |    |    |    |    |    +-activity_msdk_policy.xml(md5:91ffa7a3e3afa12789fac1daf7542c9c)
|    |    |    |    |    |    |    |    +-activity_msdk_policy_v2.xml(md5:00030c07990c0ae0d6b675af6da7e17e)
|    |    |    |    |    |    |    |    +-layout_msdk_bind_ui_enter_email.xml(md5:a30d74c0a96acfe3c3192805d2bd5a50)
|    |    |    |    |    |    |    |    +-layout_msdk_bind_ui_enter_verifycode.xml(md5:23dd47837f1da2c2a4aaee18e3865f44)
|    |    |    |    |    |    |    |    +-layout_msdk_verify_code.xml(md5:73166321933b63d3429c3e2260754ecb)
|    |    |    |    |    |    |    |    +-msdk_bind_ui_container.xml(md5:5fe70b5b489dc4929605d31c4e48353a)
|    |    |    |    |    |    |    |    +-msdk_permission_layout.xml(md5:4bd3122e0d3fd75448fc243614bac23c)
|    |    |    |    |    |    |    |    +-msdk_permission_layout_second.xml(md5:c614652b2ce9ad2ed1af855a3c699b22)
|    |    |    |    |    |    |    |    +-msdk_policy_layout.xml(md5:6edd5ae96e8d87cdfd3124faff6b8ca4)
|    |    |    |    |    |    |    |    +-msdkpopup_dialog_fragment_layout.xml(md5:109186b0c35fd3a4144773636f1b7d0e)
|    |    |    |    |    |    |    |    +-msdkpopup_dialog_policy_layout.xml(md5:35187cb0ce87a37143f899b3e1c5241e)
|    |    |    |    |    |    |    |    +-msdkpopup_dialog_richtext_layout.xml(md5:83840cb0c6e8c9cb09900c3e7684b401)
|    |    |    |    |    |    |    |    +-msdkpopup_dialog_webview_layout.xml(md5:0795d0264e1e89407db3753dabe01cf3)
|    |    |    |    |    |    |    +-layout-land
|    |    |    |    |    |    |    |    +-msdk_permission_layout.xml(md5:3dbbac7da732d3bba7f1c5a7c009bb22)
|    |    |    |    |    |    |    |    +-msdk_permission_layout_second.xml(md5:6ec6b6bdbb1a6360317eb8ae44697440)
|    |    |    |    |    |    |    |    +-msdk_policy_layout.xml(md5:e670d7b2599130eaec92d88a7b7dee51)
|    |    |    |    |    |    |    |    +-msdkpopup_dialog_policy_layout.xml(md5:01f72159d2ac918c0546bb2be7885471)
|    |    |    |    |    |    |    |    +-msdkpopup_dialog_richtext_layout.xml(md5:399063d206e038ee7017def8398f282e)
|    |    |    |    |    |    |    |    +-msdkpopup_dialog_webview_layout.xml(md5:0795d0264e1e89407db3753dabe01cf3)
|    |    |    |    |    |    |    +-values
|    |    |    |    |    |    |    |    +-values.xml(md5:0019deb7e685ba6bce829d2ff4a64d30)
|    |    |    |    |    |    |    +-values-ar
|    |    |    |    |    |    |    |    +-values-ar.xml(md5:bc6c3a6995dbe39d0d493cd4dd8698c7)
|    |    |    |    |    |    |    +-values-de
|    |    |    |    |    |    |    |    +-values-de.xml(md5:2a17e978aa20a208a755fac7ccb7ad21)
|    |    |    |    |    |    |    +-values-en
|    |    |    |    |    |    |    |    +-values-en.xml(md5:83186e20083ef85c4e545a6058c9c59f)
|    |    |    |    |    |    |    +-values-en-rUS
|    |    |    |    |    |    |    |    +-values-en-rUS.xml(md5:7e47770cf02f7a752e93fa9590e4a376)
|    |    |    |    |    |    |    +-values-es
|    |    |    |    |    |    |    |    +-values-es.xml(md5:a056c394d8769d8b14930196294475a7)
|    |    |    |    |    |    |    +-values-fr
|    |    |    |    |    |    |    |    +-values-fr.xml(md5:fe2d3a3146f0fe5246bcdab9a65b3bc5)
|    |    |    |    |    |    |    +-values-in
|    |    |    |    |    |    |    |    +-values-in.xml(md5:1d369b3cb8acb0d51a85f561ae9a6418)
|    |    |    |    |    |    |    +-values-ja
|    |    |    |    |    |    |    |    +-values-ja.xml(md5:9ca0a7e13c56dc50372d380054f702d2)
|    |    |    |    |    |    |    +-values-ko
|    |    |    |    |    |    |    |    +-values-ko.xml(md5:17f3483a66602f399f36f60e968ee95a)
|    |    |    |    |    |    |    +-values-land
|    |    |    |    |    |    |    |    +-values-land.xml(md5:6acc353b6fb4a37b442583c64536275c)
|    |    |    |    |    |    |    +-values-pt
|    |    |    |    |    |    |    |    +-values-pt.xml(md5:ddc324ebbc16a74a80cb71ff8ce4fb03)
|    |    |    |    |    |    |    +-values-ru
|    |    |    |    |    |    |    |    +-values-ru.xml(md5:75a31591927c81396542fe47d042310f)
|    |    |    |    |    |    |    +-values-th
|    |    |    |    |    |    |    |    +-values-th.xml(md5:6a7c7e628a730f8a27d16814580e35fe)
|    |    |    |    |    |    |    +-values-tr
|    |    |    |    |    |    |    |    +-values-tr.xml(md5:72feef12c10dcfaa268ea19092f948a7)
|    |    |    |    |    |    |    +-values-vi
|    |    |    |    |    |    |    |    +-values-vi.xml(md5:d1da3e2325555138cacbd5d2084c866f)
|    |    |    |    |    |    |    +-values-zh
|    |    |    |    |    |    |    |    +-values-zh.xml(md5:d114423080822c9f7379a1b8ada20020)
|    |    |    |    |    |    |    +-values-zh-rHK
|    |    |    |    |    |    |    |    +-values-zh-rHK.xml(md5:e65205e4bc727de9b89592ba79bb0490)
|    |    |    |    |    |    |    +-values-zh-rTW
|    |    |    |    |    |    |    |    +-values-zh-rTW.xml(md5:19644cba09bb51e957b16b8df691371b)
|    |    |    |    +-Win64
|    |    |    |    |    +-EOSSDK-Win64-Shipping.dll(md5:af708c0c6b6ac0c49417b9404362c41c)
|    |    |    |    |    +-MSDKCefWebView.dll(md5:28488daa7ebb7a8fa586de02a2a6cf07)
|    |    |    |    |    +-MSDKCefWebView.exp(md5:8af644d24eec3851360ce14fe40ef3f8)
|    |    |    |    |    +-MSDKCefWebView.lib(md5:a8d17bb7a5eba3fff5112517ecce2c34)
|    |    |    |    |    +-MSDKCefWebView.pdb(md5:e8300cef38150a3da9b75c9401835207)
|    |    |    |    |    +-MSDKConfig.ini(md5:88989ae39d75765943c2de1a829252f7)
|    |    |    |    |    +-MSDKCore.dll(md5:4f6f417fe6b424416b9333b267f234a7)
|    |    |    |    |    +-MSDKCore.exp(md5:ebd0203cccd8e2b4e3fc567ee1e6d5b8)
|    |    |    |    |    +-MSDKCore.lib(md5:2bc4ed074fbe54dca4a93e1bd96d698e)
|    |    |    |    |    +-MSDKCore.pdb(md5:7b29544c825a152f8cf56688bc7524ba)
|    |    |    |    |    +-MSDKRetMsg.json(md5:48e4caebac63f54ccdaa0dcfb39b406c)
|    |    |    |    |    +-MSDKUnityAdapter.dll(md5:bed66efda241e9e17aa9092dfb4b9198)
|    |    |    |    |    +-MSDKUnityAdapter.lib(md5:8ed4a08fa638f70083d7878a6b37b9df)
|    |    |    |    |    +-MSDKUnityAdapter.pdb(md5:a0a316a86cb671e19ad76cf9768719d8)
|    |    |    |    |    +-MSDKWebViewRender.exe(md5:991935c35f2da2ccda3da897e197e86a)
|    |    |    |    |    +-MSDKWebViewRender.pdb(md5:3196fcd713382a2bea5efd0d3f700bd0)
|    |    |    |    |    +-WebView2Loader.dll(md5:ff09a22bb8ff9c2a966e9e74a45c1201)
|    |    |    |    |    +-cacert.pem(md5:882db4f54c25b5157cef6c0d182e729e)
|    |    |    |    |    +-cef.pak(md5:be4bddc2a6b4b4b1ae49d9ea0a388967)
|    |    |    |    |    +-cef_100_percent.pak(md5:4996e460c4508aedf0bdb1e23a45e0bb)
|    |    |    |    |    +-cef_200_percent.pak(md5:5b1dae18ae7137b5c4709ce4f6bfde84)
|    |    |    |    |    +-cef_extensions.pak(md5:8f7e628f539bcf5861424037226d084a)
|    |    |    |    |    +-chrome_elf.dll(md5:86b6677e0af4513691437df48bfdfc7e)
|    |    |    |    |    +-d3dcompiler_47.dll(md5:222d020bd33c90170a8296adc1b7036a)
|    |    |    |    |    +-debug.log(md5:479ec2914d888170f18c5d2a05e4979c)
|    |    |    |    |    +-devtools_resources.pak(md5:4072a984735b11b2a4302553c1e84680)
|    |    |    |    |    +-icudtl.dat(md5:03205e5952ea7b803839ecfe3bb000d6)
|    |    |    |    |    +-libEGL.dll(md5:c5fcb223fbef5d28a595e40aff5b6a7f)
|    |    |    |    |    +-libGLESv2.dll(md5:96fa42669302661657eabd274dc202ed)
|    |    |    |    |    +-libcef_msdk.dll(md5:35eef3220d1bf532a9db9cbe23e906a1)
|    |    |    |    |    +-libcrypto-1_1.dll(md5:d38634f0b5d11fed982dd10e9ab06123)
|    |    |    |    |    +-libcurl.dll(md5:1efef1a288cbc48fe846d120a80c42f1)
|    |    |    |    |    +-libssh2.dll(md5:e9f2c86ae1d2233c0cfd820947a49719)
|    |    |    |    |    +-libssl-1_1.dll(md5:a0a250650713d0ba11cc8e6a62da33d5)
|    |    |    |    |    +-locales
|    |    |    |    |    |    +-am.pak(md5:60ef8bc440d05f76578923ed44044178)
|    |    |    |    |    |    +-ar.pak(md5:93209dbb8f1982087fbb73df7256a617)
|    |    |    |    |    |    +-bg.pak(md5:e5f9d6a6d68c211148cc6340c4afcab6)
|    |    |    |    |    |    +-bn.pak(md5:24b4f4a7ce60b3b0fd9b86e065278c6c)
|    |    |    |    |    |    +-ca.pak(md5:b333882d88df597b5baad4b925a0e02a)
|    |    |    |    |    |    +-cs.pak(md5:a439347900604188c8811c157382b8c3)
|    |    |    |    |    |    +-da.pak(md5:db6505cd6997cfadb2afeb489f44f606)
|    |    |    |    |    |    +-de.pak(md5:9cc0941341c0b34344c3f4bdf2e99a8b)
|    |    |    |    |    |    +-el.pak(md5:0c76df09b466fa2a15b8078ff549bad9)
|    |    |    |    |    |    +-en-GB.pak(md5:885434da2990727be5fc25fa9cfdad51)
|    |    |    |    |    |    +-en-US.pak(md5:58a9125a8b155e4b39eb6c3aa0406e1d)
|    |    |    |    |    |    +-es-419.pak(md5:3f2793d08759ac87e99999825e1af5aa)
|    |    |    |    |    |    +-es.pak(md5:bf9604d751dbd0ac9f7ca9d89f18ae51)
|    |    |    |    |    |    +-et.pak(md5:d5a9b62139150458da47cbb3c5b431ce)
|    |    |    |    |    |    +-fa.pak(md5:0752ae5117ca87c82dc95664deae7ef3)
|    |    |    |    |    |    +-fi.pak(md5:b87fabb3f2170235f3fad0964fe27ecf)
|    |    |    |    |    |    +-fil.pak(md5:503bbfa2bd8e2cbace3a9e033122c885)
|    |    |    |    |    |    +-fr.pak(md5:ff69a3a7dd4732d5440c772b216692c0)
|    |    |    |    |    |    +-gu.pak(md5:ac48327614d1ba47e06c40865bb9b2b6)
|    |    |    |    |    |    +-he.pak(md5:6e66320d5eed4114b312d2c2037dcde0)
|    |    |    |    |    |    +-hi.pak(md5:66f19224d9852ae2f3b540b53f2e6793)
|    |    |    |    |    |    +-hr.pak(md5:2d91f83237eb149cb6e43a2b18b0abce)
|    |    |    |    |    |    +-hu.pak(md5:b3160a54fca25075cafff66e099da264)
|    |    |    |    |    |    +-id.pak(md5:f9d146a739b46904e53232cbf10e737b)
|    |    |    |    |    |    +-it.pak(md5:c34b8d695683c4bac578327111622a04)
|    |    |    |    |    |    +-ja.pak(md5:e7c8498ef62340a4fedbecc651de7e2f)
|    |    |    |    |    |    +-kn.pak(md5:77d08b9042990757a7d778e16cd39d06)
|    |    |    |    |    |    +-ko.pak(md5:d300c3ea843b7a95f03a3c400f70faae)
|    |    |    |    |    |    +-lt.pak(md5:eb8b0a1ee08cae6544c459e221a4acf7)
|    |    |    |    |    |    +-lv.pak(md5:e80321f917f9582ebf0d45c8492c672f)
|    |    |    |    |    |    +-ml.pak(md5:faeed525522f8f73eb03b641b0552c3f)
|    |    |    |    |    |    +-mr.pak(md5:27ba1c72375c6ca4d68b09a87a080cba)
|    |    |    |    |    |    +-ms.pak(md5:2611beeb713f3a16e5c6d089d344aeef)
|    |    |    |    |    |    +-nb.pak(md5:e14340d366aaedf0edeb95a8ad44cd26)
|    |    |    |    |    |    +-nl.pak(md5:3f8ed761fe542925e9bdd0ab1fef24c1)
|    |    |    |    |    |    +-pl.pak(md5:79d8e16ccddea02843325ae595107da0)
|    |    |    |    |    |    +-pt-BR.pak(md5:8706931d1c894bb86fc69c18905d6376)
|    |    |    |    |    |    +-pt-PT.pak(md5:ad1459473d1273df220a725d72c5e08f)
|    |    |    |    |    |    +-ro.pak(md5:bb56a317f1776fc99016b041779e6fe9)
|    |    |    |    |    |    +-ru.pak(md5:de800711bda2b01104b88cf4fa3a42d8)
|    |    |    |    |    |    +-sk.pak(md5:9c2131bbf824421811c70362ea5f0fd1)
|    |    |    |    |    |    +-sl.pak(md5:9583ff0e5fbbabc00d2c7b95a36f8eae)
|    |    |    |    |    |    +-sr.pak(md5:c194265d1c5eff6f166c29edccd69fe1)
|    |    |    |    |    |    +-sv.pak(md5:20c147e79ab2574b691926e0a03e9913)
|    |    |    |    |    |    +-sw.pak(md5:c621b8b65b7c7371c2f36b79fb9cc758)
|    |    |    |    |    |    +-ta.pak(md5:7d5e986bdc07533988a9ec80904b6949)
|    |    |    |    |    |    +-te.pak(md5:2aad6d231ad71719add34f811431b796)
|    |    |    |    |    |    +-th.pak(md5:c8385d2433e241ca3b50a3b341f0545d)
|    |    |    |    |    |    +-tr.pak(md5:33c477e6f1fdc32344eeb0113572a058)
|    |    |    |    |    |    +-uk.pak(md5:9b077a50ee7c7c6533159a9d58af2b76)
|    |    |    |    |    |    +-vi.pak(md5:0d8472b31c6c5c258508ce81853da044)
|    |    |    |    |    |    +-zh-CN.pak(md5:cded3bd555f50ee1cfb9709e952488c9)
|    |    |    |    |    |    +-zh-TW.pak(md5:3596538eb991749ea13a918c1a22aed4)
|    |    |    |    |    +-msvcr100.dll(md5:366fd6f3a451351b5df2d7c4ecf4c73a)
|    |    |    |    |    +-pthreadGC2.dll(md5:a8e566e3a09e9451c6d2c531758a5758)
|    |    |    |    |    +-pthreadVC2.dll(md5:4a502706d149c2f5854131a7758a90e2)
|    |    |    |    |    +-snapshot_blob.bin(md5:e5288e155598c06c9ef168a880b61e5a)
|    |    |    |    |    +-steam_api64.dll(md5:8afde2d19c89d0bf1a9f6ec475aa0ebb)
|    |    |    |    |    +-steam_appid.txt(md5:6ea2ef7311b482724a9b7b0bc0dd85c6)
|    |    |    |    |    +-v8_context_snapshot.bin(md5:0de66ddbaa28ad2e1dd5b1b15aada51f)
|    |    |    |    |    +-zlibwapi.dll(md5:e1dd4cdeef1651f21a80227c2db9623f)
|    |    |    |    +-iOS
|    |    |    |    |    +-MSDKCore
|    |    |    |    |    |    +-MSDKCore.embeddedframework.zip(md5:3085a239a13b4b20266d5344db9f0cd5)
|    |    |    |    |    |    +-MSDKSensitivity.embeddedframework.zip(md5:0c668e825a32cb90c86a9154007f3ae0)
+-MSDKFacebook
|    +-MSDKFacebook.uplugin(md5:1ba4ee1258a540d680a0c4a4b01d09cd)
|    +-Resources
|    |    +-Icon128.png(md5:7b15f15f14b3399e42fed1a64d9f0cb4)
|    +-Source
|    |    +-MSDKFacebook
|    |    |    +-MSDKFacebook.Build.cs(md5:599c24ecc7e6d492a7bd04df6a06047c)
|    |    |    +-MSDKFacebook_UPL.xml(md5:745dd42a8eb49acfc35d60a3ebd5f172)
|    |    |    +-Private
|    |    |    |    +-MSDKFacebook.cpp(md5:7f3f33639a8ab84383b2f9c536606d6d)
|    |    |    +-Public
|    |    |    |    +-MSDKFacebook.h(md5:b0236762753ba76a4387d26e65145b24)
|    |    |    +-lib
|    |    |    |    +-Android
|    |    |    |    |    +-msdk-facebook
|    |    |    |    |    |    +-AndroidManifest.xml(md5:33d3ec8a071c49f2b2cf6479f1bcffbd)
|    |    |    |    |    |    +-R.txt(md5:cc0a7601a78ad7ee6c432fc3fd79091c)
|    |    |    |    |    |    +-additions.gradle(md5:6e68b98be519db157fd46119e6e40934)
|    |    |    |    |    |    +-libs
|    |    |    |    |    |    |    +-msdk-facebook.jar(md5:13758853f25470e31d14aa032a5fb9ff)
|    |    |    |    |    |    +-proguard-project.txt(md5:adf6f233b18261975991f1825834afc7)
|    |    |    |    |    |    +-project.properties(md5:91bd75c4e897b61f5875d86ba4f727eb)
|    |    |    |    |    |    +-res
|    |    |    |    |    |    |    +-drawable
|    |    |    |    |    |    |    |    +-msdk_facebook_progressbar_bg.xml(md5:a8ea472700edf6d5244f7c9c586ebc18)
|    |    |    |    |    |    |    +-layout
|    |    |    |    |    |    |    |    +-msdk_facerbook_progressbar_layout.xml(md5:60147fb194387f3d606093eee7c8ffd4)
|    |    |    |    |    |    |    +-values
|    |    |    |    |    |    |    |    +-values.xml(md5:26b914d03695140a4a74ea222626e186)
|    |    |    |    +-iOS
|    |    |    |    |    +-MSDKFacebook
|    |    |    |    |    |    +-MSDKFacebook.embeddedframework.zip(md5:c44d232f62bf176540503a06a8051a21)
|    |    |    |    |    +-Third
|    |    |    |    |    |    +-MSDKFacebook
|    |    |    |    |    |    |    +-FBAEMKit.embeddedframework.zip(md5:5ce6d85c57427d2871de37be490ce186)
|    |    |    |    |    |    |    +-FBSDKCoreKit.embeddedframework.zip(md5:d4f44ff2875ba4e25b2eced0ee5ad059)
|    |    |    |    |    |    |    +-FBSDKCoreKit_Basics.embeddedframework.zip(md5:2d231a4c6906e10cb94d404c0f95611a)
|    |    |    |    |    |    |    +-FBSDKGamingServicesKit.embeddedframework.zip(md5:dff509a4d123dea6b7e856a3a3b9b53c)
|    |    |    |    |    |    |    +-FBSDKLoginKit.embeddedframework.zip(md5:de4813961d6bbb819cd6569e5847b3b6)
|    |    |    |    |    |    |    +-FBSDKShareKit.embeddedframework.zip(md5:a65bc1ee7ff513190e331b0f1f6a8ebc)
|    |    |    |    |    |    |    +-MSDKFacebook-For-Bridging-Header.h(md5:55b58464e072a50d044333f74a8f3bfd)
|    |    |    |    |    |    |    +-MSDKFacebook.swift(md5:204d71126cf998b61c82ee6022599372)
+-MSDKGameCenter
|    +-MSDKGameCenter.uplugin(md5:5ce05dfad122d0286fdb43249430a996)
|    +-Resources
|    |    +-Icon128.png(md5:7b15f15f14b3399e42fed1a64d9f0cb4)
|    +-Source
|    |    +-MSDKGameCenter
|    |    |    +-MSDKGameCenter.Build.cs(md5:5eb8258973a0c301341ac737935424df)
|    |    |    +-MSDKGameCenter_UPL.xml(md5:4a35de0d657fb71dfb4f2cdaae4524c1)
|    |    |    +-Private
|    |    |    |    +-MSDKGameCenter.cpp(md5:483fca73ac9b9e390f17315d37bddc3d)
|    |    |    +-Public
|    |    |    |    +-MSDKGameCenter.h(md5:0f37e7edb7c830218762ee8b51d5b586)
|    |    |    +-lib
|    |    |    |    +-iOS
|    |    |    |    |    +-MSDKGameCenter
|    |    |    |    |    |    +-MSDKGameCenter.embeddedframework.zip(md5:60d7c4a61415507d6c16be0e780bf7fe)
+-MSDKGoogle
|    +-MSDKGoogle.uplugin(md5:d84d81ce2a0a69f47d90e69f20be8d8b)
|    +-Resources
|    |    +-Icon128.png(md5:7b15f15f14b3399e42fed1a64d9f0cb4)
|    +-Source
|    |    +-MSDKGoogle
|    |    |    +-MSDKGoogle.Build.cs(md5:eb8ee3b8ad1c7734e6d588ab79ea95d8)
|    |    |    +-MSDKGoogle_UPL.xml(md5:81202c6fd21d41a7e863917c80a2a2c6)
|    |    |    +-Private
|    |    |    |    +-MSDKGoogle.cpp(md5:2a55fcbe8cce916849e85cf5cb854a56)
|    |    |    +-Public
|    |    |    |    +-MSDKGoogle.h(md5:9bdf16288ea2d6881d2d1e3b471c26e3)
|    |    |    +-lib
|    |    |    |    +-Android
|    |    |    |    |    +-msdk-google
|    |    |    |    |    |    +-AndroidManifest.xml(md5:7d0fe3d75686b95a0afe525ecc52dc40)
|    |    |    |    |    |    +-R.txt(md5:10687df72f564ba4792c75edc22da41f)
|    |    |    |    |    |    +-additions.gradle(md5:5762bf7a18aed943ee0a5d02d2b8e944)
|    |    |    |    |    |    +-libs
|    |    |    |    |    |    |    +-msdk-google.jar(md5:74f62ca5001523a040e6580a6dafe970)
|    |    |    |    |    |    +-proguard-project.txt(md5:adf6f233b18261975991f1825834afc7)
|    |    |    |    |    |    +-project.properties(md5:97bc7a3398ffc98b7d51c02433a2ca4a)
|    |    |    |    |    |    +-res
|    |    |    |    |    |    |    +-values
|    |    |    |    |    |    |    |    +-values.xml(md5:a46e87b5bce1e831f5eeef5efa797881)
|    |    |    |    +-iOS
|    |    |    |    |    +-MSDKGoogle
|    |    |    |    |    |    +-MSDKGoogle.embeddedframework.zip(md5:8bc58b6d75a7d1f6168cf46aa6c5d50a)
|    |    |    |    |    +-Third
|    |    |    |    |    |    +-MSDKGoogle
|    |    |    |    |    |    |    +-AppAuth.embeddedframework.zip(md5:bd0e1d3f6110705a09e33a1d4d5f2747)
|    |    |    |    |    |    |    +-GTMAppAuth.embeddedframework.zip(md5:dedece10896ba28cb2028eac8e63de9d)
|    |    |    |    |    |    |    +-GTMSessionFetcher.embeddedframework.zip(md5:95ea3fbd30c63ea5ec95cf1641d461be)
|    |    |    |    |    |    |    +-GoogleSignIn.embeddedframework.zip(md5:adb198ef0d53832b49b56bac5ffe93f5)
+-MSDKLBS
|    +-MSDKLBS.uplugin(md5:5e029d728c4e37cf16d384004bf72272)
|    +-Resources
|    |    +-Icon128.png(md5:7b15f15f14b3399e42fed1a64d9f0cb4)
|    +-Source
|    |    +-MSDKLBS
|    |    |    +-MSDKLBS.Build.cs(md5:175d533eb9f8b23ee86bc5100f78f00b)
|    |    |    +-MSDKLBS_UPL.xml(md5:10667800b24b1faa32d30dc27e3bf5e0)
|    |    |    +-Private
|    |    |    |    +-MSDKLBS.cpp(md5:64340e95cb61b5ee38ede03fd603bdad)
|    |    |    +-Public
|    |    |    |    +-MSDKLBS.h(md5:24b185bd8aedbae2562453d44f480b2b)
|    |    |    +-lib
|    |    |    |    +-Android
|    |    |    |    |    +-msdk-lbs
|    |    |    |    |    |    +-AndroidManifest.xml(md5:215cdbcaca94521a94cc8d79263238eb)
|    |    |    |    |    |    +-R.txt(md5:6fde0547eb5e46dca7fe188643f5514a)
|    |    |    |    |    |    +-additions.gradle(md5:4a149f0a2f5fbf8eb12a6684979b0bd5)
|    |    |    |    |    |    +-libs
|    |    |    |    |    |    |    +-msdk-lbs.jar(md5:6110c4088c6904b05205de5f3ac794a0)
|    |    |    |    |    |    +-proguard-project.txt(md5:adf6f233b18261975991f1825834afc7)
|    |    |    |    |    |    +-project.properties(md5:06eb8ac23aa83301d2079053cb676fdd)
|    |    |    |    |    |    +-res
|    |    |    |    |    |    |    +-values
|    |    |    |    |    |    |    |    +-values.xml(md5:f5f98e09594ac6f2c8f0080727d7f94e)
|    |    |    |    +-iOS
|    |    |    |    |    +-MSDKLBS
|    |    |    |    |    |    +-MSDKLBS.embeddedframework.zip(md5:ad92ff4259c90d428f87faa4ebf00bee)
+-MSDKSystem
|    +-MSDKSystem.uplugin(md5:cfbef7b5876d09dafb0bdc531e773f82)
|    +-Resources
|    |    +-Icon128.png(md5:7b15f15f14b3399e42fed1a64d9f0cb4)
|    +-Source
|    |    +-MSDKSystem
|    |    |    +-MSDKSystem.Build.cs(md5:4153257c4e60df09c114f3e57f87170a)
|    |    |    +-MSDKSystem_UPL.xml(md5:e779d8d7cfd0864d3c6877468dca22a1)
|    |    |    +-Private
|    |    |    |    +-MSDKSystem.cpp(md5:e981f94e735a662bbac24669b537e3f6)
|    |    |    +-Public
|    |    |    |    +-MSDKSystem.h(md5:02522696711e39f28996a28a66aee0a7)
|    |    |    +-lib
|    |    |    |    +-Android
|    |    |    |    |    +-msdk-system
|    |    |    |    |    |    +-AndroidManifest.xml(md5:ced9639200c2182e1b7b4b3f892a4855)
|    |    |    |    |    |    +-additions.gradle(md5:4a149f0a2f5fbf8eb12a6684979b0bd5)
|    |    |    |    |    |    +-libs
|    |    |    |    |    |    |    +-msdk-system.jar(md5:0ba8f26d4695f91f8cb6c9149c56a4eb)
|    |    |    |    |    |    +-project.properties(md5:06eb8ac23aa83301d2079053cb676fdd)
|    |    |    |    |    |    +-res
|    |    |    |    |    |    |    +-values
|    |    |    |    |    |    |    |    +-values.xml(md5:5aff009b6f8cd6dc92cdd3144ec20d90)
|    |    |    |    |    |    |    +-xml
|    |    |    |    |    |    |    |    +-system_share_storage.xml(md5:6fce2ccd1650cfd5d2beb1ca346e6e7c)
|    |    |    |    +-iOS
|    |    |    |    |    +-MSDKSystem
|    |    |    |    |    |    +-MSDKSystem.embeddedframework.zip(md5:74f00ce8488a9879a771fe16613340e6)
+-MSDKTDM
|    +-MSDKTDM.uplugin(md5:098ad5e75ea13f2eb43f8c4aa15521c1)
|    +-Resources
|    |    +-Icon128.png(md5:7b15f15f14b3399e42fed1a64d9f0cb4)
|    +-Source
|    |    +-MSDKTDM
|    |    |    +-MSDKTDM.Build.cs(md5:24e25903f6bc0a6db823631dd39822d6)
|    |    |    +-MSDKTDM_UPL.xml(md5:90a6c5c508ef8935cc56e7a69dcacd87)
|    |    |    +-Private
|    |    |    |    +-MSDKTDM.cpp(md5:0c51db41d596ea977b5db7f816e571a9)
|    |    |    +-Public
|    |    |    |    +-MSDKTDM.h(md5:155fa7c0369d4a2a8dcff1d614b056a2)
|    |    |    +-lib
|    |    |    |    +-Android
|    |    |    |    |    +-msdk-tdm
|    |    |    |    |    |    +-AndroidManifest.xml(md5:cbbeb2e4ecb90fcc9d63f926256670cc)
|    |    |    |    |    |    +-R.txt(md5:bea8c979eb4f3a099902f437c5982c20)
|    |    |    |    |    |    +-additions.gradle(md5:ffa49636af5c5b43c5fcd3c9ad27a9a8)
|    |    |    |    |    |    +-libs
|    |    |    |    |    |    |    +-msdk-tdm.jar(md5:817305d1334c2dd6698c9975950f5836)
|    |    |    |    |    |    +-proguard-project.txt(md5:adf6f233b18261975991f1825834afc7)
|    |    |    |    |    |    +-project.properties(md5:6047dbe71bdb53ab5cb4047da7608ef4)
|    |    |    |    |    |    +-res
|    |    |    |    |    |    |    +-values
|    |    |    |    |    |    |    |    +-values.xml(md5:1202b92fe1bcee334495c1634d251957)
|    |    |    |    +-iOS
|    |    |    |    |    +-MSDKTDM
|    |    |    |    |    |    +-MSDKTDM.embeddedframework.zip(md5:bd7639d4ebc3cf52b4476e300e6aa440)
+-MSDKTwitter
|    +-MSDKTwitter.uplugin(md5:4715facaeab9ede12d76320438f905cc)
|    +-Resources
|    |    +-Icon128.png(md5:7b15f15f14b3399e42fed1a64d9f0cb4)
|    +-Source
|    |    +-MSDKTwitter
|    |    |    +-MSDKTwitter.Build.cs(md5:d13a7ecfe9bf9f9db61ac7876990295d)
|    |    |    +-MSDKTwitter_UPL.xml(md5:505dde756f39b294d39d9959d361b437)
|    |    |    +-Private
|    |    |    |    +-MSDKTwitter.cpp(md5:5c5bd8a2eb5ccca0c9e02503a7f75a11)
|    |    |    +-Public
|    |    |    |    +-MSDKTwitter.h(md5:57e0bb502bff62b513b5bf9aaf077f3c)
|    |    |    +-lib
|    |    |    |    +-Android
|    |    |    |    |    +-msdk-twitter
|    |    |    |    |    |    +-AndroidManifest.xml(md5:f746e1101dc4f20562fa0dbb7712f583)
|    |    |    |    |    |    +-R.txt(md5:6a8e22f30df7641ecd9c26e2acae82a0)
|    |    |    |    |    |    +-additions.gradle(md5:8e6cc1f34a9a67c24b976a492b22bab2)
|    |    |    |    |    |    +-libs
|    |    |    |    |    |    |    +-msdk-twitter.jar(md5:20c3914d2ee378a0a7651bb1c67e7c66)
|    |    |    |    |    |    |    +-twitterwrapper-1.3.1.jar(md5:572c8dfca4b2b173d57529c7a6ed1789)
|    |    |    |    |    |    +-proguard-project.txt(md5:50453ef570daf9c5382beda8b260ae6d)
|    |    |    |    |    |    +-project.properties(md5:fa2d7ec4fd5d0bf1d540ca9c69a0bf8c)
|    |    |    |    |    |    +-res
|    |    |    |    |    |    |    +-drawable
|    |    |    |    |    |    |    |    +-com_itop_twitterweb_bg_back.xml(md5:bfa72a9711c269cb30631b90fcca5d7a)
|    |    |    |    |    |    |    |    +-com_itop_twitterweb_bg_close.xml(md5:b9647742c1097dc5686fb137af792699)
|    |    |    |    |    |    |    |    +-com_itop_twitterweb_icon_back_normal.png(md5:bde8a2a18429c3a64eebc65f56aa6641)
|    |    |    |    |    |    |    |    +-com_itop_twitterweb_icon_back_pressed.png(md5:a5fcde720c76219688cf81feed2d15f1)
|    |    |    |    |    |    |    |    +-com_itop_twitterweb_icon_close_normal.png(md5:17081f88651e66ca1b77557ac0c6f350)
|    |    |    |    |    |    |    |    +-com_itop_twitterweb_icon_close_pressed.png(md5:00f8d410c021346be8cb64ca718e9dde)
|    |    |    |    |    |    |    +-layout
|    |    |    |    |    |    |    |    +-activity_twitter_web.xml(md5:e3dcee3e33ac34708aa511c5936760b7)
|    |    |    |    |    |    |    +-values
|    |    |    |    |    |    |    |    +-values.xml(md5:5f2e8617714b7f9835956e88bf4194e8)
|    |    |    |    |    |    |    +-xml
|    |    |    |    |    |    |    |    +-twitter_share_storage.xml(md5:2d31360da942ec2de171747bac1b92ad)
|    |    |    |    +-iOS
|    |    |    |    |    +-MSDKTwitter
|    |    |    |    |    |    +-MSDKTwitter.embeddedframework.zip(md5:bfbd0a45882b593b5ce2438d5c2b7e2d)
|    |    |    |    |    +-Third
|    |    |    |    |    |    +-MSDKTwitter
|    |    |    |    |    |    |    +-TwitterWrapperKit.embeddedframework.zip(md5:de8279205610291bfcd91947088dddfe)
+-TDM
|    +-Binaries
|    |    +-Win64
|    |    |    +-TDataMaster.dll(md5:de85ecbf5a5228a2e34a213361c83ebd)
|    |    |    +-cacert.pem(md5:882db4f54c25b5157cef6c0d182e729e)
|    |    |    +-libcrypto-1_1.dll(md5:d38634f0b5d11fed982dd10e9ab06123)
|    |    |    +-libcurl.dll(md5:1efef1a288cbc48fe846d120a80c42f1)
|    |    |    +-libssh2.dll(md5:e9f2c86ae1d2233c0cfd820947a49719)
|    |    |    +-libssl-1_1.dll(md5:a0a250650713d0ba11cc8e6a62da33d5)
|    |    |    +-pthreadGC2.dll(md5:a8e566e3a09e9451c6d2c531758a5758)
|    |    |    +-pthreadVC2.dll(md5:4a502706d149c2f5854131a7758a90e2)
|    |    |    +-zlibwapi.dll(md5:e1dd4cdeef1651f21a80227c2db9623f)
|    +-Resources
|    |    +-Icon128.png(md5:7b15f15f14b3399e42fed1a64d9f0cb4)
|    +-Source
|    |    +-TDM
|    |    |    +-Private
|    |    |    |    +-TDM.cpp(md5:3dfc430b5f95a4059a8662cd265f71a7)
|    |    |    +-Public
|    |    |    |    +-ITDataMaster.h(md5:cf88ec13694f6a9223c77792c1e85425)
|    |    |    |    +-ITDataMasterV2.h(md5:0b83ae9dbaa354bacb5a6fc5b2606784)
|    |    |    |    +-ITDataMasterV3.h(md5:96b8bf2f90ec59800bc3dff8cc061412)
|    |    |    |    +-ITDataMasterV4.h(md5:489557140cc00870f0ebf6ac8a0f94df)
|    |    |    |    +-ITDataMaster_GCloud.h(md5:b7752f8cde6a39c44caf67ee7f17227c)
|    |    |    |    +-TDM.h(md5:8aacbf37a569b12b4f943af196f6a293)
|    |    |    |    +-TDataMasterConfig.h(md5:f7e78a556dc0883888c04ade220697f0)
|    |    |    |    +-TDataMasterDefines.h(md5:eb5ac4a0ae5c2aadb7fc3de4487a7e00)
|    |    |    |    +-TDataMasterVersion.h(md5:e102c9a58df681c700ef7019de985ff7)
|    |    |    +-TDM.Build.cs(md5:13bb3db9bd879de320e74a3af126245a)
|    |    |    +-TDM_APL.xml(md5:50bdb3d6473add832b4f9bcbcb440747)
|    |    |    +-lib
|    |    |    |    +-Android
|    |    |    |    |    +-TDM
|    |    |    |    |    |    +-AndroidManifest.xml(md5:f40edf48b6102dbc37defbea4bf7e674)
|    |    |    |    |    |    +-additions.gradle(md5:b49cd1d70be26ae3c5541d5614f8713e)
|    |    |    |    |    |    +-libs
|    |    |    |    |    |    |    +-TDataMaster.jar(md5:4c3503f4881ffa74c2c4e31f22bfe70d)
|    |    |    |    |    |    |    +-arm64-v8a
|    |    |    |    |    |    |    |    +-libTDataMaster.so(md5:2cfef58f7f8aeb9e94cf47111b8b13b7)
|    |    |    |    |    |    |    +-armeabi-v7a
|    |    |    |    |    |    |    |    +-libTDataMaster.so(md5:beb12a513e6d658be693a460595dc085)
|    |    |    |    |    |    |    +-x86
|    |    |    |    |    |    |    |    +-libTDataMaster.so(md5:efca273a315b23ec44d396c4bf79ffb6)
|    |    |    |    |    |    |    +-x86_64
|    |    |    |    |    |    |    |    +-libTDataMaster.so(md5:63909a9fb884e0f8a17c25cda3c39cb9)
|    |    |    |    |    |    +-proguard-project.txt(md5:407fae47e251594efd134113f4e0cb3e)
|    |    |    |    |    |    +-project.properties(md5:269b71902eb1ff0f8c098a12e9246a4d)
|    |    |    |    +-MAC
|    |    |    |    |    +-libTDataMasterDylib.dylib(md5:32bf4e9f9bf78d16998f92e32de86d0f)
|    |    |    |    +-Win64
|    |    |    |    |    +-TDataMaster.lib(md5:6dcdb0ef20ff8f2c553379e568206b25)
|    |    |    |    |    +-atls.lib(md5:8290e7ec9ad8428ca79301d57b573a05)
|    |    |    |    +-iOS
|    |    |    |    |    +-TDMASA.embeddedframework.zip(md5:1f370b2b2f49b9674d5cd498f918cf3a)
|    |    |    |    |    +-TDMIDFA.embeddedframework.zip(md5:15ae3bece86bdf35fa0f976e3aad820a)
|    |    |    |    |    +-TDataMaster.embeddedframework.zip(md5:d1478dc2d0664021f44e3fb3cc6af9b1)
|    +-TDM.uplugin(md5:cb930a9f9d1da19619145facb9a82388)
+-TssSDK
|    +-Resources
|    |    +-Icon128.png(md5:7b15f15f14b3399e42fed1a64d9f0cb4)
|    +-Source
|    |    +-TssSDK
|    |    |    +-Private
|    |    |    |    +-TssSDK.cpp(md5:04e13e2b98f2d2def044be344b7199ee)
|    |    |    +-Public
|    |    |    |    +-OneSDKTss.h(md5:e343f643cb9212e79bad5dcf50367daf)
|    |    |    |    +-TssSDK.h(md5:71c8d1e90cf22fc51014d0033fc334bd)
|    |    |    +-TssSDK.Build.cs(md5:37a7ae00bbf19b093777cc9d5e2baaea)
|    |    |    +-TssSDK_APL.xml(md5:6327ba2b2a933206ec21513685978992)
|    |    +-TssSDKLib
|    |    |    +-Android
|    |    |    |    +-AndroidManifest.xml(md5:9dc208000e86cdc065897c357e5e6241)
|    |    |    |    +-libs
|    |    |    |    |    +-ano.jar(md5:2e86fc0166f5e815b3b7d6b441f61deb)
|    |    |    |    |    +-arm64-v8a
|    |    |    |    |    |    +-libanogs.so(md5:034e319aaa77b811f0dac791d8ba2ee2)
|    |    |    |    |    +-armeabi-v7a
|    |    |    |    |    |    +-libanogs.so(md5:f60b57929ac4d4a5056d5d1336cb6357)
|    |    |    |    |    +-x86
|    |    |    |    |    |    +-libanogs.so(md5:8cf42fcd9fde5584be4f889fe375ce11)
|    |    |    |    |    +-x86_64
|    |    |    |    |    |    +-libanogs.so(md5:49a95b046214e4d93424ba9db5e4336a)
|    |    |    |    +-proguard-project.txt(md5:be241343975d2f71bade64b388d0152c)
|    |    |    |    +-project.properties(md5:bc20596d957d714759ee019b59304d1c)
|    |    |    +-iOS
|    |    |    |    +-anogs.embeddedframework.zip(md5:c0b0d47dbc4e0ed50c7c70145c7e2cda)
|    +-TssSDK.uplugin(md5:5453f3580664f7070a07e54833ef451b)
+-readme.txt(md5:a37685bc4762b08b2301f0ba2c960dc8)
