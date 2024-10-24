#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    cin >> n;
    long long originalN = n;
    vector<pair<long long, int>> primeFactors;
    
    for(long long i = 2; i * i <= n; i++) {
        int cnt = 0;
        while(n % i == 0){
            cnt++;
            n /= i;
        }
        if(cnt > 0){
            primeFactors.emplace_back(i, cnt);
        }
    }
    if(n > 1){
        primeFactors.emplace_back(n, 1);
    }
    
    vector<string> factors;
    for(auto &[p, k] : primeFactors){
        for(int i = 0; i < k; i++) {
            factors.push_back(to_string(p));
        }
    }

    string factorization = "";
    for(int i = 0; i < factors.size(); i++){
        if(i > 0){
            factorization += "*";
        }
        factorization += factors[i];
    }

    cout << factorization << "\n";

    long long numDivisors = 1;
    for(auto &[p, k] : primeFactors){
        numDivisors *= (k + 1);
    }
    cout << numDivisors << "\n";

    return 0;
}
