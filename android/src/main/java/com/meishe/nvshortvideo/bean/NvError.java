package com.meishe.nvshortvideo.bean;

import java.io.Serializable;

/**
 * All rights Reserved, Designed By www.meishesdk.com
 *
 * @Author: LiFei
 * @CreateDate: 2024/5/17 15:27
 * @Description:
 * @Copyright: www.meishesdk.com Inc. All rights reserved.
 */
public class NvError implements Serializable {
    private int code;
    private String message;

    public NvError() {
    }

    public NvError(int code, String message) {
        this.code = code;
        this.message = message;
    }

    public int getCode() {
        return code;
    }

    public void setCode(int code) {
        this.code = code;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }
}
