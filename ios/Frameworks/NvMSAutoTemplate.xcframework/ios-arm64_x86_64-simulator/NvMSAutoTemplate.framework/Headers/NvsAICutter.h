//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2016. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Feb 18. 2022
//   Author:        Meishe video team
//================================================================================

#import <Foundation/Foundation.h>
#import <NvStreamingSdkCore/NvsObject.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(int, NvsAICutterLabelType) {
    NvsAICutterLabelTypePhoto = 0,               //!< \if ENGLISH Photo \else 照片 \endif
    NvsAICutterLabelTypeActivity = 1,            //!< \if ENGLISH Activity \else 活动 \endif
    NvsAICutterLabelTypePlaceL1 = 2,             //!< \if ENGLISH Place Level 1 \else 地点一级 \endif
    NvsAICutterLabelTypePlaceL2 = 3,             //!< \if ENGLISH Place Level 2 \else 地点二级 \endif
    NvsAICutterLabelTypeObjectL1 = 4,            //!< \if ENGLISH Object Level 1 \else 物体一级 \endif
    NvsAICutterLabelTypeObjectL2 = 5,            //!< \if ENGLISH Object Level 2 \else 物体二级 \endif
    NvsAICutterLabelTypeFace = 6,                //!< \if ENGLISH Face \else 面部 \endif
    NvsAICutterLabelTypeFaceRace = 7,            //!< \if ENGLISH Face Race \else 面部种族 \endif
    NvsAICutterLabelTypeFaceAge = 8,             //!< \if ENGLISH Face Age \else 面部年龄 \endif
    NvsAICutterLabelTypeFaceGender = 9,          //!< \if ENGLISH Face Gender \else 面部性别 \endif
    NvsAICutterLabelTypeDate = 10,               //!< \if ENGLISH Date \else 日期 \endif
    NvsAICutterLabelTypeDateCn = 11,             //!< \if ENGLISH Chinese Date \else 中国日期 \endif
    NvsAICutterLabelTypeSkyStatus = 12,          //!< \if ENGLISH Sky Status \else 天空状态 \endif
    NvsAICutterLabelTypeSkyWeather = 13,         //!< \if ENGLISH Sky Weather \else 天气 \endif
    NvsAICutterLabelTypeSkyRainbow = 14,         //!< \if ENGLISH Sky Rainbow \else 彩虹 \endif
    NvsAICutterLabelTypeSkyFirecloud = 15,       //!< \if ENGLISH Sky Firecloud \else 火烧云 \endif
    NvsAICutterLabelTypeSkyAirplanecloud = 16,   //!< \if ENGLISH Sky Airplane Cloud \else 飞机云 \endif
};

typedef NS_ENUM(int, NvsAICutterParamType) {
    NvsAICutterParamTypeDistanceThreshold = 0,                //!< \if ENGLISH Distance Threshold \else 距离阈值 \endif
    NvsAICutterParamTypeSkyRatioThreshold = 1,                //!< \if ENGLISH Sky Ratio Threshold \else 天空比例阈值 \endif
    NvsAICutterParamTypeSteerAngleThreshold = 2,              //!< \if ENGLISH Steer Angle Threshold \else 转向角阈值 \endif
    NvsAICutterParamTypeSteerAngleStableThreshold = 3,        //!< \if ENGLISH Steer Angle Stable Threshold \else 转向角稳定阈值 \endif
    NvsAICutterParamTypeSpeedThreshold = 4,                   //!< \if ENGLISH Speed Threshold \else 速度阈值 \endif
    NvsAICutterParamTypeARSpeedThreshold = 5,                 //!< \if ENGLISH AR Speed Threshold \else AR速度阈值 \endif
    NvsAICutterParamTypeARSteerAngleThreshold = 6,            //!< \if ENGLISH AR Steer Angle Threshold \else AR转向角阈值 \endif
    NvsAICutterParamTypeARAccelerationXThreshold = 7,         //!< \if ENGLISH AR Acceleration X Threshold \else AR加速度X阈值 \endif
    NvsAICutterParamTypeARAccelerationYThreshold = 8,         //!< \if ENGLISH AR Acceleration Y Threshold \else AR加速度Y阈值 \endif
    NvsAICutterParamTypeARAccelerationZThreshold = 9,         //!< \if ENGLISH AR Acceleration Z Threshold \else AR加速度Z阈值 \endif
    NvsAICutterParamTypeARSteerAngleJumpCount = 10,           //!< \if ENGLISH AR Steer Angle Jump Count \else AR转向角跳跃计数 \endif
    NvsAICutterParamTypeARAccelerationPreJumpCount = 11,      //!< \if ENGLISH AR Acceleration Pre Jump Count \else AR加速度预跳跃计数 \endif
    NvsAICutterParamTypeARAccelerationPostJumpCount = 12,     //!< \if ENGLISH AR Acceleration Post Jump Count \else AR加速度后跳跃计数 \endif
    NvsAICutterParamTypeRandomChooseRatio = 13                //!< \if ENGLISH Random Choose Ratio \else 随机选择比率 \endif
};

