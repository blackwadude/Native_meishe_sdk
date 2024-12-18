//
//  VideoEditPlugin.m
//  Runner
//
//  Created by 美摄 on 2021/10/15.
//

#import "VideoEditPlugin.h"
#import <NvShortVideoCore/NvShortVideoCore.h>
#import "NvHttpRequest.h"

#if __has_include("NvSpeechRecognizer.h")
#import "NvSpeechRecognizer.h"
#endif

#import <Network/Network.h>
#import "NvPublicViewController.h"

@interface VideoEditPlugin()
<
FlutterPlugin,
NvModuleManagerDelegate,
NvModuleManagerCompileStateDelegate,
NvPublicViewControllerDelegate
>

@property (nonatomic, strong) FlutterMethodChannel *mainChannel;
@property (nonatomic, strong) FlutterMethodChannel *callbackChannel;
@property (nonatomic, strong) FlutterMethodChannel *draftUpdateChannel;

@property (nonatomic, strong) NvModuleManager* moduleManager;

@end

@implementation VideoEditPlugin

-(instancetype)init{
    self = [super init];
    if(self){
        self.moduleManager = NvModuleManager.sharedInstance;
        self.moduleManager.delegate = self;
        self.moduleManager.compileDelegate = self;
        
#if __has_include("NvSpeechRecognizer.h")
        NSObject<NvVoiceRecognizer> *fileRecognizer = [[NvSpeechRecognizer alloc] init];
        moduleManager.voiceRecognizer = fileRecognizer;
#endif
        NvHttpRequest *httpRequest = [NvHttpRequest sharedInstance];
        self.moduleManager.netDelegate = httpRequest;
        self.moduleManager.webImageDelegate = httpRequest;
        [self.moduleManager prepareDownloadFolders];
        
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleDraftListNotification:) name:NvDraftManager_Draft_Save_Notification object:nil];
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleDraftListNotification:) name:NvDraftManager_Draft_Delete_Notification object:nil];
    }
    return self;
}

+ (void)registerWithRegistry:(NSObject<FlutterPluginRegistry>*)registry{
    [VideoEditPlugin registerWithRegistrar:[registry registrarForPlugin:@"VideoEditPlugin"]];
}

+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar{
    //    NSString* licPath = [[NSBundle mainBundle] pathForResource:@"meicam_licence.lic" ofType:nil];
    NSString *licPath = [[[NSBundle bundleForClass:[self class]] bundlePath] stringByAppendingPathComponent:@"meicam_licence.lic"];
    if (![NvsStreamingContext verifySdkLicenseFile:licPath]) {
        NSLog(@"ERROR ♥️: verifySdkLicenseFile error");
    }
    FlutterMethodChannel *channel = [FlutterMethodChannel methodChannelWithName:VideoEditMethodChannel binaryMessenger:[registrar messenger]];
    FlutterMethodChannel *callbackChannel = [FlutterMethodChannel methodChannelWithName:VideoEditCallbackMethodChannel binaryMessenger:[registrar messenger]];
    
    FlutterMethodChannel *draftUpdateChannel = [FlutterMethodChannel methodChannelWithName:VideoEditDraftChangeMethodChannel binaryMessenger:[registrar messenger]];
    
    VideoEditPlugin *instance = [[VideoEditPlugin alloc] init];
    instance.mainChannel = channel;
    instance.callbackChannel = callbackChannel;
    instance.draftUpdateChannel = draftUpdateChannel;
    [registrar addMethodCallDelegate:instance channel:channel];
    [registrar addMethodCallDelegate:instance channel:draftUpdateChannel];
}

- (void)networkState{
    // 联网后，请求、下载模型文件
    // After networking, request and download the model file
    nw_path_monitor_t monitor = nw_path_monitor_create();
    nw_path_monitor_set_queue(monitor, dispatch_get_main_queue());
    nw_path_monitor_set_update_handler(monitor, ^(nw_path_t path) {
        if (nw_path_get_status(path) == nw_path_status_satisfied) {
            NvModuleManager* moduleManager = [NvModuleManager sharedInstance];
            [moduleManager preloadedResource];
            nw_path_monitor_cancel(monitor);
        } else {
//            NSLog(@"Network not reachable");
        }
    });
    nw_path_monitor_start(monitor);
}

