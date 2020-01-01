#include "ILayer.h"
#include "imgui.h"



struct keyCodeItem
{
	int glfwKeyCode;
	EventKeyboard::KeyCode keyCode;
};

static keyCodeItem g_keyCodeStructArray[] = {
	/* The unknown key */
	{ GLFW_KEY_UNKNOWN         , EventKeyboard::KeyCode::KEY_NONE },

	/* Printable keys */
	{ GLFW_KEY_SPACE           , EventKeyboard::KeyCode::KEY_SPACE },
	{ GLFW_KEY_APOSTROPHE      , EventKeyboard::KeyCode::KEY_APOSTROPHE },
	{ GLFW_KEY_COMMA           , EventKeyboard::KeyCode::KEY_COMMA },
	{ GLFW_KEY_MINUS           , EventKeyboard::KeyCode::KEY_MINUS },
	{ GLFW_KEY_PERIOD          , EventKeyboard::KeyCode::KEY_PERIOD },
	{ GLFW_KEY_SLASH           , EventKeyboard::KeyCode::KEY_SLASH },
	{ GLFW_KEY_0               , EventKeyboard::KeyCode::KEY_0 },
	{ GLFW_KEY_1               , EventKeyboard::KeyCode::KEY_1 },
	{ GLFW_KEY_2               , EventKeyboard::KeyCode::KEY_2 },
	{ GLFW_KEY_3               , EventKeyboard::KeyCode::KEY_3 },
	{ GLFW_KEY_4               , EventKeyboard::KeyCode::KEY_4 },
	{ GLFW_KEY_5               , EventKeyboard::KeyCode::KEY_5 },
	{ GLFW_KEY_6               , EventKeyboard::KeyCode::KEY_6 },
	{ GLFW_KEY_7               , EventKeyboard::KeyCode::KEY_7 },
	{ GLFW_KEY_8               , EventKeyboard::KeyCode::KEY_8 },
	{ GLFW_KEY_9               , EventKeyboard::KeyCode::KEY_9 },
	{ GLFW_KEY_SEMICOLON       , EventKeyboard::KeyCode::KEY_SEMICOLON },
	{ GLFW_KEY_EQUAL           , EventKeyboard::KeyCode::KEY_EQUAL },
	{ GLFW_KEY_A               , EventKeyboard::KeyCode::KEY_A },
	{ GLFW_KEY_B               , EventKeyboard::KeyCode::KEY_B },
	{ GLFW_KEY_C               , EventKeyboard::KeyCode::KEY_C },
	{ GLFW_KEY_D               , EventKeyboard::KeyCode::KEY_D },
	{ GLFW_KEY_E               , EventKeyboard::KeyCode::KEY_E },
	{ GLFW_KEY_F               , EventKeyboard::KeyCode::KEY_F },
	{ GLFW_KEY_G               , EventKeyboard::KeyCode::KEY_G },
	{ GLFW_KEY_H               , EventKeyboard::KeyCode::KEY_H },
	{ GLFW_KEY_I               , EventKeyboard::KeyCode::KEY_I },
	{ GLFW_KEY_J               , EventKeyboard::KeyCode::KEY_J },
	{ GLFW_KEY_K               , EventKeyboard::KeyCode::KEY_K },
	{ GLFW_KEY_L               , EventKeyboard::KeyCode::KEY_L },
	{ GLFW_KEY_M               , EventKeyboard::KeyCode::KEY_M },
	{ GLFW_KEY_N               , EventKeyboard::KeyCode::KEY_N },
	{ GLFW_KEY_O               , EventKeyboard::KeyCode::KEY_O },
	{ GLFW_KEY_P               , EventKeyboard::KeyCode::KEY_P },
	{ GLFW_KEY_Q               , EventKeyboard::KeyCode::KEY_Q },
	{ GLFW_KEY_R               , EventKeyboard::KeyCode::KEY_R },
	{ GLFW_KEY_S               , EventKeyboard::KeyCode::KEY_S },
	{ GLFW_KEY_T               , EventKeyboard::KeyCode::KEY_T },
	{ GLFW_KEY_U               , EventKeyboard::KeyCode::KEY_U },
	{ GLFW_KEY_V               , EventKeyboard::KeyCode::KEY_V },
	{ GLFW_KEY_W               , EventKeyboard::KeyCode::KEY_W },
	{ GLFW_KEY_X               , EventKeyboard::KeyCode::KEY_X },
	{ GLFW_KEY_Y               , EventKeyboard::KeyCode::KEY_Y },
	{ GLFW_KEY_Z               , EventKeyboard::KeyCode::KEY_Z },
	{ GLFW_KEY_LEFT_BRACKET    , EventKeyboard::KeyCode::KEY_LEFT_BRACKET },
	{ GLFW_KEY_BACKSLASH       , EventKeyboard::KeyCode::KEY_BACK_SLASH },
	{ GLFW_KEY_RIGHT_BRACKET   , EventKeyboard::KeyCode::KEY_RIGHT_BRACKET },
	{ GLFW_KEY_GRAVE_ACCENT    , EventKeyboard::KeyCode::KEY_GRAVE },
	{ GLFW_KEY_WORLD_1         , EventKeyboard::KeyCode::KEY_GRAVE },
	{ GLFW_KEY_WORLD_2         , EventKeyboard::KeyCode::KEY_NONE },

	/* Function keys */
	{ GLFW_KEY_ESCAPE          , EventKeyboard::KeyCode::KEY_ESCAPE },
	{ GLFW_KEY_ENTER           , EventKeyboard::KeyCode::KEY_ENTER },
	{ GLFW_KEY_TAB             , EventKeyboard::KeyCode::KEY_TAB },
	{ GLFW_KEY_BACKSPACE       , EventKeyboard::KeyCode::KEY_BACKSPACE },
	{ GLFW_KEY_INSERT          , EventKeyboard::KeyCode::KEY_INSERT },
	{ GLFW_KEY_DELETE          , EventKeyboard::KeyCode::KEY_DELETE },
	{ GLFW_KEY_RIGHT           , EventKeyboard::KeyCode::KEY_RIGHT_ARROW },
	{ GLFW_KEY_LEFT            , EventKeyboard::KeyCode::KEY_LEFT_ARROW },
	{ GLFW_KEY_DOWN            , EventKeyboard::KeyCode::KEY_DOWN_ARROW },
	{ GLFW_KEY_UP              , EventKeyboard::KeyCode::KEY_UP_ARROW },
	{ GLFW_KEY_PAGE_UP         , EventKeyboard::KeyCode::KEY_PG_UP },
	{ GLFW_KEY_PAGE_DOWN       , EventKeyboard::KeyCode::KEY_PG_DOWN },
	{ GLFW_KEY_HOME            , EventKeyboard::KeyCode::KEY_HOME },
	{ GLFW_KEY_END             , EventKeyboard::KeyCode::KEY_END },
	{ GLFW_KEY_CAPS_LOCK       , EventKeyboard::KeyCode::KEY_CAPS_LOCK },
	{ GLFW_KEY_SCROLL_LOCK     , EventKeyboard::KeyCode::KEY_SCROLL_LOCK },
	{ GLFW_KEY_NUM_LOCK        , EventKeyboard::KeyCode::KEY_NUM_LOCK },
	{ GLFW_KEY_PRINT_SCREEN    , EventKeyboard::KeyCode::KEY_PRINT },
	{ GLFW_KEY_PAUSE           , EventKeyboard::KeyCode::KEY_PAUSE },
	{ GLFW_KEY_F1              , EventKeyboard::KeyCode::KEY_F1 },
	{ GLFW_KEY_F2              , EventKeyboard::KeyCode::KEY_F2 },
	{ GLFW_KEY_F3              , EventKeyboard::KeyCode::KEY_F3 },
	{ GLFW_KEY_F4              , EventKeyboard::KeyCode::KEY_F4 },
	{ GLFW_KEY_F5              , EventKeyboard::KeyCode::KEY_F5 },
	{ GLFW_KEY_F6              , EventKeyboard::KeyCode::KEY_F6 },
	{ GLFW_KEY_F7              , EventKeyboard::KeyCode::KEY_F7 },
	{ GLFW_KEY_F8              , EventKeyboard::KeyCode::KEY_F8 },
	{ GLFW_KEY_F9              , EventKeyboard::KeyCode::KEY_F9 },
	{ GLFW_KEY_F10             , EventKeyboard::KeyCode::KEY_F10 },
	{ GLFW_KEY_F11             , EventKeyboard::KeyCode::KEY_F11 },
	{ GLFW_KEY_F12             , EventKeyboard::KeyCode::KEY_F12 },
	{ GLFW_KEY_F13             , EventKeyboard::KeyCode::KEY_NONE },
	{ GLFW_KEY_F14             , EventKeyboard::KeyCode::KEY_NONE },
	{ GLFW_KEY_F15             , EventKeyboard::KeyCode::KEY_NONE },
	{ GLFW_KEY_F16             , EventKeyboard::KeyCode::KEY_NONE },
	{ GLFW_KEY_F17             , EventKeyboard::KeyCode::KEY_NONE },
	{ GLFW_KEY_F18             , EventKeyboard::KeyCode::KEY_NONE },
	{ GLFW_KEY_F19             , EventKeyboard::KeyCode::KEY_NONE },
	{ GLFW_KEY_F20             , EventKeyboard::KeyCode::KEY_NONE },
	{ GLFW_KEY_F21             , EventKeyboard::KeyCode::KEY_NONE },
	{ GLFW_KEY_F22             , EventKeyboard::KeyCode::KEY_NONE },
	{ GLFW_KEY_F23             , EventKeyboard::KeyCode::KEY_NONE },
	{ GLFW_KEY_F24             , EventKeyboard::KeyCode::KEY_NONE },
	{ GLFW_KEY_F25             , EventKeyboard::KeyCode::KEY_NONE },
	{ GLFW_KEY_KP_0            , EventKeyboard::KeyCode::KEY_0 },
	{ GLFW_KEY_KP_1            , EventKeyboard::KeyCode::KEY_1 },
	{ GLFW_KEY_KP_2            , EventKeyboard::KeyCode::KEY_2 },
	{ GLFW_KEY_KP_3            , EventKeyboard::KeyCode::KEY_3 },
	{ GLFW_KEY_KP_4            , EventKeyboard::KeyCode::KEY_4 },
	{ GLFW_KEY_KP_5            , EventKeyboard::KeyCode::KEY_5 },
	{ GLFW_KEY_KP_6            , EventKeyboard::KeyCode::KEY_6 },
	{ GLFW_KEY_KP_7            , EventKeyboard::KeyCode::KEY_7 },
	{ GLFW_KEY_KP_8            , EventKeyboard::KeyCode::KEY_8 },
	{ GLFW_KEY_KP_9            , EventKeyboard::KeyCode::KEY_9 },
	{ GLFW_KEY_KP_DECIMAL      , EventKeyboard::KeyCode::KEY_PERIOD },
	{ GLFW_KEY_KP_DIVIDE       , EventKeyboard::KeyCode::KEY_KP_DIVIDE },
	{ GLFW_KEY_KP_MULTIPLY     , EventKeyboard::KeyCode::KEY_KP_MULTIPLY },
	{ GLFW_KEY_KP_SUBTRACT     , EventKeyboard::KeyCode::KEY_KP_MINUS },
	{ GLFW_KEY_KP_ADD          , EventKeyboard::KeyCode::KEY_KP_PLUS },
	{ GLFW_KEY_KP_ENTER        , EventKeyboard::KeyCode::KEY_KP_ENTER },
	{ GLFW_KEY_KP_EQUAL        , EventKeyboard::KeyCode::KEY_EQUAL },
	{ GLFW_KEY_LEFT_SHIFT      , EventKeyboard::KeyCode::KEY_LEFT_SHIFT },
	{ GLFW_KEY_LEFT_CONTROL    , EventKeyboard::KeyCode::KEY_LEFT_CTRL },
	{ GLFW_KEY_LEFT_ALT        , EventKeyboard::KeyCode::KEY_LEFT_ALT },
	{ GLFW_KEY_LEFT_SUPER      , EventKeyboard::KeyCode::KEY_HYPER },
	{ GLFW_KEY_RIGHT_SHIFT     , EventKeyboard::KeyCode::KEY_RIGHT_SHIFT },
	{ GLFW_KEY_RIGHT_CONTROL   , EventKeyboard::KeyCode::KEY_RIGHT_CTRL },
	{ GLFW_KEY_RIGHT_ALT       , EventKeyboard::KeyCode::KEY_RIGHT_ALT },
	{ GLFW_KEY_RIGHT_SUPER     , EventKeyboard::KeyCode::KEY_HYPER },
	{ GLFW_KEY_MENU            , EventKeyboard::KeyCode::KEY_MENU },
	{ GLFW_KEY_LAST            , EventKeyboard::KeyCode::KEY_NONE }
};



