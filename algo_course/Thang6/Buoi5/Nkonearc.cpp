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
int n, m, timeDfs = 0, num_root = 0;
vector<int> adj[2005], topo;
// initial tplt
bool deleted[2005], visited[2005];
int numb[2005], low[2005], root[2005];
set<int> in, out;
stack<int> st;
//------
void initial()
{
    cin >> n >> m;
    int u, v;
    FOR(i, 1, m)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
}
// tplt mạnh
void dfs(int u)
{
    numb[u] = low[u] = ++timeDfs;
    st.push(u);
    for (auto v : adj[u])
    {
        if (deleted[v])
            continue;
        if (numb[v] > 0)
            minimize(low[u], numb[v]);
        else
        {
            dfs(v);
            minimize(low[u], low[v]);
        }
    }
    if (low[u] == numb[u])
    {
        num_root++;
        while (true)
        {
            int v = st.top();
            st.pop();
            deleted[v] = true;
            root[v] = num_root;
            if (v == u)
                break;
        }
    }
}
void solve()
{
    FOR(i, 1, n)
    {
        if (numb[i] == 0)
            dfs(i);
    }
    // đang có num_root đỉnh. kiểm tra có 1 đỉnh bắt đầu. 1 đỉnh kết thúc
    if (num_root == 1)
    {
        cout << "NO";
        exit(0);
    }
    FOR(u, 1, n)
    for (int v : adj[u])
    {
        int rootu = root[u];
        int rootv = root[v];
        if (rootu != rootv)
        {
            in.insert(rootv);
            out.insert(rootu);
        }
    }
    // có đúng 1 đỉnh vào và 1 đỉnh ra => in:root-1 đỉnh, out: root-1 đỉnh
    if ((int)in.size() != num_root - 1 || (int)out.size() != num_root - 1)
    {
        cout << "NO";
        exit(0);
    }
    int ans_in = 0, ans_out = 0;
    FOR(i, 1, num_root)
    {
        ans_in ^= i, ans_out ^= i;
    }
    for (auto i : in)
        ans_in ^= i;
    for (auto i : out)
        ans_out ^= i;
    FOR(u, 1, n)
    {
        if (root[u] != ans_in)
            continue;
        ans_in = u;
        break;
    }
    FOR(u, 1, n)
    {
        if (root[u] != ans_out)
            continue;
        ans_out = u;
        break;
    }
    cout << "YES\n"
         << ans_out << ' ' << ans_in;
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