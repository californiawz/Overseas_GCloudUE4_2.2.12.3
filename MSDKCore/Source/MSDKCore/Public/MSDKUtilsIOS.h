//
//  MSDKUtilsIOS.h
//  MSDKCore
//
//  Created by lamarzhang(张庆贺) on 2018/3/26.
//  Copyright © company. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MSDKDefine.h"

#define GET_NSSTRING(cString) [NSString stringWithCString:(cString.c_str()?cString:"").c_str() encoding:NSUTF8StringEncoding]

@interface MSDKUtilsIOS : NSObject

+ (BOOL)swizzlingOriginalClass:(Class)originalClass
                 swizzledClass:(Class)swizzledClass
                   originalSEL:(SEL)originalSEL
                   swizzledSEL:(SEL)swizzledSEL;

+ (BOOL)addOriginalClass:(Class)originalClass swizzledClass:(Class)swizzledClass originalSEL:(SEL)originalSEL swizzledSEL:(SEL)swizzledSEL ;

+ (void)loadImageWithUri:(NSString *)imageUri complete:(void(^)(NSData *image))completeHandle;


/**
 *  将标准json字符串转化为字典
 *
 *  @param jsonString 标准json字符串
 *
 *  @return 目标字典
 */
+ (NSDictionary *)dictFromJsonString:(NSString *)jsonString;

/**
 *  将NSDictionary转为标准JSON字符串
 *
 *  @param dict 目标字典
 *  @param prettyPrint 生成的JSON数据是否使用空格
 *
 *  @return 结果JSON字符串
 */
+ (NSString *)jsonStringFromDict:(NSDictionary *)dict prettyPrint:(BOOL)prettyPrint;

/**
 *  将NSArray转为标准JSON字符串
 *
 *  @param array 目标数组
 *  @param prettyPrint 生成的JSON数据是否使用空格
 *
 *  @return 结果JSON字符串
 */
+ (NSString *)jsonStringFromArray:(NSArray *)array prettyPrint:(BOOL)prettyPrint;

/**
 *  获取顶层控制器
 *
 *  @return 目标controller
 */
+ (UIViewController *)getRootViewController;

/**

 *  获取对应的KeyWindo的顶层控制器
 *
 *  @param keyWindow 对应的KeyWindow
 *
 *  @return 目标controller
 */
+ (UIViewController *)getRootViewController:(UIWindow *)keyWindow;

/**
 * 获取 info.plist 中支持的旋转方向
 * @return 屏幕方向
 */
+ (UIInterfaceOrientationMask)getSupportedInterfaceOrientations;

/**
 * 获取WebView 配置项支持的方向
 * @return 屏幕方向
 */
+ (UIInterfaceOrientationMask)getWebViewOrientations;

/**
 *  获取 URL 中的参数键值对
 *
 *  @param urlString 目标 URL 字符串
 *
 *  @return 参数键值对
 */
+ (NSDictionary *)getDictionaryFromUrl:(NSString *)urlString;

/**
 *  NSDictionary => KVPair vector
 *
 *  @param dict 目标字典
 *
 *  @return 转化后的容器
 */
+ (std::vector<GCloud::MSDK::KVPair>)vectorFromDict:(NSDictionary *)dict;

/**
 *  KVPair vector => NSDictionary
 *
 *  @param kvVector KVPair vector
 *
 *  @return 字典
 */
+ (NSDictionary *)dictFromKVVector:(GCloud::MSDK::Vector<GCloud::MSDK::KVPair>)kvVector;

/**
 *  获取原始设备型号
 *
 *  @return 设备型号
 */
+ (NSString *)getCurrentDeviceModel;
@end