#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
//gbk转UTF-8
static std::string GbkToUtf8(const std::string& strGbk)//传入的strGbk是GBK编码
{
	//gbk转unicode
	int len = MultiByteToWideChar(CP_ACP, 0, strGbk.c_str(), -1, NULL, 0);
	wchar_t *strUnicode = new wchar_t[len];
	wmemset(strUnicode, 0, len);
	MultiByteToWideChar(CP_ACP, 0, strGbk.c_str(), -1, strUnicode, len);

	//unicode转UTF-8
	len = WideCharToMultiByte(CP_UTF8, 0, strUnicode, -1, NULL, 0, NULL, NULL);
	char * strUtf8 = new char[len];
	WideCharToMultiByte(CP_UTF8, 0, strUnicode, -1, strUtf8, len, NULL, NULL);

	std::string strTemp(strUtf8);//此时的strTemp是UTF-8编码
	delete[]strUnicode;
	delete[]strUtf8;
	strUnicode = NULL;
	strUtf8 = NULL;
	return strTemp;
}

static std::string getClipboardString()
{
	std::string outvalue;

	HGLOBAL hGlobal;
	PCHAR pText;
	PCHAR pGlobal;

	OpenClipboard(GetDesktopWindow()); // Open the clipboard

	hGlobal = GetClipboardData(CF_TEXT);
	if (hGlobal == FALSE) // is equal "NULL" condition
	{
		CloseClipboard();
		return outvalue;
	}

	// Allocation memory 
	pText = new char[GlobalSize(hGlobal) + 1];
	if (pText == NULL)
	{
		CloseClipboard();
		return outvalue;
	}

	// lock and get the clipboard text address.
	pGlobal = (char*)GlobalLock(hGlobal);
	strcpy(pText, pGlobal); // copy string

	GlobalUnlock(hGlobal); // Unlock
	CloseClipboard(); // Close the clipboard

	outvalue = GbkToUtf8(pText);
	delete[]pText;

	return outvalue;
}

