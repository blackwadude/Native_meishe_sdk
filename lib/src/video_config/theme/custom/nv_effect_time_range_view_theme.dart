import '../theme_element/nv_view_theme.dart';
import '../theme_element/nv_image_view_theme.dart';

/*! \if ENGLISH
 *
 *  \brief EffectTimeRangeViewTheme Configuration item
 *  \else
 *
 *  \brief EffectTimeRangeViewTheme配置项
 *  \endif
*/
class NvEffectTimeRangeViewTheme extends NvViewTheme {
/*! \if ENGLISH
 *
 *  \brief Complete button style
 *  \else
 *
 *  \brief 完成按钮样式
 *  \endif
*/
  String? doneBtImage;

/*! \if ENGLISH
 *
 *  \brief Text color
 *  \else
 *
 *  \brief 文本颜色
 *  \endif
*/
  String? valueTextColor;
  String? valueSecondaryTextColor;

/*! \if ENGLISH
 *
 *  \brief Select the fragment Stroke style
 *  \else
 *
 *  \brief 选中片段描边样式
 *  \endif
*/
  String? clipBorderColor;
  num? clipBorderWidth;

/*! \if ENGLISH
 *
 *  \brief Center line style
 *  \else
 *
 *  \brief 中线样式
 *  \endif
*/
  NvViewTheme? centerLineView;

/*! \if ENGLISH
 *
 *  \brief Left and right handle pattern
 *  \else
 *
 *  \brief 左右把手样式
 *  \endif
*/
  String? leftHandleImage;
  String? rightHandleImage;

/*! \if ENGLISH
 *
 *  \brief Prompt text style
 *  \else
 *
 *  \brief 提示文本样式
 *  \endif
*/
  NvImageViewTheme? tipLabel;

  // 构造函数
  NvEffectTimeRangeViewTheme() : super();

// MARK: -- encode && decode
  @override
  jsonEncode() {
    Map<String, dynamic> jsonMap = super.jsonEncode();
    if (doneBtImage != null) jsonMap['doneBtImage'] = doneBtImage;
    if (valueTextColor != null) jsonMap['valueTextColor'] = valueTextColor;
    if (valueSecondaryTextColor != null) {
      jsonMap['valueSecondaryTextColor'] = valueSecondaryTextColor;
    }
    if (clipBorderColor != null) jsonMap['clipBorderColor'] = clipBorderColor;
    if (clipBorderWidth != null) jsonMap['clipBorderWidth'] = clipBorderWidth;
    if (centerLineView != null) {
      jsonMap['centerLineView'] = centerLineView!.jsonEncode();
    }
    if (leftHandleImage != null) jsonMap['leftHandleImage'] = leftHandleImage;
    if (rightHandleImage != null) {
      jsonMap['rightHandleImage'] = rightHandleImage;
    }
    if (tipLabel != null) jsonMap['tipLabel'] = tipLabel!.jsonEncode();
    return jsonMap;
  }
}
