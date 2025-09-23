#include <iostream> 
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
const int inf = 400000007;
std::vector <std::pair <int, int> > save; 
std::vector <int> a; 
int n;
long long k; 
long long fw[100005];

int getSmaller(int x) {
  int lo = 0;
  int hi = (int) a.size() - 1;
  int ret = -1; 
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] <= x) {
      ret = mid;
      lo = mid + 1; 
    }      
    else {
      hi = mid - 1;
    }
  } 
  return ret + 1; 
}

int getBigger(int x) {
  int lo = 0; 
  int hi = (int) a.size() - 1;
  int ret = -1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] >= x) {
      ret = mid;
      hi = mid - 1;
    }
    else {
      lo = mid + 1;
    }
  }
  return ret + 1;
}

long long get(int index) {
  long long ret = 0;
  for (; index > 0; index -= index & -index) {
    ret += fw[index];
  }
  return ret;
}

void update(int index, int value) {
  for (; index <= 100000; index += index & -index) {
    fw[index] += value;
  }
}

long long calc(int distance) {
  std::memset(fw, 0, sizeof(fw));
  long long ret = 0;
  int j = 0; 
  for (int i = 0; i < (int) save.size(); i++) {
    while (j < i && save[j].first + distance < save[i].first) {
      update(getSmaller(save[j].second), -1);
      j++;
    }
    int up = getSmaller(save[i].second + distance);
    int down = getBigger(save[i].second - distance); 
    ret += get(up) - get(down - 1);
    update(getSmaller(save[i].second), 1);
  }
  return ret;
}

int main () {
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    save.push_back(std::make_pair(x + y, x - y));
    a.push_back(x - y);
  }
  std::sort(save.begin(), save.end());
  std::sort(a.begin(), a.end());
  a.erase(std::unique(a.begin(), a.end()), a.end()); 
  int lo = 1, hi = inf; 
  int ans = 0;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    long long numb = calc(mid);
    if (numb >= k) {
      ans = mid;
      hi = mid - 1;
    }
    else {
      lo = mid + 1;
    }
  }
  std::cout << ans;
  return 0; 
}