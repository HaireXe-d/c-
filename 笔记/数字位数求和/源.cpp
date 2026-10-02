#include<iostream>
using namespace std;

int main()
{
	cout << "请输入一个数" << endl;
	int num = 0;
	cin >> num;

	int i = 1;
	if (num <= 999||num>=100)
	{
		int a = 0;
		int b = 0;
		int c = 0;
		a = num / 100;
		b = num % 100 / 10;
		c = num % 10;


		do
		{

			cout << a << "+";

			cout << b << "+";

			cout << c << "=";

			cout << a + b + c << endl;

			i++;

		} while (i <= 1);
	}
	else if (num <= 99||num>=10)
	{
		int a = 0;
		int b = 0;

		a = num / 100;
		b = num % 100 / 10;


		do
		{
			cout << a << "+";

			cout << b << "=";

			cout << a + b << endl;

			i++;

		} while (i <= 1);
	}
	else if (num <= 9)
	{
		cout << num;
	}
	else
	{
		cout << "输入数字有误" << endl;
	}

	system("pause");
	return 0;
}