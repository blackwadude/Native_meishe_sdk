//
//  NvTextFiedTheme.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/3/26.
//

#import "NvLabelTheme.h"

NS_ASSUME_NONNULL_BEGIN

/*! \if ENGLISH
 *
 *  \brief TextField Configuration item
 *  \else
 *
 *  \brief TextField配置项
 *  \endif
*/
@interface NvTextFieldTheme : NvLabelTheme

/*! \if ENGLISH
 *
 *  \brief Placeholder font
 *  \else
 *
 *  \brief 占位符字体
 *  \endif
*/
@property (nonatomic, strong) UIFont *placeholderFont;

/*! \if ENGLISH
 *
 *  \brief Placeholder text color
 *  \else
 *
 *  \brief 占位符文本颜色
 *  \endif
*/
@property (nonatomic, strong) UIColor *placeholderColor;

@end

NS_ASSUME_NONNULL_END
