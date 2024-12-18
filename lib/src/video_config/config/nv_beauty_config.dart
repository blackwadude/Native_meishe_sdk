// ignore_for_file: constant_identifier_names

import 'package:flutter/foundation.dart';

/*! \if ENGLISH
 *  \brief Beauty classification
 *  \else
 *  \brief 美颜分类
 *  \endif
*/
enum NvBeautyCategorical { Skin, Shape, MicroShape, Adjust }

/*! \if ENGLISH
 *  \brief Beauty Adjustment item
 *  \else
 *  \brief 美肤调节项
 *  \endif
*/
enum NvBeautyEffect {
  Standard,
  Shiny,
  Natural,
  Luxurious,
  CoolWhite,
  PinkyWhite,
  WarmWhite,
  Tanning,
  WhiteA,
  WhiteB,
  Oiliness,
  Rosy
}

/*! \if ENGLISH
 *  \brief Shape Adjustment item
 *  \else
 *  \brief 美型调节项
 *  \endif
*/
enum NvBeautyShape {
  Narrow,
  LowerJaw,
  Lessen,
  Forehead,
  Chin,
  EyesSize,
  EyesConer,
  NoseAla,
  NoseLength,
  LipHeight,
  LipWidth
}

/*! \if ENGLISH
 *  \brief MicroShape Adjustment item
 *  \else
 *  \brief 微整形调节项
 *  \endif
*/
enum NvBeautyMicroShape {
  Head,
  EyesBrighten,
  NasolabialFolds,
  BlackCircle,
  WhitenTeeth,
  CheekBones,
  ChinLength,
  Temple,
  EyesConer,
  EyesDistance,
  Philtrum,
  NoseRoot,
  EyebrowSize,
  EyebrowHeight,
  EyebrowDistance,
  EyebrowSlant,
  LowerEyelid,
  EyesLength,
  EyesEnlarge,
  EyesHeight,
  NoseTip
}

/*! \if ENGLISH
 *  \brief Adjust Functional  Adjustment item
 *  \else
 *  \brief 调节功能调节项
 *  \endif
*/
enum NvBeautyAdjust { Tone, Firm, Articulation }

/*! \if ENGLISH
 *
 *  \brief Beauty config
 *  \else
 *
 *  \brief 美颜配置项
 *  \endif
*/
class NvBeautyConfig {
/*! \if ENGLISH
 *
 *  \brief Beauty functional
 *  Refer to NvBeautyCategorical
 *  \else
 *
 *  \brief 美颜功能
 *  参考NvBeautyCategorical
 *  \endif
*/
  List<NvBeautyCategorical>? categoricalArray;

/*! \if ENGLISH
 *
 *  \brief Beauty functional
 *  Refer to NvBeautyEffect
 *  \else
 *
 *  \brief 美肤功能
 *  参考NvBeautyEffect
 *  \endif
*/
  List<NvBeautyEffect>? beautyEffectArray;
/*! \if ENGLISH
 *
 *  \brief Shape functional
 *  Refer to NvBeautyShape
 *  \else
 *
 *  \brief 美型功能
 *  参考NvBeautyShape
 *  \endif
*/
  List<NvBeautyShape>? beautyShapeArray;

/*! \if ENGLISH
 *
 *  \brief MicroShape functional
 *  Refer to NvBeautyMicroShape
 *  \else
 *
 *  \brief 微整形功能
 *  参考NvBeautyMicroShape
 *  \endif
*/
  List<NvBeautyMicroShape>? beautyMicroShapeArray;

/*! \if ENGLISH
 *
 *  \brief Adjust functional
 *  Refer to NvBeautyAdjust
 *  \else
 *
 *  \brief 调节功能
 *  参考NvBeautyAdjust
 *  \endif
*/
  List<NvBeautyAdjust>? beautyAdjustArray;

// MARK: -- encode && decode
  jsonEncode() {
    Map<String, dynamic> jsonMap = {};
    if (categoricalArray != null) {
      List<String> categoricalStringArray = [];
      categoricalArray?.forEach((element) {
        categoricalStringArray.add(element.stringValue);
      });
      jsonMap['categoricalArray'] = categoricalStringArray;
    }
    if (beautyEffectArray != null) {
      List<String> beautyEffectStringArray = [];
      beautyEffectArray?.forEach((element) {
        beautyEffectStringArray.add(element.stringValue);
      });
      jsonMap['beautyEffectArray'] = beautyEffectStringArray;
    }
    if (beautyShapeArray != null) {
      List<String> beautyShapeStringArray = [];
      beautyShapeArray?.forEach((element) {
        beautyShapeStringArray.add(element.stringValue);
      });
      jsonMap['beautyShapeArray'] = beautyShapeStringArray;
    }
    if (beautyMicroShapeArray != null) {
      List<String> beautyMicroShapeStringArray = [];
      beautyMicroShapeArray?.forEach((element) {
        beautyMicroShapeStringArray.add(element.stringValue);
      });
      jsonMap['beautyMicroShapeArray'] = beautyMicroShapeStringArray;
    }
    if (beautyAdjustArray != null) {
      List<String> beautyAdjustStringArray = [];
      beautyAdjustArray?.forEach((element) {
        beautyAdjustStringArray.add(element.stringValue);
        jsonMap['beautyAdjustArray'] = beautyAdjustStringArray;
      });
      jsonMap['beautyAdjustArray'] = beautyAdjustStringArray;
    }
    return jsonMap;
  }

