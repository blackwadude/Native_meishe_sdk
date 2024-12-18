import '../theme/theme_element/nv_view_theme.dart';

/*! \if ENGLISH
 *
 *  \brief Album configuration
 *  \else
 *
 *  \brief 相册配置
 *  \endif
*/
class NvAlbumConfig {
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
 *  \brief Album top TAB, All==0, Video==1, Pictures==2
 *  \else
 *
 *  \brief 相册顶部标签，全部==0、视频==1、图片==2
 *  \endif
*/
  int type = 0;

/*! \if ENGLISH
 *
 *  \brief The maximum number of materials for an album
 *  \else
 *
 *  \brief 相册可选最大素材数
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

  // 构造函数
  NvAlbumConfig({
    this.customTheme,
    this.type = 0,
    this.maxSelectCount = 50,
    this.useAutoCut = true,
  });

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
      'type': type,
      'maxSelectCount': maxSelectCount,
      'useAutoCut': useAutoCut,
      if (customThemeMap != null) 'customTheme': customThemeMap
    };
    return jsonMap;
  }

  static NvAlbumConfig jsonDecode(Map<String, dynamic> json) {
    NvAlbumConfig config = NvAlbumConfig();
    if (json.containsKey('type')) config.type = json['type'];
    if (json.containsKey('maxSelectCount')) {
      config.maxSelectCount = json['maxSelectCount'];
    }
    if (json.containsKey('useAutoCut')) {
      config.useAutoCut = json['useAutoCut'] == 1;
    }
    return config;
  }
}
