#include <bits/stdc++.h>
using namespace std;
//team VKU VTD *^_^*
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Point
{
    int x, y;
};

bool inside(int x, int y, int R, int C)
{
    return (x >= 0 && x < R && y >= 0 && y < C);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int R, C, N;
    cin >> R >> C >> N;
    vector<string> a(R);
    for(int i = 0; i < R; i++)
        cin >> a[i];
    
    vector<Point> pos;
    pos.emplace_back(Point{0, 0});

    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(a[i][j] == 'S')
            {
                pos.emplace_back(Point{i, j});
            }
        }
    }

    if(pos.size() - 1 != N){
        cout << "-1";
        return 0;
    }

    int total_nodes = N + 1; 
    vector<vector<int>> dist(total_nodes, vector<int>(total_nodes, 1e9));

    for(int i = 0; i < total_nodes; i++)
    {
        vector<vector<int>> d(R, vector<int>(C, -1));
        queue<Point> q;
        q.push(pos[i]);
        d[pos[i].x][pos[i].y] = 0;
        while(!q.empty())
        {
            Point u = q.front();
            q.pop();
            for(int j = 0; j < 4; j++)
            {
                int x = u.x + dx[j];
                int y = u.y + dy[j];
                if(inside(x, y, R, C) && a[x][y] != '#' && d[x][y] == -1)
                {
                    d[x][y] = d[u.x][u.y] + 1;
                    q.push(Point{x, y});
                }
            }
        }
        for(int j = 0; j < total_nodes; j++)
        {
            dist[i][j] = d[pos[j].x][pos[j].y];
        }
    }

    bool possible = true;
    for(int i = 1; i < total_nodes; i++)
    {
        if(dist[0][i] == -1){
            possible = false;
            break;
        }
    }
    if(!possible){
        cout << "-1";
        return 0;
    }

    int SIZE = 1 << N;
    vector<vector<int>> dp(SIZE, vector<int>(total_nodes, 1e9));
    dp[0][0] = 0;

    for(int mask = 0; mask < SIZE; mask++)
    {
        for(int u = 0; u < total_nodes; u++)
        {
            if(dp[mask][u] == 1e9) continue;
            for(int v = 1; v < total_nodes; v++)
            {
                int bit = v - 1;
                if(!(mask & (1 << bit)) && dist[u][v] != -1)
                {
                    int new_mask = mask | (1 << bit);
                    dp[new_mask][v] = min(dp[new_mask][v], dp[mask][u] + dist[u][v]);
                }
            }
        }
    }

    int final_mask = (1 << N) - 1;
    int res = 1e9;
    for(int v = 1; v < total_nodes; v++)
    {
        res = min(res, dp[final_mask][v]);
    }

    if(res == 1e9)
        cout << "-1";
    else
        cout << res;

    return 0;
}
