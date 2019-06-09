#pragma once

#include "main.h"

class CMoonLoader
{

public:
	CMoonLoader();
	~CMoonLoader();

	void Render();
	void Clear();
	void Show(bool bShow);

	bool ExecuteMoonScript(char* scriptName);
	void AddScripts();

public:
	bool		m_bIsActive;

};