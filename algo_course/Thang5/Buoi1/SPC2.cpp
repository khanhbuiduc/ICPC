#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define MAXN 100005
using namespace std;

const int inf = 200005;
int T, n, a[MAXN];
long long sumA[MAXN];
void initial()
{
    cin >> n;
    FOR(i, 1, n)
    cin >> a[i];
    sort(a + 1, a + n + 1);

    sumA[0] = 0;
    FOR(i, 1, n)
    sumA[i] = sumA[i - 1] + a[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--)
    {
        initial();
        long long S1 = sumA[n];
        long long S2 = 0;
        FOR(i, 2, n)
        {
            S2 += 2ll * (1ll * (i - 1) * a[i] - sumA[i - 1]);
        }
        long long nume = n;
        long long deno = S1 + S2;
        long long g = gcd(deno, nume);
        deno /= g;
        nume /= g;

        cout << deno << ' ' << nume << '\n';
    }

    return 0;
}
/*
1 ≤ ai ≤ 1000000.
T <= 40
Large Dataset: 1 ≤ N ≤ 100'000.
a=[2,3,5]
2 3 5 => |2-0| + |3-2| + |5-3|
2 5 3 => |2-0| + |5-2| + |5-3|
3 2 5 => |3-0| + |3-2| + |5-2|
3 5 2 => |3-0| + |5-3| + |5-2|
5 2 3 => |5-0| + |5-2| + |3-2|
5 3 2 => |5-0| + |5-3| + |3-2|

a ? ? ? ? ? ?
chọn ai ở vị trí đầu đóng góp: (n-1)! lần
    sumA = tổng a1->an
    s1 =  (n-1)! * sumA[n]
hỏi ai đi liền aj xuất hiện bao nhiêu lần: coi  ai, aj là 1 vị trí và xắp xếp
    |ai - aj| đóng góp  (n-1)! lần
    s2 = 2 * (n-1)!  * (tổng |ai,aj|) i: 2->n; j:1->i
    ta sort a rồi xét tổng thì sẽ bỏ đc trị tuyệt đối
    ta tính ai - aj
-----
vd: 1 2 3 5
2 - 1
3 - 1 + 3 - 2
5 - 1 + 5 - 2 + 5 - 3

sumA = [0,1,3,6,11]
for i: 2->n
    deno += (i-1)*a[i] - sumA[i-1]

avg * n! =  (n-1)! * sumA[n] + 2 * (n-1)!  * (tổng |ai,aj|)

avg = sumA[n] + 2 * (tổng |ai,aj|) / n
in ra tử số và mẫu số ở phân số tối giản.

O(N)
*/