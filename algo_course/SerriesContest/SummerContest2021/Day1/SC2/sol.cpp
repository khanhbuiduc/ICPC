#include <iostream>
#include <fstream>

using namespace std;

const int MAX_N = 100005;
const long long MOD = 1000000007;
long long derangement[MAX_N];
int N, numTest;

void init() {
  derangement[0] = 1;
  derangement[1] = 0;
  for (int i = 2; i < MAX_N; i++) {
    derangement[i] = 1LL * (i - 1);
    (derangement[i] *= 1LL * (derangement[i - 1] + derangement[i - 2]) % MOD) %= MOD;
  }
}

int main () {
  freopen("SC2.INP", "r", stdin);
  freopen("SC2.OUT", "w", stdout);
  init();
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> N;
    cout << derangement[N] << endl;
  }
  return 0;
}