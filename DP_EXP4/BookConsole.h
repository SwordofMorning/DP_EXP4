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

	// ������������
	void SetSearchStrategy();

	// ��¼���
	bool CheckLog();

	// ����
	void SearchBook();

	// ����
	void BorrowBook();

	// ����
	void ReturnBook();
public:
	// ���캯��
	BookConsole();

	// ����
	void MainLoop();
};

