#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    ll W, H;
    cin >> N >> W >> H;
    
    struct Item {
        ll w;
        int c;
    };
    
    vector<Item> items(N);
    ll sum_c = 0;
    for(int i=0; i<N; ++i){
        cin >> items[i].w >> items[i].c;
        sum_c += items[i].c;
    }
    
    // Initialize dp_all
    // dp_all[v] = min sum of weights to achieve value v
    // sum_c up to 100,000
    int max_sum_c = sum_c;
    // Using vector<ll> for dp_all
    vector<ll> dp_all(max_sum_c +1, INF);
    dp_all[0] = 0;
    
    for(int i=0; i<N; ++i){
        ll wi = items[i].w;
        int ci = items[i].c;
        for(int v = max_sum_c; v >= ci; --v){
            if(dp_all[v - ci] + wi < dp_all[v]){
                dp_all[v] = dp_all[v - ci] + wi;
            }
        }
    }
    
    // Find the maximum v_all with dp_all[v_all] <= W
    int v_all = 0;
    for(int v=0; v<=max_sum_c; ++v){
        if(dp_all[v] <= W){
            v_all = v;
        }
    }
    
    ll max_total = v_all;
    
    // Iterate over each item j with w_j <= H
    for(int j=0; j<N; ++j){
        if(items[j].w > H){
            continue;
        }
        // Initialize dp_exclude_j
        vector<ll> dp_exclude(max_sum_c +1, INF);
        dp_exclude[0] = 0;
        for(int k=0; k<N; ++k){
            if(k == j) continue;
            ll wk = items[k].w;
            int ck = items[k].c;
            for(int v = max_sum_c; v >= ck; --v){
                if(dp_exclude[v - ck] + wk < dp_exclude[v]){
                    dp_exclude[v] = dp_exclude[v - ck] + wk;
                }
            }
        }
        // Find the maximum v_j with dp_exclude_j[v_j] <= W
        int v_j = 0;
        for(int v=0; v<=max_sum_c; ++v){
            if(dp_exclude[v] <= W){
                if(v > v_j){
                    v_j = v;
                }
            }
        }
        // Total value is v_j + c_j
        ll total = (ll)v_j + (ll)items[j].c;
        if(total > max_total){
            max_total = total;
        }
    }
    
    cout << max_total;
}
