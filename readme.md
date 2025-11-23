# Competitive Programming Quality Criteria

Our code must follow this guideline: **"Correct - Fast - Easy to code - Easy to debug - Extensible - Elegant"**

## 1. Correctness ⚠️

- Must handle all test cases correctly
- Zero runtime/overflow errors
- Note: Fast but incorrect solutions are worthless

## 2. Speed ⚡

- Algorithm complexity must match constraints:
  - O(N log N) or better when N ≤ 10^5
  - O(N^2) acceptable when N ≤ 10^3
- Avoid TLE (Time Limit Exceeded)

## 3. Implementation Speed 🔧

- Write quickly with minimal bugs
- Efficient time management
- Prefer simple solutions over complex ones

## 4. Reusability 🔄

- Code should work for similar problems
- Use clear structure and functions
- Good for learning (optional in contests)

## 5. Easy Debugging 🔍

- Clear variable names
- Strategic debug statements
- Document magic numbers
- Essential for edge cases

## 6. Code Elegance ✨

- Concise, problem-specific solutions
- Improves coding skills
- Makes solutions impressive

"C++ Initial Template": {
		"prefix": "initial",
		"body": [
			"#include <bits/stdc++.h>",
			"using namespace std;",
			"#define ff first",
			"#define ss second",
			"#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)",
			"#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)",
			"#define ALL(v) (v).begin(), (v).end()",
			"typedef long long ll;",
			"typedef pair<int, int> pii;",
			"int main()",
			"{",
			"    ios_base::sync_with_stdio(false);",
			"    cin.tie(nullptr);",
			"    // freopen(\"input.txt\", \"r\", stdin);",
			"    // freopen(\"output.txt\", \"w\", stdout);",
			"    $0",
			"}"
		],
		"description": "C++ competitive programming initial template"
	},
	"Binary Search on Answer": {
		"prefix": "bsoa",
		"body": [
			"void binary_search_on_answer()",
			"{",
			"    int li = 0, hi = lim;",
			"    int ans = 0;",
			"    while (li <= hi)",
			"    {",
			"        int mid = (li + hi) / 2;",
			"        if (check(mid))",
			"        {",
			"            ans = mid;",
			"            li = mid + 1;",
			"        }",
			"        else",
			"            hi = mid - 1;",
			"    }",
			"    cout << ans << \"\\n\";",
			"}"
		],
		"description": "Binary search on answer template"
	},
	"Binary Search": {
		"prefix": "bs",
		"body": [
			"int binary_search(vector<int> a, int x)",
			"{",
			"    int lo = 0, hi = a.size() - 1;",
			"    while (lo <= hi)",
			"    {",
			"        int mid = (lo + hi) / 2;",
			"        if (a[mid] == x)",
			"            return mid;",
			"        if (a[mid] < x)",
			"            lo = mid + 1;",
			"        else",
			"            hi = mid - 1;",
			"    }",
			"    return -1;",
			"}"
		],
		"description": "Binary search template"
	},
	"Ternary Search": {
		"prefix": "ts",
		"body": [
			"void ternary_search()",
			"{",
			"    double lo = -10'005, hi = 10'005;",
			"    int step = 500;",
			"    while (step--)",
			"    {",
			"        double u = (2 * lo + hi) / 3;",
			"        double v = (2 * hi + lo) / 3;",
			"        if (f(u) >= f(v))",
			"            lo = u;",
			"        else",
			"            hi = v;",
			"    }",
			"    cout << fixed << setprecision(15) << f(lo);",
			"}"
		],
		"description": "Ternary search template"
	},
	"Depth First Search": {
		"prefix": "dfs",
		"body": [
			"void dfs(int u)",
			"{",
			"    visited[u] = true;",
			"    for (auto v : adj[u])",
			"    {",
			"        if (!visited[v])",
			"            dfs(v);",
			"    }",
			"}"
		],
		"description": "Depth First Search template"
	},
	"DFS DAG Circle Detection": {
		"prefix": "DAG",
		"body": [
			"int trace[100005], state[100005];",
			"bool haveCircle = false;",
			"void DAG(int u)",
			"{",
			"    state[u] = 1;",
			"    for (int v : adj[u])",
			"    {",
			"        if (state[v] == 0)",
			"        {",
			"            trace[v] = u;",
			"            DAG(v);",
			"        }",
			"        else if (state[v] == 1)",
			"        {",
			"            print_circle(u, v);",
			"            haveCircle = true;",
			"            exit(0);",
			"        }",
			"    }",
			"    state[u] = 2;",
			"}"
		],
		"description": "DFS for DAG circle detection template"
	},
	"Print Circle": {
		"prefix": "print_circle",
		"body": [
			"void print_circle(int u, int v)",
			"{",
			"    vector<int> ans;",
			"    ans.push_back(v);",
			"    int cur = u;",
			"    while (cur != v)",
			"    {",
			"        ans.push_back(cur);",
			"        cur = trace[cur];",
			"    }",
			"    ans.push_back(v);",
			"    cout << ans.size() << endl;",
			"    reverse(ALL(ans));",
			"    for (auto i : ans)",
			"        cout << i << ' ';",
			"}"
		],
		"description": "Print circle in DAG detection"
	},
	"DFS Topological Sort": {
		"prefix": "topo",
		"body": [
			"vector<int> topo; // topo bị ngược",
			"void dfsTopo(int u)",
			"{",
			"    visited[u] = true;",
			"    for (int v : adj[u])",
			"    {",
			"        if (visited[v] == false)",
			"            dfsTopo(v);",
			"    }",
			"    topo.push_back(u);",
			"}"
		],
		"description": "DFS Topological Sort template"
	},
	"DFS Bridge Finding": {
		"prefix": "dfs_bridge",
		"body": [
			"vector<pii> bridges;",
			"void dfs_bridge(int u, int father)",
			"{",
			"    num[u] = low[u] = ++timeDFS;",
			"    for (int v : adj[u])",
			"    {",
			"        if (v == father)",
			"            continue;",
			"        else if (num[v] > 0)",
			"            low[u] = min(low[u], num[v]);",
			"        else",
			"        {",
			"            dfs_bridge(v, u);",
			"            low[u] = min(low[u], low[v]);",
			"            if (low[v] > num[u])",
			"                bridges.emplace_back(u, v);",
			"        }",
			"    }",
			"}"
		],
		"description": "DFS Bridge Finding template"
	},
	"DFS Joint Finding": {
		"prefix": "dfs_joint",
		"body": [
			"set<int> joints;",
			"void dfs_joint(int u, int father)",
			"{",
			"    num[u] = low[u] = ++timeDFS;",
			"    int children = 0;",
			"    for (int v : adj[u])",
			"    {",
			"        if (v == father)",
			"            continue;",
			"        else if (num[v] > 0)",
			"            low[u] = min(low[u], num[v]);",
			"        else",
			"        {",
			"            dfs_joint(v, u);",
			"            children++;",
			"            low[u] = min(low[u], low[v]);",
			"            if (u == 1 && children >= 2)",
			"                joints.insert(u);",
			"            if (u != 1 && low[v] >= num[u])",
			"                joints.insert(u);",
			"        }",
			"    }",
			"}"
		],
		"description": "DFS Joint (Articulation Point) Finding template"
	},
	"SCC Tarjan": {
		"prefix": "scc",
		"body": [
			"stack<int> store_scc;",
			"void dfs_scc(int u)",
			"{",
			"    low[u] = num[u] = ++cntDfs;",
			"    store_scc.push(u);",
			"    for (int v : adj[u])",
			"    {",
			"        if (is_deleted[v])",
			"            continue;",
			"        if (num[v] > 0)",
			"            low[u] = min(low[u], num[v]);",
			"        else",
			"        {",
			"            dfs_scc(v);",
			"            low[u] = min(low[u], low[v]);",
			"        }",
			"    }",
			"    if (low[u] == num[u])",
			"    {",
			"        while (true)",
			"        {",
			"            int v = store_scc.top();",
			"            store_scc.pop();",
			"            is_deleted[v] = true;",
			"            root[v] = u; // nếu cần lưu trữ root",
			"            if (v == u)",
			"                break;",
			"        }",
			"    }",
			"}"
		],
		"description": "SCC (Strongly Connected Component) Tarjan algorithm"
	},
	"BFS Shortest Path": {
		"prefix": "bfs",
		"body": [
			"queue<int> q;",
			"int dist[1000005];",
			"void bfs(int s0)",
			"{",
			"    FOR(i, 0, n) { dist[i] = -1; }",
			"    dist[s0] = 0;",
			"    q.push(s0);",
			"    while (!q.empty())",
			"    {",
			"        int u = q.front(); q.pop();",
			"        for (int v : adj[u])",
			"        {",
			"            if (dist[v] == -1)",
			"            {",
			"                dist[v] = dist[u] + 1;",
			"                if (v == 0) // tìm min path từ s0 đến đỉnh 0",
			"                {",
			"                    cout << dist[v];",
			"                    exit(0);",
			"                }",
			"                q.push(v);",
			"            }",
			"        }",
			"    }",
			"}"
		],
		"description": "BFS Shortest Path template"
	},
	"Dijkstra Algorithm": {
		"prefix": "dijkstra",
		"body": [
			"priority_queue<pii, vector<pii>, greater<pii>> pq;",
			"void dijkstra(int start)",
			"{",
			"    FOR(i, 0, n) { dist[i] = INF; }",
			"    dist[start] = 0;",
			"    pq.emplace(0, start);",
			"    while (!pq.empty())",
			"    {",
			"        auto [d, u] = pq.top();",
			"        pq.pop();",
			"        if (d > dist[u])",
			"            continue;",
			"        for (auto [v, w] : adj[u])",
			"            if (dist[v] > dist[u] + w)",
			"            {",
			"                dist[v] = dist[u] + w;",
			"                pq.emplace(dist[v], v);",
			"            }",
			"    }",
			"}"
		],
		"description": "Dijkstra shortest path algorithm"
	},
	"Disjoint Set Union": {
		"prefix": "dsu",
		"body": [
			"int findRoot(int u) {",
			"    return (root[u] = (root[u] == u) ? u : findRoot(root[u]));",
			"}",
			"void setUnion(int u, int v)",
			"{",
			"    int rootu = findRoot(u);",
			"    int rootv = findRoot(v);",
			"    if (rootu != rootv)",
			"    {",
			"        cnt_union--;",
			"        root[rootu] = rootv;",
			"    }",
			"}"
		],
		"description": "Disjoint Set Union (DSU) template"
	},
	"Power Modulo": {
		"prefix": "powmod",
		"body": [
			"ll powMod(ll a, ll b) {",
			"    long long res = 1;",
			"    while (b > 0) {",
			"        if (b & 1)",
			"            (res *= a) %= MOD;",
			"        (a *= a) %= MOD;",
			"        b >>= 1;",
			"    }",
			"    return res;",
			"}"
		],
		"description": "Fast Power Modulo template"
	},
	"Combination Modulo": {
		"prefix": "comb_mod",
		"body": [
			"ll fact[MAXN], inv_fact[MAXN];",
			"void pre_calculator() {",
			"    fact[0] = 1;",
			"    FOR(i, 1, MAXN - 1) {",
			"        fact[i] = (fact[i - 1] * i) % MOD;",
			"    }",
			"",
			"    inv_fact[MAXN - 1] = powMod(fact[MAXN - 1], MOD - 2);",
			"    FORD(i, MAXN - 2, 0) {",
			"        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;",
			"    }",
			"}",
			"",
			"ll C(ll n, ll k) {",
			"    if (k > n || k < 0) return 0;",
			"    return (((fact[n] * inv_fact[k]) % MOD) * inv_fact[n - k]) % MOD;",
			"}"
		],
		"description": "Combination C(n,k) with modular inverse template"
	},
	"Sieve of Eratosthenes": {
		"prefix": "sieve",
		"body": [
			"void sieve(int n)",
			"{",
			"    vector<bool> is_prime(n + 1, true);",
			"    is_prime[0] = is_prime[1] = false;",
			"    for (int p = 2; p * p <= n; ++p)",
			"        if (is_prime[p])",
			"            for (int j = p * p; j <= n; j += p)",
			"                is_prime[j] = false;",
			"",
			"    for (int i = 2; i <= n; ++i)",
			"        if (is_prime[i])",
			"            primes.push_back(i);",
			"    return;",
			"}"
		],
		"description": "Sieve of Eratosthenes for finding prime numbers"
	},
	"Segment Tree": {
		"prefix": "segtree",
		"body": [
			"void build(int index, int L, int R)",
			"{",
			"    if (L == R)",
			"    {",
			"        it[index] = a[L];",
			"        return;",
			"    }",
			"    int mid = (L + R) / 2;",
			"    build(2 * index, L, mid);",
			"    build(2 * index + 1, mid + 1, R);",
			"    it[index] = min(it[2 * index], it[2 * index + 1]);",
			"}",
			"",
			"int get(int index, int L, int R, int l, int r)",
			"{",
			"    if (l > R || L > r)",
			"    {",
			"        return inf;",
			"    }",
			"    if (l <= L && R <= r)",
			"    {",
			"        return it[index];",
			"    }",
			"    int mid = (L + R) / 2;",
			"    int vLeft = get(2 * index, L, mid, l, r);",
			"    int vRight = get(2 * index + 1, mid + 1, R, l, r);",
			"    return min(vLeft, vRight);",
			"}"
		],
		"description": "Segment Tree template for range minimum query"
	},
	"Fenwick Tree": {
		"prefix": "fenwick",
		"body": [
			"int fw[60005];",
			"void update(int index, int vals)",
			"{",
			"    for (; index <= 60000; index += index & -index)",
			"        fw[index] += vals;",
			"}",
			"ll get(int index)//sum[a[1..index]]",
			"{",
			"    ll res = 0;",
			"    for (; index > 0; index -= index & -index)",
			"        res += fw[index];",
			"    return res;",
			"}"
		],
		"description": "Fenwick Tree (Binary Indexed Tree) template"
	},
	"Trie Data Structure": {
		"prefix": "trie",
		"body": [
			"struct Node",
			"{",
			"    Node *child[4];",
			"    bool isEnd;",
			"    Node()",
			"    {",
			"        FOR(i, 0, 3) { child[i] = nullptr; }",
			"        isEnd = false;",
			"    }",
			"};",
			"void addString(string &s, Node *&root)",
			"{",
			"    Node *p = root;",
			"    for (auto c : s)",
			"    {",
			"        if (p->child[id[c]] == NULL)",
			"        {",
			"            p->child[id[c]] = new Node();",
			"        }",
			"        p = p->child[id[c]];",
			"    }",
			"    p->isEnd = true;",
			"}",
			"",
			"bool check(const string &s, Node *root)",
			"{",
			"    Node *p = root;",
			"    for (auto c : s)",
			"    {",
			"        if (p->child[id[c]] == NULL)",
			"            return false;",
			"        p = p->child[id[c]];",
			"    }",
			"    return p->isEnd;",
			"}"
		],
		"description": "Trie data structure for string storage and search"
	},
	"Print Vector Simple": {
		"prefix": "print_vector",
		"body": [
			"void print_vector(vector<int> v)",
			"{",
			"    for (auto x : v)",
			"        cout << x << \" \";",
			"    cout << \"\\n\";",
			"}"
		],
		"description": "Simple print vector elements"
	},