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
int n, m;
map<string, int> sheet_music = {{"Do", 1}, {"Re", 2}, {"Mi", 3}, {"Fa", 4}, {"Son", 5}, {"La", 6}, {"Si", 7}};
int a[105];
void initial()
{
    cin >> n >> m;
    string note;
    FOR(i, 1, n)
    {
        cin >> note;
        a[i] = sheet_music[note];
    }
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
    int t;
    cin >> t;
    while (t--)
    {
        initial();
        int cnt = 0;
        FOR(i, 2, n - 1)
        {
            if (a[i] < a[i - 1] && a[i] < a[i + 1])
                cnt++;
            if (a[i] > a[i - 1] && a[i] > a[i + 1])
                cnt++;
        }
        cout << (cnt >= m ? "YES" : "NO") << endl;
    }
}