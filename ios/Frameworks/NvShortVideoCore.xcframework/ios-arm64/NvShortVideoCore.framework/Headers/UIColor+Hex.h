//
//  UIColor+Hex.h
//  NvVideoEditor
//
//  Created by chengww on 2021/11/1.
//  Copyright © 2021 MEISHE. All rights reserved.
//

#import <UIKit/UIKit.h>

#define TEXT_DISABLE_COLOR [UIColor colorWithHexARGB:@"#FF999CB0"]
#define TEXT_ENABLE_COLOR [UIColor whiteColor]
#define STYLE_COLOR [UIColor colorWithHexARGB:@"#FFFC3E5A"]

NS_ASSUME_NONNULL_BEGIN

@interface UIColor (Hex)

+ (UIColor *)colorWithHexString:(NSString *)color;

//从十六进制字符串获取颜色，
//color:支持@“#123456”、 @“0X123456”、 @“123456”三种格式
+ (UIColor *)colorWithHexString:(NSString *)color alpha:(CGFloat)alpha;

+ (instancetype)colorWithHexRGBA:(NSString *)rgba;

+ (instancetype)colorWithHexRGB:(NSString *)rgb;

+ (instancetype)colorWithHexARGB:(NSString *)argb;

+ (UIColor *)randomColor;

+ (NSString *)randomColorStringWithAlpha:(CGFloat)alpha;

+ (UIColor *)randomColorWithAlpha:(CGFloat)alpha;

+ (NSString *)hexColorString:(NSString *)color;
@end

NS_ASSUME_NONNULL_END
