#include<iostream>
using namespace std;
int main()
{
	int arr[2][3] = { 1,2,3,6,5,4 };
	for (int a = 0; a < 2; a++)
	{
		for (int b = 0; b < 3; b++)
		{
			cout << arr[a][b] << "  ";

		}
		cout << endl;
	}
		system("pause");
		return 0;
}