#include <iostream> 
int fw[60005]; 
int a[60006];
int n; 
long long ans = 0LL;  

void update(int index, int value) {
  for (; index <= 60000; index += index & -index) {
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
    std::cin >> a[i];
  }
  for (int i = n; i >= 1; i--) {
    ans += get(a[i] - 1);
    update(a[i], 1); 
  }
  std::cout << ans;
  return 0; 
}