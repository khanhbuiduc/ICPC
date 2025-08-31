#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
using namespace std;
typedef tuple<int, int, int> product;
typedef long long ll;
template <class X, class Y>
bool minimize(X &x, const Y &y)
{
    if (x > y)
    {
        x = y;
        return true;
    }
    else
        return false;
}
const int N = 3005;
const ll INF = 1'000'000'000'000'007;
int n;

product p[N];

// Sắp xếp theo b[i] - c[i]
bool cmp(const product &p1, const product &p2)
{
    auto [a1, b1, c1] = p1;
    auto [a2, b2, c2] = p2;
    return (b1 - c1) < (b2 - c2);
}

ll dp_AB[N][N], dp_AC[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    FOR(i, 1, n)
    {
        int a, b, c;
        cin >> a >> b >> c;
        p[i] = {a, b, c};
    }
    sort(p + 1, p + n + 1, cmp);

    // dp_AB[i][j]: min cost to buy first i items, j items bought at B
    FOR(i, 0, n)
    FOR(j, 0, i)
    {
        dp_AB[i][j] = INF;
    }
    dp_AB[0][0] = 0;

    FOR(i, 0, n - 1)
    {
        auto [a, b, c] = p[i + 1];
        FOR(j, 0, i)
        {
            if (dp_AB[i][j] == INF)
                continue;
            // Buy next item at A
            minimize(dp_AB[i + 1][j], dp_AB[i][j] + a);
            // Buy next item at B
            minimize(dp_AB[i + 1][j + 1], dp_AB[i][j] + b - j);
        }
    }

    // dp_AC[i][j]: min cost to buy items i..n, j items bought at C
    FOR(i, 0, n + 1)
    FOR(j, 0, n)
    {
        dp_AC[i][j] = INF;
    }
    dp_AC[n + 1][0] = 0;

    FORD(i, n, 1)
    {
        auto [a, b, c] = p[i];
        FOR(j, 0, n - i + 1)
        {
            if (dp_AC[i + 1][j] == INF)
                continue;
            // Buy item i at A
            minimize(dp_AC[i][j], dp_AC[i + 1][j] + a);
            // Buy item i at C
            minimize(dp_AC[i][j + 1], dp_AC[i + 1][j] + c - j);
        }
    }

    ll ans = INF;
    // Tách tại vị trí i: 1..i mua ở A/B, i+1..n mua ở A/C
    FOR(i, 0, n)
    {
        ll min_AB = INF, min_AC = INF;
        FOR(j, 0, i) { minimize(min_AB, dp_AB[i][j]); }
        FOR(j, 0, n - i) { minimize(min_AC, dp_AC[i + 1][j]); }
        minimize(ans, min_AB + min_AC);
    }
    cout << ans << '\n';
}
/*
mua hàng lần thứ t + 1 ở siêu thị B hoặc C được giảm t đồng
A: 5 7 9 9 6
B: 5 8 9 9 6
C: 9 5 5 5 9

nhận xét: mua  5 món ở siêu thị b thì sum =  giá 5 món - (1+2+...4)

vậy sét 2 món: b[i] và c[i].
    ta sẽ sắp xếp món hàng tăng dần theo b[i] - c[i];
    khi đó ta chỉ cần QHD 2 chiều

có 20 món: 9 món mua ở B,4 món mua ở A. 11 món còn lại mua ở C và A
---
gọi f_AB[i][j] là min số tiền khi mua i sản phẩm, j sản phẩm mua của B

bài toán cơ sở: f_AB[0][0] = 0, f_AB[i][j] = inf

QHD:
    món i+1 mua ở A
        f_AB[i + 1][j] = min(f_AB[i + 1][j], f_AB[i][j] + a[i + 1])
    món i+1 mua ở B
        f_AB[i + 1][j + 1] - min(f_AB[i + 1][j + 1], f_AB[i][j] + c[i + 1] - j)
--------
gọi f_AC[i][j] là min số tiền khi mua i sản phẩm cuối, j sản phẩm mua của C

bài toán cơ sở: f_AC[n+1][0] = 0, f_AC[i][j] = inf

QHD:
    món i-1 mua ở A
        f_AC[i - 1][j] = min(f_AC[i - 1][j], f_AC[i][j] + a[i + 1])
    món i-1 mua ở C
        f_AC[i - 1][j + 1] - min(f_AC[i - 1][j + 1], f_AC[i][j] + c[i - 1] - j)
---------
món 1->i mua ở A,B; món i+1->n mua ở A,C

tổng tiền = Min(f_AB[i][j|] + f_AC[i + 1][j'])

Min_f_AB[i] = min(f_AB[i][j]) với j từ 0->i
Min_f_AC[i] = min(f_AC[i][j]) với j từ 0->i

tính min (Min_f_AB[i], Min_f_AC[i])  với i: 1->n;
*/