#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;
__int128_t num1 = 1;
const int MAXN = 2000005;
ll sum[105][100'005], f[105][100'005]; // N <= 100, K <= 100'000

int a[105];
ll fact[MAXN], inv_fact[MAXN];
int n, k;
void initial()
{
    cin >> n >> k;
    FOR(i, 1, n)
    cin >> a[i];
    f[0][0] = 1;
    FOR(j, 0, k)
    {
        sum[0][j] = 1;
    }
}
int main()
{
    initial();
    FOR(i, 1, n)
    {
        FOR(j, 0, k)
        {
            int r = j, l = max(j - a[i], 0);
            f[i][j] = (sum[i - 1][r] - sum[i - 1][l - 1] + MOD) % MOD;
            sum[i][j] = (sum[i][j - 1] + f[i][j]) % MOD;
        }
    }
    cout << f[n][k];
}
/*
Candies:

N chidren, k candies. child i nhận [0,a[i]]

đếm số cách chia kẹo, số kẹo phải chia hết.

Gọi f[i][j] là số cách để chia j viên kẹo cho i đứa trẻ đầu tiên

bài toán cơ sở: f[0][0] = 1

QHD: Tính f[i][j]

Khi ta chia x viên kẹo cho bạn thứ i (0 <= x <= a[i], x <= j)
    f[i][j] =   f[i - 1][j] + f[i - 1][j - 1] + f[i - 1][j - 2] + ..... + f[i - 1][j - min(j, a[i])]

=>Đặt sum[i][j] = tổng f[i][0] + f[i][1] + f[i][2] + ..... + f[i][j]

----------------------------------------------------
khởi tạo: f[0][0]=1

xây dựng sum[0][j] = sum[0][j - 1] + f[0][j]

Đặt r = j, đặt L = j - min(j, a[i])

    f[i][j]= (sum[i - 1][r] - sum[i - 1][l - 1])
    sum[i][j] = sum[i][j - 1] + f[i][j]
-----------------------------

Độ phức tập: 0(N * M)
*/