#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    int k;
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> k;
    int tong = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == k){
            tong ++;
        }
    }
    cout << tong;
    return 0;
}