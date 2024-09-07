#pragma once
#include <iostream>
#include <string>
#include <iomanip> // std::setw
using namespace std;


class Worker
{
public:
	virtual void showInfo() = 0;
	virtual string getDeptId() = 0;


	string m_Name;
	int  m_Id;
	int m_DeptId;
};
