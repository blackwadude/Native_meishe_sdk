//
//  NvWebImageDelegate.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/7/8.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol NvWebImageDelegate <NSObject>

/**
 Fetches an image from the specified URL and sets it on the provided image view.

 @param imageView The image view to set the fetched image.
 @param url The URL of the image to fetch.
 @param placeholder The placeholder image to display while fetching the image. Can be nil.
 @param completion A block to be executed when the image fetching and setting is completed. The block takes a UIImage parameter that represents the fetched image, which may be nil if the image couldn't be fetched or set.
 */
- (void)fetchImageForImageView:(UIImageView *)imageView
                          url:(NSURL *)url
                  placeholder:(UIImage *_Nullable)placeholder
                   completion:(void (^ _Nullable)(UIImage * _Nullable image))completion;

@end

NS_ASSUME_NONNULL_END
