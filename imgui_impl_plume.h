#pragma once
#include <plume_render_interface.h>
#include <imgui.h>

struct ImGui_ImplPlume_InitInfo {
	plume::RenderInterface* interface;
	plume::RenderDevice* device;
};

bool ImGui_ImplPlume_Init(ImGui_ImplPlume_InitInfo& info);
bool ImGui_ImplPlume_CreateFontsTexture();
void ImGui_ImplPlume_RenderDrawData(ImDrawData* draw_data, plume::RenderCommandList* cmdList);
void ImGui_ImplPlume_Shutdown();
