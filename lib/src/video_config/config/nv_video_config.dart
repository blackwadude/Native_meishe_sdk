import 'nv_album_config.dart';
import 'nv_capture_config.dart';
import 'nv_edit_config.dart';
import 'nv_template_config.dart';
import 'nv_model_config.dart';
import 'nv_compile_config.dart';

/*! \if ENGLISH
 *
 *  \brief Project configuration item
 *  \else
 *
 *  \brief 工程配置项
 *  \endif
*/
class NvVideoConfig {
/*! \if ENGLISH
 *
 *  \brief primary Color
 *  \else
 *
 *  \brief 主色调
 *  \endif
*/
  String primaryColor = "#FC3E5A";

/*! \if ENGLISH
 *
 *  \brief backgroundColor
 *  \else
 *
 *  \brief 背景色
 *  \endif
*/
  String backgroundColor = "#000000";

/*! \if ENGLISH
 *
 *  \brief panel Color
 *  \else
 *
 *  \brief 面板色
 *  \endif
*/
  String panelBackgroundColor = "#1C1C1C";

/*! \if ENGLISH
 *
 *  \brief text Color
 *  \else
 *
 *  \brief 文字颜色
 *  \endif
*/
  String textColor = "#FFFFFF";

/*! \if ENGLISH
 *
 *  \brief secondary Text Color
 *  \else
 *
 *  \brief 二级文字颜色
 *  \endif
*/
  String secondaryTextColor = "#6C6C77";

/*! \if ENGLISH
 *
 *  \brief show the local music list
 *  \else
 *
 *  \brief 显示本地音乐列表
 *  \endif
*/
  bool enableLocalMusic = true;

/*! \if ENGLISH
 *
 *  \brief album
 *  \else
 *
 *  \brief 相册
 *  \endif
*/
  NvAlbumConfig albumConfig = NvAlbumConfig();

/*! \if ENGLISH
 *
 *  \brief Capture
 *  \else
 *
 *  \brief 拍摄
 *  \endif
*/
  NvCaptureConfig captureConfig = NvCaptureConfig();

/*! \if ENGLISH
 *
 *  \brief edit
 *  \else
 *
 *  \brief 编辑
 *  \endif
*/
  NvEditConfig editConfig = NvEditConfig();

/*! \if ENGLISH
 *
 *  \brief compile
 *  \else
 *
 *  \brief 合成
 *  \endif
*/
  NvCompileConfig compileConfig = NvCompileConfig();

/*! \if ENGLISH
 *
 *  \brief template
 *  \else
 *
 *  \brief 模版
 *  \endif
*/
  NvTemplateConfig templateConfig = NvTemplateConfig();

/*! \if ENGLISH
 *
 *  \brief Apply the required model file
 *  \else
 *  
 *  \brief 应用所需的模型文件
 *  \endif
*/
  NvModelConfig modelConfig = NvModelConfig();

// MARK: -- encode && decode

  jsonEncode() {
    Map<String, dynamic> jsonMap = {
      "primaryColor": primaryColor,
      "backgroundColor": backgroundColor,
      "panelBackgroundColor": panelBackgroundColor,
      "textColor": textColor,
      "secondaryTextColor": secondaryTextColor,
      "enableLocalMusic": enableLocalMusic,
      "albumConfig": albumConfig.jsonEncode(),
      "captureConfig": captureConfig.jsonEncode(),
      "editConfig": editConfig.jsonEncode(),
      "compileConfig": compileConfig.jsonEncode(),
      "templateConfig": templateConfig.jsonEncode(),
      "modelConfig": modelConfig.jsonEncode()
    };
    return jsonMap;
  }

  static NvVideoConfig jsonDecode(dynamic json) {
    NvVideoConfig config = NvVideoConfig();
    if (json['primaryColor'] != null) {
      config.primaryColor = json['primaryColor'];
    }
    if (json['backgroundColor'] != null) {
      config.backgroundColor = json['backgroundColor'];
    }
    if (json['panelBackgroundColor'] != null) {
      config.panelBackgroundColor = json['panelBackgroundColor'];
    }
    if (json['textColor'] != null) {
      config.textColor = json['textColor'];
    }
    if (json['secondaryTextColor'] != null) {
      config.secondaryTextColor = json['secondaryTextColor'];
    }
    if (json['enableLocalMusic'] != null) {
      config.enableLocalMusic = json['enableLocalMusic'];
    }
    if (json['albumConfig'] != null) {
      config.albumConfig = NvAlbumConfig.jsonDecode(json['albumConfig']);
    }
    if (json['captureConfig'] != null) {
      config.captureConfig = NvCaptureConfig.jsonDecode(json['captureConfig']);
    }
    if (json['editConfig'] != null) {
      config.editConfig = NvEditConfig.jsonDecode(json['editConfig']);
    }
    if (json['compileConfig'] != null) {
      config.compileConfig = NvCompileConfig.jsonDecode(json['compileConfig']);
    }
    if (json['templateConfig'] != null) {
      config.templateConfig =
          NvTemplateConfig.jsonDecode(json['templateConfig']);
    }
    if (json['modelConfig'] != null) {
      config.modelConfig = NvModelConfig.jsonDecode(json['modelConfig']);
    }
    return config;
  }
}
