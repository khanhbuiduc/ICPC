#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;
__int128_t num1 = 1;
const int MAXN = 3005;
double f[MAXN][MAXN]; // N <= 100, K <= 100'000
double p[MAXN];
int n;
void initial()
{
    cin >> n;
    FOR(i, 1, n)
    cin >> p[i];
    f[0][0] = 1;
}
int main()
{
    initial();
    FOR(i, 0, n)
    FOR(j, 0, i)
    {
        if (f[i][j] == 0)
            continue;
        f[i + 1][j + 1] += f[i][j] * p[i + 1];
        f[i + 1][j] += f[i][j] * (1 - p[i + 1]);
    }
    double ans = 0;
    FOR(j, (n + 1) / 2, n)
    {
        ans += f[n][j];
    }
    cout << fixed << setprecision(9) << ans;
}
/*
có n đồng xu với đồng xu i có xác suất: pi mặt ngửa

xác xuất để mặt ngửa nhiều hơn mặt xấp.

f[i][j]: có xét đồng xu thứ i, có j mặt ngửa

f[0][0] = 1;

QHD: xét đồng xu i
    i+1 ngửa: f[i+1][j+1] += f[i][j] * p[i+1];
    i+1  úp: f[i+1][j] += f[i][j] * (1-p[i+1]);

kết quả: tổng f[n][j] với 2*j > n;
*/