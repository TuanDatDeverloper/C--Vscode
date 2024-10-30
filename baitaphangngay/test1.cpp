#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, K;
vector<vector<pair<int, int>>> adj;
vector<int> size_subtree;
vector<bool> blocked_flag;
int ans_result = INF;
vector<int> sum_to_min_edges;

int compute_size(int u, int parent) {
    size_subtree[u] = 1;
    for(auto &[v, l] : adj[u]){
        if(v != parent && !blocked_flag[v]){
            size_subtree[u] += compute_size(v, u);
        }
    }
    return size_subtree[u];
}

int find_centroid(int u, int parent, int total_size) {
    for(auto &[v, l] : adj[u]){
        if(v != parent && !blocked_flag[v] && size_subtree[v] > total_size / 2){
            return find_centroid(v, u, total_size);
        }
    }
    return u;
}

void collect_paths(int u, int parent, int current_sum, int edge_count, vector<pair<int, int>> &paths) {
    if(current_sum > K) return;
    paths.emplace_back(current_sum, edge_count);
    for(auto &[v, l] : adj[u]){
        if(v != parent && !blocked_flag[v]){
            collect_paths(v, u, current_sum + l, edge_count + 1, paths);
        }
    }
}

void solve(int u){
    compute_size(u, -1);
    int c = find_centroid(u, -1, size_subtree[u]);
    fill(sum_to_min_edges.begin(), sum_to_min_edges.end(), INF);
    sum_to_min_edges[0] = 0;
    vector<int> active_sums;
    active_sums.push_back(0);
    for(auto &[v, l] : adj[c]){
        if(!blocked_flag[v]){
            vector<pair<int, int>> paths;
            collect_paths(v, c, l, 1, paths);
            for(auto &[s, e] : paths){
                if(K - s >=0 && K - s <= K){
                    if(sum_to_min_edges[K - s] < INF){
                        ans_result = min(ans_result, e + sum_to_min_edges[K - s]);
                    }
                }
            }
            for(auto &[s, e] : paths){
                if(s <= K && sum_to_min_edges[s] > e){
                    sum_to_min_edges[s] = e;
                    active_sums.push_back(s);
                }
            }
        }
    }
    for(auto s : active_sums){
        sum_to_min_edges[s] = INF;
    }
    blocked_flag[c] = true;
    for(auto &[v, l] : adj[c]){
        if(!blocked_flag[v]){
            solve(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    adj.assign(N, vector<pair<int, int>>());
    for(int i=0; i<N-1; ++i){
        int u, v, l;
        cin >> u >> v >> l;
        adj[u].emplace_back(v, l);
        adj[v].emplace_back(u, l);
    }
    size_subtree.assign(N, 0);
    blocked_flag.assign(N, false);
    sum_to_min_edges.assign(K+1, INF);
    solve(0);
    if(ans_result < INF){
        cout << ans_result;
    }
    else{
        cout << "-1";
    }
}
