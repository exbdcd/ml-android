#pragma once

#include <cstdlib>
#include <string>
#include <vector>
#include <list>
#include <unistd.h>
#include <jni.h>

#define RAKSAMP_CLIENT
#define NETCODE_CONNCOOKIELULZ 0x6969

#include "RakNet/SAMP/samp_netencr.h"
#include "RakNet/SAMP/SAMPRPC.h"

extern uintptr_t g_libGTASA;
extern uintptr_t g_libSAMP;

extern const char* g_pszStorage;