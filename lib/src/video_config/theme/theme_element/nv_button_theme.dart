import 'nv_view_theme.dart';
import 'nv_label_theme.dart';

/*! \if ENGLISH
 *
 *  \brief Button Configuration item
 *  \else
 *
 *  \brief Button配置项
 *  \endif
*/
class NvButtonTheme extends NvViewTheme {
/*! \if ENGLISH
 *
 *  \brief icon
 *  \else
 *
 *  \brief 图标
 *  \endif
*/
  String? imageName;

/*! \if ENGLISH
 *
 *  \brief The icon when selected
 *  \else
 *
 *  \brief 选中时的图标
 *  \endif
*/
  String? selectedImageName;

/*! \if ENGLISH
 *
 *  \brief Icon when disabled
 *  \else
 *
 *  \brief 禁用时的图标
 *  \endif
*/
  String? disableImageName;

/*! \if ENGLISH
 *
 *  \brief Text style
 *  \else
 *
 *  \brief 文本样式
 *  \endif
*/
  NvLabelTheme? title;

/*! \if ENGLISH
 *
 *  \brief Text style check
 *  \else
 *
 *  \brief 文本样式 选中
 *  \endif
*/
  NvLabelTheme? selectedTitle;

/*! \if ENGLISH
 *
 *  \brief Text style disabled
 *  \else
 *
 *  \brief 文本样式 禁用
 *  \endif
*/
  NvLabelTheme? disableTitle;

/*! \if ENGLISH
 *
 *  \brief The background color is selected
 *  \else
 *
 *  \brief 选中时背景颜色
 *  \endif
*/
  String? selectedBackgroundColor;

  // 构造函数
  NvButtonTheme() : super();

// MARK: -- encode && decode

  @override
  jsonEncode() {
    Map<String, dynamic> jsonMap = super.jsonEncode();
    if (imageName != null) {
      jsonMap['imageName'] = imageName;
    }
    if (selectedImageName != null) {
      jsonMap['selectedImageName'] = selectedImageName;
    }
    if (disableImageName != null) {
      jsonMap['disableImageName'] = disableImageName;
    }
    if (title != null) {
      jsonMap['title'] = title?.jsonEncode();
    }
    if (selectedTitle != null) {
      jsonMap['selectedTitle'] = selectedTitle?.jsonEncode();
    }
    if (disableTitle != null) {
      jsonMap['disableTitle'] = disableTitle?.jsonEncode();
    }
    if (selectedBackgroundColor != null) {
      jsonMap['selectedBackgroundColor'] = selectedBackgroundColor;
    }
    return jsonMap;
  }
}