//NSString *filePath = [[NSBundle mainBundle] pathForResource:@"dualVideo.mp4" ofType:nil];
- (void)handleMethodCall:(FlutterMethodCall *)call result:(FlutterResult)result {
    [self handleMethod:call.method arguments:call.arguments completion:^(NSObject * _Nullable response, NSError * _Nullable error) {
        if (!response && !error) {
            result(nil);
        } else {
            NSMutableDictionary *mutDic = [NSMutableDictionary dictionary];
            if (response) {
                mutDic[@"response"] = response;
            }
            if (error) {
                mutDic[@"error"] = error;
            }
            result(mutDic);
        }
    }];
}


- (void)handleMethod:(NSString*)methodName
           arguments:(NSDictionary*)arguments
          completion:(nullable void (^)(NSObject * _Nullable response, NSError * _Nullable error))completion {
    UIViewController* presentingVc = [NvSPUtils keyWindow].rootViewController;
    NSDictionary *configDic = arguments[@"config"];
    NvVideoConfig *videoConfig;
    if (configDic) {
        videoConfig = [NvVideoConfig yy_modelWithJSON:configDic];
    }
    if ([methodName isEqualToString:CaptureMethod]) {
        NvCaptionMusicInfo *musicInfo;
        NSDictionary *musicInfoDic = arguments[@"musicInfo"];
        if (musicInfoDic) {
            NSString *musicName = musicInfoDic[@"musicName"];
            NSString *musicFilePath = musicInfoDic[@"musicFilePath"];
            
            if (musicFilePath && musicFilePath.length > 0) {
                NvCaptionMusicInfo *info = [[NvCaptionMusicInfo alloc] init];
                info.musicName = musicName;
                info.musicFilePath = musicFilePath;
                musicInfo = info;
            }
        }
        [self.moduleManager startCaptureWithPresentViewController:presentingVc config:videoConfig music:musicInfo with:^{
            //
        }];
        completion(nil, nil);
    } else if([methodName isEqualToString:DualCaptureMethod]) {
        [self.moduleManager startDualCaptureWithPresentViewController:presentingVc config:videoConfig with:^{
            //
        }];
        completion(nil, nil);
    } else if([methodName isEqualToString:DualCaptureWithVideoMethod]) {
        NSFileManager* fm = [NSFileManager defaultManager];
        NSString* videoPath = arguments[@"videoPath"];
        if (videoPath && [fm fileExistsAtPath:videoPath]) {
            [self.moduleManager startDualCaptureWithPresentViewController:presentingVc config:videoConfig videoPath:videoPath with:^{
                //
            }];
            completion(nil, nil);
        }else{
            completion(nil, [NSError errorWithDomain:@"" code:-1 userInfo:@{NSLocalizedDescriptionKey:@"video file does not exist"}]);
        }
    } else if([methodName isEqualToString:EditMethod]) {
        [self.moduleManager startEditWithPresentViewController:presentingVc config:videoConfig with:^{
            //
        }];
        completion(nil, nil);
    } else if([methodName isEqualToString:ReeditMethod]) {
        NSString* projectId = arguments[@"projectId"];
        if (projectId && projectId.length > 0) {
            NSArray<NvEditProjectInfo*> * draftList = [NvModuleManager projectList];
            for (NvEditProjectInfo* draftModel in draftList) {
                if ([draftModel.projectId isEqualToString:projectId]) {
                    [self.moduleManager reeditProject:draftModel presentViewController:presentingVc config:videoConfig];
                    completion(nil, nil);
                    return;
                }
            }
        }
        completion(nil, [NSError errorWithDomain:@"" code:-1 userInfo:@{NSLocalizedDescriptionKey:@"projectId error, draft does not exist"}]);
    } else if([methodName isEqualToString:DraftListMethod]) {
        completion([self getProjectList], nil);
    } else if([methodName isEqualToString:DeleteDraftMethod]) {
        NSString* projectId = arguments[@"projectId"];
        if (projectId && projectId.length > 0) {
            if ([NvModuleManager deleteDraft:projectId]) {
                completion(nil, nil);
                return;
            }
        }
        completion(nil, [NSError errorWithDomain:@"" code:-1 userInfo:@{NSLocalizedDescriptionKey:@"projectId error, draft does not exist"}]);
    } else if([methodName isEqualToString:ExitVideoEditMethod]) {
        NSString* projectId = arguments[@"projectId"];
        if (projectId) {
            [self.moduleManager exitVideoEdit:projectId];
        }
        completion(nil, nil);
    } else if([methodName isEqualToString:ConfigServerInfo]) {
        //设置服务器参数 Setting server parameters
        NSString* host = arguments[@"host"];
        NSString* assetRequestUrl = arguments[@"assetRequestUrl"];
        NSString* assetCategoryUrl = arguments[@"assetCategoryUrl"];
        NSString* assetMusiciansUrl = arguments[@"assetMusiciansUrl"];
        NSString* assetFontUrl = arguments[@"assetFontUrl"];
        NSString* assetDownloadUrl = arguments[@"assetDownloadUrl"];
        NSString* assetPrefabricatedUrl = arguments[@"assetPrefabricatedUrl"];
        NSString* assetAutoCutUrl = arguments[@"assetAutoCutUrl"];
        NSString* assetTagUrl = arguments[@"assetTagUrl"];
        
        NSString* clientId = arguments[@"clientId"];
        NSString* clientSecret = arguments[@"clientSecret"];
        NSString* assemblyId = arguments[@"assemblyId"];
        NSInteger isAbroad = [arguments[@"isAbroad"] integerValue];
        
        if (!host || !assetRequestUrl || !assetCategoryUrl || !assetMusiciansUrl || !assetFontUrl || !assetDownloadUrl || !assetPrefabricatedUrl || !assetAutoCutUrl || !assetTagUrl) {
            completion(nil, [NSError errorWithDomain:@"" code:-1 userInfo:@{NSLocalizedDescriptionKey:@"Server Info error"}]);
            return;
        }

        NvHttpRequest *request = [NvHttpRequest sharedInstance];
        request.assetRequestUrl = [host stringByAppendingString:assetRequestUrl];
        request.assetCategoryUrl = [host stringByAppendingString:assetCategoryUrl];
        request.assetMusiciansUrl = [host stringByAppendingString:assetMusiciansUrl];
        request.assetFontUrl = [host stringByAppendingString:assetFontUrl];
        request.assetDownloadUrl = [host stringByAppendingString:assetDownloadUrl];
        request.assetPrefabricatedUrl = [host stringByAppendingString:assetPrefabricatedUrl];
        request.assetAutoCutUrl = [host stringByAppendingString:assetAutoCutUrl];
        request.assetTagUrl = [host stringByAppendingString:assetTagUrl];
        
        request.clientId = clientId;
        request.clientSecret = clientSecret;
        request.assemblyId = assemblyId;
        request.isAbroad = isAbroad;
        [self networkState];
        completion(nil, nil);
    } else if([methodName isEqualToString:SaveDraftMethod]) {
        NSString* infoString = arguments[@"draftInfo"];
        if ([self.moduleManager saveCurrentDraftWithDraftInfo:infoString]) {
            completion(nil, nil);
        } else {
            completion(nil, [NSError errorWithDomain:@"" code:-1 userInfo:@{NSLocalizedDescriptionKey:@"Save draft error"}]);
        }
    } else if([methodName isEqualToString:CompileVideoMethod]) {
        if ([self.moduleManager compileCurrentTimeline:arguments]) {
            completion(nil, nil);
        } else {
            completion(nil, [NSError errorWithDomain:@"" code:-1 userInfo:@{NSLocalizedDescriptionKey:@"Save draft error"}]);
        }
    } else if([methodName isEqualToString:SelectCoverImage]) {
        __weak typeof(self) weakSelf = self;
        [self.moduleManager selectCoverWithNavigationController:nil completionHandler:^(NSString * _Nonnull path) {
            NSFileManager *fm = [NSFileManager defaultManager];
            NSString *nFileName = [NSString stringWithFormat:@"%@.jpeg", [NSUUID UUID].UUIDString];
            NSString *nFilePath = [[path stringByDeletingLastPathComponent] stringByAppendingPathComponent:nFileName];
            [fm copyItemAtPath:path toPath:nFilePath error:nil];
            [weakSelf sendFlutterMethod:DidCoverImageChangedMethod arguments:@{@"coverImagePath":nFilePath} channel:self.callbackChannel];
        }];
        completion(nil, nil);
    } else if([methodName isEqualToString:SaveImageMethod]) {
        NSString* coverImagePath = arguments[@"coverImagePath"];
        NSFileManager* fm = [NSFileManager defaultManager];
        if (coverImagePath && [fm fileExistsAtPath:coverImagePath]) {
            [self.moduleManager saveCover:coverImagePath with:^(BOOL success) {
                if (success) {
                    completion(nil, nil);
                } else {
                    completion(nil, [NSError errorWithDomain:@"" code:-1 userInfo:@{NSLocalizedDescriptionKey:@"save error"}]);
                }
            }];
        } else {
            completion(nil, [NSError errorWithDomain:@"" code:-2 userInfo:@{NSLocalizedDescriptionKey:@"coverPath error"}]);
        }
    } else if([methodName isEqualToString:DualTestVideoPathMethod]) {
        NSString* testFile = [[NSBundle mainBundle] pathForResource:@"IMG_1333.mp4" ofType:nil];
        completion(testFile, nil);
    } else if([methodName isEqualToString:DualTestImagePathMethod]) {
        NSString* testFile = [[NSBundle mainBundle] pathForResource:@"555.PNG" ofType:nil];
        completion(testFile, nil);
    } else if([methodName isEqualToString:GetAVFileInfoArrayMethod]) {
        NSMutableArray *array = [[NvModuleManager sharedInstance] getAVFileInfoArray];
        completion(array, nil);
    } else if([methodName isEqualToString:GetAVFileInfoMethod]) {
        NSString* path = arguments[@"path"];
        NvsAVFileInfo *info = [[NvModuleManager sharedInstance] getAVFileInfo:path];
        
        NSMutableDictionary *dict = [NSMutableDictionary dictionary];
        NvsSize size = [info getVideoStreamDimension:0];
        if (size.width > 0 && size.height > 0) {
            [dict setObject:@(size.width) forKey:@"width"];
            [dict setObject:@(size.height) forKey:@"height"];
        }
        
        NvsRational rational = [info getVideoStreamFrameRate:0];
        if (rational.num > 0 && rational.den > 0) {
            int temp = round((CGFloat)rational.num / rational.den);
            [dict setObject:@(temp) forKey:@"fps"];
        }
        
        NvsVideoCodecType type = [info getVideoStreamCodecType:0];
        if (type == NvsVideoCodecType_H264) {
            [dict setObject:@"H264" forKey:@"codecType"];
        } else if (type == NvsVideoCodecType_H265) {
            [dict setObject:@"H265" forKey:@"codecType"];
        }
        completion(dict, nil);
    } else if([methodName isEqualToString:TestJsonPathMethod]) {
        NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
        NSString *documentsDirectory = [paths objectAtIndex:0];
        NSString *docPath = [documentsDirectory stringByAppendingPathComponent:@"Config"];
        NSFileManager *fm = [NSFileManager defaultManager];
        if (![fm fileExistsAtPath:docPath]) {
            [fm createDirectoryAtPath:docPath withIntermediateDirectories:NO attributes:nil error:nil];
        }
        NSString* testFile = [docPath stringByAppendingPathComponent:@"test.json"];
        completion(testFile, nil);
    } else {
        completion(nil, [NSError errorWithDomain:@"" code:-2 userInfo:@{NSLocalizedDescriptionKey:@"Method not implemented"}]);
    }
}

