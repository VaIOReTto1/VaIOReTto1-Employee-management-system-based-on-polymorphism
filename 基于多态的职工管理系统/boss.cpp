#include"boss.h"

boss::boss(int id, string name, int deptid)
{
	this->Id = id;
	this->Name = name;
	this->Deptid = deptid;
}
void boss::Showinfo()
{
	cout << "职工编号： " << this->Id
		<< "\t职工姓名： " << this->Name
		<< "\t岗位： " << this->GetDeptName()
		<< "\t岗位职责： 管理公司各项事务" << endl;
}
string boss::GetDeptName()
{
	return string("总裁");
}