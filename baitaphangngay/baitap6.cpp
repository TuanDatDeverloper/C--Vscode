#include<iostream>

using namespace std;

int main() {
    int a,b;
    int n;
    cin >> a >> b;
    for(int n=1; b > 0; n *= a, b--);
        cout << n;
    return 0;
}