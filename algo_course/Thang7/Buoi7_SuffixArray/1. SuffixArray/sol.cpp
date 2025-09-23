#include <iostream>
#include <vector>
#include <math.h>
#include <utility> 
#include <string>  
const int alphabet = 256; 
std::vector <int> c, p, cnt;
std::string s; 
int n; 

int main () {
  std::cin >> s; 
  s += '$'; 
  n = (int) s.size(); 
  cnt.resize(std::max(n + 2, alphabet), 0);
  c.resize(n);        
  p.resize(n);
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
    cn[p[0]] = 0;
    classes = 1;
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
  for (int i = 0; i < (int) p.size(); i++) {
    std::cout << p[i] << ' '; 
  }                 
  return 0; 
}                 