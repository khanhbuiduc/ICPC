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
int root[100005];
vector<tuple<int, int, int>> egdes;
int n, m, q, ki, sj;
vector<pair<int, int>> change;

void initial()
{
    egdes.clear();
    scanf("%d %d %d", &n, &m, &q);
    FOR(i, 1, m)
    {
        int ui, vi, wi;
        scanf("%d %d %d", &ui, &vi, &wi);
        egdes.emplace_back(wi, ui, vi);
    }
}

int find_root(int u)
{
    return (root[u] = root[u] == u ? u : find_root(root[u]));
}

void set_union(int u, int v)
{
    int rootu = find_root(u);
    int rootv = find_root(v);
    if (rootu != rootv)
        root[rootu] = rootv;
}

void kruskal()
{
    FOR(i, 1, n)
    root[i] = i;

    vector<tuple<int, int, int>> updateEgdes = egdes;

    for (auto [t, p] : change)
        get<0>(updateEgdes[t]) = p;

    auto [wk, uk, vk] = updateEgdes[ki];

    for (auto [w, u, v] : updateEgdes)
    {
        if (w < wk)
            set_union(u, v);
    }

    int rootu = find_root(uk);
    int rootv = find_root(vk);
    printf("%s\n", (rootu == rootv ? "YES" : "NO"));
}

void solve()
{
    while (q--)
    {
        scanf("%d %d", &ki, &sj);
        ki--;
        change.clear();

        FOR(i, 1, sj)
        {
            int t, c;
            scanf("%d %d", &t, &c);
            change.emplace_back(t - 1, c);
        }

        kruskal();
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        initial();
        solve();
    }
    return 0;
}