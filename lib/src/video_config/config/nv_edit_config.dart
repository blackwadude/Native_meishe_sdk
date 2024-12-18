// ignore_for_file: constant_identifier_names
import 'package:flutter/foundation.dart';
import 'nv_bubble_config.dart';
import 'nv_compile_config.dart';
import '../theme/theme_element/nv_view_theme.dart';

/*! \if ENGLISH
 *
 *  \brief Right-hand menu
 *  \else
 *
 *  \brief 右侧菜单
 *  \endif
*/
enum NvEditMenuItem {
  release, //!< \if ENGLISH Release \else 发布 \endif
  download, //!< \if ENGLISH Save \else 保存 \endif
  edit, //!< \if ENGLISH Edit \else 裁剪 \endif
  text, //!< \if ENGLISH Text \else 文字 \endif
  sticker, //!< \if ENGLISH Sticker \else 贴纸 \endif
  effect, //!< \if ENGLISH Effect \else 特效 \endif
  filter, //!< \if ENGLISH Filter \else 滤镜 \endif
  caption, //!< \if ENGLISH Caption \else 自动字幕 \endif
  audio, //!< \if ENGLISH Audio \else 音效 \endif
  record //!< \if ENGLISH Record \else 录音 \endif
}

enum NvEditMode {
  NvEditMode9v16,
  NvEditMode16v9,
  NvEditMode3v4,
  NvEditMode4v3,
  NvEditMode1v1,
  NvEditMode18v9,
  NvEditMode9v18,
  NvEditMode8v9,
  NvEditMode9v8
}

/*! \if ENGLISH
 *
 *  \brief Frame scale calculation method
 *  \else
 *
 *  \brief 编辑画幅比例计算方式
 *  \endif
*/
enum NvEditModeSource {
  fixed, //!< \if ENGLISH Fixed \else 画幅比例固定 \endif
  firstAsset //!< \if ENGLISH The scale is determined by the first material \else 画幅比例由第一个素材确定 \endif
}

/*! \if ENGLISH
 *
 *  \brief caption style
 *  \else
 *
 *  \brief 字幕样式
 *  \endif
*/
enum NvImageCaptionStyle {
  none, //!< \if ENGLISH None \else 无 \endif
  bg, //!< \if ENGLISH Text background \else 文字背景 \endif
  bgAlpha, //!< \if ENGLISH Text background with transparency \else 文字背景带透明度 \endif
  outline //!< \if ENGLISH Text stroke \else 文字描边 \endif
}

/*! \if ENGLISH
 *
 *  \brief Edit configuration
 *  \else
 *
 *  \brief 编辑配置
 *  \endif
*/
class NvEditConfig {
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
 *  \brief Right side menu (orderly)
 *  \else
 *
 *  \brief 右侧菜单 （有序）
 *  \endif
*/
  List<NvEditMenuItem> editMenuItems;

/*! \if ENGLISH
 *
 *  \brief Edit preview resolution
 *  Refer to NvVideoPreviewResolution
 *  \else
 *
 *  \brief 编辑预览分辨率
 *  参考NvVideoPreviewResolution
 *  \endif
*/
  NvVideoPreviewResolution resolution =
      NvVideoPreviewResolution.NvVideoPreviewResolution_1080;

/*! \if ENGLISH
 *
 *  \brief Preview fps
 *  Default 25
 *  \else
 *
 *  \brief 预览fps
 *  默认25
 *  \endif
*/
  num fps = 25;

/*! \if ENGLISH
 *
 *  \brief Minimum effect duration (milliseconds)
 *  Default 500ms
 *  \else
 *
 *  \brief 最小特效时长（毫秒）
 *  默认500ms
 *  \endif
*/
  num minEffectDuration = 500;

/*! \if ENGLISH
 *
 *  \brief Minimum recording duration (ms)
 *  Default1000ms
 *  \else
 *
 *  \brief 最小录音时长（毫秒）
 *  默认1000ms
 *  \endif
*/
  num minAudioDuration = 1000;

/*! \if ENGLISH
 *
 *  \brief Default title color
 *  Default white
 *  \else
 *
 *  \brief 默认字幕颜色
 *  默认白色
 *  \endif
*/
  String captionColor = "#FFFFFF";

/*! \if ENGLISH
 *
 *  \brief Caption color list (ordered)
 *  \else
 *
 *  \brief 字幕颜色列表（有序）
 *  \endif
*/
  List<String> captionColorList;

/*! \if ENGLISH
 *
 *  \brief Supported title styles (out of order)
 *  \else
 *
 *  \brief 支持的字幕样式（无序）
 *  \endif
*/
  List<NvImageCaptionStyle> supportedCaptionStyles;

/*! \if ENGLISH
 *
 *  \brief Scale mode
 *  Refer to NvEditModeSource
 *  \else
 *
 *  \brief 画幅比例模式
 *  参考NvEditModeSource
 *  \endif
*/
  NvEditModeSource editModeSource = NvEditModeSource.firstAsset;

/*! \if ENGLISH
 *
 *  \brief Fixed frame scale
 *  \else
 *
 *  \brief 固定画幅比例
 *  \endif
*/
  NvEditMode editMode = NvEditMode.NvEditMode9v16;

/*! \if ENGLISH
 *
 *  \brief Supported frame ratio
 *  Refer to NvEditMode
 *  \else
 *
 *  \brief 支持的画幅比例
 *  参考NvEditMode
 *  \endif
*/
  List<NvEditMode> supportedEditModes;

/*! \if ENGLISH
 *
 *  \brief Bubble configuration
 *  \else
 *
 *  \brief 气泡配置
 *  \endif
*/
  NvBubbleConfig? bubbleConfig;

/*! \if ENGLISH
 *
 *  \brief Filter default value
 *  Default 0.8
 *  \else
 *
 *  \brief 滤镜默认值
 *  默认0.8
 *  \endif
*/
  num filterDefaultValue = 0.8;

/*! \if ENGLISH
 *
 *  \brief Maximum volume, [0-8]
 *  Default 4
 *  \else
 *
 *  \brief 最大音量， [0-8]
 *  默认 4
 *  \endif
*/
  num maxVolume = 4.0;

/*! \if ENGLISH
 *
 *  \brief disable time effect
 *  \else
 *
 *  \brief 禁用时间特效 (反复、慢动作)
 *  \endif
*/
  bool disableTimeEffect = false;

// MARK: -- encode && decode

