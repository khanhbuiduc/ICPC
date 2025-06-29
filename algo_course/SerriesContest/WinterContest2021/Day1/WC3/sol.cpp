#include <iostream> 
#include <vector>
#include <map> 
#include <fstream> 

using namespace std; 
const int MAX_N = 200005; 
int numTest; 
int n, B; 
int a[MAX_N][12]; 

int main () {
  freopen("WC3.INP", "r", stdin); 
  freopen("WC3.OUT", "w", stdout); 
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> B;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < B; j++) {
        cin >> a[i][j]; 
      }
    }
    map <vector <int>, int> cnt; 
    vector <int> base;
    vector <int> sum; 
    for (int i = 1; i < B; i++) {
      base.push_back(0);
      sum.push_back(0); 
    }
    sum.push_back(0); 
    cnt[base]++; 
    long long ans = 0LL; 
    for (int i = 1; i <= n; i++) {
      for (int b = 0; b < B; b++) {
        if (a[i][b] == 1) {
          sum[b]++; 
        }
      }
      base.clear();
      for (int b = 1; b < B; b++) {
        base.push_back(sum[b] - sum[b - 1]); 
      }
      ans += cnt[base]; 
      cnt[base]++;
    }
    cout << ans << endl;             
  }
  return 0; 
}