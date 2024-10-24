#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

// Function to compute (a * b) % MOD handling negative numbers
ll mul_mod(ll a, ll b) {
    ll res = ((a % MOD) * (b % MOD)) % MOD;
    if (res < 0) res += MOD;
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<ll> A(n);
    for(auto &x:A) cin >> x;

    int count_zero =0;
    vector<ll> non_zero;
    vector<ll> negatives;
    for(auto x:A){
        if(x ==0){
            count_zero++;
        }
        else{
            non_zero.push_back(x);
            if(x <0){
                negatives.push_back(x);
            }
        }
    }

    // If there are two or more zeros, product is zero
    if(count_zero >=2){
        cout << 0;
        return 0;
    }

    // If there is exactly one zero
    if(count_zero ==1){
        // Compute product of non-zero elements
        // If there are no non-zero elements, product is zero
        if(non_zero.empty()){
            cout << 0;
            return 0;
        }
        // Compute the product
        ll product =1;
        for(auto x: non_zero){
            product = (product * ((x % MOD) + MOD)) % MOD;
        }
        // Determine if the product is positive
        int sign =1;
        for(auto x: non_zero){
            if(x <0){
                sign *= -1;
            }
        }
        if(sign >0){
            cout << product;
        }
        else{
            // Maximum between product and 0
            // Since product is negative, 0 is greater
            cout << 0;
        }
        return 0;
    }

    // If there are no zeros
    // Check number of negatives
    int neg_count = negatives.size();
    if(neg_count %2 ==0){
        // Product of all elements
        ll product =1;
        for(auto x:A){
            product = (product * ((x % MOD) + MOD)) % MOD;
        }
        // Adjust for negative product
        int sign =1;
        for(auto x:A){
            if(x <0){
                sign *= -1;
            }
        }
        if(sign >0){
            cout << product;
        }
        else{
            // Negative product is less than any positive, but since all products are negative, it's the maximum possible
            // So print the negative product modulo
            cout << ((product % MOD) + MOD) % MOD;
        }
        return 0;
    }
    else{
        // Odd number of negatives, remove the negative with smallest absolute value
        // Find the negative with smallest absolute value
        ll min_abs_neg = LLONG_MAX;
        int idx = -1;
        for(int i=0;i<A.size();i++){
            if(A[i] <0){
                if(abs(A[i]) < min_abs_neg){
                    min_abs_neg = abs(A[i]);
                    idx = i;
                }
            }
        }
        // Remove A[idx] and compute product
        ll product =1;
        for(int i=0;i<A.size();i++){
            if(i == idx) continue;
            product = (product * ((A[i] % MOD) + MOD)) % MOD;
        }
        // The product is positive
        cout << product;
        return 0;
    }
}
