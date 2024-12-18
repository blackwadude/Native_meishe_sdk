//
//  NvAudioWaveView.h
//  AVCaptureSessionAudioTest
//
//  Created by 美摄 on 2020/4/7.
//  Copyright © 2020 KC. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSUInteger, NvWaveType) {
    NvWaveType_wave,        //波形
    NvWaveType_histogram    //柱状图
};


/// 范围 -32767 --  32767

@protocol NvAudioWaveViewDelegate <NSObject>

/// 波形图长度发生了变化
-(void)waveformContentViewSizeChanged;


///// 可以实现改方法，让所有的 NvAudioWaveView 从同一个0 点开始画
//@optional
//-(CGFloat)waveViewDisplayAudioWaveInPoint;

@end

@interface NvAudioWaveView : UIScrollView

@property(weak,nonatomic)id<NvAudioWaveViewDelegate> contentDelegate;

/// 长度和时间比例尺
@property(nonatomic,assign) CGFloat currentTimeLengthScale;

/// 上下间距
@property(nonatomic,readonly) CGFloat waveTopMargin;
@property(nonatomic,readonly) CGFloat waveBottomMargin;

/// 波形图颜色
@property (strong, nonatomic) UIColor *waveColor;

/// 步频
@property(nonatomic,assign) int64_t stepRate;//默认 1

/// 波形图类型，默认: NvWaveType_wave
@property(nonatomic, assign) NvWaveType waveType;

/// 柱状图宽度
@property(nonatomic, assign) CGFloat histogramWidth;
/// 柱状图间隔
@property(nonatomic, assign) CGFloat histogramInterval;

//传入的是标准比例尺，
//属性 currentTimeLengthScale 当前比例尺，
//根据这两个值动态补偿stepRate，应用场景： 轨道缩小时，防止点过密
- (instancetype)initWithFrame:(CGRect)frame
      standardTimeLengthScale:(CGFloat)standardTimeLengthScale
                     waveType:(NvWaveType)waveType;

- (instancetype)initWithFrame:(CGRect)frame
      standardTimeLengthScale:(CGFloat)standardTimeLengthScale;

- (instancetype)init NS_UNAVAILABLE;

//滚到到
-(void)scrollToTrimIn:(int64_t)trimIn animated:(BOOL)animated;

// 改变遮挡范围
-(void)updateVisiableBound:(CGFloat)leftBound right:(CGFloat)rightBound;;

// 设置上下间距
-(void)resetMargin:(CGFloat)waveTopMargin bottom:(CGFloat)waveBottomMargin;

// 修正时长
-(void)resetDuration:(int64_t)duration;

// 加载音频文件
- (void)loadFile:(NSString*)filePath
          trimIn:(int64_t)trimIn
 completionBlock:(void (^ __nullable)(NSMutableData *sampleData,
                                      UInt32 mBitsPerChannel,
                                      NSNumber* maxSampleValue,
                                      int64_t duration))completion;

// 加载换成数据
-(void)updateSampleData:(NSMutableData*)sampleData
        mBitsPerChannel:(UInt32)mBitsPerChannel
              maxSample:(NSNumber*)maxSample
               duration:(int64_t)duration;

@end

NS_ASSUME_NONNULL_END
