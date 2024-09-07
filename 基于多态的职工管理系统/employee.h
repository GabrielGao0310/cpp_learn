#pragma once
#include "worker.h"

class Employee :public Worker
{
public:
	Employee(int id, string name, int deptId);

	void showInfo();
	string getDeptId();
};