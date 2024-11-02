#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
long long a[MAXN], pref[MAXN];

void updatePrefix(int n, int pos) {
    // Cập nhật prefix sum từ vị trí pos
    for(int i = pos; i <= n; i++) {
        pref[i] = pref[i-1] + (long long)i * a[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        
        // Reset mảng prefix
        memset(pref, 0, sizeof(pref));
        
        // Nhập mảng và tính prefix sum
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            pref[i] = pref[i-1] + (long long)i * a[i];
        }
        
        while(q--) {
            int type;
            cin >> type;
            if(type == 1) {
                int index, value;
                cin >> index >> value;
                a[index] = value;
                updatePrefix(n, index);
            } else {
                int l, r;
                cin >> l >> r;
                // Với phiên bản này l luôn = 1 và r luôn = n
                cout << pref[r] << "\n";
            }
        }
    }
    return 0;
}
