import '../theme_element/nv_button_theme.dart';
import '../theme_element/nv_view_theme.dart';
import '../theme_element/nv_label_theme.dart';
import '../theme_element/nv_image_view_theme.dart';
import '../theme_element/nv_slider_theme.dart';

/*! \if ENGLISH
 *
 *  \brief Beauty panel and Beauty makeup panel are shared Configuration item
 *  \else
 *
 *  \brief 美颜面板和美妆面板配置项
 *  \endif
*/
class NvBeautyPanelTheme extends NvViewTheme {
/*! \if ENGLISH
 *
 *  \brief cornerRadius
 *  \else
 *
 *  \brief 圆角
 *  \endif
*/
  num? cornerRadius;

/*! \if ENGLISH
 *
 *  \brief Panel background color
 *  \else
 *
 *  \brief 面板背景色
 *  \endif
*/
  String? contentBackgroundColor;

/*! \if ENGLISH
 *
 *  \brief Top panel top line
 *  \else
 *
 *  \brief 面板顶部线
 *  \endif
*/
  NvViewTheme? lineTheme;

/*! \if ENGLISH
 *
 *  \brief Underline the panel categories
 *  \else
 *
 *  \brief 面板分类的下划线
 *  \endif
*/
  String? cellUnderlineColor;

/*! \if ENGLISH
 *
 *  \brief Underline the panel categories hidden
 *  \else
 *
 *  \brief 面板分类的下划线隐藏
 *  \endif
*/
  bool? cellUnderlineHidden;

/*! \if ENGLISH
 *
 *  \brief First stage slide
 *  \else
 *
 *  \brief 一级滑杆
 *  \endif
*/
  NvSliderTheme? sliderLevel1Theme;

/*! \if ENGLISH
 *
 *  \brief Secondary slide bar, only used to Oiliness
 *  \else
 *
 *  \brief 二级滑杆，只有去油光用到
 *  \endif
*/
  NvSliderTheme? sliderLevel2Theme;

/*! \if ENGLISH
 *
 *  \brief First stage slide title
 *  \else
 *
 *  \brief 一级滑杆标题
 *  \endif
*/
  NvLabelTheme? labelLevel1Theme;

/*! \if ENGLISH
 *
 *  \brief Secondary slide bar title, only used to Oiliness
 *  \else
 *
 *  \brief 二级滑杆标题，只有去油光用到
 *  \endif
*/
  NvLabelTheme? labelLevel2Theme;

/*! \if ENGLISH
 *
 *  \brief Beauty panel under the switch button, turn on the state of color
 *  \else
 *
 *  \brief 美颜面板下的开关按钮，打开状态下的颜色
 *  \endif
*/
  String? switchOnTintColor;

/*! \if ENGLISH
 *
 *  \brief Beauty panel under the switch button, turn off the state of the color
 *  \else
 *
 *  \brief 美颜面板下的开关按钮，关闭状态下的颜色
 *  \endif
*/
  String? switchNormalTintColor;

/*! \if ENGLISH
 *
 *  \brief Beauty panel under the switch button color
 *  \else
 *
 *  \brief 美颜面板下的开关按钮的颜色
 *  \endif
*/
  String? switchThumbTintColor;

/*! \if ENGLISH
 *
 *  \brief No effect icon for beauty makeup
 *  \else
 *
 *  \brief 美妆的无效果图标
 *  \endif
*/
  String? originalImage;

/*! \if ENGLISH
 *
 *  \brief An array of optional colors for adjustable makeup
 *  \warning The array holds the string @"#243BFF"
 *  \else
 *
 *  \brief 美妆可调单妆的可选颜色数组
 *  \warning 数组存放的是此类字符串@"#243BFF"
 *  \endif
*/
  List<String>? selectorColorArray;

/*! \if ENGLISH
 *
 *  \brief Under makeup (makeup and filters) panel
 *  \else
 *
 *  \brief 美妆妆容下的（妆容和滤镜）面板
 *  \endif
*/
  NvViewTheme? makeupFilterViewTheme;

/*! \if ENGLISH
 *
 *  \brief Under makeup (makeup and filters) panel
 *  Makeup button
 *  \else
 *
 *  \brief 美妆妆容下的（妆容和滤镜）面板
 *  妆容按钮
 *  \endif
*/
  NvButtonTheme? makeupBtnTheme;

/*! \if ENGLISH
 *
 *  \brief Under makeup (makeup and filters) panel
 *  Filter button
 *  \else
 *
 *  \brief 美妆妆容下的（妆容和滤镜）面板
 *  滤镜按钮
 *  \endif
*/
  NvButtonTheme? filterBtnTheme;

/*! \if ENGLISH
 *
 *  \brief The triangle icon in the beauty palette
 *  \else
 *
 *  \brief 美妆调色面板的小三角图标
 *  \endif
*/
  NvImageViewTheme? selectorImageViewTheme;

  // 构造函数
  NvBeautyPanelTheme() : super();

// MARK: -- encode && decode
  @override
  jsonEncode() {
    Map<String, dynamic> jsonMap = super.jsonEncode();
    if (cornerRadius != null) jsonMap['cornerRadius'] = cornerRadius;
    if (contentBackgroundColor != null) {
      jsonMap['contentBackgroundColor'] = contentBackgroundColor;
    }
    if (lineTheme != null) jsonMap['lineTheme'] = lineTheme!.jsonEncode();
    if (cellUnderlineColor != null) {
      jsonMap['cellUnderlineColor'] = cellUnderlineColor;
    }
    if (cellUnderlineHidden != null) {
      jsonMap['cellUnderlineHidden'] = cellUnderlineHidden;
    }
    if (sliderLevel1Theme != null) {
      jsonMap['sliderLevel1Theme'] = sliderLevel1Theme!.jsonEncode();
    }
    if (sliderLevel2Theme != null) {
      jsonMap['sliderLevel2Theme'] = sliderLevel2Theme!.jsonEncode();
    }
    if (labelLevel1Theme != null) {
      jsonMap['labelLevel1Theme'] = labelLevel1Theme!.jsonEncode();
    }
    if (labelLevel2Theme != null) {
      jsonMap['labelLevel2Theme'] = labelLevel2Theme!.jsonEncode();
    }
    if (switchOnTintColor != null) {
      jsonMap['switchOnTintColor'] = switchOnTintColor;
    }
    if (switchNormalTintColor != null) {
      jsonMap['switchNormalTintColor'] = switchNormalTintColor;
    }
    if (switchThumbTintColor != null) {
      jsonMap['switchThumbTintColor'] = switchThumbTintColor;
    }
    if (originalImage != null) jsonMap['originalImage'] = originalImage;
    if (selectorColorArray != null) {
      jsonMap['selectorColorArray'] = selectorColorArray;
    }
    if (makeupFilterViewTheme != null) {
      jsonMap['makeupFilterViewTheme'] = makeupFilterViewTheme!.jsonEncode();
    }
    if (makeupBtnTheme != null) {
      jsonMap['makeupBtnTheme'] = makeupBtnTheme!.jsonEncode();
    }
    if (filterBtnTheme != null) {
      jsonMap['filterBtnTheme'] = filterBtnTheme!.jsonEncode();
    }
    if (selectorImageViewTheme != null) {
      jsonMap['selectorImageViewTheme'] = selectorImageViewTheme!.jsonEncode();
    }
    return jsonMap;
  }
}
