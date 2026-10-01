#include<iostream>
using namespace std;
#include"speechManager.h"
#include<string>
#include<ctime>

int main()
{
	srand((unsigned int)time(NULL));

	speechManager sm;

	int choice = 0;

	while (true)
	{
		sm.show_menu();
		cout << "ÇëÊäÈëÄúµÄÑ¡Ôñ£º " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			sm.startspeech();
			break;
		case 2:
			sm.showrecord();
			break;
		case 3:
			sm.clearrecord();
			break;
		case 0:
			sm.exitsystem();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}