//
//  NvBeautyConfig.h
//  NvShortVideoCore
//
//  Created by ms20221114 on 2024/2/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*! \if ENGLISH
 *  \brief Beauty classification
 *  \else
 *  \brief 美颜分类
 *  \endif
*/
typedef NSString * NvBeautyCategorical NS_STRING_ENUM;
/// 美肤 NvBeauty
FOUNDATION_EXPORT NvBeautyCategorical const NvBeautyCategoricalSkin;
/// 美型 Shape
FOUNDATION_EXPORT NvBeautyCategorical const NvBeautyCategoricalShape;
/// 微整形 MicroShape
FOUNDATION_EXPORT NvBeautyCategorical const NvBeautyCategoricalMicroShape;
/// 调节 Adjust
FOUNDATION_EXPORT NvBeautyCategorical const NvBeautyCategoricalAdjust;

/*! \if ENGLISH
 *  \brief Beauty Adjustment item
 *  \else
 *  \brief 美肤调节项
 *  \endif
*/
typedef NSString * NvBeautyEffect NS_STRING_ENUM;
/// 标准磨皮 Standard
FOUNDATION_EXPORT NvBeautyEffect const NvBeautyEffectStandard;
/// 水光磨皮 Shiny
FOUNDATION_EXPORT NvBeautyEffect const NvBeautyEffectShiny;
/// 自然磨皮 Natural
FOUNDATION_EXPORT NvBeautyEffect const NvBeautyEffectNatural;
/// 质感磨皮 Luxurious
FOUNDATION_EXPORT NvBeautyEffect const NvBeautyEffectLuxurious;
/// 冷白 CoolWhite
FOUNDATION_EXPORT NvBeautyEffect const NvBeautyEffectCoolWhite;
/// 粉白 PinkyWhite
FOUNDATION_EXPORT NvBeautyEffect const NvBeautyEffectPinkyWhite;
/// 暖白 WarmWhite
FOUNDATION_EXPORT NvBeautyEffect const NvBeautyEffectWarmWhite;
/// 美黑 Tanning
FOUNDATION_EXPORT NvBeautyEffect const NvBeautyEffectTanning;
/// 美白A WhiteA
FOUNDATION_EXPORT NvBeautyEffect const NvBeautyEffectWhiteA;
/// 美白B WhiteB
FOUNDATION_EXPORT NvBeautyEffect const NvBeautyEffectWhiteB;
/// 去油光 Oiliness
FOUNDATION_EXPORT NvBeautyEffect const NvBeautyEffectOiliness;
/// 红润 Rosy
FOUNDATION_EXPORT NvBeautyEffect const NvBeautyEffectRosy;

/*! \if ENGLISH
 *  \brief Shape Adjustment item
 *  \else
 *  \brief 美型调节项
 *  \endif
*/
typedef NSString * NvBeautyShape NS_STRING_ENUM;
/// 窄脸 Narrow
FOUNDATION_EXPORT NvBeautyShape const NvBeautyShapeNarrow;
/// 小脸 Lower_Jaw
FOUNDATION_EXPORT NvBeautyShape const NvBeautyShapeLowerJaw;
/// 瘦脸 Lessen
FOUNDATION_EXPORT NvBeautyShape const NvBeautyShapeLessen;
/// 额头 Forehead
FOUNDATION_EXPORT NvBeautyShape const NvBeautyShapeForehead;
/// 下巴 Chin
FOUNDATION_EXPORT NvBeautyShape const NvBeautyShapeChin;
/// 大眼 Eyes_Size
FOUNDATION_EXPORT NvBeautyShape const NvBeautyShapeEyesSize;
/// 眼角 Eyes_Coner
FOUNDATION_EXPORT NvBeautyShape const NvBeautyShapeEyesConer;
/// 瘦鼻 Nose_Ala
FOUNDATION_EXPORT NvBeautyShape const NvBeautyShapeNoseAla;
/// 长鼻 Nose_Length
FOUNDATION_EXPORT NvBeautyShape const NvBeautyShapeNoseLength;
/// 嘴型 Lip_Height
FOUNDATION_EXPORT NvBeautyShape const NvBeautyShapeLipHeight;
/// 嘴角 Lip_Width
FOUNDATION_EXPORT NvBeautyShape const NvBeautyShapeLipWidth;

