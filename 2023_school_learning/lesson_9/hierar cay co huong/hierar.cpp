#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main()
{
    freopen("hierar.inp", "r", stdin);
    freopen("hierar.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //========================================
    int p, e, n, q;
    cin >> n;
    set<pii> s;
    set<int> unique_targets;
    for (int i = 1; i < n; i++)
    {
        cin >> p >> e;
        s.insert({p, e});
        unique_targets.insert(e);
    }

    cout << (unique_targets.size() == n - 1 ? "true\n" : "false\n");
    cin >> q;
    while (q > 0)
    {

        int u, v;
        cin >> u >> v;
        if (s.find({u, v}) != s.end())
        {
            s.erase({u, v});
            s.insert({v, u});
        }
        else if (s.find({v, u}) != s.end())
        {
            s.erase({v, u});
            s.insert({u, v});
        }
        else
        {
            s.insert({u, v});
        }
        // update unique_targets
        unique_targets.clear();
        for (auto i : s)
            unique_targets.insert(i.second);
        cout << (unique_targets.size() == n - 1 ? "true\n" : "false\n");
        q--;
    }
}