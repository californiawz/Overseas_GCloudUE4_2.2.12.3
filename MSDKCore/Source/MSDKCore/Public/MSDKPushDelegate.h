//
//  MSDKPushDelegate.h
//  MSDKCore
//
//  Created by lamarzhang(张庆贺) on 2018/6/7.
//  Copyright © company. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MSDKDefine.h"



@protocol MSDKPushDelegate <NSObject>

-(void)registerPush:(const GCloud::MSDK::MSDKBaseParams &)baseParams withAccount:(const std::string &)account;

-(void)unregisterPush:(const GCloud::MSDK::MSDKBaseParams &)baseParams;

-(void)setTag:(const GCloud::MSDK::MSDKBaseParams &)baseParams withTag:(const std::string &)tag;

-(void)deleteTag:(const GCloud::MSDK::MSDKBaseParams &)baseParams withTag:(const std::string &)tag;

-(void)setAccount:(const GCloud::MSDK::MSDKBaseParams &)baseParams withAccount:(const std::string &)account;

-(void)deleteAccount:(const GCloud::MSDK::MSDKBaseParams &)baseParams withAccount:(const std::string &)account;

-(void)addLocalNotification:(const GCloud::MSDK::MSDKBaseParams &)baseParams local:(const GCloud::MSDK::InnerLocalNotification &)local;

-(void)clearLocalNotifications:(const GCloud::MSDK::MSDKBaseParams &)baseParams;

-(void)addLocalNotificationAtFront:(const GCloud::MSDK::MSDKBaseParams &)baseParams local:(GCloud::MSDK::InnerLocalNotification &) local;

-(void)deleteLocalNotifications:(const GCloud::MSDK::MSDKBaseParams &)baseParams key:(const std::string &)key;

-(void)cleanBadgeNumber;
                            
@end
