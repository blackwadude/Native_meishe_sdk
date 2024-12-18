//
//  NvThemeElementKey.h
//  NvShortVideoCore
//
//  Created by meishe on 2024/3/20.
//

#import <Foundation/Foundation.h>


/*
ThemeElementKey : 模块名称_页面名称_组件名称_组件类型
ThemeElementKey : module_viewControllerName_elementName_type
 */

// ViewController: 拍摄
// ViewController: Capture

/*! \if ENGLISH
 *  \brief Capture view
 *  \else
 *  \brief 拍摄页面
 *  \endif
*/
#define NvCaptureViewKey            @"capture_capture_view"

#define NvCaptureCloseBtKey         @"capture_capture_close_bt"
#define NvCaptureNextBtKey          @"capture_capture_next_bt"
#define NvCaptureAlbumBtKey         @"capture_capture_album_bt"
#define NvCaptureDeleteBtKey        @"capture_capture_delete_bt"

#define NvCaptureLeftMenuDevBtKey       @"capture_left_menu_dev_bt"
#define NvCaptureLeftMenuSpeedBtKey     @"capture_left_menu_speed_bt"
#define NvCaptureLeftMenuFlashBtKey     @"capture_left_menu_flash_bt"
#define NvCaptureLeftMenuBeautyBtKey    @"capture_left_menu_beauty_bt"
#define NvCaptureLeftMenuMakeupBtKey    @"capture_left_menu_makeup_bt"
#define NvCaptureLeftMenuTimerBtKey     @"capture_left_menu_timer_bt"
#define NvCaptureLeftMenuPropsBtKey     @"capture_left_menu_props_bt"
#define NvCaptureLeftMenuFilterBtKey    @"capture_left_menu_filter_bt"
#define NvCaptureLeftMenuOriginalBtKey  @"capture_left_menu_original_bt"
#define NvCaptureLeftMenuDualTypeBtKey  @"capture_left_menu_dualtype_bt"

#define NvCaptureDurationPointView      @"capture_duration_point_view"
#define NvCaptureDurationLabelKey       @"capture_duration_label"

/*! \if ENGLISH
 *  \brief Capture record button,   object:  NvRecordBtTheme
 *  \else
 *  \brief 拍摄按钮， 类型：NvRecordBtTheme
 *  \endif
*/
#define NvCaptureRecordBtSetKey         @"capture_capture_record_bt_set"

// NvCellTheme
#define NvCaptureBottomMenuCellKey          @"capture_bottom_menu_cell"
#define NvCaptureBottomMenuCellSelectedKey  @"capture_bottom_menu_cell_selected"

// NvCellTheme
#define NvCaptureTopMenuCellKey             @"capture_top_menu_cell"
#define NvCaptureTopMenuCellSelectedKey     @"capture_top_menu_cell_selected"

#define NvCaptureMusicMenuViewKey           @"capture_music_menu_view"
#define NvCaptureMusicMenuImageViewKey      @"capture_music_menu_imageview"
#define NvCaptureMusicMenuTextLabelKey      @"capture_music_menu_text_label"
#define NvCaptureMusicMenuDeleteBtKey       @"capture_music_menu_delete_bt"
#define NvCaptureMusicMenuLineViewKey       @"capture_music_menu_line_view"


#define NvCaptureMusicPanelViewKey          @"capture_music_panel_view"
#define NvCaptureMusicSearchPanelViewKey    @"capture_music_search_panel_view"
#define NvCaptureMusicCutPanelViewKey       @"capture_music_cut_panel_view"

#define NvCaptureMusicPanelLineViewKey          @"capture_music_panel_line_view"
#define NvCaptureMusicCutPanelLineViewKey       @"capture_music_cut_panel_line_view"

#define NvCaptureMusicCutPanelTitleLabelKey     @"capture_music_cut_panel_title_label"

#define NvCapturePanelBackBtKey                 @"capture_panel_back_bt"


// NvCellTheme
#define NvCaptureMusicPanelCaptegoryCellKey     @"capture_music_category_cell"
#define NvCaptureMusicPanelCaptegoryLineViewKey @"capture_music_category_line_view"

#define NvCaptureMusicPanelSearchBtKey          @"capture_music_pannel_search_bt"

// NvMusicCellTheme
#define NvCaptureMusicCellKey                   @"capture_music_cell"
#define NvCaptureMusicCellSelectedKey           @"capture_music_cell_selected"

// NvMusicSearchCellTheme
#define NvCaptureMusicHistoryCellKey            @"capture_music_search_history_cell"

// NvTextFieldTheme
#define NvCaptureMusicSearchTextFieldKey        @"capture_music_search_textfield"

