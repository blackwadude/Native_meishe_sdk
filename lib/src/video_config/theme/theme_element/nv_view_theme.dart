/*! \if ENGLISH
 *
 *  \brief View Configuration item
 *  \else
 *
 *  \brief View配置项
 *  \endif
*/
class NvViewTheme {
/*! \if ENGLISH
 *
 *  \brief hidden
 *  \else
 *
 *  \brief 隐藏
 *  \endif
*/
  bool hidden = false;

/*! \if ENGLISH
 *
 *  \brief backgroundColor
 *  \else
 *
 *  \brief 背景色
 *  \endif
*/
  String? backgroundColor;

/*! \if ENGLISH
 *
 *  \brief tintColor
 *  \else
 *
 *  \brief tintColor
 *  \endif
*/
  String? tintColor;

/*! \if ENGLISH
 *
 *  \brief Stroke color
 *  \else
 *
 *  \brief 描边颜色
 *  \endif
*/
  String? borderColor;

/*! \if ENGLISH
 *
 *  \brief Stroke width
 *  \else
 *
 *  \brief 描边宽度
 *  \endif
*/
  num? borderWidth;

// MARK: -- encode && decode
  jsonEncode() {
    Map<String, dynamic> jsonMap = {"hidden": hidden};
    if (backgroundColor != null) jsonMap["backgroundColor"] = backgroundColor;
    if (tintColor != null) jsonMap["tintColor"] = tintColor;
    if (borderColor != null) jsonMap["borderColor"] = borderColor;
    if (borderWidth != null) jsonMap["borderWidth"] = borderWidth;
    return jsonMap;
  }
}
