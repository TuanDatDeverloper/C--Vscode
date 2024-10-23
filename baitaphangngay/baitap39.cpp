#include <iostream>
using namespace std;

// sử dụng thuật toán Euclid
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int x, k;
    cin >> x >> k;

    // Khoảng cách giữa các số trong dãy là 2
    int d = 2;

    // In ra kết quả
    cout << d;
    return 0;
}
