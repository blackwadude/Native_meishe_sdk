//
//  NvPushManager.h
//  NvShortVideoCore
//
//  Created by ms20221114 on 2024/3/13.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class NvsTimeline;

typedef NS_ENUM(NSInteger, NvEditResultSource) {
    NvEditResultSourceEdit,
    NvEditResultSourceTemplate
};

@interface NvPushManager : NSObject

+ (void)createdPushPage:(NvsTimeline *)timeline
            resultVideo:(NSString *_Nullable)resultVideo
           resultSource:(NvEditResultSource)resultSource
                    nav:(UINavigationController *_Nullable)nav;

+ (void)selectCover:(NvsTimeline *)timeline 
           coverPos:(int64_t)coverPos
          coverPath:(NSString *)coverPath
          projectId:(NSString *_Nullable)projectId
                nav:(UINavigationController *_Nullable)nav
  completionHandler:(void(^_Nullable)(NSString *_Nullable imagePath, int64_t coverPos))completionHandler;

@end

NS_ASSUME_NONNULL_END

