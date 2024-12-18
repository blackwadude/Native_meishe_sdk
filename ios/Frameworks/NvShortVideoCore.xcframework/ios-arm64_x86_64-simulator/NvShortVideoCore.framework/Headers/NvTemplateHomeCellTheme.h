//
//  NvTemplateHomeCellTheme.h
//  NvShortVideoCore
//
//  Created by ms20221114 on 2024/3/25.
//

#import "NvCellTheme.h"
#import "NvLabelTheme.h"
#import "NvImageViewTheme.h"
#import "NvButtonTheme.h"

NS_ASSUME_NONNULL_BEGIN

/*! \if ENGLISH
 *
 *  \brief TemplateHomeCellTheme Configuration item
 *  \else
 *
 *  \brief TemplateHomeCellTheme配置项
 *  \endif
*/

@interface NvTemplateHomeCellTheme : NvCellTheme

/*! \if ENGLISH
 *
 *  \brief Text style
 *  \else
 *
 *  \brief 文字样式
 *  \endif
*/
@property (nonatomic, strong) NvLabelTheme *descriptionLabel;

/*! \if ENGLISH
 *
 *  \brief Picture style
 *  \else
 *
 *  \brief 图片样式
 *  \endif
*/
@property (nonatomic, strong) NvImageViewTheme *imageView;

/*! \if ENGLISH
 *
 *  \brief Secondary image style
 *  \else
 *
 *  \brief 二级图片样式
 *  \endif
*/
@property (nonatomic, strong) NvImageViewTheme *centerImageView;

/*! \if ENGLISH
 *
 *  \brief Button style
 *  \else
 *
 *  \brief 按钮样式
 *  \endif
*/
@property (nonatomic, strong) NvButtonTheme *button;

@end

NS_ASSUME_NONNULL_END
