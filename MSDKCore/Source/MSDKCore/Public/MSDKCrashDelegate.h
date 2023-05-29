//
//  MSDKCrashDelegate.h
//  MSDKCore
//
//  Created by Hillson Song on 6/9/18.
//  Copyright © company. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol MSDKCrashDelegate <NSObject>

@required

- (void)initCrashReport;

@optional

- (void)reportLog:(int)level tag:(NSString *)tag log:(NSString *)log;

- (void)setUserData:(NSString *)key value:(NSString *)value;

- (void)setUserId: (NSString *)userId;

- (void)reportException:(int)type exceptionName:(NSString *)exceptionName
        exceptionMsg:(NSString *)exceptionMsg
        exceptionStack:(NSString *)exceptionStack
        extInfo:(NSDictionary *)extInfo;

- (void)closeCrashReport;
@end
