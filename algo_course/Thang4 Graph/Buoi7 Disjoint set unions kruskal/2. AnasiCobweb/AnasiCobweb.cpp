#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int root[100'005];
bool risk[100'005];
vector<pii> adj;
vector<int> remove_thread;
int cnt_union;
int n, m, q;
vector<int> ans;
void initial()
{
    for (int i = 1; i <= n; i++)
        root[i] = i;
    adj.push_back({0, 0});
}
int findRoot(int u)
{
    return (root[u] = (root[u] == u) ? u : findRoot(root[u])); // đồng thời cập nhập root[u] = chúa đảo
}

void unionSet(int u, int v)
{
    int rootu = findRoot(u);
    int rootv = findRoot(v);
    if (rootu != rootv)
    {
        cnt_union--;
        root[rootu] = rootv;
    }
}

int main()
{
    cin >> n >> m;
    cnt_union = n;
    initial();

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj.emplace_back(u, v);
    }

    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int qi;
        cin >> qi;
        remove_thread.push_back(qi);
        risk[qi] = true;
    }

    for (int i = 1; i <= m; i++)
    {
        if (risk[i] == false)
        {
            int u = adj[i].first, v = adj[i].second;
            unionSet(u, v);
        }
    }

    reverse(remove_thread.begin(), remove_thread.end());
    for (int rm : remove_thread)
    {
        ans.push_back(cnt_union);
        auto [u, v] = adj[rm];
        unionSet(u, v);
    }

    reverse(ans.begin(), ans.end());
    for (int i : ans)
        cout << i << ' ';
    return 0;
}
