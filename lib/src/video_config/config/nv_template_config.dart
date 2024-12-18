import '../theme/theme_element/nv_view_theme.dart';

/*! \if ENGLISH
 *
 *  \brief Template configuration
 *  \else
 *
 *  \brief 模版配置
 *  \endif
*/
class NvTemplateConfig {
/*! \if ENGLISH
 *
 *  \brief Custom UI collection
 *  \else
 *
 *  \brief 自定义UI合集
 *  \endif
*/
  Map<String, NvViewTheme>? customTheme;

/*! \if ENGLISH
 *
 *  \brief Adaptive template、autoCut Maximum number of optional fragments
 *  \else
 *
 *  \brief 自适应模版、一键成片最大可选片段数量
 *  \endif
*/
  int maxSelectCount = 50;

/*! \if ENGLISH
 *
 *  \brief Whether to include AutoCut
 *  \else
 *  
 *  \brief 是否有一键成片功能
 *  \endif
*/
  bool useAutoCut = true;

// MARK: -- encode && decode

  jsonEncode() {
    Map<String, Map>? customThemeMap;
    if (customTheme != null) {
      customThemeMap = {};
      customTheme?.forEach((key, value) {
        customThemeMap?.putIfAbsent(key, () => value.jsonEncode());
      });
    }
    Map<String, dynamic> jsonMap = {
      if (customThemeMap != null) 'customTheme': customThemeMap,
      'maxSelectCount': maxSelectCount,
      'useAutoCut': useAutoCut
    };
    return jsonMap;
  }

  static NvTemplateConfig jsonDecode(dynamic json) {
    NvTemplateConfig config = NvTemplateConfig();
    if (json['maxSelectCount'] != null) {
      config.maxSelectCount = json['maxSelectCount'] as int;
    }
    if (json['useAutoCut'] != null) {
      config.useAutoCut = json['useAutoCut'] == 1;
    }
    return config;
  }
}