  static NvBeautyConfig jsonDecode(dynamic json) {
    NvBeautyConfig config = NvBeautyConfig();
    List<dynamic>? categoricalStringArray =
        json['categoricalArray'] as List<dynamic>?;
    if (categoricalStringArray != null) {
      config.categoricalArray = categoricalStringArray
          .map((e) => NvBeautyCategoricalExtension.parse(e))
          .toList();
    }
    List<dynamic>? beautyEffectStringArray =
        json['beautyEffectArray'] as List<dynamic>?;
    if (beautyEffectStringArray != null) {
      config.beautyEffectArray = beautyEffectStringArray
          .map((e) => NvBeautyEffectExtension.parse(e))
          .toList();
    }
    List<dynamic>? beautyShapeStringArray =
        json['beautyShapeArray'] as List<dynamic>?;
    if (beautyShapeStringArray != null) {
      config.beautyShapeArray = beautyShapeStringArray
          .map((e) => NvBeautyShapeExtension.parse(e))
          .toList();
    }
    List<dynamic>? beautyMicroShapeStringArray =
        json['beautyMicroShapeArray'] as List<dynamic>?;
    if (beautyMicroShapeStringArray != null) {
      config.beautyMicroShapeArray = beautyMicroShapeStringArray
          .map((e) => NvBeautyMicroShapeExtension.parse(e))
          .toList();
    }
    List<dynamic>? beautyAdjustStringArray =
        json['beautyAdjustArray'] as List<dynamic>?;
    if (beautyAdjustStringArray != null) {
      config.beautyAdjustArray = beautyAdjustStringArray
          .map((e) => NvBeautyAdjustExtension.parse(e))
          .toList();
    }
    return config;
  }
}

extension NvBeautyCategoricalExtension on NvBeautyCategorical {
  static NvBeautyCategorical parse(dynamic value) {
    try {
      return NvBeautyCategorical.values
          .firstWhere((e) => e.stringValue == value);
    } on StateError {
      debugPrint('NvBeautyCategorical parse error: $value');
      return NvBeautyCategorical.Skin;
    }
  }

  String get stringValue {
    switch (this) {
      case NvBeautyCategorical.Skin:
        return 'NvBeauty';
      case NvBeautyCategorical.Shape:
        return 'Shape';
      case NvBeautyCategorical.MicroShape:
        return 'MicroShape';
      case NvBeautyCategorical.Adjust:
        return 'Adjust';
    }
  }
}

extension NvBeautyEffectExtension on NvBeautyEffect {
  static NvBeautyEffect parse(dynamic value) {
    try {
      return NvBeautyEffect.values.firstWhere((e) => e.stringValue == value);
    } on StateError {
      debugPrint('NvBeautyEffect parse error: $value');
      return NvBeautyEffect.Standard;
    }
  }

  String get stringValue {
    switch (this) {
      case NvBeautyEffect.Standard:
        return 'Standard';
      case NvBeautyEffect.Shiny:
        return 'Shiny';
      case NvBeautyEffect.Natural:
        return 'Natural';
      case NvBeautyEffect.Luxurious:
        return 'Luxurious';
      case NvBeautyEffect.CoolWhite:
        return 'CoolWhite';
      case NvBeautyEffect.PinkyWhite:
        return 'PinkyWhite';
      case NvBeautyEffect.WarmWhite:
        return 'WarmWhite';
      case NvBeautyEffect.Tanning:
        return 'Tanning';
      case NvBeautyEffect.WhiteA:
        return 'WhiteA';
      case NvBeautyEffect.WhiteB:
        return 'WhiteB';
      case NvBeautyEffect.Oiliness:
        return 'Oiliness';
      case NvBeautyEffect.Rosy:
        return 'Rosy';
    }
  }
}

