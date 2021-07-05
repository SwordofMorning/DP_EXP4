#include "occiEmp.h"

occiEmp::occiEmp(std::string user, std::string pwd, std::string db)
{
	try
	{
		// 创建环境
		this->env = oracle::occi::Environment::createEnvironment();
		// 创建连接
		this->conn = env->createConnection(user, pwd, db);
	}
	catch (oracle::occi::SQLException ex)
	{
		std::cout << "occiEmp Create" << std::endl;
		std::cout << "Error Number:" << ex.getErrorCode() << std::endl;
		std::cout << ex.getMessage() << std::endl;
	}
}

occiEmp::~occiEmp()
{
	if (this->env != nullptr)
	{
		// 释放连接
		this->env->terminateConnection(this->conn);
	}
	if (this->env)
	{
		// 释放环境
		oracle::occi::Environment::terminateEnvironment(this->env);
	}
}