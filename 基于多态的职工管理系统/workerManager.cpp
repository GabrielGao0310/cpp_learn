#include "workerManager.h"

WorkerManager::WorkerManager()
{

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
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
		cout << "���ļ�Ϊ��" << endl;
		this->fileIsExist = false;
		this->personArray = NULL;
		this->personNum = 0;
		ifs.close();
		return;
	}

	int num = this->get_filePersonNum();
	cout << "�ļ����ѱ���ְ��������" << num << endl;
	this->personNum = num;
	this->fileIsExist = true;

	this->personArray = new Worker * [num];
	this->init_personArray();

	for (int i = 0; i <= num - 1; i++)
	{
		cout << "ְ����ţ�" << this->personArray[i]->m_Id
			<< "\tְ��������" << this->personArray[i]->m_Name
			<< "\tְ����λ��" << this->personArray[i]->getDeptId() << endl;

	}


}

void WorkerManager::Show_Menu()
{
	cout << "**************************" << endl;
	cout << "** ��ӭʹ��ְ������ϵͳ **" << endl;
	cout << "***** 0.�˳�������� *****" << endl;
	cout << "***** 1.����ְ����Ϣ *****" << endl;
	cout << "***** 2.��ʾְ����Ϣ *****" << endl;
	cout << "***** 3.ɾ��ְ����Ϣ *****" << endl;
	cout << "***** 4.�޸�ְ����Ϣ *****" << endl;
	cout << "***** 5.����ְ����Ϣ *****" << endl;
	cout << "***** 6.���ձ������� *****" << endl;
	cout << "***** 7.��������ĵ� *****" << endl;
	cout << "**************************" << endl;
	cout << endl;
}

void WorkerManager::ExitSystem()
{
	cout << "�㽫�˳�ϵͳ����ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::addPerson()
{
	cout << "������Ҫ��ӵ�����" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum <= 0)
	{
		cout << "��������" << endl;
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

			cout << "�������" << i + 1 << "��ְ���ı��" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "��ְ��������" << endl;
			cin >> name; 

			while (true)
			{
				cout << "�������" << i + 1 << "��ְ���ĸ�λ��1��Ա�� 2������ 3���ܲã�" << endl;
				cin >> dId;
				if (dId == 1 || dId == 2 || dId == 3)
				{
					break;
				}
				else
				{
					cout << "�������" << endl;
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




		cout << "��ӳɹ�" << endl;
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
		cout << "ְ�������ļ������ڻ��߼�¼Ϊ��" << endl;
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "����������ɾ����ְ���ı�ţ�" << endl;
		int i;
		cin >> i;
		int index = this->isPersonExist(i);
		if (index == -1)
		{
			cout << "�ñ�Ų�����" << endl;
		}
		else
		{
			for (int j = index; j <= this->personNum - 2; j++)
			{
				this->personArray[j] = this->personArray[j + 1];
			}
			cout << "ɾ���ɹ�" << endl;
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������Ҫ������Ϣ��ְ����ţ�" << endl;
		int i = 0;
		cin >> i;
		int index = this->isPersonExist(i);

		if (index == -1)
		{
			cout << "��ְ��������" << endl;
		}
		else
		{
			delete this->personArray[index];
			int id = 0;
			string name = "";
			int dId = 0;
			cout << "�ҵ����Ϊ " << i << "��ְ����������������ְ����ţ�" << endl;
			cin >> id;
			cout << "������������" << endl;
			cin >> name;
			cout << "�����¸�λ��ţ�1��Ա��  2������  3�����ܣ���" << endl;
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
			cout << "�޸ĳɹ�" << endl;
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
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ��" << endl
			<< "1������Ų���" << endl
			<< "2������������" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			cout << "������Ҫ���ҵ�ְ����ţ�" << endl;
			int id = 0;
			cin >> id;
			int index = this->isPersonExist(id);
			if (index == -1)
			{
				cout << "���޴���" << endl;
			}
			else
			{
				cout << "�ҵ�����" << endl;
				this->personArray[index]->showInfo();
			}
		}
		else if (select == 2)
		{
			cout << "������Ҫ���ҵ�������" << endl;
			string name = "";
			cin >> name;

			bool flag = false;
			for (int i = 0; i <= this->personNum - 1; i++)
			{
				if (this->personArray[i]->m_Name == name)
				{
					flag == true;
					cout << "���ҳɹ���ְ�����Ϊ " << this->personArray[i]->m_Id
						<< " ��ְ������Ϣ���£�" << endl;
					this->personArray[i]->showInfo();
				}
			}

			if (!flag)
			{
				cout << "���޴���" << endl;
			}
		}
		else
		{
			cout << "�������" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::sortPerson()
{
	if (!this->fileIsExist)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		int select = 0;
		cout << "��ѡ��������ʽ��" << endl
			<< "1������" << endl
			<< "2������" << endl;
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
			cout << "������λ�ɹ�" << endl;
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
			cout << "������λ�ɹ�" << endl;
			this->showPerson();
		}
		else
		{
			cout << "�������" << endl;
			system("pause");
			system("cls");
		}
	}
}

void WorkerManager::cleanPerson()
{
	int select = 0;
	cout << "���Ҫ�����" << endl
		<< "1���ǵ�" << endl
		<< "2�������" << endl;
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
		cout << "��ճɹ�" << endl;
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
