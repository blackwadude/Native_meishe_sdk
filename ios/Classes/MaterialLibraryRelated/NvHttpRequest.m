
//
//  NvHttpRequest.m
//  NvCheez
//
//  Created by meishe on 2018/6/5.
//  Copyright © 2018年 meishe. All rights reserved.
//

#import "NvHttpRequest.h"
#import <CommonCrypto/CommonDigest.h>

#if __has_include(<SDWebImageWebPCoder/SDWebImageWebPCoder.h>)
#import <SDWebImage/SDWebImage.h>
#import <SDWebImageWebPCoder/SDWebImageWebPCoder.h>
#endif

#if __has_include(<SSZipArchive/SSZipArchive.h>)
#import <SSZipArchive/SSZipArchive.h>
#endif

#define DownloadMaterialZIP

@interface NvHttpRequest()

@property(nonatomic, strong) NSString* downloadTmpPath;

@property(nonatomic, strong) NSString* machineId;

@property(nonatomic, strong) NSURLSession *urlSession;

@end

@implementation NvHttpRequest

static NvHttpRequest *sharedInstance = nil;

+ (NvHttpRequest *)sharedInstance {
    if (nil != sharedInstance) {
        return sharedInstance;
    }
    
    static dispatch_once_t pred;
    dispatch_once(&pred, ^{
        sharedInstance = [[NvHttpRequest alloc] init];
    });
    
    return sharedInstance;
}

- (instancetype)init {
    self = [super init];
    if (self) {
        //准备下载临时路径
        NSString* sourcePath = @"tmp";
        NSString *documentPath = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES).firstObject;
        self.downloadTmpPath = [documentPath stringByAppendingPathComponent:sourcePath];
        NSFileManager* fm = [NSFileManager defaultManager];
        if (![fm fileExistsAtPath:self.downloadTmpPath]) {
            [fm createDirectoryAtPath:self.downloadTmpPath withIntermediateDirectories:NO attributes:nil error:nil];
        }
        
        self.machineId = [NSUUID UUID].UUIDString;
        
        NSURLSessionConfiguration *configuration = [NSURLSessionConfiguration defaultSessionConfiguration];
        self.urlSession = [NSURLSession sessionWithConfiguration:configuration];
        
        // Add coder
        SDImageWebPCoder *webPCoder = [SDImageWebPCoder sharedCoder];
        [[SDImageCodersManager sharedManager] addCoder:webPCoder];
    }
    return self;
}

-(NSDictionary*)defaultParameters{
    NSMutableDictionary* mutDic = [NSMutableDictionary dictionary];
    mutDic[@"assemblyId"] = self.assemblyId;
    mutDic[@"clientId"] = self.clientId;
    mutDic[@"machineId"] = self.machineId;
    mutDic[@"nonceStr"] = [NSString stringWithFormat:@"%.0f",[[NSDate date] timeIntervalSince1970]];
    // lang
    NSString *languageStr = NSLocale.preferredLanguages.firstObject;
    if (languageStr) {
        mutDic[@"lang"] = [NvHttpRequest currentLang];
    }
    return mutDic;
}

+ (NSString *)currentLang{
    
    NSString * currentLang =  [[NSLocale preferredLanguages] objectAtIndex:0];
    NSString * lang = @"en";
    NSArray *languageCodes = @[@"en", @"zh", @"es", @"ar", @"de", @"el", @"fi", @"fr", @"hi", @"id", @"it", @"ja", @"ko", @"nl", @"pl", @"pt", @"ru", @"tr", @"he", @"sv"];
    for (NSString *code in languageCodes) {
    
        if ([currentLang hasPrefix:code]) {
            
            if([code isEqualToString:@"zh"]){
                lang = @"zh-cn";
            }else{
                lang = code;
            }
            break;
        }
    }
    return lang;
}

-(NSString*)signParameters:(NSDictionary*)parameters{
    //1,按照参数名ASCII码从小到大排序
    
    NSMutableString* signString = [NSMutableString string];
//    NSArray<NSString*>* sortArray = @[@"assemblyId",@"clientId",@"nonceStr"];
    NSArray* sortArray = [parameters.allKeys sortedArrayUsingComparator:^NSComparisonResult(NSString*  _Nonnull obj1, NSString*  _Nonnull obj2) {
        return [obj1 compare:obj2];
    }];
    for (NSString* key in sortArray) {
        [signString appendFormat:@"%@=%@",key,parameters[key]];
        [signString appendString:@"&"];
    }
    //2,将得到的字符串和密钥进行拼接，
    [signString appendFormat:@"clientSecret=%@",self.clientSecret];
    //3,将得到的字符串用md5加密(注意拼串不要有空格和换行)，得到32位小写加密串
    return [self md5HexDigest:signString];
}

- (NSString* )md5HexDigest:(NSString* )psw {
    if (psw && psw.length > 0) {
        NSMutableString * encrypt = [NSMutableString string];
        const char * cStr = psw.UTF8String;
        unsigned char buffer[CC_MD5_DIGEST_LENGTH];
        memset(buffer, 0x00, CC_MD5_DIGEST_LENGTH);
        CC_MD5(cStr, (CC_LONG)(strlen(cStr)), buffer);
        for (int i = 0; i < CC_MD5_DIGEST_LENGTH; i++) {
            [encrypt appendFormat:@"%02x",buffer[i]];
        }
        return encrypt;
    }
    return psw;
}