#define NvCaptureMusicSearchEmptyLabelKey       @"capture_music_search_empty_label"
#define NvCaptureMusicSearchLineViewKey         @"capture_music_search_line_view"

// NvMusciCutViewTheme
#define NvCaptureMusicCutViewSetKey             @"capture_music_cut_view_set"

#define NvCaptureDualTypeModeBtKey              @"capture_dual_type_mode_bt"
#define NvCaptureDualTypeExchangeBtKey          @"capture_dual_type_exchange_bt"
#define NvCaptureDualTypePanelLineViewKey       @"capture_dual_type_panel_line_view"
#define NvCaptureDualTypeTitleLabelKey          @"capture_dual_type_title_label"
#define NvCaptureDualTypeLeftRightBtKey         @"capture_dual_type_left_right_bt"
#define NvCaptureDualTypeTopDownBtKey           @"capture_dual_type_top_down_bt"
#define NvCaptureDualTypeLeftRectBtKey          @"capture_dual_type_left_rect_bt"
#define NvCaptureDualTypeLeftCircleBtKey        @"capture_dual_type_left_circle_bt"
#define NvCaptureDualTypeTopCircleBtKey         @"capture_dual_type_top_circle_bt"

#define NvCaptureFilterPanelViewKey             @"capture_filter_panel_view"
#define NvCaptureFilterPanelDoneBtKey           @"capture_filter_panel_done_bt"
#define NvCaptureFilterPanelEmptyBtKey          @"capture_filter_panel_empty_bt"
// NvCellTheme
#define NvCaptureFilterPanelCategoryCellKey             @"capture_filter_panel_category_cell"
#define NvCaptureFilterPanelCategoryCellSelectedKey     @"capture_filter_panel_category_cell_selected"
// NvMaterialCellTheme
#define NvCaptureFilterPanelMaterialCellKey             @"capture_filter_panel_material_cell"
#define NvCaptureFilterPanelMaterialCellSelectedKey     @"capture_filter_panel_material_cell_selected"
// NvSliderTheme
#define NvCaptureFilterPanelIntensitySliderKey      @"capture_filter_panel_intensity_slider"
#define NvCaptureFilterPanelIntensityLabelKey       @"capture_filter_panel_intensity_label"
#define NvCaptureFilterPanelCategoryLineViewKey     @"capture_filter_panel_category_line_view"


#define NvCapturePropPanelViewKey                           @"capture_prop_panel_view"
#define NvCapturePropPanelEmptyBtKey                        @"capture_prop_panel_empty_bt"
// NvCellTheme
#define NvCapturePropPanelCategoryCellKey                   @"capture_prop_panel_category_cell"
#define NvCapturePropPanelCategoryCellSelectedKey           @"capture_prop_panel_category_cell_selected"
// NvMaterialCellTheme
#define NvCapturePropPanelMaterialCellKey                   @"capture_prop_panel_material_cell"
#define NvCapturePropPanelMaterialCellSelectedKey           @"capture_prop_panel_material_cell_selected"
#define NvCapturePropPanelCategoryLineViewKey               @"capture_prop_panel_category_line_view"

/// 美颜面板
/// Beauty panel
//NvBeautyPanelTheme
#define NvCaptureBeautyPanelViewSetKey                            @"capture_beautyPanel_view_set"
#define NvCaptureBeautyPanelCategoryViewKey                       @"capture_beautyPanel_Category_view"
//NvCellTheme
#define NvCaptureBeautyPanelCategoryCellKey                       @"capture_beautyPanel_Category_cell"
//NvCellTheme
#define NvCaptureBeautyPanelCategoryCellSelectedKey               @"capture_beautyPanel_Category_cell_selected"
#define NvCaptureBeautyPanelMaterialViewKey                       @"capture_beautyPanel_Material_view"
//NvMaterialCellTheme
#define NvCaptureBeautyPanelMaterialCellKey                       @"capture_beautyPanel_Material_cell"
//NvMaterialCellTheme
#define NvCaptureBeautyPanelMaterialCellSelectedKey               @"capture_beautyPanel_Material_cell_selected"

/// 美妆面板
/// Beauty makeup panel
//NvBeautyPanelTheme
#define NvCaptureMakeupPanelViewSetKey                            @"capture_makeupPanel_view_set"
#define NvCaptureMakeupPanelCategoryViewKey                       @"capture_makeupPanel_Category_view"
//NvCellTheme
#define NvCaptureMakeupPanelCategoryCellKey                       @"capture_makeupPanel_Category_cell"
//NvCellTheme
#define NvCaptureMakeupPanelCategoryCellSelectedKey               @"capture_makeupPanel_Category_cell_selected"
#define NvCaptureMakeupPanelMaterialViewKey                       @"capture_makeupPanel_Material_view"
//NvMaterialCellTheme
#define NvCaptureMakeupPanelMaterialCellKey                       @"capture_makeupPanel_Material_cell"
//NvMaterialCellTheme
#define NvCaptureMakeupPanelMaterialCellSelectedKey               @"capture_makeupPanel_Material_cell_selected"

