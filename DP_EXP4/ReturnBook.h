#pragma once
#include "occiEmp.h"

class ReturnBook : public occiEmp
{
public:
	ReturnBook(const std::string& username = "S5120184509",
		const std::string& pwd = "admin",
		const std::string& db = "127.0.0.1:1521/orcl");

	bool operator()(const std::string& StuID, const std::string& BookID);
};

