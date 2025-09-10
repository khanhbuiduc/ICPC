#include <iostream> 
#include <vector>
#include <map>
int numTest; 
int n, B; 
int a[200005][11]; 
int sum[200005][11]; 
std::vector <int> k[200005]; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> B;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= B; j++) {
        std::cin >> a[i][j]; 
      }
    }  
    for (int j = 1; j <= B; j++) {
      for (int i = 1; i <= n; i++) {
        sum[i][j] = sum[i - 1][j] + a[i][j]; 
      }
    }
    for (int i = 0; i <= n; i++) {
      k[i].clear(); 
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 1; j < B; j++) {
        k[i].push_back(sum[i][j] - sum[i][j + 1]); 
      }
    }
    std::map <std::vector <int>, int> cnt;
    cnt[k[0]] = 1;
    long long ans = 0; 
    for (int i = 1; i <= n; i++) {
      ans += cnt[k[i]]; 
      cnt[k[i]]++; 
    } 
    std::cout << ans << std::endl; 
  }
  return 0; 
}