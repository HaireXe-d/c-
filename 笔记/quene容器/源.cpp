#include<iostream>
using namespace std;
#include<string>
#include<queue>

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

void test01()
{
	queue<person>q;
	person p1("刘涛", 18);
	person p2("赵一凡", 18);
	person p3("武增琦", 18);
	person p4("韩儒豪", 18);

	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	while (!q.empty())
	{
		cout << "队头姓名；" << q.front().m_name << "年龄：" << q.front().m_age << endl;
		cout << "队尾姓名；" << q.back().m_name << "年龄：" << q.back().m_age << endl;
		cout << endl;
		q.pop();

	}
	cout << "队列大小：" << q.size() << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}