#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> a(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    a[u].push_back({v, w});
  }

  vector<long long> d1(n, LLONG_MAX), d2(n, LLONG_MAX);
  priority_queue<pair<long long, pair<int, bool>>, vector<pair<long long, pair<int, bool>>>, greater<pair<long long, pair<int, bool>>>> pq;
  pq.push({0, {0, false}});
  d1[0] = 0;

  while (!pq.empty()) {
    auto [du, p] = pq.top();
    int u = p.first;
    bool used_coupon = p.second;
    pq.pop();

    if (used_coupon && du != d2[u]) continue;
    if (!used_coupon && du != d1[u]) continue;

    for (auto [v, w] : a[u]) {
      if (!used_coupon) {
        if (d1[v] > d1[u] + w) {
          d1[v] = d1[u] + w;
          pq.push({d1[v], {v, false}});
        }
        if (d2[v] > d1[u] + w / 2) {
          d2[v] = d1[u] + w / 2;
          pq.push({d2[v], {v, true}});
        }
      } else {
        if (d2[v] > d2[u] + w) {
          d2[v] = d2[u] + w;
          pq.push({d2[v], {v, true}});
        }
      }
    }
  }

  cout << min(d1[n - 1], d2[n - 1]) << endl;
  return 0;
}
