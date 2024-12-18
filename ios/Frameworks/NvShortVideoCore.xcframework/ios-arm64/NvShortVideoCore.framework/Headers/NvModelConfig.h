//
//  NvModelConfig.h
//  NvShortVideoCore
//
//  Created by ms20221114 on 2024/4/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*! \if ENGLISH
 *
 *  \brief model Configuration item
 *  \else
 *
 *  \brief 模型配置项
 *  \endif
*/
@interface NvModelConfig : NSObject

/*! \if ENGLISH
 *
 *  \brief Whether to use the 240 point model
 *  \else
 *
 *  \brief 是否使用240点位模型
 *  \endif
*/
@property (nonatomic, assign) BOOL use240;

/*! \if ENGLISH
 *
 *  \brief fakeface model path
 *  \else
 *
 *  \brief fakeface 模型路径
 *  \endif
*/
@property (nonatomic, strong) NSString *fakeface;

/*! \if ENGLISH
 *
 *  \brief 106face point model path
 *  \else
 *
 *  \brief 106点位模型路径
 *  \endif
*/
@property (nonatomic, strong) NSString *_Nullable face;

/*! \if ENGLISH
 *
 *  \brief 240face point  model path
 *  \else
 *
 *  \brief 240点位模型路径
 *  \endif
*/
@property (nonatomic, strong) NSString *face240;

/*! \if ENGLISH
 *
 *  \brief avatar model path
 *  \else
 *
 *  \brief avatar模型路径
 *  \endif
*/
@property (nonatomic, strong) NSString *avatar;

/*! \if ENGLISH
 *
 *  \brief makeup model path
 *  \else
 *
 *  \brief 美妆模型路径
 *  \endif
*/
@property (nonatomic, strong) NSString *makeup;

/*! \if ENGLISH
 *
 *  \brief hand model path
 *  \else
 *
 *  \brief 手势模型路径
 *  \endif
*/
@property (nonatomic, strong) NSString *hand;

/*! \if ENGLISH
 *
 *  \brief segmentation model path
 *  \else
 *
 *  \brief 分割模型路径
 *  \endif
*/
@property (nonatomic, strong) NSString *humanseg;

/*! \if ENGLISH
 *
 *  \brief eyecontour model path
 *  \else
 *
 *  \brief 眼球模型路径
 *  \endif
*/
@property (nonatomic, strong) NSString *eyecontour;

@end

NS_ASSUME_NONNULL_END
