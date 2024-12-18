//
//  NvCaptureConfig.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/3/18.
//

#import <Foundation/Foundation.h>
#import "NvDualConfig.h"
#import "NvBeautyConfig.h"
#import "NvCompileConfig.h"
#import "NvViewTheme.h"

NS_ASSUME_NONNULL_BEGIN

/*! \if ENGLISH
 *
 *  \brief Duration(in microseconds)
 *  \else
 *
 *  \brief 时长(单位毫秒)
 *  \endif
*/
@interface NvTimePair : NSObject

/*! \if ENGLISH
 *
 *  \brief min Duration(in microseconds)
 *  \else
 *
 *  \brief 最小时长(单位毫秒)
 *  \endif
*/
@property(nonatomic, assign) int64_t minDuration;

/*! \if ENGLISH
 *
 *  \brief max Duration(in microseconds)
 *  \else
 *
 *  \brief 最大时长(单位毫秒)
 *  \endif
*/
@property(nonatomic, assign) int64_t maxDuration;

@end

/*! \if ENGLISH
 *
 *  \brief Right-hand menu
 *  \else
 *
 *  \brief 右侧菜单
 *  \endif
*/
typedef NSString * NvCaptureMenuItem NS_STRING_ENUM;
FOUNDATION_EXPORT NvCaptureMenuItem const NvCaptureMenuItemDevice;      //!< \if ENGLISH Flip camera \else 翻转摄像头\endif
FOUNDATION_EXPORT NvCaptureMenuItem const NvCaptureMenuItemSpeed;       //!< \if ENGLISH Speed \else 快慢速\endif
FOUNDATION_EXPORT NvCaptureMenuItem const NvCaptureMenuItemTimer;       //!< \if ENGLISH Countdown \else 倒计时 \endif
FOUNDATION_EXPORT NvCaptureMenuItem const NvCaptureMenuItemBeauty;      //!< \if ENGLISH Beauty \else 美颜 \endif
FOUNDATION_EXPORT NvCaptureMenuItem const NvCaptureMenuItemMakeup;      //!< \if ENGLISH Makeup \else 美妆 \endif
FOUNDATION_EXPORT NvCaptureMenuItem const NvCaptureMenuItemProp;        //!< \if ENGLISH Face prop \else 人脸道具 \endif
FOUNDATION_EXPORT NvCaptureMenuItem const NvCaptureMenuItemFlashlight;  //!< \if ENGLISH Flashlight \else 闪光灯 \endif
FOUNDATION_EXPORT NvCaptureMenuItem const NvCaptureMenuItemFilter;      //!< \if ENGLISH Filter \else 滤镜 \endif
FOUNDATION_EXPORT NvCaptureMenuItem const NvCaptureMenuItemOriginal;    //!< \if ENGLISH Original sound \else 原声 \endif
FOUNDATION_EXPORT NvCaptureMenuItem const NvCaptureMenuItemDualType;    //!< \if ENGLISH Dual type \else 合拍样式 \endif
    

/*! \if ENGLISH
 *
 *  \brief Bottom menu
 *  \else
 *
 *  \brief 底部菜单
 *  \endif
*/
typedef NSString * NvCaptureBottomMenuItem NS_STRING_ENUM;
FOUNDATION_EXPORT NvCaptureBottomMenuItem const NvCaptureBottomMenuItemImage;       //!< \if ENGLISH Photo \else 拍照 \endif
FOUNDATION_EXPORT NvCaptureBottomMenuItem const NvCaptureBottomMenuItemVideo;       //!< \if ENGLISH Record \else 录制 \endif
FOUNDATION_EXPORT NvCaptureBottomMenuItem const NvCaptureBottomMenuItemSmart;       //!< \if ENGLISH Smart record \else 快拍 \endif
FOUNDATION_EXPORT NvCaptureBottomMenuItem const NvCaptureBottomMenuItemTemplate;    //!< \if ENGLISH Template \else 模版 \endif
 
/*! \if ENGLISH
 *
 *  \brief Shooting configuration
 *  \else
 *
 *  \brief 拍摄配置项
 *  \endif
*/
@interface NvCaptureConfig : NSObject

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
 *  \brief Shoot right menu (array ordered)
 *  Refer to NvCaptureMenuItem
 *  \else
 *
 *  \brief 拍摄右侧菜单 （数组有序）
 *  参考NvCaptureMenuItem
 *  \endif
