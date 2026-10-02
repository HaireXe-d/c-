#include<iostream>
using namespace std;
#include<fstream>




void test02()
{
	ifstream ifs;
	ifs.open("E:/编程产品/文本文件写文件/test.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	char buf[1024] = { 0 };
	while (ifs >> buf)
	{
		cout << buf << endl;
	}

	ifs.close();

}

int main()
{

	test02();
	system("pause");
	return 0;
}