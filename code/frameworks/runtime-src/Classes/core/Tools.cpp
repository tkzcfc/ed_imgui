#include "Tools.h"
#include "json/rapidjson.h"
#include "json/prettywriter.h"
#include "json/document.h"
#include <Windows.h>

std::map<std::string, std::vector<std::string> > Tools::cache_plistSubs;

std::wstring Tools::stringToWString(const std::string& InStr) {
	int num = MultiByteToWideChar(CP_UTF8, 0, InStr.c_str(), -1, NULL, 0);
	wchar_t *wide = new wchar_t[num];
	MultiByteToWideChar(CP_UTF8, 0, InStr.c_str(), -1, wide, num);
	std::wstring w_str(wide);
	delete[] wide;
	return w_str;
}

std::string Tools::wstringToString(const std::wstring& InStr)
{
	int needBytes = WideCharToMultiByte(CP_ACP, 0, InStr.c_str(), -1, NULL, 0, NULL, NULL);
	if (needBytes > 0)
	{
		char* pszBuf = new char[needBytes + 1];
		ZeroMemory(pszBuf, (needBytes + 1) * sizeof(char));
		WideCharToMultiByte(CP_ACP, 0, InStr.c_str(), -1, pszBuf, needBytes, NULL, NULL);
		return std::string(pszBuf);
		delete[] pszBuf;
	}
	return std::string("");
}

bool Tools::openFileMultiSelect(const std::string& InFilter, StringArray* OutPathArr)
{
	std::wstring wsFilter = stringToWString(Utf8ToGbk(InFilter));
	
	wchar_t szFilterBuf[512];
	memset(szFilterBuf, '\0', sizeof(szFilterBuf));
	lstrcpy(szFilterBuf, wsFilter.c_str());

	OPENFILENAME ofn;
	TCHAR szOpenFileNames[80 * MAX_PATH];
	TCHAR szPath[MAX_PATH];
	TCHAR szFileName[80 * MAX_PATH];
	TCHAR* p;
	int nLen = 0;
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.Flags = OFN_EXPLORER | OFN_ALLOWMULTISELECT;
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFile = szOpenFileNames;
	ofn.nMaxFile = sizeof(szOpenFileNames);
	ofn.lpstrFile[0] = '\0';
	ofn.lpstrFilter = szFilterBuf;//TEXT("All Files(*.*)\0*.*\0");
	if (GetOpenFileName(&ofn))
	{
		//把第一个文件名前的复制到szPath,即:
		//如果只选了一个文件,就复制到最后一个'\'
		//如果选了多个文件,就复制到第一个NULL字符
		lstrcpyn(szPath, szOpenFileNames, ofn.nFileOffset);

		//当只选了一个文件时,下面这个NULL字符是必需的.
		//这里不区别对待选了一个和多个文件的情况
		szPath[ofn.nFileOffset] = '\0';
		nLen = lstrlen(szPath);

		//如果选了多个文件,则必须加上'\\'
		if (szPath[nLen - 1] != '\\')   
		{
			lstrcat(szPath, TEXT("\\"));
		}

		//把指针移到第一个文件
		p = szOpenFileNames + ofn.nFileOffset; 


		std::string filterExtension = FileUtils::getInstance()->getFileExtension(InFilter);

		ZeroMemory(szFileName, sizeof(szFileName));
		while (*p)
		{
			std::wstring wspath = szPath;
			wspath.append(p);

			if (OutPathArr)
			{
				std::string fullpath = GbkToUtf8(wstringToString(wspath));
				OutPathArr->addString(fullpath);
				//std::string extension = FileUtils::getInstance()->getFileExtension(fullpath);
				//if (filterExtension == extension)
				//{
				//	OutPathArr->addString(fullpath);
				//}
			}

			//移至下一个文件
			p += lstrlen(p) + 1;    
		}
		return true;
	}
	return false;
}

//gbk转UTF-8
std::string Tools::GbkToUtf8(const std::string& strGbk)//传入的strGbk是GBK编码
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

