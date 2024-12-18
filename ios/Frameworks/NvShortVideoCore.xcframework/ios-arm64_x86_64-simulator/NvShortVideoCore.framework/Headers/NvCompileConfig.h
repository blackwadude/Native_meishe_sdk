//
//  NvCompileConfig.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/3/18.
//

#import <Foundation/Foundation.h>
#import <NvStreamingSdkCore/NvStreamingSdkCore.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, NvVideoPreviewResolution) {
    NvVideoPreviewResolution_720,
    NvVideoPreviewResolution_1080
};

typedef NS_ENUM(NSInteger, NvVideoCompileResolution) {
    NvVideoCompileResolution_720,
    NvVideoCompileResolution_1080,
    NvVideoCompileResolution_4K
};

/*! \if ENGLISH
 *
 *  \brief Compile configuration item
 *  \else
 *
 *  \brief 导出配置项
 *  \endif
*/
@interface NvCompileConfig : NSObject

/*! \if ENGLISH
 *
 *  \brief Output video resolution
 *  Default 1080
 *  Refer to NvVideoCompileResolution
 *  \else
 *
 *  \brief 输出视频分辨率
 *  默认1080
 *  参考NvVideoCompileResolution
 *  \endif
*/
@property (nonatomic, assign) NvVideoCompileResolution resolution;

/*! \if ENGLISH
 *
 *  \brief Output video fps
 *  \else
 *
 *  \brief 输出视频fps
 *  \endif
*/
@property (nonatomic, assign) int fps;

/*! \if ENGLISH
 *
 *  \brief Output video bit rate
 *  Default NvsCompileBitrateGradeHigh
 *
 *  Refer to NvsCompileVideoBitrateGrade
 *  \else
 *
 *  \brief 输出视频码率
 *  默认NvsCompileBitrateGradeHigh
 *
 *  参考NvsCompileVideoBitrateGrade
 *  \endif
*/
@property (nonatomic, assign) NvsCompileVideoBitrateGrade bitrateGrade;

/*! \if ENGLISH
 *
 *  \brief Output video bit rate
 *  For example, to set 3M bit rate, pass 3000000
 *  Default not set
 *  \else
 *
 *  \brief 输出视频码率
 *  比如要设置3M码率，则传3000000
 *  默认不设置
 *  \endif
*/
@property (nonatomic, assign) int64_t bitrate;

/*! \if ENGLISH
 *
 *  \brief Whether to save the exported video to the album
 *  Default Save
 *  false==Don't save
 *  true==Save
 *  \else
 *
 *  \brief 导出视频是否保存到相册
 *  默认保存
 *  false==不保存
 *  true==保存
 *  \endif
*/
@property (nonatomic, assign) BOOL autoSaveVideo;

@end

NS_ASSUME_NONNULL_END
