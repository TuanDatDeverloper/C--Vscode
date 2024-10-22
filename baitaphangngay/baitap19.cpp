/*Cô giáo trường tiểu học X đang dạy n học sinh tập xe đạp, các học sinh được đánh số từ 1 tới n, học sinh thứ j có trọng lượng là aj. Có một xe đạp duy nhất với tải trọng là m, hai học sinh chỉ có thể cùng lên xe nếu tổng trọng lượng của hai học sinh không vượt quá m.
Cô giáo tự hỏi có bao nhiêu cách chọn hai học sinh khác nhau cho cùng lên xe, sau nhiều giờ tính toán không có kết quả, cô quyết định hỏi các chuyên gia lập trình giải bài toán Counting Student Pairs (CSP) Yêu cầu: Đếm số cặp chỉ số i,j trong đó i < j và ai + aj ≤ m
Input
Dòng 1 chứa hai số nguyên dương n,m (m ≤ 10^6)
Dòng 2 chứa n số nguyên dương a1, a2, …,an ( ∀i : ai ≤ 10^6)
Output
Ghi một số nguyên duy nhất là đáp số
Scoring
Subtask #1 (60% số điểm): n ≤ 10^4.
Subtask #2 (20% số điểm): n ≤ 10^5.
Subtask #3 (20% số điểm): n ≤ 10^6.
*/
#include <bits/stdc++.h>
using namespace std;
// đọc số lượng học sinh và tải trọng của xe
int n, m;
// đọc trọng lượng của từng học sinh
vector<int> a;
int main(){
    cin >> n >> m;
    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    // sắp xếp trọng lượng của học sinh
    sort(a.begin(), a.end());
    // đếm số cặp học sinh
    long long res = 0;
    for(int i = 0; i < n; i++){
        // tìm vị trí của học sinh có trọng lượng nhỏ nhất mà cùng lớn hơn m - a[i]
        int pos = upper_bound(a.begin(), a.end(), m - a[i]) - a.begin();
        // cập nhật kết quả
        res += pos;
        // trừ đi trường hợp i,j
        if(pos > i){
            res--;
        }
    }
    // in ra kết quả
    cout << res / 2 << endl;
    return 0;
}
