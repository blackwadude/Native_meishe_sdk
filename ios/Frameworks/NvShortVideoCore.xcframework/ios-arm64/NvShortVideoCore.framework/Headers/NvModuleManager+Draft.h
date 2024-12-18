//
//  NvModuleManager+Draft.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/5/13.
//

#import "NvModuleManager.h"
#import "NvEditProjectInfo.h"

NS_ASSUME_NONNULL_BEGIN

UIKIT_EXTERN NSNotificationName const NvDraftManager_Draft_Save_Notification;
UIKIT_EXTERN NSNotificationName const NvDraftManager_Draft_Delete_Notification;

@interface NvModuleManager (Draft)

/*! \if ENGLISH
 *
 *  \brief Enter the editing portal through draft data recovery
 *  \param project Current draft object
 *  \param viewController Current viewController
 *  \param config Configuration item
 *  \else
 *
 *  \brief 通过草稿数据恢复，进入编辑入口
 *  \param project 当前草稿对象
 *  \param viewController 当前控制器
 *  \param config 配置项
 *  \endif
 */
- (void)reeditProject:(NvEditProjectInfo *)project presentViewController:(UIViewController *)viewController
               config:(NvVideoConfig * _Nullable)config;

+ (NvEditProjectInfo *_Nullable)projectInfoForProject:(NSString *)projectId;

+ (BOOL)deleteDraft:(NSString *)projectId;

+ (BOOL)updateProject:(NSString *)projectId description:(NSString *)description;

+ (NSArray<NvEditProjectInfo *> *)projectList;


@end

NS_ASSUME_NONNULL_END
