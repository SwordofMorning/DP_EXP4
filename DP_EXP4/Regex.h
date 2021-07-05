#pragma once
#include <regex>

class Regex
{
private:
	std::regex m_regex;
public:
	Regex();

	bool operator()(const std::string& str);
};

