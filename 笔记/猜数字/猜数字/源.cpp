#include<iostream>
#include<ctime>
using namespace std;
int main()
{
	srand((unsigned int)time(NULL));
	int num = rand() % 100 + 1;
	cout << "猜数字" << endl;
	
	while (1)
	{
		int val = 0;
		cin >> val;
		if (num > val)
		{
			cout << "小了" << endl;
		}
		else if (num < val) {
			cout << "大了" << endl;
		}
		else {
			cout << "猜对了" << endl;
			break;
		}
		
	}
	system("pause");
	return 0;
}