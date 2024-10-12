//Bài tập về các toán tử
#include <iostream>
#include <iomanip>
#include <climits>
#include <io.h>
using namespace std;
int main(){
    int a;
    cout << "Nhap a: ";
    cin >> a;
    cout<<"Gia tri cua a: "<<a<<endl;
    /*Toán tử toán học: +,-,*,/,% */
    int b, c,d;
    a = 100; b = 200;
    c = a + b;
    cout<<a<<" "<<b<<" "<<c<<endl;
    a=500;b=200;
    int tong = a + b;
    int hieu = a - b;
    int tich = a * b;
    float thuong = (float)a / b; // ép kiểu a hoặc b về float);
    int du = a % b; // % là phép chia lấy dư
    cout << "Tong: " << tong << endl;
    cout << "Hieu: " << hieu << endl;
    cout << "Tich: " << tich << endl;
    cout<<"Thuong: "<<thuong<<endl;
    cout<<"Du: "<<du<<endl;
    a = 100;
    b = a++; // a gán cho b trước rồi mới tăng a lên 1
    cout<<a<<" "<<b<<endl;
    b = ++a; // a tăng lên 1 trước rồi mới gán cho b
    cout << a << " " << b << endl;
    // tương tự với --a và a--
    a = 100; b = 200;
    a = a += b; // a = a + b
    cout << a << endl;
    a = a -= b; // a = a - b
    cout << a << endl;
    a = a *= b; // a = a * b
    a = a /= b; // a = a / b
    a = a %= b; // a = a % b
    /*Toán tử so sánh : > , >= , < , <=, ==(so sánh bằng) , != (dấu khác) 
    Cú pháp : toan_hang1 toantusosanh toan_hang2 => trả về True hoặc false*/
    bool ok = a <= b; // true
    cout << ok << endl;
    ok = a >= b; // false
    cout << ok << endl;
    ok = a == b; // false
    cout << ok << endl;
    ok = a != b; // true
    cout << ok << endl;
    /*Toán tử logic: AND,OR,NOT
    AND : &&
    OR : ||
    NOT : ! */
    a = 100; b = 200; c = 300; d= 400;
    int result = (a <= b) && (c <= d); // True
    cout << result << endl;
    result = (a == b) || (c > d); // False
    cout << result << endl;
    result = !(a == b); // True
    cout << result << endl;

    return 0;
}