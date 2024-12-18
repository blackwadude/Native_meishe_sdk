import 'nv_view_theme.dart';

/*! \if ENGLISH
 *
 *  \brief ImageView Configuration item
 *  \else
 *
 *  \brief ImageView配置项
 *  \endif
*/
class NvImageViewTheme extends NvViewTheme {
/*! \if ENGLISH
 *
 *  \brief Image name
 *  \else
 *
 *  \brief 图片名称
 *  \endif
*/
  String? imageName;

/*! \if ENGLISH
 *
 *  \brief animation file
 *  \else
 *
 *  \brief 动画文件
 *  \endif
*/
  String? animatedFilePath;

  NvImageViewTheme() : super();

// MARK: -- encode && decode
  @override
  jsonEncode() {
    Map<String, dynamic> jsonMap = super.jsonEncode();
    if (imageName != null) jsonMap['imageName'] = imageName;
    if (animatedFilePath != null) jsonMap['animatedFilePath'] = imageName;
    return jsonMap;
  }
}
