#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define ff first
#define ss second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define __builtin_popcount __builtin_popcountll
using namespace std;
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
template <class X, class Y>
bool maximize(X &x, const Y &y)
{
    if (x < y)
    {
        x = y;
        return true;
    }
    else
        return false;
}
template <class T>
T Abs(const T &x)
{
    return (x < 0 ? -x : x);
}
/// template
int n, p;
bool isBlack[35];
typedef long long ll;
const int mod = 1'000'000'007;
// gọi f[i][ew][ow][eb]
ll f[35][35][35][35];
void initial()
{
    cin >> n >> p;
    FOR(i, 1, n)
    cin >> isBlack[i];
    f[0][0][0][0] = 1;
}
void solve()
{
    // qhd:
    FOR(i, 1, n)
    FOR(ew, 0, i)
    FOR(ow, 0, i)
    FOR(eb, 0, i)
    {
        if (f[i][ew][ow][eb] == 0)
            continue;
        ll cur = f[i][ew][ow][eb];
        // xét i + 1 màu trắng thêm vào EW, OW.
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        initial();
        solve();
    }
}