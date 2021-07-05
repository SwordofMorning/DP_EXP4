#pragma once
#include "occiEmp.h"

class Login : public occiEmp
{
public:
	Login(const std::string& username = "S5120184509", 
		const std::string& pwd = "admin",
		const std::string& db = "127.0.0.1:1521/orcl");

	bool operator()(std::string stuID, std::string stuPWD);
};

