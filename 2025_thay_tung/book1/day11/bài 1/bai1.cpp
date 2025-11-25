#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, k, m;
        cin >> a >> b >> k >> m;
        ll dental = k * k + 4 * (k - m + 1);
        if (dental < 0)
        {
            cout << -1 << endl;
            continue;
        }
        ll d = sqrt(dental);
        if (d * d != dental)
        {
            cout << -1 << endl;
            continue;
        }
        ll x1, x2, y1, y2;
        x1 = (k - d) / 2, y1 = k - x1;
        x2 = (k - d) / 2, y2 = k - x2;
        if (x1 * 2 != k - d)
        {
            cout << -1 << endl;
            continue;
        }
        if (0 <= x1 && x1 <= a && 0 <= y1 && y1 < b)
        {
            cout << x1 << ' ' << y1 << endl;
        }
        else if (0 <= x2 && x2 <= a && 0 <= y2 && y2 < b)
        {
            cout << x2 << ' ' << y2 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}
/*
1 2 3 4 5 9

for(i,1,n){

}
*/