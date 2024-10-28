/*
Để sẵn sàng triển khai tiêm Vacxin cho địa phương có nguy cơ bùng dịch cao, người ta cần dự trữ không ít hơn n liều vacxin. Hiện nay trong kho đang có m liều vacxin, trong nước có hai cơ sở A,B sản xuất Vacxin. Nếu làm việc hết công suất, cơ sở A mỗi ngày sản xuất được pa liều, còn cơ sở B sản xuất được pb liều. Em hãy xác định sớm nhất sau bao nhiêu ngày sẽ có đủ n liều vacxin?
Input
Dòng đầu ghi hai số nguyên n,m(0 ≤ n,m ≤ 10^8)
Dòng thứ hai chứa hai số nguyên pa,pb(0 ≤ pa,pb ≤ 10^5)
Output
  Ghi một số nguyên là số ngày sớm nhất có đủ vacxin dự trữ theo kế hoạch
Example
Input
200 50 
20 35 
Ouput
3
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, pa, pb;
    cin >> n >> m >> pa >> pb;

    int days = 0;
    while (m < n) {
        m += pa + pb;
        days++;
    }

    cout << days << endl;
    return 0;
}