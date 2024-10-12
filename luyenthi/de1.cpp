#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    for(int scenario=1; scenario<=T; scenario++){
        int N, M;
        cin >> N >> M;
        // Initialize adjacency list
        vector<vector<int>> adj(N+1);
        for(int i=0; i<M; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // Initialize color array
        vector<int> color(N+1, 0);
        bool isBipartite = true;
        // BFS function
        for(int i=1; i<=N && isBipartite; i++){
            if(color[i]==0){
                // Start BFS
                queue<int> q;
                q.push(i);
                color[i] = 1;
                while(!q.empty() && isBipartite){
                    int u = q.front(); q.pop();
                    for(auto &v: adj[u]){
                        if(color[v]==0){
                            color[v] = 3 - color[u];
                            q.push(v);
                        }
                        else if(color[v] == color[u]){
                            isBipartite = false;
                            break;
                        }
                    }
                }
            }
        }
        // Output
        cout << "Scenario #" << scenario << ":\n";
        if(isBipartite){
            cout << "No suspicious bugs found!\n";
        }
        else{
            cout << "Suspicious bugs found!\n";
        }
    }
}
