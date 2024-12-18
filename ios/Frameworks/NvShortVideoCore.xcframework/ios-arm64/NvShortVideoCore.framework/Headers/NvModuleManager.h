//
//  NvModuleManager.h
//  NvShortVideoCore
//
//  Created by 美摄 on 2022/2/21.
//

#import <Foundation/Foundation.h>
#import "NvVideoConfig.h"
#import <NvStreamingSdkCore/NvStreamingSdkCore.h>
#import "NvTheme.h"
#import "NvRecognitionTextItem.h"
#import "NvMaterialCenter.h"
#import "NvVoiceRecognizer.h"
#import "NvWebImageDelegate.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 * \if ENGLISH
 *
 *  \brief Edit complete, ready to enter publish callback
 *  \else
 *
 *  \brief 编辑完成，准备进入发布回调
 *  \endif
 */
@protocol NvModuleManagerDelegate <NSObject>

/*!
 * \if ENGLISH
 *
 *  \brief Edit complete, jump release callback
 *  @param taskId  Edit the event id used to exit the module
 *  @param coverImagePath cover
 *  @param hasDraft Whether there is a draft button
 *  @param draftInfo The title displayed on the publish page
 *  @param videoEditNavigationController Current nav controller
 *  \else
 *
 *  \brief 编辑完成，跳转发布回调
 *  @param taskId 编辑事件id，用于退出模块
 *  @param coverImagePath 封面图
 *  @param hasDraft 是否有草稿按钮
 *  @param draftInfo 发布页显示的标题
 *  @param videoEditNavigationController 当前nav控制器
 *  \endif
 *  \sa exitVideoEdit:
 */
- (void)publishWithProjectId:(NSString *)projectId
              coverImagePath:(NSString *)coverImagePath
                    hasDraft:(BOOL)hasDraft
                   videoPath:(NSString *_Nullable)videoPath
                 description:(NSString *_Nullable)description
videoEditNavigationController:(UINavigationController *)videoEditNavigationController;

@end

/*! \if ENGLISH
 *
 *  \brief sdk video export callback
 *  \else
 *
 *  \brief sdk视频导出回调
 *  \endif
 */
@protocol NvModuleManagerCompileStateDelegate <NSObject>

/*! \if ENGLISH
 *
 *  \brief compile video progress callback
 *  \param progress  the current progress
 *  \else
 *
 *  \brief 合成视频进度回调
 *  \param progress 当前的进度
 *  \endif
 */
- (void)didCompileFloatProgress:(float)progress;

/*! \if ENGLISH
 *
 *  \brief The resultant video completes the callback
 *  \param outputPath Video output file path
 *  \param error error
 *  \else
 *
 *  \brief 合成视频完成回调
 *  \param outputPath 视频输出的文件路径
 *  \param error 错误信息
 *  \endif
 */
- (void)didCompileCompleted:(NSString *_Nullable)outputPath error:(NSError *_Nullable)error;

@end

/*! \if ENGLISH
 *
 *  \brief The NvCaptionMusicInfo class represents information about music, including the name of the music and the file path.
 *  \else
 *
 *  \brief NvCaptionMusicInfo 类用于描述音乐的信息，包括音乐名称和音乐文件路径。
 *  \endif
 */
@interface NvCaptionMusicInfo : NSObject

/*! \if ENGLISH
 *
 *  \brief Music Name
 *  \else
 *
 *  \brief 音乐名称
 *  \endif
 */
@property (nonatomic, strong) NSString *musicName;

/*! \if ENGLISH
 *
 *  \brief Music File Path
 *  \else
 *
 *  \brief 音乐文件路径
 *  \endif
 */
@property (nonatomic, strong) NSString *musicFilePath;

@end

/*! \if ENGLISH
 *
 *  \brief Short video entry main class, shooting, editing, shooting, draft entry and other methods are included in this class
 *  \else
 *
 *  \brief 短视频入口主类，拍摄、编辑、合拍、草稿入口等方法都包含在这个类中
 *  \endif
 */
@interface NvModuleManager : NSObject<NvThemeDataSourceDelegate>

- (instancetype)init NS_UNAVAILABLE;

/*! \if ENGLISH
 *
 *  \brief Initialization method
 *  \else
 *
 *  \brief 初始化方法
 *  \endif
 */
+ (instancetype)sharedInstance;

/*! \if ENGLISH
 *
 *  \brief Network dependent proxy
 *  \else
 *
 *  \brief 网络相关代理
 *  \endif
*/
@property(nonatomic, weak) id<NvMaterialCenterNetworkDelegate> netDelegate;

/*! \if ENGLISH
 *
 *  \brief Network image delegate
 *  \else
 *
 *  \brief 网络图片代理
 *  \endif
*/
@property(nonatomic, weak) id<NvWebImageDelegate> webImageDelegate;

