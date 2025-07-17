#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define xx first
#define yy second
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
int f[1005][1005][3]; // f[i][j][status]: xét i con bò đầu, chọn j con, trạng thái status
int n, K, B, T;
vector<pii> cows(1005); // (x, y)
void updateMin(int &a, int b)
{
    a = min(a, b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--)
    {
        cin >> n >> K >> B;
        // cows.resize(n + 1); // index từ 1

        for (int i = 1; i <= n; i++)
            cin >> cows[i].xx >> cows[i].yy;
        sort(cows.begin() + 1, cows.begin() + n + 1, [](pii cowa, pii cowb)
             { return (cowa.yy < cowb.yy || (cowa.yy == cowb.yy && cowa.xx < cowb.yy)); });
        // Khởi tạo f
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= K; j++)
                for (int state = 0; state < 3; state++)
                    f[i][j][state] = INF;

        // Base case: chọn con đầu tiên
        f[1][1][0] = 1;
        f[1][1][1] = 2;
        f[1][2][2] = 2;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= K; j++)
            {
                for (int state = 0; state <= 2; state++)
                {
                    if (f[i][j][state] == INF)
                        continue;
                    int cost = f[i][j][state];
                    // bò i + 1 thêm vào chuồng mới
                    updateMin(f[i + 1][j + 1][0], cost + 1);
                    updateMin(f[i + 1][j + 1][1], cost + 2);
                    updateMin(f[i + 1][j + 2][2], cost + 2);
                    // con bò i+1 cách con con bò y là dy
                    int dy = cows[i + 1].yy - cows[i].yy;
                    if (state == 0)
                    {
                        // nếu cùng hàng thêm bò i + 1 cùng chuồng cũ
                        if (cows[i].xx == cows[i + 1].xx)
                            updateMin(f[i + 1][j][0], cost + dy);
                        // thêm bò vào cùng chuồng cũ, hàng còn lại thêm 1 chuồng mới hoặc ngược lại
                        updateMin(f[i + 1][j + 1][2], cost + dy + 1);
                    }
                    else if (state == 1)
                        updateMin(f[i + 1][j][1], cost + 2 * dy);
                    else if (state == 2)
                    {
                        // thêm bò chuồng cũ, hàng còn lại chuồng mới
                        updateMin(f[i + 1][j + 1][2], cost + dy + 1);
                        if (cows[i].xx != cows[i + 1].xx)
                            updateMin(f[i + 1][j][0], cost + dy);
                        // thêm cả bò cả hàng còn lại chuồng cũ
                        updateMin(f[i + 1][j][2], cost + 2 * dy);
                    }
                }
            }
        }

        int result = INF;
        for (int s = 0; s <= 2; s++)
            updateMin(result, f[n][K][s]);
        cout << result << '\n';
    }

    return 0;
}
