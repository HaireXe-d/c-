#include<iostream>
using namespace std;
int main()
{
	for (int a = 0; a <= 100; a++)
	{
		if (a % 7 == 0 || a % 10 == 7 || a / 10 == 7)
		{
			cout << "ÇÃ×À×Ó" << endl;
		}
		else {
			cout << a << endl;
		}
	}
	system("pause");
	return 0;
}