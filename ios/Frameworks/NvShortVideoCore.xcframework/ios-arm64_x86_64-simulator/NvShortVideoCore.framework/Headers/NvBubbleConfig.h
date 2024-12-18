//
//  NvBubbleConfig.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/3/28.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "NvLabelTheme.h"

NS_ASSUME_NONNULL_BEGIN

/*! \if ENGLISH
 *
 *  \brief Bubble background blur style
 *  \else
 *
 *  \brief 气泡背景模糊样式
 *  \endif
*/
typedef NS_ENUM(NSInteger, NvBubbleBgBlurStyle) {
    NvBubbleBgBlurStyleNone = 0, //!< \if ENGLISH None \else 无模糊 \endif
    NvBubbleBgBlurStyleLight = 1, //!< \if Light \else 白色模糊 \endif
    NvBubbleBgBlurStyleDark = 2 //!< \if Dark \else 黑色模糊 \endif
};

/*! \if ENGLISH
 *
 *  \brief Bubble configuration
 *  \else
 *
 *  \brief 气泡配置
 *  \endif
*/
@interface NvBubbleConfig : NSObject

/*! \if ENGLISH
 *
 *  \brief Edit icon
 *  \else
 *
 *  \brief 编辑图标
 *  \endif
*/
@property (nonatomic, strong) NSString *editImageName;

/*! \if ENGLISH
 *
 *  \brief Duration icon
 *  \else
 *
 *  \brief 时长图标
 *  \endif
*/
@property (nonatomic, strong) NSString *durationImageName;

/*! \if ENGLISH
 *
 *  \brief
 *  \else
 *
 *  \brief 文字样式
 *  \endif
*/
@property (nonatomic, strong) NvLabelTheme *titleTheme;

/*! \if ENGLISH
 *
 *  \brief Text style
 *  \else
 *
 *  \brief 背景色（无模糊时的）
 *  \endif
*/
@property (nonatomic, strong) UIColor *backgroundColor;

/*! \if ENGLISH
 *
 *  \brief Background mode
 *  \else
 *
 *  \brief 背景模式
 *  \endif
*/
@property (nonatomic, assign) NvBubbleBgBlurStyle backgroundBlurStyle;

@end

NS_ASSUME_NONNULL_END
