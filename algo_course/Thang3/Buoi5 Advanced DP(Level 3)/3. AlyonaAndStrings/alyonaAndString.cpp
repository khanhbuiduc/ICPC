#include <bits/stdc++.h>
using namespace std;

int f[1005][1005][13][2];
int m, n, k;
string s, t; // index từ 0
void maxString(int &a, int b)
{
    a = max(a, b);
}
int main()
{
    cin >> m >> n >> k;
    cin >> s >> t;
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            for (int groups = 0; groups <= k; groups++)
                for (int state = 0; state <= 1; state++)
                    f[i][j][groups][state] = -1;
    // btcs
    f[0][0][0][0] = 0;
    // quy hoạch động
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            for (int groups = 0; groups <= k; groups++)
                for (int state = 0; state <= 1; state++)
                {
                    if (f[i][j][groups][state] == -1)
                        continue;
                    maxString(f[i + 1][j][groups][0], f[i][j][groups][state]);
                    maxString(f[i][j + 1][groups][0], f[i][j][groups][state]);
                    if (s[i + 1 - 1] == t[j + 1 - 1])
                    {
                        maxString(f[i + 1][j + 1][groups + 1][1], f[i][j][groups][state] + 1);
                        if (state == 1)
                            maxString(f[i + 1][j + 1][groups][1], f[i][j][groups][state] + 1);
                    }
                }
    // kết quả
    int res = -1;
    // for (int groups = 0; groups <= k; groups++)
    for (int state = 0; state <= 1; state++)
        maxString(res, f[m][n][k][state]);
    cout << res;
}

/*
m=3 n=2 k=2
abc
ab
Gọi f[i][j][groups][state] là tổng số lượng ký tự lớn nhất khi co i ký tự đau tiên của chuỗi S, ký tự đau tiên của chuỗi T và số nhóm là groups, cùng trạng thái state:
    - state = 1: Ký tự S[i] và T[j] bằng nhau và chung cùng ở trong 1 nhom tương ứng.
    - state = 0: Trong những trường hợp còn lại.
bài toán cơ sở:
    - f[i][j][groups][state] = -1
    - f[0][0][0][0] = 0

đáp án bài toán: Max(f[N][M][K][0], f[N][M][K][1])

công thức qh:

Khi ta co f[i][j][groups][state] != -1
    Ta bỏ qua ký tự thứ i+1:
        f[i+1][j][groups][0] = max(f[i+1][j][groups][0], f[i][j][groups][state])

    Ta bỏ qua ký tự thứ j+1:
        f[i][j+1][groups][0] = max(f[i][j+1][groups][0], f[i][j][groups][state])

    Nếu S[i+1] == T[j+1]:
        Ta có thể cho S[i+1] và T[j+1] vào nhóm mới:
            f[i+1][j+1][groups+1][1] = max(f[i+1][j+1][groups+1][1], f[i][j][groups][state] +1)
        Nếu state = 1
            f[i+1][j+1][groups][1] = max(f[i+1][j][groups][1], f[i][j][groups][state] +1);
f[n][m][10][2]: 1000*1000*10*2: O(n*m*k*state)= 20 trẹo:
không gian  O(80 trẹo)
*/