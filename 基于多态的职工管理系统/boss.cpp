#include"boss.h"

boss::boss(int id, string name, int deptid)
{
	this->Id = id;
	this->Name = name;
	this->Deptid = deptid;
}
void boss::Showinfo()
{
	cout << "ְ����ţ� " << this->Id
		<< "\tְ�������� " << this->Name
		<< "\t��λ�� " << this->GetDeptName()
		<< "\t��λְ�� ����˾��������" << endl;
}
string boss::GetDeptName()
{
	return string("�ܲ�");
}