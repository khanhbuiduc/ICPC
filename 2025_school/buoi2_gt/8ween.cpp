#include <bits/stdc++.h>
using namespace std;

const int N = 8;
int board[N][N];  // 0: trống, 1: có quân hậu
int col[N];       // đánh dấu cột đã có quân hậu
int diag1[2 * N]; // đường chéo chính (i - j + N-1)
int diag2[2 * N]; // đường chéo phụ (i + j)
int cnt = 0;      // đếm số cách

void printBoard()
{
    cout << "Solution " << cnt << ":\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << "\n";
    }
    cout << "\n";
}

bool outOfBound(int row, int c)
{
    if (col[c] || diag1[row - c + N - 1] || diag2[row + c])
        return false;
    return true;
}

void solve(int row)
{
    if (row == N)
    {
        cnt++;
        printBoard();
        return;
    }

    // Thử đặt quân hậu vào mỗi cột của hàng row
    for (int c = 0; c < N; c++)
    {
        if (outOfBound(row, c))
        {
            // Đặt quân hậu
            board[row][c] = 1;
            col[c] = 1;
            diag1[row - c + N - 1] = 1;
            diag2[row + c] = 1;

            // Đệ quy sang hàng tiếp theo
            solve(row + 1);

            // Backtrack: bỏ quân hậu
            board[row][c] = 0;
            col[c] = 0;
            diag1[row - c + N - 1] = 0;
            diag2[row + c] = 0;
        }
    }
}

int main()
{
    cout << "Solving 8 Queens Problem...\n\n";
    solve(0);
    cout << "Total solutions: " << cnt << endl;
    return 0;
}