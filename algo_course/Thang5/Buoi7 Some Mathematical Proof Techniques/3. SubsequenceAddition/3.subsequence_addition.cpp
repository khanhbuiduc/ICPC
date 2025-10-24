#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n, a[100'005];
void initial()
{
    cin >> n;
    FOR(i, 1, n)
    cin >> a[i];
}
void solve()
{
    sort(a + 1, a + n + 1);
    if (a[1] != 1)
    {
        cout << "NO";
        return;
    }
    int sum = 1;

    FOR(i, 2, n)
    {
        if (a[i] <= sum)
        {
            sum += a[i];
            continue;
        }
        cout << "NO";
        return;
    }
    cout << "YES";
}
int main()
{
    initial();
    solve();
}
