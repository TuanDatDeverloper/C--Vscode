#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum sum of a subarray with consecutive elements using Kadane's algorithm
int maxSubArraySum(int a[], int size) {
    int max_so_far = a[0];
    int curr_max = a[0];
    for (int i = 1; i < size; i++) {
        curr_max = max(a[i], curr_max + a[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

// Function to find the maximum sum of a subarray with non-consecutive elements
int maxNonConsecutiveSubArraySum(int a[], int size) {
    int max_sum = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] > 0) {
            max_sum += a[i];
        }
    }
    // If all elements are negative, return the maximum element
    if (max_sum == 0) {
        max_sum = *max_element(a, a + size);
    }
    return max_sum;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int max_consecutive_sum = maxSubArraySum(a, n);
        int max_non_consecutive_sum = maxNonConsecutiveSubArraySum(a, n);
        cout << max_non_consecutive_sum << " " << max_consecutive_sum << endl;
    }
    return 0;
}