- (void)RequestListCategoryWithType:(NSInteger)type
                           category:(NSString *)category
          optionalRequestParameters:(NSMutableDictionary *)optionalRequestParameters
                            success:(NvRequestSuccess)success
                            failure:(NvRequestFailure)failure{
    
    NSMutableDictionary* requestParameters = [NSMutableDictionary dictionary];
    
    if (optionalRequestParameters && optionalRequestParameters.count > 0) {
        requestParameters = [NSMutableDictionary dictionaryWithDictionary:optionalRequestParameters];
    }
    
    [requestParameters addEntriesFromDictionary:[self defaultParameters]];
    
    int large,minor,revision;
    [NvsStreamingContext getSdkVersion:&large minorVersion:&minor revisionNumber:&revision];
    NSString *sdkVersion = [NSString stringWithFormat:@"%d.%d.%d",large,minor,revision];
    
    NSDictionary *body = @{@"types":@(type),@"categories":category,@"sdkVersion":sdkVersion};
    if (category.length == 0) {
        body = @{@"types":@(type),@"sdkVersion":sdkVersion};
    }
    
    [requestParameters addEntriesFromDictionary:body];
    
    if (self.isAbroad != 0){
        [requestParameters setValue:@(self.isAbroad) forKey:@"isAbroad"];
    }
    requestParameters[@"sign"] = [self signParameters:requestParameters];
    
    [self GET:self.assetCategoryUrl parameters:requestParameters success:^(id responseObject) {
        NSString *packageType = @"";
        BOOL assembleKinds = NO;
        
        if (optionalRequestParameters[@"packageType"]){
            packageType = optionalRequestParameters[@"packageType"];
        }
        if (optionalRequestParameters[@"assembleKinds"]){
            assembleKinds = [optionalRequestParameters[@"assembleKinds"] boolValue];
        }
        int errNo = [[responseObject objectForKey:@"code"] intValue];
        if(errNo == 1){
            NSArray* resData = [responseObject objectForKey:@"data"];
            NSArray* array = [resData.firstObject objectForKey:@"categories"];
            
            NSMutableDictionary *mutableDictionary = [NSMutableDictionary dictionary];
            NSMutableArray *mutableArray = [NSMutableArray array];
            
            NSInteger index = 0;
            for (NSDictionary *dict in array) {
                if (dict[@"id"]){
                    if ([dict[@"kinds"] count] <= 0 || !assembleKinds){
                        NvMaterial *model = [[NvMaterial alloc]init];
                        model.indexCode = index;
                        model.type = type;
                        model.category = [dict[@"id"] integerValue];
                        model.displayName = dict[@"displayName"];
                        [mutableArray addObject:model];
                        
                        index++;
                    }
                    
                    NSMutableDictionary *tempDict = [NSMutableDictionary dictionary];
                    [mutableDictionary setValue:tempDict forKey:[NSString stringWithFormat:@"%@",dict[@"id"]]];
                    
                    if (dict[@"displayName"]){
                        [tempDict setValue:dict[@"displayName"] forKey:@"title"];
                        [tempDict setValue:dict[@"displayName"] forKey:@"folderName"];
                    }
                    
                    NSMutableDictionary *tempDict_1 = [NSMutableDictionary dictionary];
                    [tempDict setValue:tempDict_1 forKey:@"kind"];
                    
                    for (NSDictionary *dict_1 in dict[@"kinds"]) {
                        NSMutableDictionary *tempDict_2 = [NSMutableDictionary dictionary];
                        [tempDict_1 setValue:tempDict_2 forKey:[NSString stringWithFormat:@"%@",dict_1[@"id"]]];
                        
                        if (dict_1[@"displayName"]){
                            [tempDict_2 setValue:dict_1[@"displayName"] forKey:@"title"];
                            [tempDict_2 setValue:dict_1[@"displayName"] forKey:@"folderName"];
                        }
                        
                        [tempDict_2 setValue:@[packageType] forKey:@"packExtension"];
                        
                        if (assembleKinds){
                            NvMaterial *model = [[NvMaterial alloc]init];
                            model.indexCode = index;
                            model.type = type;
                            model.category = [dict[@"id"] integerValue];
                            model.kind = [dict_1[@"id"] integerValue];
                            model.displayName = dict_1[@"displayName"];
                            
                            index++;
                            [mutableArray addObject:model];
                        }
                    }
                }
            }
            
            NSDictionary *dictionary = @{@"category":mutableDictionary};
            NSDictionary *currentTata = @{[NSString stringWithFormat:@"%@",@(type)]:dictionary};
            dispatch_async(dispatch_get_main_queue(), ^{
                success(mutableArray, NO, currentTata);
            });
        }else{
            dispatch_async(dispatch_get_main_queue(), ^{
                failure(nil);
            });
        }
    } failure:^(NSError * error) {
        failure(error);
    }];
}

