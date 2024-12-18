//
//  NvMusciCutViewTheme.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/3/26.
//

#import "NvViewTheme.h"
#import "NvButtonTheme.h"
#import "NvLabelTheme.h"

NS_ASSUME_NONNULL_BEGIN

/*! \if ENGLISH
 *
 *  \brief MusciCutViewTheme Configuration item
 *  \else
 *
 *  \brief MusciCutViewTheme配置项
 *  \endif
*/
@interface NvMusciCutViewTheme : NvViewTheme

/*! \if ENGLISH
 *
 *  \brief Time text font
 *  \else
 *
 *  \brief 时间文本 字体
 *  \endif
*/
@property (nonatomic, strong) UIFont    *timeFont;

/*! \if ENGLISH
 *
 *  \brief Time text color
 *  \else
 *
 *  \brief 时间文本 颜色
 *  \endif
*/
@property (nonatomic, strong) UIColor   *timeTextColor;

/*! \if ENGLISH
 *
 *  \brief Time text second color
 *  \else
 *
 *  \brief 时间文本 第二颜色
 *  \endif
*/
@property (nonatomic, strong) UIColor   *timeSecondaryTextColor;

/*! \if ENGLISH
 *
 *  \brief Left side line color
 *  \else
 *
 *  \brief 左侧线颜色
 *  \endif
*/
@property (nonatomic, strong) UIColor *leftLineColor;

/*! \if ENGLISH
 *
 *  \brief Waveform diagram base color
 *  \else
 *
 *  \brief 波形图底色
 *  \endif
*/
@property (nonatomic, strong) UIColor *waveColor;

/*! \if ENGLISH
 *
 *  \brief Wave diagram bright color
 *  \else
 *
 *  \brief 波形图亮色
 *  \endif
*/
@property (nonatomic, strong) UIColor *waveTintColor;

/*! \if ENGLISH
 *
 *  \brief Waveform background color
 *  \else
 *
 *  \brief 波形图背景色
 *  \endif
*/
@property (nonatomic, strong) UIColor *waveBackgroundColor;

/*! \if ENGLISH
 *
 *  \brief Right button icon
 *  \else
 *
 *  \brief 右侧按钮图标
 *  \endif
*/
@property (nonatomic, strong) NSString *rightBtImage;

/*! \if ENGLISH
 *
 *  \brief Loop button style
 *  \else
 *
 *  \brief 循环按钮样式
 *  \endif
*/
@property (nonatomic, strong) NvButtonTheme *loopBt;

/*! \if ENGLISH
 *
 *  \brief Prompt text style
 *  \else
 *
 *  \brief 提示文本样式
 *  \endif
*/
@property (nonatomic, strong) NvLabelTheme *tipLabel;

@end

NS_ASSUME_NONNULL_END
