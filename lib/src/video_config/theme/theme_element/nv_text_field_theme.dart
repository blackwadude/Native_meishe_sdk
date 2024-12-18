import 'nv_label_theme.dart';

/*! \if ENGLISH
 *
 *  \brief TextField Configuration item
 *  \else
 *
 *  \brief TextField配置项
 *  \endif
*/
class NvTextFieldTheme extends NvLabelTheme {
/*! \if ENGLISH
 *
 *  \brief Placeholder font size
 *  \else
 *
 *  \brief 占位符字体大小
 *  \endif
*/
  num? placeholderFontSize;

/*! \if ENGLISH
 *
 *  \brief Placeholder font family
 *  \else
 *
 *  \brief 占位符字体名称
 *  \endif
*/
  String? placeholderFontFamily;

/*! \if ENGLISH
 *
 *  \brief Placeholder text color
 *  \else
 *
 *  \brief 占位符文本颜色
 *  \endif
*/
  String? placeholderColor;

  // 构造函数
  NvTextFieldTheme() : super();

// MARK: -- encode && decode
  @override
  jsonEncode() {
    Map<String, dynamic> jsonMap = super.jsonEncode();
    if (placeholderFontSize != null) {
      jsonMap['placeholderFontSize'] = placeholderFontSize;
    }
    if (placeholderFontFamily != null) {
      jsonMap['placeholderFontFamily'] = placeholderFontFamily;
    }
    if (placeholderColor != null) {
      jsonMap['placeholderColor'] = placeholderColor;
    }
    return jsonMap;
  }
}
