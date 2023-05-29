//
//  MSDKLoginIMPL.h
//  MSDKCore
//
//  Created by Hillson Song on 3/24/18.
//  Copyright © company. All rights reserved.
//

#ifndef MSDK_LOGIN_IMPL_H
#define MSDK_LOGIN_IMPL_H

#include "MSDKDefine.h"
#include "MSDKSingleton.h"

NS_MSDK_BEGIN

// 扫码登录返回的结构体
class MSDKQRCodeInfo : public InnerBaseRet
{
public:
    String sig; // 签名
    String random; // 一个随机的尽量不重复的字符串，用来使得每次的sig签名不同
    int64_t timestamp; // 时间戳
    AutoParser("",
               A(thirdCode, "ret"), A(thirdMsg, "msg"),A(extraJson, "extra"),
               O(retCode, retMsg, sig, random, timestamp));
    
};

// 登录平台实现层
class MSDKLoginIMPL : public MSDKSingleton<MSDKLoginIMPL> {
    friend class MSDKSingleton<MSDKLoginIMPL>;
    
public:
    
    /**
     * 渠道登录
     * @param loginParams 登录参数
     */
    void LoginChannel(const MSDKLoginParams &loginParams);

    /**
     * 渠道二次授权
     * @param loginParams 授权参数
     */
    void ChannelPermissionAuth(const MSDKLoginParams &loginParams);
    
    /**
     * 渠道自动登录
     * @param loginParams 登录参数
     */
    bool PluginAutoLogin(const MSDKLoginParams &loginParams);
    
    /**
     * 渠道登出
     * @param baseParams 内部参数
     */
    void Logout(const MSDKBaseParams &baseParams);

    /**
    * UI 登录
    * @param loginParams 内部参数
    */
    void LoginUI(const MSDKLoginParams &loginParams);

    /**
     * UI 绑定
     * @param loginParams 内部参数
     */
    void BindUI(const MSDKLoginParams &loginParams);
    
    /**
     * 扫码登录
     * @param loginParams 登录参数
     * @param qrInfo 扫码登录参数
     */
    void QRCodeLogin(const MSDKLoginParams &loginParams, const MSDKQRCodeInfo &qrInfo);

    /**
     * 判断扫码登录是否在插件实现；若在插件实现则返回 true，若需要走后台则返回 false
     * @param channel 渠道名
     */
     bool IsQRCodeLoginPluginEnabled(const std::string &channel, const std::string &seqID);
    
    /**
     * 判断是否支持自动刷新token功能；若渠道 token 有效时间较短，建议返回 true。
     * 自动刷新时间间隔，默认半小时 DEFAULT_REFRESH_INTERVAL = 30*60, MSDKConfig.ini 文件中 MSDK_REFRESH_INTERVAL 字段可配
     * @param channel 渠道名
     */
    bool IsTokenAutoRefreshEnabled(const std::string &channel, const std::string &seqID);

    /**
     * 检查是 UI 层是否需要处理回调
     * @param loginRet 登录结果
     * @return true UI 层处理不需要给游戏，UI 层不处理给游戏处理
     */
    bool checkHandleInUI(InnerLoginRet &loginRet, const char *seqID);

    /**
     * 检查是 BindUI 层是否需要处理回调
     * @param loginRet 登录结果
     * @return true UI 层处理不需要给游戏，UI 层不处理给游戏处理
     */
    bool checkHandleInBindUI(InnerLoginRet &loginRet, const char *seqID);
    
    /**
     * 检查是 UI 层是否需要处理回调
     * @param accountRet Account结果
     * @return true UI 层处理，fasle 游戏处理
     */
    bool checkHandleAccountRetInUI(const InnerBaseRet &accountRet, const char *seqID);


    /**
     * 检查是 UI 层是否需要处理回调
     * @param accountRet Account结果
     * @return true UI 层处理，fasle 游戏处理
     */
    bool checkHandleAccountRetInBindUI(const InnerAccountRet &accountRet, const char *seqID);

    
    /**
     * 判断渠道在登录或绑定操作前是否需要登出操作；
     * 默认在绑定前都会执行登出操作，但对于复杂渠道简单的登出会登出当前的游客状态，如 Garena，这就需要插件中返回 false，不做登出操作
     * @param channel 渠道名
     * @param methodName 是登录还是绑定操作
     * @param seqID 调用的序列号，用于打印日志
     * return 返回是否需要登出操作
     */
     bool IsSetNoNeedLogoutBeforeAction(const std::string &channel, const MethodName &methodName, const std::string &seqID);
    
    /**
     * 询问渠道是否需要定时器逻辑，默认需要，iOS H5 登录和手 Q 不安装客户端的情况，可以明确告知不需要超时逻辑 (Facebook 除外，Facebook 目前无法判定)
     * @param channel 渠道名
     * @param seqID 序列号，用于日志打印
     */
    bool needTimer(const std::string &channel, const char *seqID);
    
#if __APPLE__
   
    /**
       * 检查 Universal Link 的
       * @param loginParams 登录参数
    */
    void CheckUniversalLinkChannel(const MSDKLoginParams &loginParams);
#endif
    
private:
    MSDKLoginIMPL() {}
  
public:
    ~MSDKLoginIMPL() {
    }
};

NS_MSDK_END

NS_MSDK_SPACE_NO_STL_BEGIN

using MSDKQRCodeInfo = MSDK::MSDKQRCodeInfo;

NS_MSDK_SPACE_NO_STL_END

#endif /* MSDK_LOGIN_IMPL_H */
