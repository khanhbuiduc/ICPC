#include <bits/stdc++.h>

using namespace std;

struct Edge
{
  int v;
  int flow;
  int C; 
  int rev;
};

class Graph
{
public:
  int V;
  int *level;
  vector< Edge > *adj;
  Graph(int V)
  {
    adj = new vector<Edge>[V];
    this->V = V;
    level = new int[V];
  }

  void addEdge(int u, int v, int C)
  {
    Edge a{v, 0, C, adj[v].size()};
    Edge b{u, 0, 0, adj[u].size()};

    adj[u].push_back(a);
    adj[v].push_back(b);
  }

  bool BFS(int s, int t);
  int sendFlow(int s, int flow, int t, int ptr[]);
  int DinicMaxflow(int s, int t);
};

bool Graph::BFS(int s, int t)
{
  for (int i = 0 ; i < V ; i++)
    level[i] = -1;
  level[s] = 0;
  list< int > q;
  q.push_back(s);
  vector<Edge>::iterator i;
  while (!q.empty())
  {
    int u = q.front();
    q.pop_front();
    for (i = adj[u].begin(); i != adj[u].end(); i++)
    {
      Edge &e = *i;
      if (level[e.v] < 0 && e.flow < e.C)
      {
        level[e.v] = level[u] + 1;

        q.push_back(e.v);
      }
    }
  }
  return level[t] < 0 ? false : true ;
}

int Graph::sendFlow(int u, int flow, int t, int start[])
{
  if (u == t)
    return flow;
  for ( ; start[u] < adj[u].size(); start[u]++)
  {
    Edge &e = adj[u][start[u]];                
    if (level[e.v] == level[u]+1 && e.flow < e.C)
    {
      int curr_flow = min(flow, e.C - e.flow);
      int temp_flow = sendFlow(e.v, curr_flow, t, start);
      if (temp_flow > 0)
      {
        e.flow += temp_flow;
        adj[e.v][e.rev].flow -= temp_flow;
        return temp_flow;
      }
    }
  }

  return 0;
}

int Graph::DinicMaxflow(int s, int t)
{
  if (s == t)
    return -1;
  int total = 0;
  while (BFS(s, t) == true) {
    int *start = new int[V+1] {0};
    while (int flow = sendFlow(s, INT_MAX, t, start))
    total += flow;
  }
  return total;
}

int cnt[26];
int numTest;

int main () {
  freopen("AC1.INP", "r", stdin);
  freopen("AC1.OUT", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    string A, B, T;
    cin >> A >> B >> T;
    int n = (int) A.size();
    int lenT = (int) T.size();
    Graph G(3 * 'Z' + n);
    int source = 0;
    int sink = 2 * 'Z' + n;
    for (int i = 1; i <= n; i++) {
      G.addEdge(source, i, 1);
    }
    for (int i = 1; i <= n; i++) {
      G.addEdge(i, (int) A[i - 1] + n, 1);
      G.addEdge(i, (int) B[i - 1] + n, 1);
    }
    for (int c = 0; c < 26; c++) {
      cnt[c] = 0;
    }
    for (int i = 0; i < lenT; i++) {
      cnt[T[i] - 'A']++;
    }
    for (int c = 0; c < 26; c++) {
      if (cnt[c] > 0) {
        G.addEdge(c + 'A' + n, sink, cnt[c]);
      }
    }
    if (G.DinicMaxflow(source, sink) == lenT) {
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
  return 0;
}