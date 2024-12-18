//
//  NvDualConfig.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/1/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


/*! \if ENGLISH
 *
 *  \brief Dual type
 *  \else
 *
 *  \brief 合拍样式
 *  \endif
*/
typedef NS_ENUM(NSInteger, NvDualType) {
    NvDualType_leftRight    = 1,
    NvDualType_topDown      = 1<<1,
    NvDualType_leftRect     = 1<<2,
    NvDualType_leftCircle   = 1<<3,
    NvDualType_topCircle    = 1<<4
};

/*! \if ENGLISH
 *
 *  \brief PIP Configuration item
 *  \else
 *
 *  \brief 合拍配置项
 *  \endif
*/

@interface NvDualConfig : NSObject

/*! \if ENGLISH
 *
 *  \brief The ratio of the small map to the left border and the width of the base map
 *  \else
 *
 *  \brief 小图距离 左边边界和底图宽度的比例
 *  \endif
*/
@property (nonatomic, assign) CGFloat left;

/*! \if ENGLISH
 *
 *  \brief The ratio of the small map to the height of the upper boundary and the bottom map
 *  \else
 *
 *  \brief 小图距离 上边边界和底图高度的比例
 *  \endif
*/
@property (nonatomic, assign) CGFloat top;

/*! \if ENGLISH
 *
 *  \brief The ratio between the width of the short edge and the width of the base
 *  \else
 *
 *  \brief 小图 短边和底图宽度的比例
 *  \endif
*/
@property (nonatomic, assign) CGFloat limitWidth;

/*! \if ENGLISH
 *
 *  \brief PIP with default style
 *  Refer to NvDualType
 *  NvDualType_leftRight==1
 *  NvDualType_topDown==2
 *  NvDualType_leftRect==4
 *  NvDualType_leftCircle==8
 *  NvDualType_topCircle==16
 *  \else
 *
 *  \brief 合拍默认样式
 *  参考NvDualType
 *  NvDualType_leftRight==1
 *  NvDualType_topDown==2
 *  NvDualType_leftRect==4
 *  NvDualType_leftCircle==8
 *  NvDualType_topCircle==16
 *  \endif
*/
@property (nonatomic, assign) NvDualType defaultType;

/*! \if ENGLISH
 *
 *  \brief Supported styles (in no order)
 *  Refer to NvDualType
 *  \else
 *
 *  \brief 支持的样式（没有顺序）
 *  参考NvDualType
 *  \endif
*/
@property (nonatomic, assign) NSUInteger supportedTypes;

/*! \if ENGLISH
 *
 *  \brief Automatically disables the soundtrack
 *  \else
 *
 *  \brief 自动禁掉原声
 *  \endif
*/
@property (nonatomic, assign) BOOL autoDisablesMic;

/*! \if ENGLISH
 *
 *  \brief Acoustic silence
 *  \else
 *
 *  \brief 默认关掉原声
 *  \endif
*/
@property (nonatomic, assign) BOOL muteOriginal;

@end

NS_ASSUME_NONNULL_END
