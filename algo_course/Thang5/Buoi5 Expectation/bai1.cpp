#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define MOD 1'000'000'007
using namespace std;
int n, m;
double power(double a, int b)
{
    double res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a);
        a *= a;
        b >>= 1;
    }
    return res;
}
void initial()
{
    cin >> m >> n;
}
int main()
{
    initial();
    double ans = 0;
    FOR(i, 1, m)
    {
        ans += (double)i * (power(((double)i / m), n) - power(((double)(i - 1) / m), n));
    }
    cout << fixed << setprecision(4) << ans;
}