#pragma once
#include <iostream>
#include <memory>
#include <occi.h>

class occiEmp
{
protected:
	// 上下文环境
	oracle::occi::Environment* env;
	// 数据库连接句柄
	oracle::occi::Connection* conn;
	// 指向SQL语句的声明类
	oracle::occi::Statement* stmt;
public:
	occiEmp(std::string user, std::string pwd, std::string db);
	~occiEmp();
};