static void setClipboardString(const std::string& value)
{
	if (OpenClipboard(GetDesktopWindow()))//打开剪贴板
	{
		HANDLE hClip;
		char* pBuf;
		EmptyClipboard();//清空剪贴板
						 //写入数据
		hClip = GlobalAlloc(GMEM_MOVEABLE, value.size() + 1);
		pBuf = (char *)GlobalLock(hClip);
		strcpy(pBuf, value.c_str());
		GlobalUnlock(hClip);//解锁
		SetClipboardData(CF_TEXT, hClip);//设置格式
										 //关闭剪贴板
		CloseClipboard();
	}
}
#endif

























//////////////////////////////////////////////////////////////////////////

USING_NS_CC;


// on "init" you need to initialize your instance
bool ILayer::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	this->setAnchorPoint(Vec2::ZERO);
	this->setContentSize(Director::getInstance()->getVisibleSize());
	return true;
}


void ILayer::onEnter()
{
	Layer::onEnter();
	
	//----------------------------------------
	// init imgui cc
	setGLProgram(GLProgramCache::getInstance()->getGLProgram(GLProgram::SHADER_NAME_POSITION_COLOR));

	//----------------------------------------
	m_context = ImGui::CreateContext();
	ImGui::SetCurrentContext(m_context);

	irender = new IRender();
	irender->ImGui_ImplOpenGL3_Init();

	m_glView = Director::getInstance()->getOpenGLView();
	g_Window = ((GLViewImpl*)Director::getInstance()->getOpenGLView())->getWindow();
	g_Time = 0.0;

	// Setup back-end capabilities flags
	ImGuiIO& io = ImGui::GetIO();
	io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;         // We can honor GetMouseCursor() values (optional)
	//io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;          // We can honor io.WantSetMousePos requests (optional, rarely used)
	io.BackendPlatformName = "imgui_impl_glfw";

	// Keyboard mapping. ImGui will use those indices to peek into the io.KeysDown[] array.
	io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
	io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
	io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
	io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
	io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
	io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
	io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
	io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
	io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
	io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
	io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
	io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
	io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
	io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
	io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
	io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
	io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
	io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
	io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
	io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
	io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;


	io.SetClipboardTextFn = [](void* userdata, const char* text)
	{
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
		setClipboardString(text);
#else
		glfwSetClipboardString((GLFWwindow*)userdata, text);
#endif
	};
	io.GetClipboardTextFn = [](void* userdata)->const char*
	{
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
		static std::string clipboardString = "";
		clipboardString = getClipboardString();
		return clipboardString.c_str();
#else
		return glfwGetClipboardString((GLFWwindow*)userdata);
#endif
	};
	io.ClipboardUserData = g_Window;
#if defined(_WIN32)
	io.ImeWindowHandle = (void*)glfwGetWin32Window(g_Window);
#endif

	// events
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = [this](Touch* touch, Event* e) -> bool {
		auto old = ImGui::GetCurrentContext();
		ImGui::SetCurrentContext(m_context);

		bool isSwallow = ImGui::IsAnyWindowHovered();
		if (isSwallow)
		{
			this->attachWithIME();
		}
		else
		{
			this->detachWithIME();
		}

		ImGui::SetCurrentContext(old);

		if (m_engulfAllTouchs)
		{
			return true;
		}

		return isSwallow;
	};
	getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	auto e = cocos2d::EventListenerMouse::create();
	e->onMouseDown = [this](cocos2d::EventMouse* ev)
	{
		const auto b = (int)ev->getMouseButton();
		if (0 <= b && b < 5)
			g_MouseJustPressed[b] = true;
	};
	e->onMouseUp = [this](cocos2d::EventMouse* ev)
	{
		const auto b = (int)ev->getMouseButton();
		if (0 <= b && b < 5)
			g_MouseJustPressed[b] = false;
	};
	e->onMouseMove = [this](cocos2d::EventMouse* ev)
	{
		g_CursorPos.x = ev->getLocation().x * m_glView->getScaleX();
		g_CursorPos.y = ev->getLocation().y * m_glView->getScaleY();
	};
	e->onMouseScroll = [this](cocos2d::EventMouse* ev)
	{
		auto old = ImGui::GetCurrentContext();
		ImGui::SetCurrentContext(m_context);

		auto& _io = ImGui::GetIO();
		_io.MouseWheelH -= (float)ev->getScrollX();
		_io.MouseWheel -= (float)ev->getScrollY();

		ImGui::SetCurrentContext(old);
	};
	cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(e, this);
	auto e2 = cocos2d::EventListenerKeyboard::create();
	using KeyCode = cocos2d::EventKeyboard::KeyCode;
	e2->onKeyPressed = [this](auto k, auto ev)
	{
		auto old = ImGui::GetCurrentContext();
		ImGui::SetCurrentContext(m_context);

		auto& _io = ImGui::GetIO();
		_io.KeysDown[(int)getKey(k)] = true;
		// Modifiers are not reliable across systems
		_io.KeyCtrl = _io.KeysDown[(int)getKey(KeyCode::KEY_LEFT_CTRL)] || _io.KeysDown[(int)getKey(KeyCode::KEY_RIGHT_CTRL)];
		_io.KeyShift = _io.KeysDown[(int)getKey(KeyCode::KEY_LEFT_SHIFT)] || _io.KeysDown[(int)getKey(KeyCode::KEY_RIGHT_SHIFT)];
		_io.KeyAlt = _io.KeysDown[(int)getKey(KeyCode::KEY_LEFT_ALT)] || _io.KeysDown[(int)getKey(KeyCode::KEY_RIGHT_ALT)];
		_io.KeySuper = _io.KeysDown[(int)getKey(KeyCode::KEY_HYPER)];
		
		ImGui::SetCurrentContext(old);
	};
	e2->onKeyReleased = [this](auto k, auto ev)
	{
		auto old = ImGui::GetCurrentContext();
		ImGui::SetCurrentContext(m_context);

		auto& _io = ImGui::GetIO();
		_io.KeysDown[(int)getKey(k)] = false;
		// Modifiers are not reliable across systems
		_io.KeyCtrl = _io.KeysDown[(int)getKey(KeyCode::KEY_LEFT_CTRL)] || _io.KeysDown[(int)getKey(KeyCode::KEY_RIGHT_CTRL)];
		_io.KeyShift = _io.KeysDown[(int)getKey(KeyCode::KEY_LEFT_SHIFT)] || _io.KeysDown[(int)getKey(KeyCode::KEY_RIGHT_SHIFT)];
		_io.KeyAlt = _io.KeysDown[(int)getKey(KeyCode::KEY_LEFT_ALT)] || _io.KeysDown[(int)getKey(KeyCode::KEY_RIGHT_ALT)];
		_io.KeySuper = _io.KeysDown[(int)getKey(KeyCode::KEY_HYPER)];

		ImGui::SetCurrentContext(old);
	};
	cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(e2, this);

	auto handle = this->getLuaHandle("onInit");
	if (handle)
	{
		handle->ppush();
		handle->pcall();
	}

	this->scheduleUpdate();
}

