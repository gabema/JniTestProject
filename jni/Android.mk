LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := jnitestproject
LOCAL_SRC_FILES := \
 AwesomeTester.cpp \
 AwesomeTesterJni.cpp \
 JniUtility.cpp

LOCAL_CFLAGS := -std=c++11

include $(BUILD_SHARED_LIBRARY)
