#include<iostream>
using namespace std;
#include"Myarray.hpp"

void printintarr(Myarray <int>& arr)
{
	for (int i = 0; i < arr.getsize(); i++)
	{
		cout << arr[i] << endl;
	}
}



void test01()
{
	Myarray <int>arr1(5);
	for (int i = 0; i < 5; i++)
	{
		arr1.push_back(i);
		
	}
	cout << "arr1的打印输出：" << endl;
	printintarr(arr1);
	cout << "arr1的容量：" << arr1.getcapacity() << endl;
	cout << "arr1的大小：" << arr1.getsize() << endl;
	Myarray <int>arr2(arr1);
	cout << "arr2的打印输出：" << endl;
	arr2.pop_back();
	printintarr(arr2);
	cout << "arr2尾删后" << endl;
	cout << "arr1的容量：" << arr2.getcapacity() << endl;
	cout << "arr1的大小：" << arr2.getsize() << endl;
}



int main()
{

	test01();
	system("pause");
	return 0;
}