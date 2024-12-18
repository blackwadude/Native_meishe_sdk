package com.meishe.nvshortvideo;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.blankj.utilcode.util.FileUtils;
import com.blankj.utilcode.util.LogUtils;
import com.meicam.sdk.NvsAVFileInfo;
import com.meicam.sdk.NvsRational;
import com.meicam.sdk.NvsSize;
import com.meicam.sdk.NvsStreamingContext;
import com.meicam.sdk.NvsTimeline;
import com.meishe.common.model.BClipInfo;
import com.meishe.common.model.EditParamInfo;
import com.meishe.common.utils.DataBackup;
import com.meishe.config.NvVideoConfig;
import com.meishe.draft.DraftManager;
import com.meishe.draft.data.DraftData;
import com.meishe.edit.view.activity.SelectCoverActivity;
import com.meishe.engine.EngineNetApi;
import com.meishe.engine.util.PathUtils;
import com.meishe.libbase.manager.AppManager;
import com.meishe.libbase.utils.NvsServerClient;
import com.meishe.module.NvModuleManager;
import com.meishe.module.bean.NvMusicInfo;
import com.meishe.module.interfaces.NvModuleManagerCallback;
import com.meishe.nvshortvideo.bean.NvError;
import com.meishe.nvshortvideo.bean.OnMethodCallListener;

import org.jetbrains.annotations.NotNull;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

import io.flutter.embedding.engine.plugins.FlutterPlugin;
import io.flutter.embedding.engine.plugins.activity.ActivityAware;
import io.flutter.embedding.engine.plugins.activity.ActivityPluginBinding;
import io.flutter.plugin.common.MethodCall;
import io.flutter.plugin.common.MethodChannel;
import io.flutter.plugin.common.MethodChannel.MethodCallHandler;
import io.flutter.plugin.common.MethodChannel.Result;
import io.flutter.plugin.common.PluginRegistry;

import static android.app.Activity.RESULT_OK;
import static com.meishe.nvshortvideo.PluginConstants.CAPTURE_METHOD;
import static com.meishe.nvshortvideo.PluginConstants.DELETE_DRAFT_METHOD;
import static com.meishe.nvshortvideo.PluginConstants.DRAFT_LIST_METHOD;
import static com.meishe.nvshortvideo.PluginConstants.DUAL_CAPTURE_METHOD;
import static com.meishe.nvshortvideo.PluginConstants.DUAL_CAPTURE_WITH_VIDEO_METHOD;
import static com.meishe.nvshortvideo.PluginConstants.EDIT_METHOD;
import static com.meishe.nvshortvideo.PluginConstants.REEDIT_METHOD;
import static com.meishe.nvshortvideo.PluginConstants.SAVE_DRAFT_METHOD;
import static com.meishe.nvshortvideo.PluginConstants.SAVE_IMAGE_METHOD;
import static com.meishe.nvshortvideo.PluginConstants.SELECT_COVER_IMAGE_METHOD;

/**
 * VideoEditPlugin
 */
public class VideoEditPlugin implements FlutterPlugin, MethodCallHandler, ActivityAware, PluginRegistry.ActivityResultListener {
    private static final int SELECT_COVER_CODE = 100;
    private static final String PROJECT_ID = "projectId";
    private static final String PATH = "path";
    private MethodChannel mVideoEditChannel;
    private MethodChannel mVideoEditCallbackChannel;
    private MethodChannel mVideoDraftChannel;
    private MethodChannel.Result mainResult;
    private Context mContext;
    private Activity mActivity;
    private boolean isInitSdk = false;
    private long mCoverPoint;

    @Override
    public void onAttachedToActivity(@NonNull @NotNull ActivityPluginBinding binding) {
        binding.addActivityResultListener(this);
        mActivity = binding.getActivity();
        if (mActivity == null) {
            return;
        }
        if (!isInitSdk) {
            isInitSdk = true;
            NvModuleManager.get().init(mActivity.getApplication());
            String mLicPath = "assets:/meishesdk.lic";
            NvModuleManager.get().initSdk(mLicPath);
        }
    }

