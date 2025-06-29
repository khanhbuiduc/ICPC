#include <iostream>
#include <stack>  
#include <vector>
#include <set>
#include <fstream>

using namespace std; 
const int MAX_N = 105;
const int MAX_V = 2005; 
int numTest; 
int a[MAX_N][MAX_N];
int n, m; 
bool visited[MAX_V]; 
bool check[MAX_V]; 

struct element {
  int x1, y1, x2, y2; 
};
element save[MAX_V];
set <int> adj[MAX_V];
stack <int> order;

void dfs(int u) {
  visited[u] = true;
  for (set <int> :: iterator it = adj[u].begin(); it != adj[u].end(); it++) {
    int v = *it;
    if (visited[v] == false) {
      dfs(v);
    }
  }
  order.push(u);
}  

int main () {
  freopen("WC1.INP", "r", stdin);
  freopen("WC1.OUT", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j]; 
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
            x1 = min(x1, i);
            y1 = min(y1, j); 
            x2 = max(x2, i);
            y2 = max(y2, j); 
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
    cout << (int) order.size() << endl;
    while (!order.empty()) {
      int color = order.top();
      order.pop();
      element e = save[color];
      cout << e.x1 << ' ' << e.y1 << ' ' << e.x2 << ' ' << e.y2 << ' ' << color << endl; 
    }
  }
  return 0; 
}