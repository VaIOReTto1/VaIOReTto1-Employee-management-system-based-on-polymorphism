#pragma once
#include"worker.h"
using namespace std;

class manage :public worker
{
public:
	manage(int id, string name, int deptid);
	void Showinfo();
	string GetDeptName();
};