NVS_EXPORT @interface NvsTimeStampValue : NSObject

@property(nonatomic, assign) int64_t timeStamp;
@property(nonatomic, assign) float value;
@property(nonatomic, strong) NSString *strValue;

@end

NVS_EXPORT @interface NvsUnitClip : NSObject

@property(nonatomic, assign) int64_t start;
@property(nonatomic, assign) int64_t end;
@property(nonatomic, assign) int fileIdx;
@property(nonatomic, strong) NSDictionary <NSString*,NSArray<NvsTimeStampValue*>*>*formulaValues;

@property(nonatomic, assign) BOOL loopable;
@property(nonatomic, assign) BOOL segable;

@end

NVS_EXPORT @interface NvsAITag : NSObject

@property(nonatomic, strong) NSString *title;
@property(nonatomic, strong) NSString *userName;
@property(nonatomic, strong) NSDictionary <NSString *, NSString *>*tag;

@end

NVS_EXPORT @interface NvsClipInfo : NSObject
@property(nonatomic, strong) NSString *ID;
@property(nonatomic, strong) NSArray<NvsUnitClip*> *clips;
@property(nonatomic, strong) NvsAITag *tag;

@end

NVS_EXPORT @interface NvsLabelInfo : NSObject
@property(nonatomic, assign) NvsAICutterLabelType labelType;
@property(nonatomic, assign) int value;
@property(nonatomic, strong) NSString *strValue;

@end

NVS_EXPORT @interface NvsAICutter : NvsObject

- (BOOL)readTemplates:(NSArray<NSString*>*)template_jsons;

- (NSArray<NvsClipInfo*>*)matchTemplateHUD:(NSArray<NSString *>*)dataPaths extraParam:(NSArray<NSString *>*)extraParam;

- (NSArray<NvsClipInfo*>*)matchTemplateARSky:(NSArray<NSString *>*)dataPaths extraParam:(NSArray<NSString *>*)extraParam;

- (NSArray<NvsClipInfo*>*)matchTemplateVlog:(NSArray<NSString *>*)dataPaths extraParam:(NSArray<NSString *>*)extraParam;

- (NSArray<NvsClipInfo*>*)matchTemplateColor:(NSArray<NSString *>*)dataPaths extraParam:(NSArray<NSString *>*)extraParam;

- (NSArray<NvsClipInfo*>*)matchTemplateVlogIM:(NSArray<NSString *>*)dataPaths extraParam:(NSArray<NSString *>*)extraParam;

- (NSArray<NvsClipInfo*>*)matchTemplateSmart:(NSArray<NSString *>*)dataPaths extraParam:(NSArray<NSString *>*)extraParam;

- (NSArray<NvsClipInfo*>*)matchTemplateARSkyIM:(NSArray<NSString *>*)dataPaths extraParam:(NSArray<NSString *>*)extraParam;

- (NSArray<NvsClipInfo*>*)matchTemplateCutSame:(NSArray<NSString *>*)dataPaths extraParam:(NSArray<NSString *>*)extraParam;

- (NSArray<NvsClipInfo*>*)matchTemplateUnified:(NSArray<NSString *>*)dataPaths extraParam:(NSArray<NSString *>*)extraParam;

- (NSArray<NvsLabelInfo*>*)induceAndRecommend:(NSArray<NSString *>*)dataPaths;

- (void)setSmartTemplateCutPreference:(int)type;

- (BOOL)readTemplatesCutSame:(NSArray<NSString *>*)templateJsons;

- (void)clearTemplatesCutSame;

- (BOOL)setDisableIDs:(NSArray<NSString *>*)disableIDs;
- (BOOL)setEnableIDs:(NSArray<NSString *>*)enableIDs;
- (void)clearDisableIDs;

- (BOOL)setDisableTemplates:(NSArray<NSString *>*)templates;
- (BOOL)setEnableTemplates:(NSArray<NSString *>*)templates;
- (void)clearDisableTemplates;

+ (void)setFloatParam:(NvsAICutterParamType)type value:(float)value;
+ (float)getFloatParam:(NvsAICutterParamType)type;

@end

NS_ASSUME_NONNULL_END