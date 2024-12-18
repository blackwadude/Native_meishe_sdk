import '../theme_element/nv_view_theme.dart';

/*! \if ENGLISH
 *
 *  \brief TemplateEditClipSectionTheme Configuration item
 *  \else
 *
 *  \brief TemplateEditClipSectionTheme配置项
 *  \endif
*/
class NvTemplateEditClipSectionTheme extends NvViewTheme {
/*! \if ENGLISH
 *
 *  \brief Fill color
 *  \else
 *
 *  \brief 填充颜色
 *  \endif
*/
  String? fillColor;

  // 构造函数
  NvTemplateEditClipSectionTheme() : super();

  //MARK: -- encode && decode
  @override
  jsonEncode() {
    Map<String, dynamic> jsonMap = super.jsonEncode();
    if (fillColor != null) {
      jsonMap['fillColor'] = fillColor;
    }
    return jsonMap;
  }
}
