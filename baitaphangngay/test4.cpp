//HCMUT_QDL
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;      
    ll W, H;    
    cin >> N >> W >> H;
    
    vector<pair<ll, int> > items(N);
    ll sum_values = 0;  
    for(int i = 0; i < N; i++){
        cin >> items[i].first >> items[i].second;
        sum_values += items[i].second;
    }
    
    vector<ll> dp_all(sum_values + 1, INF);
    dp_all[0] = 0;  
    

    for(int i = 0; i < N; i++){
        ll weight = items[i].first;
        int value = items[i].second;
        
        for(int v = sum_values; v >= value; v--){
            if(dp_all[v - value] + weight < dp_all[v]){
                dp_all[v] = dp_all[v - value] + weight;
            }
        }
    }
    
   
    int max_without_extra = 0;
    for(int v = 0; v <= sum_values; v++){
        if(dp_all[v] <= W){
            max_without_extra = max(max_without_extra, v);
        }
    }
    
    
    ll overall_max = max_without_extra;
    
   
    for(int j = 0; j < N; j++){
        ll extra_weight = items[j].first;
        int extra_value = items[j].second;
        
        if(extra_weight > H){
            continue; 
        }
        
       
        vector<ll> dp_exc(sum_values + 1, INF);
        dp_exc[0] = 0; // Base case
        
        for(int y = 0; y < N; y++){
            if(y == j){
                continue; 
            }
            ll current_weight = items[y].first;
            int current_value = items[y].second;
            for(int v = sum_values; v >= current_value; v--){
                if(dp_exc[v - current_value] + current_weight < dp_exc[v]){
                    dp_exc[v] = dp_exc[v - current_value] + current_weight;
                }
            }
        }
        
        int max_with_extra = 0;
        for(int v = 0; v <= sum_values; v++){
            if(dp_exc[v] <= W){
                max_with_extra = max(max_with_extra, v);
            }
        }
       
        ll total_value = (ll)max_with_extra + (ll)extra_value;
        
        overall_max = max(overall_max, total_value);
    }
    
  
    cout << overall_max;
}