//
//  NvEffectTrackViewTheme.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/3/27.
//

#import "NvViewTheme.h"

NS_ASSUME_NONNULL_BEGIN

/*! \if ENGLISH
 *
 *  \brief EffectTrackViewTheme Configuration item
 *  \else
 *
 *  \brief EffectTrackViewTheme配置项
 *  \endif
*/
@interface NvEffectTrackViewTheme : NvViewTheme

/*! \if ENGLISH
 *
 *  \brief Select the fragment Stroke color
 *  \else
 *
 *  \brief 选中片段描边颜色
 *  \endif
*/
@property (nonatomic, strong) UIColor *clipBorderColor;

/*! \if ENGLISH
 *
 *  \brief
 *  \else
 *
 *  \brief 选中片段描边宽度
 *  \endif
*/
@property (nonatomic, assign) CGFloat clipBorderWidth;

/*! \if ENGLISH
 *
 *  \brief Select the fragment stroke width
 *  \else
 *
 *  \brief 中间线样式
 *  \endif
*/
@property (nonatomic, strong) NvViewTheme *centerLineView;

/*! \if ENGLISH
 *
 *  \brief Left and right handle picture
 *  \else
 *
 *  \brief 左右把手图片
 *  \endif
*/
@property (nonatomic, strong) NSString *leftHandleImage;
@property (nonatomic, strong) NSString *rightHandleImage;


@end

NS_ASSUME_NONNULL_END
