/*
Số chín ước là số có chính xác 9 ước nguyên dương. Ví dụ:
Số 36 là một số chín ước vì 36 có 9 ước nguyên dương là 1,2,3,4,6,9,12,18 và 36.
Số 2006 không phải là một số chín ước do 2006 chỉ có 8 ước nguyên dương là 1,2,17,34,59,118,1003 và 2006.
QioCass đang rất tò mò về số chín ước và muốn biết một số n có phải là số chín ước không? Các bạn hãy giúp QioCass trả lời câu hỏi nhé.                                                                                                                                                       Input                                                                                                                                                                                       Dòng đầu tiên gồm một số nguyên T(1 <= T <= 10) – Thể hiện số lượng số cần trả lời. 
Dòng thứ hai gồm T số nguyên X_{i}(1 <= X_{i} <= 10 ^ 18) – Thể hiện số thứ i cần trả lời.                                                Output                                                                                                                                                                                       Gồm T dòng, in ra YES nếu X_{i} là số chín ước, ngược lại in ra NO                                                                                        Scoring                                                                                                                                                                                Subtask 1 : điểm 10 . Giới hạn: X_{i} <= 10^6                                                                                                                                        Subtask 2 : điểm 30.  Giới hạn: X_{i} <= 10^12                                                                                                                        Subtask 3 : điểm 60. Không có ràng buộc gì thêm . Giải bằng C++
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Optimized Miller-Rabin primality test for large numbers
bool millerRabinTest(ll n, ll a) {
    if (n == a) return true;
    ll d = n - 1;
    while (d % 2 == 0) d /= 2;
    
    ll x = 1, y;
    while (d > 0) {
        y = x;
        x = ((__int128)x * x) % n;
        if (x == 1 && y != 1 && y != n - 1) 
            return false;
        if (d & 1) 
            x = ((__int128)x * a) % n;
        d >>= 1;
    }
    return x == 1;
}

bool isPrime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    // Small optimization for numbers < 1000
    if (n < 1000) {
        for (ll i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
    
    // Miller-Rabin for large numbers
    vector<ll> witnesses = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for (ll a : witnesses) {
        if (!millerRabinTest(n, a))
            return false;
    }
    return true;
}

// Function to check if n is a perfect square
bool isPerfectSquare(ll n) {
    ll root = sqrt(n);
    return root * root == n;
}

// Function to check if a number has exactly 9 divisors
bool hasNineDivisors(ll n) {
    // Special cases for small numbers
    if (n < 36) return false;
    
    // Case 1: n = p^8
    // More precise check: find perfect 8th root without floating point
    for (ll i = 2; i <= 1000; i++) {
        ll p8 = 1;
        for (int j = 0; j < 8; j++) {
            p8 *= i;
            if (p8 > n) break;
        }
        if (p8 == n && isPrime(i))
            return true;
    }
    
    // Case 2: n = p^2 * q^2
    // Try potential divisors more efficiently
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ll i2 = i * i;
            if (n % i2 == 0) {
                ll remaining = n / i2;
                if (isPerfectSquare(remaining)) {
                    ll q = sqrt(remaining);
                    if (i != q && isPrime(i) && isPrime(q))
                        return true;
                }
            }
        }
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        ll X;
        cin >> X;
        
        if (hasNineDivisors(X))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}