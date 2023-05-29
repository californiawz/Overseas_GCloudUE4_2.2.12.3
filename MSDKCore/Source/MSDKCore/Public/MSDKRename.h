//
//  MSDKCore.h
//  MSDKCore
//
//  Created by brightwan on 2018/3/20.
//  Copyright © company. All rights reserved.
//


#ifndef MSDK_Rename_H
#define MSDK_Rename_H


#include "MSDKMacros.h"
#include "MSDK.h"
#include "MSDKConfig.h"
#include "MSDKFriend.h"
#include "MSDKGroup.h"
#include "MSDKGame.h"
#include "MSDKLogin.h"
#include "MSDKNotice.h"
#include "MSDKPush.h"
#include "MSDKReport.h"
#include "MSDKTools.h"
#include "MSDKWebView.h"
#include "MSDKCrash.h"
#include "MSDKJsonManager.h"
#include "MSDKUtils.h"

#define MSDKCore_Rename_Version_String "2.2.008.3277"
#define MSDKCore_Rename_Version_Int 20208


#ifdef __cplusplus
#define NS_ITOP_BEGIN namespace GCloud \
{\
namespace iTOP \
{
#define NS_ITOP_END }}
#else
#define NS_ITOP_BEGIN
#define NS_ITOP_END
#endif


//-------------------  兼容老业务使用旧的命名空间的问题
NS_ITOP_BEGIN

//class ITOP : public GCloud::MSDK::MSDK{};
//class ITOPConfig : public GCloud::MSDK::MSDKConfig{};
//class ITOPConfigRet : public GCloud::MSDK::MSDKConfigRet{};
//class ITOPFriendReqInfo : public GCloud::MSDK::MSDKFriendReqInfo{};
//class ITOPFriendRet : public GCloud::MSDK::MSDKFriendRet{};
//class ITOPPersonInfo : public GCloud::MSDK::MSDKPersonInfo{};
//class ITOPFriend : public GCloud::MSDK::MSDKFriend{};
//class ITOPGame : public GCloud::MSDK::MSDKGame{};
//class ITOPGroupInfo : public GCloud::MSDK::MSDKGroupInfo{};
//class ITOPGroupMessage : public GCloud::MSDK::MSDKGroupMessage{};
//class ITOPGroupRet : public GCloud::MSDK::MSDKGroupRet{};
//class ITOPGroup : public GCloud::MSDK::MSDKGroup{};
//class ITOPLoginRet : public GCloud::MSDK::MSDKLoginRet{};
//class ITOPLogin : public GCloud::MSDK::MSDKLogin{};
//class ITOPNoticePictureInfo : public GCloud::MSDK::MSDKNoticePictureInfo{};
//class ITOPNoticeTextInfo : public GCloud::MSDK::MSDKNoticeTextInfo{};
//class ITOPNoticeInfo : public GCloud::MSDK::MSDKNoticeInfo{};
//class ITOPNoticeRet : public GCloud::MSDK::MSDKNoticeRet{};
//class ITOPNotice : public GCloud::MSDK::MSDKNotice{};
//class ITOPLocalNotification : public GCloud::MSDK::MSDKLocalNotification{};
//class ITOPPushRet : public GCloud::MSDK::MSDKPushRet{};
//class ITOPPush : public GCloud::MSDK::MSDKPush{};
//class ITOPReport : public GCloud::MSDK::MSDKReport{};
//class ITOPToolsFreeFlowInfo : public GCloud::MSDK::MSDKToolsFreeFlowInfo{};
//class ITOPToolsFreeFlowRet : public GCloud::MSDK::MSDKToolsFreeFlowRet{};
//class ITOPTools : public GCloud::MSDK::MSDKTools{};
//class ITOPWebViewRet : public GCloud::MSDK::MSDKWebViewRet{};
//class ITOPWebView : public GCloud::MSDK::MSDKWebView{};
//class ITOPCrash : public GCloud::MSDK::MSDKCrash{};
//class ITOPCrashRet : public GCloud::MSDK::MSDKCrashRet{};
//class ITOPBaseRet : public GCloud::MSDK::MSDKBaseRet {};
//class ITOPUtils :public GCloud::MSDK::MSDKUtils {};
//class ITOPJsonManager :public GCloud::MSDK::MSDKJsonManager {};
//class ITOPError :public GCloud::MSDK::MSDKError {};

typedef  GCloud::MSDK::MSDK ITOP;
typedef  GCloud::MSDK::MSDKConfig ITOPConfig;
typedef  GCloud::MSDK::MSDKConfigRet ITOPConfigRet;
typedef  GCloud::MSDK::MSDKFriendReqInfo ITOPFriendReqInfo;
typedef  GCloud::MSDK::MSDKFriendRet ITOPFriendRet;
typedef  GCloud::MSDK::MSDKPersonInfo ITOPPersonInfo;
typedef  GCloud::MSDK::MSDKFriend ITOPFriend;
typedef  GCloud::MSDK::MSDKGame ITOPGame;
typedef  GCloud::MSDK::MSDKGroupInfo ITOPGroupInfo;
typedef  GCloud::MSDK::MSDKGroupMessage ITOPGroupMessage;
typedef  GCloud::MSDK::MSDKGroupRet ITOPGroupRet;
typedef  GCloud::MSDK::MSDKGroup ITOPGroup;
typedef  GCloud::MSDK::MSDKLoginRet ITOPLoginRet;
typedef  GCloud::MSDK::MSDKLogin ITOPLogin;
typedef  GCloud::MSDK::MSDKNoticePictureInfo ITOPNoticePictureInfo;
typedef  GCloud::MSDK::MSDKNoticeTextInfo ITOPNoticeTextInfo;
typedef  GCloud::MSDK::MSDKNoticeInfo ITOPNoticeInfo;
typedef  GCloud::MSDK::MSDKNoticeRet ITOPNoticeRet;
typedef  GCloud::MSDK::MSDKNotice ITOPNotice;
typedef  GCloud::MSDK::MSDKLocalNotification ITOPLocalNotification;
typedef  GCloud::MSDK::MSDKPushRet ITOPPushRet;
typedef  GCloud::MSDK::MSDKPush ITOPPush;
typedef  GCloud::MSDK::MSDKReport ITOPReport;
typedef  GCloud::MSDK::MSDKToolsFreeFlowInfo ITOPToolsFreeFlowInfo;
typedef  GCloud::MSDK::MSDKToolsFreeFlowRet ITOPToolsFreeFlowRet;
typedef  GCloud::MSDK::MSDKToolsRet ITOPToolsRet;
typedef  GCloud::MSDK::MSDKToolsObserver ITOPToolsObserver;

typedef  GCloud::MSDK::MSDKTools ITOPTools;
typedef  GCloud::MSDK::MSDKWebViewRet ITOPWebViewRet;
typedef  GCloud::MSDK::MSDKWebView ITOPWebView;
typedef  GCloud::MSDK::MSDKCrash ITOPCrash;
typedef  GCloud::MSDK::MSDKCrashRet ITOPCrashRet;
typedef  GCloud::MSDK::MSDKBaseRet ITOPBaseRet;
typedef  GCloud::MSDK::MSDKUtils ITOPUtils;
typedef  GCloud::MSDK::MSDKJsonManager ITOPJsonManager;
typedef  GCloud::MSDK::MSDKError ITOPError;

typedef  GCloud::MSDK::MSDKLoginObserver ITOPLoginObserver;
typedef  GCloud::MSDK::MSDKCrashObserver ITOPCrashObserver;
typedef  GCloud::MSDK::MSDKFriendObserver ITOPFriendObserver;
typedef  GCloud::MSDK::MSDKGameObserver ITOPGameObserver;
typedef  GCloud::MSDK::MSDKNoticeObserver ITOPNoticeObserver;
typedef  GCloud::MSDK::MSDKGroupObserver ITOPGroupObserver;
typedef  GCloud::MSDK::MSDKPushObserver ITOPPushObserver;
typedef  GCloud::MSDK::MSDKWebViewObserver ITOPWebViewObserver;

//class ITOPLoginObserver : public GCloud::MSDK::MSDKLoginObserver {
//public:
//    virtual ~ITOPLoginObserver(){};
//    virtual void OnLoginRetNotify(const ITOPLoginRet &loginRet) {};
//    virtual void OnBaseRetNotify(const ITOPBaseRet &baseRet) {};
//    virtual void OnLoginRetNotify(const GCloud::MSDK::MSDKLoginRet &loginRet) {
//        ITOPLoginRet tempRet = loginRet;
//        OnLoginRetNotify(tempRet);
//    };
//    virtual void OnBaseRetNotify(const GCloud::MSDK::MSDKBaseRet &baseRet) {
//        OnBaseRetNotify((ITOPBaseRet)baseRet);
//    };
//
//private:
//};
//class ITOPCrashObserver : public GCloud::MSDK::MSDKCrashObserver {
//public:
//    //新增一个虚析构函数 不然 UE4 报错
//    virtual ~ITOPCrashObserver() { };
//    virtual long OnCrashExtraDataNotify(ITOPCrashRet &crashRet) {
//        return MSDKCrashObserver::OnCrashExtraDataNotify(crashRet);
//    };
//    virtual const char* OnCrashExtraMessageNotify(){
//        return MSDKCrashObserver::OnCrashExtraMessageNotify();
//    };
//private:
//};
//class ITOPFriendObserver : public GCloud::MSDK::MSDKFriendObserver {
//public:
//    virtual ~ITOPFriendObserver() {};
//    virtual void OnDeliverMessageNotify(const ITOPBaseRet &baseRet) {};
//    virtual void OnDeliverMessageNotify(const  GCloud::MSDK::MSDKBaseRet &baseRet) {
//        OnDeliverMessageNotify((ITOPBaseRet)baseRet);
//    };
//
//    virtual void OnQueryFriendNotify(const ITOPFriendRet &friendRet) {};
//    virtual void OnQueryFriendNotify(const GCloud::MSDK::MSDKFriendRet &friendRet) {
//        OnDeliverMessageNotify((ITOPFriendRet)friendRet);
//    };
//
//};
//class ITOPGameObserver : public GCloud::MSDK::MSDKGameObserver {
//public:
//    virtual ~ITOPGameObserver() {MSDKGameObserver::~MSDKGameObserver();};
//    virtual void OnBaseRetNotify(const ITOPBaseRet &baseRet) {};
//
//    virtual void OnBaseRetNotify(const GCloud::MSDK::MSDKBaseRet &baseRet) {
//        OnBaseRetNotify((ITOPBaseRet)baseRet);
//    };
//};
//class ITOPGroupObserver : public GCloud::MSDK::MSDKGroupObserver {
//public:
//    virtual ~ITOPGroupObserver() {};
//    virtual void OnLoadGroupData(const ITOPGroupRet &groupRet) {};
//
//    virtual void OnLoadGroupData(const GCloud::MSDK::MSDKGroupRet &groupRet) {
//        OnLoadGroupData((ITOPGroupRet)groupRet);
//    };
//};
//class ITOPNoticeObserver : public GCloud::MSDK::MSDKNoticeObserver {
//public:
//    virtual ~ITOPNoticeObserver() {};
//    virtual void OnLoadNoticeData(const ITOPNoticeRet &noticeRet) {};
//
//    virtual void OnLoadNoticeData(const GCloud::MSDK::MSDKNoticeRet &noticeRet) {
//        OnLoadNoticeData((ITOPNoticeRet)noticeRet);
//    };
//
//};
//class ITOPPushObserver : public GCloud::MSDK::MSDKPushObserver {
//public:
//    virtual ~ITOPPushObserver() {};
//    virtual void OnPushOptNotify(const ITOPBaseRet &baseRet) {};
//    virtual void OnReceiveNotification(const ITOPPushRet &pushRet) {};
//
//    virtual void OnPushOptNotify(const GCloud::MSDK::MSDKBaseRet &baseRet) {
//        OnPushOptNotify((ITOPBaseRet)baseRet);
//    };
//    virtual void OnReceiveNotification(const GCloud::MSDK::MSDKPushRet &pushRet) {
//        OnReceiveNotification((ITOPPushRet)pushRet);
//    };
//};
//class ITOPWebViewObserver : public GCloud::MSDK::MSDKWebViewObserver {
//public:
//    virtual ~ITOPWebViewObserver() {};
//    virtual void OnWebViewOptNotify(const ITOPWebViewRet &webViewRet) {};
//    virtual void OnWebViewOptNotify(const GCloud::MSDK::MSDKWebViewRet &webViewRet) {
//        OnWebViewOptNotify((ITOPWebViewRet)webViewRet);
//    };
//};

typedef enum ITOPFriendReqType
{
    kITOPFriendReqTypeText = 10000,           //文字分享
    kITOPFriendReqTypeLink,                   //链接分享
    kITOPFriendReqTypeIMG,                    //图片分享
    kITOPFriendReqTypeInvite,                 //应用邀请
    kITOPFriendReqTypeMusic,                  //音乐分享
    kITOPFriendReqTypeVideo,                  //视频分享
    kITOPFriendReqTypeMiniApp,                //小程序分享
    kITOPFriendReqTypePullUpMiniApp,          //小程序拉起
    kITOPFriendReqTypeArk,                    //ARK分享
    
    kITOPFriendReqTypeTextSilent = 20000,     //文字分享（静默）
    kITOPFriendReqTypeLinkSilent,             //链接分享 (静默)
    kITOPFriendReqTypeIMGSilent,              //图片分享 （静默）
    kITOPFriendReqTypeInviteSilent,           //应用邀请 (静默）
    kITOPFriendReqTypeMusicSilent,            //音乐分享 (静默)
    kITOPFriendReqTypeVideoSilent,            //视频分享 (静默)
    kITOPFriendReqTypeMiniAppSilent,          //小程序分享 (静默)
} ITOPFriendReqType;

typedef enum MethodName
{
    kMethodNameUndefine                 = 000,

    kMethodNameAutoLogin                = 111,
    kMethodNameLogin                    = 112,
    kMethodNameBind                     = 113,
    kMethodNameGetLoginRet              = 114,
    kMethodNameSwitchUser               = 115,
    kMethodNameQueryUserInfo            = 116,
    kMethodNameLogout                   = 117,
    kMethodNameLoginWithConfirmCode     = 118,
    kMethodNameWakeUp                   = 119,
    KMethodNameScheme                   = 120,
    kMethodNameResetGuest               = 121,

    kMethodNameShareToWall              = 211,
    kMethodNameSendMessageToFriend      = 212,
    kMethodNameQueryFriend              = 213,
    kMethodNameAddFriend                = 214,

    kMethodNameCreateGroup              = 311,
    kMethodNameBindGroup                = 312,
    kMethodNameGetGroupList             = 313,
    kMethodNameGetGroupState            = 314,
    kMethodNameJoinGroup                = 315,
    kMethodNameUnbindGroup              = 316,
    kMethodNameRemindToBindGroup        = 317,
    kMethodNameSendMessageToGroup       = 318,
    kMethodNameGetGroupRelation         = 319,

    kMethodNameCloseWebViewURL          = 411,
    kMethodNameGetEncodeURL             = 412,
    kMethodNameWebViewJsCall            = 413,
    kMethodNameWebViewJsShare           = 414,
    kMethodNameWebViewJsSendMessage     = 415,
    kMethodNameWebViewEmbedProgress     = 416,


    kMethodNameRegisterPush             = 511,
    kMethodNameUnregisterPush           = 512,
    kMethodNameSetTagForPush            = 513,
    kMethodNameDeleteTagForPush         = 514,
    kMethodNameAddLocalNotify           = 515,
    kMethodNameClearLocalNotify         = 516,
    kMethodNameNotifyCallback           = 517,
    kMethodNameNotifyShow               = 518,
    kMethodNameNotifyClick              = 519,
    kMethodNameSetAccountPush           = 520,
    kMethodNameDeleteAccountPush        = 521,




    kMethodNameLoadNoticeData           = 611,

    kMethodNameSetupGame                = 711,
    kMethodNameShowGameLeaderBoard      = 712,
    kMethodNameSetScore                 = 713,
    kMethodNameShowGameAchievement      = 714,
    kMethodNameUnlockGameAchieve        = 715,

    KMethodNameToolsOpenDeepLink        = 911,
    KMethodNameToolsConvertShortUrl     = 912,
    KMethodNameToolsGetFreeFlowInfo     = 913,

    kMethodNameCrashExtraData           = 1011,
    kMethodNameCrashExtraMessage        = 1012,
    
    kMethodNameExtend                   = 1111,
}MethodName;

NS_ITOP_END
//-------------------

#endif


