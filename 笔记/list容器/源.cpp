#include<iostream>
using namespace std;
#include<list>

void printlist(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

//构造
void test01()
{
	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printlist(L1);

	//
	list<int> L2(L1.begin(), L1.end());
	printlist(L2);

	//
	list<int>L3(L2);
	printlist(L3);

	//
	list<int> L4(10,1000);
	printlist(L4);

}

//赋值
void test02()
{
	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printlist(L1);

	//
	list<int> L2;
	L2 = L1;
	printlist(L2);

	//
	list<int> L3;
	L3.assign(L2.begin(), L2.end());
	printlist(L3);

	//
	list<int> L4;
	L4.assign(10, 1000);
	printlist(L4);


}

//交换
void test03()
{
	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	list<int> L2;
	L2.assign(10, 1000);

	cout << "交换前" << endl;
	printlist(L1);
	printlist(L2);

	cout << endl;

	L1.swap(L2);
	cout << "交换后" << endl;
	printlist(L1);
}

//大小操作
void test04()
{
	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	if (L1.empty())
	{
		cout << "L1为空" << endl;

	}
	else
	{
		cout << "L1不为空" << endl;
		cout << "L1的大小为：" << L1.size() << endl;
	}

	//重新指定大小
	L1.resize(10);
	printlist(L1);

	L1.resize(2);
	printlist(L1);
}

//list的插入和删除
void test05()
{
	//尾插
	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	//头插
	L1.push_front(100);
	L1.push_front(200);
	L1.push_front(300);
	printlist(L1);

	//尾删
	L1.pop_back();
	printlist(L1);

	//头删
	L1.pop_front();
	printlist(L1);

	//插入
	list<int>::iterator it = L1.begin();
	L1.insert(++it, 1000);
	printlist(L1);

	//删除
	it = L1.begin();
	L1.erase(++it);
	printlist(L1);

	//移除
	L1.push_back(10000);
	L1.push_back(10000);
	L1.push_back(10000);
	printlist(L1);
	L1.remove(10000);
	printlist(L1);

	//清空
	L1.clear();
	printlist(L1);
}

//数据存取
void test06()
{
	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	cout << "第一个元素是：" << L1.front() << endl;
	cout << "最后一个元素是：" << L1.back() << endl;

	//list的迭代器为双向迭代器，不支持随机访问
	list<int>::iterator it = L1.begin();
	//it = it+1错误，不可以跳跃访问

}

//反转和排序
bool myCompare(int val1, int val2)
{
	return val1 > val2;
}

//
void test07()
{
	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printlist(L1);

	//反转容器中的元素
	L1.reverse();
	printlist(L1);

	//排序
	L1.sort();
	printlist(L1);

	//指定规则，从大到小
	L1.sort(myCompare);
	printlist(L1);

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
	system("pause");
	return 0;
}