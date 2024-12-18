//
//  NvSPUtils.h
//  NvVideoEdit
//
//  Created by chengww on 2021/11/1.
//  Copyright © 2021 MEISHE. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Photos/Photos.h>
#import "UIImageView+Ext.h"

#define TOPINDICATOR [NvSPUtils safeAreaInsetsTop]
#define INDICATOR [NvSPUtils safeAreaInsetsBottom]

#define NV_Default_Filter @"D1C01CF7-CA73-4CB7-A6B7-630B5FF9EC74"

#define NV_EFFECT_UUID_DOUDONG @"A8A4344D-45DA-460F-A18F-C0E2355FE864"
#define NV_EFFECT_UUID_HUANJUE @"Video Echo"
#define NV_EFFECT_UUID_LINHUNCHUQIAO @"C6273A8F-C899-4765-8BFC-E683EE37AA84"
#define NV_EFFECT_UUID_JINGXIANG @"6B7BE12C-9FA1-4ED0-8E81-E107632FFBC8"
#define NV_EFFECT_UUID_BOLANG @"1CEE3777-A813-4378-AD52-7B264BD0CC4D"
#define NV_EFFECT_UUID_HEIMOFA @"C02204D0-F3C3-495E-B65C-9F2C79E68573"

#define NV_MINIMUM_SCALE_FACTOR .3
#define NV_MAXIMUM_SCALE_FACTOR 5

NS_ASSUME_NONNULL_BEGIN
typedef enum ENvIOSDeviceModel {
    keIOSDevice_Unknown = -1,
    keIPHONE_MIN = 0,
    keIPHONE_1 = keIPHONE_MIN,
    keIPHONE_2, // iPhone 3G
    keIPHONE_3, // iPhone 3GS
    keIPHONE_4,
    keIPHONE_4S,
    keIPHONE_5,
    keIPHONE_5C,
    keIPHONE_5S,
    keIPHONE_6,
    keIPHONE_6P,
    keIPHONE_6S,
    keIPHONE_6SP,
    keIPHONE_SE,
    keIPHONE_7,
    keIPHONE_7P,
    keIPHONE_X,
    keIPHONE_MAX,
} ENvIOSDeviceModel;

@interface NvSPUtils : NSObject
+ (BOOL)isEn;
+ (UIImage *_Nullable)imageWithName:(NSString *)imageName;
+ (UIFont *)fontWithSize:(float)size;
+ (UIFont *)smallFont;
+ (UIViewController *)getCurrentVC;
+ (ENvIOSDeviceModel)detectIOSDeviceModel;
+ (float)safeAreaInsetsTop;
+ (float)safeAreaInsetsBottom;
+ (NSString *)currentDateAndTime;
+ (NSString *)convertTimecode:(int64_t)time;
+ (NSString *_Nullable)convertTimecodePrecision:(int64_t)time;
+ (PHAssetCollection *)createCollection;
+ (void)saveImagePath:(NSString *)imagePath toCollection:(PHAssetCollection *)collection;

+ (NSArray <NSDictionary *>*)colorList;

+ (NSString *)convertVideoTime:(CGFloat)time;

+ (NSArray <NSString *>*)fontNameArrayWithFilePath:(NSString*)filePath;

+ (BOOL)lowPerformance;

+ (NSString *)captionCustomPackage;

+ (CGFloat)twoPointDistance:(CGPoint)p1 p2:(CGPoint)p2;

/// 返回设置的富文本
/// @param string 文本
/// @param color 字体颜色
/// @param font 字体大小
/// @param lineSpacing 行间距
/// @param wordSpacing 字间距
/// @param model 字符串截断样式
+ (NSAttributedString *)creatAttributedString:(NSString *)string withColor:(UIColor *)color withFont:(UIFont *)font withLineSpacing:(CGFloat)lineSpacing withWordspacing:(CGFloat)wordSpacing withLineBreakMode:(NSLineBreakMode)model;

+ (UIWindow *)keyWindow;

@end

NS_ASSUME_NONNULL_END
