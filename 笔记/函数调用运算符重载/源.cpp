#include<iostream>
#include<string>
using namespace std;

class myprint
{
public:
	void operator()(string test)
	{
		cout << test << endl;
	}
};

class myadd
{
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}

};

void test01()
{
	myprint myprint;
	myprint("hello world");
}

void test02()
{
	myadd myAdd;
	int ret = myAdd(100, 100);
	cout << ret << endl;
	//ÄäÃû
	cout << myadd()(100, 100) << endl;

}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}