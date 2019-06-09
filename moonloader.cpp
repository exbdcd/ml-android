#include "main.h"
#include "gui/gui.h"
#include "imgui/imgui_internal.h"
#include "moonloader.h"
#include <stdlib.h>
#include <string.h>

extern CGUI *pGUI;

CMoonLoader::CMoonLoader()
{
	m_bIsActive = false;
}

CMoonLoader::~CMoonLoader()
{
    // Nothing...
}

void CMoonLoader::Show(bool bShow)
{
    char* script_name;
	m_bIsActive = bShow;
}

void CMoonLoader::Clear()
{
	m_bIsActive = false;
}

bool CMoonLoader::ExecuteMoonScript(char* scriptName)
{
    // finish it..
    return false;
}

void CMoonLoader::AddScripts()
{
    // finish it..
}

void CMoonLoader::Render()
{
	if(!m_bIsActive)return;

    ImGuiIO &io = ImGui::GetIO();

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(8, 8));

    ImGui::Begin("Moon Loader Scripts", nullptr, 
        ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
    // -------------------------------------------------------------------------------------------------------- //

    AddScripts();

    // -------------------------------------------------------------------------------------------------------- //
    ImGui::SetWindowSize(ImVec2(-8, -8));
    ImVec2 size = ImGui::GetWindowSize();
    ImGui::SetWindowPos( ImVec2( ( (io.DisplaySize.x - size.x) / 2), ( ( io.DisplaySize.y - size.y ) / 2) ) );
    ImGui::End();
    ImGui::PopStyleVar();
}