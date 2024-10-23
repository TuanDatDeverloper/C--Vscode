#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[505];
int c[505][505], f[505][505], trace[505];
bool visited[505];

void input() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    c[u][v] = 1;
  }
}

bool findPath() {
  queue<int> q;
  q.push(1);
  memset(visited, false, sizeof(visited));
  visited[1] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u]) {
      if (!visited[v] && f[u][v] < c[u][v]) {
        q.push(v);
        visited[v] = true;
        trace[v] = u;
        if (v == n)
          return true;
      }
    }
  }
  return false;
}

void increaseFlow() {
  int v = n, delta = INT_MAX;
  while (v != 1) {
    int u = trace[v];
    delta = min(delta, c[u][v] - f[u][v]);
    v = u;
  }
  v = n;
  while (v != 1) {
    int u = trace[v];
    f[u][v] += delta;
    f[v][u] -= delta;
    v = u;
  }
}

void solve() {
  int maxFlow = 0;
  while (findPath()) {
    increaseFlow();
    maxFlow++;
  }
  cout << maxFlow << endl;
  for (int i = 0; i < maxFlow; i++) {
    int v = 1;
    vector<int> path;
    path.push_back(v);
    while (v != n) {
      for (int u : adj[v]) {
        if (f[v][u] == 1) {
          path.push_back(u);
          f[v][u] = 0;
          v = u;
          break;
        }
      }
    }
    cout << path.size() << endl;
    for (int room : path) {
      cout << room << " ";
    }
    cout << endl;
  }
}

int main() {
  input();
  solve();
  return 0;
}
