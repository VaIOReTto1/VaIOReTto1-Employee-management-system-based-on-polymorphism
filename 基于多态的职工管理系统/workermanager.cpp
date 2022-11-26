#include"workermanager.h"

Workermanager::Workermanager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->Empnum = 0; //初始化人数为0
		this->EmpArray = NULL;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	// 判断文件是否为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->Empnum = 0; 
		this->EmpArray = NULL;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	int num = this->GetEmpnum();
	cout << "职工人数为: " << num << endl;
	this->Empnum = num;
	this->EmpArray = new worker*[this->Empnum]; //开辟空间
	this->init_Emp(); //将文件数据存到数组中
	for (int i = 0; i < this->Empnum; i++)
	{
		cout << "职工编号： " << this->EmpArray[i]->Id
			<< "  职工名字： " << this->EmpArray[i]->Name
			<< "  职工部门编号： " << this->EmpArray[i]->Deptid << endl;
	}
}


void Workermanager::Show_menu()
{
	cout << "                                                          " << endl;
	cout << "                欢迎使用职工管理系统！                    " << endl;
	cout << "                   0.退出管理系统                         " << endl;
	cout << "                   1.增加职工信息                         " << endl;
	cout << "                   2.显示职工信息                         " << endl;
	cout << "                   3.删除职工信息                         " << endl;
	cout << "                   4.修改职工信息                         " << endl;
	cout << "                   5.查找职工信息                         " << endl;
	cout << "                   6.按照编号排序                         " << endl;
	cout << "                   7.清空所有文档                         " << endl;
	cout << "                                                          " << endl;
	cout << endl;
}

void Workermanager::Exit()
{
	cout << "已退出职工管理系统，欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void Workermanager::Add_Emp()
{
	cout << "请输入添加职工数量： " << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->Empnum + addNum; //新空间人数=原来的+新的
		worker**newSpace=new worker*[newSize];
		if (this->EmpArray != NULL)
		{
			for (int i = 0; i < this->Empnum; i++) //将原数据并入新空间
			{
				newSpace[i] = this->EmpArray[i];
			}
		}
		for (int i = 0; i < addNum; i++) //添加新数据
		{
			int id;
			string name;
			int dselect; //部门
			cout << "请输入第" << i + 1 << "个新职工编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工名字" << endl;
			cin >> name;
			cout << "请选择该员工岗位： " << endl;
			cout << "1.员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.总裁" << endl;
			cin >> dselect;
			worker *worker = NULL;
			switch (dselect)
			{
			case 1:
				worker = new employee(id, name, 1);
				break;
			case 2:
				worker = new manage(id, name, 2);
				break;
			case 3:
				worker = new boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->Empnum + i] = worker;
		}
		delete[] this->EmpArray; //释放原有空间
		this->EmpArray = newSpace; //更改新空间的指向
		this->Empnum = newSize; //更新新的职工人数
		this->FileIsEmpty = false; //更新职工不为空标志
		cout << "成功添加" << addNum << "名新职工" << endl;
		this->save(); //保存数据到文件中
	}
	else
	{
		cout << "输入数据有误" << endl;
	}
	system("pause");
	system("cls");
}

void Workermanager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->Empnum; i++)
	{
		ofs << this->EmpArray[i]->Id << " "
			<< this->EmpArray[i]->Name << " "
			<< this->EmpArray[i]->Deptid << endl;
		ofs.close();
	}
}

int Workermanager::GetEmpnum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int deptid;
	int num=0;
	while (ifs >> id&&ifs >> name&&ifs >> deptid)
	{
		num++;
	}
	return num;
}

void Workermanager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int deptid;
	int index = 0;
	while (ifs >> id&&ifs >> name&&ifs >> deptid)
	{
		worker *worker = NULL;
		if (deptid == 1)
		{
			worker = new employee(id, name, deptid);
		}
		else if (deptid == 2)
		{
			worker = new manage(id, name, deptid);
		}
		else
		{
			worker = new boss(id, name, deptid);
		}
		this->EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

void Workermanager::show_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		for (int i = 0; i < Empnum; i++)
		{
			this->EmpArray[i]->Showinfo(); //利用多态调用程序接口
		}
	}
	system("pause");
	system("cls");
}

void Workermanager::del_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		cout << "要删除的职工编号： " << endl;
		int id;
		cin >> id;
		int index = this->Isexit(id);
		if (index != -1) //寻找到职工
		{
			for (int i = index; i < this->Empnum - 1; i++)
			{
				this->EmpArray[i] = this->EmpArray[i + 1]; //数据前移
			}
			this->Empnum--; //更新数组中职工人数
			this->save(); //将数据更新同步到文件中
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败，未寻找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}

