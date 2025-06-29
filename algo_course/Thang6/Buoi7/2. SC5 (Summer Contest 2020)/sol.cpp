#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
const long long inf = 1000000000000000LL; 
long long dist[100005];
std::vector <std::pair <int, int> > adj[100005]; 
bool mark[100005]; 
int n;
long long a, b; 

void createGraph() {
  for (int i = 0; i < 100005; i++) {
    adj[i].clear();
    dist[i] = inf;
    mark[i] = false;  
  }
  std::queue <int> myqueue;
  myqueue.push(0);
  mark[0] = true; 
  while (myqueue.empty() == false) {
    int u = myqueue.front(); 
    myqueue.pop(); 
    int v = u + 1; 
    if (v <= n) {                                
      adj[u].push_back(std::make_pair(v, a)); 
      if (mark[v] == false) {
        mark[v] = true; 
        myqueue.push(v); 
      }
    }
    v = 2 * u; 
    if (v <= n && v != u) {                     
      adj[u].push_back(std::make_pair(v, b));
      if (mark[v] == false) {
        mark[v] = true; 
        myqueue.push(v); 
      }  
    }
  }
}

void Dijkstra() {
  std::priority_queue <std::pair <long long, int>, std::vector <std::pair <long long, int> >, std::greater <std::pair <long long, int> > > pq; 
  pq.push(std::make_pair(0LL, 0));
  dist[0] = 0;
  while (pq.empty() == false) {
    std::pair <long long, int> pqTop = pq.top(); 
    pq.pop(); 
    if (pqTop.first != dist[pqTop.second]) {
      continue; 
    }
    int u = pqTop.second; 
    for (int i = 0; i < (int) adj[u].size(); i++) {
      std::pair <int, int> neighbor = adj[u][i];
      if (neighbor.second + dist[u] < dist[neighbor.first]) {
        dist[neighbor.first] = neighbor.second + dist[u]; 
        pq.push(std::make_pair(dist[neighbor.first], neighbor.first)); 
      }
    }
  } 
}

int main () {
  int numTest; 
  std::cin >> numTest;         
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> a >> b;
    createGraph();
    Dijkstra();
    std::cout << dist[n] << std::endl;     
  }
  return 0; 
}