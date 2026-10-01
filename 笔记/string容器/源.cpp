#include<iostream>
using namespace std;
#include<string>

//string构造
void test01()
{
	//创建空字符，调用无参构造
	string s1;
	cout << "str1 = " << s1 << endl;
	//
	const char* str = "hello world";
	string s2(str);
	cout << "str2 = " << s2 << endl;
	//拷贝构造
	string s3(s2);
	cout << "str3 = " << s3 << endl;
	//设置输出构造
	string s4(10, 'ab');
	cout << "str4 = " << s4 << endl;
}

//string赋值
void test02()
{
	string str1;
	str1 = "hello world";
	cout << "str1 = " << str1 << endl;

	string str2;
	str2 = str1;
	cout << "str2 = " << str2 << endl;

	string str3;
	str3 = 'a';
	cout << "str3 = " << str3 << endl;

	string str4;
	str4.assign("hello world");
	cout << "str4 = " << str4 << endl;

	string str5;
	str5.assign("hello c++",5);
	cout << "str5 = " << str5 << endl;

	string str6;
	str6.assign(str5);
	cout << "str6 = " << str6 << endl;

	string str7;
	str7.assign(5, 'x');
	cout << "str7 = " << str7 << endl;

}
//字符串拼接
void test03()
{
	string str1 = "我";
	str1 += "爱玩游戏";
	cout << "str1 = " << str1 << endl;

	str1 += ':';

	cout << "str1 = " << str1 << endl;

	string str2 = "LOL DNF";
	str1 += str2;
	cout << "str1 = " << str1 << endl;

	string str3 = "I";
	str3.append("love");
	cout << "str3 = " << str3 << endl;

	str3.append("game abcde", 4);
	cout << "str3 = " << str3 << endl;

	str3.append(str2);
	cout << "str3 = " << str3 << endl;

	//从哪开始截，截多少
	str3.append(str2, 0, 3);
	cout << "str3 = " << str3 << endl;
}

//string查找和替换
void test04()
{
	string str1 = "abcdefgde";
	//find从左往右，rfind从右往左，找不到返回负一
	int pos = str1.find("de");

	if (pos == -1)
	{
		cout << "find位置未找到" << endl;
	}
	else
	{
		cout << "pos = " << pos << endl;
	}

	int sop = str1.rfind("de");

	if (sop == -1)
	{
		cout << "rfind位置未找到" << endl;
	}
	else
	{
		cout << "pos = " << sop << endl;
	}
}
void test05()
{
	string str1 = "abcdefgde";
	//从哪个位置，替换多少个字符
	str1.replace(1, 3, "1111");
	cout << "str1 = " << str1 << endl;
}

//string比较
void test06()
{
	string s1 = "hello";
	string s2 = "aello";
	int ret = s1.compare(s2);
	if (ret == 0)
	{
		cout << "相等于" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}
}

//string字符串存取
void test07()
{
	string str = "hello world";

	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << "  ";
	}
	cout << endl;

	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << "  ";
	}
	cout << endl;

	//修改
	str[0] = 'x';
	str.at(3) = 'x';
	cout << str << endl;
}

//字符串插入和删除
void test08()
{
	string str = "hello";
	str.insert(1, "111");
	cout << str << endl;

	str.erase(1, 3);
	cout << str << endl;
}

//子串获取
void test09()
{
	string str = "abcdefg";
	string subStr = str.substr(1, 3);
	cout << "subStr = " << subStr << endl;

	string email = "hello@sina.com";
	int pos = email.find("@");
	string username = email.substr(0, pos);
	cout << "username:  " << username << endl;
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