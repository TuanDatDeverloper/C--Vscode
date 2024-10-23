#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

ll compute_lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        unordered_map<ll, ll> dp;
        
        for (int i = 0; i < N; i++) {
            ll current = A[i];
            vector<pair<ll, ll>> updates;
            
            for (const auto& entry : dp) {
                ll new_lcm = compute_lcm(entry.first, current);
                updates.emplace_back(new_lcm, entry.second);
            }
            updates.emplace_back(current, 1);
            
            for (const auto& update : updates) {
                dp[update.first] = (dp[update.first] + update.second) % MOD;
            }
        }
        ll total_sum = 0;
        for (const auto& entry : dp) {
            total_sum = (total_sum + (entry.first % MOD) * (entry.second % MOD)) % MOD;
        }
        
        cout << total_sum << "\n";
    }
    
    return 0;
}
