//
//  NvMaterialLibrary.h
//  NvMaterialLibrary
//
//  Created by chengww on 2021/8/31.
//

#import <Foundation/Foundation.h>

//! Project version number for NvMaterialLibrary.
FOUNDATION_EXPORT double NvMaterialLibraryVersionNumber;

//! Project version string for NvMaterialLibrary.
FOUNDATION_EXPORT const unsigned char NvMaterialLibraryVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <NvMaterialLibrary/PublicHeader.h>
#if __has_include(<NvMaterialLibrary/NvMaterialCenter.h>)

#import <NvMaterialLibrary/NvMaterialCenter.h>
#import <NvMaterialLibrary/NvMaterial.h>
#import <NvMaterialLibrary/NvMaterialPageRequestModel.h>

#else

#import "NvMaterialCenter.h"
#import "NvMaterial.h"
#import "NvMaterialPageRequestModel.h"

#endif
