#pragma once
#include"worker.h"
using namespace std;

class employee :public worker
{
public:
	employee(int id,string name,int deptid);//函数名需要与类名一致，或者容易出错
	void Showinfo(); //记得删掉virtual，否则worlermanager.cpp会出错
	string GetDeptName();
};