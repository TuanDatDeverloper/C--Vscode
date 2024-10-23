#include <bits/stdc++.h>
using namespace std;


long long modular_multiply(long long a, long long b, long long mod) {
    long long result = 0;
    a %= mod; 
    
    while (b > 0) {
        
        if (b & 1) { 
            result = (result + a) % mod;
        }
        a = (a * 2) % mod;
        b >>= 1; 
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long a, b, c;
    cin >> a >> b >> c;
    
    
    long long a_mod = a % c;
    long long b_mod = b % c;
    
    
    long long sum_mod = (a_mod + b_mod) % c;
    
    
    long long diff_mod = (a_mod - b_mod + c) % c;
    
    
    long long prod_mod = modular_multiply(a_mod, b_mod, c);
    
    
    cout << sum_mod << " " << diff_mod << " " << prod_mod << "\n";
    
    return 0;
}
