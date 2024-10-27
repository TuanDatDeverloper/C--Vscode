#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
vector<ll> computeDP(const vector<pair<ll, ll>>& items, int excludeIndex, ll total_value) {
    vector<ll> DP(total_value + 1, INF);
    DP[0] = 0;
    for (int i = 0; i < items.size(); i++) {
        if (i == excludeIndex) continue; 
        ll wi = items[i].first;
        ll ci = items[i].second;
        for (ll v = total_value; v >= ci; v--) {
            DP[v] = min(DP[v], DP[v - ci] + wi);
        }
    }
    return DP;
}

ll findMaxValue(const vector<ll>& DP, ll weight_limit) {
    ll max_value = 0;
    for (ll v = 0; v < DP.size(); v++) {
        if (DP[v] <= weight_limit) {
            max_value = max(max_value, v);
        }
    }
    return max_value;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    ll W, H;
    cin >> N >> W >> H;
    vector<pair<ll, ll>> items(N);
    ll total_value = 0;
    for (int i = 0; i < N; i++) {
        cin >> items[i].first >> items[i].second; 
        total_value += items[i].second;
    }

    vector<ll> DP1 = computeDP(items, -1, total_value);
    ll max_v1 = findMaxValue(DP1, W);

    ll result = max_v1; 
    for (int j = 0; j < N; j++) {
        ll wj = items[j].first;
        ll cj = items[j].second;
        if (wj > H) continue; 
        vector<ll> DPj = computeDP(items, j, total_value);
        ll max_vj = findMaxValue(DPj, W);

        ll total_val = max_vj + cj; 
        result = max(result, total_val);
    }

    cout << result;
}
