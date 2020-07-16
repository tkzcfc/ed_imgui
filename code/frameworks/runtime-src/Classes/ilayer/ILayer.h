#pragma once

#include "cocos2d.h"
#include "imgui.h"
#include "IRender.h"
#include "lua_function/LuaFunction.h"
#include "lua_function/LuaFunctionBond.h"


USING_NS_CC;

class ILayer : public cocos2d::Layer, public IMEDelegate, public LuaFunctionBond
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init() override;

	virtual void visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags) override;

	void onDraw();

	// implement the "static create()" method manually
	CREATE_FUNC(ILayer);

	virtual void onEnter()override;

	virtual void onExit()override;


	void updateImGUI();

	void addImGUI(const std::function<void()>& imGUICall, std::string name) { m_callPiplines[name] = std::move(imGUICall); };
	
	void removeImGUI(std::string name);

	bool setChineseFont(const std::string& fontFileName, float size_pixels);

	// simfang.ttf 18.0f
	bool setSystemChineseFont(const std::string& fontFileName, float size_pixels);

	bool IsAnyWindowHovered();

	void setEngulfAllTouchs(bool value);

	bool isEngulfAllTouchs();

	void setDrawDefaultWindow(bool draw);

	void setDefaultWindowFlags(ImGuiWindowFlags flags);

	void setGUIBeginCall(const std::function<void()>& call);

	void setGUIEndCall(const std::function<void()>& call);

protected:

	virtual void update(float delta)override;

	/// TextFieldDelegate
	virtual void insertText(const char * text, size_t len) override;
	virtual bool canAttachWithIME() { return true; }
	virtual bool canDetachWithIME() { return true; }

protected:
	void ImGui_ImplGlfw_UpdateMousePosAndButtons();
	void ImGui_ImplGlfw_UpdateMouseCursor();
	void ImGui_ImplGlfw_UpdateGamepads();

	void ImGui_ImplGlfw_NewFrame();

protected:

	int getKey(cocos2d::EventKeyboard::KeyCode code);

private:
	CustomCommand _command;
	ImGuiContext* m_context;


	GLFWwindow*          g_Window = NULL;    // Main window
	double               g_Time = 0.0;
	bool                 g_MouseJustPressed[5] = { false, false, false, false, false };
	//GLFWcursor*          g_MouseCursors[ImGuiMouseCursor_COUNT] = { 0 };
	
	ImVec2               g_CursorPos = ImVec2(-FLT_MAX, -FLT_MAX);

	IRender* irender = NULL;
	GLView* m_glView = NULL;

	std::map<std::string, std::function<void()>> m_callPiplines;

	bool m_drawFinish = false;

	bool m_engulfAllTouchs = false;

	bool m_drawDefaultWindow = false;

	ImGuiWindowFlags m_defaultWindowFlags = 0;

	std::function<void()> m_beginCall = nullptr;
	std::function<void()> m_endCall = nullptr;

};