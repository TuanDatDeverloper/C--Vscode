#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int original_ones = count(s.begin(), s.end(), '1');
    
    // Khởi tạo max_gain với giá trị nhỏ nhất có thể là -1
    int max_gain = -1;
    int current_gain = 0;

    for (char c : s) {
        // Tính gain cho mỗi ký tự
        current_gain += (c == '0') ? 1 : -1;
        
        // Cập nhật max_gain nếu current_gain lớn hơn
        if (current_gain > max_gain) {
            max_gain = current_gain;
        }
        
        // Nếu current_gain < 0, reset current_gain
        if (current_gain < 0) {
            current_gain = 0;
        }
    }

    // Kết quả là số lượng '1' ban đầu cộng với max_gain
    // Nếu toàn bộ xâu là '1', max_gain sẽ là -1
    cout << original_ones + max_gain << "\n";

    return 0;
}
