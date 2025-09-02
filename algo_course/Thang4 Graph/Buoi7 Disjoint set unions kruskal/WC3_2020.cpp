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
// template
int root[10'005];
typedef tuple<int, int, int> tiii;
typedef long long ll;
bool haveData[10'005];
int n, e, m, k;
vector<tiii> listEdges;

ll wireCost = 0;

int findRoot(int u)
{
    return root[u] = (u == root[u] ? u : findRoot(root[u]));
}
void setUnionInkruskal(int u, int v, int cost)
{
    int rootu = findRoot(u);
    int rootv = findRoot(v);
    if (rootu != rootv)
    {
        if (haveData[rootu] && haveData[rootv])
            return;
        root[rootu] = rootv;
        wireCost += cost;
        haveData[rootv] = haveData[rootu] || haveData[rootv];
    }
}

void kruskal()
{
    sort(ALL(listEdges));
    for (auto &[cost, u, v] : listEdges)
        setUnionInkruskal(u, v, cost);
}

void initial()
{
    cin >> n >> e >> m >> k;
    FOR(i, 1, n)
    {
        root[i] = i;
        haveData[i] = false;
    }
    listEdges.clear();
    wireCost = 0;
    int ki, u, v, w;
    FOR(i, 1, k)
    {
        cin >> ki;
        haveData[ki] = true;
    }
    FOR(i, 1, e)
    {
        cin >> u >> v >> w;
        listEdges.emplace_back(w, u, v);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        initial();
        kruskal();
        ll total = 1ll * (n - k) * m + wireCost;
        cout << total << '\n';
    }
    return 0;
}
/*
t = 4
n=4 e=6 m=7 k=1
ki
1
u,v,w
1 2 7
1 3 7
1 4 1
2 3 9
2 4 5
3 4 13

total = (n-k)*m + min(cost)
*/