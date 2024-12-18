//
//  NvMusicCellTheme.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/3/25.
//

#import "NvCellTheme.h"
#import "NvLabelTheme.h"
#import "NvButtonTheme.h"
#import "NvImageViewTheme.h"

NS_ASSUME_NONNULL_BEGIN

/*! \if ENGLISH
 *
 *  \brief MusicCellTheme Configuration item
 *  \else
 *
 *  \brief MusicCellTheme配置项
 *  \endif
*/
@interface NvMusicCellTheme : NvCellTheme

/*! \if ENGLISH
 *
 *  \brief Image styles and default images
 *  \else
 *
 *  \brief 图片样式及默认图
 *  \endif
*/
@property (nonatomic, strong) NvImageViewTheme *imageView;

/*! \if ENGLISH
 *
 *  \brief Crop button style
 *  \else
 *
 *  \brief 裁剪按钮样式
 *  \endif
*/
@property (nonatomic, strong) NvButtonTheme *cutBt;

/*! \if ENGLISH
 *
 *  \brief Description text style
 *  \else
 *
 *  \brief 描述文本样式
 *  \endif
*/
@property (nonatomic, strong) NvLabelTheme *desLabel;

/*! \if ENGLISH
 *
 *  \brief Time text style
 *  \else
 *
 *  \brief 时间文本样式
 *  \endif
*/
@property (nonatomic, strong) NvLabelTheme *timeLabel;

/*! \if ENGLISH
 *
 *  \brief Download the gif file path
 *  \else
 *
 *  \brief 下载中gif文件路径
 *  \endif
*/
@property (nonatomic, strong) NSString *loadingAnimatedFilePath;

@end

NS_ASSUME_NONNULL_END
