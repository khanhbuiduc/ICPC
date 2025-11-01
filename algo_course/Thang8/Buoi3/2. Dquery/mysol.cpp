#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()

typedef long long ll;
typedef tuple<int, int, int> tiii;

int n, q;
int a[30'005];
int cnt[1'000'005];
int res[200'005];
vector<tiii> query;
int block;

bool compare(tiii a, tiii b)
{
    auto [La, Ra, ida] = a;
    auto [Lb, Rb, idb] = b;
    if (La / block != Lb / block)
    {
        return La < Lb;
    }
    return Ra < Rb;
}

void initial()
{
    cin >> n;
    block = sqrt(n) + 1;
    FOR(i, 1, n) { cin >> a[i]; }
    cin >> q;
    FOR(i, 1, q)
    {
        int L, R;
        cin >> L >> R;
        query.emplace_back(L, R, i);
    }
    sort(ALL(query), compare);
}

void solve()
{
    int ans = 0;
    auto [curL, curR, id] = query[0];
    FOR(i, curL, curR)
    {
        cnt[a[i]]++;
        if (cnt[a[i]] == 1)
            ans++;
    }
    res[id] = ans;

    FOR(i, 1, q - 1)
    {
        int preL = curL, preR = curR;
        tie(curL, curR, id) = query[i];

        if (curL < preL)
            FOR(j, curL, preL - 1)
            {
                cnt[a[j]]++;
                if (cnt[a[j]] == 1)
                    ans++;
            }
        if (preL < curL)
            FOR(j, preL, curL - 1)
            {
                cnt[a[j]]--;
                if (cnt[a[j]] == 0)
                    ans--;
            }
        if (preR < curR)
            FOR(j, preR + 1, curR)
            {
                cnt[a[j]]++;
                if (cnt[a[j]] == 1)
                    ans++;
            }
        if (curR < preR)
            FOR(j, curR + 1, preR)
            {
                cnt[a[j]]--;
                if (cnt[a[j]] == 0)
                    ans--;
            }
        res[id] = ans;
    }

    FOR(i, 1, q)
    {
        cout << res[i] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    initial();
    solve();
    return 0;
}