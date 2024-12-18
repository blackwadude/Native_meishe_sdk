//
//  NvLabelTheme.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/3/18.
//

#import "NvViewTheme.h"

NS_ASSUME_NONNULL_BEGIN

/*! \if ENGLISH
 *
 *  \brief Llabel Configuration item
 *  \else
 *
 *  \brief Label配置项
 *  \endif
*/
@interface NvLabelTheme : NvViewTheme

/*! \if ENGLISH
 *
 *  \brief UIFont
 *  \else
 *
 *  \brief 字体
 *  \endif
*/
@property (nonatomic, strong) UIFont *font;

/*! \if ENGLISH
 *
 *  \brief Text color
 *  \else
 *
 *  \brief 文字颜色
 *  \endif
*/
@property (nonatomic, strong) UIColor *textColor;

@end

NS_ASSUME_NONNULL_END
