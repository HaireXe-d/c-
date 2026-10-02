#include<iostream>
using namespace std;

class calculator
{
public:
	//Õı³£
	int getresult(string oper)
	{
		if (oper == "+")
		{
			return num1 + num2;
		}
		else if(oper == "-")
		{
			return num1 - num2;
		}
		else if(oper == "*")
		{
			return num1 * num2;
		}
	}


public:
	int num1;
	int num2;
};

//¶àÌ¬
class acalculator
{
public:
	virtual int getresult()
	{
		return 0;
	}

	int num1;
	int num2;
};

class add :public acalculator
{
public:
	int getresult()
	{
		return num1 + num2;
	}
};

class sub :public acalculator
{
public:
	int getresult()
	{
		return num1 - num2;
	}
};

class mul :public acalculator
{
public:
	int getresult()
	{
		return num1 * num2;
	}
};

void test01()
{
	calculator c;
	c.num1 = 10;
	c.num2 = 10;
	cout << c.num1 << "+" << c.num2 << "=" << c.getresult("+") << endl;
	cout << c.num1 << "-" << c.num2 << "=" << c.getresult("-") << endl;
	cout << c.num1 << "*" << c.num2 << "=" << c.getresult("*") << endl;
}

void test02()
{
	acalculator* abs = new add;
	abs->num1 = 10;
	abs->num2 = 10;
	cout << abs->num1 << "+" << abs->num2 << "=" << abs->getresult() << endl;
	delete abs;

	abs = new sub;
	abs->num1 = 10;
	abs->num2 = 10;
	cout << abs->num1 << "-" << abs->num2 << "=" << abs->getresult() << endl;
	delete abs;

	abs = new mul;
	abs->num1 = 10;
	abs->num2 = 10;
	cout << abs->num1 << "*" << abs->num2 << "=" << abs->getresult() << endl;
	delete abs;
}


int main()
{
	test01();
	test02();  
	system("pause");
	return 0;
}