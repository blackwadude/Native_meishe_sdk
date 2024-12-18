import '../theme_element/nv_view_theme.dart';

/*! \if ENGLISH
 *
 *  \brief Capture record button theme
 *  \else
 *
 *  \brief 拍摄按钮主题
 *  \endif
*/
class NvRecordBtTheme extends NvViewTheme {
/*! \if ENGLISH
 *
 *  \brief Capture record button color
 *  \else
 *
 *  \brief 拍摄按钮颜色
 *  \endif
*/
  String? normalColor;

/*! \if ENGLISH
 *
 *  \brief Capture record button  progress bar color
 *  \else
 *
 *  \brief 拍摄按钮颜色进度条颜色
 *  \endif
*/
  String? minimumTrackTintColor;

/*! \if ENGLISH
 *
 *  \brief Capture record button  progress bar color when highlighted
 *  \else
 *
 *  \brief 拍摄按钮颜色进度条高亮颜色
 *  \endif
*/
  String? maximumTrackTintColor;

/*! \if ENGLISH
 *
 *  \brief Capture button start recording icon
 *  \else
 *
 *  \brief 拍摄按钮开始录制图标
 *  \endif
*/
  String? playImageName;

/*! \if ENGLISH
 *
 *  \brief Capture button stop recording icon
 *  \else
 *
 *  \brief 拍摄按钮停止录制图标
 *  \endif
*/
  String? pauseImageName;

/*! \if ENGLISH
 *
 *  \brief Capture button story icon
 *  \else
 *  
 *  \brief 拍摄按钮快拍图标
 *  \endif
*/
  String? smartImageName;

  // 构造函数
  NvRecordBtTheme() : super();

  //MARK: -- encode && decode
  @override
  jsonEncode() {
    Map<String, dynamic> jsonMap = super.jsonEncode();
    if (normalColor != null) {
      jsonMap['normalColor'] = normalColor;
    }
    if (minimumTrackTintColor != null) {
      jsonMap['minimumTrackTintColor'] = minimumTrackTintColor;
    }
    if (maximumTrackTintColor != null) {
      jsonMap['maximumTrackTintColor'] = maximumTrackTintColor;
    }
    if (playImageName != null) {
      jsonMap['playImageName'] = playImageName;
    }
    if (pauseImageName != null) {
      jsonMap['pauseImageName'] = pauseImageName;
    }
    if (smartImageName != null) {
      jsonMap['smartImageName'] = smartImageName;
    }
    return jsonMap;
  }
}
