/*Cho bốn số nguyên dương N, A, B, C. Đếm số lượng ước nguyên
dương của N chia hết ít nhất hai trong ba số A, B, C.
Input
Gồm 4 số nguyên dương N, A, B, C (A, B, C,N ≤ 10^18).
Output
Ghi ra kết quả tìm được.
Subtask
10^6 ≤ A,B,C*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    ll res = 0;
    for(ll i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            if((i % a == 0 && i % b == 0) || (i % a == 0 && i % c == 0) || (i % b == 0 && i % c == 0)){
                res++;
            }
            ll other = n / i;
            if(i != other){
                if((other % a == 0 && other % b == 0) || (other % a == 0 && other % c == 0) || (other % b == 0 && other % c == 0)){
                    res++;
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}