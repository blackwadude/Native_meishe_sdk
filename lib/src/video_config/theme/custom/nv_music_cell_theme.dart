import '../theme_element/nv_button_theme.dart';
import '../theme_element/nv_cell_theme.dart';
import '../theme_element/nv_label_theme.dart';
import '../theme_element/nv_image_view_theme.dart';

/*! \if ENGLISH
 *
 *  \brief MusicCellTheme Configuration item
 *  \else
 *
 *  \brief MusicCellTheme配置项
 *  \endif
*/
class NvMusicCellTheme extends NvCellTheme {
/*! \if ENGLISH
 *
 *  \brief Image styles and default images
 *  \else
 *
 *  \brief 图片样式及默认图
 *  \endif
*/
  NvImageViewTheme? imageView;
/*! \if ENGLISH
 *
 *  \brief Crop button style
 *  \else
 *
 *  \brief 裁剪按钮样式
 *  \endif
*/
  NvButtonTheme? cutBt;

/*! \if ENGLISH
 *
 *  \brief Description text style
 *  \else
 *
 *  \brief 描述文本样式
 *  \endif
*/
  NvLabelTheme? desLable;

/*! \if ENGLISH
 *
 *  \brief Time text style
 *  \else
 *
 *  \brief 时间文本样式
 *  \endif
*/
  NvLabelTheme? timeLable;

/*! \if ENGLISH
 *
 *  \brief Download the gif file path
 *  \else
 *
 *  \brief 下载中gif文件路径
 *  \endif
*/
  String? loadingAnimatedFilePath;

  // 构造函数
  NvMusicCellTheme() : super();

// MARK: -- encode && decode
  @override
  jsonEncode() {
    Map<String, dynamic> jsonMap = super.jsonEncode();
    if (imageView != null) jsonMap['imageView'] = imageView!.jsonEncode();
    if (cutBt != null) jsonMap['cutBt'] = cutBt!.jsonEncode();
    if (desLable != null) jsonMap['desLable'] = desLable!.jsonEncode();
    if (timeLable != null) jsonMap['timeLable'] = timeLable!.jsonEncode();
    if (loadingAnimatedFilePath != null) {
      jsonMap['loadingAnimatedFilePath'] = loadingAnimatedFilePath!;
    }
    return jsonMap;
  }
}
