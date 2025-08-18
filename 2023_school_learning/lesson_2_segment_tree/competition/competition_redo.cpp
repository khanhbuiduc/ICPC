#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ff first
#define ss second

int n, m, k;
vector<pii> a, b;

void buildTreeWithInput(vector<pii> &tree)
{
    // initial
    k = 1;
    while (k < n)
        k <<= 1;
    tree.assign(2 * k, {0, 0});
    // nhập dữ liệu vào lá
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        tree[i + k] = {t, i + k};
    }
    // build nút cha
    for (int i = k - 1; i > 0; --i)
    {
        if (tree[2 * i].ff > tree[2 * i + 1].ff)
            tree[i] = tree[2 * i];
        else
            tree[i] = tree[2 * i + 1];
    }
}

pii getMax(vector<pii> &tree, int u, int v)
{
    pii x, y;
    u += k - 1, v += k - 1;
    x = tree[u], y = tree[v];
    while (v - u > 1)
    {
        if (u % 2 == 0)
            x = max(x, tree[u + 1]);
        if (v % 2 == 1)
            y = max(tree[v - 1], y);
        u >>= 1;
        v >>= 1;
    }
    return max(x, y);
}

int getSecondMaxSum(vector<pii> &tree, int p, int q)
{
    // tìm max 1, max 2
    pii t1, t2, t3, t4;
    t1 = getMax(tree, p, q); // max1
    //////////{p,q}
    if (t1.ss == p + k - 1) // max 1 ở p
        t2 = getMax(tree, p + 1, q);
    else if (t1.ss == q + k - 1) // max 1
        t2 = getMax(tree, p, q - 1);
    else
    {
        t3 = getMax(tree, p, t1.ss);
        t4 = getMax(tree, t1.ss + 2, q);
        t2 = max(t3, t4);
    }
    //////////
    return t1.ff + t2.ff;
}

pair<int, int> solveQueries()
{
    int r1 = 0, r2 = 0;
    int p, q;

    for (int i = 0; i < m; i++)
    {
        cin >> p >> q;
        int ra = getSecondMaxSum(a, p, q);
        int rb = getSecondMaxSum(b, p, q);

        if (ra > rb)
            r1++;
        else if (ra < rb)
            r2++;
    }
    return {r1, r2};
}

int main()
{
    freopen("competition.inp", "r", stdin);
    freopen("competition.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    // Xây dựng cây
    buildTreeWithInput(a);
    buildTreeWithInput(b);

    auto res = solveQueries();
    cout << res.ff << ' ' << res.ss;
}
