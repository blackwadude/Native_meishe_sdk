import '../theme_element/nv_button_theme.dart';
import '../theme_element/nv_view_theme.dart';
import '../theme_element/nv_label_theme.dart';

/*! \if ENGLISH
 *
 *  \brief TemplateHomeDataErrorTheme Configuration item
 *  \else
 *
 *  \brief TemplateHomeDataErrorTheme配置项
 *  \endif
*/
class NvTemplateHomeDataErrorTheme extends NvViewTheme {
/*! \if ENGLISH
 *
 *  \brief Text style
 *  \else
 *
 *  \brief 文本样式
 *  \endif
*/
  NvLabelTheme? titleLabel;

/*! \if ENGLISH
 *
 *  \brief Description text style
 *  \else
 *
 *  \brief 描述文本样式
 *  \endif
*/
  NvLabelTheme? descriptionLabel;

/*! \if ENGLISH
 *
 *  \brief Button style
 *  \else
 *
 *  \brief 按钮样式
 *  \endif
*/
  NvButtonTheme? retryBtn;

  // 构造函数
  NvTemplateHomeDataErrorTheme() : super();

  //MARK: -- encode && decode
  @override
  jsonEncode() {
    Map<String, dynamic> jsonMap = super.jsonEncode();
    if (titleLabel != null) {
      jsonMap['titleLabel'] = titleLabel!.jsonEncode();
    }
    if (descriptionLabel != null) {
      jsonMap['descriptionLabel'] = descriptionLabel!.jsonEncode();
    }
    if (retryBtn != null) {
      jsonMap['retryBtn'] = retryBtn!.jsonEncode();
    }
    return jsonMap;
  }
}
