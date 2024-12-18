//
//  NvTemplateHomeDataErrorTheme.h
//  NvShortVideoCore
//
//  Created by ms20221114 on 2024/3/27.
//

#import "NvViewTheme.h"
#import "NvLabelTheme.h"
#import "NvButtonTheme.h"
NS_ASSUME_NONNULL_BEGIN

/*! \if ENGLISH
 *
 *  \brief TemplateHomeDataErrorTheme Configuration item
 *  \else
 *
 *  \brief TemplateHomeDataErrorTheme配置项
 *  \endif
*/
@interface NvTemplateHomeDataErrorTheme : NvViewTheme

/*! \if ENGLISH
 *
 *  \brief Text style
 *  \else
 *
 *  \brief 文本样式
 *  \endif
*/
@property (nonatomic, strong) NvLabelTheme *titleLabel;

/*! \if ENGLISH
 *
 *  \brief Description text style
 *  \else
 *
 *  \brief 描述文本样式
 *  \endif
*/
@property (nonatomic, strong) NvLabelTheme *descriptionLabel;

/*! \if ENGLISH
 *
 *  \brief Button style
 *  \else
 *
 *  \brief 按钮样式
 *  \endif
*/
@property (nonatomic, strong) NvButtonTheme *retryBtn;

@end

NS_ASSUME_NONNULL_END
