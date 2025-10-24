#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
using namespace std;

int m, n;
int a[1505], b[1505];
int f[1505][1505];

void initial()
{
    cin >> m >> n;
    FOR(i, 1, m)
    cin >> a[i];
    FOR(i, 1, n)
    cin >> b[i];
    // reset
    FOR(i, 0, m)
    FOR(j, 0, n)
    f[i][j] = 0;
}

void solve()
{
    FOR(i, 1, m)
    {
        int maxlength = 0;
        FOR(j, 1, n)
        {
            f[i][j] = f[i - 1][j];
            if (a[i] == b[j])
                f[i][j] = max(f[i][j], maxlength + 1);
            if (2 * b[j] <= a[i])
                maxlength = max(maxlength, f[i - 1][j]);
        }
    }

    int ans = 0;
    FOR(j, 1, n)
    ans = max(ans, f[m][j]);
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        initial();
        solve();
    }
    return 0;
}
/*
công thức qhđ:
gọi f[i][j] là chuỗi con dài nhất khi có i phần tử trong a và phần tử chung là b[j];
f[i][j] = f[i - 1][j]
neu a[i] == b[j]:
    f[i][j] = max(f[i - 1][y] + 1) voi y < j va 2 * b[y] <- b[j]

*/