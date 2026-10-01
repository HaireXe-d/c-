#include<iostream>
using namespace std;
#include<set>
#include<string>

void printset(set<int>s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << endl;
	}
	cout << endl;
}

//构造和赋值
void test01()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	printset(s1);

	//拷贝构造
	set<int>s2(s1);
	printset(s2);

	//赋值
	set<int>s3;
	s3 = s2;
	printset(s3);
}


//大小
void test02()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);

	if (s1.empty())
	{
		cout << "s1为空" << endl;
	}
	else
	{
		cout << "s1不为空" << endl;
		cout << "s1的大小为：" << s1.size() << endl;
	}
}


//交换
void test03()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);

	set<int>s2;
	s2.insert(100);
	s2.insert(200);
	s2.insert(300);
	s2.insert(400);

	cout << "交换前：" << endl;
	printset(s1);
	printset(s2);

	cout << "交换后：" << endl;
	s1.swap(s2);
	printset(s1);
	printset(s2);
}

//插入和删除
void test04()
{
	set<int>s1;
	//插入
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	printset(s1);

	//删除
	s1.erase(s1.begin());
	printset(s1);
	s1.erase(30);
	printset(s1);

	//清除
	s1.clear();
	//或者s1.erase(s1.begin(),s1.end());
	printset(s1);
}


//查找统计
void test05()
{
	set<int>s1;
	//插入
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	printset(s1);

	//查找
	set<int>::iterator pos = s1.find(30);

	if (pos != s1.end())
	{
		cout << "找到了" << endl;

	}
	else
	{
		cout << "未找到" << endl;
	}

	//统计
	int num = s1.count(30);
	cout << "num = " << num << endl;
}

//set 与 multiset 的区别
void test06()
{
	//set
	set<int>s;
	pair<set<int>::iterator, bool> ret = s.insert(10);
	if (ret.second)
	{
		cout << "第一次插入成功" << endl;
	}
	else
	{
		cout << "第一次插入失败" << endl;
	}
	ret = s.insert(10);
	if (ret.second)
	{
		cout << "第二次插入成功" << endl;
	}
	else
	{
		cout << "第二次插入失败" << endl;
	}
	//multiset
	multiset<int>ms;
	ms.insert(10);
	ms.insert(10);
	ms.insert(10);
	ms.insert(10);

	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << endl;

	}
	cout << endl;

}

//排序
class Compare
{
public:
	bool operator()(int v1, int v2)const
	{
		return v1 > v2;
	}
};
//
void test07()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(50);
	s1.insert(30);

	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//指定顺序从大到小
	set<int, Compare>s2;
	s2.insert(10);
	s2.insert(40);
	s2.insert(20);
	s2.insert(50);
	s2.insert(30);

	for (set<int,Compare>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//自定义数据类型排序
class person
{
public:
	person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;

};
//
class Compareperson
{
public:
	bool operator()(const person &p1,const  person &p2)const
	{
		return p1.m_age > p2.m_age;
	}
};
//
void test08()
{
	/*set <person>s;
	person p1("刘备",24);
	person p2("关羽",28);
	person p3("张飞",25);
	person p4("赵云",21);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	for (set<person>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "姓名：" << it->m_name << "年龄： " << it->m_age << endl;
	}
	cout << endl;*/

	//按年龄从大到小
	set <person,Compareperson>s1;
	person e1("刘备", 24);
	person e2("关羽", 28);
	person e3("张飞", 25);
	person e4("赵云", 21);

	s1.insert(e1);
	s1.insert(e2);
	s1.insert(e3);
	s1.insert(e4);
	for (set<person,Compareperson>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << "姓名：" << it->m_name << "年龄： " << it->m_age << endl;
	}
	cout << endl;
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
