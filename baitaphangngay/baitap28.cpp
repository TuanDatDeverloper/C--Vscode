#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    long long S;
    cin >> n >> m >> S;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<long long>> prefix_sum(n + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            prefix_sum[i][j] = a[i - 1][j - 1] + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
        }
    }

    auto get_sum = [&](int x1, int y1, int x2, int y2) {
        return prefix_sum[x2][y2] - prefix_sum[x1 - 1][y2] - prefix_sum[x2][y1 - 1] + prefix_sum[x1 - 1][y1 - 1];
    };

    int low = 0, high = min(n, m), result = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        bool found = false;
        for (int i = 1; i + mid - 1 <= n && !found; i++) {
            for (int j = 1; j + mid - 1 <= m && !found; j++) {
                if (get_sum(i, j, i + mid - 1, j + mid - 1) <= S) {
                    found = true;
                    result = mid;
                }
            }
        }
        if (found) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << result * result << "\n";

    return 0;
}
