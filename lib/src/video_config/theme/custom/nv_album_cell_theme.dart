import '../theme_element/nv_cell_theme.dart';
import '../theme_element/nv_image_view_theme.dart';

/*! \if ENGLISH
 *
 *  \brief AlbumCellTheme Configuration item
 *  \else
 *
 *  \brief AlbumCellTheme配置项
 *  \endif
*/
class NvAlbumCellTheme extends NvCellTheme {
/*! \if ENGLISH
 *
 *  \brief The icon in the lower right corner of the album material cell
 *  \else
 *
 *  \brief 相册素材cell的右下角图标
 *  \endif
*/
  NvImageViewTheme? imageView;

/*! \if ENGLISH
 *
 *  \brief no Select the icon in the upper left corner of the album material cell
 *  \else
 *
 *  \brief 相册素材cell的左上角未选中图标
 *  \endif
*/
  String? normalImage;

/*! \if ENGLISH
 *
 *  \brief Select the icon in the upper left corner of the album material cell
 *  \else
 *  
 *  \brief 相册素材cell的左上角选中图标
 *  \endif
*/
  String? selectImage;

  // 构造函数
  NvAlbumCellTheme() : super();

// MARK: -- encode && decode
  @override
  jsonEncode() {
    Map<String, dynamic> jsonMap = super.jsonEncode();
    if (imageView != null) jsonMap['imageView'] = imageView!.jsonEncode();
    if (normalImage != null) jsonMap['normalImage'] = normalImage!;
    if (selectImage != null) jsonMap['selectImage'] = selectImage!;
    return jsonMap;
  }
}
