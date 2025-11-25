#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
vector<ll> fib;
ll maxN = 1e18;

void ca_fib()
{
    ll f1 = 2;
    ll f2 = 3;
    fib.push_back(f1);
    fib.push_back(f2);
    while (f1 + f2 <= maxN)
    {
        ll temp = f1 + f2;
        fib.push_back(temp);
        f1 = f2;
        f2 = temp;
    }
}
int recursion(ll n, int index)
{
    if (n == 1)
        return 1;
    if (index >= fib.size())
        return 0;
    if (n < fib[index])
        return 0;
    ll res = recursion(n, index + 1);
    if (n % fib[index] == 0)
        res += recursion(n / fib[index], index);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    ca_fib();
    while (t--)
    {
        ll n;
        cin >> n;
        cout << recursion(n, 0) << endl;
    }
}
/*
2 3 5 8 13 21

f[2] = 1
f[3] = 1
f[5] = 1
f[8] = 2

1->10^18 chỉ có 85 số fib.

dp[i][x]: số cách biểu diễn số x khi xét i số fib đầu tiên
for i: 1->n
    for x: 1->n;
---
do i < 85 nên ta dùng vét cạn.

*/