//
//  UIImageView+Ext.h
//  NvShortVideo
//
//  Created by chengww on 2021/11/2.
//  Copyright © 2021 MEISHE. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^NvImageCompletionBlock)(UIImage * _Nullable image);

@interface UIImageView (Ext)

+ (UIImageView *)animatedImageView:(CGRect)frame;

- (void)nv_setAnimatedImage:(NSString *)imageFilePath;

- (void)setImage:(UIImage *)image withSelectColor:(nullable UIColor *)color;

- (void)nv_setImageWithURL:(NSURL *_Nullable)url placeholder:(nullable UIImage *)pImage;

- (void)nv_setImageWithURL:(NSURL *_Nullable)url placeholder:(nullable UIImage *)pImage completion:(nullable NvImageCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
