#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n, a, b; //<1000000000
void initial()
{
    cin >> a >> b >> n;
}
void solve()
{
    if (a > b)
        swap(a, b);
    int g = __gcd(a, b);
    if (n % g)
    {
        cout << "-1" << endl;
        return;
    }
    a /= g, b /= g, n /= g;
    FORD(y, n / b, 0)
    {
        if ((n - b * y) % a == 0)
        {
            int x = (n - b * y) / a;

            cout << x + y << endl;
            return;
        }
    }
    cout << "-1" << endl;
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        initial();
        solve();
    }
}

/*
1. a * x + b * y = n
2. x + y nhỏ nhất có thể
3. tự đặt: a<=b;

g = gcd(a, b); nếu n % g!=0 => in -1;

rút gọn: a/=g;b/=g; c/=g;

gcd(a,b) = 1;

nếu có (x1, y1) và (x2, y2) và y1 < y2 thì x1 + y1 >= x2 + y2

ax1 + by1 = n <=>  x1+y1 = (n-b.y1+a.y1) /a
ax2 + by2 = n <=> x2+ y2 = (n-b.y2+a.y2) /a

x1 + y1 >= x2 + y2 <=> y1<=y2 (a<=b) luôn đúng.

vậy ta chọn y2.


ax + by = n
for y: n / b -> 0
    neu (n - by)%a == 0
        đặt x = (n - by) / a
        xuat x + y, dung thuat toan
*/