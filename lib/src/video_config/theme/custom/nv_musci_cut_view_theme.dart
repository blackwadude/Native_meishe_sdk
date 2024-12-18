import '../theme_element/nv_view_theme.dart';
import '../theme_element/nv_button_theme.dart';
import '../theme_element/nv_label_theme.dart';

/*! \if ENGLISH
 *
 *  \brief MusciCutViewTheme Configuration item
 *  \else
 *
 *  \brief MusciCutViewTheme配置项
 *  \endif
*/
class NvMusciCutViewTheme extends NvViewTheme {
/*! \if ENGLISH
 *
 *  \brief Time text font
 *  \else
 *
 *  \brief 时间文本 字体
 *  \endif
*/
  num? timeFontSize;

/*! \if ENGLISH
 *
 *  \brief Time text color
 *  \else
 *
 *  \brief 时间文本 颜色
 *  \endif
*/
  String? timeFontFamily;

/*! \if ENGLISH
 *
 *  \brief Time text second color
 *  \else
 *
 *  \brief 时间文本 第二颜色
 *  \endif
*/
  String? timeSecondaryTextColor;

/*! \if ENGLISH
 *
 *  \brief Left side line color
 *  \else
 *
 *  \brief 左侧线颜色
 *  \endif
*/
  String? leftLineColor;

/*! \if ENGLISH
 *
 *  \brief Waveform diagram base color
 *  \else
 *
 *  \brief 波形图底色
 *  \endif
*/
  String? waveColor;

/*! \if ENGLISH
 *
 *  \brief Wave diagram bright color
 *  \else
 *
 *  \brief 波形图亮色
 *  \endif
*/
  String? waveTintColor;

/*! \if ENGLISH
 *
 *  \brief Waveform background color
 *  \else
 *
 *  \brief 波形图背景色
 *  \endif
*/
  String? waveBackgroundColor;

/*! \if ENGLISH
 *
 *  \brief Right button icon
 *  \else
 *
 *  \brief 右侧按钮图标
 *  \endif
*/
  String? rightBtImage;

/*! \if ENGLISH
 *
 *  \brief Loop button style
 *  \else
 *
 *  \brief 循环按钮样式
 *  \endif
*/
  NvButtonTheme? loopBt;

/*! \if ENGLISH
 *
 *  \brief Prompt text style
 *  \else
 *
 *  \brief 提示文本样式
 *  \endif
*/
  NvLabelTheme? tipLabel;

  // 构造函数
  NvMusciCutViewTheme() : super();

// MARK: -- encode && decode
  @override
  jsonEncode() {
    Map<String, dynamic> jsonMap = super.jsonEncode();
    if (timeFontSize != null) jsonMap['timeFontSize'] = timeFontSize;
    if (timeFontFamily != null) jsonMap['timeFontFamily'] = timeFontFamily;
    if (timeSecondaryTextColor != null) {
      jsonMap['timeSecondaryTextColor'] = timeSecondaryTextColor;
    }
    if (leftLineColor != null) jsonMap['leftLineColor'] = leftLineColor;
    if (waveColor != null) jsonMap['waveColor'] = waveColor;
    if (waveTintColor != null) jsonMap['waveTintColor'] = waveTintColor;
    if (waveBackgroundColor != null) {
      jsonMap['waveBackgroundColor'] = waveBackgroundColor;
    }
    if (rightBtImage != null) jsonMap['rightBtImage'] = rightBtImage;
    if (loopBt != null) jsonMap['loopBt'] = loopBt?.jsonEncode();
    if (tipLabel != null) jsonMap['tipLabel'] = tipLabel?.jsonEncode();
    return jsonMap;
  }
}
