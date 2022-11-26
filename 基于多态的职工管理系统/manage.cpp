#include"manage.h"

manage::manage(int id, string name, int deptid)
{
	this->Id = id;
	this->Name = name;
	this->Deptid = deptid;
}
void manage::Showinfo()
{
	cout << "职工编号： " << this->Id
		<< "\t职工姓名： " << this->Name
		<< "\t岗位： " << this->GetDeptName()
		<< "\t岗位职责： 下放任务给员工，并听从总裁安排" << endl;
}
string manage::GetDeptName()
{
	return string("经理");
}