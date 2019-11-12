#pragma once

#include "cocos2d.h"
#include "imgui.h"

class IRender
{
public:


	bool     ImGui_ImplOpenGL3_Init(const char* glsl_version = NULL);
	void     ImGui_ImplOpenGL3_Shutdown();
	void     ImGui_ImplOpenGL3_NewFrame();
	void     ImGui_ImplOpenGL3_RenderDrawData(ImDrawData* draw_data, const float* pMatrix = NULL);

	// Called by Init/NewFrame/Shutdown
	bool     ImGui_ImplOpenGL3_CreateFontsTexture();
	void     ImGui_ImplOpenGL3_DestroyFontsTexture();
	bool     ImGui_ImplOpenGL3_CreateDeviceObjects();
	void     ImGui_ImplOpenGL3_DestroyDeviceObjects();

protected:
	void ImGui_ImplOpenGL3_SetupRenderState(ImDrawData* draw_data, int fb_width, int fb_height, GLuint vertex_array_object, const float* pMatrix);
	bool CheckShader(GLuint handle, const char* desc);
	bool CheckProgram(GLuint handle, const char* desc);

protected:

	// OpenGL Data
	char         g_GlslVersionString[32] = "";
	GLuint       g_FontTexture = 0;
	GLuint       g_ShaderHandle = 0, g_VertHandle = 0, g_FragHandle = 0;
	int          g_AttribLocationTex = 0, g_AttribLocationProjMtx = 0;                                // Uniforms location
	int          g_AttribLocationVtxPos = 0, g_AttribLocationVtxUV = 0, g_AttribLocationVtxColor = 0; // Vertex attributes location
	unsigned int g_VboHandle = 0, g_ElementsHandle = 0;
};
