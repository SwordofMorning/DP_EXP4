#pragma once
#include "occiEmp.h"

class BorrowBook : public occiEmp
{
public:
	BorrowBook(const std::string& username = "S5120184509",
		const std::string& pwd = "admin",
		const std::string& db = "127.0.0.1:1521/orcl");

	bool operator()(const std::string& StuID, const std::string& BookID);
};

