LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2djs_shared

LOCAL_MODULE_FILENAME := libcocos2djs

LOCAL_SRC_FILES := hellojavascript/main.cpp \
					../../Classes/AppDelegate.cpp \
					../../Classes/PluginSdkboxAdsJS.cpp \
					../../Classes/PluginSdkboxAdsJS.hpp \
					../../Classes/PluginSdkboxAdsJSHelper.cpp \
					../../Classes/PluginSdkboxAdsJSHelper.h \
					../../Classes/SDKBoxJSHelper.cpp \
					../../Classes/SDKBoxJSHelper.h

LOCAL_LDLIBS := -landroid -llog
LOCAL_CPPFLAGS := -DSDKBOX_ENABLED
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes
LOCAL_WHOLE_STATIC_LIBRARIES := PluginAdColony PluginFyber PluginSdkboxAds sdkbox

LOCAL_STATIC_LIBRARIES := cocos2d_js_static

include $(BUILD_SHARED_LIBRARY)
$(call import-add-path,$(LOCAL_PATH))

$(call import-module, scripting/js-bindings/proj.android/prebuilt-mk)
$(call import-module, ./sdkbox)
$(call import-module, ./pluginsdkboxads)
$(call import-module, ./pluginfyber)
$(call import-module, ./pluginadcolony)