#define NvCapturePrivilegeCloseBtKey        @"capture_privilege_close_bt"
#define NvCapturePrivilegeLocalBtKey        @"capture_privilege_local_bt"
#define NvCapturePrivilegeTitleLableKey     @"capture_privilege_title_label"
#define NvCapturePrivilegeDeseLabelKey      @"capture_privilege_dese_label"
#define NvCapturePrivilegeCameraBtKey       @"capture_privilege_camera_bt"
#define NvCapturePrivilegeAudioBtKey        @"capture_privilege_audio_bt"
#define NvCapturePrivilegePhotoBtKey        @"capture_privilege_photo_bt"
#define NvCapturePrivilegeViewKey           @"capture_privilege_view"


//MARK: -- Alert

/*! \if ENGLISH
 *  \brief Capture alert
 *  \else
 *  \brief 拍摄Alert
 *  \endif
*/
#define NvCaptureAlertViewKey           @"capture_alert_view"
#define NvCaptureAlertTitleLabelKey     @"capture_alert_title_label"
#define NvCaptureAlertMessageLabelKey   @"capture_alert_message_label"
#define NvCaptureAlertConfirmBtKey      @"capture_alert_confirm_bt"
#define NvCaptureAlertCancelBtKey       @"capture_alert_cancel_bt"

//MARK: -- Edit / 编辑页面

/*! \if ENGLISH
 *  \brief Edit view
 *  \else
 *  \brief 编辑页面
 *  \endif
*/
#define NvEditVCViewKey                 @"edit_edit_vc_view"

/*! \if ENGLISH
 *  \brief Edit view back button
 *  \else
 *  \brief 编辑页面返回按钮
 *  \endif
*/
#define NvEditVCBackBtKey               @"edit_edit_vc_back_bt"


/*! \if ENGLISH
 *  \brief Edit view right menu
 *  \else
 *  \brief 编辑页面右侧菜单
 *  \endif
*/
#define NvEditLeftMenuReleaseBtKey              @"edit_left_menu_release_bt"
#define NvEditLeftMenuDownloadBtKey             @"edit_left_menu_download_bt"
#define NvEditLeftMenuEditBtKey                 @"edit_left_menu_edit_bt"
#define NvEditLeftMenuEffectBtKey               @"edit_left_menu_effect_bt"
#define NvEditLeftMenuAudioEffectBtKey          @"edit_left_menu_audioeffect_bt"
#define NvEditLeftMenuStickerBtKey              @"edit_left_menu_sticker_bt"
#define NvEditLeftMenuCaptionBtKey              @"edit_left_menu_caption_bt"
#define NvEditLeftMenuRecognitionCaptionBtKey   @"edit_left_menu_recognition_caption_bt"
#define NvEditLeftMenuFilterBtKey               @"edit_left_menu_filter_bt"

/*! \if ENGLISH
 *  \brief Edit view top music display view
 *  \else
 *  \brief 编辑顶部音乐展示区域
 *  \endif
*/
#define NvEditMusicMenuViewKey           @"edit_music_menu_view"

/*! \if ENGLISH
 *  \brief Edit view top music display view: music icon
 *  \else
 *  \brief 编辑顶部音乐展示区域: 音乐图标
 *  \endif
*/
#define NvEditMusicMenuImageViewKey      @"edit_music_menu_imageview"

/*! \if ENGLISH
 *  \brief Edit view top music display view: music name label
 *  \else
 *  \brief 编辑顶部音乐展示区域: 音乐名称
 *  \endif
*/
#define NvEditMusicMenuTextLabelKey      @"edit_music_menu_text_label"

/*! \if ENGLISH
 *  \brief Edit view top music display view: delete button
 *  \else
 *  \brief 编辑顶部音乐展示区域: 删除按钮
 *  \endif
*/
#define NvEditMusicMenuDeleteBtKey       @"edit_music_menu_delete_bt"

/*! \if ENGLISH
 *  \brief Edit view top music display view: line
 *  \else
 *  \brief 编辑顶部音乐展示区域: 分割线
 *  \endif
*/
#define NvEditMusicMenuLineViewKey       @"edit_music_menu_line_view"

/*! \if ENGLISH
 *  \brief Edit view music panel
 *  \else
 *  \brief 编辑音乐面板
 *  \endif
*/
#define NvEditMusicPanelViewKey             @"edit_music_panel_view"