- (NSInteger)requestDataWithType:(NvMaterialType)type
                         category:(NSInteger)category
                             kind:(NSInteger)kind
        optionalRequestParameters:(NSMutableDictionary*)optionalRequestParameters
                        pageIndex:(NSInteger)pageIndex
                          success:(NvRequestSuccess)success
                          failure:(NvRequestFailure)failure{
    
    NSMutableDictionary* requestParameters = [NSMutableDictionary dictionaryWithDictionary:optionalRequestParameters];
    requestParameters[@"pageNum"] = @(pageIndex+1);
    [requestParameters addEntriesFromDictionary:[self defaultParameters]];
    
    if (type != 0) {
        requestParameters[@"type"] = @(type);
    }
    if (category != 0) {
        requestParameters[@"category"] = @(category);
    }
    if (kind != 0) {
        requestParameters[@"kind"] = @(kind);
    }
    if (self.isAbroad != 0){
        [requestParameters setValue:@(self.isAbroad) forKey:@"isAbroad"];
    }
    requestParameters[@"sign"] = [self signParameters:requestParameters];
    NSURLSessionDataTask *dataTask = [self GET:self.assetRequestUrl
                                    parameters:requestParameters
                                       success:^(id responseObject) {
        int errNo = [[responseObject objectForKey:@"code"] intValue];
        if(errNo == 1){
            NSDictionary* resData = [responseObject objectForKey:@"data"];
            NSDictionary* elements = [resData objectForKey:@"elements"];
            BOOL hasMore = YES;
            if (elements.count > 0) {
                NSInteger pageSize = [[resData objectForKey:@"pageSize"] integerValue];
                if (elements.count < pageSize) {
                    hasMore = NO;
                } else {
                    NSInteger pageNum = [[resData objectForKey:@"pageNum"] integerValue];
                    NSInteger tatal = [[resData objectForKey:@"total"] integerValue];
                    NSInteger nNumber = pageSize * pageNum;
                    if (nNumber >= tatal) {
                        hasMore = NO;
                    }
                }
            } else {
                hasMore = NO;
            }
            NSArray* array = [NSArray yy_modelArrayWithClass:[NvMaterial class] json:elements];
            success(array, hasMore, resData);
        }else{
            failure(nil);
        }
    } failure:^(NSError * error) {
        failure(error);
    }];
    return dataTask.taskIdentifier;
}

-(void)requestDataWithType:(NvMaterialType)type
 optionalRequestParameters:(NSMutableDictionary*)optionalRequestParameters
                 pageIndex:(NSInteger)pageIndex
                modelClass:(Class)modelClass
                   success:(MsRequestSuccess)success
                   failure:(MsRequestFailure)failure{
    
    NSMutableDictionary* requestParameters = [NSMutableDictionary dictionaryWithDictionary:optionalRequestParameters];
    requestParameters[@"pageNum"] = @(pageIndex+1);
    if (type != NvMaterialTypeMusic) {
        [requestParameters addEntriesFromDictionary:[self defaultParameters]];
    }
    
    requestParameters[@"sign"] = [self signParameters:requestParameters];
    if (type != NvMaterialTypeUndefined) {
        requestParameters[@"type"] = @(type);
    }
    
    NSString * urlString = type == NvMaterialTypeMusic ? self.assetMusiciansUrl : self.assetFontUrl;
    [self GET:urlString parameters:requestParameters success:^(id responseObject) {
        int errNo = [[responseObject objectForKey:@"code"] intValue];
        if(errNo == 1){
            NSDictionary* resData = [responseObject objectForKey:@"data"];
            NSDictionary* elements = [resData objectForKey:@"elements"];
            NSArray* array = [NSArray yy_modelArrayWithClass:[modelClass class] json:elements];
            success(array, resData, YES);
        }else{
            failure(nil);
        }
    } failure:^(NSError * error) {
        failure(error);
    }];
}

-(NSInteger)downloadMaterial:(NvMaterial*)material
                 targetFolder:(NSString*)targetFolder
             packExtensionSet:(NSMutableArray* __nullable)packExtensionSet
                optParameters:(NSMutableDictionary* __nullable)optParameters
                     progress:(void (^)(float progress)) downloadProgressBlock
            completionHandler:(void (^)(NSString * __nullable packagePath,
                                        NSString * __nullable packageLicPath,
                                        NSString * __nullable packageJsonPath,
                                        NSString * __nullable packageId,
                                        NSError *__nullable error))completionHandler {
    // download zip
    if (material.packageUrl && material.packageUrl.length > 0) {
        return [self requestDownloadMaterial:material
                                  packageUrl:material.packageUrl
                                targetFolder:targetFolder
                            packExtensionSet:packExtensionSet
                               optParameters:optParameters
                                    progress:downloadProgressBlock
                           completionHandler:completionHandler];
    } else {
        __weak typeof(self) weakSelf = self;
        NSURLSessionDataTask *task = [self actionRequest:material
                                           optParameters:optParameters
                                                  action:@"1"
                                       completionHandler:^(NSURLResponse * _Nonnull response,
                                                           id  _Nullable responseObject,
                                                           NSError * _Nullable error) {
            if (error) {
                completionHandler(nil,nil,nil,material.uuid,error);
            }else{
                if (!responseObject) {
                    NSLog(@"素材下载地址url请求失败 The url request for the material download address failed. Procedure");
                    NSLog(@"responseObject=%@,material.uuid=%@",responseObject,material.uuid);
                    completionHandler(nil,nil,nil,material.uuid,nil);
                }else{
                    int errNo = [[responseObject objectForKey:@"code"] intValue];
                    NSDictionary* resData = [responseObject objectForKey:@"data"];
                    if(errNo == 1 && resData){
                        NSString* packageUrl = resData[@"packageUrl"];
                        if (packageUrl) {
                            [weakSelf requestDownloadMaterial:material
                                                   packageUrl:packageUrl
                                                 targetFolder:targetFolder
                                             packExtensionSet:packExtensionSet
                                                optParameters:optParameters
                                                     progress:downloadProgressBlock
                                            completionHandler:completionHandler];
                        }else{
                            NSLog(@"素材下载地址url请求失败 The url request for the material download address failed. Procedure");
                            NSLog(@"responseObject=%@,material.uuid=%@",responseObject,material.uuid);
                            completionHandler(nil,nil,nil,material.uuid,nil);
                        }
                    }else{
                        NSLog(@"素材下载地址url请求失败 The url request for the material download address failed. Procedure");
                        NSLog(@"responseObject=%@,material.uuid=%@",responseObject,material.uuid);
                        completionHandler(nil,nil,nil,material.uuid,nil);
                    }
                }
            }
        }];
        
        [task resume];
        return task.taskIdentifier;
    }
}

