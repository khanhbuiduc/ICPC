#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define lim 300'005 //
typedef pair<int, int> pii;
typedef long long ll;
int f[100'005][3];
int a[100'005], b[100'005], c[100'005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    // btcs
    f[1][0] = a[1];
    f[1][1] = b[1];
    f[1][2] = c[1];

    for (int i = 2; i <= n; i++)
    {
        f[i][0] = max(f[i - 1][1], f[i - 1][2]) + a[i];
        f[i][1] = max(f[i - 1][0], f[i - 1][2]) + b[i];
        f[i][2] = max(f[i - 1][0], f[i - 1][1]) + c[i];
        // cout << f[i][0] << " " << f[i][1] << " " << f[i][2] << endl;
    }
    // đáp án
    cout << max(f[n][0], max(f[n][1], f[n][2]));
}

/*
N=3
a1=10 b1=0 c1=70
20 50 80
30 60 90

gọi f[i][j] là điểm hạnh phúc cao nhất của ngày thứ i chơi game j
game 0,1,2 lần

bài toán cơ sở:
    f[1][0] = a[1],
    f[1][1] = b[1],
    f[1][2] = c[1],

đáp án: max(f[n][0], f[n][1], f[n][2])

công thức hồi quy:
    f[i][0] = max(f[i-1][1],f[i-1][2]) + a[i];
    f[i][1] = max(f[i-1][0],f[i-1][2]) + b[i];
    f[i][2] = max(f[i-1][0],f[i-1][1]) + c[i];

*/
