#include <iostream>
using namespace std;
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main()
{
	//// test多态
	//Worker* worker = NULL;
	//worker = new Employee(1, "高博", 1);
	//worker->showInfo();

	//worker = new Manager(2, "程老师", 2);
	//worker->showInfo();

	//worker = new Boss(3, "lisong", 3);
	//worker->showInfo();


	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.Show_Menu();
		cout << "请输入您的选择" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:		// 退出管理系统
			wm.ExitSystem();
			break;
		case 1:		// 增加信息
			wm.addPerson();
			break;
		case 2:		// 显示信息
			wm.showPerson();
			break;
		case 3:		// 删除信息
			wm.deletePerson();
			break;
		case 4:		// 修改信息
			wm.modifyPerson();
			break;
		case 5:		// 查找信息
			wm.findPerson();
			break;
		case 6:		// 排序
			wm.sortPerson();
			break;
		case 7:		// 清空文档
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