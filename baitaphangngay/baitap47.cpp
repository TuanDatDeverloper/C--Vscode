#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 +7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> A(n);
    for(int i=0; i<n; i++) cin >> A[i];
    
    int count_zero=0, count_negative=0;
    ll min_abs_neg = LLONG_MAX;
    int remove_index = -1;
    
    for(int i=0; i<n; i++){
        if(A[i]==0){
            count_zero++;
        }
        else{
            if(A[i]<0){
                count_negative++;
                if(abs(A[i]) < min_abs_neg){
                    min_abs_neg = abs(A[i]);
                    remove_index = i;
                }
            }
        }
    }
    
    if(count_zero >=2){
        cout << 0;
        return 0;
    }
    else if(count_zero ==1){
        // Compute product of non-zero elements
        bool positive=true;
        ll product=1;
        for(int i=0; i<n; i++){
            if(A[i]==0) continue;
            if(A[i]<0){
                positive = !positive;
                product = (product * (-A[i])) % MOD;
            }
            else{
                product = (product * A[i]) % MOD;
            }
        }
        if(positive){
            cout << product;
        }
        else{
            cout << 0;
        }
        return 0;
    }
    else{
        // No zeros
        // Compute total product and sign
        bool positive=true;
        ll total_product=1;
        for(int i=0; i<n; i++){
            if(A[i]<0){
                positive = !positive;
                total_product = (total_product * (-A[i])) % MOD;
            }
            else{
                total_product = (total_product * A[i]) % MOD;
            }
        }
        if(positive){
            cout << total_product;
        }
        else{
            // Need to remove the negative element with smallest abs
            // Find the negative element with smallest abs
            ll min_abs = LLONG_MAX;
            int remove_idx = -1;
            for(int i=0; i<n; i++){
                if(A[i]<0){
                    if(abs(A[i]) < min_abs){
                        min_abs = abs(A[i]);
                        remove_idx = i;
                    }
                }
            }
            // If all elements are negative, and n==1, which cannot happen since n>=2
            // Compute the product after removing remove_idx
            ll product_new=1;
            for(int i=0; i<n; i++){
                if(i == remove_idx) continue;
                if(A[i]<0){
                    product_new = (product_new * (-A[i])) % MOD;
                }
                else{
                    product_new = (product_new * A[i]) % MOD;
                }
            }
            cout << product_new;
        }
    }
}
