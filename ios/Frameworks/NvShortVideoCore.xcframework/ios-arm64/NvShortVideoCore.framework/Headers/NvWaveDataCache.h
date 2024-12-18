//
//  NvWaveDataCache.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/2/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NvWaveData : NSObject <NSCoding>

@property (nonatomic, strong) NSMutableData *sampleData;
@property (nonatomic, assign) UInt32 mBitsPerChannel;
@property (nonatomic, strong) NSNumber* maxSampleValue;
@property (nonatomic, assign) int64_t duration;

@end

@interface NvWaveDataCache : NSObject

- (BOOL)setCacheWaveData:(NvWaveData *)waveData key:(NSString *)key;

- (NvWaveData *)cacheWaveDataForKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
