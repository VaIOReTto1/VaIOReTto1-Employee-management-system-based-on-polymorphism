#include"manage.h"

manage::manage(int id, string name, int deptid)
{
	this->Id = id;
	this->Name = name;
	this->Deptid = deptid;
}
void manage::Showinfo()
{
	cout << "ְ����ţ� " << this->Id
		<< "\tְ�������� " << this->Name
		<< "\t��λ�� " << this->GetDeptName()
		<< "\t��λְ�� �·������Ա�����������ܲð���" << endl;
}
string manage::GetDeptName()
{
	return string("����");
}