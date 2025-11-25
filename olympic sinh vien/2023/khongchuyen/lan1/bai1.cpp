#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll u, v;
    cin >> u >> v;
    ll ans = u * u / 4 + v * v / 4;
    int remain = ((u % 4) * (u % 4) + (v % 4) * (v % 4)) % 4;
    (remain *= 100) /= 4;
    double ans2 = remain / 4;
    cout << ans << '.' << remain;
    if (remain == 0)
        cout << 0;
}