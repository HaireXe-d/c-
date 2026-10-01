#include<iostream>
using namespace std;
#include<string>

void test01()
{
	//第一种创建方式
	pair<string, int>p("Tom", 20);
	cout << "姓名： " << p.first << "年龄： " << p.second << endl;

	//第二种
	pair<string, int>p2 = make_pair("jarry", 30);
	cout << "姓名： " << p2.first << "年龄： " << p2.second << endl;

	
}

int main()
{
	test01();
	system("pause");
	return 0;
}