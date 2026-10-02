#include<iostream>
using namespace std;
#include<fstream>
#include<string>


class person
{
public:
	char Name[64];
	int Age;
};

void test01()
{
	ofstream ofs("person.txt", ios::out | ios::binary);
	person p = { "уехЩ",18 };
	ofs.write((const char*)&p, sizeof(p));
	ofs.close();
}

int main()
{
	test01();
	system("pause");
	return 0;
}