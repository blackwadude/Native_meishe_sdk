//
//  NvPublicViewController.m
//  NvShortVideo
//
//  Created by 美摄 on 2022/2/22.
//

#import "NvPublicViewController.h"
#if __has_include(<NvShortVideoCore/NvShortVideoCore.h>)
#import <NvShortVideoCore/NvShortVideoCore.h>
#else
#import "NvShortVideoCore.h"
#endif

@interface NvPublicViewController ()
{
    NvModuleManager* _moduleManager;
}

@property (weak, nonatomic) IBOutlet UITextView *textView;
@property (weak, nonatomic) IBOutlet UIImageView *imageView;
@property (weak, nonatomic) IBOutlet UIButton *saveBt;
@property (weak, nonatomic) IBOutlet UIButton *compileBt;
@property (weak, nonatomic) IBOutlet UIButton *saveCoverBt;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *saveCoverleading;

@end

@implementation NvPublicViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    if (@available(iOS 13.0, *)) {
        self.overrideUserInterfaceStyle = UIUserInterfaceStyleLight;
    }

    _moduleManager = [NvModuleManager sharedInstance];
    
    _moduleManager.config.compileConfig.autoSaveVideo = false;
    
    ///获取素材信息
    ///这个方法必须在主线程调用，可能会耗时
    ///Get material information
    ///This method must be called on the main thread and may be time-consuming.
    NSMutableArray *array = [_moduleManager getAVFileInfoArray];
    NvsAVFileInfo *info = [_moduleManager getAVFileInfo:array.firstObject];
    NvsSize size = [info getVideoStreamDimension:0];
    NSLog(@"size=%d,%d",size.width,size.height);
    NvsRational rational = [info getVideoStreamFrameRate:0];
    if (rational.num > 0 && rational.den > 0) {
        int temp = round((CGFloat)rational.num / rational.den);
        NSLog(@"fps=%d",temp);
    }
    
    NvsVideoCodecType type = [info getVideoStreamCodecType:0];
    if (type == NvsVideoCodecType_H264) {
        NSLog(@"NvsVideoCodecType_H264");
    } else if (type == NvsVideoCodecType_H265) {
        NSLog(@"NvsVideoCodecType_H265");
    }
    
    NSMutableDictionary*attributes = [NSMutableDictionary dictionary];
    attributes[NSForegroundColorAttributeName] = [UIColor whiteColor];
    attributes[NSFontAttributeName] = [UIFont systemFontOfSize:16];
    self.navigationController.navigationBar.titleTextAttributes = attributes;
    
    self.navigationItem.title = NSLocalizedString(@"Publish", @"发布");
    
    UIImage *image = [UIImage imageNamed:@"arrow-left"];
    UIButton *backButton = [[UIButton alloc] initWithFrame:CGRectMake(0, 0, 40, 40)];
    [backButton setImage:image forState:UIControlStateNormal];
    [backButton addTarget:self action:@selector(leftBtClicked) forControlEvents:UIControlEventTouchUpInside];
    UIBarButtonItem *backItem = [[UIBarButtonItem alloc] initWithCustomView:backButton];
    self.navigationItem.leftBarButtonItem = backItem;
    self.textView.layer.cornerRadius = 5;
 
    
    self.imageView.image = [UIImage imageWithContentsOfFile:self.imagePath];
    self.imageView.clipsToBounds = YES;
    self.imageView.layer.cornerRadius = 2;
    self.saveBt.clipsToBounds = YES;
    self.saveBt.layer.cornerRadius = 2;
    self.compileBt.clipsToBounds = YES;
    self.compileBt.layer.cornerRadius = 2;
    
    self.saveBt.hidden = !self.hasDraft;
    
    UITapGestureRecognizer* _tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(viewTap:)];
    [self.view addGestureRecognizer:_tap];
    
    // _placeholderLabel
    UILabel* placeHolderLabel = [[UILabel alloc]init];
    placeHolderLabel.text = NSLocalizedString(@  "Type your video caption here. You can also add hashtags (e.g., #tag1 #tag2) and mention people (@username).", @"");
    placeHolderLabel.numberOfLines = 0;
    placeHolderLabel.textColor = [UIColor blackColor];
    [placeHolderLabel sizeToFit];
    [self.textView addSubview:placeHolderLabel];
    placeHolderLabel.font = [UIFont systemFontOfSize:15.f];
    [self.textView setValue:placeHolderLabel forKey:@"_placeholderLabel"];
    self.textView.text = self.draftInfo;
    
    [self.compileBt setTitle:NSLocalizedString(@"Share ", @"") forState:(UIControlStateNormal)];
    [self.saveBt setTitle:NSLocalizedString(@"Save Draft", @"") forState:(UIControlStateNormal)];
    [self.saveCoverBt setTitle:NSLocalizedString(@"Save Cover", @"") forState:(UIControlStateNormal)];
    
    self.compileBt.layer.cornerRadius = 20;
    self.saveBt.layer.cornerRadius = 20;
    self.saveCoverBt.layer.cornerRadius = 20;
    
    self.saveBt.backgroundColor = [[UIColor alloc]initWithRed:242/255.0 green:244.0/255.0 blue:247.0/255.0 alpha:1];
    self.compileBt.backgroundColor = [[UIColor alloc]initWithRed:253/255.0 green:212.0/255.0 blue:0.0/255.0 alpha:1];
    self.saveCoverBt.backgroundColor = [[UIColor alloc]initWithRed:252/255.0 green:62/255.0 blue:90/255.0 alpha:1];
    
    self.imageView.layer.cornerRadius = 8;
    self.imageView.layer.masksToBounds = YES;
    
    UILabel *label = [[UILabel alloc]initWithFrame:CGRectMake(0, self.imageView.frame.size.height - 15, self.imageView.frame.size.width, 15)];
    label.text = NSLocalizedString(@"Select Cover", @"");
    label.font = [UIFont systemFontOfSize:10];
    label.backgroundColor = [[UIColor alloc]initWithRed:0 green:0 blue:0 alpha:0.7];
    label.textColor = UIColor.whiteColor;
    label.textAlignment = NSTextAlignmentCenter;
    [self.imageView addSubview:label];
    
    self.imageView.userInteractionEnabled = YES;
    [self.imageView addGestureRecognizer:[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(tapSelectCover)]];
    if (!self.hasDraft){
        self.saveCoverleading.constant = -(2*self.saveCoverleading.constant + self.saveBt.frame.size.width);
    }
}

