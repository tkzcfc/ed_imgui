#include "StringArray.h"


StringArray::StringArray()
{
	m_values.reserve(10);
}

StringArray::~StringArray()
{}

void StringArray::addString(const std::string& InValue)
{
	m_values.push_back(InValue);
}