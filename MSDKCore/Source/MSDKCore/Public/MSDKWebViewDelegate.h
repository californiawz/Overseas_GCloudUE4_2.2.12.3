//
// Created by lamarzhang(张庆贺) on 2018/5/25.
// Copyright (c) company. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MSDKDefine.h"

typedef void (*MSDKFriendCallbackInWebView)(int fromType, const std::string &channel, int shareType,const GCloud::MSDK::MSDKFriendReqInfo &reqInfo);

@protocol MSDKWebViewDelegate <NSObject>

- (void)openURL:(const GCloud::MSDK::InnerWebViewReqInfo &)webInfo observerID:(unsigned int)observerID;

- (void)callJS:(std::string)jsonJSPara;

- (void)shareRet:(const std::string &)json;

- (void)setFriendCallback:(void (*)(int, const std::string &, int,const GCloud::MSDK::MSDKFriendReqInfo &))pFunction;

- (void)setEmbedBackground:(std::string &)imagePath;

- (void)webViewDidClose;

@end