bool ILayer::setChineseFont(const std::string& fontFileName, float size_pixels)
{
	std::string fullName = FileUtils::getInstance()->fullPathForFilename(fontFileName);
	if (FileUtils::getInstance()->isFileExist(fullName) == false)
	{
		return false;
	}

	auto old = ImGui::GetCurrentContext();
	ImGui::SetCurrentContext(m_context);

	auto &io = ImGui::GetIO();
	auto chineseFont = io.Fonts->AddFontFromFileTTF(fullName.c_str(), size_pixels, NULL, io.Fonts->GetGlyphRangesChineseFull());
	if (chineseFont)
	{
		bool btag = io.Fonts->Build();
		io.FontDefault = chineseFont;
	}

	ImGui::SetCurrentContext(old);

	return true;
}

bool ILayer::setSystemChineseFont(const std::string& fontFileName, float size_pixels)
{
	#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
		// 中文字体
		char* windir = nullptr;
		if (_dupenv_s(&windir, nullptr, "WINDIR") || windir == nullptr)
		{
			return false;
		}
		else
		{
			auto path = std::string(windir) + "\\Fonts\\" + fontFileName;
			free(windir);
			return setChineseFont(path, size_pixels);
		}
	#else
	return false;
	#endif
}

bool ILayer::IsAnyWindowHovered()
{
	if (m_engulfAllTouchs)
	{
		return true;
	}

	auto old = ImGui::GetCurrentContext();
	ImGui::SetCurrentContext(m_context);

	bool isSwallow = ImGui::IsAnyWindowHovered();

	ImGui::SetCurrentContext(old);

	return isSwallow;
}

