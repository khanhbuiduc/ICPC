#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <utility> 
const int inf = 1000000007; 
struct element {
  int x, y, position;
  bool operator < (const element &other) const {
    return x < other.x; 
  }  
};
std::string a[55]; 
int distance[55][55][55]; 
std::priority_queue <std::pair <int, element>, std::vector <std::pair <int, element> >, std::greater <std::pair <int, element> > > pq; 
std::string command; 
int n, m; 
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0}; 

std::pair <int, int> nextBaseOnDirection(char direction) {
  if (direction == 'U') {
    return std::make_pair(-1, 0); 
  }
  else if (direction == 'D') {
    return std::make_pair(1, 0); 
  }
  else if (direction == 'L') {
    return std::make_pair(0, -1); 
  }
  else {
    return std::make_pair(0, 1); 
  }
}

int main () {
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i]; 
  }
  int startx = -1, starty = -1, endx = -1, endy = -1; 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'R') {
        startx = i;
        starty = j;   
      }
      else if (a[i][j] == 'E') {
        endx = i;
        endy = j; 
      }
    }
  }
  std::cin >> command; 
  int lenCommand = (int) command.size(); 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int position = 0; position <= lenCommand; position++) {
        distance[i][j][position] = inf; 
      }
    }
  }
  distance[startx][starty][0] = 0; 
  pq.push(std::make_pair(0, (element) {startx, starty, 0})); 
  while (pq.empty() == false) {
    std::pair <int, element> pqTop = pq.top(); 
    pq.pop(); 
    element currentState = pqTop.second; 
    int x = currentState.x;
    int y = currentState.y;
    if (endx == x && endy == y) {
      std::cout << pqTop.first;
      return 0; 
    }
    int position = currentState.position; 
    if (distance[x][y][position] != pqTop.first) {
      continue; 
    }
    if (position < lenCommand) {
      if (distance[x][y][position + 1] > distance[x][y][position] + 1) {
        distance[x][y][position + 1] = distance[x][y][position] + 1;
        pq.push(std::make_pair(distance[x][y][position + 1], (element) {x, y, position + 1})); 
      }
    }
    for (int i = 0; i < 4; i++) {
      int nextx = x + dx[i];
      int nexty = y + dy[i];
      if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m || a[nextx][nexty] == '#') {
        nextx = x;
        nexty = y; 
      }
      if (distance[nextx][nexty][position] > distance[x][y][position] + 1) {
        distance[nextx][nexty][position] = distance[x][y][position] + 1;
        pq.push(std::make_pair(distance[nextx][nexty][position], (element) {nextx, nexty, position})); 
      }
    }
    if (position < lenCommand) {
      std::pair <int, int> addOn = nextBaseOnDirection(command[position]); 
      int nextx = x + addOn.first;
      int nexty = y + addOn.second;
      if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m || a[nextx][nexty] == '#') {
        nextx = x;
        nexty = y; 
      }
      if (distance[nextx][nexty][position + 1] > distance[x][y][position]) {
        distance[nextx][nexty][position + 1] = distance[x][y][position];
        pq.push(std::make_pair(distance[nextx][nexty][position + 1], (element) {nextx, nexty, position + 1})); 
      }
    }
  }
  return 0; 
}