import 'video_config/config/nv_video_config.dart';

/*! \if ENGLISH
 *  \brief Video editing module event
 *  \else
 *  \brief 视频编辑模块事件
 *  \endif
*/
enum NvVideoEditEvent {
  publish, //!< \if ENGLISH Jump to publish \else 跳转到发布 \endif
}

/*! \if ENGLISH
 *  \brief Video compile event
 *  \else
 *  \brief 视频合成事件
 *  \endif
*/
enum NvVideoCompileEvent {
  coverImageSelected, //!< \if ENGLISH cover image selected \else 封面图片选择 \endif
  progress, //!< \if ENGLISH compile progress \else 合成进度 \endif
  complete //!< \if ENGLISH compile state \else 合成完成状态 \endif
}

/*! \if ENGLISH
 *  \brief music information
 *  \else
 *  \brief 传入拍摄页面音乐信息
 *  \endif
*/
class NvMusicInfo {
  final String musicName;
  final String musicPath;

  NvMusicInfo({required this.musicName, required this.musicPath});
  Map<String, dynamic> toJson() {
    return {
      'musicName': musicName,
      'musicPath': musicPath,
    };
  }
}

/*! \if ENGLISH
 *  \brief Video editing module interface
 *  \else
 *  \brief 视频模块接口
 *  \endif
*/
abstract class NvVideoOperator {
/*! \if ENGLISH
 *  \brief Set the material server information，Pass a map
 *  \param assetRequestUrl  Material list request
 *  \param assetCategoryUrl Material category list request
 *  \param assetMusiciansUrl Music list request
 *  \param assetFontUrl Font list request
 *  \param assetDownloadUrl Download address request
 *  \param assetPrefabricatedUrl Prefabricated material request
 *  \param assetAutoCutUrl AutoCut request
 *  \param assetTagUrl Template tag list request
 *  \param clientId clientId
 *  \param clientSecret clientSecret
 *  \param assemblyId assemblyId
 *  \param isAbroad Overseas data request, 0== all, 1== overseas
 *  \else
 *  \brief 设置素材服务器信息，传递一个map
 *  \param assetRequestUrl  素材列表请求
 *  \param assetCategoryUrl 素材分类列表请求
 *  \param assetMusiciansUrl 音乐列表请求
 *  \param assetFontUrl 字体列表请求
 *  \param assetDownloadUrl 下载地址请求
 *  \param assetPrefabricatedUrl 预制素材请求
 *  \param assetAutoCutUrl 一键成片网络请求
 *  \param assetTagUrl 模版标签列表请求
 *  \param clientId clientId
 *  \param clientSecret clientSecret
 *  \param assemblyId assemblyId
 *  \param isAbroad 海外数据请求，0==全部，1==海外
 *  \endif
*/
  Future configServerInfo(Map<String, dynamic> map);

/*! \if ENGLISH
 *
 *  \brief Shooting entrance
 *  \param config Configuration item
 *  \param music The default is nil，If you need to shoot with music, you need to pass an audio object, and the path of the audio must be local and has been downloaded
 *  \else
 *
 *  \brief 拍摄入口
 *  \param config 配置项
 *  \param music 默认是nil，如果拍摄时需要带音乐拍摄，需要传递一个音频对象，音频的路径必须是本地的，已经下载的路径
 *  \endif
 */
  startVideoCapture({NvVideoConfig? config, NvMusicInfo? musicInfo});

/*! \if ENGLISH
 *
 *  \brief PIP entrance By default, the album is opened, and a material from the album is taken into the beat
 *  \param config Configuration item
 *  \else
 *
 *  \brief 合拍入口，默认打开相册，从相册取一个素材进入合拍
 *  \param config 配置项
 *  \endif
 */
  startVideoDualCapture({NvVideoConfig? config});

/*! \if ENGLISH
 *
 *  \brief PIP entrance
 *  \param config Configuration item
 *  \param videoPath The video path to be filmed must be a local path
 *  \else
 *
 *  \brief 合拍入口
 *  \param config 配置项
 *  \param videoPath 准备合拍的视频路径，必须是本地路径
 *  \endif
 */
  startVideoDualCaptureWithVideo(String videoPath, {NvVideoConfig? config});

/*! \if ENGLISH
 *
 *  \brief Edit entrance
 *  \param config Configuration item
 *  \else
 *
 *  \brief 编辑入口
 *  \param config 配置项
 *  \endif
 */
  startSelectFilesForEdit({NvVideoConfig? config});

/*! \if ENGLISH
 *  \brief get draft list
 *  \else
 *  \brief 获取草稿列表
 *  \endif
*/
  Future getDraftList();

/*! \if ENGLISH
 *
 *  \brief Enter the editing portal through draft data recovery
 *  \param projectId Current draft id
 *  \param config Configuration item
 *  \else
 *
 *  \brief 通过草稿数据恢复，进入编辑入口
 *  \param projectId 当前草稿id
 *  \param config 配置项
 *  \endif
 */
  Future reeditDraft(String projectId, {NvVideoConfig? config});

/*! \if ENGLISH
 *  \brief delete draft
 *  \else
 *  \brief 删除草稿
 *  \endif
*/
  Future deleteDraft(String projectId);

/*! \if ENGLISH
 *  \brief save draft
 *  \else
 *  \brief 保存草稿
 *  \endif
*/
  Future saveDraft(String info);

  /*! \if ENGLISH
 *  \brief save image
 *  \else
 *  \brief 保存图片
 *  \endif
*/
  Future saveImage(String info);

  /*! \if ENGLISH
 *  \brief Select Cover Image
 *  \else
 *  \brief 选择封面
 *  \endif
*/
  Future selectCoverImage();

/*! \if ENGLISH
 *  \brief Composite video
 *  \else
 *  \brief 合成视频
 *  \endif
*/
  Future compileCurrentTimeline(Map configure);

/*! \if ENGLISH
 *
 *  \brief Get a list of all currently selected materials
 *  \else
 *
 *  \brief 获取当前所选所有素材列表
 *  \endif
 */
  Future getAVFileInfoArray();

/*! \if ENGLISH
 *
 *  \brief Get material information
 *  \param path material path
 *  \else
 *
 *  \brief 获取素材信息
 *  \param path 素材路径
 *  \endif
 */
  Future getAVFileInfo(String path);

/*! \if ENGLISH
 *
 *  \brief Exit the entire publisher call
 *  \param projectId Returned by the edit completion callback
 *  \warning This method will clean up the current draft and SDK-held resources, please call after completely exiting the editing and publishing process
 *  \else
 *
 *  \brief 退出整个发布器调用
 *  \param projectId 由编辑完成回调中返回
 *  \warning 该方法会清理当前草稿以及sdk持有资源，请在完全退出编辑发布流程之后，调用
 *  \endif
 */
  exitEdit(String projectId);

/*! \if ENGLISH
 *  \brief Edit module event callback
 *  \else
 *  \brief 编辑模块事件回调
 *  \endif
*/
  setVideoEditEventHandler(Function(NvVideoEditEvent event, Map info)? handler);

/*! \if ENGLISH
 *  \brief Draft update event callback
 *  \else
 *  \brief 草稿更新事件回调
 *  \endif
*/
  setDraftUpdateHandler(Function()? handler);

/*! \if ENGLISH
 *  \brief Composite video event callback
 *  \else
 *  \brief 视频合成事件回调
 *  \endif
*/
  setVideoCompileEventHandler(
      Function(NvVideoCompileEvent event, Map compileInfo)? handler);
}
