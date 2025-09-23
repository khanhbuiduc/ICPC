#include <iostream> 
int n; 
int fw[1030][1030]; 

void update(int x, int y, int value) {             
  for (int i = x; i <= n; i += i & -i) {
    for (int j = y; j <= n; j += j & -j) {
      fw[i][j] += value; 
    }
  }
}

int get(int x, int y) {
  int ret = 0;
  for (int i = x; i > 0; i -= i & -i) {
    for (int j = y; j > 0; j -= j & -j) {
      ret += fw[i][j]; 
    }
  }
  return ret; 
}

int main () {
  int type; 
  std::cin >> type >> n; 
  n++;
  while (true) {
    std::cin >> type; 
    if (type == 3) {
      return 0; 
    }
    else if (type == 1) {
      int x, y, value; 
      std::cin >> x >> y >> value; 
      x++;
      y++; 
      update(x, y, value); 
    }
    else {
      int x1, y1, x2, y2; 
      std::cin >> x1 >> y1 >> x2 >> y2;
      x1++;
      y1++;
      x2++;
      y2++;                                     
      int ans = get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x1 - 1, y1 - 1); 
      std::cout << ans << std::endl; 
    }
  }
  return 0; 
}