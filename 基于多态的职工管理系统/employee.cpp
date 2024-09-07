#include "employee.h"

Employee::Employee(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_DeptId = dId;
	this->m_Name = name;
}

void Employee::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << setw(8) << this->m_Name
		<< "\t职工岗位：" << setw(8) << this->getDeptId()
		<< "\t岗位职责：完成经理的任务" << endl;
}

string Employee::getDeptId()
{
	return string("牛马");
}