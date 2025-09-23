#include <iostream>
const long long mod = 1000000007LL;  
struct element {
  long long value0, lazy0;
  long long value1, lazy1;
  long long value2, lazy2;
  long long value3, lazy3;
  element() {
    value0 = 0;
    lazy0 = 0;
    value1 = 0;
    lazy1 = 0;
    value2 = 0;
    lazy2 = 0;
    value3 = 0;
    lazy3 = 0;
  }  
};

element it[4 * 100005]; 
int n, numQuery; 
long long sum0[100005], sum1[100005], sum2[100005], sum3[100005]; 

void lazyUpdate(int index, int L, int R) {
  if (L == R) {
    return;
  }
  int mid = (L + R) / 2; 
  (it[2 * index].value0 += 1LL * (it[index].lazy0 * (sum0[mid] - sum0[L - 1] + mod) % mod) % mod) %= mod;
  (it[2 * index].lazy0 += it[index].lazy0) %= mod;
  (it[2 * index].value1 += 1LL * (it[index].lazy1 * (sum1[mid] - sum1[L - 1] + mod) % mod) % mod) %= mod;
  (it[2 * index].lazy1 += it[index].lazy1) %= mod;
  (it[2 * index].value2 += 1LL * (it[index].lazy2 * (sum2[mid] - sum2[L - 1] + mod) % mod) % mod) %= mod;
  (it[2 * index].lazy2 += it[index].lazy2) %= mod;
  (it[2 * index].value3 += 1LL * (it[index].lazy3 * (sum3[mid] - sum3[L - 1] + mod) % mod) % mod) %= mod;
  (it[2 * index].lazy3 += it[index].lazy3) %= mod; 
  (it[2 * index + 1].value0 += 1LL * (it[index].lazy0 * (sum0[R] - sum0[mid] + mod) % mod) % mod) %= mod;
  (it[2 * index + 1].lazy0 += it[index].lazy0) %= mod;
  (it[2 * index + 1].value1 += 1LL * (it[index].lazy1 * (sum1[R] - sum1[mid] + mod) % mod) % mod) %= mod;
  (it[2 * index + 1].lazy1 += it[index].lazy1) %= mod;
  (it[2 * index + 1].value2 += 1LL * (it[index].lazy2 * (sum2[R] - sum2[mid] + mod) % mod) % mod) %= mod;
  (it[2 * index + 1].lazy2 += it[index].lazy2) %= mod;
  (it[2 * index + 1].value3 += 1LL * (it[index].lazy3 * (sum3[R] - sum3[mid] + mod) % mod) % mod) %= mod;
  (it[2 * index + 1].lazy3 += it[index].lazy3) %= mod;
  it[index].lazy0 = 0;
  it[index].lazy1 = 0;
  it[index].lazy2 = 0;
  it[index].lazy3 = 0;  
}

void update(int index, int L, int R, int l, int r, long long v0, long long v1, long long v2, long long v3) {
  if (l <= L && R <= r) {           
    (it[index].value0 += (v0 * (sum0[R] - sum0[L - 1] + mod)) % mod) %= mod;
    (it[index].lazy0 += v0) %= mod;
    (it[index].value1 += (v1 * (sum1[R] - sum1[L - 1] + mod)) % mod) %= mod;
    (it[index].lazy1 += v1) %= mod;
    (it[index].value2 += (v2 * (sum2[R] - sum2[L - 1] + mod)) % mod) %= mod;
    (it[index].lazy2 += v2) %= mod;
    (it[index].value3 += (v3 * (sum3[R] - sum3[L - 1] + mod)) % mod) %= mod;
    (it[index].lazy3 += v3) %= mod;
    if (L < R) {
      lazyUpdate(index, L, R); 
    }
    return; 
  }
  lazyUpdate(index, L, R); 
  if (L > r || l > R) {
    return; 
  }
  int mid = (L + R) / 2; 
  update(2 * index, L, mid, l, r, v0, v1, v2, v3);
  update(2 * index + 1, mid + 1, R, l, r, v0, v1, v2, v3);
  it[index].value0 = (it[2 * index].value0 + it[2 * index + 1].value0) % mod;
  it[index].value1 = (it[2 * index].value1 + it[2 * index + 1].value1) % mod;
  it[index].value2 = (it[2 * index].value2 + it[2 * index + 1].value2) % mod;
  it[index].value3 = (it[2 * index].value3 + it[2 * index + 1].value3) % mod;
}
                                                                              
long long getSum(int index, int L, int R, int l, int r) {
  if (l <= L && R <= r) {
    long long ret = 0LL; 
    (ret += it[index].value0) %= mod;
    (ret += it[index].value1) %= mod;
    (ret += it[index].value2) %= mod;
    (ret += it[index].value3) %= mod;
    if (L < R) {
      lazyUpdate(index, L, R); 
    }
    return ret; 
  } 
  lazyUpdate(index, L, R); 
  if (l > R || L > r) {
    return 0LL; 
  }
  int mid = (L + R) / 2; 
  long long valueLeft = getSum(2 * index, L, mid, l, r); 
  long long valueRight = getSum(2 * index + 1, mid + 1, R, l, r);
  return (valueLeft + valueRight) % mod;  
}

int main () {
  std::cin >> n >> numQuery;
  for (int i = 1; i <= n; i++) {
    sum0[i] = sum0[i - 1] + 1; 
    sum1[i] = (sum1[i - 1] + i) % mod; 
    sum2[i] = (sum2[i - 1] + (1LL * i * i) % mod) % mod; 
    sum3[i] = (sum3[i - 1] + (1LL * i * i * i) % mod) % mod; 
  }
  for (int query = 1; query <= numQuery; query++) {
    int type, l, r;
    std::cin >> type >> l >> r;
    if (type == 0) {
      std::cout << getSum(1, 1, n, l, r) << std::endl; 
    } 
    else {
      long long v0 = (-(1LL * l * l * l) % mod + mod) % mod;
      (v0 += (6LL * l * l) % mod + 6LL) %= mod;
      v0 -= (11LL * l) % mod;
      (v0 += mod) %= mod;
      long long v1 = (3LL * l * l + 11LL) % mod; 
      v1 -= (12LL * l) % mod;
      (v1 += mod) %= mod;
      long long v2 = (-3LL * l + 6LL) % mod; 
      (v2 += mod) %= mod;
      long long v3 = 1LL;
      if (type == 1) {
        update(1, 1, n, l, r, v0, v1, v2, v3);
      }
      else {
        update(1, 1, n, l, r, mod - v0, mod - v1, mod - v2, mod - v3); 
      }
    }
  }
  return 0; 
}