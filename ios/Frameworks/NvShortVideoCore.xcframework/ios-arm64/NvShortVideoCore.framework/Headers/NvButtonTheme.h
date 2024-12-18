//
//  NvButtonTheme.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/3/18.
//

#import "NvLabelTheme.h"

NS_ASSUME_NONNULL_BEGIN

/*! \if ENGLISH
 *
 *  \brief Button Configuration item
 *  \else
 *
 *  \brief Button配置项
 *  \endif
*/
@interface NvButtonTheme : NvViewTheme

/*! \if ENGLISH
 *
 *  \brief icon
 *  \else
 *
 *  \brief 图标
 *  \endif
*/
@property (nonatomic, strong) NSString *imageName;

/*! \if ENGLISH
 *
 *  \brief The icon when selected
 *  \else
 *
 *  \brief 选中时的图标
 *  \endif
*/
@property (nonatomic, strong) NSString *selectedImageName;

/*! \if ENGLISH
 *
 *  \brief Icon when disabled
 *  \else
 *
 *  \brief 禁用时的图标
 *  \endif
*/
@property (nonatomic, strong) NSString *disableImageName;

/*! \if ENGLISH
 *
 *  \brief Text style
 *  \else
 *
 *  \brief 文本样式
 *  \endif
*/
@property (nonatomic, strong) NvLabelTheme *title;

/*! \if ENGLISH
 *
 *  \brief Text style check
 *  \else
 *
 *  \brief 文本样式 选中
 *  \endif
*/
@property (nonatomic, strong) NvLabelTheme *selectedTitle;

/*! \if ENGLISH
 *
 *  \brief Text style disabled
 *  \else
 *
 *  \brief 文本样式 禁用
 *  \endif
*/
@property (nonatomic, strong) NvLabelTheme *disableTitle;

/*! \if ENGLISH
 *
 *  \brief The background color is selected
 *  \else
 *
 *  \brief 选中时背景颜色
 *  \endif
*/
@property (nonatomic, strong) UIColor *selectedBackgroundColor;

- (void)addTheme:(NvButtonTheme *)theme;

+ (BOOL)supportParsing:(UIView *)view;

@end

NS_ASSUME_NONNULL_END
