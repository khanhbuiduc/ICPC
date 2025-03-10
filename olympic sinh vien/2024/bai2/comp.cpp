#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("path.inp", "r", stdin);
    freopen("path.out", "w", stdout);
    string s;
    cin >> s;
    int ans = 0;
    int n = s.size() - 1;
    for (int i = 0; i < n; i++)
    {

        if (i & ~n)
            continue;
        ans ^= ((s[i] - '0'));
    }
    cout << ans;
}