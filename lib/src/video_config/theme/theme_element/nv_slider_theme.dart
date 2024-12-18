import 'nv_view_theme.dart';

/*! \if ENGLISH
 *
 *  \brief SliderTheme Configuration item
 *  \else
 *
 *  \brief SliderTheme配置项
 *  \endif
*/
class NvSliderTheme extends NvViewTheme {
/*! \if ENGLISH
 *
 *  \brief undertone
 *  \else
 *
 *  \brief 底色
 *  \endif
*/
  String? minimumTrackTintColor;

/*! \if ENGLISH
 *
 *  \brief Effective interval color
 *  \else
 *
 *  \brief 有效区间颜色
 *  \endif
*/
  String? maximumTrackTintColor;

/*! \if ENGLISH
 *
 *  \brief Handle color
 *  \else
 *
 *  \brief 把手颜色
 *  \endif
*/
  String? thumbTintColor;

/*! \if ENGLISH
 *
 *  \brief Numeric text color
 *  \else
 *
 *  \brief 数值文本颜色
 *  \endif
*/
  String? valueTextColor;

/*! \if ENGLISH
 *
 *  \brief Second numeric text colorf'f'f
 *  \else
 *
 *  \brief 第二数值文本颜色
 *  \endif
*/
  String? valueSecondaryTextColor;

/*! \if ENGLISH
 *
 *  \brief Handle icon
 *  \else
 *
 *  \brief 把手图标
 *  \endif
*/
  String? thumbTintImage;

  // 构造函数
  NvSliderTheme() : super();

// MARK: -- encode && decode
  @override
  jsonEncode() {
    Map<String, dynamic> jsonMap = super.jsonEncode();
    if (minimumTrackTintColor != null)
      jsonMap['minimumTrackTintColor'] = minimumTrackTintColor;
    if (maximumTrackTintColor != null)
      jsonMap['maximumTrackTintColor'] = maximumTrackTintColor;
    if (thumbTintColor != null) jsonMap['thumbTintColor'] = thumbTintColor;
    if (valueTextColor != null) jsonMap['valueTextColor'] = valueTextColor;
    if (valueSecondaryTextColor != null)
      jsonMap['valueSecondaryTextColor'] = valueSecondaryTextColor;
    if (thumbTintImage != null) jsonMap['thumbTintImage'] = thumbTintImage;
    return jsonMap;
  }
}
