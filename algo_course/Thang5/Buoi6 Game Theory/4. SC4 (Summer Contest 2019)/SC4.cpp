#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define MOD 1000000007
using namespace std;
typedef long long ll;

const int MAXN = 55;
int f[55][55][55];
int n, m;

void initial()
{
    cin >> n >> m;
    FOR(i, 0, n)
    FOR(a, 0, n)
    FOR(c, 0, n)
    {
        f[i][a][c] = 0;
    }
}

int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        initial();

        FOR(i, 1, n)
        FORD(c, i, 0)
        FOR(a, 0, c)
        {
            if (c == i)
            {
                f[i][a][c] = f[a][0][0];
                continue;
            }
            int seed_b = 55;
            FOR(x, 1, min(m, i - c))
            {
                seed_b = min(seed_b, f[i][c - a][c + x]);
            }
            f[i][a][c] = i - seed_b;
        }
        cout << f[n][0][0] << endl;
    }

    return 0;
}

/*
f[i][a][b+a] là số lượng hạt zẻ mà người hiện tại có thể ăn được.
    bát a: a hạt
    bát b: B hạt

btcs: f[0][0][0] = 0

kết quả: f[n][0][0];

----------------
a+b==i; a không bốc đc
    (i,a,b) -> (a,0,0)
----------------
a+b<i và a bốc: x: 1-> min(m, i-b-a)

    seed_b = min(f[i][b][a+x]) hạt
    f[i][a][b] = i - seed_b

for i: 1 -> N
for a: 0 -> i
for b: 0 -> i - a

nhưng tính f[i][b][a+x] đến f[i][a][b]
    cách này không biết rõ đã tính đc f[i][b][a+x] chưa

    //////////////////////////////////
thay đổi f
f[i][a][c] là số lượng hạt zẻ mà người hiện tại có thể ăn được.
    bát a: a hạt
    bát c: a+b hạt


btcs: f[0][0][0] = 0

kết quả: f[n][0][0];

QHĐ:
c = i:
    f[i][a][c] = f[a][0][0];
c<i và người hiện tại bốc x: 1-> min(m,i-c);
    seed_b = min(f[i][c-a][c+x])
    f[i][a][c] = i - seed_b;

for i: 1 -> N
    for c: i -> 0
        for a: 0 -> c
            nếu c == i:
                f[i][a][c]= f[a][0][0]
            else:
                for x: 1 -> min(M, i - c)
                    seed_b = min(seed_b, f[i][c - a][c +x])
                f[i][a][c]= i - seed_b
*/