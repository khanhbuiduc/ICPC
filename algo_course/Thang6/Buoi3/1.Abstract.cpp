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
int h[1005][1005];
bool check[1005][1005];
void initial()
{
    cin >> n >> m;

    FOR(i, 1, n)
    FOR(j, 1, m)
    cin >> h[i][j];
}
void left_to_right()
{
    FOR(i, 1, n)
    {
        int hight = 0;
        FOR(j, 1, m)
        {
            if (h[i][j] > hight)
            {
                check[i][j] = true;
                hight = h[i][j];
            }
        }
    }
}
void right_to_left()
{
    FOR(i, 1, n)
    {
        int hight = 0;
        FORD(j, m, 1)
        {
            if (h[i][j] > hight)
            {
                check[i][j] = true;
                hight = h[i][j];
            }
        }
    }
}
void up_to_down()
{
    FOR(j, 1, m)
    {
        int hight = 0;
        FOR(i, 1, n)
        {
            if (h[i][j] > hight)
            {
                check[i][j] = true;
                hight = h[i][j];
            }
        }
    }
}
void down_to_up()
{
    FOR(j, 1, m)
    {
        int hight = 0;
        FORD(i, n, 1)
        {
            if (h[i][j] > hight)
            {
                check[i][j] = true;
                hight = h[i][j];
            }
        }
    }
}
void solve()
{
    left_to_right();
    right_to_left();
    down_to_up();
    up_to_down();
    int cnt = 0;
    FOR(i, 1, n)
    FOR(j, 1, m)
    {
        if (check[i][j])
            cnt++;
    }
    cout << cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    initial();
    solve();
}