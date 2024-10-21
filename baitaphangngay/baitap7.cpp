#include <bits/stdc++.h>
using namespace std;
//cách gọi hàm nhưng không chạy
void xinchao(int a,int b,float c){
    cout <<a;
}
//s=1+2+3+4+5+6+7+8+9+n
int tong(int n){
    return n*(n+1)/2;
}

int main(){
    for(int i = 0; i < 10; i++){
    xinchao(100,200,300);//gọi hàm xinchao
    }
    int a= 10;
    int s = tong(a);
    return 0;

}