#pragma once
#include<iostream>
#include<string>
using namespace std;

class worker
{
public:
	virtual void Showinfo() = 0; //��ʾ������Ϣ
	virtual string GetDeptName() = 0; //��ȡ��λ��Ϣ

	int Id;
	string Name;
	int Deptid;
};