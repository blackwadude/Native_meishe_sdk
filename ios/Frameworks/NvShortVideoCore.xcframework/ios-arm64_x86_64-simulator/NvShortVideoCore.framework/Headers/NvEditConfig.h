//
//  NvEditConfig.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/3/18.
//

#import <Foundation/Foundation.h>
#import "NvCompileConfig.h"
#import "NvViewTheme.h"
#import "NvBubbleConfig.h"

NS_ASSUME_NONNULL_BEGIN


/*! \if ENGLISH
 *
 *  \brief Right-hand menu
 *  \else
 *
 *  \brief 右侧菜单
 *  \endif
*/
typedef NSString * NvEditMenuItem NS_STRING_ENUM;
FOUNDATION_EXPORT NvEditMenuItem const NvEditMenuItemRelease;   //!< \if ENGLISH Release \else 发布 \endif
FOUNDATION_EXPORT NvEditMenuItem const NvEditMenuItemDownload;  //!< \if ENGLISH Save \else 保存 \endif
FOUNDATION_EXPORT NvEditMenuItem const NvEditMenuItemEdit;      //!< \if ENGLISH Edit \else 裁剪 \endif
FOUNDATION_EXPORT NvEditMenuItem const NvEditMenuItemText;      //!< \if ENGLISH Text \else 文字 \endif
FOUNDATION_EXPORT NvEditMenuItem const NvEditMenuItemSticker;   //!< \if ENGLISH Sticker \else 贴纸 \endif
FOUNDATION_EXPORT NvEditMenuItem const NvEditMenuItemEffect;    //!< \if ENGLISH Effect \else 特效 \endif
FOUNDATION_EXPORT NvEditMenuItem const NvEditMenuItemFilter;    //!< \if ENGLISH Filter \else 滤镜 \endif
FOUNDATION_EXPORT NvEditMenuItem const NvEditMenuItemCaption;      //!< \if ENGLISH Caption \else 字幕 \endif
FOUNDATION_EXPORT NvEditMenuItem const NvEditMenuItemAudio;     //!< \if ENGLISH Audio \else 音效 \endif
FOUNDATION_EXPORT NvEditMenuItem const NvEditMenuItemRecord;    //!< \if ENGLISH Record \else 录音 \endif



typedef NS_OPTIONS(NSInteger, NvEditMode) {
    NvEditMode9v16  = 1,
    NvEditMode16v9  = 1 << 1,
    NvEditMode3v4   = 1 << 2,
    NvEditMode4v3   = 1 << 3,
    NvEditMode1v1   = 1 << 4,
    NvEditMode18v9  = 1 << 5,
    NvEditMode9v18  = 1 << 6,
    NvEditMode8v9   = 1 << 7,
    NvEditMode9v8   = 1 << 8
};

/*! \if ENGLISH
 *
 *  \brief caption style
 *  \else
 *
 *  \brief 字幕样式
 *  \endif
*/
typedef NS_ENUM(NSInteger, NvImageCaptionStyle) {
    NvImageCaptionStyleNone    = 1,        //!< \if ENGLISH None \else 无 \endif
    NvImageCaptionStyleBg      = 1 << 1,   //!< \if ENGLISH Text background \else 文字背景 \endif
    NvImageCaptionStyleBgAlpha = 1 << 2,   //!< \if ENGLISH Text background with transparency \else 文字背景带透明度 \endif
    NvImageCaptionStyleOutline = 1 << 3    //!< \if ENGLISH Text stroke \else 文字描边 \endif
};


/*! \if ENGLISH
 *
 *  \brief Frame scale calculation method
 *  \else
 *
 *  \brief 编辑画幅比例计算方式
 *  \endif
*/
typedef NS_ENUM(NSInteger, NvEditModeSource) {
    NvEditModeSourceFixed,      //!< \if ENGLISH Fixed \else 画幅比例固定 \endif
    NvEditModeSourceFirstAsset  //!< \if ENGLISH The scale is determined by the first material \else 画幅比例由第一个素材确定 \endif
};

/*! \if ENGLISH
 *
 *  \brief Edit configuration
 *  \else
 *
 *  \brief 编辑配置
 *  \endif
*/
@interface NvEditConfig : NSObject

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
 *  \brief Right side menu (orderly)
 *  \else
 *
 *  \brief 右侧菜单 （有序）
 *  \endif
