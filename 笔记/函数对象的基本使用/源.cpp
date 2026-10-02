#include<iostream>
using namespace std;
#include<string>


//函数对象在使用时，可以像普通函数一样调用，可以有参数，可以有返回值
class myadd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};

void test01()
{
	myadd Myadd;
	cout << Myadd(10, 10) << endl;
}

//函数对象可以有自己的状态
class myprint
{
public:
	myprint()
	{
		count = 0;
	}

	void operator()(string test)
	{
		cout << test << endl;
		count++;
	}

	int count;//内部自己的状态
};

void test02()
{
	myprint Myprint;
	Myprint("hello world");
	Myprint("hello world");
	Myprint("hello world");
	Myprint("hello world");
	Myprint("hello world");
	cout << "Myprint调用次数: " <<Myprint.count<< endl;
}

//函数对象可以作为参数传递
void test03(myprint& m, string test)
{
	m(test);
}

void test04()
{
	myprint Myprint;
	test03(Myprint, "hello c++");
}

int main()
{
	test01();
	test02();
	test04();
	system("pause");
	return 0;
}