#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
unordered_set<int> adj[30];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    string keyboard, s;
    cin >> n >> keyboard >> s;
    // tạo đường đi.
    FOR(i, 1, n - 1)
    {
        int u = keyboard[i - 1] - 'a';
        int v = keyboard[i] - 'a';
        adj[u].insert(v);
    }
    {
        int u = keyboard[n - 1] - 'a';
        int v = keyboard[0] - 'a';
        adj[u].insert(v);
    }
    FOR(i, 0, n - 2)
    {
        int u = s[i] - 'a';
        int v = s[i + 1] - 'a';
        if (adj[u].find(v) == adj[u].end())
        {
            cout << "NO";
            return 0;
        }
        u = v;
    }
    cout << "YES";
    return 0;
}
