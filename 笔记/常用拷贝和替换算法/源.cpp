#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
//copy
void myprint(int val)
{
	cout << val << "  ";
}
void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int>v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());

	for_each(v2.begin(), v2.end(), myprint);
	cout << endl;
}

//replace
void test02()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(40);
	v.push_back(30);
	v.push_back(10);
	cout << "替换前：" << endl;
	for_each(v.begin(), v.end(), myprint);
	cout << endl;
	cout << "替换后：" << endl;
	replace(v.begin(), v.end(), 40, 4000);
	for_each(v.begin(), v.end(), myprint);
	cout << endl;
}

//replace_if
class greater30
{
public:
	bool operator()(int val)
	{
		return val >= 30;
	}
};
void test03()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(40);
	v.push_back(30);
	v.push_back(10);
	//将大于30替换成3000
	cout << "替换前：" << endl;
	for_each(v.begin(), v.end(), myprint);
	cout << endl;
	cout << "替换后：" << endl;
	replace_if(v.begin(), v.end(), greater30(),3000);
	for_each(v.begin(), v.end(), myprint);
	cout << endl;
}


//swap
void test04()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v1.push_back(i + 100);
	}
	cout << "交换前：" << endl;
	for_each(v1.begin(), v1.end(), myprint);
	cout << endl;
	for_each(v2.begin(), v2.end(), myprint);
	cout << endl;

	cout << "-----------------------------------------" << endl;
	cout << "交换后：" << endl;
	swap(v1, v2);
	for_each(v1.begin(), v1.end(), myprint);
	cout << endl;
	for_each(v2.begin(), v2.end(), myprint);
	cout << endl;

}
int main()
{
	test01();
	test02();
	test03();
	test04();
	system("pause");
	return 0;
}