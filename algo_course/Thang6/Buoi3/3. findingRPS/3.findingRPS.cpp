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
int t, n, countR[200'005], countS[200'005], countP[200'005];
map<char, char> win = {{'R', 'S'}, {'S', 'P'}, {'P', 'R'}};
string competitor;
void initial()
{
    cin >> competitor;
    n = competitor.length();
    competitor = '0' + competitor;
    FOR(i, 1, n)
    {
        char c = competitor[i];
        countR[i] = countR[i - 1] + (c == 'R' ? 1 : 0);
        countP[i] = countP[i - 1] + (c == 'P' ? 1 : 0);
        countS[i] = countS[i - 1] + (c == 'S' ? 1 : 0);
    }
}
void solve()
{
    int ans = 0;
    int max_k = 0;
    FOR(k, 2, n)
    {
        int cur = 0;
        for (int j = 1; j <= n; j += k)
        {
            int r = min(j + k - 1, n);
            int pre_l = j - 1;
            int cntR = countR[r] - countR[pre_l];
            int cntP = countP[r] - countP[pre_l];
            int cntS = countS[r] - countS[pre_l];
            cur += max({cntR, cntP, cntS});
        }
        if (ans <= cur)
        {
            ans = cur;
            max_k = k;
        }
    }
    cout << max_k << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--)
    {
        initial();
        solve();
    }
}
