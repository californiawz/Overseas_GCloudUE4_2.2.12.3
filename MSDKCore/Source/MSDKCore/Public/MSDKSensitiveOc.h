///*
/*!
 * @Header MSDKSensitiveOc.h
 * @Author MikeFu
 * @Version 1.0.0
 * @Date 2021/11/9
 * @Abstract 文件功能的声明
 *
 * @Module iTOP
 *
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MSDKSensitiveDelegate <NSObject>
@optional
- (void)setCouldCollectSensitiveInfo:(BOOL)couldCollect;
- (void)setSensitiveInfo:(NSString *)jsonInfo;

@end

@interface MSDKSensitiveOc : NSObject

+ (instancetype)sharedInstance;
- (void)registSensitiveObserver:(id<MSDKSensitiveDelegate>)observer;
- (void)setCouldCollectSensitiveInfo:(BOOL)couldCollect;
- (void)setSensitiveInfo:(NSString *)jsonInfo;
- (void)setCollectSensitiveInfo:(NSString *)jsonInfo;//ios侧预留开关
- (BOOL)getCouldCollectSensitiveInfo;
- (NSString *)getSensitiveInfo;

@end

NS_ASSUME_NONNULL_END
