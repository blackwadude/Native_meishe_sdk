//
//  NvTheme.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/3/18.
//

#import <UIKit/UIKit.h>
#import "NvCellTheme.h"

NS_ASSUME_NONNULL_BEGIN


@protocol NvThemeElement <NSObject>

- (NSDictionary *)themeElements;

@optional

- (void)updateCellTheme:(NvCellTheme *)cellTheme 
      selectedCellTheme:(NvCellTheme *)selectedCellTheme
           viewIndicate:(NSString *)viewIndicate;

- (Class _Nullable)themeClass:(NSString *)viewIndicate;

@end


@protocol NvThemeDelegate <NSObject>

- (void)configView:(UIView *)view viewIndicate:(NSString *_Nullable)viewIndicate;

- (void)configTableCell:(UITableViewCell *)cell
           viewIndicate:(NSString *)viewIndicate
               selected:(BOOL)selected;

- (void)configCollectViewCell:(UICollectionView *)cell
                 viewIndicate:(NSString *)viewIndicate
                     selected:(BOOL)selected;

@end

@protocol NvThemeDataSourceDelegate <NSObject>

/*! \if ENGLISH
 *
 *  \brief compile video progress callback
 *  \param view  the current progress
 *  \param viewIndicate 当前的进度
 *  \else
 *
 *  \brief 合成视频进度回调
 *  \param view 当前的进度
 *  \param viewIndicate 当前的进度
 *  \endif
*/
- (NvViewTheme *_Nullable)viewConfigWithView:(UIView *_Nullable)view
                                 configClass:(Class _Nullable)configClass
                                viewIndicate:(NSString *)viewIndicate;

/*! \if ENGLISH
 *
 *  \brief compile video progress callback
 *  \param progress  the current progress
 *  \else
 *  
 *  \brief 合成视频进度回调
 *  \param progress 当前的进度
 *  \endif
*/
- (NvCellTheme *_Nullable)cellConfigWithConfigClass:(Class)configClass
                                           selected:(BOOL)selected
                                           indicate:(NSString *)indicate;

@end

NS_ASSUME_NONNULL_END
