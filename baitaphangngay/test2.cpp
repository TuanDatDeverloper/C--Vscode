#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while(getline(cin, s)){
        if(s.empty()){
            cout << "YES\n";
            continue;
        }
        int n = s.size();
        int mismatches = 0;
        for(int i=0; i < n/2; i++){
            if(s[i] != s[n-1-i]){
                mismatches++;
            }
        }
        if(mismatches <= 2){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
} 