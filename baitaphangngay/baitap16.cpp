/*Có n thành phố và m chuyến bay giữa chúng. Nhiệm vụ của bạn là xác định độ dài của tuyến đường ngắn nhất từ  Syrjälä đến mọi thành phố.
Input
  Dòng đầu vào đầu tiên có hai số nguyên n và m: số lượng thành phố và chuyến bay. Các thành phố được đánh số 1,2,…,n và thành phố 1 là Syrjälä.
  Sau đó, có m dòng mô tả các chuyến bay. Mỗi dòng có ba số nguyên a, b và c: một chuyến bay bắt đầu tại thành phố a, kết thúc tại thành phố b, và độ dài của nó là c. Mỗi chuyến bay là một chuyến bay một chiều.
  Bạn có thể giả định rằng có thể đi từ Syrjälä đến tất cả các thành phố khác.
Output
  In n số nguyên: độ dài tuyến đường ngắn nhất từ  Syrjälä đến các thành phố 1,2,…,n.
Constraints
1 ≤ n ≤ 10^5
1 ≤ m ≤ 2 * 10^5
1 ≤ a,b ≤ n
1 ≤ c ≤ 10^9
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
#define INF 1e18 
typedef long long ll;

int n, m;
vector<pair<int, int>> a[MAX];
ll d[MAX];

void dijkstra(int s) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    for (int i = 1; i <= n; i++) {
        d[i] = INF;
    }
    d[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().second;
        ll du = pq.top().first;
        pq.pop();
        if (du != d[u]) {
            continue;
        }
        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i].first;
            ll uv = a[u][i].second;
            if (d[v] > du + uv) {
                d[v] = du + uv;
                pq.push({d[v], v});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w});
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
    return 0;
}
