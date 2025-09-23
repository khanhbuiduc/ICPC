#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum = 0;
long long N;
void dfs(int u, vector<bool> &visited)
{
    visited[u] = true;
    for (int k : {3, 5, 7})
    {
        long long v = 1ll * k * u + 1;
        if (v < N && !visited[v])
        {
            dfs(v, visited);
        }
    }
    sum += u;
}

int main()
{
    cin >> N;
    if (N < 6)
    {
        cout << N - 1;
        return 0;
    }
    vector<bool> visited(N, false);
    dfs(1, visited);
    cout << sum;

    return 0;
}