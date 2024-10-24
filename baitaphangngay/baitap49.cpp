#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int maxSumNonContiguous = 0;
        int maxElement = a[0];
        bool hasPositive = false;
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) {
                maxSumNonContiguous += a[i];
                hasPositive = true;
            }
            if (a[i] > maxElement) {
                maxElement = a[i];
            }
        }
        if (!hasPositive) {
            maxSumNonContiguous = maxElement;
        }
        int maxSubarraySum = a[0];
        int maxEndingHere = a[0];
        for (int i = 1; i < n; i++) {
            maxEndingHere = max(maxEndingHere + a[i], a[i]);
            maxSubarraySum = max(maxSubarraySum, maxEndingHere);
        }

        cout << maxSumNonContiguous << " " << maxSubarraySum << endl;
    }

    return 0;
}
