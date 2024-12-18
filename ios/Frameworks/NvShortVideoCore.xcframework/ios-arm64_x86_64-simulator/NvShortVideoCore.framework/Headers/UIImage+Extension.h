//
//  UIImage+Extension.h
//  meishe
//
//  Created by 美摄 on 2019/3/21.
//  Copyright © 2019 美摄. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (Extension)

/**
 根据颜色生成图片
 Generate images from colors
 @param color 颜色
 @param size 图片大小
 @return 图片
 */
+ (UIImage *)imageWithColor:(UIColor *)color size:(CGSize)size;
+ (UIImage *)imageWithColor:(UIColor *)color cornerRadius:(CGFloat)cornerRadius size:(CGSize)size;

/**
 根据颜色生成（1，1）图片
 Produces a (1,1) image based on color
 @param color 颜色
 @return 图片
 */
+ (UIImage *)imageWithColor:(UIColor *)color;

#pragma mark-- Circle

- (UIImage *)drawRoundedRectImage:(CGFloat)cornerRadius width:(CGFloat)width height:(CGFloat)height;

- (UIImage *)drawCircleImage;

@end

NS_ASSUME_NONNULL_END
