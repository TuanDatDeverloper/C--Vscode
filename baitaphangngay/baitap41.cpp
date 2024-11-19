#include <bits/stdc++.h>
#define datpro long long
#define dat int
#define datdz double
#define MAX 1000000007
#define dd pair<dat,dat>
#define For for(dat i=0;i<n;i++)
#define tangdan sort(v.begin(),v.end())
#define giamdan sort(v.begin(),v.rend())
#define daonguoc reverse(v.begin(),v.end())
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Dat INT_MAX
using namespace std;
dat n, m, k;
vector<vector<dat>> adj;
vector<dat> pair_u, pair_v, dist;
bool bfs(){
    queue<dat> q;
    for(dat u = 1; u <= n; u++) {
        if(pair_u[u] == 0){
            dist[u] = 0;
            q.push(u);
        }
        else{
            dist[u] = Dat;
        }
    }
    dist[0] = Dat;

    while(!q.empty()){
        int u = q.front(); q.pop();
        if(u != 0){
            for(dat v: adj[u]){
                if(pair_v[v] == 0){
                    if(dist[0] == Dat){
                        dist[0] = dist[u] + 1;
                    }
                }
                else{
                    if(dist[pair_v[v]] == Dat){
                        dist[pair_v[v]] = dist[u] + 1;
                        q.push(pair_v[v]);
                    }
                }
            }
        }
    }
    return dist[0] != Dat;
}

bool dfs(dat u){
    if(u != 0){
        for(dat v: adj[u]){
            if(pair_v[v] == 0 || (dist[pair_v[v]] == dist[u] + 1 && dfs(pair_v[v]))){
                pair_u[u] = v;
                pair_v[v] = u;
                return true;
            }
        }
        dist[u] = Dat;
        return false;
    }
    return true;
}

int main(){
    fast
    cin >> n >> m >> k;

    adj.assign(n + 1, vector<dat>());
    pair_u.assign(n + 1, 0);
    pair_v.assign(m + 1, 0);
    dist.assign(n + 1, 0);

    for(dat i = 0; i < k; i++){
        dat a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    while(bfs()){
        for(dat u = 1; u <= n; u++){
            if(pair_u[u] == 0){
                dfs(u);
            }
        }
    }

    vector<pair<dat, dat>> matching;
    for(dat u = 1; u <= n; u++) {
        if(pair_u[u] != 0){
            matching.push_back(make_pair(u, pair_u[u]));
        }
    }

    cout << matching.size() << "\n";
    for(pair<dat, dat> p: matching){
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}
