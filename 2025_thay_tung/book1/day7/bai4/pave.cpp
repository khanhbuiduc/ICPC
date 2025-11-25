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

    /*
    a*2 + (b-2)*2 = 6*2 + 7*2 = 12+14
    ----------------
    (a-2)*(b-2) = 4*7=28
    */
    int a, b;
    cin >> a >> b;
    cout << (a * 2 + (b - 2) * 2) << ' ' << (a - 2) * (b - 2);
}