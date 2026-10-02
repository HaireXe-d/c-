#include<iostream>
using namespace std;
#include<list>
#include<string>

class person
{
public:
	person(string name, int age, int height)
	{
		m_name = name;
		m_age = age;
		m_height = height;
	}

public:
	string m_name;
	int m_age;
	int m_height;
};

bool compare(person &p1 ,person &p2)
{
	if (p1.m_age == p2.m_age)
	{
		return p1.m_height > p2.m_height;
	}
	else
	{
		return p1.m_age > p2.m_age;
	}
}

void test01()
{
	list<person>L;

	person p1("刘备", 35, 175);
	person p2("曹操", 45, 180);
	person p3("孙权", 40, 170);
	person p4("赵云", 25, 190);
	person p5("张飞", 35, 160);
	person p6("关羽", 35, 200);

	
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	
	cout << "排序前" << endl;
	
	for (list<person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名： " << (*it).m_name << "年龄： " << it->m_age << "身高： " << it->m_height << endl;
	}
	cout << "--------------------------" << endl;
	cout << "排序后" << endl;
	L.sort(compare);
	for (list<person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名： " << (*it).m_name << "年龄： " << it->m_age << "身高： " << it->m_height << endl;
	}
}

int main()
{
	test01();
	system("pause");
	return 0;
}