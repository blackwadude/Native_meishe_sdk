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
#import <NvStreamingSdkCore/NvsAIParser.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(int, NvsAIDetectErrorType) {
    NvsAIDetectErrorTypeNone = 0,                       //!< \if ENGLISH No error \else 无错误 \endif
    NvsAIDetectErrorTypeFaildLoadModelFailed,           //!< \if ENGLISH Failed to load model \else 加载模型失败 \endif
    NvsAIDetectErrorTypeFaildBuildInterpreterFailed,    //!< \if ENGLISH Failed to build interpreter \else 构建解释器失败 \endif
    NvsAIDetectErrorTypeFailedAllocateFailed,           //!< \if ENGLISH Failed to allocate \else 分配失败 \endif
    NvsAIDetectErrorTypeReadImageDataFailed,            //!< \if ENGLISH Failed to read image data \else 读取图像数据失败 \endif
    NvsAIDetectErrorTypeInferenceFailed,                //!< \if ENGLISH Inference failed \else 推理失败 \endif
    NvsAIDetectErrorTypeParamsConflict,                 //!< \if ENGLISH Parameters conflict \else 参数冲突 \endif
    NvsAIDetectErrorTypeCreateGpuDelegateFailed,        //!< \if ENGLISH Failed to create GPU delegate \else 创建GPU委托失败 \endif
    NvsAIDetectErrorTypeQueryTensorsInfoFailed,         //!< \if ENGLISH Failed to query tensors info \else 查询张量信息失败 \endif
    NvsAIDetectErrorTypeIO,                             //!< \if ENGLISH IO error \else IO错误 \endif
    NvsAIDetectErrorTypeIOPermission,                   //!< \if ENGLISH IO permission error \else IO权限错误 \endif
    NvsAIDetectErrorTypeHardwareVideoDecoding           //!< \if ENGLISH Hardware video decoding error \else 硬件视频解码错误 \endif
};

@protocol NvsAIDetectorDelegate <NSObject>

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
- (void)didDetectStarted:(NSString *)videoPath taskId:(int64_t)taskId;

/*! \if ENGLISH
 *  \brief Finish detecting.
 *  \param videoPath video path.
 *  \param scdPath Detection result file path
 *  \else
 *  \brief 完成检测
 *  \param videoPath 视频路径
 *  \param scdPath 检测结果文件路径
 *  \endif
 */
- (void)didDetectFinished:(NSString *)videoPath scdPath:(NSString *)scdPath;

/*! \if ENGLISH
*  \brief detect exception information.
*  \param errorType Type of detect error.
*  \else
*  \brief 检测异常信息
*  \param errorType 错误类型
*  \endif
*/
- (void)didDetectError:(NvsAIDetectErrorType)errorType;

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
- (void)didDetectProgress:(NSString *)videoPath progress:(float)progress;

@end