int Workermanager::Isexit(int id)
{
	int index = -1;
	for (int i = 0; i < this->Empnum; i++)
	{
		index = i; //寻找职工
		break;
	}
	return index;
}

void Workermanager::mod_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >> id;
		int ret = this->Isexit(id);
		if (ret != -1) 
		{
			delete this->EmpArray[ret]; //重置该职工信息
			int newId;
			string newName;
			int dSelect;
			cout << "查到： " << id << "号职工，请输入新职工号： " << endl;
			cin >> newId;
			cout << "请输入新姓名： " << endl;
			cin >> newName;
			cout << "请选择该员工岗位： " << endl;
			cout << "1.员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.总裁" << endl;
			cin >> dSelect;
			worker *worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new manage(newId, newName, dSelect);
				break;
			case 3:
				worker = new boss(newId, newName, dSelect);
				break;
			default:
				break;
			}
			this->EmpArray[ret] = worker; //更新数据到数组中
			cout << "修改成功" << endl;
			this->save();
		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}

void Workermanager::fine_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		cout << "请输入查找的方式： " << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按职工姓名查找" << endl;
		int input = 0;
		cin >> input;
		switch (input)
		{
		case 1:
		{
				  int id;
				  cout << "请输入查找的职工编号： " << endl;
				  cin >> id;
				  int ret = Isexit(id);
				  if (ret != -1)
				  {
					  cout << "查找成功，该职工信息如下： " << endl;
					  this->EmpArray[ret]->Showinfo();
				  }
				  else
				  {
					  cout << "查无此人" << endl;
				  }
				  break;
		} //c/c++中switch语句出现定义需用大括号括起来
		case 2:
		{
				  string name;
				  cout << "请输入查找的职工姓名： " << endl;
				  cin >> name;
				  bool flag = false;  //判断是否查到
				  for (int i = 0; i < Empnum; i++)
				  {
					  if (this->EmpArray[i]->Name == name)
					  {
						  cout << "查找成功，职工编号为：" << this->EmpArray[i]->Id
							  << "号职工信息如下： " << endl;
						  flag = true;
						  this->EmpArray[i]->Showinfo();
					  }
				  }
				  if (flag == false)
				  {
					  cout << "查无此人" << endl;
				  }
				  break;
		}
		default:
			cout << "输入选项有误" << endl;
			break;
		}
	}
	system("pause");
	system("cls");
}


void Workermanager::sort_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1.按职工编号进行升序" << endl;
		cout << "2.按职工编号进行降序" << endl;
		int input;
		cin >> input;
		for (int i = 0; i < Empnum; i++)
		{
			int minORmax = i; //声明最大值或最小值下标
			for (int j = i + 1; j < this->Empnum; j++)
			{
				switch (input)
				{
				case 1:
					if (this->EmpArray[minORmax]->Id>this->EmpArray[j]->Id)
						minORmax = j;
					break;
				case 2:
					if (this->EmpArray[minORmax]->Id<this->EmpArray[j]->Id)
						minORmax = j;
					break;
				default:
					cout << "输入选项有误" << endl;
					break;
				}
			}
			if (i != minORmax)
			{
				worker *temp = this->EmpArray[i];
				this->EmpArray[i] = this->EmpArray[minORmax];
				this->EmpArray[minORmax] = temp;
			}
		}
	}
	cout << "排序成功，排序后结果为：" << endl;
	this->save();
	this->show_Emp(); //已包含清屏操作
}

void Workermanager::clean_File()
{
	cout << "确定清空？" << endl;
	cout << "1.确定" << endl;
	cout << "0.返回" << endl;
	int input;
	cin >> input;
	switch (input)
	{
	case 1:
	{
			  ofstream ofs(FILENAME, ios::trunc); //删除文件后重新创建
			  ofs.close();
			  if (this->EmpArray != NULL)
			  {
				  for (int i = 0; i < this->Empnum; i++) //删除堆区的职工
				  {
					  delete this->EmpArray[i];
					  this->EmpArray[i] = NULL;
				  }
				  delete[] this->EmpArray; //删除堆区的数组指针
				  this->EmpArray = NULL;
				  this->Empnum = 0;
				  this->FileIsEmpty = true;
			  }
			  cout << "删除成功" << endl;
			  break;
	}
		case 0:
			break;
		default:
			cout << "输入选项有误" << endl;
			break;
	}
	system("pause");
	system("cls");
}

Workermanager::~Workermanager()
{
	if (this->EmpArray != NULL)
	{
		delete[] this->EmpArray;
		this->EmpArray = NULL;
	}
}