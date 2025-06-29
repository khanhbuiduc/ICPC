#include <iostream>
#include <queue>
#include <utility>
#include <vector>    
#include <string>
#include <functional>
const int inf = 1000000007; 
std::vector <std::string> a;
int n, m;
std::vector <std::vector <int> > dist; 
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

int main() {
  while (true) {
    std::cin >> n >> m;
    if (n == 0 && m == 0) {
      break; 
    }
    a.resize(n);
    dist.resize(n);
    for (int i = 0; i < n; i++) {
      a[i].clear();
      dist[i].clear(); 
    }
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        dist[i].push_back(inf); 
      }
    }
    std::priority_queue <std::pair <int, std::pair <int, int> >, std::vector <std::pair <int, std::pair <int, int> > >, std::greater <std::pair <int, std::pair <int, int> > > > pq;
    for (int i = 0; i < n; i++) {
      if (a[i][0] == '.') {
        dist[i][0] = 1; 
        pq.push(std::make_pair(1, std::make_pair(i, 0))); 
      }
      else if (a[i][0] == '#') {
        dist[i][0] = 0;
        pq.push(std::make_pair(0, std::make_pair(i, 0))); 
      }
    }
    for (int j = 0; j < m; j++) {
      if (a[n - 1][j] == '.') {
        dist[n - 1][j] = 1;
        pq.push(std::make_pair(1, std::make_pair(n - 1, j)));
      }
      else if (a[n - 1][j] == '#') {
        dist[n - 1][j] = 0;
        pq.push(std::make_pair(0, std::make_pair(n - 1, j))); 
      }
    }
    bool found = false;
    while (!pq.empty()) {
      std::pair <int, std::pair <int, int> > pqTop = pq.top(); 
      pq.pop();
      int distance = pqTop.first;
      int x = pqTop.second.first;
      int y = pqTop.second.second;
      if (x == 0 || y == m - 1) {
        std::cout << distance << std::endl;
        found = true; 
        break; 
      }
      if (distance != dist[x][y]) {
        continue; 
      }
      for (int i = 0; i < 8; i++) {
        int nextx = x + dx[i];
        int nexty = y + dy[i];
        if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < m) {
          if (a[nextx][nexty] == '@') {
            continue; 
          }
          int cost = (a[nextx][nexty] == '.'); 
          if (dist[nextx][nexty] > dist[x][y] + cost) {
            dist[nextx][nexty] = dist[x][y] + cost;
            pq.push(std::make_pair(dist[nextx][nexty], std::make_pair(nextx, nexty))); 
          }
        }
      }
    }
    if (found == false) {
      std::cout << -1 << std::endl; 
    }
  }
  return 0; 
}