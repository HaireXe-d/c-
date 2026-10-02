#include<iostream>
using namespace std;

class person
{
public:
	person(int age)
	{
		m_age = new int(age);
	}

	person& operator=(person& p)
	{
		if (m_age != NULL)
		{
			delete m_age;
			m_age = NULL;
		}

		m_age = new int(*p.m_age);
		return *this;

	}

	int* m_age;
};


void test01()
{
	person p1(18);
	person p2(20);
	person p3(30);
	p3 = p1 = p2;
	cout << "p1的年龄" << *p1.m_age << endl;
	cout << "p2的年龄" << *p2.m_age << endl;
	cout << "p3的年龄" << *p3.m_age << endl;
}


int main()
{
	test01();
	system("pause");
	return 0;
}