#pragma mark - 获取通过素材的uuid，获取下载链接，主要是为了记录，用户点击素材的次数
/// Get the uuid of the material, get the download link, mainly to record the number of times the user clicks on the material
-(NSURLSessionDataTask*)actionRequest:(NvMaterial*)material
             optParameters:(NSMutableDictionary*)optParameters
                    action:(NSString*)action
            completionHandler:(void (^)(NSURLResponse * _Nonnull response, id  _Nullable responseObject,
                                        NSError *__nullable error))completionHandler{
    NSMutableDictionary* requestParameters = [NSMutableDictionary dictionaryWithDictionary:optParameters];
    [requestParameters addEntriesFromDictionary:[self defaultParameters]];
    requestParameters[@"materialId"] = material.uuid;
    requestParameters[@"action"] = action;
    requestParameters[@"sign"] = [self signParameters:requestParameters];
    
    //HttpBody的形式
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:self.assetDownloadUrl]];
    [request setHTTPMethod:@"POST"];
    NSError* error = nil;
    [request setHTTPBody:[NSJSONSerialization dataWithJSONObject:requestParameters options:NSJSONWritingPrettyPrinted error:&error]];
    if (error) {
        NSLog(@"%@",error);
    }
    [request setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
    [request setValue:@"application/json" forHTTPHeaderField:@"Accept"];
    NSURLSessionDataTask *task = [self.urlSession dataTaskWithRequest:request completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {
        NSError *jsonError;
        id responseObject = [NSJSONSerialization JSONObjectWithData:data options:0 error:&jsonError];
        dispatch_async(dispatch_get_main_queue(), ^{
            completionHandler(response, responseObject, error);
        });
    }];
    [task resume];
    return task;
}

typedef void (^NvDownloadCompletionHandler)(NSString * __nullable packagePath,
                                            NSString * __nullable packageLicPath,
                                            NSString * __nullable packageJsonPath,
                                            NSString * __nullable packageId,
                                            NSError * __nullable error);


