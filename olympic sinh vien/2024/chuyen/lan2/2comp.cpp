#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
ll a[100'005];
vector<int> pow2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    FOR(i, 1, n)
    cin >> a[i];
    ll ans = 0;
    FOR(i, 1, n)
    {
        // bit 1 của n chính là bit 1 của i - 1 thì lẻ
        if ((~((n - 1)) & (i - 1)) == 0)
        {

            ans ^= a[i];
        }
    }

    cout << ans;
}
/*
n= 1: 1
n= 2: 1 1
n= 3: 1   1
n= 4: 1 1 1 1
n= 5: 1       1
---------
nếu chẵn bỏ qua
nếu lẻ tính là 1 số:
khi nào C(k-1,n-1) lẻ khi: bit 1 trong k chính là bit 1 trong n
((~(n-1)) ^ (k-1)) == 0 thì lẻ
*/