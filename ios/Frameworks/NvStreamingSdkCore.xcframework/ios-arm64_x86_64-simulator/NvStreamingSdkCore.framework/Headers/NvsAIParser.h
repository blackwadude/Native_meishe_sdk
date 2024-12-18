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
#pragma once
#import "NvsObject.h"

NS_ASSUME_NONNULL_BEGIN

@protocol AIParserDelegate <NSObject>
@optional
- (void)onParserStarted:(NSString*)mediaPath taskId:(int64_t)taskId;
- (void)onParserFinished:(NSString*)mediaPath scdPath:(NSString*)scdPath;
- (void)onParserError:(int)errorType;
- (void)onParserProgress:(NvsVideoFrameInfo *_Nullable)videoFrameInfo mediaPath:(NSString*)mediaPath progress:(float)progress;

@end

typedef enum {
    NvsAIParserFlag_None = 0,
    NvsAIParserFlag_OnlyDetectKeyFrameFrameSpace = 1000000,
} NvsAIParserFlag;

NVS_EXPORT @interface NvsDetectData : NSObject

@property(nonatomic, strong) NSString *mediaPath;
@property(nonatomic, assign) int frameSpace;
@property(nonatomic, assign) NvsSize detectSize;
@property(nonatomic, assign) int year;
@property(nonatomic, assign) int month;
@property(nonatomic, assign) int day;
@property(nonatomic, assign) int hour;
@property(nonatomic, assign) int minute;
@property(nonatomic, assign) int second;

@end

NVS_EXPORT @interface NvsAIParser : NSObject

+ (instancetype)sharedInstance;
+ (instancetype)sharedInstanceWithFlags:(int)flags;
@property (nonatomic, weak) id<AIParserDelegate> delegate;

+ (void)destroyInstance;

- (BOOL)parseMediaFiles:(NSArray <NvsDetectData*>*)dataList;

- (void)cancelTask:(int64_t)taskId;

- (void)cancelAllTasks;

- (void)suspend;

- (void)resume;

- (void)setGlobalFrameSpace:(int)frameSpace;

- (void)disableGlobalFrameSpace;

@end

NS_ASSUME_NONNULL_END
