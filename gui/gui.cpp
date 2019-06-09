#include "main.h"
#include "gui.h"

#include "../moonloader.h"
#include "../RW/RenderWare.h"

#include <time.h>
#include <ctime>
#include <stdio.h>
#include <string.h>

extern CMoonLoader *pMoonLoader;

void ImGui_ImplRenderWare_RenderDrawData(ImDrawData* draw_data);
bool ImGui_ImplRenderWare_Init();
void ImGui_ImplRenderWare_NewFrame();
void ImGui_ImplRenderWare_ShutDown();

#define MULT_X	0.00052083333f	// 1920
#define MULT_Y	0.00092592592f 	// 1080

CGUI::CGUI()
{

	/* setup ImGUI */
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO &io = ImGui::GetIO();

	ImGui_ImplRenderWare_Init();

	/* scale */
	m_vecScale.x = io.DisplaySize.x * MULT_X;
	m_vecScale.y = io.DisplaySize.y * MULT_Y;

	/* font Size */
	m_fFontSize = ScaleY(30.0);

	/* mouse/touch */
	m_bMousePressed = false;
	m_vecMousePos = ImVec2(0, 0);

	/* setup style */
	ImGuiStyle& style = ImGui::GetStyle();
	style.ScrollbarSize = ScaleY(35.0f);
	style.WindowBorderSize = 0.0f;
	ImGui::StyleColorsClassic();

	/* cp1251 ranges */
	static const ImWchar ranges[] = 
	{
		0x0020, 0x0080,
		0x00A0, 0x00C0,
		0x0400, 0x0460,
		0x0490, 0x04A0,
		0x2010, 0x2040,
		0x20A0, 0x20B0,
		0x2110, 0x2130,
		0
	};
}

CGUI::~CGUI()
{
	ImGui_ImplRenderWare_ShutDown();
	ImGui::DestroyContext();
}

void CGUI::Render()
{
	ImGuiIO& io = ImGui::GetIO();

	ImGui_ImplRenderWare_NewFrame();
	ImGui::NewFrame();

	if(pMoonLoader) pMoonLoader->Render();

	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplRenderWare_RenderDrawData(ImGui::GetDrawData());

	if(m_bNeedClearMousePos)
	{
		io.MousePos = ImVec2(-1, -1);
		m_bNeedClearMousePos = false;
	}
}

bool CGUI::OnTouchEvent(int type, bool multi, int x, int y)
{
	ImGuiIO& io = ImGui::GetIO();

	switch(type)
	{
		case TOUCH_PUSH:
		io.MousePos = ImVec2(x, y);
		io.MouseDown[0] = true;
		break;

		case TOUCH_POP:
		io.MouseDown[0] = false;
		m_bNeedClearMousePos = true;
		break;

		case TOUCH_MOVE:
		io.MousePos = ImVec2(x, y);
		break;
	}

	return true;
}