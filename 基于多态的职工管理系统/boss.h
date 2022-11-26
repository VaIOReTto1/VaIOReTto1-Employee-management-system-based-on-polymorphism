#pragma once
using namespace std;
#include"worker.h"

class boss :public worker
{
public:
	boss(int id, string name, int deptid);
	void Showinfo();
	string GetDeptName();
};