import 'nv_view_theme.dart';

/*! \if ENGLISH
 *
 *  \brief Llabel Configuration item
 *  \else
 *
 *  \brief Label配置项
 *  \endif
*/
class NvLabelTheme extends NvViewTheme {
/*! \if ENGLISH
 *
 *  \brief UIFont size
 *  \else
 *
 *  \brief 字体大小
 *  \endif
*/
  num? fontSize;
/*! \if ENGLISH
 *
 *  \brief UIFont family
 *  \else
 *
 *  \brief 字体名称
 *  \endif
*/
  String? fontFamily;

/*! \if ENGLISH
 *
 *  \brief Text color
 *  \else
 *
 *  \brief 文字颜色
 *  \endif
*/
  String? textColor;

  NvLabelTheme() : super();

// MARK: -- encode && decode
  @override
  jsonEncode() {
    Map<String, dynamic> jsonMap = super.jsonEncode();
    if (fontSize != null) jsonMap['fontSize'] = fontSize;
    if (fontFamily != null) jsonMap['fontFamily'] = fontFamily;
    if (textColor != null) jsonMap['textColor'] = textColor;
    return jsonMap;
  }

  static NvLabelTheme jsonDecode(Map<String, dynamic> json) {
    NvLabelTheme theme = NvLabelTheme();
    theme.hidden = json['hidden'] == null ? false : json['hidden'] as bool;
    theme.backgroundColor = json['backgroundColor'] as String?;
    theme.tintColor = json['tintColor'] as String?;
    theme.borderColor = json['borderColor'] as String?;
    theme.borderWidth = json['borderWidth'] as double?;
    theme.fontSize = json['fontSize'] as num?;
    theme.fontFamily = json['fontFamily'] as String?;
    theme.textColor = json['textColor'] as String?;
    return theme;
  }
}
