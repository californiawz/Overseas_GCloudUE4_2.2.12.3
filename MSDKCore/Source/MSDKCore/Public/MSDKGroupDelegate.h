//
// Created by lamarzhang(张庆贺) on 2018/5/16.
// Copyright (c) company. All rights reserved.
//

#ifndef MSDK_MSDKGroupIMPL_H
#define MSDK_MSDKGroupIMPL_H

#import <Foundation/Foundation.h>
#import "MSDKMacros.h"
#import "MSDKDefine.h"

@protocol MSDKGroupDelegate <NSObject>

- (int)createGroup:(const GCloud::MSDK::InnerUnionInfo &)unionInfo params:(const GCloud::MSDK::MSDKBaseParams &)params;

- (int)bindGroup:(const GCloud::MSDK::InnerUnionInfo &)unionInfo groupInfo:(const GCloud::MSDK::InnerGroupInfo &)groupInfo params:(const GCloud::MSDK::MSDKBaseParams &)params;

- (int)unbindGroup:(const GCloud::MSDK::InnerUnionInfo &)unionInfo params:(const GCloud::MSDK::MSDKBaseParams &)params;

- (int)getGroupList:(const GCloud::MSDK::MSDKBaseParams &)params;

- (int)getGroupState:(const GCloud::MSDK::InnerUnionInfo &)unionInfo params:(const GCloud::MSDK::MSDKBaseParams &)params;

- (int)getGroupRelation:(const GCloud::MSDK::InnerUnionInfo &)unionInfo groupInfo:(const GCloud::MSDK::InnerGroupInfo &)groupInfo params:(const GCloud::MSDK::MSDKBaseParams &)params;

- (int)joinGroup:(const GCloud::MSDK::InnerUnionInfo &)unionInfo groupInfo:(const GCloud::MSDK::InnerGroupInfo &)groupInfo params:(const GCloud::MSDK::MSDKBaseParams &)params;

- (int)remindToBindGroup:(const GCloud::MSDK::InnerUnionInfo &)unionInfo params:(const GCloud::MSDK::MSDKBaseParams &)params;

- (int)sendGroupMessage:(const GCloud::MSDK::InnerUnionInfo &)unionInfo friendReqInfo:(const GCloud::MSDK::MSDKGroupMessage &)groupMessage params:(const GCloud::MSDK::MSDKBaseParams &)params;

@end

#endif //MSDK_MSDKGroupIMPL_H
