#include <bits/stdc++.h>
using namespace std;
int f[1005][1005];
int p[1005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 0; i < 1005; i++)
        for (int j = 0; j < 1005; j++)
            f[i][j] = 1e9;
    f[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (f[i][j] == 1e9)
                continue;
            if (p[i + 1] <= 100)
            {
                // Mua bằng tiền mặt
                f[i + 1][j] = min(f[i + 1][j], f[i][j] + p[i + 1]);
                // Mua bằng coupon nếu còn
                if (j > 0)
                    f[i + 1][j - 1] = min(f[i + 1][j - 1], f[i][j]);
            }
            else
            {
                // Mua bằng tiền mặt, nhận thêm 1 coupon
                f[i + 1][j + 1] = min(f[i + 1][j + 1], f[i][j] + p[i + 1]);
                // Mua bằng coupon nếu còn
                if (j > 0)
                    f[i + 1][j - 1] = min(f[i + 1][j - 1], f[i][j]);
            }
        }
    }
    int res = 1e9;
    for (int j = 0; j <= n; j++)
        res = min(res, f[n][j]);
    cout << res;
}