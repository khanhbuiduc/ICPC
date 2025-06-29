#include <iostream>
#include <fstream>

using namespace std;
const int MAX_N = 100005;
const long long MOD = 1000000007;
long long derangement[MAX_N];
long long fact[MAX_N], invFact[MAX_N];
int numTest, N;

long long POW(long long x, long long n) {
  if (n == 0) {
    return 1;
  }
  long long subProblem = POW(x, n >> 1);
  (subProblem *= subProblem) %= MOD;
  if (n & 1) {
    (subProblem *= x) %= MOD;
  }
  return subProblem;
}

void init() {
  fact[0] = 1;
  invFact[0] = 1;
  for (int i = 1; i < MAX_N; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
    invFact[i] = POW(fact[i], MOD - 2);
  }
  derangement[0] = 0;
  derangement[1] = 0;
  derangement[2] = 1;
  derangement[3] = 2;
  for (int i = 4; i < MAX_N; i++) {
    derangement[i] = 1LL * (i - 1) * (derangement[i - 1] + derangement[i - 2]) % MOD;
  }
}

long long C(int n, int k) {
  long long res = fact[n];
  (res *= invFact[k]) %= MOD;
  (res *= invFact[n - k]) %= MOD;
  return res;
}

int main () {
  freopen("SC3.INP", "r", stdin);
  freopen("SC3.OUT", "w", stdout);
  init();
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> N;
    long long res = C(N, N / 2);
    (res *= fact[N / 2]) %= MOD;
    (res *= derangement[N / 2]) %= MOD;
    cout << res << endl;
  }
  return 0;
}