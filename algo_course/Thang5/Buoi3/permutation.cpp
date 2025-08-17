#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define MOD 1000000007
using namespace std;
typedef long long ll;

const int MAXN = 3005;
ll f[MAXN][MAXN], sum[MAXN][MAXN];
int n;
string s;

void initial()
{
    cin >> n >> s;
    f[1][1] = 1;
    sum[1][1] = 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    initial();

    FOR(i, 2, n)
    FOR(j, 1, i)
    {
        if (s[i - 2] == '<')
            f[i][j] = sum[i - 1][j - 1]; // nếu bài này làm tính f[i+1] thì phải tính f[i] mỗi lần
        else
            f[i][j] = (sum[i - 1][i - 1] - sum[i - 1][j - 1] + MOD) % MOD;
        sum[i][j] = (sum[i][j - 1] + f[i][j]) % MOD;
    }
    cout << sum[n][n] << "\n";
    return 0;
}

/*
PERMUTATION

cho chuỗi s gồm 2 dấu '>' và '<';

Đếm có bao nhiêu hoán vị gồm N + 1 số sao cho xét 2 số liền kề a[i] và a[i + 1], mối quan hệ giữa a[i] và a[i + 1] sẽ tương ứng với s[i]

Ví dụ:

s = "<><"

[1, 3, 2, 4]
[1, 4, 2, 3]
[2, 3, 1, 4]
[2, 4, 1, 3]
[3, 4, 1, 2]

==== > 5

gọi f[i][j] là số lượng hoán vị có i phần tử đầu tiên và phần tử cuối cùng là j

f[1][1] = 1

kết quả: tổng f[n][x] với x từ 1 đến n

Nếu s[i-2] là '<': f[i][j] = tổng f[i-1][x] với x từ 1 đến j-1
Nếu s[i-2] là '>': f[i][j] = tổng f[i-1][x] với x từ j đến i-1
*/