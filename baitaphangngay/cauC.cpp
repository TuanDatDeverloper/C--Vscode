#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX_CI = 1000;
const int MAX_N = 100;
const int MAX_V = MAX_N * MAX_CI;

int main() {
    int N;
    long long W, H;
    cin >> N >> W >> H;

    vector<long long> wi(N + 1);
    vector<int> ci(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> wi[i] >> ci[i];
    }

    // Initialize dp array
    vector<long long> dp(MAX_V + 1, LLONG_MAX);
    vector<int> prev_item(MAX_V + 1, -1);
    dp[0] = 0;

    // Build dp[v] and prev_item[v]
    for (int i = 1; i <= N; ++i) {
        for (int v = MAX_V; v >= ci[i]; --v) {
            if (dp[v - ci[i]] != LLONG_MAX && dp[v - ci[i]] + wi[i] <= W) {
                if (dp[v] > dp[v - ci[i]] + wi[i]) {
                    dp[v] = dp[v - ci[i]] + wi[i];
                    prev_item[v] = i;
                }
            }
        }
    }

    // Build list of items that can be carried in hand
    vector<int> items_hand;
    int max_ci_hand = 0;
    for (int i = 1; i <= N; ++i) {
        if (wi[i] <= H) {
            items_hand.push_back(i);
            max_ci_hand = max(max_ci_hand, ci[i]);
        }
    }

    int ans = max_ci_hand; // Initial answer is the max ci of items that can be carried in hand
    // Also consider the case where we only use the bag
    for (int v = 0; v <= MAX_V; ++v) {
        if (dp[v] <= W) {
            ans = max(ans, v);
        }
    }

    // For each achievable total value with the bag, try to pick an additional item in hand
    for (int v = 0; v <= MAX_V; ++v) {
        if (dp[v] <= W) {
            // Reconstruct items used in the bag
            vector<bool> in_bag(N + 1, false);
            int curr_v = v;
            while (curr_v > 0 && prev_item[curr_v] != -1) {
                int item = prev_item[curr_v];
                in_bag[item] = true;
                curr_v -= ci[item];
            }
            // Try to pick an item in hand not in the bag
            for (int idx : items_hand) {
                if (!in_bag[idx]) {
                    int total_value = v + ci[idx];
                    ans = max(ans, total_value);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
