// github copilot giúp tôi giải bài thi lập trình thi đấu này
/*Given array A consisting of n integers ai. Tuan wants to remove at most 1 element in array A so that the product of all remaining elements in that array is the largest.
Please help Tuan do it!
You task is to calculate the product of all remaining elements in that array after removed at most 1 element.
Input
The first line contains a positive integer n(2 ≤ n ≤ 1000).
Next line contains n integers ai separated by a space (−10^9 ≤ ai ≤ 10^9).
Output
  Print the result of the problem. Since it may be too big, print it after taking modulo 10^9 +7.
Example
input
4
4 2 3 5
output
120
input
5
-1 -2 -4 1 2
output
16
input

*/
// github copilot giúp tôi giải bài thi lập trình thi đấu này
// input reading : The code first reads the number of elements n and then the array A.
// Counting Zeros and Negatives: It iterates through the array to count the number of zeros and negative numbers.It also keeps track of the index of the first zero and the negative number closest to zero
// Decision Making Based on Counts:Based on the counts of zeros and negatives, it decides whether to remove a zero, remove a negative number, or keep all elements.It uses the compute_product function to calculate the product accordingly.
// Product Computation:The compute_product function calculates the product of all elements except the one to be skipped (if any).It handles the sign of the product and ensures the result is within the modulo 10^9 + 7
// Output:Finally, it prints the computed maximum product.
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

// Hàm tính (a * b) % MOD an toàn
ll mul_mod(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

// Hàm tính tích của các phần tử, có thể bỏ qua một chỉ số
ll compute_product(const vector<int>& A, int skip = -1) {
    ll product = 1;
    bool has_zero = false;
    for(int i = 0; i < A.size(); i++) {
        if(i == skip) continue;
        if(A[i] == 0) {
            has_zero = true;
            break;
        }
        product = mul_mod(product, A[i]);
    }
    if(has_zero) return 0;
    // Điều chỉnh cho tích âm
    if(product < 0) {
        product = (product + MOD) % MOD;
    }
    return product;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    
    int zeros = 0, negatives = 0;
    int first_zero = -1, closest_negative = -1;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == 0)
        {
            zeros++;
            if (first_zero == -1)
                first_zero = i;
        }
        else if (A[i] < 0)
        {
            negatives++;
            // Tìm số âm có giá trị tuyệt đối nhỏ nhất
            if (closest_negative == -1 || abs(A[i]) < abs(A[closest_negative]))
            {
                closest_negative = i;
            }
        }
    }
    
    ll answer = 0;
    
    if (zeros >= 2)
    {
        // Hơn hai số 0, tích là 0
        answer = 0;
    }
    else if (zeros == 1)
    {
        if (negatives % 2 == 0)
        {
            // Loại bỏ số 0 để có tích của các phần tử không phải 0
            bool all_non_zero = (n - zeros) > 0;
            if (all_non_zero)
            {
                ll product = 1;
                for(int i = 0; i < n; i++) {
                    if(A[i] == 0) continue;
                    product = mul_mod(product, A[i]);
                }
                // Điều chỉnh cho tích âm nếu cần
                if(product < 0) {
                    product = (product + MOD) % MOD;
                }
                answer = product;
            }
            else
            {
                // Tất cả các phần tử đều là 0
                answer = 0;
            }
        }
        else
        {
            // Số lượng số âm lẻ, giữ lại số 0 để tránh tích âm
            answer = 0;
        }
    }
    else
    {
        if (negatives % 2 == 0)
        {
            // Số lượng số âm chẵn, tích của tất cả các phần tử là tối đa
            ll product = 1;
            for(int i = 0; i < n; i++) {
                product = mul_mod(product, A[i]);
            }
            // Điều chỉnh cho tích âm nếu cần (không nên xảy ra vì số âm chẵn)
            if(product < 0) {
                product = (product + MOD) % MOD;
            }
            answer = product;
        }
        else
        {
            // Số lượng số âm lẻ, loại bỏ số âm có giá trị tuyệt đối nhỏ nhất
            if(negatives == 0)
            {
                // Không có số âm và không có số 0, tích dương
                ll product = 1;
                for(int i = 0; i < n; i++) {
                    product = mul_mod(product, A[i]);
                }
                if(product < 0) {
                    product = (product + MOD) % MOD;
                }
                answer = product;
            }
            else
            {
                // Loại bỏ số âm có giá trị tuyệt đối nhỏ nhất
                ll product = compute_product(A, closest_negative);
                answer = product;
            }
        }
    }
    
    // Xử lý trường hợp tất cả các phần tử đều là 0
    bool all_zero = true;
    for(int i = 0; i < n; i++) {
        if(A[i] != 0){
            all_zero = false;
            break;
        }
    }
    if(all_zero){
        answer = 0;
    }
    
    cout << answer << "\n";
    return 0;
}


