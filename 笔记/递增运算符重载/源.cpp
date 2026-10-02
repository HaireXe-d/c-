#include<iostream>
using namespace std;

class myint
{
	friend ostream& operator<<(ostream& cout, myint myint);
public:
	

	myint()
	{
		m_num = 0;
	}

	myint &operator++()
	{
		m_num++;
		return *this;
	}

	myint operator++(int)
	{
		myint temp = *this;
		m_num++;
		return temp;
	}

private:
	int m_num;
};

ostream& operator<<(ostream& cout, myint myint)
{
	cout << myint.m_num;
	return cout;
}




void test01()
{
	myint myint1;
	cout << ++myint1 << endl;
}


int main()
{
	test01();
	system("pause");
	return 0;
}

