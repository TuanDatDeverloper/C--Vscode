#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, d;
    cin >> n >> k >> d;

    vector<pair<int, int>> events(k);
    for (int i = 0; i < k; ++i) {
        cin >> events[i].first >> events[i].second;
    }

    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
    }

   
    for (int i = 1; i <= n; ++i) {
        int pos = i;
        for (const auto& event : events) {
            int l = event.first, r = event.second;
            if (l <= pos && pos <= r) {
                pos = l + r - pos;
            }
        }
        p[i] = pos;
    }

    
    vector<bool> visited(n + 1, false);
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            vector<int> cycle;
            int pos = i;
            while (!visited[pos]) {
                visited[pos] = true;
                cycle.push_back(pos);
                pos = p[pos];
            }

            int len = cycle.size();
            for (int j = 0; j < len; ++j) {
                int new_pos = (j + d) % len;
                ans[cycle[new_pos]] = cycle[j];
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
