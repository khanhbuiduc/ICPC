#include <iostream> 
#include <vector>
#include <utility> 
#include <algorithm>
const int LIM = 1000001;
int fw[2 * LIM + 5];
std::vector <int> start[2 * LIM + 5], end[2 * LIM + 5];
int n, m;
std::vector <int> line;
std::vector <std::pair <int, int> > segment[2 * LIM + 5];  

void update(int index, const int value) {
  for (; index <= 2000001; index += index & -index) {
    fw[index] += value; 
  }
}

int get(int index) {
  int ret = 0;
  for (; index > 0; index -= index & -index) {
    ret += fw[index];
  }
  return ret; 
}

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    x1 += LIM;
    y1 += LIM;
    x2 += LIM;
    y2 += LIM; 
    if (x1 == x2) {
      line.push_back(y1);
      line.push_back(y2);
      start[y1].push_back(x1);
      end[y2].push_back(x1);  
    }
    else {
      line.push_back(y1);
      segment[y1].push_back(std::make_pair(x1, x2)); 
    }
  }
  long long ans = 0LL; 
  std::sort(line.begin(), line.end()); 
  for (int i = 0; i < (int) line.size(); i++) {
    int y = line[i]; 
    if (i > 0 && line[i] == line[i - 1]) {
      continue; 
    }
    for (int j = 0; j < (int) start[y].size(); j++) {
      int x = start[y][j];
      update(x, 1); 
    }
    for (int j = 0; j < (int) segment[y].size(); j++) {
      std::pair <int, int> element = segment[y][j]; 
      ans += get(element.second) - get(element.first - 1); 
    }
    for (int j = 0; j < (int) end[y].size(); j++) {
      int x = end[y][j];
      update(x, -1); 
    }
  } 
  std::cout << ans; 
  return 0; 
}