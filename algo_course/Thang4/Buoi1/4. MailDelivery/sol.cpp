#include <iostream>
#include <set>
#include <vector>
int n, m;
std::set<int> adj[100005];
std::vector<int> ans;

void dfs(int u)
{
  while (adj[u].empty() == false)
  {
    std::set<int>::iterator it = adj[u].begin();
    int v = *it;
    adj[v].erase(u);
    adj[u].erase(v);
    dfs(v);
  }
  ans.push_back(u);
}

int main()
{
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++)
  {
    int u, v;
    std::cin >> u >> v;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  for (int u = 1; u <= n; u++)
  {
    if ((int)adj[u].size() % 2 == 1)
    {
      std::cout << "IMPOSSIBLE";
      return 0;
    }
  }
  dfs(1);
  if ((int)ans.size() != m + 1)
  {
    std::cout << "IMPOSSIBLE";
  }
  else
  {
    for (int i = 0; i < (int)ans.size(); i++)
    {
      std::cout << ans[i] << ' ';
    }
  }
  return 0;
}