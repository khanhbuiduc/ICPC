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
    int n, a, b;
    char dummy;
    cin >> n >> a >> dummy >> b;
    string ans = "";
    int maxMoney = -1;
    FOR(i, 1, n)
    {
        string mi;
        int ei, xi;
        cin >> mi >> ei >> dummy >> xi;
        int curMoney = ei * 100 + xi;
        if (maxMoney > curMoney || a < ei || b < xi)
        {
            continue;
        }
        ans = mi;
        maxMoney = curMoney;
    }
    cout << (maxMoney == -1 ? "-1" : ans);
}
/*
tiền: eq, xu
1 eq = 100 coin
{name,c_eq,c_coin}
máy chỉ luốt tiền.
tên gói to nhất mà alice có thể mua
*/