//
//  VideoEditPlugin.h
//  Runner
//
//  Created by 美摄 on 2021/10/15.
//

#import <Foundation/Foundation.h>
#import <Flutter/Flutter.h>

NS_ASSUME_NONNULL_BEGIN

//method channel name
#define VideoEditMethodChannel              @"VideoEditMethodChannel"

//Used to update composition status
#define VideoEditCallbackMethodChannel      @"VideoEditCallbackMethodChannel"

//config server info
#define ConfigServerInfo                    @"ConfigServerInfo"

//Modele Settings
#define PresentModuleSettingsViewMethod       @"PresentModuleSettingsViewMethod"
#define ModuleSettingsUpdateMethod            @"ModuleSettingsUpdateMethod"


#define GetModuleSettingsMethod               @"GetModuleSettingsMethod"
#define SetModuleSettingsMethod               @"SetModuleSettingsMethod"



//Pop up video capture view
#define CaptureMethod               @"CaptureMethod"
//Pop up Dual video capture view, The absolute path of the original video is required
#define DualCaptureMethod           @"DualCaptureMethod"
#define DualCaptureWithVideoMethod  @"DualCaptureWithVideoMethod"

#define EditMethod                  @"EditMethod"

//Open the draft and enter the edit page. The projectId of the draft file is required.
#define ReeditMethod                @"ReeditMethod"

//
#define VideoEditResultEvent        @"VideoEditResultEvent"
#define SaveDraftMethod             @"SaveDraftMethod"
#define SelectCoverImage            @"SelectCoverImageMethod"
/// 发布页保存图片按钮调用方法
#define SaveImageMethod          @"SaveImageMethod"


#define CompileVideoMethod          @"CompileVideoMethod"

#define GetAVFileInfoArrayMethod     @"GetAVFileInfoArrayMethod"
#define GetAVFileInfoMethod          @"GetAVFileInfoMethod"

//Destroy related resources
#define ExitVideoEditMethod         @"ExitVideoEditMethod"


//MARK: -- callback
#define DidCoverImageSaveMethod           @"DidCoverImageSaveMethod"
#define DidCoverImageChangedMethod        @"DidCoverImageChangedMethod"
#define DidCompileProgressMethod          @"DidCompileProgressMethod"
#define DidCompileCompletedMethod         @"DidCompileCompletedMethod"



//test video path
#define DualTestVideoPathMethod     @"DualTestVideoPathMethod"
#define DualTestImagePathMethod     @"DualTestImagePathMethod"
#define TestJsonPathMethod          @"TestJsonPathMethod"


//草稿操作相关
#define VideoEditDraftChangeMethodChannel      @"VideoEditDraftChangeMethodChannel"
//Get draft list
#define DraftListMethod             @"DraftListMethod"
//Delete draft, The project info is required.
#define DeleteDraftMethod           @"DeleteDraftMethod"

#define DraftListUpdate             @"DraftListUpdate"

@interface VideoEditPlugin : NSObject <FlutterPlugin>

@end

NS_ASSUME_NONNULL_END
