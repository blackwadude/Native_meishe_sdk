//
//  NvAlbumConfig.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/3/18.
//

#import <Foundation/Foundation.h>
#import "NvViewTheme.h"

NS_ASSUME_NONNULL_BEGIN

/*! \if ENGLISH
 *
 *  \brief Album configuration
 *  \else
 *
 *  \brief 相册配置
 *  \endif
*/
@interface NvAlbumConfig : NSObject

/*! \if ENGLISH
 *
 *  \brief Custom UI collection
 *  \else
 *
 *  \brief 自定义UI合集
 *  \endif
*/
@property (nonatomic, strong) NSMutableDictionary <NSString *, NvViewTheme *>* customTheme;

/*! \if ENGLISH
 *
 *  \brief Album top TAB, All==0, Video==1, Pictures==2
 *  \else
 *
 *  \brief 相册顶部标签，全部==0、视频==1、图片==2
 *  \endif
*/
@property (nonatomic, assign) NSInteger type;

/*! \if ENGLISH
 *
 *  \brief The maximum number of materials for an album
 *  \else
 *
 *  \brief 相册可选最大素材数
 *  \endif
*/
@property (nonatomic, assign) NSInteger maxSelectCount;

/*! \if ENGLISH
 *
 *  \brief Whether to include AutoCut
 *  \else
 *  
 *  \brief 是否有一键成片功能
 *  \endif
*/
@property (nonatomic, assign) BOOL useAutoCut;

@end

NS_ASSUME_NONNULL_END
