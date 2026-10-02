#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<functional>

//算数仿函数
void test01()
{
	//取反
	negate<int>n;
	cout << n(50) << endl;
	//加法
	plus<int>p;
	cout << p(10, 20) << endl;
	//加法plus,减法minus,乘法multiplies,除法divides
}

//关系仿函数
void test02()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(50);
	v.push_back(40);
	v.push_back(30);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;

	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;

	sort(v.begin(), v.end(),greater<int>());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

//逻辑仿函数
void test03()
{
	vector<bool>v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);
	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;

	vector<bool>v2;
	v2.resize(v.size());

	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

int main()
{
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}