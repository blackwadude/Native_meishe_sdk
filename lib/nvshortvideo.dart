library nvshortvideo;

export 'package:nvshortvideo/src/nvvideooperator.dart';

//MARK: -- Config
export 'package:nvshortvideo/src/video_config/config/nv_video_config.dart';
export 'package:nvshortvideo/src/video_config/config/nv_album_config.dart';
export 'package:nvshortvideo/src/video_config/config/nv_beauty_config.dart';
export 'package:nvshortvideo/src/video_config/config/nv_bubble_config.dart';
export 'package:nvshortvideo/src/video_config/config/nv_capture_config.dart';
export 'package:nvshortvideo/src/video_config/config/nv_compile_config.dart';
export 'package:nvshortvideo/src/video_config/config/nv_dual_config.dart';
export 'package:nvshortvideo/src/video_config/config/nv_edit_config.dart';
export 'package:nvshortvideo/src/video_config/config/nv_model_config.dart';
export 'package:nvshortvideo/src/video_config/config/nv_template_config.dart';

//MARK: -- Theme
export 'package:nvshortvideo/src/video_config/theme/nv_theme_element_key.dart';

// theme_element
export 'package:nvshortvideo/src/video_config/theme/theme_element/nv_button_theme.dart';
export 'package:nvshortvideo/src/video_config/theme/theme_element/nv_cell_theme.dart';
export 'package:nvshortvideo/src/video_config/theme/theme_element/nv_image_view_theme.dart';
export 'package:nvshortvideo/src/video_config/theme/theme_element/nv_label_theme.dart';
export 'package:nvshortvideo/src/video_config/theme/theme_element/nv_slider_theme.dart';
export 'package:nvshortvideo/src/video_config/theme/theme_element/nv_text_field_theme.dart';
export 'package:nvshortvideo/src/video_config/theme/theme_element/nv_view_theme.dart';

// Custom

export 'package:nvshortvideo/src/video_config/theme/custom/nv_album_cell_theme.dart';
export 'package:nvshortvideo/src/video_config/theme/custom/nv_beauty_panel_theme.dart';
export 'package:nvshortvideo/src/video_config/theme/custom/nv_caption_view_theme.dart';
export 'package:nvshortvideo/src/video_config/theme/custom/nv_effect_time_range_view_theme.dart';
export 'package:nvshortvideo/src/video_config/theme/custom/nv_effect_track_view_theme.dart';
export 'package:nvshortvideo/src/video_config/theme/custom/nv_material_cell_theme.dart';
export 'package:nvshortvideo/src/video_config/theme/custom/nv_musci_cut_view_theme.dart';
export 'package:nvshortvideo/src/video_config/theme/custom/nv_music_cell_theme.dart';
export 'package:nvshortvideo/src/video_config/theme/custom/nv_music_search_cell_theme.dart';
export 'package:nvshortvideo/src/video_config/theme/custom/nv_record_bt_theme.dart';
export 'package:nvshortvideo/src/video_config/theme/custom/nv_template_edit_clip_section_theme.dart';
export 'package:nvshortvideo/src/video_config/theme/custom/nv_template_home_cell_theme.dart';
export 'package:nvshortvideo/src/video_config/theme/custom/nv_template_home_data_error_theme.dart';
export 'package:nvshortvideo/src/video_config/theme/custom/nv_video_track_edit_view_theme.dart';
export 'package:nvshortvideo/src/video_config/theme/custom/nv_recognition_edit_cell_theme.dart';

import 'package:nvshortvideo/src/facade/nvshortvideooperator.dart';
import 'package:nvshortvideo/src/nvvideooperator.dart';

NvVideoOperator shortVideoOperator() {
  return NvShortVideoOperator.getInstance();
}
