#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dat int
#define datpro double
#define For for(dat i=0;i<n;i++)
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX INT_MAX
bool songuyento(dat n){
    if(n < 2) return false;
    for(dat i = 2; i <= sqrt(n);i++){
        if(n % i == 0) return false;
    }
    return true;
}
int main(){
    fast
}