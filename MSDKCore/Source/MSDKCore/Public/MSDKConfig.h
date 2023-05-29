/*!
 * @header MSDKConfig.h
 * @author developer
 * @date 2018/4/17
 * @abstract
 * 云控开关配置下发以及本地默认配置功能，默认先输出本地配置
 * 
 * @copyright
 * Copyright © company. All rights reserved.
 */

#ifndef MSDK_CONFIG_H
#define MSDK_CONFIG_H
#include "MSDKDefine.h"

// language and region
#define MSDK_LANGUAGE "lang"
#define MSDK_REGION "region"

NS_MSDK_BEGIN
class MSDK_EXPORT MSDKConfig
{
private:
    static bool UpdateConfigPRV(Vector<KVPair> cfg);

public:

    /*！
     * 更新游戏配置项，对外使用
     * @param configs 需要更新的配置信息
    */
    static bool UpdateConfig(std::map<std::string, std::string> &configs)
    {
        Vector<KVPair> tmp;
        std::map<std::string, std::string>::iterator it = configs.begin();
        for (; it != configs.end(); it++)
        {
            KVPair kvPair;
            kvPair.key = (*it).first;
            kvPair.value = (*it).second;
            tmp.push_back(kvPair);
        }

        return UpdateConfigPRV(tmp);
    }
#if MSDK_PLATFORM_WINDOWS
#else
    /**
    * Set Language
    * @param lang language, such as en-US
    */
    static void SetLanguage(const String &lang);

    /**
     * Set Region
     * @param country country, such as US
     * @param province province, such as NY
     * @param city city, such as NYC
     */
    static void SetRegion(const String &country, const String &province = "", const String &city = "");
#endif
};

NS_MSDK_END

NS_MSDK_SPACE_NO_STL_BEGIN

class MSDK_EXPORT MSDKConfig
{
public:
    /*！
     * 更新游戏配置项，对外使用
     * @param configs 需要更新的配置信息
     */
    static bool UpdateConfig(const StringMap &configs);

#if MSDK_PLATFORM_WINDOWS
#else
    /**
    * Set Language
    * @param lang language, such as en-US
    */
    static void SetLanguage(const String &lang);

    /**
     * Set Region
     * @param country country, such as US
     * @param province province, such as NY
     * @param city city, such as NYC
     */
    static void SetRegion(const String &country, const String &province = "", const String &city = "");
#endif
};

NS_MSDK_SPACE_NO_STL_END

#include "MSDKRename.h"
#endif //MSDK_CONFIG_H

