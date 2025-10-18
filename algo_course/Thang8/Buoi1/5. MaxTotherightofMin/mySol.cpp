#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
int a[1'000'005];
int n;

ll merge(int L, int R)
{
    int mid = (L + R) >> 1;
    vector<int> sufMinL;
    // preMaxR
    FOR(i, mid + 1, R)
    {
        preMaxR.push_back(a[i]);
    }
    FOR(i, mid + 2, R)
    {
        preMaxR[i] = max(preMaxR[i - 1], preMaxR[i]);
    }
    // more
    ll more = 0;
    for (auto ri : preMaxR)
    {
        auto lower = lower_bound(ALL(sufMinL), ri);
        if (lower == sufMinL.begin())
            continue;
        lower--;
        more += (lower - sufMinL.begin() + 1);
    }
    return more;
}

ll solve(int L, int R)
{
    if (L == R)
        return 0;
    int mid = (L + R) / 2;
    ll left = solve(L, mid);
    ll right = solve(mid + 1, R);
    return left + right + merge(L, R);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    FOR(i, 1, n)
    {
        cin >> a[i];
    }
    cout << solve(1, n);
}

/*
    cho hoán vị p[1..n] distin
    lấy p[l..r]. minpos = index min p[l..r], maxpos = index maxp[l..r]
    đếm số chuỗi con có: maxPos > minPos

    solve(1..n) = solve(1..mid) + solve(mid+1..r) + more

    more:
    5 3 6 1 4 2
    -> min trái, max phải;
    => cặp đc thêm vào thỏa mãn: min trái phải là min của 2 bên, max phải là max 2 bên
    sufMin[l..r]: sufmin[i] = min a[i..r];
    preMax[l..r]: preMax[i] = max a[1..i];

    left = 5 3 6 và Right = 1 4 2
    left:
        cnt = 2
        sufmin = 3 3 6
        premax = 5 5 6
    right
        cnt = 2
        sufmin = 1 2 2
        premax = 1 4 4
    với mỗi ri:right:
        lower = lower_bound(sufmin, ri)
        lower = sufmin.begin(); continue;
        lower--;
        more += lower - sufmin.begin()

    lỗi 1:256Mb <(1 triệu int = 4tr*8 = 32 triệu)
*/