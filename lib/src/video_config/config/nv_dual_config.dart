import 'package:flutter/foundation.dart';

enum NvDualType {
  leftRight,
  topDown,
  leftRect,
  leftCircle,
  topCircle,
}

/*! \if ENGLISH
 *
 *  \brief PIP Configuration item
 *  \else
 *
 *  \brief 合拍配置项
 *  \endif
*/
class NvDualConfig {
/*! \if ENGLISH
 *
 *  \brief The ratio of the small map to the left border and the width of the base map
 *  \else
 *
 *  \brief 小图距离 左边边界和底图宽度的比例
 *  \endif
*/
  double left = 17.0 / 375.0;

/*! \if ENGLISH
 *
 *  \brief The ratio of the small map to the height of the upper boundary and the bottom map
 *  \else
 *
 *  \brief 小图距离 上边边界和底图高度的比例
 *  \endif
*/
  double top = 18.0 / 666.67;

/*! \if ENGLISH
 *
 *  \brief The ratio between the width of the short edge and the width of the base
 *  \else
 *
 *  \brief 小图 短边和底图宽度的比例
 *  \endif
*/
  double limitWidth = 153.5 / 375.0;

/*! \if ENGLISH
 *
 *  \brief PIP with default style
 *  \else
 *
 *  \brief 合拍默认样式
 *  \endif
*/
  NvDualType defaultType = NvDualType.leftRight;

/*! \if ENGLISH
 *
 *  \brief Supported styles (in no order)
 *  \else
 *
 *  \brief 支持的样式（无序）
 *  \endif
*/
  List<NvDualType> supportedTypes;

  /*! \if ENGLISH
 *
 *  \brief Automatically disables the soundtrack
 *  \else
 *
 *  \brief 自动禁掉原声
 *  \endif
*/
  bool autoDisablesMic;

  /*! \if ENGLISH
 *
 *  \brief Acoustic silence
 *  \else
 *
 *  \brief 默认关掉原声
 *  \endif
*/
  bool muteOriginal = true;

  NvDualConfig()
      : supportedTypes = [
          NvDualType.leftRight,
          NvDualType.topDown,
          NvDualType.leftRect,
          NvDualType.leftCircle,
          NvDualType.topCircle
        ],
        autoDisablesMic = false;
        
// MARK: -- encode && decode

  jsonEncode() {
    Map<String, dynamic> jsonMap = {
      'left': left,
      'top': top,
      'limitWidth': limitWidth,
      'defaultType': defaultType.stringValue,
      'supportedTypes': supportedTypes.map((e) => e.stringValue).toList(),
      'autoDisablesMic': autoDisablesMic,
      'muteOriginal': muteOriginal,
    };
    return jsonMap;
  }

  static NvDualConfig jsonDecode(dynamic json) {
    NvDualConfig config = NvDualConfig();
    if (json['left'] != null) {
      config.left = json['left'];
    }
    if (json['top'] != null) {
      config.top = json['top'];
    }
    if (json['limitWidth'] != null) {
      config.limitWidth = json['limitWidth'];
    }
    if (json['defaultType'] != null) {
      config.defaultType = NvDualTypeExtension.parse(json['defaultType']);
    }
    if (json['supportedTypes'] != null) {
      config.supportedTypes = json['supportedTypes']
          .map((e) => NvDualTypeExtension.parse(e))
          .toList();
    }
    if (json['autoDisablesMic'] != null) {
      config.autoDisablesMic = json['autoDisablesMic'] == 1;
    }
    if (json['muteOriginal'] != null) {
      config.muteOriginal = json['muteOriginal'] == 1;
    }
    return config;
  }
}

// 扩展，用于将 NvDualType 枚举值转换为对应的字符串
extension NvDualTypeExtension on NvDualType {
  static NvDualType parse(dynamic value) {
    try {
      return NvDualType.values.firstWhere((e) => e.stringValue == value);
    } on StateError {
      debugPrint('NvDualType parse error: $value');
      return NvDualType.leftRight;
    }
  }

  String get stringValue {
    switch (this) {
      case NvDualType.leftRight:
        return 'left_right';
      case NvDualType.topDown:
        return 'top_down';
      case NvDualType.leftRect:
        return 'left_rect';
      case NvDualType.leftCircle:
        return 'left_circle';
      case NvDualType.topCircle:
        return 'top_circle';
    }
  }
}
