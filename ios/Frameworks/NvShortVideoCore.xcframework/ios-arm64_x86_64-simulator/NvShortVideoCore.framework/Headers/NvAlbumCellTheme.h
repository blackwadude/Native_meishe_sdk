//
//  NvAlbumCellTheme.h
//  NvShortVideoCore
//
//  Created by ms20221114 on 2024/4/7.
//

#import "NvCellTheme.h"
#import "NvImageViewTheme.h"

NS_ASSUME_NONNULL_BEGIN

/*! \if ENGLISH
 *
 *  \brief AlbumCellTheme Configuration item
 *  \else
 *
 *  \brief AlbumCellTheme配置项
 *  \endif
*/
@interface NvAlbumCellTheme : NvCellTheme

/*! \if ENGLISH
 *
 *  \brief The icon in the lower right corner of the album material cell
 *  \else
 *
 *  \brief 相册素材cell的右下角图标
 *  \endif
*/
@property (nonatomic, strong) NvImageViewTheme *imageView;

/*! \if ENGLISH
 *
 *  \brief no Select the icon in the upper left corner of the album material cell
 *  \else
 *
 *  \brief 相册素材cell的左上角未选中图标
 *  \endif
*/
@property (nonatomic, strong) UIImage *normalImage;

/*! \if ENGLISH
 *
 *  \brief Select the icon in the upper left corner of the album material cell
 *  \else
 *  
 *  \brief 相册素材cell的左上角选中图标
 *  \endif
*/
@property (nonatomic, strong) UIImage *selectImage;

@end

NS_ASSUME_NONNULL_END
