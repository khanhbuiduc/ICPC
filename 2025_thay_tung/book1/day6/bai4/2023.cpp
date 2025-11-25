#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
typedef __int128 lll;
lll mod = 1e22;
// lll powerMod(lll a, lll b)
// {
//     lll res = 1;
//     while (b > 0)
//     {
//         if (b & 1) // lẻ
//         {
//             (res *= (a)) %= mod;//res= 10^22, a = 10^22 =>10^44 lỗi.
//         }
//         b >>= 1;
//         (a *= a) %= mod;
//     }
//     return (res);
// }
void print128(lll x)
{
    string s = "";
    FOR(i, 1, 22)
    {
        s = char('0' + (x % 10)) + s, x /= 10;
    }
    cout << s << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n;
    cin >> n;
    lll res = 1;
    lll b = n;
    FOR(i, 1, 2023) { (res = (b * res) % mod); }
    print128(res);
    // print128(mod);
    cout << "Time: " << clock() / (double)1000000 << " set";
}
/*
n^2023 = n^2023 mod (10^22)
n < 10^16
*/