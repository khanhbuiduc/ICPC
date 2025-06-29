#include <iostream>
#include <stack>  
#include <vector>
#include <set>
#include <fstream>
int numTest; 
int a[105][105];
int n, m; 
bool visited[2005]; 
bool check[2005]; 

struct element {
  int x1, y1, x2, y2; 
};
element save[2005];
std::set <int> adj[2005];
std::stack <int> order;

void dfs(int u) {
  visited[u] = true;
  for (std::set <int> :: iterator it = adj[u].begin(); it != adj[u].end(); it++) {
    int v = *it;
    if (visited[v] == false) {
      dfs(v);
    }
  }
  order.push(u);
}  

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        std::cin >> a[i][j]; 
      }
    }
    for (int color = 1; color <= 2000; color++) {
      adj[color].clear();
      visited[color] = false;
      check[color] = false;  
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        check[a[i][j]] = true; 
      }
    }
    for (int color = 1; color <= 2000; color++) {
      int x1 = 10005, y1 = 10005, x2 = -1, y2 = -1; 
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          if (a[i][j] == color) {
            x1 = std::min(x1, i);
            y1 = std::min(y1, j); 
            x2 = std::max(x2, i);
            y2 = std::max(y2, j); 
          }
        }
      }
      if (x2 == -1 && y2 == -1) {
        continue;
      }
      for (int x = x1; x <= x2; x++) {
        for (int y = y1; y <= y2; y++) {
          if (a[x][y] != color) {
            adj[color].insert(a[x][y]); 
          }
        }
      }
      save[color] = (element) {x1, y1, x2, y2};
    }
    for (int color = 1; color <= 2000; color++) {
      if (check[color] == true && visited[color] == false) {
        dfs(color); 
      }
    }
    std::cout << (int) order.size() << std::endl;
    while (!order.empty()) {
      int color = order.top();
      order.pop();
      element e = save[color];
      std::cout << e.x1 << ' ' << e.y1 << ' ' << e.x2 << ' ' << e.y2 << ' ' << color << std::endl; 
    }
  }
  return 0; 
}