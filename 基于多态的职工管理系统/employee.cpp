#include "employee.h"

Employee::Employee(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_DeptId = dId;
	this->m_Name = name;
}

void Employee::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << setw(8) << this->m_Name
		<< "\tְ����λ��" << setw(8) << this->getDeptId()
		<< "\t��λְ����ɾ��������" << endl;
}

string Employee::getDeptId()
{
	return string("ţ��");
}