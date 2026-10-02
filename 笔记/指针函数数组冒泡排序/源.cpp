#include<iostream>
using namespace std;



void bubble (int *arr, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j ] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{

	int arr[] = { 3,4,2,1,7,6,8,9,5 };

	int len = sizeof(arr) / sizeof(arr[0]);

	cout << "ÅÅÐòÇ°" << endl;
	for (int a = 0; a < 9; a++)
	{
		cout<< arr[a] << endl;
	}

	bubble(arr , len);

	cout << "ÅÅÐòºó" << endl;
	for (int a = 0; a < 9; a++)
	{
		cout << arr[a] << endl;
	}

	system("pause");
	return 0;

}