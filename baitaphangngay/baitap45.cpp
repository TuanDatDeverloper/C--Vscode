#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

long long power_mod(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

long long maxProduct(vector<int>& nums) {
    int n = nums.size();
    int count_zero = 0;
    int count_neg = 0;
    long long product_non_zero = 1;
    long long min_abs_neg = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            count_zero++;
            continue;
        }
        product_non_zero = (product_non_zero * ((nums[i] % MOD + MOD) % MOD)) % MOD;
        if (nums[i] < 0) {
            count_neg++;
            min_abs_neg = min(min_abs_neg, (long long)abs(nums[i]));
        }
    }

    if (count_zero > 1) {
        return 0;
    }
    if (count_zero == 1) {
        return max(product_non_zero, 0LL);
    }
    if (count_neg % 2 == 0) {
        return product_non_zero;
    }
    return (product_non_zero * power_mod(min_abs_neg, MOD - 2, MOD)) % MOD;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << maxProduct(nums) << endl;
    return 0;
}
