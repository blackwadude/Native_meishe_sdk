//
//  NvViewTheme.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/3/18.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/*! \if ENGLISH
 *
 *  \brief View Configuration item
 *  \else
 *
 *  \brief View配置项
 *  \endif
*/
@interface NvViewTheme : NSObject

/*! \if ENGLISH
 *
 *  \brief hidden
 *  \else
 *
 *  \brief 隐藏
 *  \endif
*/
@property (nonatomic, assign) BOOL hidden;

/*! \if ENGLISH
 *
 *  \brief backgroundColor
 *  \else
 *
 *  \brief 背景色
 *  \endif
*/
@property (nonatomic, strong) UIColor *backgroundColor;

/*! \if ENGLISH
 *
 *  \brief tintColor
 *  \else
 *
 *  \brief tintColor
 *  \endif
*/
@property (nonatomic, strong) UIColor *tintColor;

/*! \if ENGLISH
 *
 *  \brief Stroke color
 *  \else
 *
 *  \brief 描边颜色
 *  \endif
*/
@property (nonatomic, strong) UIColor *borderColor;

/*! \if ENGLISH
 *
 *  \brief Stroke width
 *  \else
 *
 *  \brief 描边宽度
 *  \endif
*/
@property (nonatomic, assign) CGFloat borderWidth;

/*! \if ENGLISH
 *
 *  \brief Pass in a new object and superimpose the current object
 *  \param view Current view
 *  \param viewIndicate view key value
 *  \else
 *
 *  \brief 传入一个新的对象，叠加当前对象
 *  \param view 当前视图
 *  \param viewIndicate view的key值
 *  \endif
*/
- (void)configView:(UIView *)view viewIndicate:(NSString *_Nullable)viewIndicate;

/*! \if ENGLISH
 *
 *  \brief Pass in a new object and superimpose the current object
 *  \param theme NvViewTheme
 *  \else
 *
 *  \brief 传入一个新的对象，叠加当前对象
 *  \param theme NvViewTheme
 *  \endif
*/
- (void)addTheme:(NvViewTheme *)theme;

- (BOOL)modelCustomTransformFromDictionary:(NSDictionary *)dic;

@end

NS_ASSUME_NONNULL_END
