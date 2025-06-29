#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
#include <fstream>

using namespace std;
const int MAX_V = 100005;
const int MAX_N = 55;
int dep[MAX_V];
long long dp[2][MAX_N][MAX_N][MAX_N];
long long C[MAX_N][MAX_N];
bool check[MAX_N];
struct element {
  int type;
  int depth;
  bool operator < (const element &other) const {
    return (type < other.type || (type == other.type && depth < other.depth));
  }
};
vector <element> listBuilding;
vector <int> found;
vector <int> type;
vector <int> depth;
int n, k, m;
int numTest;

void update(long long &a, long long value) {
  a += value;
}

void init() {
  for (int i = 0; i <= n; i++) {
    C[i][0] = 1LL;
    C[i][i] = 1LL;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
  memset(dp, 0, sizeof(dp));
  memset(check, false, sizeof(check));
  found.resize(m, 0);
  depth.resize(n, 0);
  type.resize(n, 0);
  listBuilding.clear();
}

void preProcess() {
  for (int i = 0; i < m; i++) {
    check[found[i]] = true;
  }
  set <int> S;
  for (int i = 0; i < n; i++) {
    S.insert(depth[i]);
  }
  int cnt = 0;
  for (set <int> :: iterator it = S.begin(); it != S.end(); it++) {
    int value = *it;
    cnt++;
    dep[value] = cnt;
  }
  for (int i = 0; i < n; i++) {
    listBuilding.push_back((element) {type[i], dep[depth[i]]});
  }
  sort(listBuilding.begin(), listBuilding.end());
  sort(found.begin(), found.end());
}

long long dynamicProgramming() {
  dp[0][0][0][0] = 1LL;
  for (int numBuild = 0; numBuild <= n; numBuild++) {
    int now = numBuild & 1;
    int nxt = !now;
    memset(dp[nxt], 0, sizeof(dp[nxt]));
    for (int numType = 0; numType <= m; numType++) {
      for (int numChoose = 0; numChoose <= k; numChoose++) {
        for (int maxDepth = 0; maxDepth <= n; maxDepth++) {
          if (dp[now][numType][numChoose][maxDepth] == 0) {
            continue;
          }
          long long curValue = dp[now][numType][numChoose][maxDepth];
          update(dp[nxt][numType][numChoose][maxDepth], curValue);
          if (numType < m && listBuilding[numBuild].type == found[numType]) {
            int newDepth = max(listBuilding[numBuild].depth, maxDepth);
            update(dp[nxt][numType + 1][numChoose + 1][newDepth], curValue);
          }
          if (numType > 0 && listBuilding[numBuild].type == found[numType - 1]) {
            int newDepth = maxDepth;
            update(dp[nxt][numType][numChoose + 1][newDepth], curValue);
          }
        }
      }
    }
  }
  long long ans = 0LL;
  for (int maxDepth = 1; maxDepth <= n; maxDepth++) {
    for (int numChoose = m; numChoose <= k; numChoose++) {
      if (dp[n & 1][m][numChoose][maxDepth] == 0) {
        continue;
      }
      int cntValids = 0;
      for (int i = 0; i < n; i++) {
        if (check[listBuilding[i].type] == false && listBuilding[i].depth > maxDepth) {
          cntValids++;
        }
      }
      if (k - numChoose > cntValids) {
        continue;
      }
      ans += dp[n & 1][m][numChoose][maxDepth] * C[cntValids][k - numChoose];
    }
  }
  return ans;
}

int main () {
  freopen("SC6.INP", "r", stdin);
  freopen("SC6.OUT", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> k >> m;
    init();
    for (int i = 0; i < n; i++) {
      cin >> type[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> depth[i];
    }
    for (int i = 0; i < m; i++) {
      cin >> found[i];
    }
    preProcess();
    long long res = dynamicProgramming();
    cout << res << endl;
  }
  return 0;
}