#include <bits/stdc++.h>
using namespace std;
#define ALL(v) (v).begin(), (v).end()
typedef pair<int, int> pii;
int state[100005];
int trace[100005];
map<int, vector<int>> adj;
int n, m;
void print(int start, int end)
{
    vector<int> ans;
    ans.push_back(end);
    for (int cur = start; cur != end; cur = trace[cur])
        ans.push_back(cur);
    ans.push_back(end);
    cout << ans.size() << endl;
    reverse(ALL(ans));
    for (auto i : ans)
        cout << i << ' ';
}
void dfs(int u)
{
    state[u] = 1;
    for (int v : adj[u])
    {
        if (state[v] == 0)
        {
            trace[v] = u;
            dfs(v);
        }
        else if (state[v] == 1)
        {
            print(u, v);
            exit(0);
        }
    }
    state[u] = 2;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (state[i] != 0)
            continue;
        dfs(i);
    }
    cout << "IMPOSSIBLE";
    return 0;
}