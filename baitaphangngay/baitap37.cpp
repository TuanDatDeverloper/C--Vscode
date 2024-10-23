#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

struct Cell {
    int x, y, cost;
    bool operator>(const Cell& other) const {
        return cost > other.cost;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    pair<int, int> start, end;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'G') {
                start = {i, j};
                grid[i][j] = 0;
            } else if (s[j] == 'R') {
                end = {i, j};
                grid[i][j] = 0;
            } else {
                grid[i][j] = s[j] - '0';
            }
        }
    }

    priority_queue<Cell, vector<Cell>, greater<Cell>> pq;
    vector<vector<int>> dist(n, vector<int>(m, INF));
    dist[start.first][start.second] = 0;
    pq.push({start.first, start.second, 0});

    while (!pq.empty()) {
        Cell current = pq.top();
        pq.pop();

        if (current.x == end.first && current.y == end.second) {
            cout << current.cost << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                int new_cost = current.cost + grid[nx][ny];
                if (new_cost < dist[nx][ny]) {
                    dist[nx][ny] = new_cost;
                    pq.push({nx, ny, new_cost});
                }
            }
        }
    }

    cout << -1 << endl; 
    return 0;
}