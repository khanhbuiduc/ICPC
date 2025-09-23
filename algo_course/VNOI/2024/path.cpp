#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()

int a[1005][1005];
bool canMove[1005][1005];
ll fact[200'005], invfact[200'005];
const int mod = 1'000'000'007;

ll powerMod(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            (res *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return res;
}

void pre_calculator()
{
    fact[0] = 1;
    FOR(i, 1, 200'000)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    invfact[200'000] = powerMod(fact[200'000], mod - 2);
    FORD(i, 199'999, 0) // Sửa lại phạm vi
    {
        invfact[i] = (invfact[i + 1] * (i + 1)) % mod;
    }
}

ll C(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    return ((fact[n] * invfact[k]) % mod * invfact[n - k]) % mod;
}

int main()
{
    pre_calculator();
    int n, m, k, x, y;
    cin >> n >> m >> k;
    //--------case -1------ k=0
    if (k == 0)
    {
        cout << C(n + m - 2, n - 1);
        return 0;
    }
    // Khởi tạo mảng canMove
    FOR(i, 0, 1000)
    FOR(j, 0, 1000)
    canMove[i][j] = true;

    int max_kx = 0, max_ky = 0;
    FOR(i, 1, k)
    {
        cin >> x >> y;
        canMove[x][y] = false;
        max_kx = max(max_kx, x);
        max_ky = max(max_ky, y); // Sửa lại so sánh với y
    }

    //--------case 0------
    a[1][1] = 1;
    FOR(x, 1, max_kx)
    FOR(y, 1, max_ky)
    {
        if (!canMove[x][y])
            continue;
        if (x + 1 <= n && canMove[x + 1][y])
            (a[x + 1][y] += a[x][y]) %= mod;
        if (y + 1 <= m && canMove[x][y + 1])
            (a[x][y + 1] += a[x][y]) %= mod;
    }
    //---------case 1----
    if (max_kx == n && max_ky == m)
    {
        cout << a[n][m];
        return 0;
    }
    //---------case 1-------
    // FOR(x, 1, max_kx)
    // {
    //     FOR(y, 1, max_ky)
    //     {
    //         cout << a[x][y] << ' ';
    //     }
    //     cout << endl;
    // }
    //--------case 2--------
    ll res = 0;
    if (max_kx < n)
        FOR(y, 1, max_ky)
        {
            if (a[max_kx][y] == 0)
                continue;
            int goDown = n - max_kx - 1;
            int goRight = m - y;
            (res += (1ll * a[max_kx][y] * C(goDown + goRight, goDown)) % mod) %= mod;
        }

    if (max_ky < m)
        FOR(x, 1, max_kx)
        {
            if (a[x][max_ky] == 0)
                continue;
            int goDown = n - x;
            int goRight = m - max_ky - 1;
            (res += (1ll * a[x][max_ky] * C(goDown + goRight, goDown)) % mod) %= mod;
            // cout << goDown << goRight << endl;
        }

    cout << res;
    return 0;
}
/*
lưới n*m, n<10^5, m<10^5
đếm có bao nhiêu đường đi thỏa mãn:
rô bôt:
    + đi xuống và sang phải
    + chướng ngại vật {x<=1000,y<=1000}
tính số đường đi mod 10^9 + 7

-----------
chỉ đếm trong khoảng trong khoảng (kx max, ky max):
-----------
case 1:
nếu max_kx == n và max_ky == m;
    ans = a[n][m];
    in ra.
----------
case 2:
    res = 0;
    nếu max_kx < n: xét vị trí (max_kx + 1, y) với y: 1-> m
        r= n - (max_kx + 1) + 1 hàng
        c=m - y + 1 cột
        num_way = C(r + c - 2,r - 1)
        res += num_way * a[max_kx + 1, y]
    nếu max_ky < m: xét vị trí (x, max_ky + 1) với x: 1-> n
        r= n - x + 1 hàng
        c= m - (max_ky + 1) + 1 cột
        num_way = C(r + c - 2,r - 1)
        res += num_way * a[max_kx + 1, y]
    in ra kết quả.
---


*/