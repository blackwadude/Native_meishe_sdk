//
//  NvRecordBtTheme.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/3/19.
//

#import "NvViewTheme.h"

NS_ASSUME_NONNULL_BEGIN

/*! \if ENGLISH
 *
 *  \brief Capture record button theme
 *  \else
 *
 *  \brief 拍摄按钮主题
 *  \endif
*/
@interface NvRecordBtTheme : NvViewTheme

/*! \if ENGLISH
 *
 *  \brief Capture record button color
 *  \else
 *
 *  \brief 拍摄按钮颜色
 *  \endif
*/
@property (nonatomic, strong) UIColor *normalColor;

/*! \if ENGLISH
 *
 *  \brief Capture record button  progress bar color
 *  \else
 *
 *  \brief 拍摄按钮颜色进度条颜色
 *  \endif
*/
@property (nonatomic, strong) UIColor *minimumTrackTintColor;

/*! \if ENGLISH
 *
 *  \brief Capture record button  progress bar color when highlighted
 *  \else
 *
 *  \brief 拍摄按钮颜色进度条高亮颜色
 *  \endif
*/
@property (nonatomic, strong) UIColor *maximumTrackTintColor;

/*! \if ENGLISH
 *
 *  \brief Capture button start recording icon
 *  \else
 *
 *  \brief 拍摄按钮开始录制图标
 *  \endif
*/
@property (nonatomic, strong) NSString *playImageName;

/*! \if ENGLISH
 *
 *  \brief Capture button stop recording icon
 *  \else
 *
 *  \brief 拍摄按钮停止录制图标
 *  \endif
*/
@property (nonatomic, strong) NSString *pauseImageName;

/*! \if ENGLISH
 *
 *  \brief Capture button story icon
 *  \else
 *  
 *  \brief 拍摄按钮快拍图标
 *  \endif
*/
@property (nonatomic, strong) NSString *smartImageName;

@end

NS_ASSUME_NONNULL_END
