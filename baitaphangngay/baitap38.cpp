/*Khi Majin Buu - một mối nguy hại lớn được giải phong ấn, các chiến binh Z phải chọn ra những chiến binh mạnh nhất để đồng hành cùng bảo vệ Trái Đất.
Họ tìm được N chiến binh, sức mạnh của người thứ i (1 ≤ i ≤ N) là pi. Bởi vì thời gian là có hạn nên team Z muốn tìm ra một chiến binh có đủ sức mạnh càng sớm càng tốt. Họ có một kĩ thuật ít người biết là Fusion Dance - kĩ thuật cho phép từ hai người có cùng sức mạnh tạo ra được một chiến binh mới có chỉ số sức mạnh bằng tổng sức mạnh của hai người đó, tức là nếu hai người thứ i và j (i j) có pi ≠ pj thì hai người này có khả năng hợp thể thành một người mới có chỉ số sức mạnh bằng (pi +pj) . Người được tạo thành từ phép hợp thể vừa nếu vẫn có thể tiếp tục hợp thể với các người khác miễn là thỏa mãn điều kiện sức mạnh bằng nhau.
Yêu cầu: Với mỗi x từ 1 đến N, hãy giúp team Z tìm ra cách tạo ra chiến binh có chỉ số sức mạnh lớn nhất từ x chiến binh đầu tiên.
Input
Dòng đầu tiên gồm một số nguyên dương N (1 ≤ N ≤ 5×10^5) là số chiến binh
Dòng tiếp theo gồm N số nguyên dương, số thứ i (1 ≤ i ≤ N) là pi  (1 ≤ pi ≤ 10^6) - sức mạnh của chiến binh thứ i.
Output
  Một dòng duy nhất gồm N số nguyên dương, số thứ x (1 ≤ x ≤ N) là chỉ số sức mạnh lớn nhất có thể có được từ x chiến binh đầu tiên
Scoring
Subtask 1 (10% số điểm): n ≤ 20.
Subtask 2 (15% số điểm): n ≤ 100.
Subtask 3 (25% số điểm): n ≤ 1000.
Subtask 4 (50% số điểm): Không có ràng buộc gì thêm.
Example
Input
5
3 2 4 1 2
Output
3 3 4 4 8*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> p(N);
    for(int &x : p) cin >> x;
    ll MAX_P = 1e6;
    ll max_p = 0;
    map<ll, ll> powerCount;
    for(int i = 0; i < N; i++) {
        ll current = p[i];
        powerCount[current]++;
        while(powerCount[current] >= 2) {
            ll pairs = powerCount[current] / 2;
            powerCount[current] %= 2;
            current *= 2;
            powerCount[current] += pairs;
        }
        max_p = max(max_p, current);
        cout << max_p << (i == N-1 ? '\n' : ' ');
    }
    
    return 0;
}