/*!
 * \if ENGLISH
 *
 *  \brief Edit complete, ready to enter publish callback
 *  \else
 *
 *  \brief 编辑完成，准备进入发布回调
 *  \endif
 */
@property(nonatomic, weak) id<NvModuleManagerDelegate> delegate;

/*! \if ENGLISH
 *
 *  \brief sdk video export callback
 *  \else
 *
 *  \brief sdk视频导出回调
 *  \endif
 */
@property(nonatomic, weak) id<NvModuleManagerCompileStateDelegate> compileDelegate;

/*! \if ENGLISH
 *
 *  \brief speech-to-text delegate
 *  \else
 *
 *  \brief 语音转文字回调
 *  \endif
 */
@property(nonatomic, strong) NSObject<NvVoiceRecognizer> *voiceRecognizer;

/*! \if ENGLISH
 *
 *  \brief The project initializes the incoming project configuration item, passing nil by default
 *  \else
 *
 *  \brief 项目初始化传入的工程配置项，默认传nil
 *  \endif
 */
@property(nonatomic, strong, readwrite) NvVideoConfig *config;

@property(nonatomic, weak) id<NvThemeDelegate> themeDelegate;

@property(nonatomic, assign) BOOL enableThemeKeyLog;

/*! \if ENGLISH
 *
 *  \brief Preloaded resource
 *  \else
 *
 *  \brief 预加载资源
 *  \endif
 */
- (void)preloadedResource;

/*! \if ENGLISH
 *
 *  \brief Shooting entrance
 *  \param viewController Current viewController
 *  \param config Configuration item
 *  \param music The default is nil，If you need to shoot with music, you need to pass an audio object, and the path of the audio must be local and has been downloaded
 *  \param complatetionHandler
 *  \else
 *
 *  \brief 拍摄入口
 *  \param viewController 当前控制器
 *  \param config 配置项
 *  \param music 默认是nil，如果拍摄时需要带音乐拍摄，需要传递一个音频对象，音频的路径必须是本地的，已经下载的路径
 *  \param complatetionHandler
 *  \endif
 */
- (void)startCaptureWithPresentViewController:(UIViewController *)viewController
                                       config:(NvVideoConfig * _Nullable)config
                                        music:(NvCaptionMusicInfo * _Nullable)music
                                         with:(void(^)(void))complatetionHandler;

/*! \if ENGLISH
 *
 *  \brief PIP entrance By default, the album is opened, and a material from the album is taken into the beat
 *  \param viewController Current viewController
 *  \param config Configuration item
 *  \param complatetionHandler
 *  \else
 *
 *  \brief 合拍入口，默认打开相册，从相册取一个素材进入合拍
 *  \param viewController 当前控制器
 *  \param config 配置项
 *  \param complatetionHandler
 *  \endif
 */
- (void)startDualCaptureWithPresentViewController:(UIViewController *)viewController
                                           config:(NvVideoConfig * _Nullable)config
                                             with:(void(^)(void))complatetionHandler;

/*! \if ENGLISH
 *
 *  \brief PIP entrance
 *  \param viewController Current viewController
 *  \param config Configuration item
 *  \param videoPath The video path to be filmed must be a local path
 *  \param complatetionHandler
 *  \else
 *
 *  \brief 合拍入口
 *  \param viewController 当前控制器
 *  \param config 配置项
 *  \param videoPath 准备合拍的视频路径，必须是本地路径
 *  \param complatetionHandler
 *  \endif
 */
- (void)startDualCaptureWithPresentViewController:(UIViewController *)viewController
                                           config:(NvVideoConfig * _Nullable)config
                                        videoPath:(NSString *)videoPath
                                             with:(void(^)(void))complatetionHandler;

/*! \if ENGLISH
 *
 *  \brief Edit entrance
 *  \param viewController Current viewController
 *  \param config Configuration item
 *  \param complatetionHandler
 *  \else
 *
 *  \brief 编辑入口
 *  \param viewController 当前控制器
 *  \param config 配置项
 *  \param complatetionHandler
 *  \endif
 */
- (void)startEditWithPresentViewController:(UIViewController *)viewController
                                    config:(NvVideoConfig * _Nullable)config
                                      with:(void(^)(void))complatetionHandler;

/*! \if ENGLISH
 *
 *  \brief Template entrance
 *  \param viewController Current viewController
 *  \param config Configuration item
 *  \param draft The process operation of the current draft object and template will not be saved to the draft, and the unified saving path of the draft is mainly used here.
 *  \param complatetionHandler
 *  \else
 *
 *  \brief 模版入口
 *  \param viewController 当前控制器
 *  \param config 配置项
 *  \param draft 当前草稿对象，模版的流程操作不会保存到草稿，这里主要使用草稿的统一保存路径，
 *  \param complatetionHandler
 *  \endif
 */
