//
//  NvShortVideoCore.h
//  NvShortVideoCore
//
//  Created by chengww on 2022/1/4.
//

#import <Foundation/Foundation.h>

#define NvShortVideoCoreMajorVersion 1
#define NvShortVideoCoreMinorVersion 2
#define NvShortVideoCoreRevisionVersion 2
#define NvShortVideoCoreBuild 2

//! Project version number for NvShortVideoCore.
FOUNDATION_EXPORT double NvShortVideoCoreVersionNumber;

//! Project version string for NvShortVideoCore.
FOUNDATION_EXPORT const unsigned char NvShortVideoCoreVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <NvShortVideoCore/PublicHeader.h>
#if __has_include(<NvShortVideoCore/NvBaseModel.h>)

#import <NvShortVideoCore/NvModuleManager.h>
#import <NvShortVideoCore/NvModuleManager+Draft.h>
#import <NvShortVideoCore/NvTheme.h>
#import <NvShortVideoCore/NvRecognitionTextItem.h>

#import <NvShortVideoCore/NvSPUtils.h>
#import <NvShortVideoCore/NvAppEnv.h>
#import <NvShortVideoCore/NvTipToast.h>
#import <NvShortVideoCore/NvMaterialCenter.h>
#import <NvShortVideoCore/NvMaterialPageRequestModel.h>
#import <NvShortVideoCore/UIImage+Extension.h>
#import <NvShortVideoCore/UIColor+Hex.h>
#import <NvShortVideoCore/NvAlertView.h>
#import <NvShortVideoCore/NCSequenceView.h>
#import <NvShortVideoCore/NvAudioWaveView.h>
#import <NvShortVideoCore/NvWaveDataParse.h>
#import <NvShortVideoCore/NvEditProjectInfo.h>
#import <NvShortVideoCore/NvSqlite3Operator.h>
#import <NvShortVideoCore/NvPushManager.h>
#import <NvShortVideoCore/YYModel.h>
#import <NvShortVideoCore/NvWaveDataCache.h>
#import <NvShortVideoCore/NvMaterialLibrary.h>


//MARK: -- Config
#import <NvShortVideoCore/NvVideoConfig.h>
#import <NvShortVideoCore/NvDualConfig.h>
#import <NvShortVideoCore/NvBeautyConfig.h>
#import <NvShortVideoCore/NvCaptureConfig.h>
#import <NvShortVideoCore/NvEditConfig.h>
#import <NvShortVideoCore/NvAlbumConfig.h>
#import <NvShortVideoCore/NvCompileConfig.h>
#import <NvShortVideoCore/NvTemplateConfig.h>
#import <NvShortVideoCore/NvBubbleConfig.h>
#import <NvShortVideoCore/NvModelConfig.h>

//MARK: -- Theme
#import <NvShortVideoCore/NvThemeElementKey.h>

// ThemeElement
#import <NvShortVideoCore/NvLabelTheme.h>
#import <NvShortVideoCore/NvTextFieldTheme.h>
#import <NvShortVideoCore/NvButtonTheme.h>
#import <NvShortVideoCore/NvImageViewTheme.h>
#import <NvShortVideoCore/NvViewTheme.h>
#import <NvShortVideoCore/NvSliderTheme.h>
#import <NvShortVideoCore/NvCellTheme.h>

// Custom
#import <NvShortVideoCore/NvRecordBtTheme.h>
#import <NvShortVideoCore/NvMusicCellTheme.h>
#import <NvShortVideoCore/NvMaterialCellTheme.h>
#import <NvShortVideoCore/NvMusciCutViewTheme.h>
#import <NvShortVideoCore/NvMusicSearchCellTheme.h>
#import <NvShortVideoCore/NvBeautyPanelTheme.h>
#import <NvShortVideoCore/NvTemplateHomeCellTheme.h>
#import <NvShortVideoCore/NvTemplateEditClipSectionTheme.h>
#import <NvShortVideoCore/NvTemplateHomeDataErrorTheme.h>
#import <NvShortVideoCore/NvCaptionViewTheme.h>
#import <NvShortVideoCore/NvEffectTimeRangeViewTheme.h>
#import <NvShortVideoCore/NvAlbumCellTheme.h>
#import <NvShortVideoCore/NvRecognitionEditCellTheme.h>
#import <NvShortVideoCore/NvEffectTrackViewTheme.h>

#else

#import "NvModuleManager.h"
#import "NvModuleManager+Draft.h"
#import "NvTheme.h"

#import "NvSPUtils.h"
#import "NvAppEnv.h"
#import "NvTipToast.h"
#import "NvMaterialCenter.h"
#import "NvMaterialPageRequestModel.h"
#import "UIImage+Extension.h"
#import "UIColor+Hex.h"
#import "NvAlertView.h"
#import "NvRecognitionTextItem.h"
#import "NCSequenceView.h"
#import "NvAudioWaveView.h"
#import "NvWaveDataParse.h"
#import "NvEditProjectInfo.h"
#import "NvSqlite3Operator.h"
#import "NvPushManager.h"
#import "YYModel.h"
#import "NvWaveDataCache.h"
#import "NvMaterialLibrary.h"

//MARK: -- Config
#import "NvVideoConfig.h"
#import "NvDualConfig.h"
#import "NvBeautyConfig.h"
#import "NvCaptureConfig.h"
#import "NvEditConfig.h"
#import "NvAlbumConfig.h"
#import "NvCompileConfig.h"
#import "NvTemplateConfig.h"
#import "NvBubbleConfig.h"
#import "NvModelConfig.h"

//MARK: -- Theme
#import "NvThemeElementKey.h"
// ThemeElement
#import "NvLabelTheme.h"
#import "NvTextFieldTheme.h"
#import "NvButtonTheme.h"
#import "NvImageViewTheme.h"
#import "NvViewTheme.h"
#import "NvSliderTheme.h"
#import "NvCellTheme.h"
// Custom
#import "NvRecordBtTheme.h"
#import "NvMusicCellTheme.h"
#import "NvMaterialCellTheme.h"
#import "NvMusciCutViewTheme.h"
#import "NvMusicSearchCellTheme.h"
#import "NvBeautyPanelTheme.h"
#import "NvTemplateHomeCellTheme.h"
#import "NvTemplateEditClipSectionTheme.h"
#import "NvTemplateHomeDataErrorTheme.h"
#import "NvCaptionViewTheme.h"
#import "NvEffectTimeRangeViewTheme.h"
#import "NvAlbumCellTheme.h"
#import "NvRecognitionEditCellTheme.h"
#import "NvEffectTrackViewTheme.h"

#endif
