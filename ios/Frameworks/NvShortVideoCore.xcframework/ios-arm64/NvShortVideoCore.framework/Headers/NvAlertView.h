//
//  NvAlertView.h
//  NvVideoEditor
//
//  Created by chengww on 2021/11/2.
//  Copyright © 2021 MEISHE. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface NvAlertView : NSObject

+ (UIView *)showAlertWithTitle:(NSString *)title
                       Message:(NSString *)message
                    moduleName:(NSString *)moduleName
                   cancelTitle:(NSString *)cancelTitle
                     doneTitle:(NSString *)doneTitle
                 selectBtIndex:(void (^)(NSInteger))selectBtIndex;

+ (UIView *)showAlertWithTitle:(NSString *)title
                       Message:(NSString *)message
                    moduleName:(NSString *)moduleName
                   cancelTitle:(NSString *)cancelTitle
                     doneTitle:(NSString *)doneTitle
                        config:(NSDictionary *_Nullable)config
                 selectBtIndex:(void (^)(NSInteger))selectBtIndex;

+ (UIView *)showAlertWithMessages:(NSArray <NSString *>*)messages
                       moduleName:(NSString *)moduleName
                   completeHandle:(void (^)(NSInteger selectIndex))handle;

@end

NS_ASSUME_NONNULL_END
