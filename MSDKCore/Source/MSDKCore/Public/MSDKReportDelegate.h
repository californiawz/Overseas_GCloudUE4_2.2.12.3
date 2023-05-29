//
//  MSDKReportDelegate.h
//  MSDKCore
//
//  Created by Hillson Song on 6/7/18.
//  Copyright © company. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol MSDKReportDelegate <NSObject>

@required

- (bool)initStat;

- (void)reportEvent:(NSString *)event params:(NSDictionary *)params isRealtime:(BOOL)realtime seqID:(NSString *)seqID extra:(NSString *) extraJson;

@optional

- (void)setPushToken:(NSString *)pushToken;

- (std::string)getInstanceID:(NSString *) seqID __deprecated_msg("** this is a deprecated function from MSDKCore V5.16, please use getInstanceIDAsync instead **");

@end
