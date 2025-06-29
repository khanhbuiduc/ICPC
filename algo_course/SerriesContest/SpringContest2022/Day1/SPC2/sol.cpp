#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 2000005; 
const long long MOD = 1000000007;

priority_queue <long long, vector <long long>, greater <long long> > pq;  
bool isPrime[MAX_N];
long long ans[MAX_N]; 

void erathones() {
  for (int i = 2; i < MAX_N; i++) {
    isPrime[i] = true; 
  }
  for (int i = 2; i * i < MAX_N; i++) {
    if (isPrime[i] == false) {
      continue; 
    }
    for (int j = i * i; j < MAX_N; j += i) {
      isPrime[j] = false;
    }
  }
  for (int i = 2; i < MAX_N; i++) {
    if (isPrime[i] == true) { 
      pq.push((long long) i); 
    }
  }                                 
} 

void init() {
  ans[0] = 1LL;
  for (int i = 1; i <= 100000; i++) {
    long long value = pq.top();
    pq.pop();
    pq.push(value * value); 
    ans[i] = (ans[i - 1] * value) % MOD; 
  }  
}

int main () {
  freopen("SPC2.INP", "r", stdin);
  freopen("SPC2.OUT", "w", stdout);
  erathones(); 
  init(); 
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    cin >> n;
    cout << ans[n] << endl; 
  }
  return 0; 
}