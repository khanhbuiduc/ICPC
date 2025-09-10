#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MAX = 70'005;
int c[10] = {0, 1, 2, 5, 10, 20, 50, 100, 200, 500};
int a[10], b[10];
// DP tables
int f_max[10][70'005];
int f_min[10][70'005];

void minCacul(int &a, int b)
{
    a = min(a, b);
}

void maxCacul(int &a, int b)
{
    a = max(a, b);
}

int main()
{
    int T;
    cin >> T;
    for (int step = 1; step <= T; step++)
    {
        int C, totalBillA = 0, totalBillB = 0;
        cin >> C;
        C = C / 1000;

        for (int i = 1; i <= 9; i++)
        {
            string dummy;
            cin >> dummy >> a[i] >> b[i];
            totalBillA += a[i];
            totalBillB += b[i];
        }

        // Khởi tạo DP tables
        for (int i = 0; i <= 9; i++)
            for (int j = 0; j <= 70'000; j++)
            {
                f_max[i][j] = -INF;
                f_min[i][j] = INF;
            }

        // Base case
        f_max[0][0] = 0;
        f_min[0][0] = 0;

        // DP for max bills paid (người mua đưa nhiều tờ nhất có thể)
        for (int i = 0; i < 9; i++)
            for (int j = 0; j <= 70'000; j++)
            {
                if (f_max[i][j] == -INF)
                    continue;
                for (int x = 0; x <= a[i + 1]; x++)
                    maxCacul(f_max[i + 1][j + x * c[i + 1]], f_max[i][j] + x);
            }

        // DP for min bills returned (người bán đưa ít tờ tiền nhất có thể)
        for (int i = 0; i < 9; i++)
            for (int j = 0; j <= 70'000; j++)
            {
                if (f_min[i][j] == INF)
                    continue;
                for (int x = 0; x <= b[i + 1]; x++)
                    minCacul(f_min[i + 1][j + x * c[i + 1]], f_min[i][j] + x);
            }

        // Tìm kết quả tối ưu
        int res = INF;
        for (int payment = C; payment <= 70'000; payment++)
        {
            int change = payment - C;
            if (f_max[9][payment] == -INF || f_min[9][change] == INF)
                continue;

            // Số tờ tiền cuối cùng = số tờ ban đầu - số tờ đưa ra + số tờ nhận lại
            int finalBills = totalBillA - f_max[9][payment] + f_min[9][change];
            minCacul(res, finalBills);
        }

        if (res == INF)
            cout << "SORRY!!!" << endl;
        else
            cout << res << endl;
    }
    return 0;
}
/*
tờ tiền:[]
c[1,2,5,10,20,50,100,200,500]
người mua: [{a1:1}, {a2:2}, {a3:5}, {a4:10}, {a5:20}, {a6:50}, {a7:100}, {a8:200},{a9:500}];
người bán: [{b1:1}, {b2:2}, {b3:5}, {b4:10}, {b5:20}, {b6:50}, {b7:100}, {b8:200},{b9:500}];

người mua muốn sở hữu ít tờ tiền nhất, thanh toán nhiều nhất
người bán muốn sở hữu nhiều tờ nhất, trả lại ít nhất

gọi f_max[i][j] là số tờ tiền tối đa khi có i mệnh giá và tổng tiền j

bài toán cơ sở:
    f_max[0][0] = 0;
    f_max[i][j] = -INF;
QHD:
    xét mệnh giá thứ i (f_max[i][j] != -INF
        mệnh giá i+1 có a[i+1] tờ
        ta sử dụng x tờ tiền: 0->a[i+1]
            f_max[i+1][j + x*c[i+1]] = max(f_max[i+1][j + x*c[i+1]], f_max[i][j] + x);
-----------
người bán trả lại ít tờ nhất
gọi f_max[i][j] là số tờ tiền tối đa khi có i mệnh giá và tổng tiền j
bài toán cơ sở:
    f_min[0][0] = 0;
    f_min[i][j] = INF;
QHD:
    xét mệnh giá thứ i (f_min[i][j] != -INF)
        mệnh gái i+1 có b[i+1] tờ tiền
        ta sử dụng x tờ tiền: 0->b[i+1]
             f_min[i+1][j + x*c[i+1]] = max(f_min[i+1][j + x*c[i+1]], f_min[i][j] + x);
--------------
người mua trả: x đồng(x>=c), người bán trả lại X-C đồng

tổng số tờ tiền: amount_bill= a1+...a9;
tổng số tiền trong túi sau khi mua bán: amount_bill - f_min[9][X] + f[9][X-C]; X: c-> tổng tiền
*/