*/
@property (nonatomic, strong) NSArray <NvCaptureMenuItem>* captureMenuItems;

/*! \if ENGLISH
 *
 *  \brief Shoot the bottom menu (array ordered, templates placed last)
 *  Refer to NvCaptureBottomMenuItem
 *  \else
 *
 *  \brief 拍摄底部菜单 （数组有序，模版放最后）
 *  参考NvCaptureBottomMenuItem
 *  \endif
*/
@property (nonatomic, strong) NSArray <NvCaptureBottomMenuItem>* captureBottomMenuItems;

/*! \if ENGLISH
 *
 *  \brief Default front camera
 *  0==Rear camera，1==Front camera
 *  \else
 *
 *  \brief 默认前置摄像头
 *  0==后置，1==前置
 *  \endif
*/
@property (nonatomic, assign) unsigned int captureDeviceIndex;

/*! \if ENGLISH
 *
 *  \brief Shooting resolution
 *  Refer to NvVideoPreviewResolution
 *  \else
 *
 *  \brief 拍摄分辨率
 *  参考NvVideoPreviewResolution
 *  \endif
*/
@property (nonatomic, assign) NvVideoPreviewResolution resolution;

/*! \if ENGLISH
 *
 *  \brief Ignore device rotation
 *  \else
 *
 *  \brief 忽略设备旋转
 *  \endif
*/
@property(nonatomic, assign) BOOL ignoreVideoRotation;

/*! \if ENGLISH
 *
 *  \brief Photo duration Settings (milliseconds)
 *  \else
 *
 *  \brief 拍照时长设置（毫秒）
 *  \endif
*/
@property(nonatomic, assign) int64_t imageDuration;

/*! \if ENGLISH
 *
 *  \brief Taken photos, before entering editing, whether to save to album
 *  false==Don't save，true==save
 *  \else
 *
 *  \brief 拍摄的照片，进入编辑之前，是否保存到相册
 *  false==不保存，true==保存
 *  \endif
*/
@property(nonatomic, assign) BOOL autoSavePhotograph;

/*! \if ENGLISH
 *
 *  \brief
 *  \else
 *
 *  \brief 录制时长设置
 *  参考NvTimePair
 *  \endif
*/
@property(nonatomic, strong) NSArray<NvTimePair *> *timeRanges;

/*! \if ENGLISH
 *
 *  \brief smart setting
 *  Refer to NvTimePair
 *  \else
 *
 *  \brief 快拍设置
 *  参考NvTimePair
 *  \endif
*/
@property(nonatomic, strong) NvTimePair *smartTimeRange;

/*! \if ENGLISH
 *
 *  \brief Beauty configuration item
 *  Refer to NvBeautyConfig
 *  \else
 *
 *  \brief 美颜配置项
 *  参考NvBeautyConfig
 *  \endif
*/
@property(nonatomic, strong) NvBeautyConfig *beautyConfig;

/*! \if ENGLISH
 *
 *  \brief Click right menu (orderly)
 *  \else
 *
 *  \brief 合拍右侧菜单（有序）
 *  \endif
*/
@property (nonatomic, strong) NSArray <NvCaptureMenuItem>* dualMenuItems;

/*! \if ENGLISH
 *
 *  \brief PIP setting
 *  Refer to NvDualConfig
 *  \else
 *
 *  \brief 合拍设置
 *  参考NvDualConfig
 *  \endif
*/
@property(nonatomic, strong) NvDualConfig *dualConfig;

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
 *  \brief The Capture page shows the album button
 *  \else
 *
 *  \brief 拍摄页显示相册按钮
 *  \endif
*/
@property (nonatomic, assign) BOOL enableCaptureAlbum;

/*! \if ENGLISH
 *
 *  \brief Automatically disables the soundtrack
 *  \else
 *
 *  \brief 自动禁掉原声
 *  \endif
*/
@property (nonatomic, assign) BOOL autoDisablesMic;

@end

NS_ASSUME_NONNULL_END
