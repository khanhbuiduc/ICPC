#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
using namespace std;

int n, k, p, x_0 = 0, y_0 = 0, placed = 0;
string arr[1005];
int row[1005], col[1005];

void initial()
{
    x_0 = 0, y_0 = 0, placed = 0;
    FOR(i, 1, n)
    row[i] = col[i] = 0;

    FOR(i, 1, n)
    {
        cin >> arr[i];
        arr[i] = '0' + arr[i];
    }
    FOR(i, 1, n)
    FOR(j, 1, n)
    {
        if (arr[i][j] == 'R')
        {
            row[i] = col[j] = 1;
            placed++;
        }
    }
    FOR(i, 1, n)
    {
        if (row[i] == 1)
            x_0++;
        if (col[i] == 1)
            y_0++;
    }
}

bool check(int x, int y)
{
    if (y < 0 || y > n)
        return false;
    if (x < x_0 || y < y_0)
        return false;
    if (k < max(x - x_0, y - y_0))
        return false;
    if ((x == 0 && y != 0) || (x != 0 && y == 0))
        return false;
    if (placed + k > x * y)
        return false;
    return true;
}

void solve()
{
    FOR(x, x_0, n)
    {
        int y = 2 * (placed + k) - p - x;
        if (!check(x, y))
            continue;

        cout << "YES\n";

        int new_cr = min(x - x_0, y - y_0);
        int new_r = (x - x_0) - new_cr;
        int new_c = (y - y_0) - new_cr;
        int old_cr = k - new_cr - new_r - new_c;

        // đặt new_cr (hàng trống × cột trống)
        FOR(i, 1, n)
        FOR(j, 1, n)
        {
            if (new_cr > 0 && row[i] == 0 && col[j] == 0 && arr[i][j] != 'R')
            {
                arr[i][j] = 'R';
                row[i] = col[j] = 1;
                new_cr--;
            }
        }

        // đặt new_r (hàng trống × cột có sẵn)
        FOR(i, 1, n)
        FOR(j, 1, n)
        if (new_r > 0 && row[i] == 0 && col[j] == 1 && arr[i][j] != 'R')
        {
            arr[i][j] = 'R';
            row[i] = 1;
            new_r--;
        }

        // đặt new_c (cột trống × hàng có sẵn)
        FOR(i, 1, n)
        FOR(j, 1, n)
        if (new_c > 0 && col[j] == 0 && row[i] == 1 && arr[i][j] != 'R')
        {
            arr[i][j] = 'R';
            col[j] = 1;
            new_c--;
        }

        // đặt old_cr (hàng đã có × cột đã có)
        FOR(i, 1, n)
        FOR(j, 1, n)
        if (old_cr > 0 && row[i] == 1 && col[j] == 1 && arr[i][j] != 'R')
        {
            arr[i][j] = 'R';
            old_cr--;
        }

        // in kết quả
        FOR(i, 1, n)
        {
            FOR(j, 1, n)
            cout << arr[i][j];
            cout << "\n";
        }
        return;
    }
    cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true)
    {
        cin >> n >> k >> p;
        if (n == 0)
            return 0;
        initial();
        solve();
    }
}
// lỗi khi làm bài:

// 1: thêm đồng thời new_c, new_r, new_cr, old_cr gây ra lỗi vì khi đặt quân thì thành 'R' và không đc đặt thêm nữa