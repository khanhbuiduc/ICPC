#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, a1, a2, b1, b2;
    cin >> n >> a1 >> a2 >> b1 >> b2;

    ll x1, x2, y1, y2;
    ll r1, r2, r12, r21, res12, res21;

    // Trường hợp 1
    x1 = a2 * b2 * n / (a1 * b1 + a2 * b2);
    x2 = x1 + 1;

    if (x1 > n)
        x1 = n;
    if (x2 > n)
        x2 = n;

    r1 = max(a1 * b1 * x1, a2 * b2 * (n - x1));
    r2 = max(a1 * b1 * x2, a2 * b2 * (n - x2));

    if (r1 < r2)
    {
        res12 = x1;
        r12 = r1;
    }
    else
    {
        res12 = x2;
        r12 = r2;
    }

    // Trường hợp 2
    y1 = a1 * b2 * n / (a2 * b1 + a1 * b2);
    y2 = y1 + 1;

    if (y1 > n)
        y1 = n;
    if (y2 > n)
        y2 = n;

    r1 = max(a2 * b1 * y1, a1 * b2 * (n - y1));
    r2 = max(a2 * b1 * y2, a1 * b2 * (n - y2));

    if (r1 < r2)
    {
        res21 = y1;
        r21 = r1;
    }
    else
    {
        res21 = y2;
        r21 = r2;
    }

    // So sánh hai kết quả
    if (r12 < r21)
    {
        cout << r12 << "\n1 " << res12 << "\n2 " << n - res12;
    }
    else
    {
        cout << r21 << "\n2 " << n - res21 << "\n1 " << res21;
    }

    return 0;
}
/*
n=20// người
a1=10 a2=30// độ liều thủ lĩnh
b1=40 b2=10// độ liều hang động
tính min (max(ai*ki*bj))
---------------------------
a1 chọn b1=> độ liều đội 1 = a1*k*b1
            => độ liều đội 2 = a2*k*b2
min nhất: a1*x*b1 = a2*(n-x)*b2
nhưng người là số nguyên.
    => tính x = a2*b2*n / (a1*b1 + a2*b2);
xét x1 =x và x2 = x+1:
    tính m1 = max(a1*x1*b1, a2*(n-x1)*b2)
        m2 = max(a1*x2*b1, a2*(n-x2)*b2)
    m1 <= m2 chọn x1; m1 > m2 chọn x2
----------------------------------------
tương tự với a1 chọn b2.

*/