    @Override
    public void onAttachedToEngine(@NonNull FlutterPluginBinding flutterPluginBinding) {
        mContext = flutterPluginBinding.getApplicationContext();
        mVideoEditChannel = new MethodChannel(flutterPluginBinding.getBinaryMessenger(), PluginConstants.VIDEO_EDIT_CHANNEL);
        mVideoEditChannel.setMethodCallHandler(this);
        mVideoEditCallbackChannel = new MethodChannel(flutterPluginBinding.getBinaryMessenger(), PluginConstants.VIDEO_EDIT_CALLBACK_CHANNEL);
        mVideoEditCallbackChannel.setMethodCallHandler(this);
        mVideoDraftChannel = new MethodChannel(flutterPluginBinding.getBinaryMessenger(), PluginConstants.VIDEO_DRAFT_CHANNEL);
        mVideoDraftChannel.setMethodCallHandler(this);
        NvModuleManager.get().setModuleManagerCallback(new NvModuleManagerCallback() {
            @Override
            public void publishWithInfo(Activity activity, boolean needSaveDraft, boolean needSaveCover, boolean needSaveVideo, String videoPath) {
                if (activity instanceof PublishActivity) {
                    goPublish(needSaveDraft, needSaveCover, needSaveVideo,videoPath);
                } else {
                    Bundle bundle = new Bundle();
                    bundle.putBoolean("intent_key_can_save_draft", needSaveDraft);
                    bundle.putBoolean("intent_key_can_save_cover", needSaveCover);
                    bundle.putBoolean("intent_key_can_save_video", needSaveVideo);
                    bundle.putString("intent_key_video_path", videoPath);
                    AppManager.getInstance().jumpActivity(activity,
                            PublishActivity.class, bundle);
                }
            }

        });
        DraftManager.getInstance().setDraftDeleteCallBack(new DraftManager.DraftDeleteCallBack() {
            @Override
            public void onDraftDeleted() {
                Map<String, Object> argumentsReturn = new TreeMap<>();
                mVideoDraftChannel.invokeMethod("DraftListUpdate", argumentsReturn);
            }
        });
    }

    @Override
    public void onMethodCall(@NonNull MethodCall call, @NonNull Result result) {
        mainResult = result;
        onPluginMethodCall(call.method, call.arguments(), new OnMethodCallListener() {
            @Override
            public void completion(Object response, NvError error) {
                if (null == response && (null == error)) {
                    result.notImplemented();
                    return;
                }
                Map<String, Object> info = new HashMap<>(2);
                if (null != response) {
                    info.put("response", response);
                }
                if (null != error) {
                    info.put("error", error);
                }
                result.success(info);
            }
        });
    }

