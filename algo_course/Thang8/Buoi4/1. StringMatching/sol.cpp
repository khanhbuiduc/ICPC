#include <iostream>
#include <string>
std::string original, pattern; 
long long power27[1000005]; 
long long hashSum[1000005];

int main () {
  std::cin >> original >> pattern; 
  int n = (int) original.size();
  power27[0] = 1LL;
  for (int i = 1; i <= 1000000; i++) {
    power27[i] = power27[i - 1] * 27LL; 
  } 
  for (int i = 1; i <= n; i++) {
    hashSum[i] = hashSum[i - 1] + power27[i - 1] * (original[i - 1] - 'a' + 1); 
  }
  long long hashValue = 0LL;
  int lenPattern = (int) pattern.size();  
  for (int i = 0; i < lenPattern; i++) {
    hashValue += power27[i] * (pattern[i] - 'a' + 1); 
  }
  int ans = 0;
  for (int i = 0; i + lenPattern - 1 < n; i++) {
    if (pattern[0] != original[i]) {
      continue;
    }
    int l = i + 1;
    int r = l + lenPattern - 1; 
    if (hashValue * power27[i] == hashSum[r] - hashSum[l - 1]) {
      ans++; 
    }
  }
  std::cout << ans;
  return 0;
}