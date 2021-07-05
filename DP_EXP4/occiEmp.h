#pragma once
#include <iostream>
#include <memory>
#include <occi.h>

class occiEmp
{
protected:
	// �����Ļ���
	oracle::occi::Environment* env;
	// ���ݿ����Ӿ��
	oracle::occi::Connection* conn;
	// ָ��SQL����������
	oracle::occi::Statement* stmt;
public:
	occiEmp(std::string user, std::string pwd, std::string db);
	~occiEmp();
};
