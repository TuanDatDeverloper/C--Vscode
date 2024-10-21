#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a;
    cin >> a;
    const int MAX_A = 200000;
    vector<int> last_seen(MAX_A +1, -1);
    while(a--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &x: a) cin >> x;
        ll answer=0;
        int j=0;
        vector<int> used_values;
        for(int i=0; i<n; i++){
            int val = a[i];
            if(last_seen[val] >= j){
                j = last_seen[val] +1;
            }
            if(last_seen[val]==-1){
                used_values.push_back(val);
            }
            last_seen[val] = i;
            answer += (ll)(i - j +1);
        }
        cout << answer << " ";
    
        for(auto val: used_values){
            last_seen[val] = -1;
        }
    }
    cout << "\n";
}
