///*
/*!
 * @Header IServeiceAccount.h
 * @Author Hillson Song
 * @Version 1.0.0
 * @Date 2018/9/3
 * @Abstract 文件功能的声明
 *
 * @Module MSDK
 *
 */

#ifndef IServeiceAccount_H
#define IServeiceAccount_H

#include "PluginBase.h"

class MSDKAccount
{
public:
    char * openID;
    char * token;
    char * userName;
    char * channel;
    int channelID;
    long tokenExpire;

public:
    MSDKAccount();
    ~MSDKAccount();
};

class IServeiceAccount : public GCloud::Plugin::IPluginService
{
    
public:
    virtual bool getLoginRet(MSDKAccount &account) = 0;
};

#endif /* IServeiceAccount_H */
