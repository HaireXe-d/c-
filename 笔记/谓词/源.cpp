#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


//仿函数返回值类型是bool,称为谓词
//一元
class greaterfive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//查找容器中，有没有大于五的数字
	//greaterfive(),匿名函数对象
	vector<int>::iterator it = find_if(v.begin(), v.end(), greaterfive());
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到了为:" << *it << endl;
	}
}


//二元
class mysort
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}

};

void test02()
{
	vector<int>v;
	v.push_back(2);
	v.push_back(1);
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);

	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	sort(v.begin(), v.end(),mysort());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}