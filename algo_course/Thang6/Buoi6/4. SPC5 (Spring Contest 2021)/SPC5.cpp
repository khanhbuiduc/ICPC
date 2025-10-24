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
const long long mod = 1'000'000'007LL;
typedef long long ll;
string s;
int n;
ll f[305][305][305];
void solve()
{
    f[0][0][0] = 1;
    FOR(i, 0, n - 1)
    FOR(oneEye, 0, i)
    FOR(eyeAndMouth, 0, i)
    {
        if (f[i][oneEye][eyeAndMouth] == 0)
            continue;
        ll cur = f[i][oneEye][eyeAndMouth];
        if (s[i + 1] == 'T')
        {
            (f[i + 1][oneEye + 1][eyeAndMouth] += cur) %= mod;
            if (eyeAndMouth)
                (f[i + 1][oneEye][eyeAndMouth - 1] += (eyeAndMouth * cur) % mod) %= mod;
        }
        else
        {
            if (oneEye)
                (f[i + 1][oneEye - 1][eyeAndMouth + 1] += (oneEye * cur) % mod) %= mod;
            if (eyeAndMouth)
                (f[i + 1][oneEye][eyeAndMouth] += (eyeAndMouth * cur) % mod) %= mod;
        }
    }
    cout << f[n][0][0] << endl;
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
        cin >> s;
        n = s.length();
        s = ' ' + s;
        FOR(i, 0, n)
        FOR(j, 0, n)
        FOR(k, 0, n)
        f[i][j][k] = 0;
        solve();
    }
}