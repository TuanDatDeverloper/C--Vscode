#include <bits/stdc++.h>
using namespace std;
int main(){
    char a;
    cin >> a;
    if((a>='a' && a<='z') || (a>='A' && a<='Z')){
    if((a =='z')||(a=='Z')){
        cout << "a\n";

    } 
    else{
        if(a>='A' && a<='Z'){
            a+=32;
        }
        ++a;
        cout << a << endl;
        
    }
    }
    else{ 
        cout << "Invalid\n";
    }
    return 0;
}