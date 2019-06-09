#include <android/log.h>
#include <ucontext.h>
#include <pthread.h>

#include "main.h"
#include "JniUtils.h"
#include "util.h"
#include "gui/gui.h"
#include "moonloader.h"

// ----------------------------------------------

uintptr_t g_libGTASA = 0;
uintptr_t g_libSAMP = 0;

const char* g_pszStorage = nullptr;

CGUI *pGUI = nullptr;
CMoonLoader *pMoonLoader = nullptr;

void InitRenderWareFunctions();
void MainLoop();

// ----------------------------------------------


void MainLoop(){
	g_pszStorage = (const char*)(g_libGTASA+0x63C4B8);
	pGUI = new CGUI();

	pMoonLoader = new CMoonLoader();
}

void handler(int signum, siginfo_t *info, void* contextPtr)
{
	ucontext* context = (ucontext_t*)contextPtr;
	if(info->si_signo == SIGSEGV)exit(0);

	return;
}

void *Init(void *p)
{
	pthread_exit(0);
}

jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
	JNIEnv* p_JNIEnv;
	p_JNIEnv = getJniEnv(vm);
	if(!p_JNIEnv)
		return NULL;
	
	if(!Jni_Load(p_JNIEnv, "/data/data/com.rockstargames.gtasa/lib/libsamp_orig.so"))
		return NULL;
	
	g_libGTASA = FindLibrary("libGTASA.so");
	uintptr_t g_libSAMP = FindLibrary("libsamp_orig.so");
	
	if(g_libGTASA == 0 || g_libSAMP )
		return 0;

	srand(time(0));

	InitRenderWareFunctions();

	pthread_t thread;
	pthread_create(&thread, 0, Init, 0);

	struct sigaction act;
	act.sa_sigaction = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGSEGV, &act, 0);

	return JNI_VERSION_1_4;
}