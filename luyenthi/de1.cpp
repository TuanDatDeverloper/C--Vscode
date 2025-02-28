#include <bits/stdc++.h>
using namespace std;
#define dat int
#define datpro long long 
#define datdz double
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main()
{
    FAST
    dat n;
    cin >> n;
    dat a = 1, res = 0;
    for(dat i = 0; i < n; i++)
    {
        dat ai;
        cin >> ai;
        if(ai == a)
        {
            a++;
        }
        else
        {
            res++;
        }
    }
        cout << res << endl;
    return 0;
}