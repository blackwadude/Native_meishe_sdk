import 'package:flutter/foundation.dart';
import '../theme/theme_element/nv_view_theme.dart';
import 'nv_compile_config.dart';
import 'nv_beauty_config.dart';
import 'nv_dual_config.dart';

/*! \if ENGLISH
 *
 *  \brief Duration(in microseconds)
 *  \else
 *
 *  \brief 时长(单位毫秒)
 *  \endif
*/
class NvTimePair {
/*! \if ENGLISH
 *
 *  \brief min Duration(in microseconds)
 *  \else
 *
 *  \brief 最小时长(单位毫秒)
 *  \endif
*/
  final int minDuration;

/*! \if ENGLISH
 *
 *  \brief max Duration(in microseconds)
 *  \else
 *
 *  \brief 最大时长(单位毫秒)
 *  \endif
*/
  final int maxDuration;

  NvTimePair(this.minDuration, this.maxDuration);

  // MARK: -- encode && decode
  jsonEncode() {
    Map<String, dynamic> jsonMap = {
      'minDuration': minDuration,
      'maxDuration': maxDuration
    };
    return jsonMap;
  }

  static NvTimePair jsonDecode(Map<String, dynamic> json) {
    return NvTimePair(json['minDuration'].toInt(), json['maxDuration'].toInt());
  }
}

/*! \if ENGLISH
 *
 *  \brief Right-hand menu
 *  \else
 *
 *  \brief 右侧菜单
 *  \endif
*/
enum NvCaptureMenuItem {
  device, //!< \if ENGLISH Flip camera \else 翻转摄像头\endif
  speed, //!< \if ENGLISH Speed \else 快慢速\endif
  timer, //!< \if ENGLISH Countdown \else 倒计时 \endif
  beauty, //!< \if ENGLISH Beauty \else 美颜 \endif
  makeup, //!< \if ENGLISH Makeup \else 美妆 \endif
  prop, //!< \if ENGLISH Face prop \else 人脸道具 \endif
  flashlight, //!< \if ENGLISH Flashlight \else 闪光灯 \endif
  filter, //!< \if ENGLISH Filter \else 滤镜 \endif
  original, //!< \if ENGLISH Original sound \else 原声 \endif
  dualtype, //!< \if ENGLISH Dual type \else 合拍样式 \endif
}

/*! \if ENGLISH
 *
 *  \brief Bottom menu
 *  \else
 *
 *  \brief 底部菜单
 *  \endif
*/
enum NvCaptureBottomMenuItem {
  image, //!< \if ENGLISH Photo \else 拍照 \endif
  video, //!< \if ENGLISH Record \else 录制 \endif
  smart, //!< \if ENGLISH Smart record \else 快拍 \endif
  template, //!< \if ENGLISH Template \else 模版 \endif
}

/*! \if ENGLISH
 *
 *  \brief Shooting configuration
 *  \else
 *
 *  \brief 拍摄配置项
 *  \endif
*/
class NvCaptureConfig {
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
 *  \brief Shoot right menu (array ordered)
 *  Refer to NvCaptureMenuItem
 *  \else
 *
 *  \brief 拍摄右侧菜单 （数组有序）
 *  参考NvCaptureMenuItem
 *  \endif
*/
  List<NvCaptureMenuItem> captureMenuItems;

/*! \if ENGLISH
 *
 *  \brief Shoot the bottom menu (array ordered, templates placed last)
 *  Refer to NvCaptureBottomMenuItem
 *  \else
 *
 *  \brief 拍摄底部菜单 （数组有序，模版放最后）
 *  参考NvCaptureBottomMenuItem
 *  \endif
*/
  List<NvCaptureBottomMenuItem> captureBottomMenuItems;

/*! \if ENGLISH
 *
 *  \brief Default front camera
 *  0==Rear camera，1==Front camera
 *  \else
 *
 *  \brief 默认前置摄像头
 *  0==后置，1==前置
 *  \endif
*/
  int captureDeviceIndex;

/*! \if ENGLISH
 *
 *  \brief Shooting resolution
 *  Refer to NvVideoPreviewResolution
 *  \else
 *
 *  \brief 拍摄分辨率
 *  参考NvVideoPreviewResolution
 *  \endif
*/
  NvVideoPreviewResolution resolution;

/*! \if ENGLISH
 *
 *  \brief Ignore device rotation
 *  \else
 *
 *  \brief 忽略设备旋转
 *  \endif
*/
  bool ignoreVideoRotation;

/*! \if ENGLISH
 *
 *  \brief Photo duration Settings (milliseconds)
 *  \else
 *
 *  \brief 拍照时长设置（毫秒）
 *  \endif
*/
  int imageDuration;

/*! \if ENGLISH
 *
 *  \brief Taken photos, before entering editing, whether to save to album
 *  false==Don't save，true==save
 *  \else
 *
 *  \brief 拍摄的照片，进入编辑之前，是否保存到相册
 *  false==不保存，true==保存
 *  \endif
*/
  bool autoSavePhotograph;

/*! \if ENGLISH
 *
 *  \brief
 *  \else
 *
 *  \brief 录制时长设置
 *  参考NvTimePair
 *  \endif
*/
  List<NvTimePair> timeRanges;

/*! \if ENGLISH
 *
 *  \brief smart setting
 *  Refer to NvTimePair
 *  \else
 *
 *  \brief 快拍设置
 *  参考NvTimePair
 *  \endif
*/
  NvTimePair smartTimeRange;

/*! \if ENGLISH
 *
 *  \brief Beauty configuration item
 *  Refer to NvBeautyConfig
 *  \else
 *
 *  \brief 美颜配置项
 *  参考NvBeautyConfig
 *  \endif
*/
  NvBeautyConfig? beautyConfig;

/*! \if ENGLISH
 *
 *  \brief Click right menu (orderly)
 *  \else
 *
 *  \brief 合拍右侧菜单（有序）
 *  \endif
*/
  List<NvCaptureMenuItem> dualMenuItems;

/*! \if ENGLISH
 *
 *  \brief PIP setting
 *  Refer to NvDualConfig
 *  \else
 *
 *  \brief 合拍设置
 *  参考NvDualConfig
 *  \endif
*/
  NvDualConfig? dualConfig;

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
  double filterDefaultValue;

