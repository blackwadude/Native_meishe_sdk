//
//  NvMusicSearchCellTheme.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/3/26.
//

#import "NvCellTheme.h"
#import "NvLabelTheme.h"
#import "NvButtonTheme.h"
#import "NvImageViewTheme.h"

NS_ASSUME_NONNULL_BEGIN

/*! \if ENGLISH
 *
 *  \brief MusicSearchCellTheme Configuration item
 *  \else
 *
 *  \brief MusicSearchCellTheme配置项
 *  \endif
*/

@interface NvMusicSearchCellTheme : NvCellTheme

/*! \if ENGLISH
 *
 *  \brief Left icon style
 *  \else
 *
 *  \brief 左侧图标样式
 *  \endif
*/
@property (nonatomic, strong) NvImageViewTheme *imageView;

/*! \if ENGLISH
 *
 *  \brief Remove button style
 *  \else
 *
 *  \brief 删除按钮样式
 *  \endif
*/
@property (nonatomic, strong) NvButtonTheme *deleteBt;

@end

NS_ASSUME_NONNULL_END
