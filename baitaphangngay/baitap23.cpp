/*Cho một dãy số gồm n số nguyên a1, a2, …,an. Với mỗi tập con khác rỗng  	S = (i1, i2, …,ik) 
(0	< k ≤ n,1 ≤ i1 < i2 < … < ik ≤ n), gọi f(S) là số nguyên nhỏ nhất mà chia hết cho mọi aij  
(1	≤ j ≤ k), tức là
f(S) = lcm(ai1 , ai2 , …,aik ) .
Yêu cầu: Hãy tính R = ∑f(S) với tất cả mọi tập con S khác rỗng. Vì R có thể rất lớn nên chỉ cần đưa ra số dư của R khi chia cho 10^9 + 7.
Input
Dòng đầu tiên gồm một số nguyên dương T (1 ≤ T ≤ 10) là số bộ dư liệu. T nhóm dòng sau, mỗi nhóm dòng thể hiện một bộ dữ liệu có dạng sau.
Dòng đầu tiên gồm một số nguyên dương n (1 ≤ n ≤ 100) --- là số phần tử của dãy.
Dòng thứ hai gồm n số nguyên dương a1,a2, …,an  (1 ≤ ai ≤ 500). Output
  Gồm T dòng, mỗi dòng là kết quả của các bộ dữ liệu theo đúng thứ tự trong đầu vào.
Scoring
Subtask 1 (15% số điểm): n ≤ 20,ai ≤ 20.
Subtask 2 (20% số điểm): n ≤ 20.
Subtask 3 (25% số điểm): Bội chung nhỏ nhất của n số nguyên dương không vượt quá 50000.
Subtask 4 (40% số điểm): Không có ràng buộc gì thêm.
Example
Input 
3
2
2 4
10
1 2 3 4 5 6 7 8 9 10
3
20 3 14
Output
10
516031
699*/
#include <bits/stdc++.h>
using namespace std;

// hàm tính GCD
long long gcd(long long a, long long b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

// hàm tính LCM
long long lcm(long long a, long long b){
    return a / gcd(a,b) * b;
}

// tránh bị lỗi TLE
const long long mod = 1e9 + 7;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        
        long long res = 0;
        int totalSubsets = 1 << n; // 2^n tập con
        vector<long long> lcmMemo(totalSubsets, -1); // memoization array

        for(int mask = 1; mask < totalSubsets; mask++){
            if (lcmMemo[mask] != -1) {
                res = (res + lcmMemo[mask]) % mod;
                continue;
            }
            long long currentLcm = 1;
            for(int i = 0; i < n; i++){
                if(mask & (1 << i)){
                    currentLcm = lcm(currentLcm, a[i]);
                    if(currentLcm > mod) currentLcm %= mod; // tránh tràn số
                }
            }
            lcmMemo[mask] = currentLcm;
            res = (res + currentLcm) % mod;
        }
        
        cout << res << endl;
    }
    return 0;
}