-(void)sendFlutterMethod:(NSString*)methodName
               arguments:(NSDictionary*)arguments
                 channel:(FlutterMethodChannel*)channel{
    [channel invokeMethod:methodName
                arguments:arguments
                   result:^(id  _Nullable result) {
        if (result && [result isKindOfClass:[FlutterError class]]) {
            FlutterError *error = (FlutterError *)result;
            NSLog(@"flutter invokeMethod error:%@",error.message);
        } else {
            //flutter回调信息
            NSLog(@"flutter invokeMethod result:%@",result);
        }
    }];
}

-(void)invokeSurfaceMethod:(NSString*)methodName arguments:(NSDictionary*)arguments{
    [self sendFlutterMethod:methodName arguments:arguments channel:self.mainChannel];
}

-(void)handleDraftListNotification:(NSNotification*)notification{
    //    [self invokeSurfaceMethod:DraftListUpdate arguments:nil];
    [self sendFlutterMethod:DraftListUpdate arguments:nil channel:self.draftUpdateChannel];
}


- (void)publishWithProjectId:(nonnull NSString *)projectId
              coverImagePath:(nonnull NSString *)coverImagePath
                    hasDraft:(BOOL)hasDraft
                   videoPath:(NSString * _Nullable)videoPath
                 description:(NSString * _Nullable)description
