#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 500;
const int MAXM = 500;
vector<int> adj[MAXN + 1];
int match[MAXM + 1];
bool visited[MAXN + 1];

bool dfs(int u) {
    for (int v : adj[u]) {
        if (!visited[v]) {
            visited[v] = true;
            if (match[v] == 0 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    int result = 0;
    memset(match, 0, sizeof(match));

    for (int i = 1; i <= n; ++i) {
        memset(visited, false, sizeof(visited));
        if (dfs(i)) ++result;
    }

    cout << result << '\n';
    for (int v = 1; v <= m; ++v) {
        if (match[v] != 0) {
            cout << match[v] << ' ' << v << '\n';
        }
    }

    return 0;
}
