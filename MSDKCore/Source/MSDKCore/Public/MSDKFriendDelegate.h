//
//  MSDKFriendDelegate.h
//  MSDKCore
//
//  Created by lamarzhang(张庆贺) on 2018/3/24.
//  Copyright © company. All rights reserved.
//


#ifndef MSDKFriendDelegate_h
#define MSDKFriendDelegate_h

#import "MSDKMacros.h"
#import "MSDKDefine.h"
#import "MSDKFriend.h"

struct MSDKQueryFriendsRequest {
    std::string subChannel;
    int page;
    int count;
    bool isInGame;
};


@protocol MSDKFriendDelegate <NSObject>

/*!
 *  @brief 发送消息
 *
 *  @param reqInfo  分享信息
 *  @param params 入参，包括channel，seqID，methodID
 */
- (void)sendMessage:(const GCloud::MSDK::MSDKFriendReqInfo &)reqInfo params:(GCloud::MSDK::MSDKBaseParams &)params observerID:(unsigned int)observerID;

/*!
 *  @brief 分享
 *
 *  @param reqInfo  分享信息
 *  @param params 入参，包括channel，seqID，methodID
 */
- (void)share:(const GCloud::MSDK::MSDKFriendReqInfo &)reqInfo params:(GCloud::MSDK::MSDKBaseParams &)params observerID:(unsigned int)observerID;

@optional

/*!
 *  @brief 获取好友
 *
 *  @param reqInfo  分享信息
 *  @param params 入参，包括channel，seqID，methodID
 */
- (void)queryFriends:(const MSDKQueryFriendsRequest &)reqInfo params:(GCloud::MSDK::MSDKBaseParams &)params;


/*!
 *  @brief 添加好友
 *
 *  @param reqInfo  好友的信息
 *  @param params 入参，包括channel，seqID，methodID
 */
- (void)addFriend:(const GCloud::MSDK::MSDKFriendReqInfo &)reqInfo params:(GCloud::MSDK::MSDKBaseParams &)params observerID:(unsigned int)observerID;

/**
 *
 * @param type 方法类型
 * @param seqId 请求ID
 * @return  YES: 支持该接口的静默协议
 */
- (BOOL)isBackendSupported:(int)methodID type:(int)type seqId:(NSString *)seqId;

/**
 *
 * @param reqInfo  分享信息
 * @param seqId 请求ID
 * @return  YES: 该渠道openid需要转化为uid
 */
- (BOOL)needOpenid2Uid:(int)methodId reqInfo:(const GCloud::MSDK::MSDKFriendReqInfo &)reqInfo seqId:(NSString *)seqId;

@end

#endif /* MSDKFriendDelegate_h */

