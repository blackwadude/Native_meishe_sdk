//
//  NvEffectTimeRangeViewTheme.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/3/28.
//

#import "NvViewTheme.h"
#import "NvImageViewTheme.h"

NS_ASSUME_NONNULL_BEGIN

/*! \if ENGLISH
 *
 *  \brief EffectTimeRangeViewTheme Configuration item
 *  \else
 *
 *  \brief EffectTimeRangeViewTheme配置项
 *  \endif
*/
@interface NvEffectTimeRangeViewTheme : NvViewTheme

/*! \if ENGLISH
 *
 *  \brief Complete button style
 *  \else
 *
 *  \brief 完成按钮样式
 *  \endif
*/
@property (nonatomic, strong) NSString *doneBtImage;

/*! \if ENGLISH
 *
 *  \brief Text color
 *  \else
 *
 *  \brief 文本颜色
 *  \endif
*/
@property (nonatomic, strong) UIColor *valueTextColor;
@property (nonatomic, strong) UIColor *valueSecondaryTextColor;

/*! \if ENGLISH
 *
 *  \brief Select the fragment Stroke style
 *  \else
 *
 *  \brief 选中片段描边样式
 *  \endif
*/
@property (nonatomic, strong) UIColor *clipBorderColor;
@property (nonatomic, assign) CGFloat clipBorderWidth;

/*! \if ENGLISH
 *
 *  \brief Center line style
 *  \else
 *
 *  \brief 中线样式
 *  \endif
*/
@property (nonatomic, strong) NvViewTheme *centerLineView;

/*! \if ENGLISH
 *
 *  \brief Left and right handle pattern
 *  \else
 *
 *  \brief 左右把手样式
 *  \endif
*/
@property (nonatomic, strong) NSString *leftHandleImage;
@property (nonatomic, strong) NSString *rightHandleImage;

/*! \if ENGLISH
 *
 *  \brief Prompt text style
 *  \else
 *
 *  \brief 提示文本样式
 *  \endif
*/
@property (nonatomic, strong) NvViewTheme *tipLabel;

@end

NS_ASSUME_NONNULL_END
