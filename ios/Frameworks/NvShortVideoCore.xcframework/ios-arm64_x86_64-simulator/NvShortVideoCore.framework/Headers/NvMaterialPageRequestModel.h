//
//  NvMaterialPageRequestModel.h
//  NvMaterialLibrary
//
//  单类别资源管理
//
//  Created by 美摄 on 2021/9/1.
//

#import <Foundation/Foundation.h>

#if __has_include(<NvMaterialLibrary/NvMaterial.h>)
#import <NvMaterialLibrary/NvMaterial.h>
#else
#import "NvMaterial.h"
#endif

NS_ASSUME_NONNULL_BEGIN

/*
 两种使用场景
 1，没有内置资源，当前页面展示网络列表+导入测试资源： 导入测试资源在网络列表前，（美映）
 2，有内置资源，当前页面展示导入测试资源+内置资源，全量加载 不做分页，其他页面展示网络列表下载  （美摄sdk demo）
 Two use cases
 1, no built-in resources, the current page shows the network list + Import test resources: import test resources before the network list, (Mei Ying)
 2, there are built-in resources, the current page shows the import test resources + built-in resources, full load without pagination, other pages show the network list download (Beautiful photo sdk demo)
 */

@interface NvMaterialPageRequestModel : NSObject

// 三层分类
// Three-level classification
@property(nonatomic, readonly) NvMaterialType type;
@property(nonatomic, readonly) NSInteger category;
@property(nonatomic, readonly) NSInteger kind;

// 例如：搜索key、pageSize
// For example: search key, pageSize
@property(nonatomic, strong) NSMutableDictionary *optionalRequestParameters;

@property(nonatomic, strong) NSMutableArray<NvMaterial *> *dataArray;

- (instancetype)init NS_UNAVAILABLE;

- (void)addDefaultItems:(NSArray<NvMaterial *> *)items;

// 1，有内置资源，当前页面展示导入测试资源+内置资源，全量加载 不做分页，其他页面展示网络列表下载  （例：美摄sdk demo）
// 1, there are built-in resources, the current page shows the import test resources + built-in resources, full load does not do pagination, other pages show the network list download (example: Beautiful photo sdk demo)
- (void)reloadBondleAssets:(NvRequestSuccess __nullable)success;

// 2，没有内置资源，当前页面展示网络列表+导入测试资源： 导入测试资源在网络列表前，不计入pagesize （例：美映）
// 2, no built-in resources, the current page display network list + import test resources: import test resources in the network list before, not included in pagesize (example: Mei Ying)
- (NSUInteger)refreshSuccess:(NvRequestSuccess __nullable)success failure:(NvRequestFailure __nullable)failure;
- (NSUInteger)loadMoreSuccess:(NvRequestSuccess __nullable)success failure:(NvRequestFailure __nullable)failure;

@end

NS_ASSUME_NONNULL_END
