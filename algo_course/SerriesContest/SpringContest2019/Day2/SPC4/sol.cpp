#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 26; 

int test; 
char a[MAX_N][MAX_N]; 
int R, C; 

int main () {
  //freopen("SPC4.INP", "r", stdin);
  //freopen("SPC4.OUT", "w", stdout);
  cin >> test; 
  for (int tt = 1; tt <= test; tt++) {
    cin >> R >> C; 
    for (int i = 1; i <= R; i++) {
      for (int j = 1; j <= C; j++) {
        cin >> a[i][j]; 
      }
    }

    for (int i = 1; i <= R; i++) {
      for (int j = 1; j <= C; j++) {
        if (a[i][j] != '?') {
          int x = j - 1; 
          while (a[i][x] == '?') {
            a[i][x] = a[i][j];
            x--;  
          }

          x = j + 1; 
          while (a[i][x] == '?') {
            a[i][x] = a[i][j]; 
            x++; 
          }
        }
      }
    }

    for (int i = 1; i <= R; i++) {
      for (int j = 1; j <= C; j++) {
        if (a[i][j] != '?') {
          int x = i - 1; 
          while (a[x][j] == '?') {
            a[x][j] = a[i][j];
            x--;  
          }

          x = i + 1; 
          while (a[x][j] == '?') {
            a[x][j] = a[i][j]; 
            x++; 
          }
        }
      }
    }
    for (int i = 1; i <= R; i++) {
      for (int j = 1; j <= C; j++) {
        cout << a[i][j]; 
      }

      cout << endl; 
    }
  }
  return 0; 
}