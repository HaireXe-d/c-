#include<iostream>
using namespace std;
#include"workerManager.h"
#include"boss.h"
#include"manager.h"
#include"employee.h"
#include"worker.h"


int main()
{
	WorkerManager wm;

	int choice = 0;

	while (true)
	{
		wm.showmenu();
		cout << "请输入您的选项" << endl;
		cin >> choice;


		switch (choice)
		{
		case 0:
			wm.exitsystem();
			break;
		case 1:
			wm.add_emp();
			break;
		case 2:
			wm.showemp();
			break;
		case 3:
			wm.delemp();
			break;
		case 4:
			wm.modemp();
			break;
		case 5:
			wm.findemp();
			break;
		case 6:
			wm.sortemp();
			break;
		case 7:
			wm.cleanall();
			break;
		default:
			system("cls");
			break;
		}

	}


	

	system("pause");
	return 0;

}