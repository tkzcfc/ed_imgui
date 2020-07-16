#include "EditorContext.h"
#include "imgui/imgui_internal.h"
#include "core/Tools.h"
#include "ui/CocosGUI.h"


// Á½²àÃæ°å·¶Î§
static float bothSidesPanelMinWidth = 50.0f;
static float bothSidesPanelMaxWidth = 350.0f;

static float topPanelMinHeight = 50.0f;
static float topPanelMaxHeight = 200.0f;

static float bottomPanelMinHeight = 50.0f;
static float bottomPanelMaxHeight = 400.0f;

constexpr static float thickness = 4.0f;

static constexpr char* backgroundImageResource = "bg.jpg";

EditorContext::EditorContext()
	: m_iLayer(NULL)
	, m_backgroundNode(NULL)
	, m_initGUITag(false)
	, m_leftPaneWidth(0.0f)
	, m_centerPaneWidth(0.0f)
	, m_rightPaneWidth(0.0f)
	, m_topPanelHeight(0.0f)
	, m_bottomPanelHeight(0.0f)
	, m_centerPaneHeight(0.0f)
	, m_rightPaneWidthTmp(0.0f)
	, m_bottomPaneWidthTmp(0.0f)
{}

EditorContext::~EditorContext()
{
	TextureCache::getInstance()->unbindImageAsync(backgroundImageResource);
}

bool EditorContext::init()
{
	if (!Node::init())
	{
		return false;
	}

	TextureCache::getInstance()->addImageAsync(backgroundImageResource, [=](Texture2D* texture)
	{
		if (texture == NULL)
		{
			return;
		}
		auto backgroundImage = ui::ImageView::create();
		backgroundImage->loadTexture(backgroundImageResource, ui::Widget::TextureResType::LOCAL);
		//backgroundImage->ignoreContentAdaptWithSize(false);
		//backgroundImage->setOpacity(200);
		backgroundImage->setPosition(Director::getInstance()->getWinSize() * 0.5f);
		backgroundImage->setContentSize(Director::getInstance()->getWinSize());
		m_backgroundNode->addChild(backgroundImage);
	});

	m_backgroundNode = Node::create();
	this->addChild(m_backgroundNode, -2);
	
	m_iLayer = ILayer::create();
	m_iLayer->setDrawDefaultWindow(false);
	m_iLayer->setGUIBeginCall([=]() 
	{
		ImGuiIO& io = ImGui::GetIO();

		ImGuiWindowFlags flags = ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_MenuBar;

		ImGui::SetNextWindowPos(ImVec2(0, 0));
		ImGui::SetNextWindowSize(io.DisplaySize);
		ImGui::Begin("Content", nullptr, ImVec2(0, 0), 0.0f, flags);
	});
	m_iLayer->setGUIEndCall([]() 
	{
		ImGui::End();
	});
	this->addChild(m_iLayer, 1);

	m_iLayer->addImGUI(std::bind(&EditorContext::onGUI, this), "contextGUI");

	return true;
}

ILayer* EditorContext::getIlayer()
{
	return m_iLayer;
}

Node* EditorContext::getBackgroundNode()
{
	return m_backgroundNode;
}

void EditorContext::initGUI()
{
	if(m_initGUITag)
	{
		return;
	}
	m_initGUITag = true;

	auto& io = ImGui::GetIO();

	float DefaultWidth = 250.0f;

	m_leftPaneWidth = DefaultWidth;
	m_centerPaneWidth = 0;
	m_rightPaneWidth = DefaultWidth;

	m_topPanelHeight = topPanelMinHeight;
	m_bottomPanelHeight = 200.0f;

	m_rightPaneWidthTmp = std::fabs(bothSidesPanelMaxWidth - m_leftPaneWidth);
	m_bottomPaneWidthTmp = std::fabs(topPanelMaxHeight - m_topPanelHeight);
}

