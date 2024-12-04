#include <bits/stdc++.h>
using namespace std;
// 0A lùi đầu dòng, 13H là xuống dòng
//__int128: 10^40
int main()
{
    freopen("dark_m.inp", "r", stdin);
    freopen("dark_m.out", "w", stdout);
    int n, n1, ms, k = 0, m;
    string s;
    cin >> n;
    n1 = n - 1;
    // n = stol(s);
    vector<__int128_t> d(n);
    __int128_t ans = 0;
    auto get_n = [&](string s)
    {
        int flg = 1;
        __int128_t t = 0;
        if (s[0] == '-')
        {
            flg = -1;
            s.erase(0, 1);
        }
        for (int i = 0; i < s.size(); i++)
        {
            t = t * 10 + s[i] - '0';
        }
        return t * flg;
    };
    auto prt = [&](__int128_t x)
    {
        string v = "";
        int flg = 0;
        if (x < 0)
        {
            flg = 1;
            x = -x;
        };
        while (x > 0)
        {
            v = char(x % 10 + 48) + v;
            x /= 10;
        }
        if (flg)
            v = '-' + v;
        return v;
    };
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        d[i] = get_n(s);
        ans += d[i];
    }
    ans /= n;
    cout << prt(ans);
}