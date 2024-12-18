import 'nv_view_theme.dart';
import 'nv_label_theme.dart';

/*! \if ENGLISH
 *
 *  \brief CellTheme Configuration item
 *  \else
 *
 *  \brief CellTheme配置项
 *  \endif
*/
class NvCellTheme extends NvViewTheme {
/*! \if ENGLISH
 *
 *  \brief Text style
 *  \else
 *
 *  \brief 文本样式
 *  \endif
*/
  NvLabelTheme? titleLabel;

  // 构造函数
  NvCellTheme() : super();
  
// MARK: -- encode && decode
  @override
  jsonEncode() {
    Map<String, dynamic> jsonMap = super.jsonEncode();
    if (titleLabel != null) jsonMap['titleLabel'] = titleLabel!.jsonEncode();
    return jsonMap;
  }
}
