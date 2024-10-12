//Kiểu dữ liệu và biến
#include <iostream>
#include <iomanip>
using namespace std;
/*kiểu dữ liệu số
1.số nguyên: int, long, short
n bit ==> -2^(n-1) -> 2^(n-1)-1
int:4byte=32bit: -2^31 -> 2^31-1
longlong:8byte=64bit:-2^63 -> 2^63-1
unsigned int: 0 -> 2^32-1
unsigned long: 0 -> 2^64-1 
short: 2byte=16bit: -2^15 -> 2^15-1
char: 1byte=8bit: -2^7 -> 2^7-1 (Lưu ký tự)
2.số thực: float, double, long double
float: 4byte 
double: 8byte 
3.kiểu dữ liệu logic: bool (true/false) 
4.Biến: lưu trữ giá trị
ví dụ: int a=5; 
float bankinh;
*/
int main(){
cout << "Tuan Dat\n";
cout << INT_MAX << INT_MIN << endl;
cout << LLONG_MAX << LLONG_MIN << endl;
cout << UINT_MAX << endl;
cout << ULONG_MAX << endl;
cout << SHRT_MAX << SHRT_MIN << endl;
cout << CHAR_MAX << CHAR_MIN << endl;
int banKinh;
cout << "banKinh"<<endl;
cout<<"Xin chao"<<endl;
int a,b,c;
cout << "Nhap a,b,c :";
cin >> a >> b >> c ;
cout <<a<<" "<<b<<" "<<c<<endl;
long long d;
cin >> d;
cout << d<<endl;
float e;
cin >> e;
cout << fixed << setprecision(4) << e << endl;//in ra 4 số sau dấu phẩy
double f;
cin >> f;
cout<<fixed<<setprecision(10)<<f<<endl;//in ra 10 số sau dấu phẩy
char kytu='a';//chi lưu 1 ký tự và phải đặt trong dấu nháy đơn
cin >> kytu;
cout << kytu<<endl;
bool oke=true;// true=1, false=0
cout << oke<<endl;
    return 0;
}