void ILayer::setEngulfAllTouchs(bool value)
{
	m_engulfAllTouchs = value;
}

bool ILayer::isEngulfAllTouchs()
{
	return m_engulfAllTouchs;
}

void ILayer::onExit()
{
	//for (ImGuiMouseCursor cursor_n = 0; cursor_n < ImGuiMouseCursor_COUNT; cursor_n++)
	//{
	//	glfwDestroyCursor(g_MouseCursors[cursor_n]);
	//	g_MouseCursors[cursor_n] = NULL;
	//}

	ImGui::SetCurrentContext(m_context);

	irender->ImGui_ImplOpenGL3_Shutdown();
	CC_SAFE_DELETE(irender);

	ImGui::DestroyContext(m_context);
	m_context = NULL;

	Layer::onExit();
}

void ILayer::updateImGUI()
{
	auto iter = m_callPiplines.begin();
	for (; iter != m_callPiplines.end(); ++iter)
	{
		iter->second();
	}

	auto handle = this->getLuaHandle("onGUI");
	if (handle)
	{
		handle->ppush();
		handle->pcall();
	}
}

void ILayer::removeImGUI(std::string name)
{
	auto iter = m_callPiplines.find(name);
	if (iter != m_callPiplines.end())
		m_callPiplines.erase(iter);
}

