#include <bits/stdc++.h>
using namespace std;
int root[100005];
typedef tuple<int, int, int> tiii;
int n, m;
vector<tiii> listEdges;
long long ans = 0;
int numbEdges = 0;

int findRoot(int u)
{
    return root[u] = (u == root[u] ? u : findRoot(root[u]));
}
void setUnionInkruskal(int u, int v, int cost) // thêm tính chi phí và số cạnh
{
    int rootu = findRoot(u);
    int rootv = findRoot(v);
    if (rootu != rootv)
    {
        root[rootu] = rootv;
        ans += cost;
        numbEdges++;
    }
}

void kruskal()
{
    sort(listEdges.begin(), listEdges.end());
    for (auto [cost, u, v] : listEdges)
        setUnionInkruskal(u, v, cost);
}

void initial()
{
    for (int i = 1; i <= n; i++)
        root[i] = i;
}
int main()
{
    cin >> n >> m;
    initial();
    for (int i = 1; i <= m; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        listEdges.emplace_back(cost, u, v);
    }
    kruskal();
    numbEdges < n - 1 ? (cout << "IMPOSSIBLE") : (cout << ans);
    return 0;
}