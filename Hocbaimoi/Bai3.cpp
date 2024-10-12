#include <iostream>
#include <math.h>
using namespace std;
int main(){
    // abs(x) : trả về giá trị tuyệt đối của x
    // pow(x,y) : trả về x^y: trả về số double
    //sqrt(x) : trả về căn bậc 2 của x
    //round(x) : làm tròn số x
    int x = -100;
    int y = abs(x); // gán giá trị tuyệt đối của x cho y
    cout << y << endl;
    int a = 2, b = 3;
    int res = pow(a, b); // 2^3 = 8.00000
    cout << res << endl;
    int c = 16;
    int can = sqrt(c); // căn bậc 2 của 16 = 4.00000
    cout << can << endl;
float d = 5.14657;
int e = round(d); // làm tròn số d
cout << e << endl;
    return 0;


}