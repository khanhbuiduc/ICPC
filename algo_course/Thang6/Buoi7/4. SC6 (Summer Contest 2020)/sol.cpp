#include <iostream>
#include <cstring>
const long long mod = 1000000007; 
int n, p; 
int c[33]; 
int f[2][33][33][33]; 
long long C[33][33]; 
long long odd[33], even[33]; 
long long pw[33]; 

void init() {
  pw[0] = 1LL;
  for (int i = 1; i < 33; i++) {
    pw[i] = (pw[i - 1] * 2LL) % mod; 
  }
  for (int i = 0; i < 33; i++) {
    C[i][0] = 1LL;
    C[i][i] = 1LL; 
  }
  for (int i = 1; i < 33; i++) {
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
  }
  for (int i = 0; i < 33; i++) {
    for (int j = 0; j <= i; j += 2) {
      (even[i] += C[i][j]) %= mod; 
    }
    for (int j = 1; j <= i; j += 2) {
      (odd[i] += C[i][j]) %= mod; 
    }
  }
}

int main () {
  init();
  int numTest; 
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> p; 
    for (int i = 1; i <= n; i++) {
      std::cin >> c[i];  
    }
    std::memset(f[0], 0, sizeof(f[0]));
    std::memset(f[1], 0, sizeof(f[1])); 
    f[0][0][0][0] = 1LL; 
    for (int i = 0; i < n; i++) {
      int now = i & 1; 
      int nxt = !now; 
      std::memset(f[nxt], 0, sizeof(f[nxt])); 
      for (int ew = 0; ew <= i; ew++) {
        for (int eb = 0; eb + ew <= i; eb++) {
          for (int ow = 0; eb + ew + ow <= i; ow++) {
            if (f[now][ew][eb][ow] == 0) {
              continue; 
            }
            long long value = f[now][ew][eb][ow]; 
            int ob = i - ew - eb - ow;
            if (c[i + 1] != 0) {
              (f[nxt][ew][eb][ow] += ((value * pw[eb + ob + ew]) % mod * even[ow]) % mod) %= mod; 
              (f[nxt][ew][eb + 1][ow] += ((value * pw[eb + ob + ew]) % mod * odd[ow]) % mod) %= mod; 
            } 
            if (c[i + 1] != 1) {
              (f[nxt][ew][eb][ow + 1] += ((value * pw[ew + ow + eb]) % mod * even[ob]) % mod) %= mod; 
              (f[nxt][ew + 1][eb][ow] += ((value * pw[ew + ow + eb]) % mod * odd[ob]) % mod) %= mod; 
            }
          }
        }
      }
    }
    long long res = 0LL; 
    for (int ew = 0; ew <= n; ew++) {
      for (int eb = 0; eb + ew <= n; eb++) {
        for (int ow = 0; eb + ew + ow <= n; ow++) {
          int ob = n - ew - eb - ow; 
          if ((ow + ob) % 2 == p) {
            (res += f[n & 1][ew][eb][ow]) %= mod; 
          }
        }
      }
    }
    std::cout << res << std::endl;
  }
  return 0; 
}