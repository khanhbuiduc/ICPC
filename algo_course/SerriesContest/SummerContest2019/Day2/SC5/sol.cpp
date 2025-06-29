#include <bits/stdc++.h> 

using namespace std; 
int test; 
long long N, M, A, B; 

pair <long long, long long> findPoint(long long R, long long C, long long X) {
  long long l = 1; 
  long long r = R; 
  long long row = 1; 
  while (l <= r) {
    long long mid = (l + r) >> 1; 
    long long cnt = mid * C; 
    if (cnt < X) {
      l = mid + 1; 
    } 
    else {
      row = mid; 
      r = mid - 1; 
    }
  }
  long long col; 
  X -= (row - 1) * C;
  if (row % 2 == 1) {
    col = X;  
  }
  else {
    col = C - X + 1; 
  }
  return make_pair(row, col); 
} 

int main () {
  freopen("SC5.INP", "r", stdin); 
  freopen("SC5.OUT", "w", stdout); 
  cin >> test; 
  for (int tt = 1; tt <= test; tt++) {
    cin >> N >> M >> A >> B; 
    N = min(N, (A + B) / M + 1); 
    pair <long long, long long> tmp1 = findPoint(N, M, A);
    pair <long long, long long> tmp2 = findPoint(N, M, A + B);
    cout << (abs(tmp1.first - tmp2.first) + abs(tmp1.second - tmp2.second)) << endl; 
  }
  return 0; 
}