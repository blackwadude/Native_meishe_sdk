//
//  NvMaterialCellTheme.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/3/27.
//

#import "NvCellTheme.h"
#import "NvImageViewTheme.h"

NS_ASSUME_NONNULL_BEGIN

/*! \if ENGLISH
 *
 *  \brief MaterialCellTheme Configuration item
 *  \else
 *
 *  \brief MaterialCellTheme配置项
 *  \endif
*/
@interface NvMaterialCellTheme : NvCellTheme

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
 *  \brief Download button icon
 *  \else
 *
 *  \brief 下载按钮图标
 *  \endif
*/
@property (nonatomic, strong) NSString *downloadImageName;

/*! \if ENGLISH
 *
 *  \brief Download animation file
 *  \else
 *
 *  \brief 下载动画文件
 *  \endif
*/
@property (nonatomic, strong) NSString *loadingAnimatedFilePath;

@end

NS_ASSUME_NONNULL_END
