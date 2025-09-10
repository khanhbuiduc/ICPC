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
int cnt[26];
void initial()
{
}
void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string s;
    cin >> s;
    for (auto c : s)
    {
        int ci = c - 'A';
        cnt[ci]++;
    }
    string str = "", res = "";
    string sOdd = "";
    // tạo string:
    FOR(i, 0, 25)
    {
        if (!(cnt[i] & 1))
        {
            FOR(num, 1, cnt[i] / 2)
            str += (i + 'A');
        }
        else
        {
            if (sOdd == "")
            {
                FOR(num, 1, cnt[i])
                sOdd += (i + 'A');
                continue;
            }
            cout << "NO SOLUTION";
            return 0;
        }
    }
    res += str;
    res += sOdd;
    reverse(str.begin(), str.end());
    res += str;
    cout << res;
}