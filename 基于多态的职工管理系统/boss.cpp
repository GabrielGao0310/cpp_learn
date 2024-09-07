#include "boss.h"

Boss::Boss(int id, string name, int dId)
{
	this->m_DeptId = dId;
	this->m_Id = id;
	this->m_Name = name;
}

void Boss::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << setw(8) << this->m_Name
		<< "\t职工岗位：" << setw(8) << this->getDeptId()
		<< "\t岗位职责：命令经理，主要负责收割剩余价值" << endl;
}
string Boss::getDeptId()
{
	return string("资本家");
}