//UTF-8转gbk
std::string Tools::Utf8ToGbk(const std::string& strUtf8)//传入的strUtf8是UTF-8编码
{
	//UTF-8转unicode
	int len = MultiByteToWideChar(CP_UTF8, 0, strUtf8.c_str(), -1, NULL, 0);
	wchar_t * strUnicode = new wchar_t[len];//len = 2
	wmemset(strUnicode, 0, len);
	MultiByteToWideChar(CP_UTF8, 0, strUtf8.c_str(), -1, strUnicode, len);

	//unicode转gbk
	len = WideCharToMultiByte(CP_ACP, 0, strUnicode, -1, NULL, 0, NULL, NULL);
	char *strGbk = new char[len];//len=3 本来为2，但是char*后面自动加上了\0
	memset(strGbk, 0, len);
	WideCharToMultiByte(CP_ACP, 0, strUnicode, -1, strGbk, len, NULL, NULL);

	std::string strTemp(strGbk);//此时的strTemp是GBK编码
	delete[]strUnicode;
	delete[]strGbk;
	strUnicode = NULL;
	strGbk = NULL;
	return strTemp;
}

//gbk转unicode (下面的例子没用到)
std::wstring Tools::GbkToUnicode(const std::string& strGbk)//返回值是wstring
{
	int len = MultiByteToWideChar(CP_ACP, 0, strGbk.c_str(), -1, NULL, 0);
	wchar_t *strUnicode = new wchar_t[len];
	wmemset(strUnicode, 0, len);
	MultiByteToWideChar(CP_ACP, 0, strGbk.c_str(), -1, strUnicode, len);

	std::wstring strTemp(strUnicode);//此时的strTemp是Unicode编码
	delete[]strUnicode;
	strUnicode = NULL;
	return strTemp;
}

//Unicode转gbk
std::string Tools::UnicodeToGbk(const std::wstring& strUnicode)//参数是wstring
{
	int len = WideCharToMultiByte(CP_ACP, 0, strUnicode.c_str(), -1, NULL, 0, NULL, NULL);
	char *strGbk = new char[len];//len=3 本来为2，但是char*后面自动加上了\0
	memset(strGbk, 0, len);
	WideCharToMultiByte(CP_ACP, 0, strUnicode.c_str(), -1, strGbk, len, NULL, NULL);

	std::string strTemp(strGbk);//此时的strTemp是GBK编码
	delete[]strGbk;
	strGbk = NULL;
	return strTemp;
}

std::string Tools::getFilename(const std::string& InPath)
{
	std::size_t pos = InPath.find_last_of('/');
	if (pos != std::string::npos && pos < InPath.size() - 1)
	{
		return InPath.substr(pos + 1);
	}
	pos = InPath.find_last_of('\\');
	if (pos != std::string::npos && pos < InPath.size() - 1)
	{
		return InPath.substr(pos + 1);
	}
	return InPath;
}


bool Tools::isInRect(Node* InNode, const float InX, const float InY)
{
	if (InNode == NULL)
	{
		return false;
	}

	Rect rect;
	rect.size = InNode->getContentSize();
	return isScreenPointInRect(Vec2(InX, InY), Camera::getDefaultCamera(), InNode->getWorldToNodeTransform(), rect, NULL);
}

long Tools::getMillisecond()
{
	struct timeval timevalue;
	gettimeofday(&timevalue, NULL);
	return timevalue.tv_sec * 1000 + timevalue.tv_usec / 1000;
}

bool Tools::copyFile(const std::string& existingFileName, const std::string& newFileName, bool bFailIfExists)
{
	std::wstring wsExistingFileName = stringToWString(existingFileName);
	std::wstring wsNewFileName = stringToWString(newFileName);
	return ::CopyFile(wsExistingFileName.c_str(), wsNewFileName.c_str(), (BOOL)bFailIfExists);
}

std::string Tools::replaceString(const std::string& str, const std::string& targetstr, const std::string& replacestr)
{
	std::size_t pos = str.find(targetstr.c_str());
	if (pos != std::string::npos)
	{
		std::string outstr(str);
		outstr.replace(outstr.begin() + pos, outstr.begin() + pos + targetstr.size(), replacestr.c_str());
		return outstr;
	}
	return str;
}

PROCESS_INFORMATION* Tools::s_ProcessInfomation = NULL;

