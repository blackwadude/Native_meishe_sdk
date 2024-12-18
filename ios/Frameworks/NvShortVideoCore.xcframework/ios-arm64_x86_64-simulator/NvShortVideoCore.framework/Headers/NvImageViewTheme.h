//
//  NvImageViewTheme.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/3/25.
//

#import "NvLabelTheme.h"

NS_ASSUME_NONNULL_BEGIN

/*! \if ENGLISH
 *
 *  \brief ImageView Configuration item
 *  \else
 *
 *  \brief ImageView配置项
 *  \endif
*/
@interface NvImageViewTheme : NvViewTheme

/*! \if ENGLISH
 *
 *  \brief Image name
 *  \else
 *
 *  \brief 图片名称
 *  \endif
*/
@property (nonatomic, strong) NSString *imageName;

/*! \if ENGLISH
 *
 *  \brief animation file
 *  \else
 *
 *  \brief 动画文件
 *  \endif
*/
@property (nonatomic, strong) NSString *animatedFilePath;

/*! \if ENGLISH
 *
 *  \brief Pass in a new object and superimpose the current object
 *  \param theme NvImageViewTheme
 *  \else
 *
 *  \brief 传入一个新的对象，叠加当前对象
 *  \param theme NvImageViewTheme
 *  \endif
*/
- (void)addTheme:(NvViewTheme *)theme;

@end

NS_ASSUME_NONNULL_END
