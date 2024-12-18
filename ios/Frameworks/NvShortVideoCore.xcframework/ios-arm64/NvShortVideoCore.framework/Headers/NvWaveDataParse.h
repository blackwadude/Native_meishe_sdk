//
//  NvWaveDataParse.h
//  bilistudio
//
//  Created by Kirk on 2020/6/15.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, NvParseChannelType) {
    NvParseChannelType_left,
    NvParseChannelType_right,
    NvParseChannelType_hybrid//不区分声道 左右各取一个点比较 / Take the left and the right
};

@interface NvWaveDataParse : NSObject

@property(nonatomic,assign) NvParseChannelType parsepType;

@property(nonatomic,strong) NSMutableData *sampleData;
@property(nonatomic,assign) UInt32    mBitsPerChannel;
@property(nonatomic,strong) NSNumber* maxSample;

@property(nonatomic,assign) int64_t duration;

/// 取值片段时长  默认10000   1s 100个点
/// Value Segment length The default length is 10000 1s and 100 points
@property(nonatomic,assign) int64_t samplingInterval;

-(instancetype)init;

- (void)loadAudioSamplesFromFilePath:(NSString*)filePath
                  completionBlock:(void (^ __nullable)(NSMutableData *sampleData,UInt32 mBitsPerChannel,NSNumber* maxSample))completionBlock;

- (void)loadAudioSamplesFromAsset:(AVAsset *)asset
completionBlock:(void (^ __nullable)(NSMutableData *sampleData,UInt32 mBitsPerChannel,NSNumber* maxSample))completionBlock;

-(void)appendSampleBuffer:(CMSampleBufferRef)sampleBuffer;

-(void)prepareForReuse;

@end

NS_ASSUME_NONNULL_END
