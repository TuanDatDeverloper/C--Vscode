#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

// Function to compute the minimum weight to achieve each value using all items
vector<ll> computeDP(const vector<pair<ll, ll>>& items, int excludeIndex, ll total_value) {
    vector<ll> DP(total_value + 1, INF);
    DP[0] = 0;
    for (int i = 0; i < items.size(); i++) {
        if (i == excludeIndex) continue; // Skip the excluded item
        ll wi = items[i].first;
        ll ci = items[i].second;
        for (ll v = total_value; v >= ci; v--) {
            DP[v] = min(DP[v], DP[v - ci] + wi);
        }
    }
    return DP;
}

// Function to find the maximum value that can be achieved with a given weight limit
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
        cin >> items[i].first >> items[i].second; // w[i], c[i]
        total_value += items[i].second;
    }

    // Compute DP1: min weight to achieve value v using all items
    vector<ll> DP1 = computeDP(items, -1, total_value);

    // Find max_v1 such that DP1[v1] <= W
    ll max_v1 = findMaxValue(DP1, W);

    ll result = max_v1; // Case where no additional item is taken

    // Consider taking one additional item with weight <= H
    for (int j = 0; j < N; j++) {
        ll wj = items[j].first;
        ll cj = items[j].second;
        if (wj > H) continue; // This item cannot be taken additionally

        // Compute DPj: min weight to achieve value v excluding item j
        vector<ll> DPj = computeDP(items, j, total_value);

        // Find max_vj such that DPj[vj] <= W
        ll max_vj = findMaxValue(DPj, W);

        ll total_val = max_vj + cj; // Total value when adding item j
        result = max(result, total_val);
    }

    cout << result;
}
