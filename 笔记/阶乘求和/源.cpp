#include <iostream>
using namespace std;

int main() 
{
    long long sum = 0;
    long long temp = 1;
    for (int i = 1; i <= 20; i++) 
    {
        temp *= i;
        sum += temp;
    }
    cout <<"½á¹ûÎª£º" << sum << endl;
    system("pause");
    return 0;
}

