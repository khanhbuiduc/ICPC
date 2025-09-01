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
vector<int> adj[100];
// initial tplt
bool deleted[2005];
int numb[2005], low[2005];
int root[2005];
int timeDfs = 0;
stack<int> st;
int ans;
//------
void initial()
{
}
// tplt mạnh
void dfs(int u)
{
    numb[u] = low[u] = timeDfs;
    st.push(u);
    root[u] = u;
    for (auto v : adj[u])
    {
        if (deleted[v] = true)
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
        ans++;
        while (true)
        {
            int v = st.top();
            st.pop();
            deleted[v] == true;
            root[v] = u;
            if (v == u)
                break;
        }
    }
}
void solve()
{
    // kiểm tra đồ thị DAG
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
}