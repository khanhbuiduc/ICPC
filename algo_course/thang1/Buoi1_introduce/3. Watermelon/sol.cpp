#include <bits/stdc++.h>
using namespace std;
int main()
{
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int n;
  cin >> n;
  cout << ((n & 1 || n == 2) ? "NO" : "YES");
  return 0;
}