typedef NS_ENUM(int, NvsAIDetectModelType) {
    NvsAIDetectModelTypePlace = 0,                 //!< \if ENGLISH Old scene model \else 旧版场景模型 pf.model \endif
    NvsAIDetectModelTypeSkySeg = 1,                //!< \if ENGLISH Sky segmentation model \else 天空分割模型 ms_skyseg_* \endif
    NvsAIDetectModelTypeSkyClass = 2,              //!< \if ENGLISH Sky classification model \else 天空分类模型 ms_skyclass_* \endif
    NvsAIDetectModelTypeFace = 3,                  //!< \if ENGLISH Face detection model \else 人脸检测模型 ms_face_* \endif
    NvsAIDetectModelTypeActivity = 4,              //!< \if ENGLISH Activity classification model \else 活动分类模型 activity_* \endif
    NvsAIDetectModelTypeObjDet = 5,                //!< \if ENGLISH Object detection model (80 classes for Zhiji) \else 目标检测模型（智己用80类） ms_vehicle_pedestrian_* \endif
    NvsAIDetectModelTypeFaceAttr = 6,              //!< \if ENGLISH Face attribute model \else 人脸属性模型 FaceAttri.model \endif
    NvsAIDetectModelTypePhoto = 7,                 //!< \if ENGLISH Photo classification model \else 照片分类模型 photo_category_* \endif
    NvsAIDetectModelTypeImageClass = 8,            //!< \if ENGLISH Object classification model (1000 classes) \else 物体分类模型（1000类） ms_imagecls_* \endif
    NvsAIDetectModelTypePlaceClassNew = 9,         //!< \if ENGLISH New scene model \else 新版场景模型 ms_placecls_* \endif
    NvsAIDetectModelTypeDFace = 10,                //!< \if ENGLISH DSP version face detection model \else 人脸检测模型DSP版本 ms_face_mosaic_* \endif
    NvsAIDetectModelTypeDClp = 11,                 //!< \if ENGLISH DSP version license plate detection model \else 车牌检测模型DSP版本 ms_clp_mosaic_* \endif
    NvsAIDetectModelTypeDFaceClp = 12,             //!< \if ENGLISH DSP version combined face and license plate model \else 人脸车牌联合模型DSP版本 ms_mosaic_* \endif
    NvsAIDetectModelTypeScene = 13,                //!< \if ENGLISH Scene classification model \else 景别分类模型 sf.model \endif
    NvsAIDetectModelTypeAerial = 14,               //!< \if ENGLISH Aerial/non-aerial classification model \else 航拍非航拍分类模型 aerial_* \endif
    NvsAIDetectModelTypeFaceAttrShape = 15,        //!< \if ENGLISH Face shape model \else 人脸形状模型 net_face_448_20210121.model \endif
    NvsAIDetectModelTypeFaceAttrEyeGlass = 16,     //!< \if ENGLISH Eye and glasses classification model \else 眼镜和眼睛分类模型 net_glass_448_20210121.model \endif
    NvsAIDetectModelTypeFaceAttrMaleHair = 17,     //!< \if ENGLISH Male hairstyle model \else 男士发型模型 net_m_hair_448_20210118.model \endif
    NvsAIDetectModelTypeFaceAttrFemaleHair = 18,   //!< \if ENGLISH Female hairstyle model \else 女士发型模型 net_f_hair_448_20210118.model \endif
    NvsAIDetectModelTypeFaceAttrBeard = 19,        //!< \if ENGLISH Beard model \else 胡子模型 net_moustache_224.model \endif
    NvsAIDetectModelTypeObjDetV2 = 20,             //!< \if ENGLISH Object detection model (365 classes) \else 检测模型(365类) objdet_* \endif
    NvsAIDetectModelTypeLandmark = 21,             //!< \if ENGLISH Landmark model \else 地标模型 ms_landmark_* \endif
    NvsAIDetectModelTypeMainColor = 22,            //!< \if ENGLISH Main color detection (no model needed, use "" as path) \else 主色检测 不需要模型，直接使用""作为路径 \endif
    NvsAIDetectModelTypeImageQuality = 23,         //!< \if ENGLISH Image quality detection model \else 图像质量检测 ms_imageq_* \endif
    NvsAIDetectModelTypeCarDet = 24,               //!< \if ENGLISH Car detection model \else 车辆检测 ms_cardet_* \endif
    NvsAIDetectModelTypeExpression = 25,           //!< \if ENGLISH Expression model \else 表情模型 \endif
    NvsAIDetectModelTypeAesthetic = 26,            //!< \if ENGLISH Aesthetic model \else 美学模型 \endif
    NvsAIDetectModelTypeHandGesture = 27,          //!< \if ENGLISH Hand gesture model \else 手势模型 \endif
    NvsAIDetectModelTypeHandSmile = 28,            //!< \if ENGLISH Hand smile model \else 手笑模型 \endif
    NvsAIDetectModelTypeNio4 = 29                  //!< \if ENGLISH Nio4 model \else Nio4模型 \endif
};


/*! \if ENGLISH
*   \brief Frame information class
*   \else
*   \brief 帧信息类
*   \endif
*/
@interface NvsCarFrameInfo : NSObject

@property (nonatomic, strong) NSString *placel1;
@property (nonatomic, strong) NSString *placel2;
@property (nonatomic, strong) NSString *activity;
@property (nonatomic, strong) NSString *skytype;
@property (nonatomic, strong) NSString *skycolor;
@property (nonatomic, strong) NSString *moon;
@property (nonatomic, strong) NSString *rainbow;
@property (nonatomic, strong) NSString *airplanecloud;
@property (nonatomic, strong) NSString *weather;
@property (nonatomic, strong) NSString *time;
@property (nonatomic, strong) NSString *sky;
@property (nonatomic, strong) NSString *firecloud;
@property (nonatomic, strong) NSString *dface;
@property (nonatomic, strong) NSString *dclp;

@end


/*! \if ENGLISH
*   \brief AI detection class
*   \warning In the NvsAIDetector class, all public APIs can be used not only in the UI thread, but also across threads! ! !
*   \else
*   \brief AI检测类
*   \warning NvsAIDetector类中API不仅可以在UI线程使用，也可以跨线程使用！！！
*   \endif
*/
NVS_EXPORT @interface NvsAIDetector : NvsObject

@property (nonatomic, weak) id<NvsAIDetectorDelegate> delegate;

/*! \if ENGLISH
 *  \brief Initializes detector instance.
 *  \return Returns an object instance of the detector.
 *  \else
 *  \brief 获取AI检测类的单例
 *  \return 返回AI检测类的对象实例
 *  \endif
 *  \sa close
*/
+ (NvsAIDetector *)shareDetector;
+ (NvsAIDetector *)shareDetectorWithFlags:(int)flags;

/*! \if ENGLISH
 *  \brief Destroys the detector object instance. note: it can be created again after destruction.
 *  \else
 *  \brief 销毁AI检测类实例。注意: 销毁之后可以再次创建及获取
 *  \endif
 *  \sa shareDetector
 */
+ (void)destroyInstance;

- (BOOL)initModel:(NSString *)modelPath type:(NvsAIDetectModelType)type;
- (BOOL)detectMediaFiles:(NSArray<NvsDetectData *> *)mediaFiles;
- (void)cancelTask:(int64_t)taskId;
- (void)cancelAllTasks;
- (void)suspend;
- (void)resume;

+ (NvsCarFrameInfo *)read:(NSString *)infodata;
+ (void)installDescData:(NSString *)descpath;
+ (void)setDSPPath:(NSString *)dsppath;
+ (void)setLandmarkDatabasePath:(NSString *)path;

@end

NS_ASSUME_NONNULL_END