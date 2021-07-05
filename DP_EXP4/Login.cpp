#include "Login.h"

Login::Login(const std::string& username, const std::string& pwd, const std::string& db) :
	occiEmp(username, pwd, db)
{
	// do nothing
}

bool Login::operator()(std::string stuID, std::string stuPWD)
{
	bool re = false;
	
	// ²éÑ¯Óï¾ä
	std::string sqlStmt = "select * from Students where ID = :x1 and PWD = :x2";
	this->stmt = this->conn->createStatement(sqlStmt);

	try
	{
		// Ìæ»»×Ö·û
		this->stmt->setString(1, stuID);
		this->stmt->setString(2, stuPWD);

		// Ö´ÐÐÓï¾ä
		oracle::occi::ResultSet* result = this->stmt->executeQuery();

		if (result->next())
		{
			re = true;
			std::cout << "Login succed...Welcome User: "<< result->getString(3)  << std::endl;
		}

		// ÊÍ·ÅÊý¾Ý¼¯ºÏ
		this->stmt->closeResultSet(result);
	}
	catch (oracle::occi::SQLException ex)
	{
		std::cout << "Login Failed" << std::endl;
		std::cout << "Error Number:" << ex.getErrorCode() << std::endl;
		std::cout << ex.getMessage() << std::endl;
	}

	// ÊÍ·ÅÓï¾ä
	this->conn->terminateStatement(this->stmt);

	return re;
}