package com.meishe.nvshortvideo;

import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.EditText;
import android.widget.ImageView;

import androidx.annotation.Nullable;

import com.blankj.utilcode.util.LogUtils;
import com.blankj.utilcode.util.SizeUtils;
import com.meicam.sdk.NvsTimeline;
import com.meishe.common.UIConfig;
import com.meishe.common.dialog.LoadingPop;
import com.meishe.common.utils.CaptureAndEditUtil;
import com.meishe.draft.DraftManager;
import com.meishe.edit.view.activity.EditMediaActivity;
import com.meishe.edit.view.activity.SelectCoverActivity;
import com.meishe.engine.EditorEngine;
import com.meishe.engine.bean.MeicamTimeline;
import com.meishe.engine.util.PathUtils;
import com.meishe.libbase.base.BaseActivity;
import com.meishe.libbase.manager.AppManager;
import com.meishe.libbase.utils.DrawableUitls;
import com.meishe.libbase.utils.ImageLoader;
import com.meishe.libbase.utils.ToastUtil;
import com.meishe.libbase.utils.Utils;
import com.meishe.libbase.view.RoundBoundView;
import com.meishe.module.NvModuleManager;

/**
 * @author zcy
 * @Destription:
 * @Emial:
 * @CreateDate: 2022/1/26.
 */
public class PublishActivity extends BaseActivity implements View.OnClickListener {
    private static final int REQUEST_EDIT_COVER = 1;
    private static final String INTENT_KEY_CAN_SAVE_DRAFT = "intent_key_can_save_draft";
    private static final String INTENT_KEY_CAN_SAVE_COVER = "intent_key_can_save_cover";
    private static final String INTENT_KEY_CAN_SAVE_VIDEO = "intent_key_can_save_video";
    private ImageView mCoverView;
    private EditText mEditTextView;
    private Bitmap mCoverBitmap;
    private long mCoverPoint;
    private MeicamTimeline mTimeline;
    private View mSaveAlbum;
    private View mSaveCover;
    private boolean mCanSaveDraft = true;
    private boolean mCanSaveCover = true;
    private boolean mCanSaveVideo = true;
    private View mSaveDaft;
    private LoadingPop mLoadingPop;


    public static class IntentBuilder {
       private boolean saveDraft;
       private boolean saveCover;
       private boolean saveVideo;
       public IntentBuilder canSaveDraft(boolean saveDraft){
           this.saveDraft = saveDraft;
           return this;
       }
       public IntentBuilder canSaveCover(boolean saveCover){
           this.saveCover = saveCover;
           return this;
       }

       public IntentBuilder canSaveVideo(boolean saveVideo){
           this.saveVideo = saveVideo;
           return this;
       }

       public Bundle build(){
           Bundle bundle = new Bundle();
           bundle.putBoolean(INTENT_KEY_CAN_SAVE_DRAFT, saveDraft);
           bundle.putBoolean(INTENT_KEY_CAN_SAVE_COVER, saveCover);
           bundle.putBoolean(INTENT_KEY_CAN_SAVE_VIDEO, saveVideo);
           return bundle;
       }
   }

