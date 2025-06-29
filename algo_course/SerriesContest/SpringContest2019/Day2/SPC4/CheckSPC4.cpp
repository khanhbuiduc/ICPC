#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 26; 
struct element {
  int R, C; 
  char a[MAX_N][MAX_N]; 
};

vector <element> A, B; 
int test; 
pair <int, int> mark[26]; 
int cnt[26]; 

bool compare(element &A, element &B) {
  for (int i = 0; i < 26; i++) {
    mark[i].first = 0;
    mark[i].second = 0; 
    cnt[i] = 0; 
  }

  for (int i = 1; i <= A.R; i++) {
    for (int j = 1; j <= A.C; j++) {
      if (A.a[i][j] != '?') {
        mark[A.a[i][j] - 'A'].first = i; 
        mark[A.a[i][j] - 'A'].second = j; 
      }
    }
  }

  int sum = 0; 

  for (int c = 0; c < 26; c++) {
    if (mark[c].first == 0) {
      continue;
    }

    int x1 = MAX_N, y1 = MAX_N, x2 = -1, y2 = -1; 
    for (int i = 1; i <= A.R; i++) {
      for (int j = 1; j <= A.C; j++) {
        if (B.a[i][j] - 'A' != c) {
          continue; 
        }

        x1 = min(x1, i); 
        y1 = min(y1, j); 
        x2 = max(x2, i); 
        y2 = max(y2, j); 
        cnt[c]++; 
      }
    }

    if (x2 == -1) {
      return false; 
    }

    sum += cnt[c]; 
    if (cnt[c] != (x2 - x1 + 1) * (y2 - y1 + 1)) {
      return false; 
    }
    
    if (mark[c].first < x1 || mark[c].first > x2 || mark[c].second < y1 || mark[c].second > y2) {
      return false; 
    }
  }

  if (sum != A.R * A.C) {
    return false; 
  }

  return true;
} 

int main (int argc, char **argv) {
  if (argc == 3) {
    freopen(argv[0], "r", stdin); 
  } 
  cin.clear(); 
  cin >> test; 
  for (int t = 1; t <= test; t++) {
    element E; 
    cin >> E.R >> E.C; 
    for (int i = 1; i <= E.R; i++) {
      for (int j = 1; j <= E.C; j++) {
        cin >> E.a[i][j]; 
      }
    }

    A.push_back(E); 
  }
  
  if (argc == 3) {
    freopen(argv[2], "r", stdin); 
  }
  cin.clear();  
  for (int t = 1; t <= test; t++) {
    element E = A[t - 1];
    for (int i = 1; i <= E.R; i++) {
      for (int j = 1; j <= E.C; j++) {
        cin >> E.a[i][j]; 
      }
    }

    B.push_back(E); 
  }
  
  //freopen("output.txt", "w", stdout);
  bool ok = true; 
  for (int t = 0; t < test; t++) {
    ok &= compare(A[t], B[t]);  
  }

  if (ok == true) {            
    cout << 1.0 << endl; 
    cerr << "Correct" << endl; 
  }
  else {                            
    cout << 0.0 << endl; 
    cerr << "Wrong Answer" << endl;
  }
  return 0; 
}