#include<iostream>
using namespace std;
int main()
{
	int arr[] = { 100,250,200,140,300 };
	int max = 0;
	for (int i = 0; i < 5; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}cout << "×îÖØ= " <<max<< endl;
	system("pause");
	return 0;
}