-(NSInteger)requestDownloadMaterial:(NvMaterial *)material
                          packageUrl:(NSString *)packageUrl
                        targetFolder:(NSString *)targetFolder
                    packExtensionSet:(NSMutableArray *)packExtensionSet
                       optParameters:(NSMutableDictionary *)optParameters
                            progress:(void (^)(float progress)) downloadProgressBlock
                   completionHandler:(void (^)(NSString * __nullable packagePath,
                                               NSString * __nullable packageLicPath,
                                               NSString * __nullable packageJsonPath,
                                               NSString * __nullable packageId,
                                               NSError *__nullable error))completion {
    
    NvDownloadCompletionHandler completionHandler = ^(NSString * __nullable packagePath,
    NSString * __nullable packageLicPath,
    NSString * __nullable packageJsonPath,
    NSString * __nullable packageId,
    NSError *__nullable error) {
        if (completion) {
            dispatch_async(dispatch_get_main_queue(), ^{
                completion(packagePath, packageLicPath, packageJsonPath, packageId, error);
            });
        }
    };
    
    NSString* packageUUID = material.uuid;
    NSFileManager* fm = [NSFileManager defaultManager];
    NSURLSessionDownloadTask *downloadTask = [self.urlSession downloadTaskWithURL:[NSURL URLWithString:packageUrl]
                                                                completionHandler:^(NSURL * _Nullable location,
                                                                                    NSURLResponse * _Nullable response,
                                                                                    NSError * _Nullable error) {
        if (error) {
            completionHandler(nil, nil, nil, material.uuid, error);
        } else {
            if (material.type == NvMaterialTypeMusic ||
                material.type == NvMaterialTypeFont) {
                NSString *fileName = [material.uuid stringByAppendingPathExtension:packageUrl.pathExtension];
                NSString *filePath = [targetFolder stringByAppendingPathComponent:fileName];
                NSError *moveError = nil;
                [fm moveItemAtURL:location toURL:[NSURL fileURLWithPath:filePath] error:&moveError];
                if (moveError) {
                    completionHandler(nil, nil, nil, material.uuid, moveError);
                } else {
                    completionHandler(filePath, nil, nil, material.uuid, error);
                }
                return;
            }
            if ([packageUrl hasSuffix:@"mp4"]){
                [NSFileManager.defaultManager moveItemAtPath:location.path toPath:targetFolder error:nil];
                completionHandler(location.path, nil, nil, material.uuid,error);
                return;
            }
            
#ifndef DownloadMaterialZIP
            //1, 不需要lic文件，下载.videofx包，复制到目标路径
            
            NSError* copyError = nil;
            NSString* targetFile = [targetFolder stringByAppendingPathComponent:filePath.absoluteString.lastPathComponent];
            if ([fm fileExistsAtPath:targetFile]) {
                [fm removeItemAtPath:targetFile error:nil];
            }
            [fm copyItemAtURL:filePath toURL:[NSURL fileURLWithPath:targetFile] error:&copyError];
            if (copyError) {
                completionHandler(nil,nil,copyError);
            }else{
                completionHandler(targetFile,nil,error);
            }
            [fm removeItemAtURL:filePath error:nil];
#else
            //2，下载的是zip，解压出.videofx和.lic文件，解压到目标路径
            NSError* unpackError = nil;
            NSString* zipFileNameFull = packageUrl.lastPathComponent;//response.suggestedFilename;//
            NSString* zipFileName = zipFileNameFull.stringByDeletingPathExtension;
            NSString* unzipPath = [self.downloadTmpPath stringByAppendingPathComponent:zipFileName];
            [fm removeItemAtPath:unzipPath error:nil];
            if ([self unzipWithPath:location.path destination:unzipPath]) {
                //根据packExtensionSet中后缀名找文件,移动到targetFolder
                if (material.type == NvMaterialTypeLooks) {
                    //需要解压妆容
                    __block NSString *packageFile = @"";
                    NSArray<NSString *> *subpaths = [[NSFileManager defaultManager] subpathsAtPath:unzipPath];
                    [subpaths enumerateObjectsUsingBlock:^(NSString * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                        if ([obj hasSuffix:@"zip"]) {
                            packageFile = [unzipPath stringByAppendingPathComponent:obj];
                            *stop = YES;
                        }
                    }];
                    NSString* targetFile = [targetFolder stringByAppendingPathComponent:material.uuid];
                    if ([[NSFileManager defaultManager] fileExistsAtPath:targetFile]) {
                        [[NSFileManager defaultManager] removeItemAtPath: targetFile error:nil];
                    }else {
                        [[NSFileManager defaultManager] createDirectoryAtPath:targetFile withIntermediateDirectories:YES attributes:nil error:nil];
                    }
                    if (packageFile.length > 0){
                        if ([self unzipWithPath:packageFile destination:targetFile]) {
                            [[[NSFileManager defaultManager] subpathsAtPath:unzipPath] enumerateObjectsUsingBlock:^(NSString * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                                if ([obj hasSuffix:@"lic"]) {
                                    NSString *licPath = [unzipPath stringByAppendingPathComponent:obj];
                                    [[NSFileManager defaultManager] moveItemAtPath:licPath toPath:[targetFile stringByAppendingPathComponent:obj] error:nil];
                                }
                            }];
                            completionHandler(targetFile,nil,nil,material.uuid,unpackError);
                        } else {
                            completionHandler(nil,nil,nil,material.uuid,unpackError);
                        }
                    } else {
                        packageFile = unzipPath;
                        
                        // 遍历源文件夹中的所有文件和子文件夹
                        NSError *error;
                        NSArray *items = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:packageFile error:&error];
                        if (error) {
                            completionHandler(nil,nil,nil,material.uuid,error);
                            return;
                        }
                        
                        for (NSString *item in items) {
                            NSString *sourceItemPath = [packageFile stringByAppendingPathComponent:item];
                            NSString *destinationItemPath = [targetFile stringByAppendingPathComponent:item];
                            
                            // 是文件，直接拷贝文件
                            [[NSFileManager defaultManager] copyItemAtPath:sourceItemPath toPath:destinationItemPath error:&error];
                            if (error) {
                                NSLog(@"Error copying file: %@", error);
                                break;
                            }
                        }
                        
                        if(!error){
                            completionHandler(targetFile,nil,nil,material.uuid,unpackError);
                        }else{
                            completionHandler(nil,nil,nil,material.uuid,unpackError);
                        }
                    }
                }else if (material.type == NvMaterialTypePrefabricate){
                    NSError* copyError = nil;
                    NSString *tempPath = [unzipPath stringByAppendingPathComponent:zipFileName];
                    if ([fm fileExistsAtPath:targetFolder]) {
                        [fm removeItemAtPath:targetFolder error:nil];
                    }
                    [fm moveItemAtPath:tempPath toPath:targetFolder error:&copyError];
                    
                    tempPath = [targetFolder stringByAppendingPathComponent:zipFileName];
                    if (copyError && copyError.code != 516) {
                        [fm removeItemAtPath:tempPath error:nil];
                        completionHandler(nil, nil, nil, material.uuid, copyError);
                    }else{
                        completionHandler(tempPath, nil, nil, material.uuid, nil);
                    }
                }else{
                    //剪切过去
                    //是否是文件夹的形式
                    BOOL checkDir = [packExtensionSet containsObject:@"$"];
                    
                    NSArray* files = [fm contentsOfDirectoryAtPath:unzipPath error:nil];
                    NSLog(@"------->\n%@",files);
                    /// 找不到包不移动lic文件
                    NSString* packageFile = nil;
                    NSString* licFile = nil;
                    NSString* jsonFile = nil;
                    for (NSString* file in files) {
                        NSString* extension = file.pathExtension;
                        if (extension && [packExtensionSet containsObject:extension]) {
                            packageFile = file;
                            continue;
                        }else if([extension isEqualToString:@"lic"]){
                            licFile = file;
                            continue;
                        }else if([extension isEqualToString:@"json"]) {
                            if (material.type == NvMaterialTypeMakeup) { // 美妆需要拷贝info.json文件
                                if ([file containsString:@"info.json"]) {
                                    jsonFile = file;
                                }
                            }else {
                                if ([file containsString:packageUUID]) {
                                    jsonFile = file;
                                }
                            }
                            continue;
                        }
                        
                        if (checkDir) {
                            NSString* filePath = [unzipPath stringByAppendingPathComponent:file];
                            BOOL isDirectory = NO;
                            [fm fileExistsAtPath:filePath isDirectory:&isDirectory];
                            if (isDirectory) {
                                packageFile = file;
                            }
                        }
                    }
                    if (packageFile) {
                        NSString* targetFile = [targetFolder stringByAppendingPathComponent:packageFile];
                        NSError* copyError = nil;
                        [fm moveItemAtPath:[unzipPath stringByAppendingPathComponent:packageFile] toPath:targetFile error:&copyError];
                        if (copyError && copyError.code != 516) {
                            completionHandler(nil,nil,nil,material.uuid,copyError);
                        }else{
                            NSString* targetJsonFile = nil;
                            if (jsonFile) {
                                if (material.type == NvMaterialTypeMakeup) { // 美妆需要拷贝info.json文件
                                    targetJsonFile = [targetFolder stringByAppendingPathComponent:[NSString stringWithFormat:@"%@.json", packageUUID]];
                                    [fm moveItemAtPath:[unzipPath stringByAppendingPathComponent:jsonFile] toPath:targetJsonFile error:&copyError];
                                }else {
                                    targetJsonFile = [targetFolder stringByAppendingPathComponent:jsonFile];
                                    [fm moveItemAtPath:[unzipPath stringByAppendingPathComponent:jsonFile] toPath:targetJsonFile error:&copyError];
                                }
                            }
                            NSString* targetLicFile = nil;
                            if (licFile) {
                                targetLicFile = [targetFolder stringByAppendingPathComponent:licFile];
                                [fm moveItemAtPath:[unzipPath stringByAppendingPathComponent:licFile] toPath:targetLicFile error:&copyError];
                                if (copyError && copyError.code != 516) {
                                    [fm removeItemAtPath:targetFile error:nil];
                                    completionHandler(nil,nil,nil,material.uuid,copyError);
                                }else{
                                    completionHandler(targetFile,targetLicFile,targetJsonFile,material.uuid,nil);
                                }
                            }else{
                                completionHandler(targetFile,targetLicFile,targetJsonFile,material.uuid,error);
                            }
                        }
                    }else{
                        completionHandler(nil, nil, nil, material.uuid, nil);
                    }
                }
                //清理
                [fm removeItemAtPath:unzipPath error:nil];
                [fm removeItemAtPath:location.path error:nil];
            } else {
                completionHandler(nil, nil, nil, material.uuid, unpackError);
            }
#endif
        }
    }];
    
    [downloadTask resume];
    return downloadTask.taskIdentifier;
}

