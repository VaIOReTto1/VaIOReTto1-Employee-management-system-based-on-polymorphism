#pragma once //防止头文件重复包含
#include"worker.h"
#include"employee.h"
#include"boss.h"
#include"manage.h"
#include<fstream>
#define FILENAME "empFile.text"
using namespace std;

class Workermanager
{
public:
	Workermanager();
	void Show_menu();
	void Exit();
	int Empnum; //职工人数
	worker **EmpArray;//职工数组指针
	void Add_Emp();
	void save(); //保存文件
	bool FileIsEmpty; //判断文件是否为空
	int GetEmpnum(); //统计人数
	void init_Emp(); //初始化职工
	void show_Emp(); //显示职工
	void del_Emp(); //删除职工
	int Isexit(int id); //判断职工是否存在
	void mod_Emp(); //修改职工
	void fine_Emp(); //查找职工
	void sort_Emp(); //按编号排序职工
	void clean_File(); //清空文件（破产跑路
	~Workermanager();
};