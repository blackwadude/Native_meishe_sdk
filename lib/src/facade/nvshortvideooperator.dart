import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';
import '../nvvideooperator.dart';
import '../video_config/config/nv_video_config.dart';

class NvShortVideoOperator extends NvVideoOperator {
  final MethodChannel _videoEditChannel =
      const MethodChannel('VideoEditMethodChannel');
  final MethodChannel _videoEditCallbackChannel =
      const MethodChannel('VideoEditCallbackMethodChannel');
  final MethodChannel _draftUpdateChannel =
      const MethodChannel('VideoEditDraftChangeMethodChannel');

  void Function(NvVideoEditEvent event, Map info)? videoEventHandler;
  void Function()? draftHandler;
  void Function(NvVideoCompileEvent event, Map compileInfo)? compileHandler;

  NvShortVideoOperator() {
    _videoEditChannel.setMethodCallHandler((MethodCall call) async {
      debugPrint("******* edit channel call method:" + call.method);
      if (call.method == 'VideoEditResultEvent') {
        if (call.arguments is Map) {
          Map arguments = call.arguments;
          if (videoEventHandler != null) {
            videoEventHandler!(NvVideoEditEvent.publish, arguments);
          }
          return (0);
        } else {
          debugPrint("arguments type error");
          return (-1);
        }
      } else {
        return (0);
      }
    });
    _draftUpdateChannel.setMethodCallHandler((MethodCall call) async {
      debugPrint("******* draft channel call method:" + call.method);
      if (call.method == 'DraftListUpdate') {
        if (draftHandler != null) {
          draftHandler!();
        }
      }
    });

    _videoEditCallbackChannel.setMethodCallHandler((MethodCall call) async {
      debugPrint("******* video channel call method:" + call.method);
      Map arguments = {};
      if (call.arguments is Map) {
        arguments = call.arguments;
      } else {
        debugPrint("arguments type error");
        return (-1);
      }
      if (call.method == 'DidCompileProgressMethod') {
        if (compileHandler != null) {
          compileHandler!(NvVideoCompileEvent.progress, arguments);
        }
      } else if (call.method == 'DidCompileCompletedMethod') {
        if (compileHandler != null) {
          compileHandler!(NvVideoCompileEvent.complete, arguments);
        }
      } else if (call.method == 'DidCoverImageChangedMethod') {
        if (compileHandler != null) {
          compileHandler!(NvVideoCompileEvent.coverImageSelected, arguments);
        }
      }

      return (0);
    });
  }

  static late final NvShortVideoOperator _instance = NvShortVideoOperator();

  static NvShortVideoOperator getInstance() {
    return _instance;
  }

  //向原生发送命令
  //Send commands to native platform
  Future<T?> invokeVideoEditMethod<T>(String method, [dynamic arguments]) {
    return _videoEditChannel.invokeMethod<T>(method, arguments);
  }

  @override
  Future configServerInfo(Map<String, dynamic> map) {
    return invokeVideoEditMethod("ConfigServerInfo", map);
  }

  @override
  startVideoCapture({NvVideoConfig? config, NvMusicInfo? musicInfo}) {
    final methodArguments = <String, dynamic>{
      if (musicInfo != null) "musicInfo": musicInfo.toJson(),
      if (config != null) "config": config.jsonEncode()
    };
    invokeVideoEditMethod("CaptureMethod", methodArguments);
  }

  @override
  startVideoDualCapture({NvVideoConfig? config}) {
    final methodArguments =
        config != null ? {"config": config.jsonEncode()} : {};
    invokeVideoEditMethod("DualCaptureMethod", methodArguments);
  }

  @override
  startVideoDualCaptureWithVideo(String videoPath, {NvVideoConfig? config}) {
    final methodArguments = <String, dynamic>{
      "videoPath": videoPath,
      if (config != null) "config": config.jsonEncode()
    };
    invokeVideoEditMethod("DualCaptureWithVideoMethod", methodArguments);
  }

  @override
  startSelectFilesForEdit({NvVideoConfig? config}) {
    final methodArguments =
        config != null ? {"config": config.jsonEncode()} : {};
    invokeVideoEditMethod("EditMethod", methodArguments);
  }

  @override
  Future getDraftList() {
    return invokeVideoEditMethod("DraftListMethod");
  }

  @override
  Future reeditDraft(String projectId, {NvVideoConfig? config}) {
    return invokeVideoEditMethod("ReeditMethod", {
      "projectId": projectId,
      if (config != null) "config": config.jsonEncode()
    });
  }

  @override
  Future deleteDraft(String projectId) {
    return invokeVideoEditMethod("DeleteDraftMethod", {"projectId": projectId});
  }

  @override
  Future saveDraft(String info) {
    return invokeVideoEditMethod("SaveDraftMethod", {"draftInfo": info});
  }

  @override
  Future saveImage(String info) {
    return invokeVideoEditMethod("SaveImageMethod", {"coverImagePath": info});
  }

  @override
  Future selectCoverImage() {
    return invokeVideoEditMethod("SelectCoverImageMethod");
  }

  @override
  Future compileCurrentTimeline(Map configure) {
    return invokeVideoEditMethod("CompileVideoMethod", configure);
  }

  @override
  Future getAVFileInfoArray() {
    return invokeVideoEditMethod("GetAVFileInfoArrayMethod");
  }

  @override
  Future getAVFileInfo(String path) {
    return invokeVideoEditMethod("GetAVFileInfoMethod", {"path": path});
  }

  @override
  exitEdit(String projectId) {
    invokeVideoEditMethod("ExitVideoEditMethod", {"projectId": projectId});
  }

  @override
  setVideoEditEventHandler(
      Function(NvVideoEditEvent event, Map info)? handler) {
    videoEventHandler = handler;
  }

  @override
  setDraftUpdateHandler(Function()? handler) {
    draftHandler = handler;
  }

  @override
  setVideoCompileEventHandler(
      Function(NvVideoCompileEvent event, Map compileInfo)? handler) {
    compileHandler = handler;
  }
}
