//
//  NvEditProjectInfo.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/5/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NvEditProjectInfo : NSObject

/*! \if ENGLISH
 *
 *  \brief The identifier of project
 *  \else
 *
 *  \brief 项目id
 *  \endif
 */
@property (nonatomic, strong) NSString *projectId;

/*! \if ENGLISH
 *
 *  \brief Project description
 *  \else
 *
 *  \brief 项目描述
 *  \endif
 */
@property (nonatomic, strong) NSString *projectDescription;


/*! \if ENGLISH
 *
 *  \brief The last time of project modified
 *  \else
 *
 *  \brief 最后修改时间
 *  \endif
 */
@property (nonatomic, strong) NSString * lastModifiedTime;

/*! \if ENGLISH
 *
 *  \brief the duration of timeline
 *  \else
 *
 *  \brief 项目时长
 *  \endif
 */
@property (nonatomic, assign) int64_t duration;

/*! \if ENGLISH
 *
 *  \brief The image of draft
 *  \else
 *
 *  \brief 草稿封面图片
 *  \endif
 */
@property (nonatomic, strong) NSString * coverImagePath;

/*! \if ENGLISH
 *
 *  \brief Cover time
 *  \else
 *
 *  \brief 封面时间
 *  \endif
 */
@property (nonatomic, assign) int64_t coverPos;

@end

NS_ASSUME_NONNULL_END
