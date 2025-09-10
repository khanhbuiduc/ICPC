
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define lim 300'005 //
typedef pair<int, int> pii;
typedef long long ll;
int f[60'005], t[60'005], r[60'005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    for (int i = 1; i <= n; i++)
        cin >> r[i];
    // btcs:
    f[1] = t[1];
    f[2] = min(t[1] + t[2], r[1]);
    // công thức truy hồi
    for (int i = 3; i <= n; i++)
    {
        f[i] = min(f[i - 1] + t[i], f[i - 2] + r[i - 1]);
    }
    cout << f[n];
}

/*

n=5
ti=2 5 7 8 4
ri=4 9 10 10

gọi f[i] là thời gian ngắn nhất để i người mua vé:

bài toán cơ sở: f[1] =t[1]; f[2] = min(t[1] + t[2], r[1])

đáp án: f[n]

công thức truy hồi:
    - f[i] =
        case 1: người i mua vé: f[i] = f[i-1] + t[i];
        case 2: người i nhờ i-1 mua vé: f[i] = f[i-2] + r[i-1];
        ====> f[i] = min (f[i-1] + t[i] , f[i-2] + r[i]);

*/