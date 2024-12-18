//
//  NvVideoConfig.h
//  NvShortVideoCore
//
//  Created by meishe on 2023/9/12.
//

#import <Foundation/Foundation.h>
#import "NvCaptureConfig.h"
#import "NvEditConfig.h"
#import "NvAlbumConfig.h"
#import "NvCompileConfig.h"
#import "NvTemplateConfig.h"
#import "NvModelConfig.h"

NS_ASSUME_NONNULL_BEGIN

/*! \if ENGLISH
 *
 *  \brief Project configuration item
 *  \else
 *
 *  \brief 工程配置项
 *  \endif
*/
@interface NvVideoConfig : NSObject

/*! \if ENGLISH
 *
 *  \brief primary Color
 *  \else
 *
 *  \brief 主色调
 *  \endif
*/
@property (nonatomic, strong) UIColor *primaryColor;

/*! \if ENGLISH
 *
 *  \brief backgroundColor
 *  \else
 *
 *  \brief 背景色
 *  \endif
*/
@property (nonatomic, strong) UIColor *backgroundColor;

/*! \if ENGLISH
 *
 *  \brief panel Color
 *  \else
 *
 *  \brief 面板色
 *  \endif
*/
@property (nonatomic, strong) UIColor *panelBackgroundColor;

/*! \if ENGLISH
 *
 *  \brief text Color
 *  \else
 *
 *  \brief 文字颜色
 *  \endif
*/
@property (nonatomic, strong) UIColor *textColor;

/*! \if ENGLISH
 *
 *  \brief secondary Text Color
 *  \else
 *
 *  \brief 二级文字颜色
 *  \endif
*/
@property (nonatomic, strong) UIColor *secondaryTextColor;

/*! \if ENGLISH
 *
 *  \brief show the itunes music list
 *  \else
 *
 *  \brief 显示itunes 音乐列表
 *  \endif
*/
@property (nonatomic, assign) BOOL enableLocalMusic;

/*! \if ENGLISH
 *
 *  \brief album
 *  \else
 *
 *  \brief 相册
 *  \endif
*/
@property (nonatomic, strong) NvAlbumConfig *albumConfig;

/*! \if ENGLISH
 *
 *  \brief Capture
 *  \else
 *
 *  \brief 拍摄
 *  \endif
*/
@property (nonatomic, strong) NvCaptureConfig *captureConfig;

/*! \if ENGLISH
 *
 *  \brief edit
 *  \else
 *
 *  \brief 编辑
 *  \endif
*/
@property (nonatomic, strong) NvEditConfig *editConfig;

/*! \if ENGLISH
 *
 *  \brief compile
 *  \else
 *
 *  \brief 合成
 *  \endif
*/
@property (nonatomic, strong) NvCompileConfig *compileConfig;

/*! \if ENGLISH
 *
 *  \brief template
 *  \else
 *
 *  \brief 模版
 *  \endif
*/
@property (nonatomic, strong) NvTemplateConfig *templateConfig;

/*! \if ENGLISH
 *
 *  \brief Apply the required model file
 *  \else
 *  
 *  \brief 应用所需的模型文件
 *  \endif
*/
@property (nonatomic, strong) NvModelConfig *modelConfig;

@end

NS_ASSUME_NONNULL_END
