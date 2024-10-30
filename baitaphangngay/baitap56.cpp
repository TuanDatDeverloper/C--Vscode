/*
Lipon là một cậu bé đam mê toán học, cậu rất muốn khám phá ra nhưng điều mới lạ trong toán học. Một ngày nọ, cậu khám phá ra dãy số Fibonacci, Lipon càng tìm hiểu sâu hơn thì biết được dãy số ấy được tạo ra bởi Leonardo Fibonacci. Cậu ấy liền nghĩ ra một dãy số và đặt tên nó là dãy số Lipon.
Dãy số Lipon được định nghĩa như sau:
L1  = 14
Li  = (Li−1 ∗2+2) mod 1000
Khi đi học lại, Lipon giới thiệu cho Anfel (người bạn thân nhất của Lipon) thì Anfel đã thử thách Lipon.
Anfel cho Lipon 2 số tự nhiên a và b và bảo Lipon tính tổng các số từ số thứ a đến số thứ b của dãy số Lipon trong vòng 1 giây. Vì số a và số b mà Anfel cho quá lớn nên Lipon không thể tính nhanh được, cậu nhờ các coder (trong đó có bạn) để giải hộ thử thách của Anfel.
Vì là một coder tốt bụng, bạn hãy giúp Lipon nhé.
Input
  Dòng đầu tiên chứa hai số tự nhiên a và b (a ≤ b ≤ 10^16)
Output
  Dòng đầu tiên là kết quả tìm được
Subtasks
Subtask 1: (a ≤ b ≤ 10^5) (40% số điểm)
Subtask 2: (a ≤ b ≤ 10^16) (60% số điểm)
Example
Input
1 10
Output
1348
*/

#include <iostream>
using namespace std;

long long get_lipon(long long n) {
    if (n == 1) return 14;
    long long prev = 14;
    for (long long i = 2; i <= n; i++) {
        prev = (prev * 2 + 2) % 1000;
    }
    return prev;
}

int main() {
    long long a, b;
    cin >> a >> b;
    
    long long sum = 0;
    for (long long i = a; i <= b; i++) {
        sum += get_lipon(i);
    }
    
    cout << sum << endl;
    return 0;
}