extension NvBeautyShapeExtension on NvBeautyShape {
  static NvBeautyShape parse(dynamic value) {
    try {
      return NvBeautyShape.values.firstWhere((e) => e.stringValue == value);
    } on StateError {
      debugPrint('NvBeautyShape parse error: $value');
      return NvBeautyShape.Narrow;
    }
  }

  String get stringValue {
    // 创建一个映射来关联枚举值和它们的字符串表示
    final map = <NvBeautyShape, String>{
      NvBeautyShape.Narrow: 'Narrow',
      NvBeautyShape.LowerJaw: 'Lower_Jaw',
      NvBeautyShape.Lessen: 'Lessen',
      NvBeautyShape.Forehead: 'Forehead',
      NvBeautyShape.Chin: 'Chin',
      NvBeautyShape.EyesSize: 'Eyes_Size',
      NvBeautyShape.EyesConer: 'Eyes_Coner',
      NvBeautyShape.NoseAla: 'Nose_Ala',
      NvBeautyShape.NoseLength: 'Nose_Length',
      NvBeautyShape.LipHeight: 'Lip_Height',
      NvBeautyShape.LipWidth: 'Lip_Width'
    };

    // 返回与当前枚举值对应的字符串
    return map[this] ?? toString(); // 如果映射中不存在当前枚举值，则使用枚举值的默认字符串表示
  }
}

extension NvBeautyMicroShapeExtension on NvBeautyMicroShape {
  static NvBeautyMicroShape parse(dynamic value) {
    try {
      return NvBeautyMicroShape.values
          .firstWhere((e) => e.stringValue == value);
    } on StateError {
      debugPrint('NvBeautyMicroShape parse error: $value');
      return NvBeautyMicroShape.Head;
    }
  }

  String get stringValue {
    // 创建一个映射来关联枚举值和它们的字符串表示
    final map = <NvBeautyMicroShape, String>{
      NvBeautyMicroShape.Head: 'Head',
      NvBeautyMicroShape.EyesBrighten: 'Eyes_Brighten',
      NvBeautyMicroShape.NasolabialFolds: 'Nasolabial_Folds',
      NvBeautyMicroShape.BlackCircle: 'Black_Circle',
      NvBeautyMicroShape.WhitenTeeth: 'Whiten_Teeth',
      NvBeautyMicroShape.CheekBones: 'Cheek_bones',
      NvBeautyMicroShape.ChinLength: 'Chin_Length',
      NvBeautyMicroShape.Temple: 'Temple',
      NvBeautyMicroShape.EyesConer: 'Eyes_Coner',
      NvBeautyMicroShape.EyesDistance: 'Eyes_Distance',
      NvBeautyMicroShape.Philtrum: 'Philtrum',
      NvBeautyMicroShape.NoseRoot: 'Nose_Root',
      NvBeautyMicroShape.EyebrowSize: 'Eyebrow_Size',
      NvBeautyMicroShape.EyebrowHeight: 'Eyebrow_Height',
      NvBeautyMicroShape.EyebrowDistance: 'Eyebrow_Distance',
      NvBeautyMicroShape.EyebrowSlant: 'Eyebrow_Slant',
      NvBeautyMicroShape.LowerEyelid: 'Lower_Eyelid',
      NvBeautyMicroShape.EyesLength: 'Eyes_Length',
      NvBeautyMicroShape.EyesEnlarge: 'Eyes_Enlarge',
      NvBeautyMicroShape.EyesHeight: 'Eyes_Height',
      NvBeautyMicroShape.NoseTip: 'Nose_Tip'
    };

    // 返回与当前枚举值对应的字符串
    return map[this] ?? toString(); // 如果映射中不存在当前枚举值，则使用枚举值的默认字符串表示
  }
}

extension NvBeautyAdjustExtension on NvBeautyAdjust {
  static NvBeautyAdjust parse(dynamic value) {
    try {
      return NvBeautyAdjust.values.firstWhere((e) => e.stringValue == value);
    } on StateError {
      debugPrint('NvBeautyAdjust parse error: $value');
      return NvBeautyAdjust.Tone;
    }
  }

  String get stringValue {
    // 创建一个映射来关联枚举值和它们的字符串表示
    final map = <NvBeautyAdjust, String>{
      NvBeautyAdjust.Tone: 'Tone',
      NvBeautyAdjust.Firm: 'Firm',
      NvBeautyAdjust.Articulation: 'Articulation'
    };

    // 返回与当前枚举值对应的字符串
    return map[this] ?? toString(); // 如果映射中不存在当前枚举值，则使用枚举值的默认字符串表示
  }
}
