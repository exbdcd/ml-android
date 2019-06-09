#include "../main.h"

#define PI 3.14159265

uintptr_t GetTexture(const char* texture)
{
	return (( uintptr_t (*)(const char*))(g_libGTASA+0x258910+1))(texture);
}

uintptr_t LoadTextureFromDB(const char* dbname, const char* texture)
{
	uintptr_t db_handle = (( uintptr_t (*)(const char*))(g_libGTASA+0x1BF530+1))(dbname);
	if(!db_handle)return 0;

	(( void (*)(uintptr_t))(g_libGTASA+0x1BE898+1))(db_handle);
	uintptr_t tex = GetTexture(texture);

	(( void (*)(uintptr_t))(g_libGTASA+0x1BE938+1))(db_handle);

	return tex;
}

void DefinedState2d()
{
	return (( void (*)())(g_libGTASA+0x5590B0+1))();
}

void SetScissorRect(void* pRect)
{
}

float DegToRad(float fDegrees)
{
    if (fDegrees > 360.0f || fDegrees < 0.0f) return 0.0f;
    
    if (fDegrees > 180.0f) return (float)(-(PI - (((fDegrees - 180.0f) * PI) / 180.0f)));
    else return (float)((fDegrees * PI) / 180.0f);
}

// 0.3.7
float FloatOffset(float f1, float f2)
{   
    if(f1 >= f2) return f1 - f2;
    else return (f2 - f1);
}