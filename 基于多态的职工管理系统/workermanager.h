#pragma once //��ֹͷ�ļ��ظ�����
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
	int Empnum; //ְ������
	worker **EmpArray;//ְ������ָ��
	void Add_Emp();
	void save(); //�����ļ�
	bool FileIsEmpty; //�ж��ļ��Ƿ�Ϊ��
	int GetEmpnum(); //ͳ������
	void init_Emp(); //��ʼ��ְ��
	void show_Emp(); //��ʾְ��
	void del_Emp(); //ɾ��ְ��
	int Isexit(int id); //�ж�ְ���Ƿ����
	void mod_Emp(); //�޸�ְ��
	void fine_Emp(); //����ְ��
	void sort_Emp(); //���������ְ��
	void clean_File(); //����ļ����Ʋ���·
	~Workermanager();
};