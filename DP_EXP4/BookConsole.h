#pragma once
#include <iostream>
#include <Windows.h>
#include "occiEmp.h"
#include "Login.h"
#include "ISearchStrategy.h"
#include "BorrowBook.h"
#include "ReturnBook.h"
#include "Regex.h"

class BookConsole
{
private:
	Login m_Login;
	ISearchStrategy* m_SearchStrategy;
	Regex m_Regex;
	BorrowBook m_BorrowBook;
	ReturnBook m_ReturnBook;

	std::string m_StuID;

	// 设置搜索策略
	void SetSearchStrategy();

	// 登录检查
	bool CheckLog();

	// 查找
	void SearchBook();

	// 借书
	void BorrowBook();

	// 还书
	void ReturnBook();
public:
	// 构造函数
	BookConsole();

	// 主控
	void MainLoop();
};

