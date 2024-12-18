//
//  NvMaterialCenter.h
//  NvMaterialLibrary
//
//  管理路径、下载状态、提供ViewModel
//
//  Created by 美摄 on 2021/8/31.
//

#import <Foundation/Foundation.h>
#import "NvMaterial.h"
#import "NvMaterialPageRequestModel.h"

NS_ASSUME_NONNULL_BEGIN

/// 下载状态
/// Download status
typedef NS_ENUM(NSInteger, NvDownloadStatus) {
    // 空闲
    // none
    NvDownloadStatusNone,
    // 下载中
    // downloading
    NvDownloadStatusInProgress,
    // 下载完成
    // finish
    NvDownloadStatusFinished,
    // 下载失败
    // failed
    NvDownloadStatusFailed
};

/*! \if ENGLISH
 *
 *  \brief Network dependent proxy
 *  \else
 *
 *  \brief 网络相关代理
 *  \endif
*/
@protocol NvMaterialCenterNetworkDelegate <NSObject>

/*! \if ENGLISH
 *
 *  \brief Request list data
 *  \param type type
 *  \param category category
 *  \param kind kind
 *  \param optionalRequestParameters Custom parameter
 *  \param pageIndex pagination
 *  \param success Successful callback
 *  \param failure Failure callback
 *  \else
 *
 *  \brief 请求列表数据
 *  \param type 资源类型
 *  \param category 资源二级分类
 *  \param kind 资源三级分类
 *  \param optionalRequestParameters 自定义参数
 *  \param pageIndex 页码
 *  \param success 成功回调
 *  \param failure 失败回调
 *  \endif
*/
- (NSInteger)requestDataWithType:(NvMaterialType)type
                         category:(NSInteger)category
                             kind:(NSInteger)kind
        optionalRequestParameters:(NSMutableDictionary *)optionalRequestParameters
                        pageIndex:(NSInteger)pageIndex
                          success:(NvRequestSuccess)success
                          failure:(NvRequestFailure)failure;

/*! \if ENGLISH
 *
 *  \brief Request list data
 *  \param type type
 *  \param optionalRequestParameters Custom parameter
 *  \param pageIndex pagination
 *  \param modelClass Data Class
 *  \param success Successful callback
 *  \param failure Failure callback
 *  \else
 *
 *  \brief 请求列表数据
 *  \param type 资源类型
 *  \param optionalRequestParameters 自定义参数
 *  \param pageIndex 页码
 *  \param modelClass 数据类
 *  \param success 成功回调
 *  \param failure 失败回调
 *  \endif
*/
- (void)requestDataWithType:(NvMaterialType)type
  optionalRequestParameters:(NSMutableDictionary *)optionalRequestParameters
                  pageIndex:(NSInteger)pageIndex
                 modelClass:(Class)modelClass
                    success:(MsRequestSuccess)success
                    failure:(MsRequestFailure)failure;

/*! \if ENGLISH
 *
 *  \brief Request material category
 *  \param type type
 *  \param category
 *  \param optionalRequestParameters 自定义参数
 *  \param success 成功回调
 *  \param failure 失败回调
 *  \else
 *
 *  \brief 请求资源分类
 *  \param type 资源类型
 *  \param category
 *  \param optionalRequestParameters 自定义参数
 *  \param success 成功回调
 *  \param failure 失败回调
 *  \endif
*/
- (void)RequestListCategoryWithType:(NSInteger)type
                           category:(NSString *)category
          optionalRequestParameters:(NSMutableDictionary *)optionalRequestParameters
                            success:(NvRequestSuccess)success
                            failure:(NvRequestFailure)failure;


/// 下载资源
/// Download Resources
/// @param material 资源信息
/// @param targetFolder 目标文件夹
/// @param packExtensionSet 资源对于后缀名数组，用于从zip解压出来的文件中找到包，$：文件夹
/// Resources An array of extensions used to find packages, $: folders, from files unzipped
/// @param optParameters 自定义参数
/// @param downloadProgressBlock 进度回调
/// @param completionHandler 完成回调，

/*! \if ENGLISH
 *
 *  \brief Download Resources
 *  \param material material
 *  \param targetFolder Target Folder
 *  \param packExtensionSet Resource file type
 *  \param optParameters Custom parameter
 *  \param downloadProgressBlock Progress callback
 *  \param completionHandler Result callback
 *  \else
 *
 *  \brief 下载资源
 *  \param material 资源
 *  \param targetFolder 目标文件
 *  \param packExtensionSet 资源文件类型
 *  \param optParameters 自定义参数
 *  \param downloadProgressBlock 进度回调
 *  \param completionHandler 结果回调
 *  \endif
*/
- (NSInteger)downloadMaterial:(NvMaterial *)material
                  targetFolder:(NSString *)targetFolder
              packExtensionSet:(NSMutableArray *__nullable)packExtensionSet
                 optParameters:(NSMutableDictionary *__nullable)optParameters
                      progress:(void (^)(float progress))downloadProgressBlock
             completionHandler:(void (^)(NSString *__nullable packagePath,
                                         NSString *__nullable packageLicPath,
                                         NSString *__nullable packageJsonPath,
                                         NSString *__nullable packageId,
                                         NSError *__nullable error))completionHandler;

