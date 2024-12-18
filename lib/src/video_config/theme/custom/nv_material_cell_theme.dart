import '../theme_element/nv_cell_theme.dart';
import '../theme_element/nv_image_view_theme.dart';

/*! \if ENGLISH
 *
 *  \brief MaterialCellTheme Configuration item
 *  \else
 *
 *  \brief MaterialCellTheme配置项
 *  \endif
*/
class NvMaterialCellTheme extends NvCellTheme {
/*! \if ENGLISH
 *
 *  \brief Picture style
 *  \else
 *
 *  \brief 图片样式
 *  \endif
*/
  NvImageViewTheme? imageView;

/*! \if ENGLISH
 *
 *  \brief Download button icon
 *  \else
 *
 *  \brief 下载按钮图标
 *  \endif
*/
  String? downloadImageName;

/*! \if ENGLISH
 *
 *  \brief Download animation file
 *  \else
 *
 *  \brief 下载动画文件
 *  \endif
*/
  String? loadingAnimatedFilePath;

  // 构造函数
  NvMaterialCellTheme() : super();

// MARK: -- encode && decode
  @override
  jsonEncode() {
    Map<String, dynamic> jsonMap = super.jsonEncode();
    if (imageView != null) jsonMap['imageView'] = imageView!.jsonEncode();
    if (downloadImageName != null) {
      jsonMap['downloadImageName'] = downloadImageName!;
    }
    if (loadingAnimatedFilePath != null) {
      jsonMap['loadingAnimatedFilePath'] = loadingAnimatedFilePath!;
    }
    return jsonMap;
  }
}
