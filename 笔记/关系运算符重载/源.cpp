#include<iostream>
#include<string>
using namespace std;

class person
{
public:
	person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}

	bool operator==(person& p)
	{
		if (this->m_name == p.m_name && this->m_age == p.m_age)
		{
			return true;
		}
		return false;
	}

	string m_name;
	int m_age;
};

void test01()
{
	person p1("张三" ,18);
	person p2("李四" ,19);

	if (p1 == p2)
	{
		cout << "相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}
}


int main()
{
	test01();
	system("pause");
	return 0;
}