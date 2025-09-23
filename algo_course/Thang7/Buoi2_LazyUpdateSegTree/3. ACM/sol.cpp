#include <iostream>
#include <math.h> 
#include <vector> 
#include <stdio.h>
#include <utility>
int n, numQueries;
int numTest; 
std::vector <int> listPrimes; 
std::vector <std::pair <int, int> > pw[151]; 
struct node {
  long long lazyValue; 
  long long sum; 
};
node it[35][4 * 50002]; 
bool isPrime(int p) {
  for (int i = 2; i <= (int) std::sqrt(p); i++) {
    if (p % i == 0) {
      return false; 
    }
  }
  return true; 
}
void init() {
  for (int p = 2; p <= 150; p++) {
    if (isPrime(p) == true) {
      listPrimes.push_back(p); 
    }
  }
  for (int i = 1; i <= 150; i++) {
    int x = i; 
    for (int j = 0; j < 35; j++) {
      int cnt = 0;
      while (x % listPrimes[j] == 0) {
        cnt++;
        x /= listPrimes[j]; 
      }
      if (cnt > 0) {
        pw[i].push_back(std::make_pair(j, cnt));    
      }
    } 
  }                                                 
}
long long fastpow(const long long &x, const long long &n, const long long &mod) {
  if (n == 0) {
    return 1LL; 
  }
  long long ret = fastpow(x, n / 2, mod); 
  (ret *= ret) %= mod; 
  if (n % 2 == 1) {
    (ret *= x) %= mod; 
  }
  return ret; 
}
void build(const int &j, int index, int L, int R) {
  it[j][index] = (node) {0LL, 0LL};
  if (L == R) {
    return;  
  }
  int mid = (L + R) / 2; 
  build(j, 2 * index, L, mid);
  build(j, 2 * index + 1, mid + 1, R); 
}
void lazyUpdate(const int &j, int index, int L, int R) {
  if (L < R) {
    int mid = (L + R) / 2; 
    it[j][2 * index].lazyValue += it[j][index].lazyValue; 
    it[j][2 * index].sum += (long long) (mid - L + 1) * it[j][index].lazyValue;
    it[j][2 * index + 1].lazyValue += it[j][index].lazyValue;
    it[j][2 * index + 1].sum += (long long) (R - mid) * it[j][index].lazyValue;  
  }
  it[j][index].lazyValue = 0LL; 
}
void update(const int &j, int index, int L, int R, int l, int r, const long long &k) {
  lazyUpdate(j, index, L, R);
  if (L > r || l > R) {
    return; 
  }  
  if (l <= L && R <= r) {
    it[j][index].lazyValue += k; 
    it[j][index].sum += (long long) (R - L + 1) * k;
    lazyUpdate(j, index, L, R);
    return;   
  }
  int mid = (L + R) / 2; 
  update(j, 2 * index, L, mid, l, r, k); 
  update(j, 2 * index + 1, mid + 1, R, l, r, k);                              
  it[j][index].sum = it[j][2 * index].sum + it[j][2 * index + 1].sum; 
}
long long get(const int &j, int index, int L, int R, int l, int r) {
  lazyUpdate(j, index, L, R);
  if (L > r || l > R) {
    return 0LL; 
  } 
  if (l <= L && R <= r) {
    return it[j][index].sum; 
  }
  int mid = (L + R) / 2; 
  long long sumLeft = get(j, 2 * index, L, mid, l, r);
  long long sumRight = get(j, 2 * index + 1, mid + 1, R, l, r);
  return sumLeft + sumRight;  
} 

int main () {
  init();
  scanf("%d", &numTest); 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    scanf("%d %d", &n, &numQueries); 
    for (int j = 0; j < 35; j++) {
      build(j, 1, 1, n);
    }
    for (int query = 1; query <= numQueries; query++) {
      int type, L, R;
      scanf("%d %d %d", &type, &L, &R); 
      if (type == 0) {
        long long mod;
        scanf("%lld", &mod);      
        long long ans = 1LL;
        for (int j = 0; j < 35; j++) {
          if (L <= R) {
            (ans *= fastpow(listPrimes[j], get(j, 1, 1, n, L, R), mod)) %= mod; 
          }
          else {
            (ans *= fastpow(listPrimes[j], get(j, 1, 1, n, L, n), mod)) %= mod; 
            (ans *= fastpow(listPrimes[j], get(j, 1, 1, n, 1, R), mod)) %= mod; 
          }
        }
        printf("%lld\n", ans);   
      }
      else if (type == 1) {
        int X; 
        scanf("%d", &X); 
        if (X == 1) {
          continue; 
        }
        std::vector <std::pair <int, int> > &cnt = pw[X];
        for (int j = 0; j < (int) cnt.size(); j++) {                          
          if (L <= R) {
            update(cnt[j].first, 1, 1, n, L, R, cnt[j].second);
          }
          else {
            update(cnt[j].first, 1, 1, n, L, n, cnt[j].second);
            update(cnt[j].first, 1, 1, n, 1, R, cnt[j].second);
          } 
        }                      
      }
      else {
        int Y;
        scanf("%d", &Y);
        if (Y == 1) {
          continue; 
        }
        std::vector <std::pair <int, int> > &cnt = pw[Y]; 
        for (int j = 0; j < (int) cnt.size(); j++) {
          if (L <= R) {
            update(cnt[j].first, 1, 1, n, L, R, -cnt[j].second);
          }
          else {
            update(cnt[j].first, 1, 1, n, L, n, -cnt[j].second);
            update(cnt[j].first, 1, 1, n, 1, R, -cnt[j].second);
          } 
        }
      }
    }
  }
  return 0; 
}