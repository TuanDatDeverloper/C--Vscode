#include <bits/stdc++.h>
using namespace std;

int n, k, c[1000001], f[1000001];

int main()
{
    cin >> n >> k;
    for(int u, i = 1; i <= k; i++)
    {
        cin >> u;
        c[u] = 1;
    }
    f[1] = 1;
    for(int i = 1; i <= n; i++)
    {
        if(c[i] == 1)
            continue;
        if(i + 1 <= n && c[i+1] == 0)
        {
            f[i+1] = (f[i+1] + f[i]) % 14062008;
        }
        if(i + 2 <= n && c[i+2] == 0)
        {
            f[i+2] = (f[i+2] + f[i]) % 14062008;
        }
    }
    cout << f[n];
    return 0;
}