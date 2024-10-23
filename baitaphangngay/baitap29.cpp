#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_A = 1e6 + 1;

vector<int> sieve(int max_val) {
    vector<int> spf(max_val); // Smallest prime factor
    iota(spf.begin(), spf.end(), 0); // Initialize spf with itself

    for (int i = 2; i * i < max_val; i++) {
        if (spf[i] == i) { // i is a prime number
            for (int j = i * i; j < max_val; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
    return spf;
}

int64_t mod_exp(int64_t base, int64_t exp, int64_t mod) {
    int64_t result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> spf = sieve(MAX_A);
    unordered_map<int, int> max_prime_powers;

    for (int num : a) {
        unordered_map<int, int> prime_powers;
        while (num > 1) {
            int prime = spf[num];
            prime_powers[prime]++;
            num /= prime;
        }
        for (const auto& [prime, power] : prime_powers) {
            max_prime_powers[prime] = max(max_prime_powers[prime], power);
        }
    }

    int64_t result = 1;
    for (const auto& [prime, power] : max_prime_powers) {
        result = (result * mod_exp(prime, power, MOD)) % MOD;
    }

    cout << result << "\n";

    return 0;
}