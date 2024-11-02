#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
long long a[MAXN];

// Hàm tính weighted sum từ l đến r 
long long calculateWeightedSum(int l, int r) {
    long long sum = 0;
    for(int i = l, weight = 1; i <= r; i++, weight++) {
        sum += (long long)weight * a[i];
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        
        // Nhập mảng
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        
        // Xử lý từng truy vấn
        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                // Cập nhật giá trị tại vị trí index
                int index, value;
                cin >> index >> value;
                a[index] = value;
            } else {
                // Tính weighted sum từ l đến r
                int l, r;
                cin >> l >> r;
                cout << calculateWeightedSum(l, r) << endl;
            }
        }
    }
    return 0;
}