videoEditNavigationController:(nonnull UINavigationController *)videoEditNavigationController {
    NvPublicViewController *publicVc = [[UIStoryboard storyboardWithName:@"Main" bundle:nil] instantiateViewControllerWithIdentifier:@"NvPublicViewController"];
    publicVc.imagePath = coverImagePath;
    publicVc.hasDraft = hasDraft;
    publicVc.draftInfo = description;
    publicVc.projectId = projectId;
    publicVc.delegate = self;
    [videoEditNavigationController pushViewController:publicVc animated:YES];
}

- (void)didCompileFloatProgress:(float)progress{
    NSLog(@"didCompileFloatProgress:%f",progress);
    [self sendFlutterMethod:DidCompileProgressMethod arguments:@{@"progress":@(progress)} channel:self.callbackChannel];
}

- (void)didCompileCompleted:(NSString*)outputPath error:(NSError*)error{
    NSMutableDictionary* mutDic = [NSMutableDictionary dictionary];
    if (outputPath) {
        mutDic[@"outputPath"] = outputPath;
    }
    if (error) {
        mutDic[@"errorCode"] = @(error.code);
        mutDic[@"errorString"] = error.localizedDescription;
    }
    NSLog(@"didCompileCompleted:%@",mutDic);
    [self sendFlutterMethod:DidCompileCompletedMethod arguments:mutDic channel:self.callbackChannel];
}

