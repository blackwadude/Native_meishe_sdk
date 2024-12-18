//
//  NvSqlite3Operator.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/5/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NvSqlite3Operator : NSObject

+ (BOOL)beginEdit:(Class)model_object;

+ (void)endEdit;

+ (NSArray *)query:(Class)model_class;

+ (NSArray *)query:(Class)model_class where:(NSString *)where;

+ (BOOL)delete:(Class)model_class where:(NSString *)where;

+ (BOOL)insert:(id)model_object;

+ (BOOL)inserts:(NSArray *)model_array;



@end

NS_ASSUME_NONNULL_END
