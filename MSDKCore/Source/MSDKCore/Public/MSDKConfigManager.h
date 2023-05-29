/*!
 * @header MSDKConfigManager.h
 * @author developer
 * @date 2018/6/13
 * @abstract
 * 云控开关的声明
 * 
 * @copyright
 * Copyright © company. All rights reserved.
 */
#include "MSDKSingleton.h"
#include "MSDKCompatLayer.h"
#include "MSDKMutex.h"

#ifndef MSDK_CONFIG_MANAGER_H
#define MSDK_CONFIG_MANAGER_H

NS_MSDK_BEGIN

#define MSDK_CONFIG_PATH               "v2/conf/get_conf"
#define MSDK_DEFAULT_INI_NAME          "MSDKConfig.ini"
#define MSDK_CONFIG_FILE_POSTFIX       ".tmp"
#define MSDK_REMOTE_CONFIG_FILE_NAME   "itop_remote_config"
#define MSDK_GAME_SET_CONFIG_FILE_NAME "itop_game_set_config"
#define MSDK_LOGIN_UI_ENABLE "MSDK_LOGIN_UI_ENABLE"
#define MSDK_BIND_UI_ENABLE "MSDK_BIND_UI_ENABLE"
#define MSDK_ACCOUNT_PASSWORD_VALIDATION "MSDK_ACCOUNT_PASSWORD_VALIDATION"
#define MSDK_ACCOUNT_CUSTOM_CHANNEL         "MSDK_ACCOUNT_CUSTOM_CHANNEL"
#define MSDK_ACCOUNT_CUSTOM_CHANNEL_ID      "MSDK_ACCOUNT_CUSTOM_CHANNEL_ID"
#define MSDK_ACCOUNT_CUSTOM_PLATFORM_TYPE   "MSDK_ACCOUNT_CUSTOM_PLATFORM_TYPE"

class MSDK_EXPORT MSDKConfigManager : public MSDKSingleton<MSDKConfigManager>
{
    friend class MSDKSingleton<MSDKConfigManager>;

public:
    /*!
     * 根据键值，优先获取云端的配置，如果没有找到，再读取应用内的配置
     *
     * @param key 键值
     * @param defValue 获取不到值时默认返回
     * @return 根据键值获取的内容，没有找到的情况返回 defValue
     */
    std::string Get(const std::string &key, const char *defValue = "");

    std::string Get(const std::string &key, const std::string &defValue);

    bool Get(const std::string &key, bool defValue);

    int Get(const std::string &key, int defValue);

    long Get(const std::string &key, long defValue);

    double Get(const std::string &key, double defValue);
    
    bool GetDebugConfig(const std::string &key, bool defVal);

    /*!
     * 根据键值，获取应用内置的默认配置
     *
     * @param key 键值
     * @param defValue 获取不到值时默认返回
     * @return 根据键值获取的内容，没有找到的情况返回 defValue
     */
    std::string GetDefaultValue(const std::string &key, const std::string &defValue = "");

    /*!
     * 根据键值，获取云端下发的配置
     *
     * @param key 键值
     * @param defValue 获取不到值时默认返回
     * @return 根据键值获取的内容，没有找到的情况返回 defValue
     */
    std::string GetRemoteValue(const std::string &key, const std::string &defValue = "");

    /*!
     * 根据键值，获取本地游戏配置信息
     *
     * @param key 键值
     * @param defValue 获取不到值时默认返回
     * @return 根据键值获取的内容，没有找到的情况返回 defValue
     */
    std::string GetGameSetValue(const std::string &key, const std::string &defValue = "");


    /*!
     * 根据键值，获取GCloud云控配置信息
     *
     * @param key 键值
     * @param defValue 获取不到值时默认返回
     * @return 根据键值获取的内容，没有找到的情况返回 defValue
     */
    std::string GetGCRemoteValue(const std::string &key, const std::string &defValue = "");

    /*!
     * 更新云控开关，内部使用
     */
    void UpdateConfig(const std::string &seqID);

    /*!
     * 内部使用，更新配置并起开定时任务
     * @param seqID 执行序列ID
     * @param force 是否启用强制更新，true，强制本次更新，false，正常拉取，即，当有更新正在进行的时候，放弃本次更新
     */
    void UpdateConfigWithTimer(const std::string &seqID, bool force);


    bool UpdateConfig(const Vector<KVPair> &cfg);

    /*!
     * 内部使用，主动更新GC云控配置，仅在登录成功回调里调用
     */
    void UpdateGCRemoteConfig();
    


private:
    static std::map<std::string, std::string> mDefaultConfigCache;
    static std::map<std::string, std::string> mRemoteConfigCache;
    static std::map<std::string, std::string> mGameSetConfigCache;

    static bool mIsPullingData;

    static bool mIsConfigInitSucceed;

    static bool mIsConfigDebugEnable;

    static bool mIsGCloudExService;

    // 使用void*避免头文件引入IRemoteConfigService.h，从而大量cpp需要修改为混编
    static void *mGCloudConfigObserver;

    static MSDKMutex m_configMutex;

    void InitConfigFromINI();

    MSDKConfigManager();

    std::string CalcConfigsMD5(std::map<std::string, std::string> cfg);

    /*!
     * @return 组装云控开关请求串
     */
    std::string BuildUpdateConfigUrl(int &channelID, const std::string &seqID);

    /*!
     * 获取本地保存的云端配置项并且缓存到 mRemoteConfigCache 成员变量
     */
    void GetLocalConfig(const std::string &configFileName, std::map<std::string, std::string> &cfg);

    static bool SaveConfig(const std::string &configFileName,
                           std::map<std::string, std::string> cfg);

    std::string GetValue(const std::string &key, const std::string &defValue,
                         std::map<std::string, std::string> &m);

    static void OnConfigResponse(int sessionId, unsigned int ret, const std::string &respBody,
                                 void *userData);

    // 是否开启GCloud云控，默认打开
    bool IsGCRemoteConfigEnable(bool defValue = true);
    
    // 使用void*避免头文件引入IRemoteConfigService.h，从而大量cpp需要修改为混编
    void *GetGCRemoteConfig();

};
NS_MSDK_END

NS_MSDK_SPACE_NO_STL_BEGIN

using MSDKConfigManager = MSDK::MSDKConfigManager;

NS_MSDK_SPACE_NO_STL_END

#endif //MSDK_CONFIG_MANAGER_H
