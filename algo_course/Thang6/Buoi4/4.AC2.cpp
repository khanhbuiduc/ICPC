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
typedef long long ll;
const int mod = 998244353;
int n, d; // n bạn, d khoảng cách
bool sing[40], dance[40];
// f[i][dRemain][friendRemain][dSing][friendSing][dDance][friendDance]
int f[40][40][3][40][3][40][3];

void update(int &a, int b)
{
    (a += b) %= mod;
}

void initial()
{
    // Reset arrays for each test case
    memset(sing, false, sizeof(sing));
    memset(dance, false, sizeof(dance));
    memset(f, 0, sizeof(f));

    cin >> n >> d;
    int cntSing, cntDance;
    cin >> cntSing;
    int id;
    FOR(i, 1, cntSing)
    {
        cin >> id;
        sing[id] = true;
    }
    cin >> cntDance;
    FOR(i, 1, cntDance)
    {
        cin >> id;
        dance[id] = true;
    }
    //-----
    f[0][0][0][0][0][0][0] = 1;
}
int cal_d(int dis)
{
    return min(dis + 1, d + 1);
}
void solve()
{
    FOR(i, 0, n - 1)
    FOR(dRemain, 0, d + 1)
    FOR(friendRemain, 0, 2)
    FOR(dSing, 0, d + 1)
    FOR(friendSing, 0, 2)
    FOR(dDance, 0, d + 1)
    FOR(friendDance, 0, 2)
    {
        if (f[i][dRemain][friendRemain][dSing][friendSing][dDance][friendDance] == 0)
            continue;
        int curValue = f[i][dRemain][friendRemain][dSing][friendSing][dDance][friendDance];

        // add student i+1 to remain
        if (friendRemain == 0)
            update(f[i + 1][0][1][cal_d(dSing)][friendSing][cal_d(dDance)][friendDance], curValue);

        if (friendRemain == 1 && dRemain < d)
            update(f[i + 1][0][2][cal_d(dSing)][friendSing][cal_d(dDance)][friendDance], curValue);

        if (friendRemain == 2)
        {
            if (dRemain < d)
                update(f[i + 1][0][2][cal_d(dSing)][friendSing][cal_d(dDance)][friendDance], curValue);
            else
                update(f[i + 1][0][1][cal_d(dSing)][friendSing][cal_d(dDance)][friendDance], curValue);
        }

        // add student i+1 to sing
        if (sing[i + 1])
        {
            if (friendSing == 0)
                update(f[i + 1][cal_d(dRemain)][friendRemain][0][1][cal_d(dDance)][friendDance], curValue);
            if (friendSing == 1 && dSing < d)
                update(f[i + 1][cal_d(dRemain)][friendRemain][0][2][cal_d(dDance)][friendDance], curValue);

            if (friendSing == 2)
            {
                if (dSing < d)
                    update(f[i + 1][cal_d(dRemain)][friendRemain][0][2][cal_d(dDance)][friendDance], curValue);
                else
                    update(f[i + 1][cal_d(dRemain)][friendRemain][0][1][cal_d(dDance)][friendDance], curValue);
            }
        }

        // add student i+1 to dance
        if (dance[i + 1])
        {
            if (friendDance == 0)
                update(f[i + 1][cal_d(dRemain)][friendRemain][cal_d(dSing)][friendSing][0][1], curValue);
            if (friendDance == 1 && dDance < d)
                update(f[i + 1][cal_d(dRemain)][friendRemain][cal_d(dSing)][friendSing][0][2], curValue);
            if (friendDance == 2)
            {
                if (dDance < d)
                    update(f[i + 1][cal_d(dRemain)][friendRemain][cal_d(dSing)][friendSing][0][2], curValue);
                else
                    update(f[i + 1][cal_d(dRemain)][friendRemain][cal_d(dSing)][friendSing][0][1], curValue);
            }
        }
    }
    // result
    int result = 0;
    FOR(dRemain, 0, d + 1)
    FOR(dSing, 0, d + 1)
    FOR(dDance, 0, d + 1)
    {
        update(result, f[n][dRemain][0][dSing][2][dDance][2]);
        update(result, f[n][dRemain][2][dSing][2][dDance][2]);
    }
    cout << result << endl;
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