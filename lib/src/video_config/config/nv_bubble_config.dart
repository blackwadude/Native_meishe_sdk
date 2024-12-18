import '../theme/theme_element/nv_label_theme.dart';

/*! \if ENGLISH
 *
 *  \brief Bubble background blur style
 *  \else
 *
 *  \brief 气泡背景模糊样式
 *  \endif
*/
enum NvBubbleBgBlurStyle {
  none, //!< \if ENGLISH None \else 无模糊 \endif
  light, //!< \if Light \else 白色模糊 \endif
  dark //!< \if Dark \else 黑色模糊 \endif
}

/*! \if ENGLISH
 *
 *  \brief Bubble configuration
 *  \else
 *
 *  \brief 气泡配置
 *  \endif
*/
class NvBubbleConfig {
/*! \if ENGLISH
 *
 *  \brief Edit icon
 *  \else
 *
 *  \brief 编辑图标
 *  \endif
*/
  String? editImageName;

/*! \if ENGLISH
 *
 *  \brief Duration icon
 *  \else
 *
 *  \brief 时长图标
 *  \endif
*/
  String? durationImageName;

/*! \if ENGLISH
 *
 *  \brief
 *  \else
 *
 *  \brief 文字样式
 *  \endif
*/
  NvLabelTheme? titleTheme;

/*! \if ENGLISH
 *
 *  \brief Text style
 *  \else
 *
 *  \brief 背景色（无模糊时的）
 *  \endif
*/
  String? backgroundColor;

/*! \if ENGLISH
 *
 *  \brief Background mode
 *  \else
 *
 *  \brief 背景模式
 *  \endif
*/
  NvBubbleBgBlurStyle backgroundBlurStyle = NvBubbleBgBlurStyle.dark;

  // MARK: -- encode && decode

  jsonEncode() {
    Map<String, dynamic> jsonMap = {};
    if (editImageName != null) jsonMap['editImageName'] = editImageName;
    if (durationImageName != null) {
      jsonMap['durationImageName'] = durationImageName;
    }
    if (titleTheme != null) jsonMap['titleTheme'] = titleTheme!.jsonEncode();
    if (backgroundColor != null) jsonMap['backgroundColor'] = backgroundColor;
    jsonMap['backgroundBlurStyle'] = backgroundBlurStyle.index;
    return jsonMap;
  }

  static NvBubbleConfig? jsonDecode(Map<String, dynamic> json) {
    Map<String, dynamic>? titleThemeDic =
        json['titleTheme'] as Map<String, dynamic>?;
    NvBubbleConfig config = NvBubbleConfig();
    config.editImageName = json['editImageName'] as String?;
    config.durationImageName = json['durationImageName'] as String?;
    config.titleTheme =
        titleThemeDic != null ? NvLabelTheme.jsonDecode(titleThemeDic) : null;
    config.backgroundColor = json['backgroundColor'] as String?;
    config.backgroundBlurStyle =
        NvBubbleBgBlurStyle.values[json['backgroundBlurStyle'] as int];
    return config;
  }
}
