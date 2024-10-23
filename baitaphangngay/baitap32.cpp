#include <bits/stdc++.h>
using namespace std;

bool isPerfectSquare(long long x) {
    if (x < 0) return false;
    long long root = sqrt(x);
    return root * root == x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<long long> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long max_val = LLONG_MIN;
    
    for (int i = 0; i < n; i++) {
        if (!isPerfectSquare(a[i])) {
            max_val = max(max_val, a[i]);
        }
    }
    
    cout << max_val << "\n";
    return 0;
}
