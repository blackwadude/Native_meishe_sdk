//
//  NvRecognitionTextItem.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/5/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NvRecognitionTextItem : NSObject

@property (nonatomic, strong) NSMutableString *text;
@property (nonatomic, assign) int64_t inPoint;
@property (nonatomic, assign) int64_t outPoint;

@end

NS_ASSUME_NONNULL_END