*/
@property (nonatomic, strong) NSArray <NvEditMenuItem>* editMenuItems;

/*! \if ENGLISH
 *
 *  \brief Edit preview resolution
 *  Refer to NvVideoPreviewResolution
 *  \else
 *
 *  \brief 编辑预览分辨率
 *  参考NvVideoPreviewResolution
 *  \endif
*/
@property (nonatomic, assign) NvVideoPreviewResolution resolution;

/*! \if ENGLISH
 *
 *  \brief Preview fps
 *  Default 25
 *  \else
 *
 *  \brief 预览fps
 *  默认25
 *  \endif
*/
@property (nonatomic, assign) int fps;

/*! \if ENGLISH
 *
 *  \brief Minimum effect duration (milliseconds)
 *  Default 500ms
 *  \else
 *
 *  \brief 最小特效时长（毫秒）
 *  默认500ms
 *  \endif
*/
@property (nonatomic, assign) int64_t minEffectDuration;

/*! \if ENGLISH
 *
 *  \brief Minimum recording duration (ms)
 *  Default1000ms
 *  \else
 *
 *  \brief 最小录音时长（毫秒）
 *  默认1000ms
 *  \endif
*/
@property (nonatomic, assign) int64_t minAudioDuration;

/*! \if ENGLISH
 *
 *  \brief Default title color
 *  Default white
 *  \else
 *
 *  \brief 默认字幕颜色
 *  默认白色
 *  \endif
*/
@property (nonatomic, strong) NSString *captionColor;

/*! \if ENGLISH
 *
 *  \brief Caption color list (ordered)
 *  \else
 *
 *  \brief 字幕颜色列表（有序）
 *  \endif
*/
@property (nonatomic, strong) NSArray <NSString *>* captionColorList;

/*! \if ENGLISH
 *
 *  \brief Supported title styles (out of order)
 *  \else
 *
 *  \brief 支持的字幕样式（无序）
 *  \endif
*/
@property (nonatomic, assign) NSInteger supportedCaptionStyles;

/*! \if ENGLISH
 *
 *  \brief Scale mode
 *  Refer to NvEditModeSource
 *  \else
 *
 *  \brief 画幅比例模式
 *  参考NvEditModeSource
 *  \endif
*/
@property (nonatomic, assign) NvEditModeSource editModeSource;

/*! \if ENGLISH
 *
 *  \brief Fixed frame scale
 *  Refer to NvEditMode
 *  NvEditMode9v16==1
 *  NvEditMode16v9==2
 *  NvEditMode3v4==4
 *  NvEditMode4v3==8
 *  NvEditMode1v1==16
 *  NvEditMode18v9==32
 *  NvEditMode9v18==64
 *  NvEditMode8v9==128
 *  NvEditMode9v8==256
 *  \else
 *
 *  \brief 固定画幅比例
 *  参考NvEditMode
 *  NvEditMode9v16==1
 *  NvEditMode16v9==2
 *  NvEditMode3v4==4
 *  NvEditMode4v3==8
 *  NvEditMode1v1==16
 *  NvEditMode18v9==32
 *  NvEditMode9v18==64
 *  NvEditMode8v9==128
 *  NvEditMode9v8==256
 *  \endif
*/
@property (nonatomic, assign) NvEditMode editMode;

/*! \if ENGLISH
 *
 *  \brief Supported frame ratio
 *  Refer to NvEditMode
 *  \else
 *
 *  \brief 支持的画幅比例
 *  参考NvEditMode
 *  \endif
*/
@property (nonatomic, assign) NvEditMode supportedEditModes;

/*! \if ENGLISH
 *
 *  \brief Bubble configuration
 *  \else
 *
 *  \brief 气泡配置
 *  \endif
*/
@property (nonatomic, strong) NvBubbleConfig *bubbleConfig;

/*! \if ENGLISH
 *
 *  \brief Filter default value
 *  Default 0.8
 *  \else
 *
 *  \brief 滤镜默认值
 *  默认0.8
 *  \endif
*/
@property (nonatomic, assign) CGFloat filterDefaultValue;

/*! \if ENGLISH
 *
 *  \brief Maximum volume, [0-8]
 *  Default 4
 *  \else
 *
 *  \brief 最大音量， [0-8]
 *  默认 4
 *  \endif
*/
@property (nonatomic, assign) float maxVolume;

@end

NS_ASSUME_NONNULL_END
