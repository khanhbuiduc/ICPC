#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;
__int128_t num1 = 1;
const int MAXN = 1'000'000'5;
ll fact[MAXN], sum_fact[MAXN], sum_sum_fact[MAXN];
ll MOD_power(ll a, ll b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
void pre_caculator()
{
    fact[0] = sum_fact[0] = sum_sum_fact[0] = 1;
    FOR(i, 1, MAXN - 1)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
        sum_fact[i] = (sum_fact[i - 1] + fact[i]) % MOD;
        sum_sum_fact[i] = (sum_sum_fact[i - 1] + sum_fact[i]) % MOD;
    }
}

int main()
{
    pre_caculator();
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        ll s = fact[n];
        ll s1 = (2 * (sum_fact[n - 1]) - 1) % MOD;
        ll s2 = sum_sum_fact[n - 2];
        ll ans = (s - s1 + s2 + MOD) % MOD;
        cout << ans << endl;
    }
}
/*
    có mảnh đất  n*n.
    trồng n cây trên mảnh đất:
        - tồn tại đường đi
        - mỗi hàng 1 cây. mỗi cột một cây.
    ---------------------
    số cách trồng: s = n!
    số cách trồng mà chặn 1 đường chéo:
        s2 = 2 * (n - i)! + 1: i: 1->  n - 1
    số cách trồng mà chặn 2 đường chéo i,j:
        s3 = (n-i-j)! ; i+j<n
    kết quả s3= s - s2 - s3
-----------------------
tính n!
    tạo mảng fact[i]
----
tính tổng (n - i)! với i: 1 -> n - 1
    tạo bảng sumFact[i]
    s2 = 2*(sumFact[n-1]) + 1
tính tổng (n-i-j)! với i + j < n
    for i: 0->n-1;
         s3 += sumFact[n-1];
    tạo bảng sum2fact[i] với i: 0 -> 10'000'000
    s3 = sum2fact[n - 2];
-----------------------
*/