//chương trình hiển thị những số lớn hơn hoặc bằng 0 và nhỏ hơn hoặc bằng 10 trong mảng 
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] >= 0 && a[i] <= 10){
            cout << a[i] << " ";
        }
    }
    return 0;
}