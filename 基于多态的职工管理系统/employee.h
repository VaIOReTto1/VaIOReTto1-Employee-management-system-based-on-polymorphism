#pragma once
#include"worker.h"
using namespace std;

class employee :public worker
{
public:
	employee(int id,string name,int deptid);//��������Ҫ������һ�£��������׳���
	void Showinfo(); //�ǵ�ɾ��virtual������worlermanager.cpp�����
	string GetDeptName();
};