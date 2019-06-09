#include "main.h"
#include "jni.h" 
#include <jni.h>

JNIEnv* g_JNIEnv;
 
JNIEnv* getJniEnv(JavaVM *vm)
{
    JavaVMAttachArgs attachArgs;
    attachArgs.version = JNI_VERSION_1_4;
    attachArgs.name = "no_more_anime_jokes"; // ???
    attachArgs.group = NULL;
 
    JNIEnv* env;
    if (vm->AttachCurrentThread(&env, &attachArgs) != JNI_OK)env = NULL;
   
    return env;
}
 
bool Jni_Load(const char * libPath)
{
    //LOGI("Jni_Load %s", libPath);
    jclass sysClass = g_JNIEnv->FindClass("java/lang/System");
 
    if (!sysClass)
    {
        //LOGE("[Jni_Load] sysClass is NULL!");
        return false;
    }
 
    jmethodID loadMethod = g_JNIEnv->GetStaticMethodID(sysClass, "load", "(Ljava/lang/String;)V");
    jstring jStr = g_JNIEnv->NewStringUTF(libPath);
    g_JNIEnv->CallStaticByteMethod(sysClass, loadMethod, jStr);
    return true;
}