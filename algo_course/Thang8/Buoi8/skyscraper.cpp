#include <iostream>
#include <algorithm> 
#include <vector>
#include <utility> 
#include <stdio.h>
int numTest, n, numQueries; 
int t[1000005];
std::vector <std::pair <int, int> > a; 
std::vector <int> line;
int root[1000005];
bool marked[1000005]; 
int numbConnected = 0; 

int findRoot(int u) {
  return root[u] = (u == root[u] ? u : findRoot(root[u])); 
}  

void unionSet(int u, int v) {
  int rootu = findRoot(u);
  int rootv = findRoot(v); 
  if (rootu != rootv) {
    numbConnected--; 
    root[rootu] = rootv; 
  }
}

int main () {
  scanf("%d", &numTest);
  for (int testCase = 1; testCase <= numTest; testCase++) {
    scanf("%d %d", &n, &numQueries);
    numbConnected = 0; 
    a.clear(); 
    line.clear();
    line.push_back(0);
    line.push_back(1000000000);   
    a.resize(n); 
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      line.push_back(a[i].first);
      a[i].second = i;  
    }
    for (int i = 0; i < n; i++) {
      root[i] = i; 
      marked[i] = false; 
    }
    std::sort(a.begin(), a.end()); 
    std::reverse(a.begin(), a.end());
    std::sort(line.begin(), line.end());
    std::reverse(line.begin(), line.end());
    std::vector <int> tmp;
    tmp.push_back(line[0]); 
    for (int i = 1; i < (int) line.size(); i++) {
      if (line[i] != line[i - 1]) {
        tmp.push_back(line[i]); 
      }
    }
    line = tmp;
    std::vector <int> numbComponents = line; 
    int p = 0;
    for (int i = 0; i < (int) line.size(); i++) {
      numbComponents[i] = numbConnected;
      while (p < n && line[i] == a[p].first) {
        int id = a[p].second; 
        marked[id] = true; 
        numbConnected++;
        if (id > 0 && marked[id - 1] == true) {
          unionSet(id, id - 1);   
        }
        if (id < n - 1 && marked[id + 1] == true) {
          unionSet(id, id + 1); 
        }
        p++;
      }                                    
    }  
    std::reverse(numbComponents.begin(), numbComponents.end());
    std::reverse(line.begin(), line.end());
    p = 0;
    for (int query = 0; query < numQueries; query++) {
      int level;
      scanf("%d", &level); 
      int ans; 
      while (p < (int) line.size() && line[p] <= level) {
        ans = numbComponents[p];
        p++; 
      }
      printf("%d ", ans); 
    }
    printf("\n");
  }
  return 0; 
}