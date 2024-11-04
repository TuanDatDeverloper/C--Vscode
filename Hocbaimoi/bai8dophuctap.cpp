#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dat int
#define pi = 3.14
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main(){
    FAST
   ll a,b;
    cin >> a >> b;
    //hoán đổi giá trị 2 số a và b sau đó tính giá trị biểu thức 128 * a + 97 * b + 1000 in ra màn hình.
    swap(a,b);
    cout << 128*a + 97*b + 1000;
    return 0;
}
