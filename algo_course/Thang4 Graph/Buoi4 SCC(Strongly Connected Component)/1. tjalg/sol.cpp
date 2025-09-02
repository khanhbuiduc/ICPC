#include <iostream>
#include <vector>
#include <math.h>
#include <stack>
using namespace std;
int n, m;
int low[10005], num[10005];
bool deleted[10005];
vector<int> adj[10005];
int timeDfs = 0;
int scc = 0;
stack<int> mystack;

void dfs(int u)
{
  low[u] = num[u] = ++timeDfs;
  mystack.push(u);
  for (int i = 0; i < (int)adj[u].size(); i++)
  {
    int v = adj[u][i];
    if (deleted[v] == true)
      continue;
    if (num[v] == 0)
    {
      dfs(v);
      low[u] = min(low[u], low[v]);
    }
    else
      low[u] = min(low[u], num[v]);
  }
  if (low[u] == num[u])
  {
    scc++;
    do
    {
      int v = mystack.top();
      mystack.pop();
      deleted[v] = true;
      if (v == u)
      {
        break;
      }
    } while (true);
  }
}

int main()
{
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  for (int i = 1; i <= n; i++)
  {
    if (num[i] == 0)
    {
      dfs(i);
    }
  }
  cout << scc;
  return 0;
}