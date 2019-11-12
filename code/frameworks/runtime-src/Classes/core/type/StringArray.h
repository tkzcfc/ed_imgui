#pragma once

#include <string>
#include <vector>

class StringArray
{
public:

	StringArray();

	~StringArray();

	inline int getValueCount() { return (int)m_values.size(); }

	inline const std::string& getValueByIndex(int InIndex) { return m_values[InIndex]; }

	void addString(const std::string& InValue);

private:
	std::vector<std::string> m_values;
};

