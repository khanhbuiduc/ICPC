#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef long long ll;
ll f[1005][1005][2]; // 10^9 * 10^6
int cost[1005][1005];
int main()
{
    int step;
    cin >> step;
    for (int i = 1; i <= step; i++)
    {
        int n, m;
        cin >> n >> m;
        // Khởi tạo mảng f với giá trị lớn
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                for (int s = 0; s < 2; s++)
                    f[i][j][s] = 1e18;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> cost[i][j];
        for (int j = 1; j <= m; j++)
            f[0][j][1] = 0;
        for (int i = 1; i <= n; i++)
            f[i][0][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                f[i][j][0] = min(
                    f[i - 1][j][0],
                    f[i - 1][j][1] + cost[i][j]);
                f[i][j][1] = min(
                    f[i][j - 1][1],
                    f[i][j - 1][0] + cost[i][j]);
            }
        }
        cout << min(f[n][m][0], f[n][m][1]) << endl;
    }
}
/* chi phí c(xi, yi)
n=2 m=3
2 3 30
15 5 4
xaau T là xâu trộn giữa 2 xâu x là y:
    - Nếu: t[i], t[i+1] cùng thuộc 1 xâu: c=0
    - nếu t[i], t[i+1] khác xâu: c = (xi, yi);
gọi f[i][j][state] là giá trị nhỏ nhất khi trộn i kí tự của dãy x và j kí tự của dãy y với pt cuối là state
state: 0 là x
state: 1 là y

bài toán cơ sở:
    f[0][j][1] = 0; f[i][0][0] = 0;
    f[i][j][state] còn lại = inf
đáp án:
    min (f[n][m][0], f[n][m][1])
QHD:
    xét f[i][j][0];
    state = 0:  f[i][j][0] = min(f[i-1][j][0] , f[i-1][j][1] + cost[i][j]),
    state = 1: f[i][j][1] = min(f[i-1][j][1] , f[i-1][j][0] + cost[i][j])
*/