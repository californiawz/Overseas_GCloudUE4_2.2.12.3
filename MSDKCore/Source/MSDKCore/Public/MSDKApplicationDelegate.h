//
//  MSDKApplicationDelegate.h
//  MSDKCore
//
//  Created by lamarzhang(张庆贺) on 2018/3/26.
//  Copyright © company. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

#define MSDKAPPLICATIONDELEGATE                                  @"MSDKApplicationDelegate"
#define APPLICATION_DIDFINISHLAUNCHINGWITHOPTIONS                @"application:didFinishLaunchingWithOptions:"
#define APPLICATION_OPENURL_SOURCEAPPLICATION_ANNOTATION         @"application:openURL:sourceApplication:annotation:"
#define APPLICATION_OPENURL_OPTIONS                              @"application:openURL:options:"
#define APPLICATION_DEVICE_TOKEN                                 @"application:didRegisterForRemoteNotificationsWithDeviceToken:"
#define APPLICATION_FAIL_DEVICE_TOKEN                            @"application:didFailToRegisterForRemoteNotificationsWithError:"
#define APPLICATION_NOTIFICATION                                 @"application:didReceiveRemoteNotification:"
#define APPLICATION_NOTIFICATION_HANDLE                          @"application:didReceiveRemoteNotification:fetchCompletionHandler:"
#define APPLICATION_LOCAL_NOTIFICATION                           @"application:didReceiveLocalNotification:"
#define APPLICATION_CONTINUEUSERACTIVITY                         @"application:continueUserActivity:restorationHandler:"


NSString *const MSDKDeviceToken                                                 = @"MSDKDeviceToken";

NSString *const MSDKApplicationRegisterForRemoteNotificationsNotification       = @"MSDKApplicationRegisterForRemoteNotificationsNotification";
NSString *const MSDKApplicationRegisterForRemoteNotificationsFailedNotification = @"MSDKApplicationRegisterForRemoteNotificationsFailedNotification";
NSString *const MSDKApplicationDidReceiveRemoteNotificationNotification         = @"MSDKApplicationDidReceiveRemoteNotificationNotification";
NSString *const MSDKApplicationDidReceiveRemoteNotificationWithFetchCompletionHandlerNotification = @"MSDKApplicationDidReceiveRemoteNotificationWithFetchCompletionHandlerNotification";
NSString *const MSDKApplicationDidReceiveLocalNotificationNotification         = @"MSDKApplicationDidReceiveLocalNotificationNotification";

/*!
 *  @brief 通过 application:open:options: 打开 APP，MSDK 对 URL 参数进行解析处理后的回调
 *
 *  @param launchData 回调参数
 *  @param launchURL 透传 application:open:options: 中完整的 URL 参数
 */
typedef void(^MSDKUrlLaunchHandle)(NSDictionary *launchData, NSURL *launchURL);

@interface MSDKApplicationDelegate : NSObject

/*!
 @abstract 获取单例对象
 @result 单例对象
 */
+ (instancetype)sharedInstance;

/*!
 @abstract MSDK SDK 应用入口
 @discussion 需要在应用 [UIApplicationDelegate application:didFinishLaunchingWithOptions:] 内调用
 @param application     application
 @param launchOptions   launchOptions
 @result YES
 */
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

#pragma mark - Open URL

- (BOOL)application:(UIApplication *)application
            openURL:(NSURL *)url
  sourceApplication:(NSString *)sourceApplication
         annotation:(id)annotation;

//for iOS9+
- (BOOL)application:(UIApplication *)application
            openURL:(NSURL *)url
            options:(NSDictionary *)options;

#pragma mark - Orientation

- (UIInterfaceOrientationMask)application:(UIApplication *)application supportedInterfaceOrientationsForWindow:(UIWindow *)window;

/**
 * 游戏是否调用了 [MSDKApplicationDelegate application:supportedInterfaceOrientationsForWindow]
 * @return  YES：调用了，NO: 未调用
 */
- (BOOL)isCallOrientation;

#pragma mark - APNS Push

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;

- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error;

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo;//收到通知的回调

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification;

#pragma clang diagnostic pop

- (BOOL)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void (^)(NSArray * _Nullable))restorationHandler;

NS_ASSUME_NONNULL_END

@end
