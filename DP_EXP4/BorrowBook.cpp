#include "BorrowBook.h"

BorrowBook::BorrowBook(const std::string& username, const std::string& pwd, const std::string& db) :
	occiEmp(username, pwd, db)
{
	// do nothing
}

bool BorrowBook::operator()(const std::string& StuID, const std::string& BookID)
{
	bool re = true;

	// Óï¾ä
	std::string sqlStmt = "call LendBook(:x1, :x2)";
	this->stmt = this->conn->createStatement(sqlStmt);

	try
	{
		this->stmt->setString(1, StuID);
		this->stmt->setString(2, BookID);

		// Ö´ÐÐÓï¾ä
		unsigned int result = this->stmt->executeUpdate();
		std::cout << "Borrow Book succed..." << std::endl;
	}
	catch (oracle::occi::SQLException ex)
	{
		std::cout << "Borrow Book Failed: Book Not Existed or Have Been Lend." << std::endl;
		std::cout << "Error Number:" << ex.getErrorCode() << std::endl;
		std::cout << ex.getMessage() << std::endl;
		re = false;
	}

	// ÊÍ·ÅÓï¾ä
	this->conn->terminateStatement(this->stmt);

	return re;
}
