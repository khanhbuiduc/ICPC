#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;

int h[1005][1005];
bool canSee[1005][1005];
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin >> n;
    FOR(i, 0, n - 1)
    FOR(j, 0, n - 1)
    {
        cin >> h[i][j];
    }
    // Duyệt từ trái sang phải
    FOR(i, 0, n - 1)
    {
        int maxHeight = 0;
        FOR(j, 0, n - 1)
        {
            if (h[i][j] > maxHeight)
            {
                canSee[i][j] = true;
                maxHeight = h[i][j];
            }
        }
    }

    // Duyệt từ phải sang trái
    FOR(i, 0, n - 1)
    {
        int maxHeight = 0;
        FORD(j, n - 1, 0)
        {
            if (h[i][j] > maxHeight)
            {
                canSee[i][j] = true;
                maxHeight = h[i][j];
            }
        }
    }

    // Duyệt từ trên xuống dưới
    FOR(j, 0, n - 1)
    {
        int maxHeight = 0;
        FOR(i, 0, n - 1)
        {
            if (h[i][j] > maxHeight)
            {
                canSee[i][j] = true;
                maxHeight = h[i][j];
            }
        }
    }

    // Duyệt từ dưới lên trên
    FOR(j, 0, n - 1)
    {
        int maxHeight = 0;
        FORD(i, n - 1, 0)
        {
            if (h[i][j] > maxHeight)
            {
                canSee[i][j] = true;
                maxHeight = h[i][j];
            }
        }
    }

    // Đếm số ô có thể nhìn thấy
    int ans = 0;
    FOR(i, 0, n - 1)
    FOR(j, 0, n - 1)
    {
        if (canSee[i][j])
        {
            ans++;
        }
    }

    cout << ans;
    return 0;
}
/*
cho mảng h[i][j]. vị trí (i,j) có độ cao h[i][j].
nhìn thấy cột (i,j) nếu nó cao hơn hàng cột trồng sách trc đó theo hướng nhìn.

//
duyệt từ trên xuống
    => dánh dấu ô xem đc
duyệt từ dưới lên
    => dánh dấu ô xem đc
duyệt từ trái sang phải
    => dánh dấu ô xem đc
duyệt từ phải sang trái
    => dánh dấu ô xem đc
---
duyệt lại 1 lần đếm ô đánh dấu.
---------------------------
*/