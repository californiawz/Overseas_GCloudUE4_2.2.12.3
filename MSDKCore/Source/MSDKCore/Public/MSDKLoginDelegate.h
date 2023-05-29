//
//  MSDKLoginDelegate.h
//  MSDKCore
//
//  Created by Hillson Song on 3/26/18.
//  Copyright © company. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MSDKDefine.h"
#import "MSDKLoginIMPL.h"

#define MSDK_LOGIN_CANCEL_NOTI @"MSDK_LOGIN_CANCEL_NOTI" // 登录取消通知

@protocol MSDKLoginDelegate <NSObject>

@required

- (void)login:(const GCloud::MSDK::MSDKLoginParams &)params;

@optional

//渠道授权协议，用于某些特殊渠道，视频号授权时可调用该插件
- (void)channelPermissionAuth:(const GCloud::MSDK::MSDKLoginParams &)params;

// 插件自动登录协议，用于某些特殊渠道，其要求在自动登录时调用到插件
- (void)autoLogin:(const GCloud::MSDK::MSDKLoginParams &)params;

// 插件登出协议，如果渠道本身不支持登出（如XIN），可不实现该函数
- (void)logout:(const GCloud::MSDK::MSDKBaseParams &)params;

// 渠道 APP 是否安装
- (BOOL)isChannelInstall;

// 扫码登录
- (void)qrCodeLogin:(const GCloud::MSDK::MSDKLoginParams &)params info:(const GCloud::MSDK::MSDKQRCodeInfo &)qrinfo;

// 判断插件是否支持扫码登录
- (BOOL)isQRCodeLoginPluginEnabled;

/**
 * 判断是否支持自动刷新token功能；若渠道 token 有效时间较短，建议返回 true。
 * 自动刷新时间间隔，默认半小时，MSDKConfig.ini 文件中 MSDK_REFRESH_INTERVAL 字段可配
 */
- (BOOL)isTokenAutoRefreshEnabled;

/**
 * 判断 methodID 返回是否需要先执行登出操作
 * @return true - 设置不执行登出操作，false - 不设置，即默认执行登出操作
 */
- (BOOL)isSetNoNeedLogoutBeforeAction:(const int &)methodID seqID:(const std::string &)seqID;

/**
 * 插件检测接口，params 这里不适用引用，防止在插件的 block 中引起 Crash
 */
- (void)checkUniversalLink:(const GCloud::MSDK::MSDKLoginParams)params;

/**
 * 询问渠道是否需要定时器逻辑，默认需要，iOS H5 登录和手 Q 不安装客户端的情况，可以明确告知不需要超时逻辑 (Facebook 除外，Facebook 目前无法判定)
 */
- (bool)needTimer:(const char *)seqID;

@end