void EditorContext::onGUI()
{
	initGUI();

	// bar
	if (ImGui::BeginMenuBar())
	{
		callLuaGUI("onGUI_MenuBar");
		ImGui::EndMenuBar();
	}

	splitter("##Splitter_L_R", true, thickness, &m_leftPaneWidth, &m_rightPaneWidthTmp, bothSidesPanelMinWidth, 0.0f);

	if (ImGui::BeginChild("context_left", ImVec2(m_leftPaneWidth - thickness, 0), true))
	{
		callLuaGUI("onGUI_Left");
		ImGui::EndChild();
	}

	//ImGui::SameLine(0.0f, 12.0f);
	ImGui::SameLine();

	if (ImGui::BeginChild("context_right_all", ImVec2(0, 0)))
	{
		m_centerPaneWidth = ImGui::GetContentRegionAvailWidth() - m_rightPaneWidth;
		splitter("##Splitter_C_R", true, thickness, &m_centerPaneWidth, &m_rightPaneWidth, ImGui::GetContentRegionAvailWidth() - bothSidesPanelMaxWidth, bothSidesPanelMinWidth);

		if (ImGui::BeginChild("context_center_all", ImVec2(m_centerPaneWidth, 0)))
		{
			splitter("##Splitter_T_B", false, thickness, &m_topPanelHeight, &m_bottomPaneWidthTmp, topPanelMinHeight, 0);
			if (ImGui::BeginChild("context_top", ImVec2(0, m_topPanelHeight), true))
			{
				callLuaGUI("onGUI_Top");
				ImGui::EndChild();
			}

			auto avali = ImGui::GetContentRegionAvail();
			m_centerPaneHeight = avali.y - m_bottomPanelHeight;
			splitter("##Splitter_C_B", false, thickness, &m_centerPaneHeight, &m_bottomPanelHeight, avali.y - bottomPanelMaxHeight, bottomPanelMinHeight);
			if (ImGui::BeginChild("context_center", ImVec2(0, m_centerPaneHeight), false, ImGuiWindowFlags_NoBackground))
			{
				callLuaGUI("onGUI_Center");
				ImGui::EndChild();
			}

			if (ImGui::BeginChild("context_bottom", ImVec2(0, 0)))
			{
				callLuaGUI("onGUI_Bottom");
				ImGui::EndChild();
			}

			ImGui::EndChild();
		}

		//ImGui::SameLine(0.0f, 12.0f);
		ImGui::SameLine();

		if (ImGui::BeginChild("context_right", ImVec2(0, 0), true))
		{
			callLuaGUI("onGUI_Right");
			ImGui::EndChild();
		}

		ImGui::EndChild();
	}
}

void EditorContext::callLuaGUI(const char* name)
{
	auto handle = this->getLuaHandle(name);
	if (handle && handle->isvalid())
	{
		handle->ppush();
		handle->pcall();
	}
}


float EditorContext::getSplitterThickness()
{
	return thickness;
}

bool EditorContext::splitter(const char* sp_name, bool split_vertically, float thickness, float* size1, float* size2, float min_size1, float min_size2, float splitter_long_axis_size)
{
	ImGuiContext* g = ImGui::GetCurrentContext();
	ImGuiWindow* window = g->CurrentWindow;
	ImGuiID id = window->GetID(sp_name);
	ImRect bb;
	bb.Min = window->DC.CursorPos + (split_vertically ? ImVec2(*size1, 0.0f) : ImVec2(0.0f, *size1));
	bb.Max = bb.Min + ImGui::CalcItemSize(split_vertically ? ImVec2(thickness, splitter_long_axis_size) : ImVec2(splitter_long_axis_size, thickness), 0.0f, 0.0f);
	return ImGui::SplitterBehavior(bb, id, split_vertically ? ImGuiAxis_X : ImGuiAxis_Y, size1, size2, min_size1, min_size2, 0.0f);
}
