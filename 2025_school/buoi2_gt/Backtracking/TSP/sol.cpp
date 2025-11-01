#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
const int INF = 1e9;

int n, m;
int c[25][25];
int x[25];        // hành trình
bool visited[25]; // đánh dấu
int ans = INF;
int cost_now = 0;
int cmin = INF;

void Try(int i)
{
    // i: đang chọn thành phố thứ i trong hành trình
    for (int j = 2; j <= n; j++)
    { // duyệt thành phố tiếp theo
        if (!visited[j] && c[x[i - 1]][j] < INF)
        {
            x[i] = j;
            visited[j] = true;
            cost_now += c[x[i - 1]][j];

            if (i == n)
            { // đã đi hết
                if (c[x[n]][1] < INF)
                    ans = min(ans, cost_now + c[x[n]][1]);
            }
            else
            {
                // Nhánh cận
                int lower_bound = cost_now + (n - i + 1) * cmin;
                if (lower_bound < ans)
                    Try(i + 1);
            }

            // Quay lui
            visited[j] = false;
            cost_now -= c[x[i - 1]][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    // khởi tạo
    FOR(i, 1, n)
    FOR(j, 1, n)
    c[i][j] = INF;

    FOR(k, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        c[u][v] = min(c[u][v], w);
        cmin = min(cmin, w);
    }

    x[1] = 1;
    visited[1] = true;
    Try(2);

    cout << ans << '\n';
}
