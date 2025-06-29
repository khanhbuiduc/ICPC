#include <bits/stdc++.h> 

using namespace std; 
const int MAX_V = 100005; 
int key[102]; 
int dist[MAX_V]; 

int main () {
  freopen("AC5.INP", "r", stdin);
  freopen("AC5.OUT", "w", stdout); 
  int test; 
  cin >> test; 
  for (int tt = 1; tt <= test; tt++) {
    int n, k; 
    cin >> n >> k; 
    for (int i = 1; i <= n; i++) {
      cin >> key[i]; 
    }
    for (int i = 0; i < MAX_V; i++) {
      dist[i] = -1; 
    }
    dist[1] = 0; 
    queue <int> myqueue; 
    myqueue.push(1); 
    while (!myqueue.empty()) {
      int u = myqueue.front();
      myqueue.pop(); 
      for (int i = 1; i <= n; i++) {
        int v = u * key[i]; 
        if (v > 100000 || dist[v] != -1) {
          continue; 
        }
        dist[v] = dist[u] + 1; 
        myqueue.push(v); 
      }
    }
    if (dist[k] == -1) {
      cout << "Impossible"; 
    }
    else {
      cout << dist[k];
    }
    cout << endl; 
  }
  return 0; 
}