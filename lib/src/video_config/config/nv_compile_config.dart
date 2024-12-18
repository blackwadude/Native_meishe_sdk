// ignore_for_file: constant_identifier_names

enum NvVideoPreviewResolution {
  NvVideoPreviewResolution_720,
  NvVideoPreviewResolution_1080,
}

enum NvVideoCompileResolution {
  NvVideoCompileResolution_720,
  NvVideoCompileResolution_1080,
  NvVideoCompileResolution_4K,
}

enum NvsCompileVideoBitrateGrade {
  NvsCompileBitrateGradeLow,
  NvsCompileBitrateGradeMedium,
  NvsCompileBitrateGradeHigh,
}

/*! \if ENGLISH
 *
 *  \brief Compile configuration item
 *  \else
 *
 *  \brief 导出配置项
 *  \endif
*/
class NvCompileConfig {
/*! \if ENGLISH
 *
 *  \brief Output video resolution
 *  Default 1080
 *  Refer to NvVideoCompileResolution
 *  \else
 *
 *  \brief 输出视频分辨率
 *  默认1080
 *  参考NvVideoCompileResolution
 *  \endif
*/
  NvVideoCompileResolution resolution =
      NvVideoCompileResolution.NvVideoCompileResolution_1080;

/*! \if ENGLISH
 *
 *  \brief Output video fps
 *  \else
 *
 *  \brief 输出视频fps
 *  \endif
*/
  int fps = 25;

/*! \if ENGLISH
 *
 *  \brief Output video bit rate
 *  Default NvsCompileBitrateGradeHigh
 *
 *  Refer to NvsCompileVideoBitrateGrade
 *  \else
 *
 *  \brief 输出视频码率
 *  默认NvsCompileBitrateGradeHigh
 *
 *  参考NvsCompileVideoBitrateGrade
 *  \endif
*/
  NvsCompileVideoBitrateGrade bitrateGrade =
      NvsCompileVideoBitrateGrade.NvsCompileBitrateGradeHigh;

/*! \if ENGLISH
 *
 *  \brief Output video bit rate
 *  For example, to set 3M bit rate, pass 3000000
 *  Default not set
 *  \else
 *
 *  \brief 输出视频码率
 *  比如要设置3M码率，则传3000000
 *  默认不设置
 *  \endif
*/
  int bitrate = -1;

/*! \if ENGLISH
 *
 *  \brief Whether to save the exported video to the album
 *  Default Save
 *  false==Don't save
 *  true==Save
 *  \else
 *
 *  \brief 导出视频是否保存到相册
 *  默认保存
 *  false==不保存
 *  true==保存
 *  \endif
*/
  bool autoSaveVideo = true;

// MARK: -- encode && decode

  jsonEncode() {
    Map<String, dynamic> jsonMap = {
      "resolution": resolution.index,
      "fps": fps,
      "bitrateGrade": bitrateGrade.index,
      "bitrate": bitrate,
      "autoSaveVideo": autoSaveVideo,
    };
    return jsonMap;
  }

  static NvCompileConfig jsonDecode(Map<String, dynamic> json) {
    NvCompileConfig config = NvCompileConfig();
    if (json["resolution"] != null) {
      config.resolution =
          NvVideoCompileResolution.values[json["resolution"] as int];
    }
    if (json["fps"] != null) {
      config.fps = json["fps"] as int;
    }
    if (json["bitrateGrade"] != null) {
      config.bitrateGrade =
          NvsCompileVideoBitrateGrade.values[json["bitrateGrade"] as int];
    }
    if (json["bitrate"] != null) {
      config.bitrate = json["bitrate"] as int;
    }
    if (json["autoSaveVideo"] != null) {
      config.autoSaveVideo = json["autoSaveVideo"] as bool;
    }
    return config;
  }
}
