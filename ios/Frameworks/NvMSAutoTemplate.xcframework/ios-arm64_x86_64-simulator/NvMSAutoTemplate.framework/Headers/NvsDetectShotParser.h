//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2023. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Oct 27. 2023
//   Author:        Meishe video team
//================================================================================
#pragma once

#import <Foundation/Foundation.h>
#import <NvStreamingSdkCore/NvsCommonDef.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(int, NvsDetectShotParserErrorType) {
    NvsDetectShotParserErrorTypeNone = 0,       //!< \if ENGLISH No error \else 无错误 \endif
    NvsDetectShotParserErrorTypeFileType,       //!< \if ENGLISH File type error \else 文件类型错误 \endif
    NvsDetectShotParserErrorTypeIO,             //!< \if ENGLISH IO error \else IO错误 \endif
    NvsDetectShotParserErrorTypeIOPermission,   //!< \if ENGLISH IO permission error \else IO权限错误 \endif
    NvsDetectShotParserErrorTypeVideoDecode     //!< \if ENGLISH Video decode error \else 视频解码错误 \endif
};

@protocol NvsDetectShotParserDelegate <NSObject>
@optional

/*! \if ENGLISH
 *  \brief Start detecting.
 *  \param videoPath video path.
 *  \param taskId task ID.
 *  \else
 *  \brief 开始检测
 *  \param videoPath 视频路径
 *  \param taskId 任务序号
 *  \endif
 */
- (void)didDetectStarted:(NSString*)videoPath taskId:(int64_t)taskId;

/*! \if ENGLISH
 *  \brief Finish detecting.
 *  \param videoPath video path.
 *  \param timeStampArray time stamp array
 *  \else
 *  \brief 完成检测
 *  \param videoPath 视频路径
 *  \param timeStampArray 时间戳队列
 *  \endif
 */
- (void)didDetectFinished:(NSString*)videoPath timeStampArray:(NSArray<NSNumber *> *)timeStampArray;

/*! \if ENGLISH
*  \brief detect exception information.
*  \param errorType Type of detect error.
*  \else
*  \brief 检测异常信息
*  \param errorType 错误类型
*  \endif
*/
- (void)didDetectError:(NvsDetectShotParserErrorType)errorType;

/*! \if ENGLISH
*  \brief Progress of detect.
*  \param videoPath video path.
*  \param progress Progess value.
*  \else
*  \brief 检测进度
*  \param videoPath 视频路径
*  \param progress 进度值
*  \endif
*/
- (void)didDetectProgress:(NSString*)videoPath progress:(float)progress;

@end

/*! \if ENGLISH
*   \brief Detect shot parser class
*   \warning In the NvsDetectShotParser class, all public APIs can be used not only in the UI thread, but also across threads! ! !
*   \else
*   \brief 转场帧检测类
*   \warning NvsDetectShotParser类中，所有public API不仅可以在UI线程使用，也可以跨线程使用！！！
*   \endif
*/

NVS_EXPORT @interface NvsDetectShotParser : NSObject

@property (atomic, weak) id<NvsDetectShotParserDelegate> delegate;

/*! \if ENGLISH
 *  \brief Initializes detect shot instance.
 *  \return Returns an object instance of the detect shot parser.
 *  \else
 *  \brief 对转场帧检测类的单例实例进行初始化
 *  \return 返回转场帧检测类的对象实例
 *  \endif
 *  \sa close
*/
+ (NvsDetectShotParser *)shareShotParser;

/*! \if ENGLISH
 *  \brief Destroys the detect shot object instance. note: it can be created again after destruction.
 *  \else
 *  \brief 销毁转场帧检测类实例。注意: 销毁之后可以再次创建及获取
 *  \endif
 *  \sa init
 *  \sa getInstance
 */
+ (void)destroyInstance;

/*! \if ENGLISH
 *  \brief set max detect thread count
 *  \param threadCount thread count
 *  \return Returns a BOOL value. true means successful and false means failure
 *  \else
 *  \brief 设置最大检测线程数目
 *  \param threadCount 线程数目
 *  \return 返回布尔值。值为true则成功，false则失败。
 *  \endif
 */
- (BOOL)setMaxThreadCount:(int)threadCount;

/*! \if ENGLISH
 *  \brief detect video shot
 *  \param videoPath video path
 *  \return Returns a BOOL value. true means successful and false means failure
 *  \else
 *  \brief 检测视频转场帧
 *  \param videoPath 资源列表
 *  \return 返回布尔值。值为true则成功，false则失败。
 *  \endif
 */
- (BOOL)detect:(NSString *)videoPath;

/*! \if ENGLISH
 *  \brief cancel media detect task.
 *  \param taskId task ID.
 *  \else
 *  \brief 取消检测任务
 *  \param taskId 任务序号
 *  \endif
 */
- (void)cancelTask:(int64_t)taskId;

/*! \if ENGLISH
 *  \brief cancel all detect tasks.
 *  \else
 *  \brief 取消所有检测任务
 *  \endif
 */
- (void)cancelAllTasks;

/*! \if ENGLISH
 *  \brief suspend all detect tasks.
 *  \else
 *  \brief 挂起检测任务
 *  \endif
 */
- (void)suspend;

/*! \if ENGLISH
 *  \brief resume all detect tasks.
 *  \else
 *  \brief 恢复所有检测任务
 *  \endif
 */
- (void)resume;

@end

NS_ASSUME_NONNULL_END


