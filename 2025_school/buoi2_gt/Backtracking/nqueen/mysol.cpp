#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a, _b = b; i <= _b; i++)
vector<string> board; // 0: trống, 1: có quân hậu
vector<vector<string>> res;
int n, sz;
bool col[10];
bool diag1[20]; // diag1[r-c+9] = true thì đã có hậu đi qua đường chéo chính;
bool diag2[20]; // diag2[r+c] = true thì ....

void solve(int r)
{
    // btcs
    if (r == sz)
    {
        res.push_back(board);
        return;
    }
    FOR(c, 0, sz - 1)
    {
        if (col[c] || diag1[r - c + 9] || diag2[r + c])
            continue;
        // đặt hậu.
        board[r][c] = 'Q';
        col[c] = true;
        diag1[r - c + 9] = true;
        diag2[r + c] = true;
        // xét hàng r+1
        solve(r + 1);
        // cất hậu
        board[r][c] = '.';
        col[c] = false;
        diag1[r - c + 9] = false;
        diag2[r + c] = false;
    }
}
void printQueen()
{
    for (auto b : res)
    {
        for (auto row : b)
        {
            cout << row << endl;
        }
        cout << endl;
    }
}
void initial()
{
    cin >> n;
    sz = n;
    // khởi tạo bàn cờ
    string row = string(n, '.');
    FOR(i, 0, n - 1) { board.push_back(row); }
}
int main()
{
    initial();
    solve(0);
    printQueen();
    return 0;
}