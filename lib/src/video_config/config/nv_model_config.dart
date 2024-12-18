/// NvModelConfig 类，用于配置不同的模型路径

/*! \if ENGLISH
 *
 *  \brief model Configuration item
 *  \else
 *
 *  \brief 模型配置项
 *  \endif
*/
class NvModelConfig {

/*! \if ENGLISH
 *
 *  \brief Whether to use the 240 point model
 *  \else
 *
 *  \brief 是否使用240点位模型
 *  \endif
*/
  bool? use240;

/*! \if ENGLISH
 *
 *  \brief fakeface model path
 *  \else
 *
 *  \brief fakeface 模型路径
 *  \endif
*/
  String? fakeface;

/*! \if ENGLISH
 *
 *  \brief 106face point model path
 *  \else
 *
 *  \brief 106点位模型路径
 *  \endif
*/
  String? face;

/*! \if ENGLISH
 *
 *  \brief 240face point  model path
 *  \else
 *
 *  \brief 240点位模型路径
 *  \endif
*/
  String? face240;

/*! \if ENGLISH
 *
 *  \brief avatar model path
 *  \else
 *
 *  \brief avatar模型路径
 *  \endif
*/
  String? avatar;

/*! \if ENGLISH
 *
 *  \brief makeup model path
 *  \else
 *
 *  \brief 美妆模型路径
 *  \endif
*/
  String? makeup;

/*! \if ENGLISH
 *
 *  \brief hand model path
 *  \else
 *
 *  \brief 手势模型路径
 *  \endif
*/
  String? hand;

/*! \if ENGLISH
 *
 *  \brief segmentation model path
 *  \else
 *
 *  \brief 分割模型路径
 *  \endif
*/
  String? humanseg;

/*! \if ENGLISH
 *
 *  \brief eyecontour model path
 *  \else
 *
 *  \brief 眼球模型路径
 *  \endif
*/
  String? eyecontour;

/*! \if ENGLISH
 *
 *  \brief Activity model path
 *  \else
 *
 *  \brief Activity 模型路径
 *  \endif
*/
  String? autoCutActivity;

/*! \if ENGLISH
 *
 *  \brief FaceAttri model path
 *  \else
 *
 *  \brief FaceAttri 模型路径
 *  \endif
*/
  String? autoCutFaceAttri;

/*! \if ENGLISH
 *
 *  \brief Face model path
 *  \else
 *
 *  \brief Face 模型路径
 *  \endif
*/
  String? autoCutFace;

/*! \if ENGLISH
 *
 *  \brief Imagecls model path
 *  \else
 *
 *  \brief Imagecls 模型路径
 *  \endif
*/
  String? autoCutImagecls;

/*! \if ENGLISH
 *
 *  \brief Pf model path
 *  \else
 *
 *  \brief Pf 模型路径
 *  \endif
*/
  String? autoCutPf;

/*! \if ENGLISH
 *
 *  \brief Photo model path
 *  \else
 *  
 *  \brief Photo 模型路径
 *  \endif
*/
  String? autoCutPhoto;

// MARK: -- encode && decode

  jsonEncode() {
    Map<String, dynamic> jsonMap = {
      if (fakeface != null) 'use240': use240,
      if (fakeface != null) 'fakeface': fakeface,
      if (face != null) 'face': face,
      if (face240 != null) 'face240': face240,
      if (avatar != null) 'avatar': avatar,
      if (makeup != null) 'makeup': makeup,
      if (hand != null) 'hand': hand,
      if (humanseg != null) 'humanseg': humanseg,
      if (eyecontour != null) 'eyecontour': eyecontour,
      if (autoCutActivity != null) 'autoCutActivity': autoCutActivity,
      if (autoCutFaceAttri != null) 'autoCutFaceAttri': autoCutFaceAttri,
      if (autoCutFace != null) 'autoCutFace': autoCutFace,
      if (autoCutImagecls != null) 'autoCutImagecls': autoCutImagecls,
      if (autoCutPf != null) 'autoCutPf': autoCutPf,
      if (autoCutPhoto != null) 'autoCutPhoto': autoCutPhoto
    };
    return jsonMap;
  }

  static NvModelConfig jsonDecode(dynamic json) {
    NvModelConfig config = NvModelConfig();
    if (json['use240'] != null) {
      config.use240 = json['use240'] as bool?;
    }
    if (json['fakeface'] != null) {
      config.fakeface = json['fakeface'] as String?;
    }
    if (json['face'] != null) {
      config.face = json['face'] as String?;
    }
    if (json['face240'] != null) {
      config.face240 = json['face240'] as String?;
    }
    if (json['avatar'] != null) {
      config.avatar = json['avatar'] as String?;
    }
    if (json['makeup'] != null) {
      config.makeup = json['makeup'] as String?;
    }
    if (json['hand'] != null) {
      config.hand = json['hand'] as String?;
    }
    if (json['humanseg'] != null) {
      config.humanseg = json['humanseg'] as String?;
    }
    if (json['eyecontour'] != null) {
      config.eyecontour = json['eyecontour'] as String?;
    }
    if (json['autoCutActivity'] != null) {
      config.autoCutActivity = json['autoCutActivity'] as String?;
    }
    if (json['autoCutFaceAttri'] != null) {
      config.autoCutFaceAttri = json['autoCutFaceAttri'] as String?;
    }
    if (json['autoCutFace'] != null) {
      config.autoCutFace = json['autoCutFace'] as String?;
    }
    if (json['autoCutImagecls'] != null) {
      config.autoCutImagecls = json['autoCutImagecls'] as String?;
    }
    if (json['autoCutPf'] != null) {
      config.autoCutPf = json['autoCutPf'] as String?;
    }
    if (json['autoCutPhoto'] != null) {
      config.autoCutPhoto = json['autoCutPhoto'] as String?;
    }
    return config;
  }
}