/*! \if ENGLISH
 *  \brief Edit view music search panel
 *  \else
 *  \brief 编辑音乐搜素面板
 *  \endif
*/
#define NvEditMusicSearchPanelViewKey       @"edit_music_search_panel_view"

/*! \if ENGLISH
 *  \brief Edit view music crop panel
 *  \else
 *  \brief 编辑音乐裁剪面板
 *  \endif
*/
#define NvEditMusicCutPanelViewKey          @"edit_music_cut_panel_view"

/*! \if ENGLISH
 *  \brief Edit view volume panel
 *  \else
 *  \brief 编辑音量面板
 *  \endif
*/
#define NvEditVolumPanelViewKey             @"edit_music_volume_panel_view"

/*! \if ENGLISH
 *  \brief Edit view effect panel
 *  \else
 *  \brief 编辑特效面板
 *  \endif
*/
#define NvEditAudioEffectPanelViewKey       @"edit_audio_effect_panel_view"
#define NvEditRecordPanelViewKey            @"edit_audio_record_panel_view"
#define NvEditEffectDurationPanelViewKey    @"edit_effect_duration_panel_view"

#define NvEditPanelBackBtKey                @"edit_panel_back_bt"

#define NvEditMusicPanelLineViewKey             @"edit_music_panel_line_view"
#define NvEditMusicCutPanelLineViewKey          @"edit_music_cut_panel_line_view"
#define NvEditVolumPanelLineViewKey             @"edit_music_volume_panel_line_view"
#define NvEditAudioEffectPanelLineViewKey       @"edit_audio_effect_panel_line_view"
#define NvEditRecordPanelLineViewKey            @"edit_audio_record_panel_line_view"
#define NvEditEffectDurationPanelLineViewKey    @"edit_effect_duration_panel_line_view"

#define NvEditMusicCutPanelTitleLabelKey             @"edit_music_cut_panel_title_label"
#define NvEditEffectDurationPanelTitleLabelKey       @"edit_effect_duration_panel_title_label"

// NvCellTheme
#define NvEditMusicPanelCaptegoryCellKey        @"edit_music_category_cell"
#define NvEditMusicPanelCaptegoryLineViewKey    @"edit_music_category_line_view"

#define NvEditMusicPanelSearchBtKey         @"edit_music_pannel_search_bt"
#define NvEditMusicPanelOriginalBtKey       @"edit_music_pannel_original_bt"
#define NvEditMusicPanelSoundBtKey          @"edit_music_pannel_sound_bt"
#define NvEditMusicPanelVolumeBtKey         @"edit_music_pannel_volume_bt"

// NvMusicCellTheme
#define NvEditMusicCellKey                  @"edit_music_cell"
#define NvEditMusicCellSelectedKey          @"edit_music_cell_selected"

// NvMusicSearchCellTheme
#define NvEditMusicHistoryCellKey           @"edit_music_search_history_cell"
// NvTextFieldTheme
#define NvEditMusicSearchTextFieldKey       @"edit_music_search_textfield"

#define NvEditMusicSearchEmptyLabelKey      @"edit_music_search_empty_label"
#define NvEditMusicSearchLineViewKey        @"edit_music_search_line_view"

// NvMusciCutViewTheme
#define NvEditMusicCutViewSetKey            @"edit_music_cut_view_set"

#define NvEditFilterPanelViewKey            @"edit_filter_panel_view"
#define NvEditFilterPanelDoneBtKey          @"edit_filter_panel_done_bt"
#define NvEditFilterPanelEmptyBtKey         @"edit_filter_panel_empty_bt"
// NvCellTheme
#define NvEditFilterPanelCategoryCellKey            @"edit_filter_panel_category_cell"
#define NvEditFilterPanelCategoryCellSelectedKey    @"edit_filter_panel_category_cell_selected"
// NvMaterialCellTheme
#define NvEditFilterPanelMaterialCellKey            @"edit_filter_panel_material_cell"
#define NvEditFilterPanelMaterialCellSelectedKey    @"edit_filter_panel_material_cell_selected"
// NvSliderTheme
#define NvEditFilterPanelIntensitySliderKey         @"edit_filter_panel_intensity_slider"
#define NvEditFilterPanelIntensityLabelKey          @"edit_filter_panel_intensity_label"
#define NvEditFilterPanelCategoryLineViewKey        @"edit_filter_panel_category_line_view"

