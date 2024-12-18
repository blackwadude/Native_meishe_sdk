//
//  NvVoiceRecognizer.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/5/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 * \if ENGLISH
 *
 *  \brief speech-to-text
 *  \else
 *
 *  \brief 语音转文字
 *  \endif
 */
@protocol NvVoiceRecognizer <NSObject>


/*!
 * \if ENGLISH
 *
 *  \brief Supported languages
 *  \else
 *
 *  \brief 支持的语言
 *  \endif
 */
- (NSArray<NSString *> *_Nullable)supportedLanguages;


/*!
 * \if ENGLISH
 *
 *  \brief Default language, nil: automatically selected
 *  \else
 *
 *  \brief 默认语言，nil : 自动选择
 *  \endif
 */
- (NSString * _Nullable)defaulLanguage;


/*!
 * \if ENGLISH
 *
 *  \brief Identify the process schedule percentage
 *  \else
 *
 *  \brief 识别过程 进度占比
 *  \endif
 */
- (CGFloat)recognizerProgressRate;

/*!
 * \if ENGLISH
 *
 *  \brief Identify authorization status
 *  \else
 *
 *  \brief 文字识别授权状态
 *  \endif
 */
- (void)requestRecognitionAuthorization:(void (^)(BOOL authorized))completion;


/*!
 * \if ENGLISH
 *
 *  \brief Speech recognition
 *  \param audioFilePath  audio file path
 *  \param languageIdentifier  Locale Identifier
 *  \param progressBlock Identify progress
 *  \param completion Complete callback
 *  \else
 *
 *  \brief 语音识别
 *  \param audioFilePath 音频文件
 *  \param languageIdentifier 语言标识
 *  \param progressBlock 识别进度
 *  \param completion 完成回调
 *  \endif
 */
- (BOOL)recognitionAudioFile:(NSString *)audioFilePath
          languageIdentifier:(NSString *_Nullable)languageIdentifier
                    progress:(void (^)(float progress))progressBlock
                  completion:(void (^)(NSArray<NvRecognitionTextItem *> *textArray,
                                       NSError *error))completion;

/*!
 * \if ENGLISH
 *
 *  \brief The text recognition task is cancelled
 *  \else
 *
 *  \brief 文字识别任务取消
 *  \endif
 */
- (void)cancleRecognition;

@end

NS_ASSUME_NONNULL_END