void Tools::runExe(std::string exe, std::string cmd)
{
	if (s_ProcessInfomation == NULL)
	{
		s_ProcessInfomation = new PROCESS_INFORMATION();
	}
	else
	{
		::CloseHandle(s_ProcessInfomation->hProcess);
		::CloseHandle(s_ProcessInfomation->hThread);
		s_ProcessInfomation->hProcess = NULL;
		s_ProcessInfomation->hThread = NULL;
		s_ProcessInfomation->dwProcessId = 0;
		s_ProcessInfomation->dwThreadId = 0;
	}

	std::wstring wsExe = stringToWString(Utf8ToGbk(exe));
	std::wstring wsCmd = stringToWString(Utf8ToGbk(cmd));

	wsExe.append(L" ");


	STARTUPINFO stStartUpInfo;
	::memset(&stStartUpInfo, 0, sizeof(stStartUpInfo));
	stStartUpInfo.cb = sizeof(stStartUpInfo);

	::memset(s_ProcessInfomation, 0, sizeof(PROCESS_INFORMATION));

	try
	{
		bool bRet = ::CreateProcess(
			wsExe.c_str(),
			(TCHAR* )wsCmd.c_str(),
			NULL,
			NULL,
			false,
			CREATE_NEW_CONSOLE,
			NULL,
			NULL,
			&stStartUpInfo,
			s_ProcessInfomation);
		if(!bRet)
		{
			//如果创建进程失败，查看错误码
			DWORD dwErrCode = GetLastError();
			printf_s("ErrCode : %d\n", dwErrCode);
		}
	}
	catch (...)
	{
	}
}

void* Tools::getImguiTextureID(const std::string& key, bool isPlist)
{
	Texture2D* texture = NULL;
	if (isPlist)
	{
		auto sf = SpriteFrameCache::getInstance()->getSpriteFrameByName(key);
		if (sf)
		{
			texture = sf->getTexture();
		}
	}
	else
	{
		texture = TextureCache::getInstance()->addImage(key);
	}
	if (texture == NULL)
	{
		//assert(0);
		return 0;
	}
	return (void*)texture->getName();
}

void* Tools::getImguiTextureIDByTexture(Texture2D* texture)
{
	if (texture)
	{
		return (void*)texture->getName();
	}
	return NULL;
}

int Tools::getImguiTextureWidth(const std::string& key, bool isPlist)
{
	Texture2D* texture = NULL;
	if (isPlist)
	{
		auto sf = SpriteFrameCache::getInstance()->getSpriteFrameByName(key);
		if (sf)
		{
			return (int)sf->getRect().size.width;
		}
	}
	else
	{
		texture = TextureCache::getInstance()->addImage(key);
	}
	if (texture == NULL)
	{
		//assert(0);
		return 0;
	}
	return texture->getPixelsWide();
}

int Tools::getImguiTextureHeight(const std::string& key, bool isPlist)
{
	Texture2D* texture = NULL;
	if (isPlist)
	{
		auto sf = SpriteFrameCache::getInstance()->getSpriteFrameByName(key);
		if (sf)
		{
			return (int) sf->getRect().size.height;
		}
	}
	else
	{
		texture = TextureCache::getInstance()->addImage(key);
	}
	if (texture == NULL)
	{
		//assert(0);
		return 0;
	}
	return texture->getPixelsHigh();
}


bool Tools::imgui_inputText(const char* label, std::string& buf, unsigned int buf_size, unsigned int flags/* = 0*/)
{
	static char maxInput_buf[1024];
	if (buf_size > sizeof(maxInput_buf) - 1)
	{
		buf_size = sizeof(maxInput_buf) - 1;
	}
	strcpy(maxInput_buf, buf.c_str());

	if (flags & ImGuiInputTextFlags_EnterReturnsTrue)
	{
		if (ImGui::InputText(label, maxInput_buf, buf_size, flags))
		{
			buf.assign(maxInput_buf);
			return true;
		}
		buf.assign(maxInput_buf);
	}
	else
	{
		if (ImGui::InputText(label, maxInput_buf, buf_size, flags))
		{
			buf.assign(maxInput_buf);
			return true;
		}
	}
	return false;
}

std::vector<std::string> Tools::getLogicalDriveStrings()
{
	std::vector<std::string> out;
#if _WIN32
	char diskStrings[256];
	memset(diskStrings, 0, 256);
	::GetLogicalDriveStringsA(256, diskStrings);

	for (char *s = diskStrings; *s; s += strlen(s) + 1)
	{
		out.push_back(s);
	}
#endif
	return out;
}


std::string Tools::UTS(const std::string& str)
{
#if _WIN32
	int nwLen = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);

	wchar_t * pwBuf = new wchar_t[nwLen + 1];//一定要加1，不然会出现尾巴 
	memset(pwBuf, 0, nwLen * 2 + 2);

	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.length(), pwBuf, nwLen);

	int nLen = WideCharToMultiByte(CP_ACP, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

	char * pBuf = new char[nLen + 1];
	memset(pBuf, 0, nLen + 1);

	WideCharToMultiByte(CP_ACP, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

	std::string retStr = pBuf;

	delete[]pBuf;
	delete[]pwBuf;

	pBuf = NULL;
	pwBuf = NULL;

	return retStr;
#else
	return str;
#endif
}

std::string Tools::STU(const std::string& str)
{
#if _WIN32
	int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);

	wchar_t * pwBuf = new wchar_t[nwLen + 1];//一定要加1，不然会出现尾巴  
	ZeroMemory(pwBuf, nwLen * 2 + 2);

	::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);

	int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

	char * pBuf = new char[nLen + 1];
	ZeroMemory(pBuf, nLen + 1);

	::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

	std::string retStr(pBuf);

	delete[]pwBuf;
	delete[]pBuf;

	pwBuf = NULL;
	pBuf = NULL;

	return retStr;
