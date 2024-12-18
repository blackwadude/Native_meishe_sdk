import '../theme_element/nv_button_theme.dart';
import '../theme_element/nv_cell_theme.dart';
import '../theme_element/nv_label_theme.dart';
import '../theme_element/nv_image_view_theme.dart';

/*! \if ENGLISH
 *
 *  \brief TemplateHomeCellTheme Configuration item
 *  \else
 *
 *  \brief TemplateHomeCellTheme配置项
 *  \endif
*/
class NvTemplateHomeCellTheme extends NvCellTheme {
/*! \if ENGLISH
 *
 *  \brief Text style
 *  \else
 *
 *  \brief 文字样式
 *  \endif
*/
  NvLabelTheme? descriptionLabel;

/*! \if ENGLISH
 *
 *  \brief Picture style
 *  \else
 *
 *  \brief 图片样式
 *  \endif
*/
  NvImageViewTheme? imageView;

/*! \if ENGLISH
 *
 *  \brief Secondary image style
 *  \else
 *
 *  \brief 二级图片样式
 *  \endif
*/
  NvImageViewTheme? centerImageView;

/*! \if ENGLISH
 *
 *  \brief Button style
 *  \else
 *
 *  \brief 按钮样式
 *  \endif
*/
  NvButtonTheme? button;

  // 构造函数
  NvTemplateHomeCellTheme() : super();

  //MARK: -- encode && decode
  @override
  jsonEncode() {
    Map<String, dynamic> jsonMap = super.jsonEncode();
    if (descriptionLabel != null) {
      jsonMap['descriptionLabel'] = descriptionLabel!.jsonEncode();
    }
    if (imageView != null) {
      jsonMap['imageView'] = imageView!.jsonEncode();
    }
    if (centerImageView != null) {
      jsonMap['centerImageView'] = centerImageView!.jsonEncode();
    }
    if (button != null) {
      jsonMap['button'] = button!.jsonEncode();
    }

    return jsonMap;
  }
}
