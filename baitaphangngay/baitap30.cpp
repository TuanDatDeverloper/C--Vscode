#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Constants
const int MOD = 1e9 + 7;

// Fast multiplication to prevent overflow
ll mulmod(ll a, ll b, ll mod) {
    __int128 res = (__int128(a) * b) % mod;
    return res;
}

// Fast exponentiation
ll power(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) {
            res = mulmod(res, a, mod);
        }
        a = mulmod(a, a, mod);
        b >>= 1;
    }
    return res;
}

// Miller-Rabin primality test
bool is_prime(ll n) {
    if (n < 2) return false;
    for (auto p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n % p == 0) {
            return n == p;
        }
    }

    ll d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }

    vector<ll> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for (auto a : bases) {
        if (a >= n) continue;
        ll x = power(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool cont_outer = false;
        for (int r = 1; r < s; r++) {
            x = mulmod(x, x, n);
            if (x == n - 1) {
                cont_outer = true;
                break;
            }
        }
        if (cont_outer) continue;
        return false;
    }
    return true;
}

mt19937_64 mt_rand64(chrono::steady_clock::now().time_since_epoch().count());

// Pollard's Rho algorithm
ll pollards_rho(ll n) {
    if (n % 2 == 0) return 2;
    if (is_prime(n)) return n;
    while (true) {
        ll c = mt_rand64() % n;
        auto f = [&](ll x) -> ll {
            return (mulmod(x, x, n) + c) % n;
        };
        ll x = 2, y = 2, d = 1;
        while (d == 1) {
            x = f(x);
            y = f(f(y));
            d = gcd(abs(x - y), n);
        }
        if (d != n) {
            if (is_prime(d)) {
                return d;
            } else {
                return pollards_rho(d);
            }
        }
    }
}

// Factorization using Pollard's Rho
void factor(ll n, vector<ll> &factors) {
    if (n == 1) return;
    if (is_prime(n)) {
        factors.push_back(n);
        return;
    }
    ll d = pollards_rho(n);
    factor(d, factors);
    factor(n / d, factors);
}

// Function to get unique prime factors
vector<ll> get_unique_factors(ll n) {
    vector<ll> factors;
    factor(n, factors);
    sort(factors.begin(), factors.end());
    factors.erase(unique(factors.begin(), factors.end()), factors.end());
    return factors;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    // Compute GCD of the array
    ll current_gcd = a[0];
    for (int i = 1; i < n; i++) current_gcd = gcd(current_gcd, a[i]);

    if (current_gcd > 1) {
        cout << "0\n";
        return 0;
    }

    // Sample a subset of the array to find candidate primes
    // To ensure coverage, sample up to 10 elements or all if n <10
    int sample_size = min(n, 10);
    vector<ll> sample(a.begin(), a.begin() + sample_size);

    // Collect candidate primes from ai, ai-1, ai+1
    vector<ll> candidates;
    for (auto x : sample) {
        for (auto y : {x, x - 1, x + 1}) {
            if (y < 2) continue;
            vector<ll> factors = get_unique_factors(y);
            candidates.insert(candidates.end(), factors.begin(), factors.end());
        }
    }

    // Sort and remove duplicates
    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

    // Ensure p=2 is included
    if (find(candidates.begin(), candidates.end(), 2) == candidates.end()) {
        candidates.push_back(2);
    }

    // Remove p=1 if exists (though unlikely)
    candidates.erase(remove(candidates.begin(), candidates.end(), 1), candidates.end());

    // Remove duplicates again after adding p=2
    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

    ll min_cost = LLONG_MAX;

    // Precompute ai % p for all p's
    // To optimize, loop through ai once and store necessary information
    // However, with p's up to ~1000 and n=2e5, it's still feasible

    for(auto p : candidates){
        if(p <2) continue;

        ll total_cost =0;
        bool feasible = true;

        for(int i =0; i<n; i++){
            ll mod = a[i] % p;
            if(mod ==0) continue;

            if(a[i] > mod){
                ll cost_sub = mod;
                ll cost_add = p - mod;
                total_cost += min(cost_sub, cost_add);
            }
            else{
                ll cost_add = p - mod;
                total_cost += cost_add;
            }

            if(total_cost >= min_cost){
                feasible = false;
                break;
            }
        }

        if(feasible){
            min_cost = min(min_cost, total_cost);
        }
    }

    // Edge Case: No candidate primes found (unlikely)
    if(min_cost == LLONG_MAX){
        // As per problem constraints, this should not happen
        // But to handle it, we can make all a_i =1 by adding 1 to each (if n >1)
        // Or impossible if n=1 and a_i=1
        // However, since GCD needs to be >1, it's impossible for n=1 and a_i=1
        // But n >=1, so output -1 or some large number
        // Here, we'll output -1
        cout << "-1\n";
    }
    else{
        cout << min_cost << "\n";
    }

    return 0;
}
