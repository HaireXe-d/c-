#include<iostream>
using namespace std;
#include<map>

void printmap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "ker = " << (*it).first << " value = " << it->second << endl;
	}
	cout << endl;
}



//构造和赋值
void test01()
{
	map<int, int>m;

	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	printmap(m);

	//拷贝构造
	map<int, int>m2(m);
	printmap(m);

	//赋值
	map<int, int>m3;
	m3 = m2;
	printmap(m);
}

//大小
void test02()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	printmap(m);

	if (m.empty())
	{
		cout << "m为空" << endl;
	}
	else
	{
		cout << "m不为空" << endl;
		cout << "m的大小为： " << m.size() << endl;
	}
}

//交换
void test03()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));

	map<int, int>m2;
	m2.insert(pair<int, int>(1, 100));
	m2.insert(pair<int, int>(2, 200));
	m2.insert(pair<int, int>(3, 300));

	cout << "交换前：" << endl;
	printmap(m);
	printmap(m2);

	m.swap(m2);

	cout << "交换后：" << endl;
	printmap(m);
	printmap(m2);
}

//插入和删除
void test04()
{
	//插入
	map<int, int>m;
	//第一种
	m.insert(pair<int, int>(1, 10));
	//第二种
	m.insert(make_pair(2, 20));
	//第三种
	m.insert(map<int, int>::value_type(3, 30));
	//第四种(一般用于访问，不用于创建）
	m[4] = 40;

	//删除
	m.erase(m.begin());
	printmap(m);

	m.erase(3);
	printmap(m);

	//清空
	//m.erase(m.begin(), m.end());
	m.clear();
	printmap(m);
}

//查找和统计
void test05()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	//查找
	map<int, int>::iterator pos = m.find(3);
	if (pos != m.end())
	{
		cout << "查到了元素 key = " << (*pos).first << " value =  " << pos->second << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}

	//统计
	//map不允许插入重复key元素，对于count统计而言，结果要么是0 要么是1
	//multimap 统计可以大于1
	int num = m.count(3);
	cout << "num = " << num << endl;
}

//排序
class mycompare
{
public:
	bool operator()(int v1, int v2)const
	{
		//降序
		return v1 > v2;
	}
};

void test06()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(5, 50));
	printmap(m);

	map<int, int, mycompare>m2;
	m2.insert(pair<int, int>(1, 10));
	m2.insert(pair<int, int>(2, 20));
	m2.insert(pair<int, int>(3, 30));
	m2.insert(pair<int, int>(4, 40));
	m2.insert(pair<int, int>(5, 50));
	for (map<int, int, mycompare>::iterator it = m2.begin(); it != m2.end(); it++)
	{
		cout << "ker = " << (*it).first << " value = " << it->second << endl;
	}
}

int main()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	system("pause");
	return 0;
}