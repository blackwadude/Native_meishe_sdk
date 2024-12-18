import '../theme_element/nv_view_theme.dart';
import '../theme_element/nv_button_theme.dart';

/*! \if ENGLISH
 *
 *  \brief CaptionViewTheme Configuration item
 *  \else
 *
 *  \brief CaptionViewTheme配置项
 *  \endif
*/
class NvCaptionViewTheme extends NvViewTheme {
/*! \if ENGLISH
 *
 *  \brief Cursor color
 *  \else
 *
 *  \brief 光标颜色
 *  \endif
*/
  String? textViewTintColor;

/*! \if ENGLISH
 *
 *  \brief Complete button style
 *  \else
 *
 *  \brief 完成按钮样式
 *  \endif
*/
  NvButtonTheme? doneBt;

/*! \if ENGLISH
 *
 *  \brief Align icon
 *  \else
 *
 *  \brief 对齐图标
 *  \endif
*/
  String? leftAlignmentImage;
  String? centerAlignmentImage;
  String? rightAlignmentImage;

/*! \if ENGLISH
 *
 *  \brief Caption style corresponding icon
 *  \else
 *
 *  \brief 字幕样式对应的图标
 *  \endif
*/
  String? styleNoneImage;
  String? styleBgImage;
  String? styleBgAlphaImage;
  String? styleOutlineImage;

/*! \if ENGLISH
 *
 *  \brief Font style
 *  \else
 *
 *  \brief 字体样式
 *  \endif
*/
  NvViewTheme? fontCellTheme;
  NvViewTheme? fontCellSelectedTheme;

/*! \if ENGLISH
 *
 *  \brief Color style
 *  \else
 *
 *  \brief 颜色样式
 *  \endif
*/
  NvViewTheme? colorCellTheme;
  NvViewTheme? colorCellSelectedTheme;

  // 构造函数
  NvCaptionViewTheme() : super();

// MARK: -- encode && decode
  @override
  jsonEncode() {
    Map<String, dynamic> jsonMap = super.jsonEncode();
    if (textViewTintColor != null) {
      jsonMap['textViewTintColor'] = textViewTintColor;
    }
    if (doneBt != null) jsonMap['doneBt'] = doneBt!.jsonEncode();
    if (leftAlignmentImage != null) {
      jsonMap['leftAlignmentImage'] = leftAlignmentImage;
    }
    if (centerAlignmentImage != null) {
      jsonMap['centerAlignmentImage'] = centerAlignmentImage;
    }
    if (rightAlignmentImage != null) {
      jsonMap['rightAlignmentImage'] = rightAlignmentImage;
    }
    if (styleNoneImage != null) jsonMap['styleNoneImage'] = styleNoneImage;
    if (styleBgImage != null) jsonMap['styleBgImage'] = styleBgImage;
    if (styleBgAlphaImage != null) {
      jsonMap['styleBgAlphaImage'] = styleBgAlphaImage;
    }
    if (styleOutlineImage != null) {
      jsonMap['styleOutlineImage'] = styleOutlineImage;
    }
    if (fontCellTheme != null) {
      jsonMap['fontCellTheme'] = fontCellTheme!.jsonEncode();
    }
    if (fontCellSelectedTheme != null) {
      jsonMap['fontCellSelectedTheme'] = fontCellSelectedTheme!.jsonEncode();
    }
    if (colorCellTheme != null) {
      jsonMap['colorCellTheme'] = colorCellTheme!.jsonEncode();
    }
    if (colorCellSelectedTheme != null) {
      jsonMap['colorCellSelectedTheme'] = colorCellSelectedTheme!.jsonEncode();
    }
    return jsonMap;
  }
}
