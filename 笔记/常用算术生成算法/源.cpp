#include<iostream>
using namespace std;
#include<vector>
#include<numeric>
#include<algorithm>


//累加accumulate
void test01()
{
	vector<int>v;
	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}
	int tatol = accumulate(v.begin(), v.end(), 0);//第三个参数为起始累加值

	cout << "tatol: " <<tatol<< endl;
}


//填充fill
class myprint
{
public:
	void operator()(int val)
	{
		cout << val << "  ";
	}
};
void test02()
{
	vector<int>v;
	v.resize(10);
	fill(v.begin(), v.end(), 100);
	for_each(v.begin(), v.end(), myprint());
	cout << endl;
}


int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}