#define NvEditStickerPanelViewKey                       @"edit_sticker_panel_view"
#define NvEditStickerPanelCategoryCellKey               @"edit_sticker_panel_category_cell"
#define NvEditStickerPanelCategoryCellSelectedKey       @"edit_sticker_panel_category_cell_selected"
#define NvEditStickerPanelMaterialCellKey               @"edit_sticker_panel_material_cell"
#define NvEditStickerPanelMaterialCellSelectedKey       @"edit_sticker_panel_material_cell_selected"
#define NvEditStickerPanelCategoryLineViewKey           @"edit_sticker_panel_category_line_view"
#define NvEditStickerPanelCategoryBottomLineViewKey     @"edit_sticker_panel_category_bottom_line_view"


#define NvEditEffectPanelViewKey                       @"edit_effect_panel_view"
// NvCellTheme
#define NvEditEffectPanelCategoryCellKey               @"edit_effect_panel_category_cell"
#define NvEditEffectPanelCategoryCellSelectedKey       @"edit_effect_panel_category_cell_selected"
// NvMaterialCellTheme
#define NvEditEffectPanelMaterialCellKey               @"edit_effect_panel_material_cell"
#define NvEditEffectPanelMaterialCellSelectedKey       @"edit_effect_panel_material_cell_selected"
#define NvEditEffectPanelCategoryLineViewKey           @"edit_effect_panel_category_line_view"
#define NvEditEffectPanelCategoryBottomLineViewKey     @"edit_effect_panel_category_bottom_line_view"

// NvEffectTrackViewTheme
#define NvEditEffectVCTrackViewSetKey               @"edit_effect_vc_track_view_set"

#define NvEditEffectVCRightiMenuViewKey             @"edit_effect_vc_right_menu_view"
#define NvEditEffectVCRightiMenuRevertBtKey         @"edit_effect_vc_right_menu_revert_bt"
#define NvEditEffectVCRightiMenuForwardBtKey        @"edit_effect_vc_right_menu_forward_bt"
#define NvEditEffectVCRightiMenuDeleteBtKey         @"edit_effect_vc_right_menu_delete_bt"
#define NvEditEffectVCRightiMenuLineViewKey         @"edit_effect_vc_right_menu_line_view"
#define NvEditEffectVCBackBtKey                     @"edit_effect_vc_back_bt"
#define NvEditEffectVCDoneBtKey                     @"edit_effect_vc_done_bt"
#define NvEditEffectVCPlayBtKey                     @"edit_effect_vc_play_bt"
#define NvEditEffectVCViewKey                       @"edit_effect_vc_view"

#define NvEditAudioFxVCBackBtKey                    @"edit_audiofx_vc_back_bt"
#define NvEditAudioFxVCDoneBtKey                    @"edit_audiofx_vc_done_bt"
#define NvEditAudioFxVCPlayBtKey                    @"edit_audiofx_vc_play_bt"
#define NvEditAudioFxVCViewKey                      @"edit_audiofx_vc_view"

#define NvEditAudioFxPanelAudioFxCellKey            @"edit_audiofx_panel_audiofx_cell"
#define NvEditAudioFxPanelAudioFxCellSelectedKey    @"edit_audiofx_panel_audiofx_cell_selected"

#define NvEditAudioFxPanelBottomVolumeBtKey         @"edit_audiofx_panel_bottom_volume_bt"
#define NvEditAudioFxPanelBottomRecordBtKey         @"edit_audiofx_panel_bottom_record_bt"
#define NvEditAudioFxPanelBottomLineViewKey         @"edit_audiofx_panel_bottom_line_view"
#define NvEditAudioFxPanelBottomViewKey             @"edit_audiofx_panel_bottom_view"

#define NvEditVolumePanelTopSliderTitleLabelKey         @"edit_volume_panel_top_slider_title_label"
#define NvEditVolumePanelTopSliderKey                   @"edit_volume_panel_top_slider"
#define NvEditVolumePanelBottomSliderTitleLabelKey      @"edit_volume_panel_bottom_slider_title_label"
#define NvEditVolumePanelBottomSliderKey                @"edit_volume_panel_bottom_slider"

#define NvEditCaptionViewSetKey                         @"edit_caption_view_set"

#define NvEditRecordPanelOriginalBtKey                  @"edit_record_panel_original_bt"
#define NvEditRecordPanelRecordBtKey                    @"edit_record_panel_record_bt"
#define NvEditRecordPanelDeleteBtKey                    @"edit_record_panel_delete_bt"
#define NvEditRecordPanelSliderKnobViewKey              @"edit_record_panel_sliderKnob_view"
#define NvEditRecordPanelRecordLableKey                 @"edit_record_panel_record_lable"
#define NvEditRecordPanelTimeLableKey                   @"edit_record_panel_time_lable"

#define NvEditEffectTimeRangeViewSetKey                 @"edit_effect_time_range_view_set"


