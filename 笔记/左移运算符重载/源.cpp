#include<iostream>
using namespace std;

class person
{
public:

	

	int m_a;
	int m_b;
};

ostream &operator<< (ostream& cout, person& p)
{
	cout << "m_a = " << p.m_a << " m_b =" << p.m_b;
	return cout;
}


void test01()
{
	person p;
	p.m_a = 10;
	p.m_b = 10;


	cout << p << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}