- (void)requestProjectConfiguration:(void (^)(BOOL, id _Nullable, NSError * _Nullable))completionHandler{
    [self requestProjectFile:self.assetPrefabricatedUrl parameters:nil completion:completionHandler];
}

- (void)requestProjectModelFiles:(void (^)(BOOL success,
                                           id __nullable responseObject,
                                           NSError *__nullable error))completionHandler {
    [self requestProjectFile:self.assetPrefabricatedUrl parameters:@{@"assetType":@"model"} completion:completionHandler];
}

// https://www.yuque.com/ta44uc/cubgq6/bpgqwy6vpx9dvqa5?singleDoc=

- (void)requestProjectFile:(NSString *)url
                parameters:(NSDictionary *)parameters
                completion:(void (^)(BOOL, id _Nullable, NSError * _Nullable))completionHandler {
    [self GET:url parameters:parameters success:^(id responseObject) {
        int errNo = [[responseObject objectForKey:@"code"] intValue];
        if(errNo == 1){
            NSObject* resData = [responseObject objectForKey:@"data"];
            completionHandler(YES, resData, nil);
        }else{
            completionHandler(NO, nil, nil);
        }
    } failure:^(NSError * error) {
        completionHandler(NO, nil, error);
    }];
}

//=====================模版 template================//
#pragma mark - NvTemplateMaterialCenterDelegate
-(void)templateRequestListCategoryWithType:(NSInteger)type 
                 optionalRequestParameters:(NSMutableDictionary *)optionalRequestParameters
                                   success:(void (^)(NSArray * _Nonnull, BOOL, NSObject * _Nonnull))success
                                   failure:(void (^)(NSError * _Nullable))failure {
    
    NSMutableDictionary* requestParameters = [NSMutableDictionary dictionary];
    
    if (optionalRequestParameters[@"requestParameters"]){
        requestParameters = [NSMutableDictionary dictionaryWithDictionary:optionalRequestParameters];
    }
    
    [requestParameters addEntriesFromDictionary:[self defaultParameters]];
    
    int large,minor,revision;
    [NvsStreamingContext getSdkVersion:&large minorVersion:&minor revisionNumber:&revision];
    NSString *sdkVersion = [NSString stringWithFormat:@"%d.%d.%d",large,minor,revision];
    
    NSDictionary *body = @{@"types":@(type),@"sdkVersion":sdkVersion};
    
    [requestParameters addEntriesFromDictionary:body];
    
    if (self.isAbroad != 0){
        [requestParameters setValue:@(self.isAbroad) forKey:@"isAbroad"];
    }
    requestParameters[@"sign"] = [self signParameters:requestParameters];
    [self GET:self.assetTagUrl parameters:requestParameters success:^(id responseObject) {
        int errNo = [[responseObject objectForKey:@"code"] intValue];
        if(errNo == 1){
            NSArray* array = [responseObject objectForKey:@"data"];
//            NSMutableArray *mutableArray = [NSMutableArray array];
//            for (NSDictionary *dict in array) {
//                NvTemplateMaterialCategoryModel *model = [[NvTemplateMaterialCategoryModel alloc]init];
//                model.category = [dict[@"id"] integerValue];
//                model.displayName = dict[@"displayName"];
//                [mutableArray addObject:model];
//            }
            
            success(array, NO, responseObject);
        }else{
            failure(nil);
        }
    } failure:^(NSError * error) {
        failure(error);
    }];
}

