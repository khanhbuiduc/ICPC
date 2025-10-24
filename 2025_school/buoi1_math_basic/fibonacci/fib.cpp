#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a), _b = b; i <= (_b); i++)
typedef long long ll;
int mod = 1'000'000'007;
int fib(int n)
{
    int f0 = 0;
    int f1 = 1;
    int f2 = 1;
    FOR(i, 2, n)
    {
        f2 = (0ll + f0 + f1) % mod;
        f0 = f1;
        f1 = f2;
    }
    return f1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << fib(n) << " ";
    return 0;
}

// tính fib(100'000'000)