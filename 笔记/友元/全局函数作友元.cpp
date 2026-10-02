#include<iostream>
#include<string>
using namespace std;

class building
{
	friend void goodgay(building* Building);

public:
	building()
	{
		m_sittingroom = "客厅";
		m_bedroom = "卧室";
	}
public:
	string m_sittingroom;

private:
	string m_bedroom;
};

void goodgay(building *Building)
{
	cout << "gay正在访问:  " << Building->m_sittingroom << endl;
	cout << "gay正在访问:  " << Building->m_bedroom << endl;
}

void test01()
{
	building Building;
	goodgay(&Building);
}


int main()
{
	test01();
	system("pause");
	return 0;
}