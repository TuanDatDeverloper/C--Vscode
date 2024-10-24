#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; 
    ll w, h; 
    cin >> n >> w >> h;
    vector<pair<ll, int>> v(n);
    ll sum_ci = 0;
    for(int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second; 
        sum_ci += v[i].second;
    }
    vector<ll> dp(sum_ci + 1, INF);
    dp[0] = 0;

    for(int i = 0; i < n; i++){
        ll wi = v[i].first;
        int ci = v[i].second;
        for(int s = sum_ci; s >= ci; s--){
            if(dp[s - ci] + wi < dp[s]){
                dp[s] = dp[s - ci] + wi;
            }
        }
    }
    int maxtotal = 0;
    for(int s = 0; s <= sum_ci; s++){
        if(dp[s] <= w){
            maxtotal = max(maxtotal, s);
        }
    }
    ll ans = maxtotal;
    for(int j = 0; j < n; j++){
        ll wj = v[j].first;
        int cj = v[j].second;
        if(wj > h) continue; 
        vector<ll> dp1(sum_ci + 1, INF);
        dp1[0] = 0;
        for(int k = 0; k < n; k++){
            if(k == j) continue; 
            ll wk = v[k].first;
            int ck = v[k].second;
            for(int s = sum_ci; s >= ck; s--){
                if(dp1[s - ck] + wk < dp1[s]){
                    dp1[s] = dp1[s - ck] + wk;
                }
            }
        }
        int maxj = 0;
        for(int s = 0; s <= sum_ci; s++){
            if(dp1[s] <= w){
                maxj = max(maxj, s);
            }
        }
        ll tv = (ll)maxj + (ll)cj;
        ans= max(ans, tv);
    }
    cout << ans;
    return 0;
}