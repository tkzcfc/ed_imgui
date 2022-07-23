#include "Tools.h"


bool Tools::copyFile(const char* existingFileName, const char* newFileName)
{
	return (bool)::CopyFile(existingFileName, newFileName, FALSE);
}