//
//  NvRecognitionEditCellTheme.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/5/23.
//

#import "NvCellTheme.h"
#import "NvButtonTheme.h"

NS_ASSUME_NONNULL_BEGIN

/*! \if ENGLISH
 *
 *  \brief Automatic captioning text editing configuration item
 *  \else
 *
 *  \brief 自动字幕文字编辑配置项
 *  \endif
*/
@interface NvRecognitionEditCellTheme : NvCellTheme

/*! \if ENGLISH
 *
 *  \brief Play button style
 *  \else
 *
 *  \brief 播放按钮样式
 *  \endif
*/
@property (nonatomic, strong) NvButtonTheme *playBtTheme;

@end

NS_ASSUME_NONNULL_END
