#include <iostream>
using namespace std;
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main()
{
	//// test��̬
	//Worker* worker = NULL;
	//worker = new Employee(1, "�߲�", 1);
	//worker->showInfo();

	//worker = new Manager(2, "����ʦ", 2);
	//worker->showInfo();

	//worker = new Boss(3, "lisong", 3);
	//worker->showInfo();


	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.Show_Menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:		// �˳�����ϵͳ
			wm.ExitSystem();
			break;
		case 1:		// ������Ϣ
			wm.addPerson();
			break;
		case 2:		// ��ʾ��Ϣ
			wm.showPerson();
			break;
		case 3:		// ɾ����Ϣ
			wm.deletePerson();
			break;
		case 4:		// �޸���Ϣ
			wm.modifyPerson();
			break;
		case 5:		// ������Ϣ
			wm.findPerson();
			break;
		case 6:		// ����
			wm.sortPerson();
			break;
		case 7:		// ����ĵ�
			wm.cleanPerson();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}