- (void)startTemplateWithPresentViewController:(UIViewController *)viewController
                                        config:(NvVideoConfig * _Nullable)config
                           complatetionHandler:(void(^)(void))complatetionHandler;



/*! \if ENGLISH
 *
 *  \brief Go to select a cover page
 *  \param naviagtionController Current naviagtionController
 *  \param completionHandler The path parameter is the image path after selection
 *  \else
 *
 *  \brief 进入选择封面页
 *  \param naviagtionController 当前控制器
 *  \param completionHandler 参数path是选择之后的图片路径
 *  \endif
 */
- (void)selectCoverWithNavigationController:(UINavigationController * _Nullable)naviagtionController
                          completionHandler:(nullable void(^)(NSString *path))completionHandler;


/*! \if ENGLISH
 *
 *  \brief Save the cover image to the album
 *  \param coverPath Current cover map path
 *  \param completionHandler
 *  \warning Publish page Save picture button, click after the call
 *  \else
 *
 *  \brief 保存封面图到相册
 *  \param coverPath 当前封面图路径
 *  \param completionHandler
 *  \warning 发布页保存图片按钮，点击之后调用
 *  \endif
 */
- (void)saveCover:(NSString *)coverPath with:(nullable void(^)(BOOL success))completionHandler;

/*! \if ENGLISH
 *
 *  \brief Save the video to the album
 *  \param coverPath Current video path
 *  \param completionHandler
 *  \else
 *
 *  \brief 保存视频到相册
 *  \param coverPath 当前视频路径
 *  \param completionHandler
 *  \endif
 */
- (void)saveVideo:(NSString *)videoPath with:(nullable void(^)(BOOL success))completionHandler;

/*! \if ENGLISH
 *
 *  \brief Save draft
 *  \param infoString The text of the currently saved publication page
 *  \warning Publish page Save draft button, called after clicking
 *  \else
 *
 *  \brief 保存草稿
 *  \param infoString 当前保存的发布页文本
 *  \warning 发布页保存草稿按钮，点击之后调用
 *  \endif
 */
- (BOOL)saveCurrentDraftWithDraftInfo:(NSString *_Nullable)infoString;

/*! \if ENGLISH
 *
 *  \brief Start exporting video
 *  \param configure Default is nil, no need to pass
 *  \warning Publish page Save video button, click after the call
 *  \else
 *
 *  \brief 开始导出视频
 *  \param configure 默认是nil，不需要传
 *  \warning 发布页保存视频按钮，点击之后调用
 *  \endif
 */
- (BOOL)compileCurrentTimeline:(NSDictionary *_Nullable)configure;

/*! \if ENGLISH
 *
 *  \brief Exit the entire publisher call
 *  \param projectId Returned by the edit completion callback
 *  \warning This method will clean up the current draft and SDK-held resources, please call after completely exiting the editing and publishing process
 *  \else
 *
 *  \brief 退出整个发布器调用
 *  \param projectId 由编辑完成回调中返回
 *  \warning 该方法会清理当前草稿以及sdk持有资源，请在完全退出编辑发布流程之后，调用
 *  \endif
 */
- (BOOL)exitVideoEdit:(NSString *)projectId;

/*! \if ENGLISH
 *
 *  \brief
 *  \warning This method is called internally and does not need to be called externally
 *  \else
 *
 *  \brief
 *  \warning 内部会调用该方法，外部不需要调用该方法
 *  \endif
 */
- (void)configTemplateNetwork;

/*! \if ENGLISH
 *
 *  \brief
 *  \warning This method is called internally and does not need to be called externally
 *  \else
 *
 *  \brief
 *  \warning 内部会调用该方法，外部不需要调用该方法
 *  \endif
 */
- (void)applyViewThem:(NSObject <NvThemeElement>*)view moduleFlag:(NSString *)moduleFlag;

/*! \if ENGLISH
 *
 *  \brief Prepare the download folder
 *  \else
 *
 *  \brief 准备下载文件夹
 *  \endif
*/
- (BOOL)prepareDownloadFolders;

- (void)setupSwiftPackageEnv;

/*! \if ENGLISH
 *
 *  \brief Get a list of all currently selected materials
 *  \else
 *
 *  \brief 获取当前所选所有素材列表
 *  \endif
 */
- (NSMutableArray *)getAVFileInfoArray;

/*! \if ENGLISH
 *
 *  \brief Get material information
 *  \param path material path
 *  \else
 *
 *  \brief 获取素材信息
 *  \param path 素材路径
 *  \endif
 */
- (NvsAVFileInfo*)getAVFileInfo:(NSString *)path;

@end

NS_ASSUME_NONNULL_END
