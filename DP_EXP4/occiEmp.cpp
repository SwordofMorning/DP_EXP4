#include "occiEmp.h"

occiEmp::occiEmp(std::string user, std::string pwd, std::string db)
{
	try
	{
		// ��������
		this->env = oracle::occi::Environment::createEnvironment();
		// ��������
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
		// �ͷ�����
		this->env->terminateConnection(this->conn);
	}
	if (this->env)
	{
		// �ͷŻ���
		oracle::occi::Environment::terminateEnvironment(this->env);
	}
}