#include "ISearchStrategy.h"

ISearchStrategy::ISearchStrategy(const std::string& username, const std::string& pwd, const std::string& db):
	occiEmp(username, pwd, db)
{
	// do nothing
}

SearchStrategyAuthor::SearchStrategyAuthor(const std::string& username, const std::string& pwd, const std::string& db) :
	ISearchStrategy(username, pwd, db)
{
	// do nothing
}

void SearchStrategyAuthor::Search(const std::string& authorName)
{
	// ²éÑ¯Óï¾ä
	std::string sqlStmt = "select * from Books where Author = :x1";
	this->stmt = this->conn->createStatement(sqlStmt);

	try
	{
		// Ìæ»»×Ö·û
		this->stmt->setString(1, authorName);

		// Ö´ÐÐÓï¾ä
		oracle::occi::ResultSet* result = this->stmt->executeQuery();

		std::cout << "Here what we found:" << std::endl;
		std::cout 
			<< std::left << std::setw(20) << "Book ID"
			<< std::left << std::setw(20)<< "ISBN"
			<< std::left << std::setw(20)<< "Book Name"
			<< std::left << std::setw(20)<< "Author"
			<< std::left << std::setw(20)<< "In Stock ?"
			<< std::endl;

		int rows = 0;
		while (result->next())
		{
			std::cout 
				<< std::left << std::setw(20) << result->getString(1) 
				<< std::left << std::setw(20) << result->getString(2)
				<< std::left << std::setw(20)<< result->getString(3)
				<< std::left << std::setw(20) << result->getString(4)
				<< std::left << std::setw(20)<< result->getString(5)
				<< std::endl;
			rows++;
		}

		std::cout << "Total results: " << rows << std::endl;

		// ÊÍ·ÅÊý¾Ý¼¯ºÏ
		this->stmt->closeResultSet(result);
	}
	catch (oracle::occi::SQLException ex)
	{
		std::cout << "Search Author Failed" << std::endl;
		std::cout << "Error Number:" << ex.getErrorCode() << std::endl;
		std::cout << ex.getMessage() << std::endl;
	}

	// ÊÍ·ÅÓï¾ä
	this->conn->terminateStatement(this->stmt);
}

SearchStrategyBookName::SearchStrategyBookName(const std::string& username, const std::string& pwd, const std::string& db):
	ISearchStrategy(username, pwd, db)
{
	// do nothing
}

void SearchStrategyBookName::Search(const std::string& bookName)
{
	// ²éÑ¯Óï¾ä
	std::string sqlStmt = "select * from Books where BookName = :x1";
	this->stmt = this->conn->createStatement(sqlStmt);

	try
	{
		// Ìæ»»×Ö·û
		this->stmt->setString(1, bookName);

		// Ö´ÐÐÓï¾ä
		oracle::occi::ResultSet* result = this->stmt->executeQuery();

		std::cout << "Here what we found:" << std::endl;
		std::cout
			<< std::left << std::setw(20) << "Book ID"
			<< std::left << std::setw(20) << "ISBN"
			<< std::left << std::setw(20) << "Book Name"
			<< std::left << std::setw(20) << "Author"
			<< std::left << std::setw(20) << "In Stock ?"
			<< std::endl;

		int rows = 0;
		while (result->next())
		{
			std::cout
				<< std::left << std::setw(20) << result->getString(1)
				<< std::left << std::setw(20) << result->getString(2)
				<< std::left << std::setw(20) << result->getString(3)
				<< std::left << std::setw(20) << result->getString(4)
				<< std::left << std::setw(20) << result->getString(5)
				<< std::endl;
			rows++;
		}

		std::cout << "Total results: " << rows << std::endl;

		// ÊÍ·ÅÊý¾Ý¼¯ºÏ
		this->stmt->closeResultSet(result);
	}
	catch (oracle::occi::SQLException ex)
	{
		std::cout << "Search Author Failed" << std::endl;
		std::cout << "Error Number:" << ex.getErrorCode() << std::endl;
		std::cout << ex.getMessage() << std::endl;
	}

	// ÊÍ·ÅÓï¾ä
	this->conn->terminateStatement(this->stmt);
}
