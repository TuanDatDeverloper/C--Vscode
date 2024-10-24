#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<vector<int>> adj;
vector<int> pair_u, pair_v;
vector<bool> visited;

bool dfs(int u) {
    for (int v : adj[u]) {
        if (!visited[v]) {
            visited[v] = true;
            if (pair_v[v] == 0 || dfs(pair_v[v])) {
                pair_u[u] = v;
                pair_v[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    adj.resize(n + 1);
    pair_u.resize(n + 1, 0);
    pair_v.resize(m + 1, 0);

    for (int i = 0; i < k; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int matching = 0;
    for (int u = 1; u <= n; ++u) {
        visited.assign(m + 1, false);
        if (dfs(u)) {
            matching++;
        }
    }

    vector<pair<int, int>> result;
    for (int u = 1; u <= n; ++u) {
        if (pair_u[u] != 0) {
            result.emplace_back(u, pair_u[u]);
        }
    }

    cout << matching << "\n";
    for (auto &[a, b] : result) {
        cout << a << " " << b << "\n";
    }

    return 0;
}
