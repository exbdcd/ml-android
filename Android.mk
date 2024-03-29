LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := samp
LOCAL_LDLIBS := -llog

FILE_LIST := $(wildcard $(LOCAL_PATH)/*.cpp)

FILE_LIST += $(wildcard $(LOCAL_PATH)/raknet/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/raknet/SAMP/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/RW/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/imgui/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/gui/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/game/*.cpp)

LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_CPPFLAGS := -w -s -fvisibility=hidden -pthread -Wall -fpack-struct=1 -O2 -std=c++14 -fexceptions
include $(BUILD_SHARED_LIBRARY)