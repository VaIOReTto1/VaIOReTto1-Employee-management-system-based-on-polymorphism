#include"employee.h"

employee::employee(int id, string name, int deptid)
{
	this->Id = id;
	this->Name = name;
	this->Deptid = deptid;
}
void employee::Showinfo()
{
	cout << "ְ����ţ� " << this->Id
		<< "\tְ�������� " << this->Name
		<< "\t��λ�� " << this->GetDeptName()
		<< "\t��λְ�� ��ɹ�˾�ɷ�������" << endl;
}
string employee::GetDeptName()
{
	return string("Ա��");
}