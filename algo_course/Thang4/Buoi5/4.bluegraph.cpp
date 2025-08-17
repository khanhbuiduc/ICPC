#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ff first
#define ss second
const int inf = 1'000'000'000;
vector<int> adj[500005];
priority_queue<pii> firstQueue;
queue<int> secondQueue;
vector<pii> queries;
vector<int> ans;
int dist[500005];
bool whiteNode[500005];
int n, m, numQuery;
void coloring()
{
    while (!firstQueue.empty())
    {
        auto [di, u] = firstQueue.top();
        firstQueue.pop();
        if (di <= 1)
            continue;
        else // tô trắng các đỉnh tiếp theo
            for (int v : adj[u])
            {
                if (!whiteNode[v])
                {
                    whiteNode[v] = true;
                    firstQueue.push({di - 1, v});
                }
            }
    }
}
void caculate_Distant()
{
    while (!secondQueue.empty())
    {
        int u = secondQueue.front();
        secondQueue.pop();
        for (int v : adj[u])
            if (dist[v] == inf)
            {
                dist[v] = dist[u] + 1;
                secondQueue.push(v);
            }
    }
}
int main()
{
    cin >> n >> m >> numQuery;
    int u, v;
    for (int i = 0; i <= n; i++)
    {
        dist[i] = inf;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= numQuery; i++)
    {
        int ci, di;
        cin >> ci >> di;
        if (di != 0)
            whiteNode[ci] = true;
        firstQueue.push({di, ci});
        queries.push_back({di, ci});
    }
    // từ query loang ra xung quanh tạo ô trắng.
    coloring();
    // lưu nút xanh
    for (int i = 1; i <= n; i++)
        if (!whiteNode[i])
        {
            ans.push_back(i);
            secondQueue.push(i);
            dist[i] = 0;
        }
    // từ ô xanh loang ra xung quanh lưu khoảng cách gần nhất.
    caculate_Distant();
    // kiểm tra khoảng cách có hợp lệ.
    for (auto [di, ci] : queries)
    {
        if (dist[ci] != di)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (int blue_index : ans)
        cout << blue_index << ' ';
}