/*! \if ENGLISH
 *
 *  \brief Get prefab material
 *  \param completionHandler
 *  \else
 *
 *  \brief 获取预制素材
 *  \param completionHandler
 *  \endif
*/
- (void)requestProjectConfiguration:(void (^)(BOOL success,
                                              id __nullable responseObject,
                                              NSError *__nullable error))completionHandler;

/*! \if ENGLISH
 *
 *  \brief Get model file
 *  \param completionHandler
 *  \else
 *
 *  \brief 获取模型文件
 *  \param completionHandler
 *  \endif
 */
- (void)requestProjectModelFiles:(void (^)(BOOL success,
                                           id __nullable responseObject,
                                           NSError *__nullable error))completionHandler;
@end

@protocol NvMaterialDownloadCompleteDelegate <NSObject>

/// 下载完成回调
/// Download completed callback
/// @param material 资源
/// @param error 错误信息
- (void)materialDownloadComplete:(NvMaterial *)material error:(NSError *__nullable)error;

@end

/*
 * 更新下载状态代理
 * Update the download status agent
 */
@protocol NvMaterialDownloadStateDelegate <NSObject>

/// 下载进度回调
/// Download the progress callback
/// @param materialId 资源id
/// @param progress 进度
- (void)materialId:(NSString *)materialId downloadProgress:(float)progress;

/// 下载状态变化回调
/// Download the state change callback
/// @param materialId 资源id
/// @param state 下载状态
/// @param error 错误信息
- (void)materialId:(NSString *)materialId downloadStateChange:(NvDownloadStatus)state error:(NSError *__nullable)error;

@end

/*! \if ENGLISH
 *
 *  \brief Asset Center
 *  \else
 *
 *  \brief 素材中心
 *  \endif
*/
@interface NvMaterialCenter : NSObject

@property (nonatomic, readonly) NSString *downloadFileDir;

/*! \if ENGLISH
 *
 *  \brief Network dependent proxy
 *  \else
 *
 *  \brief 网络相关代理
 *  \endif
*/
@property(nonatomic, weak) id<NvMaterialCenterNetworkDelegate> netDelegate;

- (instancetype)init NS_UNAVAILABLE;

/*! \if ENGLISH
 *
 *  \brief init sdk
 *  \else
 *
 *  \brief 初始化方法
 *  \endif
*/
+ (instancetype)sharedInstance;

/*! \if ENGLISH
 *
 *  \brief destroy sdk
 *  \else
 *
 *  \brief 销毁方法
 *  \endif
*/
+ (void)destroyInstance;

/*! \if ENGLISH
 *
 *  \brief Setting resource paths
 *  \param path Resource path
 *  \else
 *
 *  \brief 设置资源路径
 *  \param path  资源路径
 *  \endif
*/
- (void)setForMaterialPath:(NSString *)path;

/*! \if ENGLISH
 *
 *  \brief Prepare the download folder
 *  \else
 *
 *  \brief 准备下载文件夹
 *  \endif
*/
- (BOOL)prepareDownloadFolders;

- (void)findMaterialCategoryType:(NvMaterialType)type
                        category:(int)category
                   assembleKinds:(BOOL)assembleKinds
                         success:(NvRequestSuccess)success
                         failure:(NvRequestFailure)failure;

/// 新建分页模型
/// Create a new paging model
/// @param type 资源类型
/// @param category 资源分类
/// @param kind 资源种类
- (NvMaterialPageRequestModel *)requestModelWithType:(NvMaterialType)type
                                            category:(NSInteger)category
                                                kind:(NSInteger)kind;

/// 获取资源下载状态
/// Get the resource download status
/// @param material 资源信息
- (NvDownloadStatus)downloadStateForMaterial:(NvMaterial *)material;

/// 添加下载状态变化回调
/// @param observer  observer
- (void)appendDownloadObserver:(id<NvMaterialDownloadCompleteDelegate>)observer;

/// 注册下载回调接收者
/// Register the download callback receiver
/// @param observer 接收者
/// @param materialId 资源ID
- (void)addDownloadObserver:(id<NvMaterialDownloadStateDelegate>)observer forMaterial:(NSString *)materialId;

/// 移除下载回调接收者
/// Remove the download callback receiver
/// @param observer 接收者
/// @param materialId 资源ID
- (void)removeDownloadObserver:(id<NvMaterialDownloadStateDelegate>)observer forMaterial:(NSString *)materialId;

/// 下载资源
/// Download Resources
/// @param material 资源信息
/// @param optParameters 自定义参数
- (NSInteger)downloadMaterial:(NvMaterial *)material optParameters:(NSMutableDictionary *__nullable)optParameters;


/*! \if ENGLISH
 *
 *  \brief download model files
 *  \else
 *
 *  \brief 下载模型文件
 *  \endif
*/
- (void)downloadProjectModelFilesWithPreDownload:(void (^)(BOOL))completionHandler;

- (NSString *_Nullable)recognitionCaptionContext;

@end

NS_ASSUME_NONNULL_END
