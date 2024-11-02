/*
Lets see how well u know your divisors, you are given q queries of two types
Type 1: 1 l r - Return number of values having odd number of divisors between l and r
Type 2: 2 l r - Return number of values having even number of divisors between l and r
Input
The first line contains an integer q (1 ≤ q ≤ 10^6) — the number of queries.
Then,the next q lines contain the following types of queries:
Type 1: 1 l r - (1 ≤ l,r ≤ 10^9)
Type 2: 2 l r - (1 ≤ l,r ≤ 10^9)
Output
For each query of type 1, return the number of numbers having odd number of divisors, and for each of type 2, return the number of numbers having even number of divisors
Example
Input
20
1 97 183
1 57 71
1 57 91
2 14 93
2 23 81
1 73 154
2 79 143
1 82 110
2 67 132
1 23 63
1 83 145
2 14 18
1 73 132
1 34 67
1 48 82
1 96 193
2 3 19
2 62 151
2 66 134
1 76 119
Output
4
1
2
74
54
4
62
1
63
3
3
4
3
3
3
4
14
85
66
2

*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Binary search to find number of perfect squares in range [l,r]
ll socp(ll l, ll r) {
    // Find first perfect square >= l
    ll left = 0, right = 1e5;
    ll first = right;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        ll square = mid * mid;
        if (square >= l) {
            first = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    // Find last perfect square <= r
    left = 0; right = 1e5;
    ll last = 0;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        ll square = mid * mid;
        if (square <= r) {
            last = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return max(0LL, last - first + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q;
    cin >> q;
    
    while (q--) {
        ll type, l, r;
        cin >> type >> l >> r;
        
        ll odd_count = socp(l, r);
        
        if (type == 1) {
            cout << odd_count << "\n";
        } else {
            cout << (r - l + 1 - odd_count) << "\n";
        }
    }
    
    return 0;
}