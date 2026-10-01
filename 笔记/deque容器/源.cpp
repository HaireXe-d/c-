#include<iostream>
#include<deque>
using namespace std;
#include<algorithm>

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

//deque的构造
void test01()
{
	//无参构造函数
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	//
	deque<int> d2(d1.begin(), d1.end());
	printDeque(d2);

	//
	deque<int> d3(10, 100);
	printDeque(d3);

	//
	deque<int> d4 = d3;
	printDeque(d4);
}

//deque的赋值
void test02()
{
	//
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	//
	deque<int> d2;
	d2 = d1;
	printDeque(d2);

	//
	deque<int> d3;
	d3.assign(d1.begin(), d1.end());
	printDeque(d3);

	//
	deque<int>d4;
	d4.assign(10, 100);
	printDeque(d4);
}

//deque的大小操作
void test03()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	//判断容器是否为空
	if (d1.empty())
	{
		cout << "d1为空" << endl;
	}
	else
	{
		cout << "d1不为空" << endl;
		//统计大小
		cout << "d1的大小为：" << d1.size() << endl;
	}
	//重新指定大小
	d1.resize(15, 1);
	printDeque(d1);
	d1.resize(5);
	printDeque(d1);
}

//deque的插入与删除
//两端插入
void test04()
{
	deque<int> d;
	//尾插
	d.push_back(10);
	d.push_back(20);
	//头插
	d.push_front(100);
	d.push_front(200);
	printDeque(d);
	//尾删
	d.pop_back();
	//头删
	d.pop_front();
	printDeque(d);

}
//插入
void test05()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	printDeque(d);
	d.insert(d.begin(), 1000);
	printDeque(d);
	d.insert(d.begin(), 2, 10000);
	printDeque(d);

	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);
	d.insert(d.begin(), d2.begin(), d2.end());
	printDeque(d);
}
//删除
void test06()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	printDeque(d);

	d.erase(d.begin());
	printDeque(d);
	d.erase(d.begin(), d.end());
	//或d.claer();
	printDeque(d);
}

//数据存取
void test07()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << "  ";
	}
	cout << endl;
	//
	for (int i = 0; i < d.size(); i++)
	{
		cout << d.at(i) << "  ";
	}
	cout << endl;

	cout << "front:" << d.front() << endl;
	cout << "back:" << d.back() << endl;
}

//deque排序
void test08()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	printDeque(d);

	sort(d.begin(), d.end());
	printDeque(d);
}


int main()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	test08();
	system("pause");
	return 0;
}