#define NvEditCompilePanelViewKey               @"edit_compile_panel_view"
#define NvEditCompilePanelInfoLabelKey          @"edit_compile_panel_info_label"
#define NvEditCompilePanelBackBtKey             @"edit_compile_panel_back_bt"
#define NvEditCompilePanelProgressSliderKey     @"edit_compile_panel_progress_slider"

// NvVideoTrackEditViewTheme
#define NvEditVideoTrackViewSetKey              @"edit_pro_edit_video_track_view_set"

#define NvProEditVCCenterLineViewKey             @"edit_pro_edit_vc_center_line_view"
#define NvProEditVCAddBtKey                      @"edit_pro_edit_vc_add_bt"
#define NvProEditVCDeleteBtKey                   @"edit_pro_edit_vc_delete_bt"

#define NvProEditVCBackBtKey                     @"edit_effect_vc_back_bt"
#define NvProEditVCPlayBtKey                     @"edit_pro_edit_vc_play_bt"
#define NvProEditVCViewKey                       @"edit_pro_edit_vc_view"


// MARK: -- 自动字幕 / Automatic captioning
#define NvEditRecognitionVcBackBtKey  @"edit_recognition_vc_back_bt"
#define NvEditRecognitionVcDoneBtKey  @"edit_recognition_vc_done_bt"
#define NvEditRecognitionVcPlayBtKey  @"edit_recognition_vc_play_bt"
#define NvEditRecognitionVcViewKey    @"edit_recognition_vc_view"

#define NvEditRecognitionWorkingViewKey                  @"edit_recognition_working_view"
#define NvEditRecognitionWorkingViewProgressLabelKey     @"edit_recognition_working_view_progress_label"
#define NvEditRecognitionWorkingViewTipLabelKey          @"edit_recognition_working_view_tip_label"
#define NvEditRecognitionWorkingViewLoadingImageViewKey  @"edit_recognition_working_view_loading_image_view"
#define NvEditRecognitionWorkingViewCancelBtKey          @"edit_recognition_working_view_cancel_bt"
#define NvEditRecognitionWorkingViewErrorLabelKey        @"edit_recognition_working_view_error_label"
#define NvEditRecognitionWorkingViewErrorTipLabelKey     @"edit_recognition_working_view_error_tip_label"
#define NvEditRecognitionWorkingViewRetryBtKey           @"edit_recognition_working_view_retry_bt"
#define NvEditRecognitionWorkingViewExamineBtKey         @"edit_recognition_working_view_examine_bt"
#define NvEditRecognitionWorkingViewEmptyTipLabelKey     @"edit_recognition_working_view_empty_tip_label"
#define NvEditRecognitionWorkingViewEmptyExitBtKey       @"edit_recognition_working_view_empty_exit_bt"


#define NvEditRecognitionViewDeleteBtKey            @"edit_recognition_view_delete_bt"
#define NvEditRecognitionViewStyleBtKey             @"edit_recognition_view_style_bt"
#define NvEditRecognitionViewEditBtKey              @"edit_recognition_view_edit_bt"
#define NvEditRecognitionViewCellKey                @"edit_recognition_view_cell"
#define NvEditRecognitionViewCellSelectedKey        @"edit_recognition_view_cell_selected"
#define NvEditRecognitionCaptionPanelViewKey        @"edit_recognition_caption_panel_view"
#define NvEditRecognitionViewPanelLineViewKey       @"edit_recognition_view_panel_line_view"

#define NvEditRecognitionStylePanelViewKey        @"edit_recognition_style_panel_view"
#define NvEditRecognitionStylePanelTitleLabelKey  @"edit_recognition_style_panel_title_label"
#define NvEditRecognitionStylePanelRightBtKey     @"edit_recognition_style_panel_right_bt"
#define NvEditRecognitionStylePanelLineViewKey    @"edit_recognition_style_panel_line_view"

#define NvEditRecognitionEditPanelViewKey          @"edit_recognition_edit_panel_view"
#define NvEditRecognitionEditPanelTitleLabelKey    @"edit_recognition_edit_panel_title_label"
#define NvEditRecognitionEditPanelRightBtKey       @"edit_recognition_edit_panel_right_bt"
#define NvEditRecognitionEditPanelLineViewKey      @"edit_recognition_edit_panel_line_view"
#define NvEditRecognitionEditCellKey               @"edit_recognition_edit_cell"
#define NvEditRecognitionEditCellSelectedKey       @"edit_recognition_edit_cell_selected"

//MARK: -- Alert

/*! \if ENGLISH
 *  \brief edit alert
 *  \else
 *  \brief 编辑Alert
 *  \endif
*/
#define NvEditAlertViewKey              @"edit_alert_view"
#define NvEditAlertTitleLabelKey        @"edit_alert_title_label"
#define NvEditAlertMessageLabelKey      @"edit_alert_message_label"
#define NvEditAlertConfirmBtKey         @"edit_alert_confirm_bt"
#define NvEditAlertCancelBtKey          @"edit_alert_cancel_bt"

