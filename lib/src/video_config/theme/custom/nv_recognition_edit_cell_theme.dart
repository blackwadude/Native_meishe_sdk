import '../theme_element/nv_cell_theme.dart';
import '../theme_element/nv_button_theme.dart';

/*! \if ENGLISH
 *
 *  \brief MaterialCellTheme Configuration item
 *  \else
 *
 *  \brief MaterialCellTheme配置项
 *  \endif
*/
class NvRecognitionEditCellTheme extends NvCellTheme {
/*! \if ENGLISH
 *
 *  \brief Play button style
 *  \else
 *
 *  \brief 播放按钮样式
 *  \endif
*/
  NvButtonTheme? playBtTheme;

  // 构造函数
  NvRecognitionEditCellTheme() : super();

// MARK: -- encode && decode
  @override
  jsonEncode() {
    Map<String, dynamic> jsonMap = super.jsonEncode();
    if (playBtTheme != null) jsonMap['playBtTheme'] = playBtTheme!.jsonEncode();
    return jsonMap;
  }
}