  NvEditConfig()
      : captionColorList = [
          "#FFFFFF",
          "#000000",
          "#0099F6",
          "#50C23B",
          "#FFC840",
          "#FF8500",
          "#FF3350",
          "#E40069",
          "#B200C0",
          "#F8808A",
          "#FEBF7C",
          "#262626",
          "#363636",
          "#555555",
          "#737373",
          "#989898",
          "#B2B2B2",
          "#C7C7C7",
          "#DBDBDB",
          "#F0F0F0"
        ],
        editMenuItems = [
          NvEditMenuItem.release,
          NvEditMenuItem.download,
          NvEditMenuItem.edit,
          NvEditMenuItem.text,
          NvEditMenuItem.sticker,
          NvEditMenuItem.effect,
          NvEditMenuItem.filter,
          NvEditMenuItem.caption,
          NvEditMenuItem.audio,
          NvEditMenuItem.record
        ],
        supportedCaptionStyles = [
          NvImageCaptionStyle.none,
          NvImageCaptionStyle.bg,
          NvImageCaptionStyle.bgAlpha,
          NvImageCaptionStyle.outline
        ],
        supportedEditModes = [
          NvEditMode.NvEditMode9v16,
          NvEditMode.NvEditMode16v9,
          NvEditMode.NvEditMode3v4,
          NvEditMode.NvEditMode4v3,
          NvEditMode.NvEditMode1v1,
          NvEditMode.NvEditMode18v9,
          NvEditMode.NvEditMode9v18,
          NvEditMode.NvEditMode8v9,
          NvEditMode.NvEditMode9v8
        ];

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
      'editMenuItems': editMenuItems.map((e) => e.stringValue).toList(),
      'resolution': resolution.index,
      'fps': fps,
      'minEffectDuration': minEffectDuration,
      'minAudioDuration': minAudioDuration,
      'captionColor': captionColor,
      'captionColorList': captionColorList,
      'supportedCaptionStyles':
          supportedCaptionStyles.map((e) => e.stringValue).toList(),
      'editMode': editMode.stringValue,
      'editModeSource': editModeSource.index,
      'supportedEditModes':
          supportedEditModes.map((e) => e.stringValue).toList(),
      if (bubbleConfig != null) 'bubbleConfig': bubbleConfig!.jsonEncode(),
      'filterDefaultValue': filterDefaultValue,
      'maxVolume': maxVolume,
      'disableTimeEffect': disableTimeEffect
    };
    return jsonMap;
  }

  static NvEditConfig jsonDecode(dynamic json) {
    NvEditConfig config = NvEditConfig();
    config.customTheme = null;
    List<dynamic>? editMenuStringItems =
        json['editMenuItems'] as List<dynamic>?;
    if (editMenuStringItems != null) {
      config.editMenuItems = editMenuStringItems
          .map((e) => NvEditMenuItemExtension.parse(e))
          .toList();
    }
    if (json['resolution'] != null) {
      config.resolution =
          NvVideoPreviewResolution.values[json['resolution'] as int];
    }
    if (json['fps'] != null) {
      config.fps = json['fps'] as num;
    }
    if (json['minEffectDuration'] != null) {
      config.minEffectDuration = json['minEffectDuration'] as num;
    }
    if (json['minAudioDuration'] != null) {
      config.minAudioDuration = json['minAudioDuration'] as num;
    }
    if (json['captionColor'] != null) {
      config.captionColor = json['captionColor'] as String;
    }
    List<dynamic>? captionColorStringList =
        json['captionColorList'] as List<dynamic>?;
    if (captionColorStringList != null) {
      config.captionColorList =
          captionColorStringList.whereType<String>().toList();
    }
    List<dynamic>? supportedCaptionStringStyles =
        json['supportedCaptionStyles'] as List<dynamic>?;
    if (supportedCaptionStringStyles != null) {
      config.supportedCaptionStyles = supportedCaptionStringStyles
          .map((e) => NvImageCaptionStyleExtension.parse(e))
          .toList();
    }
    if (json['editMode'] != null) {
      config.editMode = NvEditModeExtension.parse(json['editMode']);
    }
    if (json['editModeSource'] != null) {
      config.editModeSource =
          NvEditModeSource.values[json['editModeSource'] as int];
    }
    List<dynamic>? supportedEditStringModes =
        json['supportedEditModes'] as List<dynamic>?;
    if (supportedEditStringModes != null) {
      config.supportedEditModes = supportedEditStringModes
          .map((e) => NvEditModeExtension.parse(e))
          .toList();
    }
    if (json['bubbleConfig'] != null) {
      config.bubbleConfig = NvBubbleConfig.jsonDecode(json['bubbleConfig']);
    }
    if (json['filterDefaultValue'] != null) {
      config.filterDefaultValue = json['filterDefaultValue'] as num;
    }
    if (json['maxVolume'] != null) {
      config.maxVolume = json['maxVolume'] as num;
    }
    if (json['disableTimeEffect'] != null) {
      config.disableTimeEffect = json['disableTimeEffect'] as bool;
    }
    return config;
  }
}

