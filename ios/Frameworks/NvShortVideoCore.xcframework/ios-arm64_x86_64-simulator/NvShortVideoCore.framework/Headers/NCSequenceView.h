//
//  NCSequenceView.h
//  VideoTrack
//
//  Created by 美摄 on 2020/5/20.
//  Copyright © 2020 美摄. All rights reserved.
//
#import <UIKit/UIScrollView.h>
#import <NvStreamingSdkCore/NvsMultiThumbnailSequenceView.h>

typedef NS_ENUM(NSInteger, NvIconCropMode) {
    NvIconCropModeNone,
    NvIconCropModeHalfLeft,
    NvIconCropModeHalfRight,
    NvIconCropModeHalfTop,
    NvIconCropModeHalfDown,
};


/*! \if ENGLISH
*   \brief Multi-thumbnail sequence information description.
*   \else
*   \brief 多缩略图序列信息描述
*   \endif
*   \since 1.10.0
*/
@interface NCSequenceDesc : NvsThumbnailSequenceDesc

@property(nonatomic,assign)BOOL custom;

@property(nonatomic,strong)NSDictionary<NSString*,NSString*>* customInfo;

@end

NVS_EXPORT @interface NCSequenceView : UIScrollView

@property (nonatomic,assign) NvIconCropMode cropMode;

@property (nonatomic,strong) NSArray <NCSequenceDesc*>*descArray;    //!< \if ENGLISH The thumbnail sequence describes the array. Note: Once it has been set, altering array contents will not work unless one sets the thumbnail sequence description array again. NVSThumbNailSequenceDesc should be arranged in the order of InPoint from small to large, and the time segments represented by InPoint and OutPoint should not overlap. \else 缩略图序列描述数组。注意：一旦设置，再修改数组里面的内容是不起作用的，除非再次设置缩略图序列描述数组。NVSThumbNailSequenceDesc应该按照InPoint从小到大的顺序排列，InPoint和OutPoint所代表的时间段不能重叠。 \endif
@property (nonatomic,assign) CGFloat thumbnailAspectRatio;                     //!< \if ENGLISH Thumbnail aspect ratio,default:9.0/16 \else 单张缩略图横纵比，默认值：9.0/16 \endif
@property (nonatomic,assign) double pointsPerMicrosecond;                      //!< \if ENGLISH Scale bar, the number of points occupied per microsecond. default: 720.0/15000000 \else 时间和像素比例尺，每微秒所占用的point数量，默认值：720.0/15000000 \endif
@property (nonatomic,assign) CGFloat startPadding;                             //!< \if ENGLISH Starting padding in unit of point. \else 起始边距，单位为point \endif
@property (nonatomic,assign) CGFloat endPadding;                               //!< \if ENGLISH Ending padding in unit of point. \else 结束边距，单位为point \endif
@property (nonatomic,assign) NvsThumbnailImageFillMode thumbnailImageFillMode; //!< \if ENGLISH Thumbnail image fill mode,default: NvsThumbnailFillModeStretch \else 缩略图图片填充模式，默认值：NvsThumbnailFillModeStretch \endif
@property (nonatomic,assign) int64_t maxTimelinePosToScroll;                   //!< \if ENGLISH The maximum timeline position (in microseconds) that is allowed to scroll. The default value is 0, which means no limit. \else 允许滚动的最大时间线位置(单位微秒)，默认值为0，表示不做限制 \endif

- (instancetype)init;
- (instancetype)initWithFrame:(CGRect)frame;
- (instancetype)initWithCoder:(NSCoder *)aDecoder;

/*! \if ENGLISH
 *  \brief Set up edit mode, When descArray is set, the contentoffSize and contentSize are not reset to avoid the thumbnail flashing,contentOffset and contentSize shoule be reset
 *  \param height Height of thumbnail image, Default: Height of UIScrollView.If the height of the thumbnail is less than the height of the UIScrollView, You can add a custom view below the thumbnail that scrolls along with the thumbnail. If the height of the thumbnail is greater than the UIScrollView height, the excess part will not respond to the gesture event.
 *  \else
 *  \brief 设置编辑模式可用  编辑模式下，设置descArray时不会重置contentOffsize和contentSize，避免缩略图闪动，需要外部设置contentOffsize和contentSize
 *  \param height 缩略图高度，默认值：和UIScrollView等高。如果缩略图高度小于UIScrollView高度，会漏出部分UIScrollView，可在缩略图下面添加随缩略图一起滚动的自定义视图。如果缩略图高度大于UIScrollView高度，超出部分不会响应手势事件。
 *  \endif
 *  \since 2.15.0
 *  \sa reloadClipData
*/
-(void)enableClipEditModeWithThumnailHeight:(CGFloat)height;

/*! \if ENGLISH
 *  \brief Maps the X coordinate of the control to the timeline position.
 *  \param x The X coordinate of the control(in points).
 *  \return Returns the timeline position of the map(in microseconds).
 *  \else
 *  \brief 将控件的X坐标映射到时间线位置
 *  \param x 控件的X坐标，单位为point
 *  \return 返回映射的时间线位置，单位为微秒
 *  \endif
 *  \sa mapXFromTimelinePos
*/
- (int64_t)mapTimelinePosFromX:(CGFloat)x;

/*! \if ENGLISH
 *  \brief Maps the timeline position to the X coordinate of the control.
 *  \param timelinePos Timeline position(in microseconds)
 *  \return Returns the mapped X coordinate of the control(in points).
 *  \else
 *  \brief 将时间线位置映射到控件的X坐标
 *  \param timelinePos 时间线位置，单位为微秒
 *  \return 返回映射的控件的X坐标，单位为point
 *  \endif
 *  \sa mapTimelinePosFromX
*/
- (CGFloat)mapXFromTimelinePos:(int64_t)timelinePos;

/*! \if ENGLISH
 *  \brief Zooms the current scale.
 *  \param scaleFactor  Scale ratio,Value range：>0
 *  \param anchorX X coordinate of scaled anchor(in points).
 *  \else
 *  \brief 缩放当前比例尺
 *  \param scaleFactor 缩放的比例,取值范围：>0
 *  \param anchorX 缩放的锚点X坐标，单位为point
 *  \endif
*/
- (void)scale:(double)scaleFactor withAnchor:(CGFloat)anchorX;

-(void)updateDescArray:(NSArray <NCSequenceDesc*>*)descArray startPadding:(CGFloat)startPadding;

@end

