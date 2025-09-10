#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef long long ll;
int maxProfit(int k, vector<int> &prices)
{
    int f[1'005][105][2]; // 10^3 * 10^3 = 10^6
    int n = (int)prices.size();
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
        {
            f[i][j][0] = -1e9;
            f[i][j][1] = -1e9;
        }
    f[1][0][0] = 0;
    f[1][1][1] = 0;
    for (int i = 1; i < n; i++)
        for (int j = 0; j <= k; j++)
            for (int state = 0; state <= 1; state++)
            {
                if (f[i][j][state] == -1e9)
                    continue;
                f[i + 1][j][0] = max(f[i + 1][j][0], f[i][j][state]);
                if (state == 1)
                    f[i + 1][j][1] = max(f[i + 1][j][1], f[i][j][state] + (prices[i + 1 - 1] - prices[i - 1]));
                f[i + 1][j + 1][1] = max(f[i + 1][j + 1][1], f[i][j][state] + 0);
            }
    int res = -1e9;
    for (int j = 0; j <= k; j++)
        for (int state = 0; state <= 1; state++)
            res = max(res, f[n][j][state]);
    return res;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    cout << maxProfit(k, prices);
}

/*
k giao dịch(1 sell-1stock) k phủ nhau
price[i] là giá cổ phiếu ở năm i
n=5,k=2
5 8 2 1 10
nhận xét:
    mua năm 3 bán năm 5: p[5] - p[3] = 8
    mua năm 3 bán năm 6: p[6] - p[5] + p[5] - p[3]
    ==> bán năm x, mua năm i+1
        p[i+1] - p[x] = (p[i] - p[x]) + (p[i+1] - p[i])
    gọi f[i][j][state] là max lợi nhuận tính đến năm i vs j giao dịch, năm i đang trong trạng thái state:
        state = 0: k trong giao dịch
        state = 1: đang trong giao dịch và tạm chấp nhận năm hiện tại là bán
    bài toán cơ sở:
        f[1][0][0] = 0;
        f[1][1][1] = 0;
        f[i][j][state] = -inf;
    đáp án bài toán:
        f[n][j][state]: j:0->k; state: 0->1
    công thức quy hoạch động:(f[i][j][state] != -inf)
        nếu năm i+1 k trong giao dịch:
            f[i+1][j][0] = max(f[i+1][j][0], f[i][j][state])
        nếu năm thứ i+1 nằm trong giao dịch hiện tại(state=1):
            f[i+1][j][1] = max(f[i+1][j][1], f[i][j][state] + (prices[i+1] - prices[i]))
        nếu năm thứ i+1 nằm trong giao dịch mới:
            f[i+1][j+1][1] = max(f[i+1][j+1][1], f[i][j][state] + 0)


*/