#include<iostream>
#include"add.h"
using namespace std;

void output()
{
	cout << "×ÜºÍÎª" << endl;
}

/*int add(int num1 = 0, int num2 = 0)
{
	int sum = num1 + num2;
	return sum;
}*/

int main()
{
	output();
	int a = 10;
	int b = 34;
	int c = add(a, b);
		
		cout << c << endl;

		system("pause");
		return 0;
}