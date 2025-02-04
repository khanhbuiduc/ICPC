#include <bits/stdc++.h>
using namespace std;
#define NAME "paramid."

ifstream fi(NAME "inp");
ofstream fo(NAME "out");

#define t128 __int128_t
#define ll long long
// ans=n(n+1)(3m-n+1)/6: m>n
int main()
{
    int t, m, n;
    fi >> t;
    t128 ans;
    for (int i = 0; i < t; i++)
    {
        fi >> n >> m;
        if (n > m)
            swap(n, m);
        ans = (t128)n * (n + 1) * (3 * m - n + 1) / 6;
        string s = "";
        while (ans)
        {
            s = char(ans % 10 + 48) + s;
            ans /= 10;
        }
        fo << s << "\n";
    }
}