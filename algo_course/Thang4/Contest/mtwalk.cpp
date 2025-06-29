#include <iostream>
#include <math.h>
bool visited[105][105]; 
int height[105][105]; 
int n; 
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0}; 

void dfs(int x, int y, int lo, int hi) {
  visited[x][y] = true; 
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && visited[nx][ny] == false && lo <= height[nx][ny] && height[nx][ny] <= hi) {
      dfs(nx, ny, lo, hi); 
    }
  }
}

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> height[i][j];
    }
  }
  int ans = 115; 
  for (int minHeight = 0; minHeight <= height[1][1]; minHeight++) {
    int lo = 0;
    int hi = 110; 
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          visited[i][j] = false;
        }
      } 
      dfs(1, 1, minHeight, minHeight + mid); 
      if (visited[n][n] == true) {
        ans = std::min(ans, mid);
        hi = mid - 1;   
      }
      else {
        lo = mid + 1; 
      }
    }
  }
  std::cout << ans; 
  return 0; 
}