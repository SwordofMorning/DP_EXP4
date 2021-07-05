#include "BookConsole.h"

BookConsole::BookConsole()
{
	// 默认使用搜索作者策略
	m_SearchStrategy = new SearchStrategyAuthor{};
}

void BookConsole::MainLoop()
{
	// 登录检查
	while (!CheckLog()) {}

	system("cls");

	// 控制面板
	while (true)
	{
		std::cout << "input num to chose function:" << std::endl;
		std::cout
			<< std::left << std::setw(30) << "1 : Search Book"
			<< std::left << std::setw(30) << "2 : Borrow Book"
			<< std::left << std::setw(30) << "3 : Return Book"
			<< std::left << std::setw(30) << "4 : Logout"
			<< std::endl;

		int inNum;
		std::cin >> inNum;
		system("cls");

		switch (inNum)
		{
		case 1:
			this->SearchBook();
			break;
		case 2:
			this->BorrowBook();
			break;
		case 3:
			this->ReturnBook();
			break;
		case 4:
			std::cout << "Logout Succed!" << std::endl;
			return;
		default:
			break;
		}
	}
}

void BookConsole::SetSearchStrategy()
{
	system("cls");
	std::cout << "Select your search Mode:" << std::endl;
	std::cout
		<< std::left << std::setw(40) << "1 : Search Author Name"
		<< std::left << std::setw(40) << "2 : Search Book Name"
		<< std::endl;

	int inNum;
	std::cin >> inNum;
	system("cls");

	switch (inNum)
	{
	case 1:
		this->m_SearchStrategy = new SearchStrategyAuthor{};
		break;
	case 2:
		this->m_SearchStrategy = new SearchStrategyBookName{};
		break;
	default:
		std::cout << "Invalid Input, use Default Mode: Search Author" << std::endl;
		this->m_SearchStrategy = new SearchStrategyAuthor{};
		break;
	}
}

bool BookConsole::CheckLog()
{
	// 输入
	std::string StuID, StuPwd;

	std::cout << "ID: ";
	std::cin >> StuID;

	std::cout << "Pwd:";
	std::cin >> StuPwd;

	// 正则检查
	if ((!this->m_Regex(StuID)) ||
		(!this->m_Regex(StuPwd)))
	{
		std::cout << "your input have invalid character!" << std::endl;
		return false;
	}

	// 登录检查
	if (!this->m_Login(StuID, StuPwd))
	{
		std::cout << "wrong ID or Pwd!" << std::endl;
		return false;
	}

	this->m_StuID = StuID;
	return true;
}

void BookConsole::SearchBook()
{
	this->SetSearchStrategy();

	std::cout << "input Key words" << std::endl;

	std::string key;
	std::cin >> key;

	this->m_SearchStrategy->Search(key);
}

void BookConsole::BorrowBook()
{
	std::cout << "input Book ID" << std::endl;

	std::string BookID;
	std::cin >> BookID;

	this->m_BorrowBook(this->m_StuID, BookID);
}

void BookConsole::ReturnBook()
{
	std::cout << "input Book ID" << std::endl;

	std::string BookID;
	std::cin >> BookID;

	this->m_ReturnBook(this->m_StuID, BookID);
}
