/*
Cho một xâu con độ dài n. Hãy tìm cách thay thế nhiều nhất 2 kí tự để thu được 1 xâu đối xứng.
Input
Gồm T testcase (T ≤ 10), mỗi testcase nằm trên một dòng:
  Mỗi dòng gồm 1 xâu s (∣s∣ ≤ 600)
Output
  Hãy in ra T dòng, mỗi dòng là YES nếu có cách thực hiện yêu cầu trên, hoặc NO nếu không tồn tại cách nào.
Example
Input 
zcxxxc
xxczxx
zxcvbn 
Output
YES
YES
NO
Note
Cách biến đổi từng testcase như sau:
zcxxxc -> ccxxcc
xxczxx -> xxccxx
không có cách biến đổi thoả mãn
*/
// Lưu ý: Đề bài yêu cầu thay thế nhiều nhất 2 kí tự để thu được 1 xâu đối xứng
// Để xâu đối xứng thì xâu đó phải có số kí tự chẵn và số kí tự xuất hiện của mỗi kí tự phải chẵn
// Nếu xâu có số kí tự lẻ thì không thể tạo xâu đối xứng
// Nếu xâu có số kí tự chẵn thì chỉ cần kiểm tra số lần xuất hiện của mỗi kí tự
// Nếu có 2 kí tự xuất hiện lẻ thì không thể tạo xâu đối xứng
// Nếu có 1 kí tự xuất hiện lẻ thì chỉ cần thay thế 1 kí tự đó để tạo xâu đối xứng
// Nếu không có kí tự nào xuất hiện lẻ thì chỉ cần thay thế 2 kí tự bất kì để tạo xâu đối xứng
#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
    int n = s.length();
    int cnt[26] = {0};
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }
    int odd = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 == 1) {
            odd++;
        }
    }
    if (n % 2 == 0) {
        if (odd == 0) {
            return true;
        }
        return false;
    }
    if (odd == 1) {
        return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (check(s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

