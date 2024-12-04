#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("hippocame.inp", "r", stdin);
    freopen("hippocame.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 1; i < n - 1; i++)
        cin >> p[i];
    vector<int> go(n);
    for (int i = 0; i < n; i++)
        if (p[i] == 0)
            go[i] = 1;
        else
            go[i] = go[i - p[i]];
    const int inf = (int)1e9;
    vector<int> d(n, inf);
    d[0] = 0;
    deque<int> q;
    q.push_back(0);
    while (!q.empty())
    {
        int i = q.front();
        q.pop_front();
    }
}