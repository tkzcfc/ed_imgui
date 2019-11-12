#pragma once

#include "cocos2d.h"
#include "type/StringArray.h"
#include "imgui.h"

using namespace cocos2d;

class Tools
{
public:
	 
	static std::wstring stringToWString(const std::string& InStr);

	static std::string wstringToString(const std::wstring& InStr);

	static bool openFileMultiSelect(const std::string& InFilter, StringArray* OutPathArr);

	static std::string GbkToUtf8(const std::string& strGbk);

	static std::string Utf8ToGbk(const std::string& strUtf8);

	static std::wstring GbkToUnicode(const std::string& strGbk);

	static std::string UnicodeToGbk(const std::wstring& strUnicode);

	static std::string getFilename(const std::string& InPath);

	static bool isInRect(Node* InNode, const float InX, const float InY);

	// ∫¡√Î
	static long getMillisecond();

	static bool copyFile(const std::string& existingFileName, const std::string& newFileName, bool bFailIfExists);

	static std::string replaceString(const std::string& str, const std::string& targetstr, const std::string& replacestr);

	static void runExe(std::string exe, std::string cmd);

	static PROCESS_INFORMATION* s_ProcessInfomation;

	static void* getImguiTextureID(const std::string& key, bool isPlist = false);

	static int getImguiTextureWidth(const std::string& key, bool isPlist = false);

	static int getImguiTextureHeight(const std::string& key, bool isPlist = false);

	static bool imgui_inputText(const char* label, std::string& buf, unsigned int buf_size, unsigned int flags = 0);

	static std::vector<std::string> getLogicalDriveStrings();

	static std::string UTS(const std::string& str);

	static std::string STU(const std::string& str);

	static int32_t bor_int32(int32_t a, int32_t b);

	static uint32_t bor_uint32(uint32_t a, uint32_t b);


	// imgui
	static Size getWindowSize();

	static bool          BeginTabItem_NoClose(const char* label, ImGuiTabItemFlags flags = 0);

	static ImVec2 getMouseClickedPos(int index);

	static bool BeginWindow_NoClose(const char* name, ImGuiWindowFlags flags);

	static bool check_AcceptDragDropPayload(const char* type, ImGuiDragDropFlags flags = 0);

	static std::string AcceptDragDropPayload(const char* type, ImGuiDragDropFlags flags = 0);

	static const ImVec4& getStyleColor(int type);

	static bool copyFile(const std::string& srcFile, const std::string& dstFile);
};
