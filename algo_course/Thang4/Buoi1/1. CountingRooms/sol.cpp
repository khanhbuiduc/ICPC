#include <iostream>
#include <string>  
int dx[4] = {0, 0, 1, -1}; 
int dy[4] = {1, -1, 0, 0}; 
std::string a[1005]; 
int n, m; 
bool visited[1005][1005]; 
 
void dfs(int x, int y) {
  visited[x][y] = true;
  for (int i = 0; i < 4; i++) {
    int newx = x + dx[i];
    int newy = y + dy[i];
    if (newx >= 0 && newx < n && newy >= 0 && newy < m && visited[newx][newy] == false && a[newx][newy] == '.') {
      dfs(newx, newy);
    }
  }
}
 
int main () {
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i]; 
  }
  int ans = 0; 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '.' && visited[i][j] == false) {
        ans++;
        dfs(i, j); 
      }
    }
  }
  std::cout << ans; 
  return 0;
}