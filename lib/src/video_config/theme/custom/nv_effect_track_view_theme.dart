import '../theme_element/nv_view_theme.dart';

/*! \if ENGLISH
 *
 *  \brief EffectTrackViewTheme Configuration item
 *  \else
 *
 *  \brief EffectTrackViewTheme配置项
 *  \endif
*/
class NvEffectTrackViewTheme extends NvViewTheme {
/*! \if ENGLISH
 *
 *  \brief Select the fragment Stroke color
 *  \else
 *
 *  \brief 选中片段描边颜色
 *  \endif
*/
  String? clipBorderColor;

/*! \if ENGLISH
 *
 *  \brief
 *  \else
 *
 *  \brief 选中片段描边宽度
 *  \endif
*/
  num? clipBorderWidth;

/*! \if ENGLISH
 *
 *  \brief Select the fragment stroke width
 *  \else
 *
 *  \brief 中间线样式
 *  \endif
*/
  NvViewTheme? centerLineView;

/*! \if ENGLISH
 *
 *  \brief Left and right handle picture
 *  \else
 *
 *  \brief 左右把手图片
 *  \endif
*/
  String? leftHandleImage;
  String? rightHandleImage;

/*! \if ENGLISH
 *
 *  \brief Time handle picture
 *  \else
 *
 *  \brief 时间把手图片
 *  \endif
*/
  String? timeHandleImage;

  // 构造函数
  NvEffectTrackViewTheme() : super();

// MARK: -- encode && decode
  @override
  jsonEncode() {
    Map<String, dynamic> jsonMap = super.jsonEncode();
    if (clipBorderColor != null) jsonMap['clipBorderColor'] = clipBorderColor;
    if (clipBorderWidth != null) jsonMap['clipBorderWidth'] = clipBorderWidth;
    if (centerLineView != null) {
      jsonMap['centerLineView'] = centerLineView!.jsonEncode();
    }
    if (leftHandleImage != null) jsonMap['leftHandleImage'] = leftHandleImage;
    if (rightHandleImage != null) {
      jsonMap['rightHandleImage'] = rightHandleImage;
    }
    if (timeHandleImage != null) jsonMap['timeHandleImage'] = timeHandleImage;
    return jsonMap;
  }
}
