// Hàm trong ngôn ngữ lập trình C++
#include <bits/stdc++.h>
using namespace std;
// Nạp chồng hàm
int tong(int a, int b){
  return a + b;
}
float tong(float a, float b){
  return a + b;
}
int main(){
    float n = 100.2,m=200.5;
    cout << tong(n,m) << endl;

}
// muốn thay đổi giá trị của biến thì phải truyền tham chiếu bằng cách thêm dấu & trước tên biến