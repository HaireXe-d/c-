#include <iostream>
using namespace std;

int main() {
    int a = 0;
    int n = 0;
    cout << "输入数字 a: ";
    cin >> a;
    cout << "输入项数 n: ";
    cin >> n;

    long long sum = 0;
    long long temp = 0;

    for (int i = 1; i <= n; i++) 
    {
        temp = temp * 10 + a;
        sum += temp;
    }

    cout << "该数列的和为: " << sum << endl;
    system("pause");
    return 0;
}
