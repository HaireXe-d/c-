#include<iostream>
using namespace std;
#include<map>
#include<string>
#include<ctime>
#include<vector>
#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class worker
{
public:
	string m_name;
	int m_salary;
};

void creatworker(vector<worker>&v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		worker worker;
		worker.m_name = "员工";
		worker.m_name += nameSeed[i];
		worker.m_salary = rand() % 10000 + 10000;
		v.push_back(worker);
	}
}

void setgroup(vector<worker>&v,multimap<int,worker>&m)
{
	for (vector<worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int depid = rand() % 3;
		m.insert(make_pair(depid, *it));
	}
}

void showworker(multimap<int,worker>&m)
{
	cout << "策划部门：" << endl;
	multimap<int, worker>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名： " << pos->second.m_name << " 工资： " << pos->second.m_salary << endl;
	}

	cout << "-----------------------------------------" << endl;
	cout << "美术部门：" << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名： " << pos->second.m_name << " 工资： " << pos->second.m_salary << endl;
	}

	cout << "-----------------------------------------" << endl;
	cout << "研发部门：" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名： " << pos->second.m_name << " 工资： " << pos->second.m_salary << endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL));        

	vector<worker>Worker;
	creatworker(Worker);
	for (vector<worker>::iterator it = Worker.begin(); it != Worker.end(); it++)
	{
		cout << "姓名： " << it->m_name << " 工资：" << it->m_salary << endl;
	}
	cout << endl;

	multimap<int, worker>mworker;
	setgroup(Worker, mworker);

	showworker(mworker);

	system("pause");
	return 0;
}