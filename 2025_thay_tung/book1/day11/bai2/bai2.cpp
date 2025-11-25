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
    int n, t, m, x, y;
    cin >> n >> t >> m >> x >> y;
    // cnt time
    double cnt = (double)m / x + (double)(n - m) / y;
    ll ans = (ll)((cnt + 59) / 60) - t;
    cout << max(0ll, ans);
    clock_t end = clock();
}
/*
t phút:
path của bot: n mét
m(mét) đầu: v1= x (m/s)
đoạn còn lại v2<=y (m/s)
*/