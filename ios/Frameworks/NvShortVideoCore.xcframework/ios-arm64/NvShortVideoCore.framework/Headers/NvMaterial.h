//
//  NvMaterial.h
//  NvMaterialLibrary
//
//  Created by 美摄 on 2021/8/31.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class NvMaterial;

typedef void (^NvRequestProgress)(NSString *materialId, float progress);
typedef void (^NvRequestSuccess)(NSArray<NvMaterial *> *__nullable array, BOOL hasMore, id __nullable responseObject);
typedef void (^NvRequestFailure)(NSError *__nullable error);
typedef void (^MsRequestSuccess)(NSArray *__nullable array, id __nullable responseObject, BOOL hasMore);
typedef void (^MsRequestFailure)(NSError *__nullable error);

typedef NS_ENUM(NSInteger, NvMaterialType) {
    NvMaterialTypeUndefined = 0,        // 未定义
    NvMaterialTypeFilter = 2,           // 滤镜
    NvMaterialTypeCaption = 3,          // 字幕
    NvMaterialTypeCompoundCaption = 3,          // 组合字幕
    NvMaterialTypeSticker = 4,          // 贴纸
    NvMaterialTypeTransition = 5,       // 转场
    NvMaterialTypeFont = 6,             // 字体
    NvMaterialTypeARScene = 14,         // 人脸道具
    NvMaterialTypeMakeup = 20,          // 美妆
    NvMaterialTypeLooks = 21,           // 妆容
    NvMaterialTypeShape = 22,           // 美颜
    NvMaterialTypeMusic = 23,           // 音乐
    NvMaterialTypePrefabricate = 24,    // 预制需要下载的文件
};

typedef NS_ENUM(NSInteger, NvMaterialVideoFxType) {
    NvMaterialVideoFxType_Package = 0, //!< \if ENGLISH The type of package \else 包裹采集类型 \endif
    NvMaterialVideoFxType_Builtin,     //!< \if ENGLISH The type of built-in \else 内建采集类型 \endif
};

/*! \if ENGLISH
 *
 *  \brief The resource object returned by the network interface
 *  Most interfaces return json parsing that can be used
 *  \else
 *
 *  \brief 网络接口返回的资源对象
 *  大部分接口返回的json解析可以使用
 *  \endif
*/
@interface NvMaterial : NSObject

/*! \if ENGLISH
 *
 *  \brief index
 *  \else
 *
 *  \brief 下标
 *  \endif
*/
@property(nonatomic, assign) NSInteger indexCode;

/*! \if ENGLISH
 *
 *  \brief type
 *  \else
 *
 *  \brief 一级分类
 *  \endif
*/
@property(nonatomic, assign) NvMaterialType type;

/*! \if ENGLISH
 *
 *  \brief category
 *  \else
 *
 *  \brief 二级分类
 *  \endif
*/
@property(nonatomic, assign) NSInteger category;

/*! \if ENGLISH
 *
 *  \brief kind
 *  \else
 *
 *  \brief 三级分类
 *  \endif
*/
@property(nonatomic, assign) NSInteger kind;

/*! \if ENGLISH
 *
 *  \brief uuid of the material
 *  \else
 *
 *  \brief 素材的uuid
 *  \endif
*/
@property(nonatomic, copy) NSString *uuid;

/*! \if ENGLISH
 *
 *  \brief Parcel type
 *  \else
 *
 *  \brief 包裹类型
 *  \endif
*/
@property(nonatomic, assign) NvMaterialVideoFxType materialVideoFxType;

/*! \if ENGLISH
 *
 *  \brief The absolute path to where the archive was downloaded and unzipped
 *  \else
 *
 *  \brief 素材包下载解压后的绝对路径
 *  \endif
*/
@property(nonatomic, strong) NSString *packageFilePath;

/*! \if ENGLISH
 *
 *  \brief Asset package corresponds to lic file path
 *  \else
 *
 *  \brief 素材包对应lic文件路径
 *  \endif
*/
@property(nonatomic, strong) NSString *__nullable packageLicFilePath;

/*! \if ENGLISH
 *
 *  \brief Asset package corresponds to lic file path
 *  The main beauty needs to be used
 *  \else
 *
 *  \brief 素材包对应json文件路径
 *  主要美妆需要用到
 *  \endif
*/
@property(nonatomic, strong) NSString *__nullable packageJsonFilePath;

/*! \if ENGLISH
 *
 *  \brief Resource pack Url
 *  \else
 *
 *  \brief 资源包Url
 *  \endif
*/
@property(nonatomic, strong) NSString *packageUrl;

/*! \if ENGLISH
 *
 *  \brief Cover path (image file path or web url)
 *  \else
 *
 *  \brief 封面路径（图片文件路径或网络url）
 *  \endif
*/
@property(nonatomic, strong) NSString *coverUrl;

/*! \if ENGLISH
 *
 *  \brief Cover path (image Select file path or web url)
 *  \else
 *
 *  \brief 封面选中路径（图片文件路径或网络url）
 *  \endif
*/
@property(nonatomic, strong) NSString *coverSelectUrl;

/*! \if ENGLISH
 *
 *  \brief Video cover
 *  \else
 *
 *  \brief 视频封面
 *  \endif
*/
@property(nonatomic, strong) NSString *previewVideoUrl;

/*! \if ENGLISH
 *
 *  \brief display name
 *  \else
 *
 *  \brief 显示名称
 *  \endif
*/
@property(nonatomic, copy) NSString *displayName;

/*! \if ENGLISH
 *
 *  \brief Supported frame ratios
 *  \else
 *
 *  \brief 支持的画幅比例
 *  \endif
*/
@property(nonatomic, assign) int supportedAspectRatio;

/*! \if ENGLISH
 *
 *  \brief Minimum supported SDK version
 *  \else
 *
 *  \brief 最低支持SDK版本
 *  \endif
*/
@property(nonatomic, copy) NSString *minAppVersion;

/*! \if ENGLISH
 *
 *  \brief version
 *  \else
 *
 *  \brief 版本号
 *  \endif
*/
@property(nonatomic, assign) NSInteger version;

/*! \if ENGLISH
 *
 *  \brief Animation pack type
 *  \else
 *
 *  \brief 动画包类型
 *  \endif
*/
@property(nonatomic, assign) BOOL isPostPackage;


- (NSString *)operationalName;

@end

NS_ASSUME_NONNULL_END
