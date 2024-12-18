package com.meishe.nvshortvideo.bean;

/**
 * All rights Reserved, Designed By www.meishesdk.com
 *
 * @Author: LiFei
 * @CreateDate: 2024/5/17 15:26
 * @Description:
 * @Copyright: www.meishesdk.com Inc. All rights reserved.
 */
public interface OnMethodCallListener {
    void completion(Object response, NvError error);
}
