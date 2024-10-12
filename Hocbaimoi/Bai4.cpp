#include <iostream>
using namespace std;
int main(){
    //1 khai báo hằng số
    const float PI = 3.14f;
    const int DOSoi = 100;
    cout <<"Gia tri cua PI là:" <<" "<<PI<< endl;
    cout << DOSoi << endl;
    //2. type promotion
    int a = 5;
    double b = 7.5;
    // xuất thử a+b
    cout << a + b << endl;
    // khai báo biến nhận giá trị của a+b
    int kq;
    kq = a + b;
    cout <<"Giá trị kq là "<< kq << endl;

    double kq2;
    kq2 = a + b;
    cout <<"Giá trị kq2 là "<< kq2 << endl;
}