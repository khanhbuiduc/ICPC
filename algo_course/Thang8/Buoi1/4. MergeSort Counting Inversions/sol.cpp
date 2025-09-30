#include <iostream>
#include <vector>
const int inf = 10000007; 
int n, numTest;
std::vector <int> a; 

long long calculateInversions(std::vector <int> &a) {
  std::vector <int> a1, a2; 
  int n = (int) a.size(); 
  if (n == 1) {
    return 0LL; 
  }
  int mid = n / 2; 
  for (int i = 0; i < mid; i++) {
    a1.push_back(a[i]); 
  }
  for (int i = mid; i < n; i++) {
    a2.push_back(a[i]); 
  }
  long long numbInversions1 = calculateInversions(a1);
  long long numbInversions2 = calculateInversions(a2);
  a1.push_back(inf);
  a2.push_back(inf); 
  long long ret = numbInversions1 + numbInversions2;
  std::vector <int> mergeArray;
  int firstPoint = 0; 
  int secondPoint = 0; 
  while (firstPoint < (int) a1.size() - 1 || secondPoint < (int) a2.size() - 1) {
    if (a1[firstPoint] <= a2[secondPoint]) {
      mergeArray.push_back(a1[firstPoint]);
      firstPoint++;
    }
    else {
      mergeArray.push_back(a2[secondPoint]);
      ret += (int) a1.size() - 1 - firstPoint;
      secondPoint++;
    }
  }
  a = mergeArray; 
  return ret; 
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    a.clear(); 
    std::cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i]; 
    }
    std::cout << calculateInversions(a) << std::endl;
  }
  return 0; 
}