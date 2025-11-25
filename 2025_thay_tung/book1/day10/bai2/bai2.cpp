#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
int a[200'005], b[200'005];
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr);
      // freopen("input.txt", "r", stdin);
      // freopen("output.txt", "w", stdout);
      vector<int> ans;
      int n, m;
      cin >> n;
      int sum = 0;
      int cnt = 0;
      FOR(i, 1, n)
      {
            cin >> a[i];
            sum += a[i];
      }
      cin >> m;
      //------------------------------
      FOR(i, 1, m) { cin >> b[i]; }
      FOR(i, 1, n)
      {
            if (a[i] <= 0)
                  ans.push_back(a[i]);
      }
      FOR(i, 1, n)
      {
            if (a[i] > 0)
                  ans.push_back(a[i]);
      }
      //------------------------------
      FOR(i, 1, m)
      {
            if (sum > b[i])
            {
                  cnt++;
            }
      }
      cout << cnt << endl;
      for (auto i : ans)
            cout << i << ' ';
}