- (void)templateRequestListDataWithType:(NSInteger)type 
                               category:(NSInteger)category
                                   kind:(NSInteger)kind
              optionalRequestParameters:(NSMutableDictionary *)optionalRequestParameters 
                              pageIndex:(NSInteger)pageIndex
                                success:(void (^)(NSArray * _Nonnull, 
                                                  BOOL, NSObject * _Nonnull))success
                                failure:(void (^)(NSError * _Nullable))failure {
    
    NSMutableDictionary* requestParameters = [NSMutableDictionary dictionaryWithDictionary:optionalRequestParameters];
    requestParameters[@"pageNum"] = @(pageIndex+1);
    [requestParameters addEntriesFromDictionary:[self defaultParameters]];
    
    
    if (type != 0) {
        requestParameters[@"type"] = @(type);
    }
    ///这里的category代表的是标签
    ///The category here is the tag
    if (category != 0) {
        requestParameters[@"intelTagId"] = @(category);
    }
    if (self.isAbroad != 0){
        [requestParameters setValue:@(self.isAbroad) forKey:@"isAbroad"];
    }
    requestParameters[@"sign"] = [self signParameters:requestParameters];
    [self GET:self.assetRequestUrl parameters:requestParameters success:^(id responseObject) {
        int errNo = [[responseObject objectForKey:@"code"] intValue];
        if(errNo == 1){
            NSDictionary* resData = [responseObject objectForKey:@"data"];
            NSArray* elements = [resData objectForKey:@"elements"];
            BOOL hasMore = YES;
            if (elements.count > 0) {
                NSInteger pageSize = [[resData objectForKey:@"pageSize"] integerValue];
                if (elements.count < pageSize) {
                    hasMore = NO;
                } else {
                    NSInteger pageNum = [[resData objectForKey:@"pageNum"] integerValue];
                    NSInteger tatal = [[resData objectForKey:@"total"] integerValue];
                    NSInteger nNumber = pageSize * pageNum;
                    if (nNumber >= tatal) {
                        hasMore = NO;
                    }
                }
            } else {
                hasMore = NO;
            }
            success(elements.count > 0?elements:@[], hasMore, resData);
        }else{
            failure(nil);
        }
    } failure:^(NSError * error) {
        failure(error);
    }];
}

