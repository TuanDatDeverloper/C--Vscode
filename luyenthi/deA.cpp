/*
Bờm đang nghiên cứu mực nước biển ở hành tinh Quạt Mo. Sau nhiều ngày theo dõi, Bờm nhận thấy rằng quy luật của mực nước biển là: mực nước biển của một ngày bất kì bằng trung bình cộng mực nước biển của ngày hôm trước và ngày hôm sau. Dựa vào ghi chép mực nước biển hai ngày đầu của Bờm, hãy tính toán mực nước biển ngày thứ N.
Input
  Dòng 1: chứa 2 số nguyên b,a là mực nước biển 2 ngày đầu (−100 ≤ a,b ≤ 100). Số a là mực nước ngày thứ nhất, số b là mực nước ngày thứ 2.
  Dòng 2: chứa số nguyên dương N (3 ≤ N ≤ 10^12). 
Output
  Mực nước biển ngày thứ N.
Scoring
Subtask 1 (50% số điểm): n ≤ 10^7 
Subtask 2 (50% số điểm): 10^7 < n ≤ 10^12 
Example                                                                                                                                                        Test 1 
Input 
1 2 
3 
Output 
3 
Test 2
Input 
3 1
​3 
Output 
-1 
*/
#include <iostream>
using namespace std;

int main() {
    long long a, b, N;
    cin >> a >> b;
    cin >> N;
    
    long long d = b - a; // common difference
    long long tideN = a + d * (N - 1);
    
    cout << tideN;
    return 0;
}