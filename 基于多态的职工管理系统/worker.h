#pragma once
#include<iostream>
#include<string>
using namespace std;

class worker
{
public:
	virtual void Showinfo() = 0; //显示个人信息
	virtual string GetDeptName() = 0; //获取岗位信息

	int Id;
	string Name;
	int Deptid;
};