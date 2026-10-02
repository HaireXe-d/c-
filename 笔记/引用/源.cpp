#include<iostream>
using namespace std;
//引用传递

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int& test01()
{
	static int a = 10;
	return a;
}


int main()
{
	int a = 10;
	int b = 20;
	swap(a, b);
	cout << a << endl;
	cout << b << endl;

	system("pause");
	//引用做返回值
 
	int& ref = test01();
	cout << ref << endl;
	cout << ref << endl;

	test01() = 1000;
	cout << ref << endl;
	cout << ref << endl;

	system("pause");
	return 0;

}



//引用的本质
/*
int& ref = a就是int* const ref = &a;
ref = b就是*ref = b;


*/