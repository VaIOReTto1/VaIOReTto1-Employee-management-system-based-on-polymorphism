#include"employee.h"

employee::employee(int id, string name, int deptid)
{
	this->Id = id;
	this->Name = name;
	this->Deptid = deptid;
}
void employee::Showinfo()
{
	cout << "职工编号： " << this->Id
		<< "\t职工姓名： " << this->Name
		<< "\t岗位： " << this->GetDeptName()
		<< "\t岗位职责： 完成公司派发的任务" << endl;
}
string employee::GetDeptName()
{
	return string("员工");
}