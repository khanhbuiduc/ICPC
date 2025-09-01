#include <iostream> 
#include <string> 
#include <utility>
#include <queue>

int dist[185][185];
std::string a[185];
int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};                    

void init() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dist[i][j] = -1; 
    }
  }
}

void bfs() {
  std::queue <std::pair <int, int> > myqueue;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '1') {
        dist[i][j] = 0;
        myqueue.push(std::make_pair(i, j));   
      }
    }
  }
  while (!myqueue.empty()) {
    std::pair <int, int> curLocation = myqueue.front();
    myqueue.pop(); 
    int x = curLocation.first; 
    int y = curLocation.second; 
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i]; 
      int yy = y + dy[i];
      if (xx >= 0 && xx < n && yy >= 0 && yy < m && dist[xx][yy] == -1) {
        dist[xx][yy] = dist[x][y] + 1; 
        myqueue.push(std::make_pair(xx, yy)); 
      }
    } 
  }
}

void solve() {
  int numTest;
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m; 
    for (int i = 0; i < n; i++) {
      std::cin >> a[i]; 
    }
    init();
    bfs(); 
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        std::cout << dist[i][j] << ' ';
      }
      std::cout << std::endl; 
    }
  }
}

int main () {
  solve(); 
  return 0; 
}