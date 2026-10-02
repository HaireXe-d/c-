#include<iostream>
#include<string>
using namespace std;
int main()
{
	string name[3] = { "张三", "李四", "王五" };

	int arr[3][3] = {
		{100,100,100},
		{70,60,100},
		{80,50,90}
	};

	int sum = 0;

	for (int a = 0; a < 3; a++)
	{
		for (int b = 0; b < 3; b++)
		{
			sum += arr[a][b];
		}
		cout << endl;
		cout << name[a] << "的分数为" << sum << endl;
		sum = 0;
	}
	system("pause");
	return 0;
}