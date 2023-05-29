///*
/*!
 * @Header MSDKLBSIMPL.hpp
 * @Author waylenzhang(张文亮)
 * @Version 1.0.0
 * @Date 2019/5/16
 * @Abstract 文件功能的声明
 *
 * @Module MSDK
 *
 * Copyright © company. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "MSDKDefine.h"

@protocol MSDKLBSDelegate <NSObject>

@required

- (void)location:(const GCloud::MSDK::MSDKBaseParams &)param;

@optional

@end

