//
//  NvSliderTheme.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/3/27.
//

#import "NvViewTheme.h"

NS_ASSUME_NONNULL_BEGIN

/*! \if ENGLISH
 *
 *  \brief SliderTheme Configuration item
 *  \else
 *
 *  \brief SliderTheme配置项
 *  \endif
*/
@interface NvSliderTheme : NvViewTheme

/*! \if ENGLISH
 *
 *  \brief undertone
 *  \else
 *
 *  \brief 底色
 *  \endif
*/
@property (nonatomic, strong) UIColor *minimumTrackTintColor;

/*! \if ENGLISH
 *
 *  \brief Effective interval color
 *  \else
 *
 *  \brief 有效区间颜色
 *  \endif
*/
@property (nonatomic, strong) UIColor *maximumTrackTintColor;

/*! \if ENGLISH
 *
 *  \brief Handle color
 *  \else
 *
 *  \brief 把手颜色
 *  \endif
*/
@property (nonatomic, strong) UIColor *thumbTintColor;

/*! \if ENGLISH
 *
 *  \brief Numeric text color
 *  \else
 *
 *  \brief 数值文本颜色
 *  \endif
*/
@property (nonatomic, strong) UIColor *valueTextColor;

/*! \if ENGLISH
 *
 *  \brief Second numeric text colorf'f'f
 *  \else
 *
 *  \brief 第二数值文本颜色
 *  \endif
*/
@property (nonatomic, strong) UIColor *valueSecondaryTextColor;

/*! \if ENGLISH
 *
 *  \brief Handle icon
 *  \else
 *
 *  \brief 把手图标
 *  \endif
*/
@property (nonatomic, strong) NSString *thumbTintImage;

+ (BOOL)supportParsing:(UIView *)view;

@end

NS_ASSUME_NONNULL_END
