#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m, n, s0;
int a[11];
int b[11];
queue<int> q;
// bfs
int dist[1'000'005];
void bfs()
{
    for (int i = 0; i <= m; i++)
        dist[i] = -1;
    dist[s0] = 0;
    q.push(s0);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 1; i <= n; i++)
        {
            int v = (1ll * u * a[i] + b[i]) % m;
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                if (v == 0)
                {
                    cout << dist[v];
                    exit(0);
                }
                q.push(v);
            }
        }
    }
}
int main()
{
    cin >> m >> n >> s0;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    bfs();
    cout << -1;
    return 0;
}
/*
MOVE:

Cho 2 day so nguyen a va b. Ban dau co mot gia trị S
Ta được phép thực hiện nhiều thao tác như sau:
    Chọn một vị trí i, lay S = (S * a[i] + b[i]) % M
Hoi sau toi thieu bao nhieu phep thì S se tro ve 0 hoac dua ra ket luan la khong the lam.

--------------------------
n m s
5 2 1
a b
2 1
3 1

a = [2, 3]
b = [1, 1]

Cho 2 dãy số nguyên a và b gồm N so. Ban đầu có một gia trị S

Ta được phép thực hiện nhiều thao tác như sau:

Chọn một vị trí i, lay S = (S * a[i] + b[i]) % M

Hoi sau toi thieu bao nhieu phep thì S se tro ve 0 hoac dua ra ket luan la khong the lam.

Khởi tạo dist[i] = -1 với mọi i: 0 -> M-1

đưa S vao hàng đợi

dist[S] =0

Lay đinh u ra khỏi hang đợi
duyệt mọi v kề u:
    for i: 1 -> n
        v = (u * a[i] + b[i]) % M
        neu dist[v] == -1:
            dist[v] = dist[u] +1
            đưa v vào hàng đợi.


*/