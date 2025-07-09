#include <bits/stdc++.h>
using namespace std;
const int INF = -1000000000;
int f[405][205][205];
int a[205][205];
int n, m;

bool check(int x1, int y1, int x2, int y2)
{
    // nếu không trùng nhau || hoặc là điểm gặp nhau ở [m,n] thì đúng
    // do đặt mảng lớn hơn cần thiết nhiều lên k cần kiểm tra biên
    if (x1 != x2)
        return true;
    if (x1 == n && y1 == m)
        return true;
    return false;
}

int value(int x1, int y1, int x2, int y2)
{
    return a[x1][y1] + a[x2][y2];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    // Khởi tạo
    int steps = n + m - 2;
    for (int i = 0; i <= steps; i++)
        for (int x1 = 1; x1 <= n; x1++)
            for (int x2 = 1; x2 <= n; x2++)
                f[i][x1][x2] = INF;
    f[0][1][1] = 0;

    // QHD
    for (int i = 0; i < steps; i++)
    {
        for (int x1 = 1; x1 <= n; x1++)
        {
            for (int x2 = x1; x2 <= n; x2++) // bình luôn dưới hàng an trừ điểm cuối và đầu
            {
                int y1 = i + 2 - x1;
                int y2 = i + 2 - x2;
                if (y1 < 1 || y2 < 1 || f[i][x1][x2] == INF)
                    continue;
                // An sang phải, Bình sang phải
                if (check(x1, y1 + 1, x2, y2 + 1))
                {
                    f[i + 1][x1][x2] = max(f[i + 1][x1][x2], f[i][x1][x2] + value(x1, y1 + 1, x2, y2 + 1));
                }
                // An xuống, Bình sang phải
                if (x1 + 1 <= x2 && check(x1 + 1, y1, x2, y2 + 1))
                {
                    f[i + 1][x1 + 1][x2] = max(f[i + 1][x1 + 1][x2], f[i][x1][x2] + value(x1 + 1, y1, x2, y2 + 1));
                }
                // An sang phải, Bình xuống
                if (check(x1, y1 + 1, x2 + 1, y2))
                {
                    f[i + 1][x1][x2 + 1] = max(f[i + 1][x1][x2 + 1], f[i][x1][x2] + value(x1, y1 + 1, x2 + 1, y2));
                }
                // An xuống, Bình xuống
                if (check(x1 + 1, y1, x2 + 1, y2))
                {
                    f[i + 1][x1 + 1][x2 + 1] = max(f[i + 1][x1 + 1][x2 + 1], f[i][x1][x2] + value(x1 + 1, y1, x2 + 1, y2));
                }
            }
        }
    }

    cout << f[steps][n][n] << endl;
    return 0;
}
/*

giới hạn: 1<N<M<200

--------------
nhận xét:
    - ae chỉ đi sang và xuống từ (1,1) -> (N,M)
        đi sang N-1 lần, đi xuống M-1 lần: tổng: N+M-2
    - cần lưu: f(xi,yi),(xj,yj) trong QHD: 4 chiều O(200^4)=O(1'600'000'000)
        - cải thiện: có số bước, hàng thì sẽ tính đc cột:
            x + y - 2 = step => y = step + 2 - x
        --> f[step][xi][xj]
    - xi>xj khi cùng step:

gọi: f[step][xA][xB] là số lượng nấm lớn nhất mà 2 ae an và bình thu thập đc sau step bước. An đang ở hàng xA và bình đang đứng ở hàng xB

bài toán cơ sở:
    f[0][1][1] = 0; các f[step][xA][xB] = -1 với mọi xA,xB
đáp án bài toán:
    f[N+M-2][n][m]
công thức quy hoạch động:
    khi f[step][xA][xB] != -1
    yA = step + 2 - (xA) và yB = step + 2 - (xB)
    case1: An sang phải(yA + 1 <= M && xA < xB):
        + bình sang phải (yB + 1<=M):
            f[step+1][xA][xB] = max(f[step+1][xA][xB], f[step][xA][xB] + a[xA][yA+1]+ a[xB][yB+1])
        + bình xuống dưới (xB + 1<= N):
            f[step+1][xA][xB+1] = max(f[step+1][xA][xB+1], f[step][xA][xB] + a[xA][yA+1]+ a[xB+1][yB])
    case2: An xuống dưới(xA+1<=N)
        + bình sang phải (yB+1<=M && (xA+1 < xB || step = N + M -3)):
            f[step+1][xA+1][xB] = max(f[step+1][xA+1][xB], f[step][xA][xB] + a[xA+1][yA]+ a[xB][yB+1])
        + bình xuống dưới (xB+1<= N && xA<xB):
            f[step+1][xA+1][xB+1] = max(f[step+1][xA+1][xB+1], f[step][xA][xB] + a[xA+1][yA]+ a[xB+1][yB])
*/