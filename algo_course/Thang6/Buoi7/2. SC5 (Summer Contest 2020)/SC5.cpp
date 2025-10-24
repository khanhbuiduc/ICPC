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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
vector<pair<int, int>> adj[100'005]; // 0 là trọng số A, 1 là trọng số b;
bool visited[100'005];
ll dist[100'005];
const ll inf = 100'000'000'007;
int n, a, b;
void dijistra()
{
    FOR(i, 0, 100'000)
    dist[i] = inf;
    dist[1] = a;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.emplace(a, 1);
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (u == n)
            break;
        if (d > dist[u])
            continue;
        for (auto [v, t] : adj[u])
        {
            if (v > n)
                continue;
            int w = t ? b : a;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
}
void init()
{
    FOR(i, 0, 100'000)
    adj[i].emplace_back(i + 1, 0);
    FOR(i, 1, 50'000)
    adj[i].emplace_back(2 * i, 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    init();
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b;
        dijistra();
        cout << dist[n] << endl;
    }
}