- (void)templateDownloadMaterialWithUuid:(NSString *)uuid 
                                     url:(NSString *)url
                            targetFolder:(NSString *)targetFolder
                           optParameters:(NSMutableDictionary *)optParameters
                                progress:(void (^)(float))progress
                                 success:(void (^)(NSArray * _Nonnull, BOOL, NSObject * _Nullable))success
                                 failure:(void (^)(NSError * _Nullable))failure{
    NvMaterial *material = [[NvMaterial alloc]init];
    material.uuid = uuid;
    material.packageUrl = url;
    [self downloadMaterial:material targetFolder:targetFolder packExtensionSet:[NSMutableArray arrayWithArray:@[@"template"]] optParameters:NSMutableDictionary.dictionary progress:^(float progress) {
        
    } completionHandler:^(NSString * _Nullable packagePath, NSString * _Nullable packageLicPath, NSString * _Nullable packageJsonPath, NSString * _Nullable packageId, NSError * _Nullable error) {
        if (error){
            NSError *error = [[NSError alloc]initWithDomain:NSCocoaErrorDomain code:-1 userInfo:@{@"packageId":packageId.length>0?packageId:@""}];
            if (failure){
                failure(error);
            }
        }else{
            if (success){
                success(@[],NO,packageId);
            }
        }
        
    }];
}
//====================一键成片 autocut================//
- (NSURLSessionDataTask *)autoCutListMaterialWithParam:(NSDictionary *)param
                             success:(void (^)(NSArray * _Nonnull, BOOL, NSObject * _Nonnull))success
                             failure:(void (^)(NSError * _Nullable))failure{
    NSMutableDictionary* requestParameters = [NSMutableDictionary dictionaryWithDictionary:param];
    [requestParameters addEntriesFromDictionary:[self defaultParameters]];
    if (self.isAbroad != 0){
        [requestParameters setValue:@(self.isAbroad) forKey:@"isAbroad"];
    }
    requestParameters[@"sign"] = [self signParameters:requestParameters];
    
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:self.assetAutoCutUrl]];
    [request setHTTPMethod:@"POST"];
    NSError* error = nil;
    [request setHTTPBody:[NSJSONSerialization dataWithJSONObject:requestParameters options:NSJSONWritingPrettyPrinted error:&error]];
    if (error) {
        NSLog(@"%@",error);
    }
    [request setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
    [request setValue:@"application/json" forHTTPHeaderField:@"Accept"];
    NSURLSessionDataTask *task = [self.urlSession dataTaskWithRequest:request 
                                                    completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {
        if (error){
            dispatch_async(dispatch_get_main_queue(), ^{
                failure(error);
            });
        }else{
            //解析数据
            NSError *jsonError;
            id responseObject = [NSJSONSerialization JSONObjectWithData:data options:0 error:&jsonError];
            if (jsonError) {
                NSLog(@"JSON Error: %@", jsonError.localizedDescription);
                if (failure) {
                    dispatch_async(dispatch_get_main_queue(), ^{
                        failure(jsonError);
                    });
                }
            } else {
                int errNo = [[responseObject objectForKey:@"code"] intValue];
                if(errNo == 1){
                    dispatch_async(dispatch_get_main_queue(), ^{
                        success(@[], NO, responseObject);
                    });
                }else{
                    NSError *error = [[NSError alloc]initWithDomain:NSCocoaErrorDomain code:errNo userInfo:responseObject];
                    dispatch_async(dispatch_get_main_queue(), ^{
                        failure(error);
                    });
                }
            }
        }
    }];
    [task resume];
    
    return task;
}


- (NSArray<NSURLQueryItem *> *)queryItemsFromDic:(NSDictionary *)dic {
    NSMutableArray<NSURLQueryItem *> *queryItems = [NSMutableArray array];
    for (NSString *key in dic.allKeys) {
        id value = dic[key];
        NSString *stringValue;
        if ([value isKindOfClass:[NSString class]]) {
            stringValue = value;
        } else if ([value isKindOfClass:[NSNumber class]]) {
            stringValue = [value stringValue];
            if (!stringValue) {
                stringValue = [value boolValue] ? @"1" : @"0";
            }
        } else {
            continue;
        }
        
        [queryItems addObject:[[NSURLQueryItem alloc] initWithName:key value:stringValue]];
    }
    return queryItems;
}

- (NSURLSessionDataTask *)GET:(NSString *)URLString
                   parameters:(NSDictionary *_Nullable)parameters
                      success:(nullable void (^)(id))success
                      failure:(nullable void (^)(NSError * _Nonnull))failure
{
    // 构建URL
    NSURL *url = [NSURL URLWithString:URLString];
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"GET"];
    // 设置请求参数
    NSURLComponents *components = [NSURLComponents componentsWithURL:url resolvingAgainstBaseURL:NO];
    components.queryItems = [self queryItemsFromDic:parameters];
    request.URL = components.URL;
    NSURLSessionDataTask *dataTask = [self.urlSession dataTaskWithRequest:request
                                                        completionHandler:^(NSData *data,
                                                                            NSURLResponse *response,
                                                                            NSError *error) {
        if (error) {
            NSLog(@"Error: %@", error.localizedDescription);
            if (failure) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    failure(error);
                });
            }
        } else {
            NSError *jsonError;
            id responseObject = [NSJSONSerialization JSONObjectWithData:data options:0 error:&jsonError];
            if (jsonError) {
                NSLog(@"JSON Error: %@", jsonError.localizedDescription);
                if (failure) {
                    dispatch_async(dispatch_get_main_queue(), ^{
                        failure(jsonError);
                    });
                }
            } else {
                if (success) {
                    dispatch_async(dispatch_get_main_queue(), ^{
                        success(responseObject);
                    });
                }
            }
        }
    }];
    [dataTask resume];
    return dataTask;
}

// MARK: -- NvWebImageDelegate
- (void)fetchImageForImageView:(UIImageView *)imageView
                          url:(NSURL *)url
                  placeholder:(UIImage *_Nullable)placeholder
                    completion:(void (^ _Nullable)(UIImage * _Nullable image))completion {
#if __has_include(<SDWebImageWebPCoder/SDWebImageWebPCoder.h>)
    [imageView sd_setImageWithURL:url placeholderImage:placeholder completed:^(UIImage * _Nullable image, NSError * _Nullable error, SDImageCacheType cacheType, NSURL * _Nullable imageURL) {
        if (completion) {
            completion(image);
        }
    }];
#endif
}

// MARK: -- Zip
- (BOOL)unzipWithPath:(NSString *)path destination:(NSString *)destination {
#if __has_include(<SSZipArchive/SSZipArchive.h>)
    NSError* unpackError = nil;
    BOOL ret = [SSZipArchive unzipFileAtPath:path toDestination:destination overwrite:YES password:nil error:&unpackError];
    if (unpackError) {
        NSLog(@"unzip error: %@", unpackError);
    }
    return ret;
#else
    NSLog(@"♥️: zip decompression not implemented");
#endif
}

@end
