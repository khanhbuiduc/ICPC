#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ff first
#define ss second
#define lim 300'005 //
typedef pair<int, int> pii;
typedef long long ll;
int a[1005];
int f[1005];
int n;
int lis()
{
    memset(f, 0, sizeof(f));
    // btcs: f[0] = 0
    // qhd: f[i] = max(f[0..i-1]) + 1 với a[j] < a[i]

    FOR(i, 1, n)
    FOR(j, 0, i - 1)
    {
        if (a[j] < a[i])
            f[i] = max(f[i], f[j] + 1);
    }

    int ans = 0;
    FOR(i, 1, n) { ans = max(ans, f[i]); }
    return ans;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cout << lis();
}