    @Override
    protected int bindLayout() {
        return R.layout.activity_publish;
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode == REQUEST_EDIT_COVER) {
            if (resultCode == RESULT_OK) {
                if (data != null) {
                    Bundle extras = data.getExtras();
                    if (extras != null) {
                        mCoverPoint = extras.getLong(SelectCoverActivity.INTENT_KEY_COVER_POINT);
                        String coverPath =  extras.getString(SelectCoverActivity.INTENT_KEY_COVER_PATH);
                        if (!TextUtils.isEmpty(coverPath)) {
                            ImageLoader.loadUrl(this, coverPath, mCoverView);
                        } else {
                            Bitmap fromTime = CaptureAndEditUtil.getImageFromTime(mTimeline, mCoverPoint);
                            mCoverView.setImageBitmap(fromTime);
                        }
                    }
                }
            }
        }

    }

    private void initListener() {
        findViewById(R.id.backBtn).setOnClickListener(this);
        mSaveDaft.setOnClickListener(this);
        mSaveCover.setOnClickListener(this);
        mSaveAlbum.setOnClickListener(this);
        mCoverView.setOnClickListener(this);
    }


    protected void initView() {
        mCoverView = findViewById(R.id.iv_cover);
        mEditTextView = findViewById(R.id.et_tittle);
        mSaveDaft = findViewById(R.id.tv_save_draft);
        mSaveAlbum = findViewById(R.id.tv_save_album);
        mSaveCover = findViewById(R.id.tv_save_cover);
        Drawable radiusDrawable = DrawableUitls.getRadiusDrawable(getResources().getDimensionPixelSize(R.dimen.dp_px_24)
                , getResources().getColor(R.color.red_ff365));
        mSaveAlbum.setBackground(radiusDrawable);
        mSaveCover.setBackground(radiusDrawable);

        initListener();
        config();
    }

    private void config() {
        NvModuleManager nvModuleManager = NvModuleManager.get();
        int globalBackgroundColor = nvModuleManager.getGlobalBackgroundColor();
        if (globalBackgroundColor != 0) {
            nvModuleManager.setGlobalBackgroundColor(findViewById(R.id.publish_edit_content));
            RoundBoundView roundBoundView = findViewById(R.id.publish_round_bound);
            roundBoundView.setBoundColor(globalBackgroundColor);
        }
        int radius = SizeUtils.dp2px(8);
        nvModuleManager.setPrimaryColor(mSaveAlbum,radius);
        nvModuleManager.setPrimaryColor(mSaveCover,radius);
    }

    @Override
    protected void initData(Bundle savedInstanceState) {
        Intent intent = getIntent();
        if (intent != null) {
            Bundle extras = intent.getExtras();
            if (extras != null) {
                mCanSaveCover = extras.getBoolean(INTENT_KEY_CAN_SAVE_COVER);
                mCanSaveDraft = extras.getBoolean(INTENT_KEY_CAN_SAVE_DRAFT);
                mCanSaveVideo = extras.getBoolean(INTENT_KEY_CAN_SAVE_VIDEO);
            }
        }
        mSaveDaft.setVisibility(mCanSaveDraft ? View.VISIBLE : View.GONE);
        mSaveCover.setVisibility(mCanSaveCover ? View.VISIBLE : View.GONE);
        mSaveAlbum.setVisibility(mCanSaveVideo ? View.VISIBLE : View.GONE);
        initUploadData();
    }

    private void initUploadData() {
        mTimeline = EditorEngine.getInstance().getCurrentTimeline();
        setVideoCover();
    }

    private void setVideoCover() {
        if (mTimeline == null) {
            LogUtils.e("Timeline is null!");
            return;
        }
        String coverImagePath = mTimeline.getCoverImagePath();
        if (TextUtils.isEmpty(coverImagePath)) {//默认使用第0帧
            mCoverView.setImageBitmap(CaptureAndEditUtil.getImageFromTime(mTimeline, 0));
        } else {
            if (mCoverBitmap != null && !mCoverBitmap.isRecycled()) {
                mCoverBitmap.recycle();
            }
            mCoverBitmap = BitmapFactory.decodeFile(coverImagePath);
            if (mCoverBitmap != null) {
                mCoverView.setImageBitmap(mCoverBitmap);
            }
        }
    }


    @Override
    public void onBackPressed() {
        super.onBackPressed();
    }

    private void saveDraftToLocal() {
        String videoDesc = mEditTextView.getText().toString();
        showProgress();
        NvModuleManager.get().saveDraft(videoDesc, mCoverPoint, new DraftManager.DraftSaveCallBack() {
            @Override
            public void onSaveSuccess(boolean isNew) {
                hideProgress();
                if (isNew) {
                    saveDraftFinish();
                } else {
                    if (!isFinishing()) {
                        AppManager.getInstance().finishEditActivityWidthOut(UIConfig.get().getDraftActivity());
                    }
                }
                NvModuleManager.get().publishWithInfo(PublishActivity.this, true, true, true,null);
            }
        });
    }

    private void saveDraftFinish() {
        if (!isFinishing()) {
            NvModuleManager.get().finishPublish(this, UIConfig.get().getMainActivity());
        }
    }

    @Override
    public void onClick(View v) {
        int id = v.getId();
        if (id == R.id.tv_save_draft) {
            saveDraftToLocal();
        } else if (id == R.id.tv_save_cover) {
            doSaveCover(mCoverPoint);
        } else if (id == R.id.tv_save_album) {
            saveDraftToLocal();
            //doSaveAlbum();
        } else if (id == R.id.backBtn) {
            AppManager.getInstance().finishActivity();
        } else if (id == R.id.iv_cover) {
            doEditCover();
        }
    }

    private void doEditCover() {
        NvModuleManager.editCover(this, mCoverPoint, REQUEST_EDIT_COVER);
    }

    private void doSaveAlbum() {
        showProgress();
        NvModuleManager.saveVideoToAlbum(new NvModuleManager.OnCompileVideoListener() {
            @Override
            public void compileProgress(NvsTimeline timeline, int progress) {
            }

            @Override
            public void compileFinished(NvsTimeline timeline) {
                hideProgress();
            }

            @Override
            public void compileFailed(NvsTimeline timeline) {
                hideProgress();
                ToastUtil.showToast(PublishActivity.this, R.string.save_video_failed_hint);
            }

            @Override
            public void compileCompleted(NvsTimeline nvsTimeline, String compileVideoPath, boolean isCanceled) {
                if (!isCanceled) {
                    ToastUtil.showToast(Utils.getApp(), R.string.save_video_success_hint);
                }
                hideProgress();
            }

            @Override
            public void compileVideoCancel() {
                hideProgress();
            }

            @Override
            public void onCompileCompleted(boolean isHardwareEncoder, int errorType, String stringInfo, int flags) {
                hideProgress();
            }
        });
    }

    private void doSaveCover(long coverTime) {
        showProgress();
        boolean result = NvModuleManager.get().saveCover(PathUtils.getCoverDir(), String.valueOf(System.currentTimeMillis()), coverTime, true, new NvModuleManager.OnCoverSavedCallBack() {
            @Override
            public void onCoverSaved(String path) {
                hideProgress();
                ToastUtil.showToast(PublishActivity.this, R.string.save_cover_success_hint);
            }

            @Override
            public void onCoverSaveFailed() {
                ToastUtil.showToast(PublishActivity.this, R.string.save_cover_failed_hint);
                hideProgress();
            }
        });
        if (!result) {
            ToastUtil.showToast(PublishActivity.this, R.string.save_cover_failed_hint);
        }
    }

    private void showProgress() {
        if (mLoadingPop == null) {
            mLoadingPop = LoadingPop.create(this, LoadingPop.LOADING_STYLE_COMMON);
        }
        mLoadingPop.show();
    }

    private void hideProgress() {
        if (mLoadingPop != null) {
            mLoadingPop.dismiss();
        }
    }
}