// NvCellTheme
#define NvEditAlertMessageCellKey       @"edit_alert_message_cell"
#define NvEditAlertMessageCancelBtKey   @"edit_alert_message_cancel_bt"

//MARK: -- cover
/*! \if ENGLISH
 *  \brief
 *  \else
 *  \brief 封面
 *  \endif
*/
#define NvEditCoverTopHeaderViewKey                  @"edit_cover_topHeader_view"
#define NvEditCoverTopHeaderBackBtKey                @"edit_cover_topHeader_back_bt"
#define NvEditCoverTopHeaderTitleLabelKey            @"edit_cover_topHeader_title_label"
#define NvEditCoverTopHeaderDoneBtKey                @"edit_cover_topHeader_done_bt"
#define NvEditCoverImageViewKey                      @"edit_cover_image_view"
#define NvEditCoverThumbnailViewKey                  @"edit_cover_thumbnail_view"
#define NvEditCoverThumbnailSelectViewKey            @"edit_cover_thumbnailSelect_view"

//MARK: -- album
/*! \if ENGLISH
 *  \brief Album top area
 *  \else
 *  \brief 相册顶部区域
 *  \endif
*/
#define NvAlbumHomeTopHeaderViewKey                @"album_home_topHeader_view"
#define NvAlbumHomeCloseBtKey                      @"album_home_close_bt"
#define NvAlbumHomeTitleLabelKey                   @"album_home_title_label"

/*! \if ENGLISH
 *  \brief Album top TAB
 *  \else
 *  \brief 相册顶部标签
 *  \endif
*/
#define NvAlbumHomeTopTagViewKey                 @"album_home_topTag_view"
#define NvAlbumHomeTopTagAllBtKey                @"album_home_topTagAll_bt"
#define NvAlbumHomeTopTagVideoBtKey              @"album_home_topTagVideo_bt"
#define NvAlbumHomeTopTagImageBtKey              @"album_home_topTagImage_bt"
#define NvAlbumHomeTopLineViewKey                @"album_home_topLine_view"

/*! \if ENGLISH
 *  \brief Album material
 *  \else
 *  \brief 相册素材
 *  \endif
*/
#define NvAlbumHomeMaterialViewKey                 @"album_home_material_view"
//NvAlbumCellTheme
#define NvAlbumHomeMaterialCellKey                 @"album_home_material_cell"

/*! \if ENGLISH
 *  \brief Normal style album, bottom view
 *  \else
 *  \brief 普通样式相册，底部视图
 *  \endif
*/
#define NvAlbumHomeBottomViewKey                     @"album_home_bottom_view"
#define NvAlbumHomeBottomNextBtKey                   @"album_home_next_bt"
#define NvAlbumHomeBottomAutoCutBtKey                @"album_home_autoCut_bt"
//NvTemplateHomeCellTheme
#define NvAlbumHomeBottomCelley                      @"album_home_bottom_cell"
//NvTemplateHomeCellTheme
#define NvAlbumHomeBottomCellSelectedKey             @"album_home_bottom_cell_selected"

/*! \if ENGLISH
 *  \brief Template style album, bottom view
 *  \else
 *  \brief 模版样式相册，底部视图
 *  \endif
*/
#define NvAlbumHomeTemplateBottomViewKey             @"album_homeTemplate_bottom_view"
#define NvAlbumHomeTemplateBottomNextBtKey           @"album_homeTemplate_bottomNext_bt"
#define NvAlbumHomeTemplateBottomNextBtSelectedKey   @"album_homeTemplate_bottomNext_bt_selected"
#define NvAlbumHomeTemplateBottomShowTipLabelKey     @"album_homeTemplate_bottomShowTip_label"
#define NvAlbumHomeTemplateBottomShowNumberLabelKey  @"album_homeTemplate_bottomShowNumber_label"
//NvTemplateHomeCellTheme
#define NvAlbumHomeTemplateBottomCellKey             @"album_homeTemplate_bottom_cell"

//MARK: -- Template
/// 模版首页
/// Template home page
#define NvTemplateHomeCloseBtKey                @"template_home_close_bt"
#define NvTemplateHomeAutoCutBtKey              @"template_home_autoCut_bt"
//NvCellTheme
#define NvTemplateHomeCategoryCellKey           @"template_home_category_cell"
#define NvTemplateHomeCategoryCellSelectedKey   @"template_home_category_cell_selected"
//NvTemplateHomeCellTheme
#define NvTemplateHomeListCellKey               @"template_home_list_cell"
//NvTemplateHomeDataErrorTheme
#define NvTemplateHomeListDataErrorSetKey       @"template_home_listDataError_set"

