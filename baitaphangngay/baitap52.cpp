#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Hàm tính GCD
ll gcd_custom(ll a, ll b) {
    while (b != 0) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Hàm tính LCM
ll lcm_custom(ll a, ll b) {
    return a / gcd_custom(a, b) * b;
}

// Hàm nhân theo modulo để tránh tràn khi nhân hai số lớn
ll mulmod(ll a, ll b, ll mod) {
    __int128 res = (__int128(a) * b) % mod;
    return res;
}

// Hàm tính lũy thừa theo modulo
ll powermod(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1)
            res = mulmod(res, a, mod);
        a = mulmod(a, a, mod);
        b >>= 1;
    }
    return res;
}

// Hàm kiểm tra tính nguyên tố bằng Miller-Rabin
bool is_prime(ll n) {
    if (n < 2)
        return false;
    for(auto p : {2LL,3LL,5LL,7LL,11LL,13LL,17LL,19LL,23LL,29LL,31LL,37LL}) {
        if(n % p == 0){
            return n == p;
        }
    }
    // Bases for n < 2^64
    static const int bases[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    ll d = n - 1;
    int r = 0;
    while ((d & 1) == 0) {
        d >>=1;
        r +=1;
    }
    for(auto a : bases){
        if(a >= n) continue;
        ll x = powermod(a, d, n);
        if(x ==1 || x == n-1) continue;
        bool cont_outer = false;
        for(int i=1;i<r;i++){
            x = mulmod(x, x, n);
            if(x == n-1){
                cont_outer = true;
                break;
            }
        }
        if(cont_outer) continue;
        return false;
    }
    return true;
}

// Hàm Pollard's Rho để tìm một ước số không nguyên tố của n
mt19937_64 mt_rand64(chrono::steady_clock::now().time_since_epoch().count());

ll pollard_rho(ll n){
    if(n%2==0) return 2;
    if(n%3==0) return 3;
    if(n%5==0) return 5;
    if(n%7==0) return 7;
    if(n%11==0) return 11;
    if(n%13==0) return 13;
    if(n%17==0) return 17;
    if(n%19==0) return 19;
    if(n%23==0) return 23;
    if(n%29==0) return 29;
    if(n%31==0) return 31;
    if(n%37==0) return 37;
    
    if(is_prime(n)) return n;
    while(true){
        ll c = mt_rand64() % n;
        auto f = [c, n](ll x) -> ll {
            return (mulmod(x, x, n) + c) % n;
        };
        ll x = 2, y = 2, d = 1;
        while(d ==1){
            x = f(x);
            y = f(f(y));
            d = gcd_custom(abs(x - y), n);
        }
        if(d != n){
            if(is_prime(d))
                return d;
            else
                return pollard_rho(d);
        }
    }
}

// Hàm phân tích thừa số nguyên tố
void factor(ll n, vector<ll> & factors){
    if(n ==1) return;
    if(is_prime(n)){
        factors.push_back(n);
        return;
    }
    ll d = pollard_rho(n);
    factor(d, factors);
    factor(n/d, factors);
}

// Hàm tính số lượng ước từ thừa số nguyên tố
ll count_divisors(ll n){
    if(n ==0) return 0;
    vector<ll> factors;
    factor(n, factors);
    // Đếm số lần xuất hiện của từng thừa số nguyên tố
    map<ll, int> cnt;
    for(auto p : factors){
        cnt[p]++;
    }
    ll res =1;
    for(auto &[p, c] : cnt){
        res *= (c +1);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, A, B, C;
    cin >> N >> A >> B >> C;
    
    // Tính LCM của các cặp và cả ba số
    ll AB = lcm_custom(A, B);
    ll AC = lcm_custom(A, C);
    ll BC = lcm_custom(B, C);
    ll ABC = lcm_custom(AB, C);
    
    // Hàm lambda để đếm số lượng ước chia hết cho K
    auto count_divisible = [&](ll K) -> ll {
        if(K ==0) return 0;
        if(N % K !=0) return 0;
        ll M = N / K;
        return count_divisors(M);
    };
    
    ll countAB = count_divisible(AB);
    ll countAC = count_divisible(AC);
    ll countBC = count_divisible(BC);
    ll countABC = count_divisible(ABC);
    
    // Áp dụng công thức bao hàm và loại trừ
    ll result = countAB + countAC + countBC - 2 * countABC;
    
    cout << result;
    return 0;
}
