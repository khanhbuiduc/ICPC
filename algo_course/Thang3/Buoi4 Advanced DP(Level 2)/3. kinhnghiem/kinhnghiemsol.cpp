#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 205;
const int INF = 1e9;

int N, M;
int board[MAX_N][MAX_N];
int dp[MAX_N * 2][MAX_N][MAX_N];

int main()
{
    // Đọc input
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> board[i][j];
        }
    }

    // Khởi tạo mảng dp với giá trị âm vô cực
    for (int k = 0; k <= N + M - 2; k++)
    {
        for (int x1 = 1; x1 <= N; x1++)
        {
            for (int x2 = 1; x2 <= N; x2++)
            {
                dp[k][x1][x2] = -INF;
            }
        }
    }

    // Khởi tạo trạng thái ban đầu: An và Bình ở (1,1)
    dp[0][1][1] = 0;

    // Quy hoạch động
    for (int k = 0; k < N + M - 2; k++)
    {
        for (int x1 = 1; x1 <= N; x1++)
        {
            for (int x2 = 1; x2 <= N; x2++)
            {
                if (dp[k][x1][x2] == -INF)
                    continue;

                int y1 = k - x1 + 2; // Cột của An
                int y2 = k - x2 + 2; // Cột của Bình

                // Kiểm tra xem vị trí có hợp lệ
                if (y1 < 1 || y1 > M || y2 < 1 || y2 > M)
                    continue;

                // Kiểm tra xem An và Bình có ở cùng ô không (trừ ô (N,M))
                if (x1 == x2 && y1 == y2 && !(x1 == N && y1 == M))
                    continue;

                // Tính điểm tại ô hiện tại
                int score = board[x1][y1];
                if (x1 != x2 || y1 != y2)
                    score += board[x2][y2]; // Cộng điểm của Bình nếu không trùng ô

                // Các hướng di chuyển
                int dx[] = {0, 1}; // 0: sang phải, 1: xuống
                int dy[] = {1, 0};

                // Xét 4 trường hợp di chuyển
                for (int i = 0; i < 2; i++)
                { // Di chuyển của An
                    for (int j = 0; j < 2; j++)
                    { // Di chuyển của Bình
                        int nx1 = x1 + dx[i];
                        int ny1 = y1 + dy[i];
                        int nx2 = x2 + dx[j];
                        int ny2 = y2 + dy[j];

                        // Kiểm tra xem di chuyển có hợp lệ
                        if (nx1 >= 1 && nx1 <= N && ny1 >= 1 && ny1 <= M &&
                            nx2 >= 1 && nx2 <= N && ny2 >= 1 && ny2 <= M)
                        {
                            // Nếu hai người cùng đến một ô (không phải ô đích) thì bỏ qua
                            if (nx1 == nx2 && ny1 == ny2 && !(nx1 == N && ny1 == M))
                                continue;

                            int nk = k + 1;
                            dp[nk][nx1][nx2] = max(dp[nk][nx1][nx2], dp[k][x1][x2] + score);
                        }
                    }
                }
            }
        }
    }

    // Kết quả tại ô (N,M)
    cout << dp[N + M - 2][N][N] << endl;
    return 0;
}
