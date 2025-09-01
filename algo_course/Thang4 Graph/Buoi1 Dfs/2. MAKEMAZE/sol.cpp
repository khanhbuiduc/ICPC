#include <iostream>
#include <string>
#include <vector> 
#include <utility> 
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int numTest; 
std::string a[25]; 
int n, m;
bool visited[25][25];
std::vector <std::pair <int, int> > listEntries;  

void dfs(int x, int y) {
  visited[x][y] = true; 
  for (int i = 0; i < 4; i++) {
    int newx = x + dx[i];
    int newy = y + dy[i]; 
    if (newx >= 0 && newx < n && newy >= 0 && newy < m && a[newx][newy] == '.' && visited[newx][newy] == false) {
      dfs(newx, newy); 
    }
  }
}

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    listEntries.clear(); 
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        visited[i][j] = false; 
      }
    } 
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
      std::cin >> a[i]; 
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
          if (a[i][j] == '.') {
            listEntries.push_back(std::make_pair(i, j)); 
          }
        }
      }
    }
    if ((int) listEntries.size() != 2) {
      std::cout << "invalid" << std::endl;
      continue; 
    }
    dfs(listEntries[0].first, listEntries[0].second); 
    if (visited[listEntries[1].first][listEntries[1].second] == true) {
      std::cout << "valid" << std::endl; 
    }
    else {
      std::cout << "invalid" << std::endl; 
    }
  }
  return 0; 
}