  /*! \if ENGLISH
 *
 *  \brief The Capture shows the album button
 *  \else
 *
 *  \brief 拍摄页显示相册按钮
 *  \endif
*/
  bool enableCaptureAlbum;

/*! \if ENGLISH
 *
 *  \brief Automatically disables the soundtrack
 *  \else
 *
 *  \brief 自动禁掉原声
 *  \endif
*/
  bool autoDisablesMic;

  NvCaptureConfig()
      : customTheme = null,
        resolution = NvVideoPreviewResolution.NvVideoPreviewResolution_1080,
        captureMenuItems = [
          NvCaptureMenuItem.device,
          NvCaptureMenuItem.speed,
          NvCaptureMenuItem.timer,
          NvCaptureMenuItem.beauty,
          NvCaptureMenuItem.makeup,
          NvCaptureMenuItem.prop,
          NvCaptureMenuItem.flashlight,
          NvCaptureMenuItem.filter,
          NvCaptureMenuItem.original
        ],
        dualMenuItems = [
          NvCaptureMenuItem.device,
          NvCaptureMenuItem.speed,
          NvCaptureMenuItem.timer,
          NvCaptureMenuItem.beauty,
          NvCaptureMenuItem.makeup,
          NvCaptureMenuItem.prop,
          NvCaptureMenuItem.flashlight,
          NvCaptureMenuItem.filter,
          NvCaptureMenuItem.original,
          NvCaptureMenuItem.dualtype
        ],
        captureBottomMenuItems = [
          NvCaptureBottomMenuItem.image,
          NvCaptureBottomMenuItem.video,
          NvCaptureBottomMenuItem.smart,
          NvCaptureBottomMenuItem.template
        ],
        timeRanges = [
          NvTimePair(3 * 1000, 15 * 1000),
          NvTimePair(3 * 1000, 60 * 1000)
        ],
        smartTimeRange = NvTimePair(3 * 1000, 15 * 1000),
        captureDeviceIndex = 1,
        ignoreVideoRotation = true,
        imageDuration = 3 * 1000,
        autoSavePhotograph = false,
        filterDefaultValue = 0.8,
        enableCaptureAlbum = false,
        autoDisablesMic = false;

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
      'captureMenuItems': captureMenuItems.map((e) => e.stringValue).toList(),
      'captureBottomMenuItems':
          captureBottomMenuItems.map((e) => e.stringValue).toList(),
      'captureDeviceIndex': captureDeviceIndex,
      'resolution': resolution.index,
      'ignoreVideoRotation': ignoreVideoRotation,
      'imageDuration': imageDuration,
      'autoSavePhotograph': autoSavePhotograph,
      'timeRanges': timeRanges.map((e) => e.jsonEncode()).toList(),
      'smartTimeRange': smartTimeRange.jsonEncode(),
      'dualMenuItems': dualMenuItems.map((e) => e.stringValue).toList(),
      if (beautyConfig != null) 'beautyConfig': beautyConfig!.jsonEncode(),
      if (dualConfig != null) 'dualConfig': dualConfig!.jsonEncode(),
      'filterDefaultValue': filterDefaultValue,
      'enableCaptureAlbum': enableCaptureAlbum,
      'autoDisablesMic': autoDisablesMic
    };
    return jsonMap;
  }

  static NvCaptureConfig jsonDecode(dynamic json) {
    NvCaptureConfig config = NvCaptureConfig();
    List<dynamic>? captureMenuStringItems =
        json['captureMenuItems'] as List<dynamic>?;
    if (captureMenuStringItems != null) {
      config.captureMenuItems = captureMenuStringItems
          .map((e) => NvCaptureMenuItemExtension.parse(e))
          .toList();
    }
    List<dynamic>? captureBottomMenuStringItems =
        json['captureBottomMenuItems'] as List<dynamic>?;
    if (captureBottomMenuStringItems != null) {
      config.captureBottomMenuItems = captureBottomMenuStringItems
          .map((e) => NvCaptureBottomMenuItemExtension.parse(e))
          .toList();
    }
    config.captureDeviceIndex = json['captureDeviceIndex'] != null
        ? json['captureDeviceIndex'] as int
        : 1;
    if (json['resolution'] != null) {
      config.resolution =
          NvVideoPreviewResolution.values[json['resolution'] as int];
    }
    config.ignoreVideoRotation = json['ignoreVideoRotation'] != null
        ? json['ignoreVideoRotation'] as bool
        : true;
    config.imageDuration =
        json['imageDuration'] != null ? json['imageDuration'] as int : 3 * 1000;
    if (json['autoSavePhotograph'] != null) {
      config.autoSavePhotograph = json['autoSavePhotograph'] == 1;
    }
    List<dynamic>? timeStringRanges = json['timeRanges'] as List<dynamic>?;
    if (timeStringRanges != null) {
      config.timeRanges =
          timeStringRanges.map((e) => NvTimePair.jsonDecode(e)).toList();
    }
    if (json['smartTimeRange'] != null) {
      config.smartTimeRange = NvTimePair.jsonDecode(json['smartTimeRange']);
    }
    List<dynamic>? dualMenuStringItems =
        json['dualMenuItems'] as List<dynamic>?;
    if (dualMenuStringItems != null) {
      config.dualMenuItems = dualMenuStringItems
          .map((e) => NvCaptureMenuItemExtension.parse(e))
          .toList();
    }
    if (json['beautyConfig'] != null) {
      config.beautyConfig = NvBeautyConfig.jsonDecode(json['beautyConfig']);
    }
    if (json['dualConfig'] != null) {
      config.dualConfig = NvDualConfig.jsonDecode(json['dualConfig']);
    }
    config.filterDefaultValue = json['filterDefaultValue'] != null
        ? json['filterDefaultValue'] as double
        : 0.8;
    if (json['enableCaptureAlbum'] != null) {
      config.enableCaptureAlbum = json['enableCaptureAlbum'] == 1;
    }
    if (json['autoDisablesMic'] != null) {
      config.autoDisablesMic = json['autoDisablesMic'] == 1;
    }
    return config;
  }
}