- (void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    [self.navigationController setNavigationBarHidden:NO animated:animated];
}

- (void)leftBtClicked{
    [self.navigationController popViewControllerAnimated:YES];
}

- (void)tapSelectCover{
    [_moduleManager selectCoverWithNavigationController:self.navigationController
                                      completionHandler:^(NSString * _Nonnull path) {
        self.imagePath = path;
        self.imageView.image = [UIImage imageWithContentsOfFile:self.imagePath];
    }];
}

- (IBAction)saveBtClicked:(UIButton *)sender {
    if([_moduleManager saveCurrentDraftWithDraftInfo:self.textView.text]){
        [self finish:nil];
    }else{
        [NvTipToast showInfoWithMessage:NSLocalizedString(@"Save Failed", @"")];
    }
}

- (IBAction)compileBtClicked:(UIButton *)sender {
    [self jump];
}

- (void)jump{
    self.draftInfo = self.textView.text.length > 0 ? self.textView.text : @"";
    // if([_moduleManager saveCurrentDraftWithDraftInfo:self.textView.text]){
        if (self.delegate && [self.delegate respondsToSelector:@selector(compileBtClickedViewController:)]) {
            [self.delegate compileBtClickedViewController:self];
        }
    // }else{
    //     [NvTipToast showInfoWithMessage:NSLocalizedString(@"Save_Failed", @"")];
    // }
}

- (IBAction)saveCoverClicked:(UIButton *)sender {
    [_moduleManager saveCover:self.imagePath with:^(BOOL success) {
        dispatch_async(dispatch_get_main_queue(), ^{
            if (success){
                [NvTipToast showInfoWithMessage:NSLocalizedString(@"Save Successful", @"")];
            }else{
                [NvTipToast showInfoWithMessage:NSLocalizedString(@"Save Failed", @"")];
            }
        });
    }];
}

-(void)viewTap:(UITapGestureRecognizer*)tap{
    if (self.textView.isFirstResponder) {
        [self.textView resignFirstResponder];
    }
}

- (void)finish:(NSString *)outputPath{
    [[NSFileManager defaultManager] removeItemAtPath:outputPath error:nil];
    if (self.presentingViewController.presentingViewController){
        [self.presentingViewController.presentingViewController dismissViewControllerAnimated:YES completion:^{
            [self->_moduleManager exitVideoEdit:self.projectId];
        }];
    }else{
        [self.navigationController dismissViewControllerAnimated:YES completion:^{
            [self->_moduleManager exitVideoEdit:self.projectId];
        }];
    }
}

@end

