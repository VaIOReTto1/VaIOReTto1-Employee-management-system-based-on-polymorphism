#include"workermanager.h"
#include"boss.h"
#include"employee.h"
#include"manage.h"
#include"worker.h"
using namespace std;

int main()
{
	Workermanager WM;
	int input;
	while (1)
	{
		WM.Show_menu();
		cout << "请输入你的选择:>  ";
		cin >> input;
		switch (input)
		{
		case 0:
			WM.Exit();
			break;
		case 1:
			WM.Add_Emp();
			break;
		case 2:
			WM.show_Emp();
			break;
		case 3:
			WM.del_Emp();
			break;
		case 4:
			WM.mod_Emp();
			break;
		case 5:
			WM.fine_Emp();
			break;
		case 6:
			WM.sort_Emp();
			break;
		case 7:
			WM.clean_File();
			break;
		default:
			system("cls"); //清屏
			break;
		}
	}
	system("pause");
	return 0;

}