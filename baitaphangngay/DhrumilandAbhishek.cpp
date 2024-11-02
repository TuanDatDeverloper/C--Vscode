/*
Time limit: 2s
Dhrumil and Abhishek are playing a game on an array, Abhishek gives Dhrumil an array a1,a2,…,an consisting of n levels.
Abhishek provides Dhrumil with two types of operations:
Type 1: Abhishek gives Dhrumil an index and a value, and Dhrumil must update a[index]=value
Type 2: Abhishek asks Dhrumil to calculate the weighted sum of points between two indices l and r: 1∗a[l]+2∗a[l+1]+3∗a[l+2]+4∗a[l+3]....
In this version, l = 1 and r = n
Your task is to help Dhrumil to accurately find the points, else he will lose the game
Input
The first line of input contains an integer t(1≤t≤1000) — the number of test cases. 
For each test case:
The first line contains two integers n and q(1≤n,q≤10^5) — the size of the array and the number of queries.
The second line contains n integers a1,a2,…,an (1≤ai≤10^9) — the initial values of the array.
Then, the next q lines contain the following types of queries:
Type 1: 1 index value — update a[index]=value.
Type 2: 2 l r — compute and output the weighted sum S(l,r).
It is guaranteed that the sum of all n+q across all test cases does not exceed 10^6.
Output
For each query of Type 2, output the weighted sum S(l,r).
Example
Input
3
5 3
1 2 4 1 5
2 1 5
1 3 10
2 1 5
5 1
1 2 3 4 5
2 1 5
10 4
1 3 2 7 9 6 9 2 6 7
1 1 9
2 1 10
1 6 3
2 1 10
Output
46
64
55
333
315

*/
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
