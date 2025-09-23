#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
int n, k;
pair<int, int> a[100'005];
ll fw[100'005][12], f[100'005][12];
void update(int index, int j, int val)
{
    for (; index <= 100'000; index += index & -index)
        fw[index][j] += val;
}
ll get(int index, int j) // trc index có bao nhiêu số < index.
{
    ll res = 0;
    for (; index > 0; index -= index & -index)
        res += fw[index][j];
    return res;
}
int main()
{
    cin >> n >> k;
    FOR(i, 1, n)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + n + 1);
    FOR(i, 1, n)
    {
        f[i][1] = 1;
    }
    FOR(j, 2, k)
    FOR(i, 1, n)
    {
        f[i][j] = get(a[i].second - 1, j - 1);
        update(a[i].second, j - 1, f[i][j - 1]);
    }
    long long ans = 0LL;
    for (int i = 1; i <= n; i++)
    {
        ans += f[i][k];
    }
    cout << ans;
}
/*
chọn k người: mỗi người có {rank_1,rank_2}
    elo A>elo B nếu:  A.rank1>B.rank1; A.rank2>b.rank2
có bao nhiêu cách chọn: k trong n người.
r1i, r2i là rank của từng người.

ans<2^63
------------------------------------------------------------
1 4
2 5
3 6
4 1
5 2
6 3
sort. theo rank 1.
QHD: gọi f[i][j]: số cách chọn
    - khi xét đến người thứ i
    - người i là người đc chọn cuối cùng.
    - hiện tại có j bạn được chọn.

bài toán cơ sở: f[0][0] =1

đáp án bài toán: Tổng của các f[i][k] với i: 1 -> n

Giả sử trước đó ta có một bạn x sao cho b[x] < b[i] :// đoạn này có thể cải tiến theo fenwick tree.
--------
    - f[i][j] = Tổng (f[x][j - 1]) với x < i và b[x] < b[i]
--------
f[x][j - 1]) = fw[b[i] -1][j]
*/