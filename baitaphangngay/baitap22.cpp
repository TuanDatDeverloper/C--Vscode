/*Viết chương trình nhập vào hai số nguyên a,b. In ra hai số đó theo thứ tự nhỏ đến lớn.
Input
  Hai số nguyên a,b mỗi số trên 1 dòng.
Output
  In ra hai số đó theo thứ tự nhỏ đến lớn
  example
input
1234567 
7655454555
output
1234567 7655454555
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long a,b;
    cin >> a >> b;
    cout << min(a,b) << " " << max(a,b) << endl;
    return 0;
}