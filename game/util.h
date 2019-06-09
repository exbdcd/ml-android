#pragma once

uintptr_t GetTexture(const char* texture);
uintptr_t LoadTextureFromDB(const char* dbname, const char* texture);
void DefinedState2d();
void SetScissorRect(void* pRect);
float DegToRad(float fDegrees);
float FloatOffset(float f1, float f2);