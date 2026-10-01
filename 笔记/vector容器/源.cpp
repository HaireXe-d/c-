#include<iostream>
using namespace std;
#include<vector>


void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

//vector构造函数
void test01()
{
	//默认无参构造
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	//区间方式构造
	vector<int>v2(v1.begin(), v1.end());
	printVector(v2);

	//n个elem方式构造
	vector<int>v3(10, 100);
	printVector(v3);

	//拷贝构造
	vector<int>v4(v3);
	printVector(v4);
}


//vector赋值操作
void test02()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	//=赋值
	vector<int>v2;
	v2 = v1;
	printVector(v2);

	//assign
	vector<int>v3;
	v3.assign(v1.begin(), v1.end());
	printVector(v3);

	//n个elem方式赋值
	vector<int>v4;
	v4.assign(10, 100);
	printVector(v4);
}


//vector容量和大小
void test03()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	if (v1.empty())
	{
		cout << "v1为空" << endl;
	}
	else
	{
		cout << "v1不为空" << endl;
		cout << "v1容量为：" << v1.capacity() << endl;
		cout << "v1的大小为：" << v1.size() << endl;
	}

	//重新指定大小
	v1.resize(15,100);//利用重载版本，可以指定默认填充值
	printVector(v1);//如果重新指定的比原来长，默认用0填充

	v1.resize(5);
	printVector(v1);//比原来短，删除多出部分
}

//vector插入和删除
void test04()
{
	vector<int>v1;
	//尾插
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	printVector(v1);

	//尾删
	v1.pop_back();
	printVector(v1);

	//插入
	v1.insert(v1.begin(), 100);
	printVector(v1);
	v1.insert(v1.begin(), 2, 1000);
	printVector(v1);

	//删除
	v1.erase(v1.begin());
	printVector(v1);

	//清空
	v1.erase(v1.begin(), v1.end());
	//或者v1.clear();
	printVector(v1);
}

//数据存取
void test05()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	//访问元素
	for  (int i = 0; i < 10; i++)
	{
		cout << v1[i] << "  ";
	}
	cout << endl;
	//用at方式访问元素
	for (int i = 0; i < 10; i++)
	{
		cout << v1.at(i) << "  ";
	}
	cout << endl;

	//获取第一个和最后的元素
	cout << "第一个元素是：" << v1.front() << endl;
	cout << "最后一个元素是：" << v1.back() << endl;
}

//vector互换容器
void test06()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	cout << "交换前" << endl;
	printVector(v1);

	vector<int>v2;
	for (int i = 10; i > 0 ; i--)
	{
		v2.push_back(i);
	}
	printVector(v1);

	cout << "交换后" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);

}
//实际用途：可以用swap收缩内存空间
void test07()
{
	vector<int>v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小：" << v.size() << endl;


	v.resize(3);
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小：" << v.size() << endl;

	vector<int>(v).swap(v);

	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;
}

//vector预留空间
//未预留空间
void test08()
{
	vector<int>v;

	int num = 0;
	int* p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);

		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
	cout << "num的值为" << num << endl;
}
//预留空间
void test09()
{

	vector<int>v;
	v.reserve(100000);
	int num = 0;
	int* p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);

		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
	cout << "num的值为" << num << endl;
}



int main()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	test08();
	test09();
	system("pause");
	return 0;
}