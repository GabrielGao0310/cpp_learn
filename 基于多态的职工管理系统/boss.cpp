#include "boss.h"

Boss::Boss(int id, string name, int dId)
{
	this->m_DeptId = dId;
	this->m_Id = id;
	this->m_Name = name;
}

void Boss::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << setw(8) << this->m_Name
		<< "\tְ����λ��" << setw(8) << this->getDeptId()
		<< "\t��λְ���������Ҫ�����ո�ʣ���ֵ" << endl;
}
string Boss::getDeptId()
{
	return string("�ʱ���");
}