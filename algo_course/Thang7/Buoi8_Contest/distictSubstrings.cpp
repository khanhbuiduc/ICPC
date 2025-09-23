#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <math.h>
const int alphabet = 256; 
std::string s;  
int n; 
std::vector <int> p, c, cnt; 
std::vector <int> rank, lcp; 
 
int main () {
  std::cin >> s;
  s += '$'; 
  n = (int) s.size(); 
  p.resize(n);
  c.resize(n); 
  cnt.resize(std::max(alphabet, n), 0); 
  for (int i = 0; i < n; i++) {
    cnt[s[i]]++; 
  }
  for (int i = 1; i < alphabet; i++) {
    cnt[i] += cnt[i - 1]; 
  }
  for (int i = 0; i < n; i++) {
    p[--cnt[s[i]]] = i;
  }
  c[p[0]] = 0; 
  int classes = 1;
  for (int i = 1; i < n; i++) {
    if (s[p[i]] != s[p[i - 1]]) {
      classes++; 
    }
    c[p[i]] = classes - 1; 
  }
  std::vector <int> pn(n), cn(n); 
  for (int h = 0; (1 << h) < n; h++) {
    for (int i = 0; i < n; i++) {
      pn[i] = p[i] - (1 << h);
      if (pn[i] < 0) {
        pn[i] += n; 
      }  
    }
    for (int i = 0; i < classes; i++) {
      cnt[i] = 0; 
    }
    for (int i = 0; i < n; i++) {
      cnt[c[pn[i]]]++; 
    }
    for (int i = 1; i < classes; i++) {
      cnt[i] += cnt[i - 1]; 
    }
    for (int i = n - 1; i >= 0; i--) {
      p[--cnt[c[pn[i]]]] = pn[i]; 
    }
    classes = 1; 
    cn[p[0]] = 0;
    for (int i = 1; i < n; i++) {
      std::pair <int, int> cur = std::make_pair(c[p[i]], c[(p[i] + (1 << h)) % n]); 
      std::pair <int, int> prev = std::make_pair(c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]); 
      if (cur != prev) {
        classes++; 
      }
      cn[p[i]] = classes - 1; 
    }
    c.swap(cn);  
  }
  p.erase(p.begin()); 
  n--; 
  rank.resize(n);
  lcp.resize(n);
  for (int i = 0; i < n; i++) {
    rank[p[i]] = i;
  } 
  int k = 0;
  for (int i = 0; i < n; i++) {
    if (rank[i] == n - 1) {
      k = 0;
      continue; 
    }
    int j = p[rank[i] + 1]; 
    while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
      k++; 
    }
    lcp[rank[i]] = k; 
    if (k > 0) {
      k--; 
    }
  }
  long long ans = (long long) n * (n + 1) / 2; 
  for (int i = 0; i < n; i++) {
    ans -= lcp[i]; 
  }
  std::cout << ans; 
  return 0;         
}