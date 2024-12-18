import '../theme_element/nv_view_theme.dart';
import '../theme_element/nv_label_theme.dart';

/*! \if ENGLISH
 *
 *  \brief VideoTrackEditViewTheme Configuration item
 *  \else
 *
 *  \brief VideoTrackEditViewTheme配置项
 *  \endif
*/
class NvVideoTrackEditViewTheme extends NvViewTheme {
/*! \if ENGLISH
 *
 *  \brief Stroke color
 *  \else
 *
 *  \brief 描边颜色
 *  \endif
*/
  String? selectedClipBorderColor;

/*! \if ENGLISH
 *
 *  \brief Left and right handle icon
 *  \else
 *
 *  \brief 左右把手图标
 *  \endif
*/
  String? leftHandleImage;
  String? rightHandleImage;

/*! \if ENGLISH
 *
 *  \brief Timeline color
 *  \else
 *
 *  \brief 时间轴颜色
 *  \endif
*/
  String? timeTrackColor;

/*! \if ENGLISH
 *
 *  \brief Text style
 *  \else
 *
 *  \brief 文本样式
 *  \endif
*/
  NvLabelTheme? durationLabel;

  // 构造函数
  NvVideoTrackEditViewTheme() : super();

  //MARK: -- encode && decode
  @override
  jsonEncode() {
    Map<String, dynamic> jsonMap = super.jsonEncode();
    if (selectedClipBorderColor != null) {
      jsonMap['selectedClipBorderColor'] = selectedClipBorderColor;
    }
    if (leftHandleImage != null) {
      jsonMap['leftHandleImage'] = leftHandleImage;
    }
    if (rightHandleImage != null) {
      jsonMap['rightHandleImage'] = rightHandleImage;
    }
    if (timeTrackColor != null) {
      jsonMap['timeTrackColor'] = timeTrackColor;
    }
    if (durationLabel != null) {
      jsonMap['durationLabel'] = durationLabel!.jsonEncode();
    }
    return jsonMap;
  }
}
