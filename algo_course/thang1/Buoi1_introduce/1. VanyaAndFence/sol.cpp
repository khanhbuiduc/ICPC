#include <bits/stdc++.h>
using namespace std;
int main()
{
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int n, h, ai;
  cin >> n >> h;
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> ai;
    count += (ai > h ? 2 : 1);
  }
  cout << count;
}