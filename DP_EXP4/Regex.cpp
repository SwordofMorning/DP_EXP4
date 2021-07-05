#include "Regex.h"

Regex::Regex()
{
	std::regex re("^[A-Za-z0-9]+$");

	m_regex = re;
}

bool Regex::operator()(const std::string& str)
{
	return std::regex_match(str, m_regex);
}
