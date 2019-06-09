#include "main.h"

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
 
bool Jni_Load(JNIEnv* p, const char * libPath)
{
    //LOGI("Jni_Load %s", libPath);
    jclass sysClass = p->FindClass("java/lang/System");
 
    if (!sysClass)
    {
        //LOGE("[Jni_Load] sysClass is NULL!");
        return false;
    }
 
    jmethodID loadMethod = p->GetStaticMethodID(sysClass, "load", "(Ljava/lang/String;)V");
    jstring jStr = p->NewStringUTF(libPath);
    p->CallStaticByteMethod(sysClass, loadMethod, jStr);
    return true;
}