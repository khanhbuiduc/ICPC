#include <iostream>
#include <string>

using namespace std;
const int MAX_N = 25;

int numTest;
string a[MAX_N];
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool visited[MAX_N][MAX_N][12];

void dfs(int x, int y, int toxic) {
  visited[x][y][toxic] = true;
  for (int i = 0; i < 4; i++) {
    int nxtx = x + dx[i];
    int nxty = y + dy[i];
    if (nxtx >= 0 && nxtx < n && nxty >= 0 && nxty < m && a[nxtx][nxty] != '#') {
      int nxtToxic = toxic;
      if ('1' <= a[nxtx][nxty] && a[nxtx][nxty] <= '9') {
        nxtToxic += a[nxtx][nxty] - '0';
      }
      if (a[nxtx][nxty] == 'S') {
        nxtToxic = 0;
      }
      if (nxtToxic >= 10) {
        continue;
      }
      if (visited[nxtx][nxty][nxtToxic] == false) {
        dfs(nxtx, nxty, nxtToxic);
      }
    }
  }
}

int main () {
  freopen("SC5.INP", "r", stdin);
  freopen("SC5.OUT", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int value = 0; value < 10; value++) {
          visited[i][j][value] = false;
        }
      }
    }
    dfs(0, 0, 0);
    bool ans = false;
    for (int toxic = 0; toxic < 10; toxic++) {
      if (visited[n - 1][m - 1][toxic] == true) {
        ans = true;
        break;
      }
    }
    cout << (ans == true ? "possible" : "impossible") << endl;
  }
  return 0;
}