    private void onPluginMethodCall(String method, Map<String, Object> arguments, OnMethodCallListener methodCallListener) {
        if (TextUtils.isEmpty(method) || (null == methodCallListener)) {
            return;
        }
        if (null == arguments) {
            arguments = new HashMap<>();
        }
        NvVideoConfig mVideoConfig = null;
        if (arguments.containsKey("config")) {
            Map<String, Object> configMap = (Map<String, Object>) arguments.get("config");
            if (null != configMap) {
                try {
                    mVideoConfig = NvVideoConfig.fromJson(configMap);
                } catch (Exception e) {
                    LogUtils.e(e);
                }
            }
        }

        switch (method) {
            case CAPTURE_METHOD:
                NvMusicInfo musicInfo = null;
                if (arguments.containsKey("musicInfo")) {
                    Map<String, Object> musicInfoMap = (Map<String, Object>) arguments.get("musicInfo");
                    if (null != musicInfoMap) {
                        String musicName = (String) musicInfoMap.get("musicName");
                        String musicPath = (String) musicInfoMap.get("musicPath");
                        musicInfo = new NvMusicInfo();
                        musicInfo.setMusicName(musicName);
                        musicInfo.setMusicPath(musicPath);
                    }
                }
                NvModuleManager.get().openCapture(mActivity, mVideoConfig, musicInfo);
                methodCallListener.completion(null, null);
                break;
            case DUAL_CAPTURE_METHOD:
                NvModuleManager.get().openDualCapture(mActivity, mVideoConfig);
                methodCallListener.completion(null, null);
                break;
            case DUAL_CAPTURE_WITH_VIDEO_METHOD:
                String videoPath = (String) arguments.get("videoPath");
                if (TextUtils.isEmpty(videoPath) || !FileUtils.isFileExists(videoPath)) {
                    methodCallListener.completion(null, new NvError(-1, "File exception, please check!"));
                    return;
                }
                NvModuleManager.get().openDualCapture(mActivity, mVideoConfig, videoPath);
                methodCallListener.completion(null, null);
                break;
            case EDIT_METHOD:
                NvModuleManager.get().openEdit(mActivity, mVideoConfig);
                methodCallListener.completion(null, null);
                break;
            case SELECT_COVER_IMAGE_METHOD:
                NvModuleManager.editCover(mActivity, mCoverPoint, SELECT_COVER_CODE);
                methodCallListener.completion(null, null);
                break;
            case SAVE_DRAFT_METHOD:
                String draftDesc = (String) arguments.get("draftInfo");
                NvModuleManager.get().saveDraft(draftDesc, 0, new DraftManager.DraftSaveCallBack() {
                    @Override
                    public void onSaveSuccess(boolean isNew) {
                        methodCallListener.completion(null, null);
                    }
                });
                break;
            case SAVE_IMAGE_METHOD:
                String coverImagePath = (String) arguments.get("coverImagePath");
                NvModuleManager.get().saveCover(coverImagePath, null, 0, true, new NvModuleManager.OnCoverSavedCallBack() {
                    @Override
                    public void onCoverSaved(String path) {
                        if (TextUtils.isEmpty(path) || !FileUtils.isFileExists(path)) {
                            methodCallListener.completion(null, new NvError(-2, "Cover Path error"));
                            return;
                        }
                        methodCallListener.completion(path, null);
                    }

                    @Override
                    public void onCoverSaveFailed() {
                        methodCallListener.completion(null, new NvError(-1, "Save error"));
                    }
                });
                break;
            case "CompileVideoMethod":
                NvModuleManager.saveVideoToAlbum(new NvModuleManager.OnCompileVideoListener() {
                    @Override
                    public void compileProgress(NvsTimeline timeline, int progress) {
                        Map<String, Object> arguments = new TreeMap<>();
                        double progressD = progress;
                        arguments.put("progress", progressD);
                        mVideoEditCallbackChannel.invokeMethod("DidCompileProgressMethod", arguments);
                    }

                    @Override
                    public void compileFinished(NvsTimeline timeline) {
                    }

                    @Override
                    public void compileFailed(NvsTimeline timeline) {
                        Map<String, Object> arguments = new TreeMap<>();
                        mVideoEditCallbackChannel.invokeMethod("DidCompileCompletedMethod", arguments);
                    }

                    @Override
                    public void compileCompleted(NvsTimeline nvsTimeline, String compileVideoPath, boolean isCanceled) {
                        Map<String, Object> arguments = new TreeMap<>();
                        arguments.put("outputPath", compileVideoPath);
                        mVideoEditCallbackChannel.invokeMethod("DidCompileCompletedMethod", arguments);
                    }

                    @Override
                    public void compileVideoCancel() {
                        Map<String, Object> arguments = new TreeMap<>();
                        mVideoEditCallbackChannel.invokeMethod("DidCompileCompletedMethod", arguments);
                    }

                    @Override
                    public void onCompileCompleted(boolean isHardwareEncoder, int errorType, String stringInfo, int flags) {
                    }
                });
                break;
            case "GetAVFileInfoArrayMethod":
                EditParamInfo editParamInfo = DataBackup.getInstance().getEditParamInfo();
                List<String> pathList = new ArrayList<>();
                if (null != editParamInfo) {
                    ArrayList<BClipInfo> videoClipArray = editParamInfo.getMaterialLists();
                    if (videoClipArray != null && videoClipArray.size() > 0) {
                        for (BClipInfo bClipInfo : videoClipArray) {
                            if (bClipInfo != null) {
                                pathList.add(bClipInfo.getFilePath());
                            }
                        }
                    }
                }
                methodCallListener.completion(pathList, null);
                break;
            case "GetAVFileInfoMethod":
                String path = (String) arguments.get(PATH);
                Map<String, Object> resultMap = new TreeMap<>();
                if (!TextUtils.isEmpty(path)) {
                    NvsAVFileInfo avFileInfo = NvsStreamingContext.getInstance().getAVFileInfo(path);
                    if (avFileInfo != null) {
                        NvsSize nvsSize = avFileInfo.getVideoStreamDimension(0);
                        if (nvsSize != null) {
                            resultMap.put("width", nvsSize.width);
                            resultMap.put("height", nvsSize.height);
                        }
                        NvsRational nvsRational = avFileInfo.getVideoStreamFrameRate(0);
                        if (nvsRational != null) {
                            resultMap.put("fps", Math.round(nvsRational.num * 1.00f / nvsRational.den));
                        }
                        int codecType = avFileInfo.getVideoStreamCodecType(0);
                        if (codecType == 1) {
                            resultMap.put("codecType", "H264");
                        } else if (codecType == 2) {
                            resultMap.put("codecType", "H265");
                        } else {
                            resultMap.put("codecType", "UNKNOWN");
                        }
                    }
                }
                methodCallListener.completion(resultMap, null);
                break;
            case "ExitVideoEditMethod":
                AppManager.getInstance().finishAllEditActivity();
                break;
            case "ConfigServerInfo":

                String host = (String) arguments.get("host");
                if (!TextUtils.isEmpty(host)) {
                    NvsServerClient.get().initConfig(mActivity.getApplication(), host);
                }
                String assetAutoCutUrl = (String) arguments.get("assetAutoCutUrl");
                if (!TextUtils.isEmpty(assetAutoCutUrl)) {
                    EngineNetApi.NV_ASSET_AUTOCUT_URL = assetAutoCutUrl;
                }

                String assetRequestUrl = (String) arguments.get("assetRequestUrl");
                if (!TextUtils.isEmpty(assetRequestUrl)) {
                    EngineNetApi.NV_ASSET_REQUEST_URL = assetRequestUrl;
                }

                String assetCategoryUrl = (String) arguments.get("assetCategoryUrl");
                if (!TextUtils.isEmpty(assetCategoryUrl)) {
                    EngineNetApi.NV_ASSET_CATEGORY_URL = assetCategoryUrl;
                }

                String assetMusiciansUrl = (String) arguments.get("assetMusiciansUrl");
                if (!TextUtils.isEmpty(assetMusiciansUrl)) {
                    EngineNetApi.NV_ASSET_MUSICIANS_URL = assetMusiciansUrl;
                }

                String assetFontUrl = (String) arguments.get("assetFontUrl");
                if (!TextUtils.isEmpty(assetFontUrl)) {
                    EngineNetApi.NV_ASSET_FONT_URL = assetFontUrl;
                }

                String assetDownloadUrl = (String) arguments.get("assetDownloadUrl");
                if (!TextUtils.isEmpty(assetDownloadUrl)) {
                    EngineNetApi.NV_ASSET_DOWNLOAD_URL = assetDownloadUrl;
                }

                String assetPrefabricatedUrl = (String) arguments.get("assetPrefabricatedUrl");
                if (!TextUtils.isEmpty(assetPrefabricatedUrl)) {
                    EngineNetApi.NV_ASSET_PREFABRICATED_URL = assetPrefabricatedUrl;
                }

                String assetTagUrl = (String) arguments.get("assetTagUrl");
                if (!TextUtils.isEmpty(assetTagUrl)) {
                    EngineNetApi.NV_ASSET_TAG_URL = assetTagUrl;
                }
                String clientId = (String) arguments.get("clientId");
                if (!TextUtils.isEmpty(clientId)) {
                    NvsServerClient.MallInfo.CLIENT_ID = clientId;
                }

                String clientSecret = (String) arguments.get("clientSecret");
                if (!TextUtils.isEmpty(clientSecret)) {
                    NvsServerClient.MallInfo.CLIENT_SECRET = clientSecret;
                }
                String assemblyId = (String) arguments.get("assemblyId");
                if (!TextUtils.isEmpty(assemblyId)) {
                    NvsServerClient.MallInfo.ASSEMBLY_ID = assemblyId;
                }
                NvModuleManager.get().initModel();
                break;
            case DRAFT_LIST_METHOD:
                methodCallListener.completion(getDraftList(), null);
                break;
            case DELETE_DRAFT_METHOD:
                String draftIdStr = (String) arguments.get(PROJECT_ID);
                DraftData draftData = getDraftDataById(draftIdStr);
                if (null == draftData) {
                    return;
                }
                DraftManager.getInstance().deleteDraft(draftData);
                Map<String, Object> argumentsReturn = new TreeMap<>();
                mVideoDraftChannel.invokeMethod("DraftListUpdate", argumentsReturn);

                methodCallListener.completion(null, null);
                break;
            case REEDIT_METHOD:
                String editDraftIdStr = (String) arguments.get(PROJECT_ID);
                DraftData editDraftData = getDraftDataById(editDraftIdStr);
                if (null == editDraftData) {
                    return;
                }
                NvModuleManager.get().openDraftAndJumpToEdit(mActivity, editDraftData);
                methodCallListener.completion(null, null);
                break;
            default:
                break;
        }
    }