extension NvCaptureMenuItemExtension on NvCaptureMenuItem {
  static NvCaptureMenuItem parse(dynamic value) {
    try {
      return NvCaptureMenuItem.values.firstWhere((e) => e.stringValue == value);
    } on StateError {
      debugPrint('NvCaptureMenuItem parse error: $value');
      return NvCaptureMenuItem.device;
    }
  }

  String get stringValue {
    switch (this) {
      case NvCaptureMenuItem.device:
        return 'capture_menu_device';
      case NvCaptureMenuItem.speed:
        return 'capture_menu_speed';
      case NvCaptureMenuItem.timer:
        return 'capture_menu_timer';
      case NvCaptureMenuItem.beauty:
        return 'capture_menu_beauty';
      case NvCaptureMenuItem.makeup:
        return 'capture_menu_makeup';
      case NvCaptureMenuItem.prop:
        return 'capture_menu_prop';
      case NvCaptureMenuItem.flashlight:
        return 'capture_menu_flashlight';
      case NvCaptureMenuItem.filter:
        return 'capture_menu_filter';
      case NvCaptureMenuItem.original:
        return 'capture_menu_original';
      case NvCaptureMenuItem.dualtype:
        return 'capture_menu_dual_type';
    }
  }
}

extension NvCaptureBottomMenuItemExtension on NvCaptureBottomMenuItem {
  static NvCaptureBottomMenuItem parse(dynamic value) {
    try {
      return NvCaptureBottomMenuItem.values
          .firstWhere((e) => e.stringValue == value);
    } on StateError {
      debugPrint('NvCaptureBottomMenuItem parse error: $value');
      return NvCaptureBottomMenuItem.video;
    }
  }

  String get stringValue {
    switch (this) {
      case NvCaptureBottomMenuItem.image:
        return 'capture_bottom_menu_image';
      case NvCaptureBottomMenuItem.video:
        return 'capture_bottom_menu_video';
      case NvCaptureBottomMenuItem.smart:
        return 'capture_bottom_menu_smart';
      case NvCaptureBottomMenuItem.template:
        return 'capture_bottom_menu_template';
    }
  }
}
