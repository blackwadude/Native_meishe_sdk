//
//  NvCaptionViewTheme.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/3/28.
//

#import "NvViewTheme.h"
#import "NvButtonTheme.h"

NS_ASSUME_NONNULL_BEGIN

/*! \if ENGLISH
 *
 *  \brief CaptionViewTheme Configuration item
 *  \else
 *
 *  \brief CaptionViewTheme配置项
 *  \endif
*/
@interface NvCaptionViewTheme : NvViewTheme

/*! \if ENGLISH
 *
 *  \brief Cursor color
 *  \else
 *
 *  \brief 光标颜色
 *  \endif
*/
@property (nonatomic, strong) UIColor *textViewTintColor;

/*! \if ENGLISH
 *
 *  \brief Complete button style
 *  \else
 *
 *  \brief 完成按钮样式
 *  \endif
*/
@property (nonatomic, strong) NvButtonTheme *doneBt;

/*! \if ENGLISH
 *
 *  \brief Align icon
 *  \else
 *
 *  \brief 对齐图标
 *  \endif
*/
@property (nonatomic, strong) NSString *leftAlignmentImage;
@property (nonatomic, strong) NSString *centerAlignmentImage;
@property (nonatomic, strong) NSString *rightAlignmentImage;

/*! \if ENGLISH
 *
 *  \brief Caption style corresponding icon
 *  \else
 *
 *  \brief 字幕样式对应的图标
 *  \endif
*/
@property (nonatomic, strong) NSString *styleNoneImage;
@property (nonatomic, strong) NSString *styleBgImage;
@property (nonatomic, strong) NSString *styleBgAlphaImage;
@property (nonatomic, strong) NSString *styleOutlineImage;

/*! \if ENGLISH
 *
 *  \brief Font style
 *  \else
 *
 *  \brief 字体样式
 *  \endif
*/
@property (nonatomic, strong) NvViewTheme *fontCellTheme;
@property (nonatomic, strong) NvViewTheme *fontCellSelectedTheme;

/*! \if ENGLISH
 *
 *  \brief Color style
 *  \else
 *
 *  \brief 颜色样式
 *  \endif
*/
@property (nonatomic, strong) NvViewTheme *colorCellTheme;
@property (nonatomic, strong) NvViewTheme *colorCellSelectedTheme;

@end

NS_ASSUME_NONNULL_END
