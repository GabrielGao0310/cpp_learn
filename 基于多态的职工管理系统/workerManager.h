#pragma once	// ��ֹͷ�ļ��ظ�����
#include <iostream>
using namespace std;	// ʹ�ñ�׼�����ռ�
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>

#define FILENAME "workers_list.txt"

class WorkerManager
{
public:
	WorkerManager();

	void Show_Menu();

	void ExitSystem();

	void addPerson();

	void save();

	int get_filePersonNum();

	void init_personArray();

	void showPerson();

	int isPersonExist(int id);

	void deletePerson();

	void modifyPerson();

	void findPerson();

	void sortPerson();

	void cleanPerson();


	~WorkerManager();

	int personNum;
	Worker** personArray;
	bool fileIsExist;
};