    private void goPublish(boolean needSaveDraft, boolean needSaveCover, boolean needSaveVideo, String videoPath) {
        if (null == mActivity || (null == mVideoEditChannel)) {
            return;
        }
        NvModuleManager.get().saveCover(PathUtils.getCoverDir(), String.valueOf(System.currentTimeMillis()), mCoverPoint, false,
                new NvModuleManager.OnCoverSavedCallBack() {
                    @Override
                    public void onCoverSaved(String path) {
                        Map<String, Object> arguments = new TreeMap<>();
                        arguments.put("hasDraft", needSaveDraft);
                        arguments.put("coverImagePath", path);
                        arguments.put("videoPath", videoPath);
                        //目前默认传00
                        arguments.put("projectId", "00");
                        mVideoEditChannel.invokeMethod("VideoEditResultEvent", arguments);
                        AppManager.getInstance().finishAllEditActivity();
                    }

                    @Override
                    public void onCoverSaveFailed() {
                    }
                });
    }

    private DraftData getDraftDataById(String draftIdStr) {
        if (TextUtils.isEmpty(draftIdStr)) {
            return null;
        }
        List<DraftData> data = DraftManager.getInstance().getAllDraftData();
        if (null == data || data.isEmpty()) {
            return null;
        }
        int draftId = Integer.parseInt(draftIdStr);
        if (draftId < 0 || draftId > data.size() - 1) {
            return null;
        }
        return data.get(draftId);
    }

