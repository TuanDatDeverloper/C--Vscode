/*Cho một mảng a gồm n số nguyên dương a1, a2,..., an. Gọi trọng
số của mảng là tổng của các (ai + aj) (1 ≤ i ≤ j ≤ n) thỏa mãn
ai + aj lẻ. Bạn hãy tìm trọng số của mảng a.
Vì trọng số có thể rất lớn, hãy in ra kết quả mod 10^9 +7.
Input
Dòng đầu tiên gồm số nguyên dương n (1 ≤ n ≤ 10^6).
Dòng thứ hai gồm n số nguyên dương a1, a2,..., an (1 ≤ a ≤ 10^9).
Output
Gồm một dòng duy nhất là trọng số của mảng a mod 10^9 + 7.
*/
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    long long a[n];

    // Đọc mảng
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long count_even = 0, count_odd = 0;

    // Đếm số lượng số chẵn và số lẻ
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0)
            count_even++;
        else
            count_odd++;
    }

    long long res = 0;

    // Tính trọng số
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            // Nếu là số chẵn, cộng tổng của nó với tất cả các số lẻ
            res = (res + a[i] * count_odd) % MOD;
        } else {
            // Nếu là số lẻ, cộng tổng của nó với tất cả các số chẵn
            res = (res + a[i] * count_even) % MOD;
        }
    }

    // In ra kết quả
    cout << res << endl;
    return 0;
}

