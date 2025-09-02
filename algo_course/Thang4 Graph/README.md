# Graph

## bài 1: DFS

### 1. DFS

```cpp
void dfs(u)
{
    visited[u] = true;
    for (auto v: adj[u])
    {
        if(visited[v])
            dfs(v);
    }
}
```

### 2. DAG: đồ thị có hướng và không tồn tại 1 chu trình đơn

```cpp
int trace[100'005],state[100'005];
bool haveCircle = false;
void dfs_dag(int u)
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
            haveCircle = true;
            exit(0);
        }
    }
    state[u] = 2;
}
```

```cpp
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
```

### EULER: tất cả đỉnh trong đồ thị là bậc chẵn thì tồn tại đường đi euler

```cpp
set<int> adj[100005];
void dfs_euler(int u)
{
  for(auto v:adj[u])
  {
    adj[v].erase(u);
    adj[u].erase(v);
    dfs(v);
  }
  ans.push_back(u);
}
```

## Buổi 2: Topo

```cpp
vector<int> store;//store bị ngược
void dfsTopo(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (visited[v] == false)
            dfsTopo(v);
    }
    store.push(u);
}
```

## Buổi 3: joint and bridges

### tìm cầu

```cpp
void dfs_bridges(int u, int father)
{
    num[u] = low[u] = ++timeDFS;
    for (int v : adj[u])
    {
        if (v == father)
            continue;
        else if (num[v] > 0)
            low[u] = min(low[u], num[v]);
        else
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (num[v] == low[v])
                bridges.emplace_back(u, v);
        }
    }
}
```

### tìm khớp

```cpp
set<int> joints;
void dfs(int u, int father)
{
    num[u] = low[u] = ++timeDFS;
    int children = 0;
    for (int v : adj[u])
    {
        if (v == father)
            continue;
        else if (num[v] > 0)
            low[u] = min(low[u], num[v]);
        else
        {
            dfs(v, u);
            children++;
            low[u] = min(low[u], low[v]);
            if (u == 1 && children >= 2)
                joints.insert(u);
            if (u != 1 && low[v] >= num[u])
                joints.insert(u);
        }
    }
}
```

## Buổi 4: SCC strongly connected component

thành phần liên thông mạnh

```cpp
void dfs(int u)
{
    low[u] = num[u] = ++cntDfs;
    store.push(u);
    for (int v : adj[u])
    {
        if (is_deleted[v])
            continue;
        if (num[v] > 0)
            low[u] = min(low[u], num[v]);
        else
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == num[u])
    {
        ans++;
        while (true)
        {
            int v = store.top();
            store.pop();
            is_deleted[v] = true;
            root[v] = u;//nếu cần lưu trữ root;
            if (v == u)
                break;
        }
    }
}
```

## Buổi 5: BFS

tìm đường đi ngắn nhất đến mọi đỉnh

```cpp
queue<int> q;
int dist[1'000'005];
void bfs()
{
    for (int i = 0; i <= m; i++)
        dist[i] = -1;
    dist[s0] = 0;
    q.push(s0);
    while (!q.empty())
    {
        int u = q.front(),q.pop();
        for (int v:adj[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                if (v == 0)
                {
                    cout << dist[v];
                    exit(0);
                }
                q.push(v);
            }
        }
    }
}
```

## buổi 6: dijkstra

```cpp
priority_queue<pii, vector<pii>, greater<pii>> pq;
dijkstra()
{
    pq.emplace(0, start);
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;
        for (auto [v, w] : adj[u])
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
    }
}
```

## Buoi7 Disjoint set unions kruskal

```cpp
int findRoot(u) {
    return (root[u] = (root[u] == u) ? u : findRoot(root[u]));
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
```
