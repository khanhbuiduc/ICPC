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
    ll n, k, ans = 0;
    cin >> n >> k;
    if (n == 1)
    {
        cout << (k == 0 ? 0 : 6);
        return 0;
    }
    // vị trí có 3 mặt (góc): 8 ô
    ll n3 = 8;
    ll m = min(n3, k);
    ans += m * 3;
    k -= m;

    // vị trí có 2 mặt (cạnh): 12 * (n-2) ô
    ll n2 = 12 * (n - 2);
    m = min(n2, k);
    ans += m * 2;
    k -= m;

    // vị trí có 1 mặt (mặt): 6 * (n-2)^2 ô
    ll n1 = 6 * (n - 2) * (n - 2);
    m = min(n1, k);
    ans += m;
    k -= m;

    cout << ans;
}