void ILayer::insertText(const char * text, size_t len)
{
	std::string utf8String(text, len);
	std::u16string u16String;
	StringUtils::UTF8ToUTF16(utf8String, u16String);

	auto old = ImGui::GetCurrentContext();
	ImGui::SetCurrentContext(m_context);

	ImGuiIO& io = ImGui::GetIO();
	for (auto i = 0; i < u16String.size(); ++i)
	{
		io.AddInputCharacter(u16String.at(i));
	}

	ImGui::SetCurrentContext(old);
}

void ILayer::update(float delta)
{
	ImGui::SetCurrentContext(m_context);

	ImGuiIO& io = ImGui::GetIO();
	io.DeltaTime = Director::getInstance()->getDeltaTime();

	irender->ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();

	this->updateImGUI();

	m_drawFinish = true;
}

void ILayer::visit(cocos2d::Renderer *renderer, const cocos2d::Mat4 &parentTransform, uint32_t parentFlags)
{
	Layer::visit(renderer, parentTransform, parentFlags);

	if (!m_drawFinish)
	{
		return;
	}

	_command.init(_globalZOrder);
	_command.func = CC_CALLBACK_0(ILayer::onDraw, this);
	Director::getInstance()->getRenderer()->addCommand(&_command);
}

void ILayer::onDraw()
{
	glUseProgram(0);

	ImGui::SetCurrentContext(m_context);

	//ImGuiIO& io = ImGui::GetIO();
	//io.DeltaTime = Director::getInstance()->getDeltaTime();

	//irender->ImGui_ImplOpenGL3_NewFrame();
	//ImGui_ImplGlfw_NewFrame();
	//
	////ImGui::SetNextWindowPos(ImVec2(0, 0));
	////ImGui::SetNextWindowSize(io.DisplaySize);
	////ImGui::Begin("Content", nullptr, ImVec2(0, 0), 0.0f,
	////	ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
	////	ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoSavedSettings |
	////	ImGuiWindowFlags_NoBringToFrontOnFocus);
	////
	//this->updateImGUI();

	////ImGui::End();

	// Rendering
	ImGui::Render();

	irender->ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	glUseProgram(1);
}

