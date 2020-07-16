#pragma once

#include "cocos2d.h"
#include "ilayer/ILayer.h"
#include "lua_function/LuaFunctionBond.h"

USING_NS_CC;

class EditorContext : public Node, public LuaFunctionBond
{
public:

	EditorContext();

	virtual ~EditorContext();

	virtual bool init()override;

	CREATE_FUNC(EditorContext);

	ILayer* getIlayer();

	Node* getBackgroundNode();

	float getLeftPaneWidth() { return m_leftPaneWidth; }
	float getCenterPaneWidth() { return m_centerPaneWidth; }
	float getRightPaneWidth() { return m_rightPaneWidth; }

	float getTopPanelHeight() { return m_topPanelHeight; }
	float getBottomPanelHeight() { return m_bottomPanelHeight; }
	float getCenterPaneHeight() { return m_centerPaneHeight; }

	float getSplitterThickness();

private:

	void initGUI();

	void onGUI();

	void callLuaGUI(const char* name);

	static bool splitter(const char* sp_name, bool split_vertically, float thickness, float* size1, float* size2, float min_size1, float min_size2, float splitter_long_axis_size = -1.0f);

private:
	ILayer* m_iLayer;

	Node* m_backgroundNode;

	float m_leftPaneWidth;
	float m_centerPaneWidth;
	float m_rightPaneWidth;

	float m_topPanelHeight;
	float m_bottomPanelHeight;
	float m_centerPaneHeight;

	float m_rightPaneWidthTmp;
	float m_bottomPaneWidthTmp;

	bool m_initGUITag;
};
