#include <bits/stdc++.h>
using namespace std;
int64_t a, b, M;
int64_t fib(int num)
{
    int64_t a1 = 1, a2 = 1, a3 = 2;
    if (num <= 2)
        return 1;
    if (num == 3)
        return 2;
    while (num > 3)
    {
        a1 = a2;
        a2 = a3;
        a3 = (a1 + a2) % M;
        num--;
    }
    return a3 % M;
}
int main()
{
    // freopen("gcd.inp", "r", stdin);
    // freopen("gcd.out", "w", stdout);
    cin >> a >> b >> M;
    // tính fib(gcd(a,b))%M

    int64_t ans = __gcd(a, b);
    cout << fib(ans);
    return 0;
}