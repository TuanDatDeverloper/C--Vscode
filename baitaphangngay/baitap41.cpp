#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    
    vector<vector<int>> adj(n+1, vector<int>());
    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    

    
    
    vector<int> pair_u(n+1, 0); 
    vector<int> pair_v(m+1, 0); 
    vector<int> dist(n+1, 0);    
    
    
    auto bfs = [&]() -> bool{
        queue<int> q;
        for(int u = 1; u <= n; u++) {
            if(pair_u[u] == 0){
                dist[u] = 0;
                q.push(u);
            }
            else{
                dist[u] = INT32_MAX;
            }
        }
        dist[0] = INT32_MAX;
        
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(u != 0){
                for(auto &v: adj[u]){
                    if(pair_v[v] == 0){
                        if(dist[0] == INT32_MAX){
                            dist[0] = dist[u] + 1;
                        }
                    }
                    else{
                        if(dist[pair_v[v]] == INT32_MAX){
                            dist[pair_v[v]] = dist[u] + 1;
                            q.push(pair_v[v]);
                        }
                    }
                }
            }
        }
        return dist[0] != INT32_MAX;
    };
    
  
    function<bool(int)> dfs = [&](int u) -> bool{
        if(u != 0){
            for(auto &v: adj[u]){
                if(pair_v[v] == 0 || (dist[pair_v[v]] == dist[u] + 1 && dfs(pair_v[v]))){
                    pair_u[u] = v;
                    pair_v[v] = u;
                    return true;
                }
            }
            dist[u] = INT32_MAX;
            return false;
        }
        return true;
    };
    
    
    while(bfs()){
        for(int u = 1; u <= n; u++){
            if(pair_u[u] == 0){
                dfs(u);
            }
        }
    }
    
  
    vector<pair<int, int>> matching;
    for(int u = 1; u <= n; u++) {
        if(pair_u[u] != 0){
            matching.emplace_back(u, pair_u[u]);
        }
    }
    

    cout << matching.size() << "\n";
    for(auto &[a, b]: matching){
        cout << a << " " << b << "\n";
    }
}
