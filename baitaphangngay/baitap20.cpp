#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    double max_avg = a[0];
    double current_sum = 0;
    int window_size = 1;

    for (int i = 0; i < n; i++) {
        current_sum += a[i];
        if (i >= window_size - 1) {
            double current_avg = current_sum / window_size;
            max_avg = max(max_avg, current_avg);
            current_sum -= a[i - window_size + 1];
        }
    }

    cout << fixed << setprecision(6) << max_avg << endl;
    return 0;
}
