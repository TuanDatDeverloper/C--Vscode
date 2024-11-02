/*
Jagjeet is a famous personality in TSEC people are mad to meet him. But there's someone for whom Jagjeet is mad.......that's his best friend Sagar. Both of them like to play cricket. But Sagar is very busy unlike Jagjeet.At time a
 (in seconds) Sagar is busy. Then every b seconds after it, he is busy for b and b+1 interval.Thus it sagar is busy at times a,a + b,a + b + 1,a + 2b,a + 2b + 1,etc.
Jagjeet is very desperate for playing cricket, but he wants to play with sagar when he is busy. Jagjeet plans to play at time c (in seconds), so he asked you to tell him if sagar is busy at that time.
Input
The first line of input contains an integer n (1 ≤ n ≤ 1000) — the number of test cases. 
The only line of each test contains 3 integers,a,b,c (1 ≤ a,b,c ≤ 10^9)
Output
Print a single "Yes" (without quotes) if it's possible to play for both of them at time c or a single "No" (without quotes) otherwise in the only line of output.
Example
Input
10
3 2 6
1 1 1
8 7 10
2 9 8
3 4 6
1 5 6
8 9 4
7 5 3
10 8 3
1 4 1
Output
Yes
Yes
No
No
No
Yes
No
No
No
Yes
*/
#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

void solve() {
    long long a, b, c;
    cin >> a >> b >> c;
    
    // Trường hợp đặc biệt: c = a
    if (c == a) {
        cout << "Yes\n";
        return;
    }
    
    // Nếu c < a, chắc chắn không bận
    if (c < a) {
        cout << "No\n";
        return;
    }
    
    // Tính khoảng cách từ c đến a
    long long diff = c - a;
    
    // Tính k bằng floor division
    long long k = diff / b;
    if (k >= 1 && (diff == k * b || diff == k * b + 1)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}