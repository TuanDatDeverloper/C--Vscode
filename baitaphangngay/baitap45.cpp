#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

// Hàm nhân theo modulo, xử lý số âm
ll mul_mod(ll a, ll b) {
    a %= MOD;
    b %= MOD;
    ll res = (a * b) % MOD;
    if (res < 0) res += MOD;
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<ll> A(n);
    int zeros = 0;
    vector<ll> neg;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
        if(A[i] == 0) {
            zeros++;
        }
        else if(A[i] < 0) {
            neg.push_back(A[i]);
        }
    }
    
    // Trường hợp có hai hoặc nhiều số 0
    if(zeros >= 2) {
        cout << 0;
        return 0;
    }
    
    // Trường hợp có đúng một số 0
    if(zeros == 1) {
        // Tính tích của các phần tử không phải là 0
        ll prod = 1;
        bool all_zero = true;
        for(auto x : A) {
            if(x != 0) {
                all_zero = false;
                prod = mul_mod(prod, x);
            }
        }
        // Nếu tất cả đều là 0
        if(all_zero) {
            cout << 0;
            return 0;
        }
        // Kiểm tra dấu của tích
        int sign = 1;
        for(auto x : A) {
            if(x < 0) sign *= -1;
        }
        if(sign > 0) {
            cout << prod;
        }
        else {
            // Nếu tích âm, thì không có cách nào để có tích dương khi chỉ loại bỏ một số (zero đã được loại bỏ)
            // Do đó, tối đa là 0
            cout << 0;
        }
        return 0;
    }
    
    // Trường hợp không có số 0
    if(neg.size() % 2 == 0) {
        // Số lượng số âm chẵn, tính tích tất cả các phần tử
        ll prod = 1;
        for(auto x : A) {
            prod = mul_mod(prod, x);
        }
        cout << prod;
    }
    else {
        // Số lượng số âm lẻ, cần loại bỏ số âm có giá trị tuyệt đối nhỏ nhất
        // Tìm số âm có giá trị tuyệt đối nhỏ nhất
        ll min_neg = LLONG_MAX;
        int idx = -1;
        for(int i = 0; i < n; i++) {
            if(A[i] < 0 && abs(A[i]) < min_neg) {
                min_neg = abs(A[i]);
                idx = i;
            }
        }
        
        // Tính tích các phần tử ngoại trừ số âm có giá trị tuyệt đối nhỏ nhất
        ll prod = 1;
        bool removed = false;
        for(int i = 0; i < n; i++) {
            if(i == idx && !removed) {
                removed = true; // Loại bỏ số âm này
                continue;
            }
            prod = mul_mod(prod, A[i]);
        }
        cout << prod;
    }
    return 0;
}
