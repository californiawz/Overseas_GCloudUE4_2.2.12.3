/*!
 * @Module MSDK
 *
 * @Header  MSDKQrcodeVC.h
 * @Author  hillsonsong
 * @Date 2018/08/09
 * @Abstract 扫码登录显示页面
 *
 * @Copyright
 * Copyright © company. All rights reserved.
 */

#import <UIKit/UIKit.h>

@interface MSDKQrcodeVC : UIViewController

/**
 * 初始化视图控制器
 * @param channel 渠道名
 */
- (id)initWithChannel:(NSString *)channel seqID:(NSString *)seqID;

/**
 * 展示
 */
- (void)show;

/**
 * 隐藏
 */
- (void)dismiss;

/**
 * 插件获取到二维码后，调用改函数展示二维码
 */
- (void)onAuthGotQrcode:(UIImage *)image;

/**
 * 二维码扫描过程中，调用该函数
 */
- (void)onQrcodeScanned;

@end
