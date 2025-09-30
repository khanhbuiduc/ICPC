#include <iostream> 
#include <algorithm>
int n, k;
long long a[10005]; 
long long askAnd(int i, int j) {
  std::cout << "and " << i << ' ' << j << std::endl;
  fflush(stdout); 
  long long ret;
  std::cin >> ret; 
  return ret; 
}

long long askOr(int i, int j) {
  std::cout << "or " << i << ' ' << j << std::endl;
  fflush(stdout); 
  long long ret;
  std::cin >> ret; 
  return ret; 
}

int main () {
  std::cin >> n >> k;
  long long and12 = askAnd(1, 2);
  long long or12 = askOr(1, 2);
  long long and23 = askAnd(2, 3);
  long long or23 = askOr(2, 3);
  long long and31 = askAnd(3, 1);
  long long or31 = askOr(3, 1); 
  long long sum = (and12 + or12 + and23 + or23 + and31 + or31) / 2; 
  a[1] = sum - (and23 + or23); 
  a[2] = sum - (and31 + or31); 
  a[3] = sum - (and12 + or12);
  for (int i = 4; i <= n; i++) {
    long long andValue = askAnd(1, i);
    long long orValue = askOr(1, i);
    a[i] = andValue + orValue - a[1];  
  } 
  std::sort(a + 1, a + n + 1);
  std::cout << "finish " << a[k] << std::endl;
  fflush(stdout); 
  return 0; 
}