/// 模版预览页
/// Template preview page
#define NvTemplatePreviewBackBtKey             @"template_preview_back_bt"
#define NvTemplatePreviewApplyBtKey            @"template_preview_apply_bt"
#define NvTemplatePreviewUserLabelKey          @"template_preview_user_label"
#define NvTemplatePreviewDescriptionLabelKey   @"template_preview_description_label"
#define NvTemplatePreviewInfoLabelKey          @"template_preview_info_label"

/// 模版编辑页
/// Template edit page
#define NvTemplateEditCloseBtKey                @"template_edit_close_bt"
#define NvTemplateEditAddBtKey                  @"template_edit_add_bt"
#define NvTemplateEditPublishBtKey              @"template_edit_publish_bt"
#define NvTemplateEditCaptionBtKey              @"template_edit_caption_bt"
#define NvTemplateEditPlayBtKey                 @"template_edit_play_bt"
#define NvTemplateEditTitleLabelKey             @"template_edit_title_label"
#define NvTemplateEditDescriptionLabelKey       @"template_edit_description_label"
// NvCellTheme
#define NvTemplateEditListCellKey               @"template_edit_list_cell"
#define NvTemplateEditCompileViewKey            @"template_edit_compile_view"
#define NvTemplateEditCompileTitleLabelKey      @"template_edit_compileTitle_label"
#define NvTemplateEditCompileProgressLabelKey   @"template_edit_compileProgress_label"
#define NvTemplateEditCompileProgressViewKey    @"template_edit_compileProgress_view"

/// 模版片段编辑页
/// Template clip edit page
#define NvTemplateEditClipViewKey                @"template_editClip_view"
//NvTemplateEditClipSectionTheme
#define NvTemplateEditClipSectionSetKey          @"template_editClip_section_set"
#define NvTemplateEditClipReplaceBtKey           @"template_editClip_replace_bt"
#define NvTemplateEditClipVerifyBtKey            @"template_editClip_verify_bt"
#define NvTemplateEditClipPlayBtKey              @"template_editClip_play_bt"
#define NvTemplateEditClipTitleLabelKey          @"template_editClip_title_label"
#define NvTemplateEditClipStartLabelKey          @"template_editClip_start_label"
#define NvTemplateEditClipEndLabelKey            @"template_editClip_end_label"

#define NvTemplateLoadingViewKey                 @"template_loading_view"
#define NvTemplateLoadingImageViewKey            @"template_loading_imageView"
#define NvTemplateLoadingTitleLabelKey           @"template_loading_title_label"
#define NvTemplateLoadingCancelBtKey             @"template_loading_cancel_bt"

/// 模版字幕编辑页
/// Template Caption edit page
#define NvTemplateEditCaptionViewKey             @"template_editCaption_view"
#define NvTemplateEditCaptionListViewKey         @"template_editCaption_list_view"
#define NvTemplateEditCaptionInputViewKey        @"template_editCaption_input_view"
#define NvTemplateEditCaptionInputTextViewKey    @"template_editCaption_inputText_view"
#define NvTemplateEditCaptionDoneBtKey           @"template_editCaption_done_bt"
#define NvTemplateEditCaptionListCellKey         @"template_editCaption_list_cell"

/// 一键成片的首页
/// AutoCut Home
#define NvTemplateAutoCutHomeCloseBtKey             @"template_autoCut_homeClose_bt"
#define NvTemplateAutoCutHomePlayBtKey              @"template_autoCut_homePlay_bt"
#define NvTemplateAutoCutHomePanelViewKey           @"template_autoCut_homePanel_view"
#define NvTemplateAutoCutHomePanelTemplateLabelKey  @"template_autoCut_homePanelTemplate_label"
//NvTemplateHomeCellTheme
#define NvTemplateAutoCutHomePanelCellKey           @"template_autoCut_homePanel_cell"
//NvTemplateHomeCellTheme
#define NvTemplateAutoCutHomePanelCellSelectedKey   @"template_autoCut_homePanel_cell_selected"

//MARK: -- Alert

/*! \if ENGLISH
 *  \brief template alert
 *  \else
 *  \brief 模版Alert
 *  \endif
*/
#define NvTemplateAlertViewKey              @"template_alert_view"
#define NvTemplateAlertTitleLabelKey        @"template_alert_title_label"
#define NvTemplateAlertMessageLabelKey      @"template_alert_message_label"
#define NvTemplateAlertConfirmBtKey         @"template_alert_confirm_bt"
#define NvTemplateAlertCancelBtKey          @"template_alert_cancel_bt"
