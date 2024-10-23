#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
   
    vector<int> negative_values;
    
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            negative_values.push_back(-a[i]); 
        }
    }
    
    
    sort(negative_values.rbegin(), negative_values.rend());
    
    
    int max_damage = 0;
    for (int i = 0; i < min(m, (int)negative_values.size()); i++) {
        max_damage += negative_values[i];
    }
    
    cout << max_damage << "\n";
    
    return 0;
}