#else
	return str;
#endif
}

uint32_t Tools::bor_uint32(uint32_t a, uint32_t b)
{
	return a | b;
}

int32_t Tools::bor_int32(int32_t a, int32_t b)
{
	return a | b;
}

Size Tools::getWindowSize()
{
	return Director::getInstance()->getOpenGLView()->getFrameSize();
}

bool          Tools::BeginTabItem_NoClose(const char* label, ImGuiTabItemFlags flags)
{
	return ImGui::BeginTabItem(label, NULL, flags);
}

ImVec2 Tools::getMouseClickedPos(int index)
{
	auto& io = ImGui::GetIO();
	return io.MouseClickedPos[index];
}

bool Tools::BeginWindow_NoClose(const char* name, ImGuiWindowFlags flags)
{
	return ImGui::Begin(name, NULL, flags);
}

bool Tools::check_AcceptDragDropPayload(const char* type, ImGuiDragDropFlags flags/* = 0*/)
{
	return ImGui::AcceptDragDropPayload(type, flags) != NULL;
}

std::string Tools::AcceptDragDropPayload(const char* type, ImGuiDragDropFlags flags/* = 0*/)
{
	auto payload = ImGui::AcceptDragDropPayload(type, flags);
	if (payload == NULL)
	{
		return "";
	}
	return std::string((const char*)payload->Data, payload->DataSize);
}

const ImVec4& Tools::getStyleColor(int type)
{
	return ImGui::GetStyle().Colors[type];
}

bool Tools::copyFile(const std::string& srcFile, const std::string& dstFile)
{
	auto FileUtilsPtr = FileUtils::getInstance();
	auto& data = FileUtilsPtr->getDataFromFile(srcFile);
	return FileUtilsPtr->writeDataToFile(data, dstFile);
}

void Tools::enumerateChildren(cocos2d::Node* node, const std::string& name, LuaFunction& handle)
{
	if (node != NULL && handle.isvalid())
	{
		node->enumerateChildren(name, [&](cocos2d::Node* cur)->bool
		{
			handle.ppush();
			handle.pushusertype<Node>(cur, "cc.Node");
			handle.pcall();
			return false;
		});
	}
}

std::string Tools::prettyJson(const char* json)
{
	rapidjson::Document docu;
	docu.Parse(json);

	rapidjson::StringBuffer buffer;
	rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);

	docu.Accept(writer);

	return buffer.GetString();
}

int Tools::imguiComboUserdata(const char* label, int current_item)
{
	const static char* items[] = { "int", "bool", "string", "float" };
	ImGui::Combo(label, &current_item, items, IM_ARRAYSIZE(items));
	return current_item;
}

bool Tools::imguiComboBool(const char* label, bool current_item)
{
	int item = (int)current_item;

	const static char* items[] = { "false", "true" };
	ImGui::Combo(label, &item, items, IM_ARRAYSIZE(items));
	return (bool)item;
}

void Tools::helpMarker(const char* desc)
{
	ImGui::TextDisabled("(?)");
	if (ImGui::IsItemHovered())
	{
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(desc);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}

std::vector<std::string> Tools::splitPlist(const std::string& plist)
{
	auto it = cache_plistSubs.find(plist);
	if (it != cache_plistSubs.end())
	{
		return it->second;
	}

	std::vector<std::string> frameNames;

	std::string fullPath = FileUtils::getInstance()->fullPathForFilename(plist);
	ValueMap dict = FileUtils::getInstance()->getValueMapFromFile(fullPath);

	if (dict["frames"].getType() != cocos2d::Value::Type::MAP)
	{
		cache_plistSubs[plist] = frameNames;
		return frameNames;
	}

	ValueMap& framesDict = dict["frames"].asValueMap();
	for (auto iter = framesDict.begin(); iter != framesDict.end(); ++iter)
	{
		ValueMap& frameDict = iter->second.asValueMap();
		frameNames.push_back(iter->first);
	}

	cache_plistSubs[plist] = frameNames;
	return frameNames;
}
