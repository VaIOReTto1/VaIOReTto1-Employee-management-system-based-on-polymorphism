#include"workermanager.h"

Workermanager::Workermanager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		this->Empnum = 0; //��ʼ������Ϊ0
		this->EmpArray = NULL;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	// �ж��ļ��Ƿ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		this->Empnum = 0; 
		this->EmpArray = NULL;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	int num = this->GetEmpnum();
	cout << "ְ������Ϊ: " << num << endl;
	this->Empnum = num;
	this->EmpArray = new worker*[this->Empnum]; //���ٿռ�
	this->init_Emp(); //���ļ����ݴ浽������
	for (int i = 0; i < this->Empnum; i++)
	{
		cout << "ְ����ţ� " << this->EmpArray[i]->Id
			<< "  ְ�����֣� " << this->EmpArray[i]->Name
			<< "  ְ�����ű�ţ� " << this->EmpArray[i]->Deptid << endl;
	}
}


void Workermanager::Show_menu()
{
	cout << "                                                          " << endl;
	cout << "                ��ӭʹ��ְ������ϵͳ��                    " << endl;
	cout << "                   0.�˳�����ϵͳ                         " << endl;
	cout << "                   1.����ְ����Ϣ                         " << endl;
	cout << "                   2.��ʾְ����Ϣ                         " << endl;
	cout << "                   3.ɾ��ְ����Ϣ                         " << endl;
	cout << "                   4.�޸�ְ����Ϣ                         " << endl;
	cout << "                   5.����ְ����Ϣ                         " << endl;
	cout << "                   6.���ձ������                         " << endl;
	cout << "                   7.��������ĵ�                         " << endl;
	cout << "                                                          " << endl;
	cout << endl;
}

void Workermanager::Exit()
{
	cout << "���˳�ְ������ϵͳ����ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void Workermanager::Add_Emp()
{
	cout << "���������ְ�������� " << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->Empnum + addNum; //�¿ռ�����=ԭ����+�µ�
		worker**newSpace=new worker*[newSize];
		if (this->EmpArray != NULL)
		{
			for (int i = 0; i < this->Empnum; i++) //��ԭ���ݲ����¿ռ�
			{
				newSpace[i] = this->EmpArray[i];
			}
		}
		for (int i = 0; i < addNum; i++) //���������
		{
			int id;
			string name;
			int dselect; //����
			cout << "�������" << i + 1 << "����ְ�����" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ������" << endl;
			cin >> name;
			cout << "��ѡ���Ա����λ�� " << endl;
			cout << "1.Ա��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ܲ�" << endl;
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
		delete[] this->EmpArray; //�ͷ�ԭ�пռ�
		this->EmpArray = newSpace; //�����¿ռ��ָ��
		this->Empnum = newSize; //�����µ�ְ������
		this->FileIsEmpty = false; //����ְ����Ϊ�ձ�־
		cout << "�ɹ����" << addNum << "����ְ��" << endl;
		this->save(); //�������ݵ��ļ���
	}
	else
	{
		cout << "������������" << endl;
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
		cout << "�ļ������ڻ�Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		for (int i = 0; i < Empnum; i++)
		{
			this->EmpArray[i]->Showinfo(); //���ö�̬���ó���ӿ�
		}
	}
	system("pause");
	system("cls");
}

void Workermanager::del_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	else
	{
		cout << "Ҫɾ����ְ����ţ� " << endl;
		int id;
		cin >> id;
		int index = this->Isexit(id);
		if (index != -1) //Ѱ�ҵ�ְ��
		{
			for (int i = index; i < this->Empnum - 1; i++)
			{
				this->EmpArray[i] = this->EmpArray[i + 1]; //����ǰ��
			}
			this->Empnum--; //����������ְ������
			this->save(); //�����ݸ���ͬ�����ļ���
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δѰ�ҵ���ְ��" << endl;
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
		index = i; //Ѱ��ְ��
		break;
	}
	return index;
}

void Workermanager::mod_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı�ţ�" << endl;
		int id;
		cin >> id;
		int ret = this->Isexit(id);
		if (ret != -1) 
		{
			delete this->EmpArray[ret]; //���ø�ְ����Ϣ
			int newId;
			string newName;
			int dSelect;
			cout << "�鵽�� " << id << "��ְ������������ְ���ţ� " << endl;
			cin >> newId;
			cout << "�������������� " << endl;
			cin >> newName;
			cout << "��ѡ���Ա����λ�� " << endl;
			cout << "1.Ա��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ܲ�" << endl;
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
			this->EmpArray[ret] = worker; //�������ݵ�������
			cout << "�޸ĳɹ�" << endl;
			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}

void Workermanager::fine_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ�� " << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.��ְ����������" << endl;
		int input = 0;
		cin >> input;
		switch (input)
		{
		case 1:
		{
				  int id;
				  cout << "��������ҵ�ְ����ţ� " << endl;
				  cin >> id;
				  int ret = Isexit(id);
				  if (ret != -1)
				  {
					  cout << "���ҳɹ�����ְ����Ϣ���£� " << endl;
					  this->EmpArray[ret]->Showinfo();
				  }
				  else
				  {
					  cout << "���޴���" << endl;
				  }
				  break;
		} //c/c++��switch�����ֶ������ô�����������
		case 2:
		{
				  string name;
				  cout << "��������ҵ�ְ�������� " << endl;
				  cin >> name;
				  bool flag = false;  //�ж��Ƿ�鵽
				  for (int i = 0; i < Empnum; i++)
				  {
					  if (this->EmpArray[i]->Name == name)
					  {
						  cout << "���ҳɹ���ְ�����Ϊ��" << this->EmpArray[i]->Id
							  << "��ְ����Ϣ���£� " << endl;
						  flag = true;
						  this->EmpArray[i]->Showinfo();
					  }
				  }
				  if (flag == false)
				  {
					  cout << "���޴���" << endl;
				  }
				  break;
		}
		default:
			cout << "����ѡ������" << endl;
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
		cout << "�ļ������ڻ�Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1.��ְ����Ž�������" << endl;
		cout << "2.��ְ����Ž��н���" << endl;
		int input;
		cin >> input;
		for (int i = 0; i < Empnum; i++)
		{
			int minORmax = i; //�������ֵ����Сֵ�±�
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
					cout << "����ѡ������" << endl;
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
	cout << "����ɹ����������Ϊ��" << endl;
	this->save();
	this->show_Emp(); //�Ѱ�����������
}

void Workermanager::clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "0.����" << endl;
	int input;
	cin >> input;
	switch (input)
	{
	case 1:
	{
			  ofstream ofs(FILENAME, ios::trunc); //ɾ���ļ������´���
			  ofs.close();
			  if (this->EmpArray != NULL)
			  {
				  for (int i = 0; i < this->Empnum; i++) //ɾ��������ְ��
				  {
					  delete this->EmpArray[i];
					  this->EmpArray[i] = NULL;
				  }
				  delete[] this->EmpArray; //ɾ������������ָ��
				  this->EmpArray = NULL;
				  this->Empnum = 0;
				  this->FileIsEmpty = true;
			  }
			  cout << "ɾ���ɹ�" << endl;
			  break;
	}
		case 0:
			break;
		default:
			cout << "����ѡ������" << endl;
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