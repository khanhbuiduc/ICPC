#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define MOD 2111992
using namespace std;
typedef long long ll;
__int128_t num1 = 1;
const int MAXN = 100'005;
ll f[100'005]; // K <= 100'000
ll fact[MAXN], inv_fact[MAXN];
int n, k;

void initial()
{
    cin >> n >> k;
    FOR(i, 0, k)
    f[i] = i + 1;
}

int main()
{
    initial();
    FOR(i, k + 1, n)
    f[i] = (f[i - 1] + f[i - k - 1]) % MOD;
    cout << f[n];
}

/*
cnt bull

Có bao nhiêu cách xếp N con bò, mỗi con có thể chọn là đực hoặc cái và căn thoa măn điều kiện: Giữa 2 con đực phải có ít nhất K con cái.
N - 5, K - 3

ccccc
DCCCC
CDCCC
CCDCC
CCCDC
CCCCD
DCCCD

gọi f[i] là số cách đặt bò khi có i bò
bài toán cơ sở: f[i] = i + 1 nếu i <= K + 1

đáp án bài toán: f[n]

DHD:
    f[i] là bò cái f[i] = f[i - 1]
    f[i] là bò đực f[i] = f[i - k - 1];
    f[i] = f[i - 1] + f[i - k - 1];
*/