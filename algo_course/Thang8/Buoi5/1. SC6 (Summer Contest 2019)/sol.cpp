#include <iostream> 
#include <vector>
#include <utility> 
#include <algorithm> 
int n, m, k, start, destination; 
int numTest;
std::pair <int, int> segment[2005]; 
std::vector <int> adj[2005]; 
bool visited[2005]; 

void dfs(int u, int key) {
  visited[u] = true; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (visited[v] == false && segment[v].first <= key && segment[v].second >= key) {
      dfs(v, key); 
    } 
  }
}

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m >> start >> destination >> k; 
    for (int i = 1; i <= n; i++) {
      adj[i].clear(); 
    }
    std::vector <int> save; 
    save.push_back(0); 
    save.push_back(k); 
    for (int i = 1; i <= n; i++) {
      std::cin >> segment[i].first >> segment[i].second; 
      save.push_back(segment[i].first - 1);
      save.push_back(segment[i].second);  
    }
    for (int i = 1; i <= m; i++) {
      int u, v;
      std::cin >> u >> v;
      adj[u].push_back(v);
    }
    std::sort(save.begin(), save.end());
    int ans = 0; 
    for (int i = 0; i < (int) save.size() - 1; i++) {
      if (save[i] + 1 <= save[i + 1]) {
        for (int u = 1; u <= n; u++) {
          visited[u] = false; 
        }
        dfs(start, save[i] + 1); 
      }
      if (visited[destination] == true) {
        ans += save[i + 1] - save[i]; 
      }
    } 
    std::cout << ans << std::endl;
  }
  return 0; 
}