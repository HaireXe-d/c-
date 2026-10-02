#include<iostream>
using namespace std;

class animal
{
public:
	int m_age;
};

class sheep :virtual public animal {};


class tuo :virtual public animal{};


class sheeptuo :public sheep,public tuo{};

void test01()
{
	sheeptuo st;
	st.sheep::m_age = 18;
	st.tuo::m_age = 28;
	cout << "st.sheep::m_age= " << st.sheep::m_age << endl;
	cout << "st.tuo::m_age= " << st.tuo::m_age << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}