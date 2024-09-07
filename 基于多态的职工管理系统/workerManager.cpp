#include "workerManager.h"

WorkerManager::WorkerManager()
{

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->personArray = NULL;
		this->personNum = 0;
		this->fileIsExist = false;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "该文件为空" << endl;
		this->fileIsExist = false;
		this->personArray = NULL;
		this->personNum = 0;
		ifs.close();
		return;
	}

	int num = this->get_filePersonNum();
	cout << "文件中已保存职工人数：" << num << endl;
	this->personNum = num;
	this->fileIsExist = true;

	this->personArray = new Worker * [num];
	this->init_personArray();

	for (int i = 0; i <= num - 1; i++)
	{
		cout << "职工编号：" << this->personArray[i]->m_Id
			<< "\t职工姓名：" << this->personArray[i]->m_Name
			<< "\t职工岗位：" << this->personArray[i]->getDeptId() << endl;

	}


}

void WorkerManager::Show_Menu()
{
	cout << "**************************" << endl;
	cout << "** 欢迎使用职工管理系统 **" << endl;
	cout << "***** 0.退出管理程序 *****" << endl;
	cout << "***** 1.增加职工信息 *****" << endl;
	cout << "***** 2.显示职工信息 *****" << endl;
	cout << "***** 3.删除职工信息 *****" << endl;
	cout << "***** 4.修改职工信息 *****" << endl;
	cout << "***** 5.查找职工信息 *****" << endl;
	cout << "***** 6.按照编码排序 *****" << endl;
	cout << "***** 7.清空所有文档 *****" << endl;
	cout << "**************************" << endl;
	cout << endl;
}

void WorkerManager::ExitSystem()
{
	cout << "你将退出系统，欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::addPerson()
{
	cout << "请输入要添加的人数" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum <= 0)
	{
		cout << "输入有误" << endl;
	}
	else
	{
		int newSize = 0;
		newSize = this->personNum + addNum;
		Worker** newArray;
		newArray = new Worker * [newSize];

		if (this->personArray != NULL)
		{
			for (int i = 0; i <= this->personNum - 1; i++)
			{
				newArray[i] = this->personArray[i];
			}
		}

		

		for (int i = 0; i <= addNum - 1; i++)
		{
			int id = 0;
			int dId = 0;
			string name = " ";

			cout << "请输入第" << i + 1 << "个职工的编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个职工的姓名" << endl;
			cin >> name; 

			while (true)
			{
				cout << "请输入第" << i + 1 << "个职工的岗位（1：员工 2：经理 3：总裁）" << endl;
				cin >> dId;
				if (dId == 1 || dId == 2 || dId == 3)
				{
					break;
				}
				else
				{
					cout << "输入错误" << endl;
				}
			}
			
			Worker* worker = NULL;
			switch (dId)
			{
			case 1:
				worker = new Employee(id, name, dId);
				break;
			case 2:
				worker = new Manager(id, name, dId);
				break;
			case 3:
				worker = new Boss(id, name, dId);
				break;
			default:
				break;
			}

			newArray[this->personNum + i] = worker;

		}

		delete[] this->personArray;
		this->personArray = newArray;
		this->personNum = newSize;




		cout << "添加成功" << endl;
		this->fileIsExist = true;
		this->save();

	}
	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i <= this->personNum - 1; i++)
	{
		ofs << this->personArray[i]->m_Id << " "
			<< this->personArray[i]->m_Name << " "
			<< this->personArray[i]->m_DeptId << endl;
		
	}
	ofs.close();
}

int WorkerManager::get_filePersonNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id = 0;
	string name = " ";
	int dId = 0;
	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}

	return num;

}

void WorkerManager::init_personArray()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int i = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		switch (dId)
		{
		case 1:
			worker = new Employee(id, name, dId);
			break;
		case 2:
			worker = new Manager(id, name, dId);
			break;
		case 3:
			worker = new Boss(id, name, dId);
			break;
		default:
			break;
		}

		this->personArray[i] = worker;
		i++;
	}
	ifs.close();
}

