//
//  NvHttpRequest.h
//  NvCheez
//
//  Created by shizhouhu on 2018/6/5.
//  Copyright © 2018年 shizhouhu. All rights reserved.
//

#import <Foundation/Foundation.h>
#if __has_include(<NvShortVideoCore/NvShortVideoCore.h>)
#import <NvShortVideoCore/NvShortVideoCore.h>
#else
#import "NvShortVideoCore.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@protocol NvHttpRequestDelegate <NSObject>
@optional

@end

@interface NvHttpRequest : NSObject <NvMaterialCenterNetworkDelegate, NvWebImageDelegate>

/// 根据分类获取素材列表
/// Get a list of materials by category
@property(nonatomic,strong)NSString* assetRequestUrl;

/// 根据素材类型获取素材分类列表
/// Gets a classified list of materials based on their type
@property(nonatomic,strong)NSString* assetCategoryUrl;

/// 获取音乐列表
/// Get music list
@property(nonatomic,strong)NSString* assetMusiciansUrl;

/// 获取字体列表
/// Get font list
@property(nonatomic,strong)NSString* assetFontUrl;

/// 把素材的id作为参数传入，获取到素材下载的链接
/// Pass in the id of the material as a parameter to get the link to the material download
@property(nonatomic,strong)NSString* assetDownloadUrl;

/// 获取预制素材
/// Get the Prefabricated material for the project
@property(nonatomic,strong)NSString* assetPrefabricatedUrl;

/// 一键成片
/// AutoCut
@property(nonatomic,strong)NSString* assetAutoCutUrl;

/// 获取模版的标签分类
/// Gets the label classification of the template
@property(nonatomic,strong)NSString* assetTagUrl;

@property(nonatomic,strong)NSString* clientId;
@property(nonatomic,strong)NSString* clientSecret;
@property(nonatomic,strong)NSString* assemblyId;

/// 数据来源
/// 0==所有，1==海外
/// Data source
/// 0==所有，1==海外
@property(nonatomic,assign)NSInteger isAbroad;

+ (NvHttpRequest *)sharedInstance;

@end

NS_ASSUME_NONNULL_END


