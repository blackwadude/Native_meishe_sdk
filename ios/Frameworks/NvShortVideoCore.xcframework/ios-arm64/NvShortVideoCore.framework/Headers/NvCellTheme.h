//
//  NvCellTheme.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/3/18.
//

#import "NvViewTheme.h"
#import "NvLabelTheme.h"

NS_ASSUME_NONNULL_BEGIN

/*! \if ENGLISH
 *
 *  \brief CellTheme Configuration item
 *  \else
 *
 *  \brief CellTheme配置项
 *  \endif
*/
@interface NvCellTheme : NvViewTheme

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
 *  \brief line
 *  \else
 *
 *  \brief 线
 *  \endif
*/
@property (nonatomic, strong) NvViewTheme *lineView;

/*! \if ENGLISH
 *
 *  \brief Pass in a new object and superimpose the current object
 *  \param theme NvCellTheme
 *  \else
 *
 *  \brief 传入一个新的对象，叠加当前对象
 *  \param theme NvCellTheme
 *  \endif
*/

- (void)addTheme:(NvCellTheme *)theme;

@end

NS_ASSUME_NONNULL_END
