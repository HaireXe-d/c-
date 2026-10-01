#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//for_each的使用                                      
//常规函数
void print01(int val)
{
	cout << val << "  ";
}
//仿函数
class print02
{
public:
	void operator()(int val)
	{
		cout << val << "  ";
	}
};



//transform的使用
class Transform
{
public:
	int operator()(int val)
	{
		return val;
	}
};

class myprint
{
public:
	void operator()(int val)
	{
		cout << val << "  ";
	}
};



//for_each
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//
	for_each(v.begin(), v.end(), print01);
	cout << endl;
	//
	for_each(v.begin(), v.end(), print02());
	cout << endl;
}
//transform
void test02()
{
     vector<int>v;
	 for (int i = 0; i < 10; i++)
	 {
			v.push_back(i);
	 }

	 vector<int>vTarget;
	 vTarget.resize(v.size());
	 transform(v.begin(), v.end(), vTarget.begin(), Transform());
	 for_each(vTarget.begin(), vTarget.end(), myprint());
}


int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}