#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
vector<string> list_s = {"NO", "AA", "BB", "CC", "DDDD", "BABA", "ACAC", "DABCACB"};
string s, t;
queue<string> q;
map<string, int> dist;
map<string, pii> trace;

void print_list(string v)
{
    vector<pii> ans;

    while (v != s)
    {
        auto [i, pos] = trace[v];
        ans.push_back({i, pos});

        if (i > 0)
        {
            v.erase(pos, list_s[i].size());
        }
        else
        {
            v.insert(pos, list_s[-i]);
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto [i, pos] : ans)
    {
        cout << pos + 1 << ' ' << i << endl;
    }
}

void bfs(int len)
{
    q.push(s);
    dist[s] = 0;
    while (!q.empty())
    {
        string u = q.front();
        q.pop();
        if (dist[u] >= len)
            continue;
        // Khi xóa 1 từ
        FOR(i, 1, 7)
        {
            int pos = 0;
            while ((pos = u.find(list_s[i], pos)) != string::npos)
            {
                string v = u;
                v.erase(pos, list_s[i].size());
                if (v == t)
                {
                    trace[v] = {-i, pos};
                    print_list(v);
                    return;
                }
                if (dist.find(v) == dist.end())
                {
                    trace[v] = {-i, pos};
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
                pos++;
            }
        }
        // Khi thêm 1 từ vào u
        FOR(pos, 0, u.size())
        {
            FOR(i, 1, 7)
            {
                string v = u;
                v.insert(pos, list_s[i]);
                if (v == t)
                {
                    trace[v] = {i, pos};
                    print_list(v);
                    return;
                }
                if (dist.find(v) == dist.end())
                {
                    trace[v] = {i, pos};
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    cout << "impossible";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> s >> t;
    bfs(5);
    return 0;
}