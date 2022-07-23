#pragma once

#include <string>
#include "mugen/mugen.h"

class MugenHelper
{
public:

	static NS_G::GEntity* serializeRole(const char* content);

	static bool serializeRoleToFile(const char* content, const char* filename);

	static std::vector<std::string> errors();

	static std::vector<std::string> warings();

public:

	static void addError(const std::string& err);
	
	static void addWaring(const std::string& str);

	static std::vector<std::string> s_errLog;
	static std::vector<std::string> s_waring;

	static std::string s_errsActName;
	static std::string s_errskillName;
};