void WorkerManager::showPerson()
{
	if (!this->fileIsExist)
	{
		cout << "职工管理文件不存在或者记录为空" << endl;
	}
	else
	{
		for (int i = 0; i <= this->personNum - 1; i++)
		{
			this->personArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

int WorkerManager::isPersonExist(int id)
{
	int i = 0;
	int index = -1;
	for (i = 0; i <= this->personNum - 1; i++)
	{
		if (this->personArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::deletePerson()
{
	if (!this->fileIsExist)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入你想删除的职工的编号：" << endl;
		int i;
		cin >> i;
		int index = this->isPersonExist(i);
		if (index == -1)
		{
			cout << "该编号不存在" << endl;
		}
		else
		{
			for (int j = index; j <= this->personNum - 2; j++)
			{
				this->personArray[j] = this->personArray[j + 1];
			}
			cout << "删除成功" << endl;
			this->personNum --;
			this->save();

		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::modifyPerson()
{
	if (!this->fileIsExist)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入想要更改信息的职工编号：" << endl;
		int i = 0;
		cin >> i;
		int index = this->isPersonExist(i);

		if (index == -1)
		{
			cout << "该职工不存在" << endl;
		}
		else
		{
			delete this->personArray[index];
			int id = 0;
			string name = "";
			int dId = 0;
			cout << "找到编号为 " << i << "的职工，请输入他的新职工编号：" << endl;
			cin >> id;
			cout << "输入新姓名：" << endl;
			cin >> name;
			cout << "输入新岗位编号（1：员工  2：经理  3：老总）：" << endl;
			cin >> dId;

			Worker* worker = NULL;
			switch (dId)
			{
			case 1:
				worker = new Employee(id, name, dId);
				break;
			case 2:
				worker = new Manager(id, name, dId);
				break;
			case 3:
				worker = new Boss(id, name, dId);
				break;
			default:
				break;
			}

			this->personArray[index] = worker;
			cout << "修改成功" << endl;
			this->save();

		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::findPerson()
{
	if (!this->fileIsExist)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		cout << "请输入查找方式：" << endl
			<< "1：按编号查找" << endl
			<< "2：按人名查找" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			cout << "请输入要查找的职工编号：" << endl;
			int id = 0;
			cin >> id;
			int index = this->isPersonExist(id);
			if (index == -1)
			{
				cout << "查无此人" << endl;
			}
			else
			{
				cout << "找到他了" << endl;
				this->personArray[index]->showInfo();
			}
		}
		else if (select == 2)
		{
			cout << "请输入要查找的人名：" << endl;
			string name = "";
			cin >> name;

			bool flag = false;
			for (int i = 0; i <= this->personNum - 1; i++)
			{
				if (this->personArray[i]->m_Name == name)
				{
					flag == true;
					cout << "查找成功，职工编号为 " << this->personArray[i]->m_Id
						<< " 的职工的信息如下：" << endl;
					this->personArray[i]->showInfo();
				}
			}

			if (!flag)
			{
				cout << "查无此人" << endl;
			}
		}
		else
		{
			cout << "输入错误" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::sortPerson()
{
	if (!this->fileIsExist)
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		int select = 0;
		cout << "请选择编号排序方式：" << endl
			<< "1：升序" << endl
			<< "2：降序" << endl;
		cin >> select;

		if (select == 1)
		{
			for (int i = 0; i <= this->personNum - 1; i++)
			{
				for (int j = i + 1; j <= this->personNum - 1; j++)
				{
					if (this->personArray[j]->m_Id < this->personArray[i]->m_Id)
					{
						Worker* temp = NULL;
						temp = this->personArray[j];
						this->personArray[j] = this->personArray[i];
						this->personArray[i] = temp;
					}
				}
			}
			this->save();
			cout << "升序排位成功" << endl;
			this->showPerson();
		}
		else if (select == 2)
		{
			for (int i = 0; i <= this->personNum - 1; i++)
			{
				for (int j = i + 1; j <= this->personNum - 1; j++)
				{
					if (this->personArray[j]->m_Id > this->personArray[i]->m_Id)
					{
						Worker* temp = NULL;
						temp = this->personArray[j];
						this->personArray[j] = this->personArray[i];
						this->personArray[i] = temp;
					}
				}
			}
			this->save();
			cout << "降序排位成功" << endl;
			this->showPerson();
		}
		else
		{
			cout << "输入错误" << endl;
			system("pause");
			system("cls");
		}
	}
}

void WorkerManager::cleanPerson()
{
	int select = 0;
	cout << "真的要清空吗？" << endl
		<< "1：是的" << endl
		<< "2：后悔了" << endl;
	cin >> select;
	if (select == 1)
	{
		if (this->personArray != NULL)
		{
			delete[] this->personArray;
			this->personArray = NULL;
			this->personNum = 0;
			this->fileIsExist = false;
		}
		cout << "清空成功" << endl;
		save();
	}
	system("pause");
	system("cls");
	
}






WorkerManager::~WorkerManager()
{
	if (this->personArray != NULL)
	{
		delete[] this->personArray;
		this->personArray = NULL;
	}
}