/*! \if ENGLISH
 *  \brief MicroShape Adjustment item
 *  \else
 *  \brief 微整形调节项
 *  \endif
*/
typedef NSString * NvBeautyMicroShape NS_STRING_ENUM;
/// 缩头 Head
FOUNDATION_EXPORT NvBeautyMicroShape const NvBeautyMicroShapeHead;
/// 亮眼 Eyes_Brighten
FOUNDATION_EXPORT NvBeautyMicroShape const NvBeautyMicroShapeEyesBrighten;
/// 法令纹 Nasolabial_Folds
FOUNDATION_EXPORT NvBeautyMicroShape const NvBeautyMicroShapeNasolabialFolds;
/// 黑眼圈 Black_Circle
FOUNDATION_EXPORT NvBeautyMicroShape const NvBeautyMicroShapeBlackCircle;
/// 美牙 Whiten_Teeth
FOUNDATION_EXPORT NvBeautyMicroShape const NvBeautyMicroShapeWhitenTeeth;
/// 颧骨 Cheek_bones
FOUNDATION_EXPORT NvBeautyMicroShape const NvBeautyMicroShapeCheekBones;
/// 下颌 Chin_Length
FOUNDATION_EXPORT NvBeautyMicroShape const NvBeautyMicroShapeChinLength;
/// 太阳穴 Temple
FOUNDATION_EXPORT NvBeautyMicroShape const NvBeautyMicroShapeTemple;
/// 眼角 Eyes_Coner
FOUNDATION_EXPORT NvBeautyMicroShape const NvBeautyMicroShapeEyesConer;
/// 眼距 Eyes_Distance
FOUNDATION_EXPORT NvBeautyMicroShape const NvBeautyMicroShapeEyesDistance;
/// 人中 Philtrum
FOUNDATION_EXPORT NvBeautyMicroShape const NvBeautyMicroShapePhiltrum;
/// 鼻梁 Nose_Root
FOUNDATION_EXPORT NvBeautyMicroShape const NvBeautyMicroShapeNoseRoot;
/// 眉粗细 Eyebrow_Size
FOUNDATION_EXPORT NvBeautyMicroShape const NvBeautyMicroShapeEyebrowSize;
/// 眉上下 Eyebrow_Height
FOUNDATION_EXPORT NvBeautyMicroShape const NvBeautyMicroShapeEyebrowHeight;
/// 眉间距 Eyebrow_Distance
FOUNDATION_EXPORT NvBeautyMicroShape const NvBeautyMicroShapeEyebrowDistance;
/// 眉角度 Eyebrow_Slant
FOUNDATION_EXPORT NvBeautyMicroShape const NvBeautyMicroShapeEyebrowSlant;
/// 眼弧度 Lower_Eyelid
FOUNDATION_EXPORT NvBeautyMicroShape const NvBeautyMicroShapeLowerEyelid;
/// 眼宽度 Eyes_Length
FOUNDATION_EXPORT NvBeautyMicroShape const NvBeautyMicroShapeEyesLength;
/// 眼高度 Eyes_Enlarge
FOUNDATION_EXPORT NvBeautyMicroShape const NvBeautyMicroShapeEyesEnlarge;
/// 眼上下 Eyes_Height
FOUNDATION_EXPORT NvBeautyMicroShape const NvBeautyMicroShapeEyesHeight;
/// 鼻头 Nose_Tip
FOUNDATION_EXPORT NvBeautyMicroShape const NvBeautyMicroShapeNoseTip;

/*! \if ENGLISH
 *  \brief Adjust Functional  Adjustment item
 *  \else
 *  \brief 调节功能调节项
 *  \endif
*/
typedef NSString * NvBeautyAdjust NS_STRING_ENUM;
/// 校色 Tone
FOUNDATION_EXPORT NvBeautyAdjust const NvBeautyAdjustTone;
/// 锐度 Firm
FOUNDATION_EXPORT NvBeautyAdjust const NvBeautyAdjustFirm;
/// 清晰度 Articulation
FOUNDATION_EXPORT NvBeautyAdjust const NvBeautyAdjustArticulation;

/*! \if ENGLISH
 *
 *  \brief Beauty config
 *  \else
 *
 *  \brief 美颜配置项
 *  \endif
*/
@interface NvBeautyConfig : NSObject

/*! \if ENGLISH
 *
 *  \brief Beauty functional
 *  Refer to NvBeautyCategorical
 *  \else
 *
 *  \brief 美颜功能
 *  参考NvBeautyCategorical
 *  \endif
*/
@property (nonatomic, strong) NSArray <NvBeautyCategorical>*categoricalArray;

/*! \if ENGLISH
 *
 *  \brief Beauty functional
 *  Refer to NvBeautyEffect
 *  \else
 *
 *  \brief 美肤功能
 *  参考NvBeautyEffect
 *  \endif
*/
@property (nonatomic, strong) NSArray <NvBeautyEffect>*beautyEffectArray;

/*! \if ENGLISH
 *
 *  \brief Shape functional
 *  Refer to NvBeautyShape
 *  \else
 *
 *  \brief 美型功能
 *  参考NvBeautyShape
 *  \endif
*/
@property (nonatomic, strong) NSArray <NvBeautyShape>*beautyShapeArray;

/*! \if ENGLISH
 *
 *  \brief MicroShape functional
 *  Refer to NvBeautyMicroShape
 *  \else
 *
 *  \brief 微整形功能
 *  参考NvBeautyMicroShape
 *  \endif
*/
@property (nonatomic, strong) NSArray <NvBeautyMicroShape>*beautyMicroShapeArray;

/*! \if ENGLISH
 *
 *  \brief Adjust functional
 *  Refer to NvBeautyAdjust
 *  \else
 *
 *  \brief 调节功能
 *  参考NvBeautyAdjust
 *  \endif
*/
@property (nonatomic, strong) NSArray <NvBeautyAdjust>*beautyAdjustArray;

@end

NS_ASSUME_NONNULL_END
