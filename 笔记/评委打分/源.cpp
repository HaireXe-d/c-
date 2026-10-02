#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;


class person
{
public:
	person(string name, int score)
	{
		this->m_name = name;
		this->m_score = score;
	}
	string m_name;
	int m_score;
};

void creatperson(vector<person>&v)
{
	string nmaeSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nmaeSeed[i];

		int score = 0;

		person p(name, score);
		v.push_back(p);
	}

}

void setscore(vector<person>& v)
{
	for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
		}
		cout << "选手： " << it->m_name << "打分：" << endl;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			cout << *dit << "  ";
		}
		cout << endl;
		//排序
		sort(d.begin(), d.end());
		//去最高最低分
		d.pop_front();
		d.pop_back();
		//取平均分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		int avg = sum / d.size();
		it->m_score = avg;
	}
}

void showscore(vector<person>& v)
{
	for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名： " << it->m_name << "平均分： " << it->m_score << endl;
	}
}


int main()
{
	//创建五名选手
	vector<person>v;
	creatperson(v);
	for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << (*it).m_name << "分数：" << (*it).m_score << endl;
	}
	//打分
	setscore(v);
	//显示最后得分
	showscore(v);

	system("pause");
	return 0;
}