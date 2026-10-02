#include<iostream>
using namespace std;

template<typename T>
void myswap(T&a, T&b)
{
	T temp = a;
	a = b;
	b = temp;

}

template<class T>
void mysort(T arr[],int len)
{
	for (int i = 0; i < len; i++)
	{
		int min = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			myswap(arr[min], arr[i]);
		}
	}
}

template<typename T>
void printarr(T arr[],int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << "   ";
	}
	cout << endl;
}


void test01()
{
	char chararr[] = "badcfe";
	int num = sizeof(chararr) / sizeof(char);
	mysort(chararr, num);
	printarr(chararr, num);

}

void test02()
{
	int intarr[] = { 3,2,1,4,6,5,7,8,9, };
	int num = sizeof(intarr) / sizeof(int);
	mysort(intarr, num);
	printarr(intarr, num);
}




int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}