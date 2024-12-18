//
//  NvTemplateConfig.h
//  NvShortVideoCore
//
//  Created by ms20221114 on 2024/3/25.
//

#import <Foundation/Foundation.h>
#import "NvViewTheme.h"

NS_ASSUME_NONNULL_BEGIN

/*! \if ENGLISH
 *
 *  \brief Template configuration
 *  \else
 *
 *  \brief 模版配置
 *  \endif
*/
@interface NvTemplateConfig : NSObject

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
 *  \brief Adaptive template、autoCut Maximum number of optional fragments
 *  \else
 *
 *  \brief 自适应模版、一键成片最大可选片段数量
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
