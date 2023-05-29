//
//  MSDKNetworkUtils.h
//  MSDK
//
//  Created by brightwan on 2018/3/30.
//  Copyright © company. All rights reserved.
//

#ifndef MSDK_NETWORK_UTILS_H
#define MSDK_NETWORK_UTILS_H

#include <string>
#include <stdio.h>

#include "MSDKLog.h"
#include "MSDKError.h"
#include "MSDKTools.h"
#include "MSDKMacros.h"
#include "MSDKJsonManager.h"

NS_MSDK_BEGIN

class MSDKNetworkUtils
{
public:

    /**
     * 创建请求 URL，创建请求Url，get参数携带openid
     * @param actionPath 后台接口字段，参考 MSDKProtocol.h 文件
     * @param channelID 账号平台标示 3--游客(guest)， 4 -- facebook ……MSDKMmap.h
     * @param seqStr 表示透传的参数，会在返回的json中带上该透传参数，用于调用方异步，只能由英文字母，数字，下划线组成，默认为空
     * @return 最终用于 MSDK 请求的 URL
     */
    static std::string GetURL(const std::string &actionPath, int channelID, const std::string postBody, const std::string &seqStr = "");

    /**
     * 创建请求 Account模块URL
     * @param actionPath 后台接口字段，参考 MSDKProtocol.h 文件
     * @param seqStr 表示透传的参数，会在返回的json中带上该透传参数，用于调用方异步，只能由英文字母，数字，下划线组成，默认为空
     * @return 最终用于 MSDK 请求的 URL
     */
    static std::string GetAccountURL(const std::string &actionPath, const std::string postBody, const std::string accountPlatType,
        const std::string &langType, const std::string &seqStr = "");

    /**
     * 加密 post data
     * @param postData 原始数据
     * @return 加密后数据
     */
    static std::string GetEncryptPostData(const std::string &postData);
    
    /**
     * 解密 response data
     * @param responseData 回包数据
     * @return 解密后的数据
     */
    static std::string GetDecryptResponseData(const std::string &responseData);
    
    /**
     * 根据指定键值 加密 post data
     * @param data 原始数据
     * @param key 加密key
     * @return 加密后数据
     */
    static std::string GetEncryptData(const std::string &data, const std::string &key);
    
    /**
     * 根据指定键值，解密 response data
     * @param data 回包数据
     * @param key 解密密key
     * @return 解密后的数据
     */
    static std::string GetDecryptData(const std::string &data, const std::string &key);
    
    /**
     * WebView 加密 data
     * @param postData 原始数据
     * @return 加密后数据
     */
    static std::string GetWebViewEncryptData(const std::string &postData);

    /**
     * urlencode 编码
     * @param str 源字符串
     * @return 编码字符串
     */
    static std::string UrlEncode(const std::string& str);
    
    /**
     * urlencode 解码
     * @param str 编码数据
     * @return 解码后原始数据
     */
    static std::string UrlDecode(const std::string& str);
    
    /**
     * 生成一个新的网络请求ID
     * @return 网络请求ID，ID默认从10000开始
     */
    static unsigned int GenerateRequestID();
    
    // MSDK 服务器回调统一处理
    template<typename MSDKRet>
    static void HandleNetworkResponse(unsigned int ret, const std::string &respBody,
                                      MSDKRet &msdkRet, const char *seqId, const char *realRetName)
    {
        LOG_DEBUG("[ %s ], handle network response data with ret : %d and respBody : %s", seqId,
                  ret, respBody.c_str());
        if (ret == 0)
        {
            if (respBody.empty())
            {
                msdkRet.retCode = MSDKError::MSDK_SERVER_ERROR;
                msdkRet.retMsg = MSDKTools::GetRetMsg(MSDKError::MSDK_SERVER_ERROR);
                msdkRet.thirdCode = ret;
                msdkRet.retMsg = "server returns data exception";

            }
            else
            {
                LOG_DEBUG("[ %s ], json to struct %s start", seqId, realRetName);
                MSDKJsonManager::LoadJson(respBody, msdkRet);
                LOG_DEBUG("[ %s ], json to struct %s finish", seqId, realRetName);

                if (msdkRet.thirdCode != 0)
                {
                    msdkRet.retCode = MSDKError::MSDK_SERVER_ERROR;
                    msdkRet.retMsg = MSDKTools::GetRetMsg(MSDKError::MSDK_SERVER_ERROR);
                }
                else
                {
                    msdkRet.retCode = MSDKError::SUCCESS;
                    msdkRet.retMsg = MSDKTools::GetRetMsg(MSDKError::SUCCESS);
                }
            }
        }
        else
        {
            msdkRet.retCode = MSDKError::LIBCURL_ERROR;
            msdkRet.retMsg = MSDKTools::GetRetMsg(MSDKError::LIBCURL_ERROR);
            msdkRet.thirdCode = ret;
            msdkRet.thirdMsg = "network library error";
        }
    }
};

NS_MSDK_END

NS_MSDK_SPACE_NO_STL_BEGIN

using MSDKNetworkUtils = MSDK::MSDKNetworkUtils;

NS_MSDK_SPACE_NO_STL_END

#endif /* MSDK_NETWORK_UTILS_H */