-(NSMutableArray<NSDictionary*>*)getProjectList{
    NSArray<NvEditProjectInfo*> * draftList = [NvModuleManager projectList];
    NSMutableArray* mutArray = [NSMutableArray array];
    for (NvEditProjectInfo* draftModel in draftList) {
        NSString* imagePath = draftModel.coverImagePath?:@"";
        [mutArray addObject:@{@"projectId": draftModel.projectId,
                              @"coverImagePath": imagePath,
                              @"draftInfo": draftModel.projectDescription ? draftModel.projectDescription:@""}];
    }
    NSLog(@"mutArray:%@",mutArray);
    return mutArray;
}

#pragma mark - NvPublicViewControllerDelegate
- (void)compileBtClickedViewController:(NvPublicViewController *)vc {
    if (vc.presentingViewController.presentingViewController) {
        UIViewController* presentingVc = [NvSPUtils keyWindow].rootViewController;
        [presentingVc dismissViewControllerAnimated:YES completion:^{
            [self sendFlutterMethod:VideoEditResultEvent
                          arguments:@{@"coverImagePath":vc.imagePath,
                                      @"hasDraft":@(vc.hasDraft),
                                      @"draftInfo":vc.draftInfo!=nil?vc.draftInfo:@"",
                                      @"projectId":vc.projectId}
                            channel:self.mainChannel];
        }];
    }else{
        [vc dismissViewControllerAnimated:YES completion:^{
            [self sendFlutterMethod:VideoEditResultEvent
                          arguments:@{@"coverImagePath":vc.imagePath,
                                      @"hasDraft":@(vc.hasDraft),
                                      @"draftInfo":vc.draftInfo!=nil?vc.draftInfo:@"",
                                      @"projectId":vc.projectId}
                            channel:self.mainChannel];
        }];
    }
}

@end
