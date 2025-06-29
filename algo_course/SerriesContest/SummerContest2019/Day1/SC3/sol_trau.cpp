#include <bits/stdc++.h> 

using namespace std; 
struct element {
  int x, y, c; 
};
const int MAX_N = 405; 
int test; 
int n; 
vector <element> e; 
int a[MAX_N][MAX_N]; 

int main () {
  freopen("SC3.INP", "r", stdin);
  freopen("output.txt", "w", stdout); 
  scanf("%d", &test); 
  for (int tt = 1; tt <= test; tt++) {
    scanf("%d", &n);
    e.clear(); 
    for (int x = 0; x <= 400; x++) {
      for (int y = 0; y <= 400; y++) {
        a[x][y] = 0; 
      }
    }
    for (int i = 1; i <= n; i++) {
      int x, y, c; 
      scanf("%d %d %d", &x, &y, &c); 
      e.push_back((element) {x, y, c}); 
      a[x + 200][y + 200] = c; 
    }
    int res = 0; 
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i != j) {
          if (e[i].x < e[j].x && e[i].y < e[j].y) {
            int c1 = e[i].c;
            int c2 = e[j].c;
            int c3 = a[e[i].x + 200][e[j].y + 200];
            int c4 = a[e[j].x + 200][e[i].y + 200];
            if (c1 == 0 || c2 == 0 || c3 == 0 || c4 == 0) {
              continue; 
            }
            if (c1 != c2 && c1 != c3 && c1 != c4 && c2 != c3 && c2 != c4 && c3 != c4) {
              res++;   
            }  
          }
        }
      }
    }
    printf("%d\n", res); 
  }
  return 0; 
}