#include "manager.h"

Manager::Manager(int id, string name, int dId)
{
	this->m_DeptId = dId;
	this->m_Id = id;
	this->m_Name = name;
}

void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << setw(8) << this->m_Name
		<< "\tְ����λ��" << setw(8) << this->getDeptId()
		<< "\t��λְ������ţ������ϰ������" << endl;
}
string Manager::getDeptId()
{
	return string("�߼�ţ��");
}