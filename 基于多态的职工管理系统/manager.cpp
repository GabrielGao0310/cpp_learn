#include "manager.h"

Manager::Manager(int id, string name, int dId)
{
	this->m_DeptId = dId;
	this->m_Id = id;
	this->m_Name = name;
}

void Manager::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << setw(8) << this->m_Name
		<< "\t职工岗位：" << setw(8) << this->getDeptId()
		<< "\t岗位职责：命令牛马，完成老板的任务" << endl;
}
string Manager::getDeptId()
{
	return string("高级牛马");
}