#include <bits/stdc++.h>
using namespace std;
int main (){
    long long a, b;
    cin>>a>>b;
    int tong = a + b;
    int hieu = a / b;
    long long tich = a * b;
    float thuong = (float)a / b;
    cout<<tong<<" "<<hieu<<" "<<tich<<" "<<fixed<<setprecision(2)<<thuong<<endl;
    return 0;


}