extension NvEditMenuItemExtension on NvEditMenuItem {
  static NvEditMenuItem parse(dynamic value) {
    try {
      return NvEditMenuItem.values.firstWhere((e) => e.stringValue == value);
    } on StateError {
      debugPrint('NvEditMenuItem parse error: $value');
      return NvEditMenuItem.release;
    }
  }

  String get stringValue {
    switch (this) {
      case NvEditMenuItem.release:
        return 'edit_menu_release';
      case NvEditMenuItem.download:
        return 'edit_menu_download';
      case NvEditMenuItem.edit:
        return 'edit_menu_edit';
      case NvEditMenuItem.text:
        return 'edit_menu_text';
      case NvEditMenuItem.sticker:
        return 'edit_menu_sticker';
      case NvEditMenuItem.effect:
        return 'edit_menu_effect';
      case NvEditMenuItem.filter:
        return 'edit_menu_filter';
      case NvEditMenuItem.caption:
        return 'edit_menu_caption';
      case NvEditMenuItem.audio:
        return 'edit_menu_audio';
      case NvEditMenuItem.record:
        return 'edit_menu_record';
    }
  }
}

extension NvEditModeExtension on NvEditMode {
  static NvEditMode parse(dynamic value) {
    try {
      return NvEditMode.values.firstWhere((e) => e.stringValue == value);
    } on StateError {
      debugPrint('NvEditMode parse error: $value');
      return NvEditMode.NvEditMode9v16;
    }
  }

  String get stringValue {
    switch (this) {
      case NvEditMode.NvEditMode9v16:
        return '9v16';
      case NvEditMode.NvEditMode16v9:
        return '16v9';
      case NvEditMode.NvEditMode3v4:
        return '3v4';
      case NvEditMode.NvEditMode4v3:
        return '4v3';
      case NvEditMode.NvEditMode1v1:
        return '1v1';
      case NvEditMode.NvEditMode18v9:
        return '18v9';
      case NvEditMode.NvEditMode9v18:
        return '9v18';
      case NvEditMode.NvEditMode8v9:
        return '8v9';
      case NvEditMode.NvEditMode9v8:
        return '9v8';
    }
  }
}

extension NvImageCaptionStyleExtension on NvImageCaptionStyle {
  static NvImageCaptionStyle parse(dynamic value) {
    try {
      return NvImageCaptionStyle.values
          .firstWhere((e) => e.stringValue == value);
    } on StateError {
      debugPrint('NvImageCaptionStyle parse error: $value');
      return NvImageCaptionStyle.none;
    }
  }

  String get stringValue {
    switch (this) {
      case NvImageCaptionStyle.none:
        return 'none';
      case NvImageCaptionStyle.bg:
        return 'bg';
      case NvImageCaptionStyle.bgAlpha:
        return 'bgAlpha';
      case NvImageCaptionStyle.outline:
        return 'outline';
    }
  }
}
