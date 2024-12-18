//
//  NvTipToast.h
//  MintLive
//
//  Created by meishe on 2024/3/13.
//  Copyright © 2024年 meishe. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NvTipToast : NSObject

//以下方法会拦截用户交互
+ (void)showLoading;
+ (void)showLoadingInView:(UIView *)view;

+ (void)dismiss;
+ (void)dismissInView:(UIView *)view;

////以下方法不拦截交互
+ (void)showInfoWithMessage:(NSString *)message;
+ (void)showErrorWithMessage:(NSString *)message;
//
+ (void)showInfoWithMessage:(NSString *)message inView:(UIView *)view;

@end
