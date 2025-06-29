#include <bits/stdc++.h>
#pragma GCC target("popcnt") // dùng khi n*3 và TLE
using namespace std;
bitset<3005> grid[3005];
int main()
{
    int n;
    long long res = 0LL;
    string s;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        for (int j = 1; j <= n; ++j)
        {
            if (s[j - 1] == '1')
            {
                grid[i].set(j, 1);
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int cnt = (grid[i] & grid[j]).count();
            if (cnt)
                res += (cnt * (cnt - 1) / 2);
        }
    }
    cout << res;
    return 0;
}