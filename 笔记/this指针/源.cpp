#include<iostream>
using namespace std;

class person
{
public:
	person(int age)
	{
		this->age = age;
	}

	person& personaddage(person p)
	{
		this->age += p.age;
		return *this;
	}


	int age;
};


void test01()
{
	person p1(10);
	cout << "p1.age=  " << p1.age << endl;

	person p2(10);
	p2.personaddage(p1).personaddage(p1);
	cout << "p2.age=  " << p2.age << endl;


}

int main()
{
	test01();

	system("pause");

	return 0;

}