void ILayer::ImGui_ImplGlfw_UpdateMousePosAndButtons()
{
	// Update buttons
	ImGuiIO& io = ImGui::GetIO();
	for (int i = 0; i < IM_ARRAYSIZE(io.MouseDown); i++)
	{
		// If a mouse press event came, always pass it as "mouse held this frame", so we don't miss click-release events that are shorter than 1 frame.
		io.MouseDown[i] = g_MouseJustPressed[i];
	}
	// Update mouse position
	const ImVec2 mouse_pos_backup = io.MousePos;
	io.MousePos = ImVec2(-FLT_MAX, -FLT_MAX);
	if (io.WantSetMousePos)
	{
	}
	else
	{
		io.MousePos = g_CursorPos;
	}
}


void ILayer::ImGui_ImplGlfw_UpdateMouseCursor()
{
}

void ILayer::ImGui_ImplGlfw_UpdateGamepads()
{
	ImGuiIO& io = ImGui::GetIO();
	memset(io.NavInputs, 0, sizeof(io.NavInputs));
	if ((io.ConfigFlags & ImGuiConfigFlags_NavEnableGamepad) == 0)
		return;

	int axes_count = 0, buttons_count = 0;

	if (axes_count > 0 && buttons_count > 0)
		io.BackendFlags |= ImGuiBackendFlags_HasGamepad;
	else
		io.BackendFlags &= ~ImGuiBackendFlags_HasGamepad;
}


void ILayer::ImGui_ImplGlfw_NewFrame()
{
	ImGuiIO& io = ImGui::GetIO();
	IM_ASSERT(io.Fonts->IsBuilt() && "Font atlas not built! It is generally built by the renderer back-end. Missing call to renderer _NewFrame() function? e.g. ImGui_ImplOpenGL3_NewFrame().");

	// Setup display size (every frame to accommodate for window resizing)
	int w, h;
	int buffer_w, buffer_h;

	const auto frame_size = m_glView->getFrameSize();
	//const auto buffer_size = glv->getDesignResolutionSize();
	w = buffer_w = frame_size.width;
	h = buffer_h = frame_size.height;

	io.DisplaySize = ImVec2((float)w, (float)h);
	if (w > 0 && h > 0)
		io.DisplayFramebufferScale = ImVec2((float)buffer_w / w, (float)buffer_h / h);

	static float imgui_min_delta_time = 1 / 60.0f;

	// Setup time step
	io.DeltaTime = MAX(cocos2d::Director::getInstance()->getDeltaTime(), imgui_min_delta_time);

	ImGui_ImplGlfw_UpdateMousePosAndButtons();
	ImGui_ImplGlfw_UpdateMouseCursor();

	// Update game controllers (if enabled and available)
	ImGui_ImplGlfw_UpdateGamepads();

	ImGui::NewFrame();
}

int ILayer::getKey(cocos2d::EventKeyboard::KeyCode code)
{
	for (auto& it : g_keyCodeStructArray)
	{
		if (it.keyCode == code)
		{
			return it.glfwKeyCode;
		}
	}
	assert(0);
	return GLFW_KEY_UNKNOWN;
}
