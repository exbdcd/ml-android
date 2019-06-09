#pragma once

#include <jni.h>

#define JNI_OK = 1; // ???

JNIEnv* getJniEnv(JavaVM *vm);
bool Jni_Load(const char * libPath)