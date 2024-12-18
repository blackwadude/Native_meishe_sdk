import '../theme_element/nv_button_theme.dart';
import '../theme_element/nv_cell_theme.dart';
import '../theme_element/nv_image_view_theme.dart';

/*! \if ENGLISH
 *
 *  \brief MusicSearchCellTheme Configuration item
 *  \else
 *
 *  \brief MusicSearchCellTheme配置项
 *  \endif
*/
class NvMusicSearchCellTheme extends NvCellTheme {
/*! \if ENGLISH
 *
 *  \brief Left icon style
 *  \else
 *
 *  \brief 左侧图标样式
 *  \endif
*/
  NvImageViewTheme? imageView;
/*! \if ENGLISH
 *
 *  \brief Remove button style
 *  \else
 *
 *  \brief 删除按钮样式
 *  \endif
*/
  NvButtonTheme? deleteBt;

  // 构造函数
  NvMusicSearchCellTheme() : super();

// MARK: -- encode && decode
  @override
  jsonEncode() {
    Map<String, dynamic> jsonMap = super.jsonEncode();
    if (imageView != null) jsonMap['imageView'] = imageView!.jsonEncode();
    if (deleteBt != null) jsonMap['deleteBt'] = deleteBt!.jsonEncode();
    return jsonMap;
  }
}
