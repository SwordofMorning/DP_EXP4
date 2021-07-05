#pragma once
#include <iostream>
#include <iomanip>
#include "occiEmp.h"

class ISearchStrategy : public occiEmp
{
public:
	ISearchStrategy(const std::string& username = "S5120184509",
		const std::string& pwd = "admin",
		const std::string& db = "127.0.0.1:1521/orcl");

	virtual void Search(const std::string& key) = 0;
};

class SearchStrategyAuthor : public ISearchStrategy
{
public:
	SearchStrategyAuthor(const std::string& username = "S5120184509",
		const std::string& pwd = "admin",
		const std::string& db = "127.0.0.1:1521/orcl");

	virtual void Search(const std::string& authorName) override;
};

class SearchStrategyBookName : public ISearchStrategy
{
public:
	SearchStrategyBookName(const std::string& username = "S5120184509",
		const std::string& pwd = "admin",
		const std::string& db = "127.0.0.1:1521/orcl");

	virtual void Search(const std::string& bookName) override;
};