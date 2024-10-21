#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int> adj[100005];
int par[100005][20];
int depth_node[100005];
void dfs(int u, int p_node)
{
    par[u][0] = p_node;
    for(int j = 1; j < 20; j++)
    {
        par[u][j] = par[par[u][j-1]][j-1];
    }
    for(int v : adj[u])
    {
        if(v != p_node)
        {
            depth_node[v] = depth_node[u] + 1;
            dfs(v, u);
        }
    }
}
int lca(int u, int v)
{
    if(depth_node[u] < depth_node[v])
        swap(u, v);
    for(int i = 19; i >= 0; i--)
    {
        if(depth_node[u] - (1 << i) >= depth_node[v])
            u = par[u][i];
    }
    if(u == v)
        return u;
    for(int i = 19; i >= 0; i--)
    {
        if(par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}
int distance_func(int u, int v)
{
    int w = lca(u, v);
    return depth_node[u] + depth_node[v] - 2 * depth_node[w];
}
bool check(int x, int y, int z)
{
    int dist_xz = distance_func(x, z);
    int dist_xy = distance_func(x, y);
    int dist_yz = distance_func(y, z);
    return (dist_xz == dist_xy + dist_yz);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> q;
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    depth_node[1] = 0;
    dfs(1, 1); 
    
    while(q--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if(check(x, y, z))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
