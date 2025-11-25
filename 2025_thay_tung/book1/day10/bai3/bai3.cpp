#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
int a[400'005], x[400'005];
int l[400'005]; // vị trí xa nhất bên trái.
int cnt = 0;    // số phần tử bằng nhau tính đến thời điểm hiện tại
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    FOR(i, 1, n) { cin >> a[i]; }
    int m, k;
    cin >> m >> k;
    if (k == 0)
        k++;
    FOR(i, 1, m) { cin >> x[i]; }
    // solve
    l[1] = 1;
    cnt = 1;

    FOR(i, 2, n)
    {
        if (a[i - 1] < a[i])
        {
            l[i] = l[i - 1];
            cnt = 1;
        }
        else if (a[i - 1] > a[i])
        {
            l[i] = i;
            cnt = 1;
        }
        else // a[i - 1] == a[i]
        {
            cnt++;
            if (cnt <= k)
                l[i] = l[i - 1];
            else
            {
                l[i] = i - k + 1;
            }
        }
    }

    FOR(i, 1, m)
    {
        cout << l[x[i]] << ' ';
    }
    return 0;
}