    /**
     * Get a list of drafts
     */
    private List<Map<String, Object>> getDraftList() {
        List<DraftData> data = DraftManager.getInstance().getAllDraftData();
        List<Map<String, Object>> resultData = new ArrayList<>();
        if (null != data && !data.isEmpty()) {
            for (int i = 0; i < data.size(); i++) {
                DraftData draftData = data.get(i);
                Map<String, Object> draftMap = new TreeMap<>();
                draftMap.put("coverImagePath", draftData.getCoverPath());
                draftMap.put(PROJECT_ID, i + "");
                draftMap.put("draftInfo", ""+draftData.getVideoDesc());
                resultData.add(draftMap);
            }
        }
        return resultData;
    }


    @Override
    public boolean onActivityResult(int requestCode, int resultCode, @Nullable @org.jetbrains.annotations.Nullable Intent data) {
        if (resultCode != RESULT_OK) {
            return false;
        }
        if (requestCode == SELECT_COVER_CODE) {
            if (data != null) {
                Bundle extras = data.getExtras();
                if (extras != null) {
                    mCoverPoint = extras.getLong(SelectCoverActivity.INTENT_KEY_COVER_POINT);
                    String path = extras.getString(SelectCoverActivity.INTENT_KEY_COVER_PATH);
                    Map<String, Object> arguments = new TreeMap<>();
                    arguments.put("coverImagePath", path);
                    mVideoEditCallbackChannel.invokeMethod("DidCoverImageChangedMethod", arguments);
                    return true;
                }
            }
        }
        return false;
    }


    @Override
    public void onDetachedFromActivity() {
        NvModuleManager.get().destroy();
    }

    @Override
    public void onDetachedFromEngine(@NonNull FlutterPluginBinding binding) {
        mVideoEditChannel.setMethodCallHandler(null);
        mVideoEditCallbackChannel.setMethodCallHandler(null);
        mVideoDraftChannel.setMethodCallHandler(null);
    }


    @Override
    public void onDetachedFromActivityForConfigChanges() {
    }

    @Override
    public void onReattachedToActivityForConfigChanges(@NonNull @NotNull ActivityPluginBinding binding) {
        onAttachedToActivity(binding);
    }

}
