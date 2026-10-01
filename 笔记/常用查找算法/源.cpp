#include<iostream>
using namespace std;
#include<vector>   
#include<algorithm>
//find
class person
{
public:
	person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	//重载 == （让底层find知道怎么对比person数据类型）
	bool operator==(const person& p)
	{
		if (this->m_name == p.m_name && this->m_age == p.m_age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	string m_name;
	int m_age;
};
//查找内置数据类型
void test01()
{
	vector<int>v; 
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到了：" << *it << endl;
	}
}
//查找自定义的数据类型
void test02()
{
	vector<person>v;
	person p1("aaa", 10);
	person p2("bbb", 20);
	person p3("ccc", 30);
	person p4("ddd", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	vector<person>::iterator it = find(v.begin(), v.end(), p2);
	if (it == v.end())
	{
		cout << "未找到" << endl;

	}
	else
	{
		cout << "找到了: "
			<<"姓名：" << it->m_name <<" 年龄：" << it->m_age << endl;
	}
}


//find_if
class greaterfive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

class greater20
{
public:
	bool operator()(person& p)
	{
		return p.m_age > 20;
	}
};
//查找内置数据类型
void test03()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator it = find_if(v.begin(), v.end(), greaterfive());

	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到了：" << *it << endl;
	}
}
//查找自定义数据类型
void test04()
{
	vector<person>v;
	person p1("aaa", 10);
	person p2("bbb", 20);
	person p3("ccc", 30);
	person p4("ddd", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	vector<person>::iterator it = find_if(v.begin(), v.end(), greater20());   
	if (it == v.end())
	{
		cout << "未找到" << endl;

	}
	else
	{
		cout << "找到了: "
			<< "姓名：" << it->m_name << " 年龄：" << it->m_age << endl;
	}
}



//adjacent_find（查找相邻重复元素）
void test05()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(0);
	v.push_back(4);
	v.push_back(0);
	v.push_back(0);
	v.push_back(2);
	v.push_back(3);
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到了：" << *it << endl;
	}
}



//binary_search查找指定元素是否存在
void test06()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//容器中必须是有序序列
	bool ret = binary_search(v.begin(), v.end(), 9);
	if (ret)
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}




//count（统计元素个数）
class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	//重载 == （让底层find知道怎么对比person数据类型）
	bool operator==(const Person& p)
	{
		if ( this->m_age == p.m_age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	string m_name;
	int m_age;
};
//统计内置数据类型
void test07()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);
	int num = count(v.begin(), v.end(), 40);
	cout << "40的个数为： " << num << endl;
}
//统计自定义数据类型
void test08()
{
	vector<Person>v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 40);
	v.push_back(p5);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	int num = count(v.begin(), v.end(), p4);
	cout << "和ddd年龄相同的有几人：" << num << endl;  
}

// count_if（按条件来统计元素个数）
//谓词
class Greater20
{
public:
	bool operator()(int val)
	{
		return val > 20;
	}
};

class agegreater20
{
public:
	bool operator()(const Person& p)
	{
		return p.m_age > 20;
	}
};
//统计内置数据类型
void test09()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);
	int num = count_if(v.begin(), v.end(), Greater20());
	cout << "大于20的元素个数为：" << num << endl;
}
//统计自定义数据类型
void test00()
{
	vector<Person>v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 40);
	v.push_back(p5);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	int num = count_if(v.begin(), v.end(), agegreater20());
	cout << "大于20岁的人员个数：" << num << endl;
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
	test00();
	
	system("pause");
	return 0;  
}