#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
vector<pii> adj[1005];
bool visited[1005];
vector<int> cur_path;
ll cost = 0;
vector<pair<int, vector<int>>> paths;
int n, m;
void printPath(int c, vector<int> p)
{
    cout << "cost:" << c << endl;
    for (auto i : p)
    {
        cout << char(i + 'A') << ' ';
    }
    cout << endl;
}
void printALLPath()
{
    for (auto [c, p] : paths)
    {
        printPath(c, p);
    }
}

void dfs(int u)
{
    if (u == (n - 1))
    {
        paths.emplace_back(cost, cur_path);
        return;
    }
    for (auto [v, w] : adj[u])
    {
        if (!visited[v])
        {
            visited[v] = true;
            cur_path.push_back(v);
            cost += w;
            dfs(v);
            visited[v] = false;
            cost -= w;
            cur_path.pop_back();
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    FOR(i, 1, m)
    {
        char u, v;
        int w;
        cin >> u >> v >> w;
        adj[u - 'A'].emplace_back(v - 'A', w);
        adj[v - 'A'].emplace_back(u - 'A', w);
    }
    // in ra tất cả các đường đi và chi phí.
    cur_path.push_back(0);
    visited[0] = true;
    dfs(0);
    printALLPath();
    cout << "----min_path----" << endl;
    sort(ALL(paths));
    printPath(paths[0].ff, paths[0].ss);
    cout << "----remove ----" << endl;
    char u, v;
    cin >> u >> v;
    u -= 'A', v -= 'A';
    bool found = false;
    for (auto [c, path] : paths)
    {
        bool hasEdge = false;
        for (int i = 0; i < path.size() - 1; i++)
        {
            if ((path[i] == u && path[i + 1] == v) ||
                (path[i] == v && path[i + 1] == u))
            {
                hasEdge = true;
                break;
            }
        }
        if (!hasEdge)
        {
            printPath(c, path);
            found = true;
            break;
        }
    }
}
/*
---input---
7 10
A B 4
A C 3
B D 5
B E 2
C D 7
C F 4
D E 6
D F 3
E G 5
F G 2
CF
----ouput---
cost:22
A B D C F G
cost:20
A B D E G
cost:14
A B D F G
cost:25
A B E D C F G
cost:17
A B E D F G
cost:11
A B E G
cost:22
A C D B E G
cost:21
A C D E G
cost:15
A C D F G
cost:22
A C F D B E G
cost:21
A C F D E G
cost:9
A C F G
----min_path----
cost:9
A C F G
----remove ----
cost:11
A B E G

*/