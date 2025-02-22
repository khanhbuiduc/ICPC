#include <bits/stdc++.h>
using namespace std;
#define LIM 1002
#define MOD 1'000'000'002
#define MAX 200'000
int row, col, maxBlockRow = 1, maxBlockColumn = 1;
bool canGo[LIM][LIM]; // mặc định false
int numway[LIM][LIM]; // mặc định bằng 0
int frac[MAX], finv[MAX];
// Frac[n]=n!
// finv[n]=((n!)^(mod-2))
int PowMod(int num, int pow)
{
    int res = 1;
    while (pow > 0)
    {
        if (pow & 1)
            res = (1ll * res * num) % MOD;
        num = (1ll * num * num) % MOD;
        pow >>= 1;
    }
    return res;
}
void CaculateFrac()
{
    frac[0] = 1;
    finv[0] = 1;
    // tính frac
    for (int i = 2; i < 200'000; i++)
    {
        frac[i] = ((1ll * frac[i - 1] * i) % MOD);
    }
    finv[MAX - 1] = PowMod(frac[MAX - 1], MOD - 2); // có thể tối ưu
    for (int i = MAX - 1; i > 0; i--)
    {
        finv[i - 1] = ((1ll * finv[i] * i) % MOD);
    }
}
int C(int k, int n)
{
    __int64 res = frac[n] * finv[k] * finv[n - k];
    return res % MOD;
}
int Combi(int x1, int y1, int x2, int y2)
{
    int right = x2 - x1;
    int down = y2 - y1;
    return C(down, right + down);
}
void add(int &a, int b)
{
    a = (1ll + a + b) % MOD;
    return;
}
void process()
{ // tính số cách đi (1,1)->(maxBlockRow,maxBlockColumn)
    // khởi tạo ô đầu tiên =1
    numway[1][1] = 1;
    for (int i = 1; i <= maxBlockRow; i++)
    {
        for (int j = 1; j <= maxBlockColumn; j++)
        {
            // tính số cách đi ô kề trái
            if (i < maxBlockRow && canGo[i + 1][j])
                add(numway[i + 1][j], numway[i][j]);
            // tính số cách đi ô kề dưới
            if (j < maxBlockColumn && canGo[i][j + 1])
                add(numway[i][j + 1], numway[i][j]);
        }
    }
    // nếu khoảng ô block ở vị trí max cũng chính là giới hạn
    if (row == maxBlockRow && col == maxBlockColumn)
    {
        cout << numway[row][col];
        return;
    }
    // Xử lý phần còn lại không có block bằng tổ hợp
    int ways = 0;
    // xét từng ô bên phải
    if (col > maxBlockColumn)
    {
        int caculationRight;
        for (int i = 1; i < maxBlockRow; i++)
        {
            caculationRight = numway[i][maxBlockColumn];
            caculationRight = (1ll * caculationRight * Combi(i, maxBlockColumn + 1, row, col)) % MOD;
            add(ways, caculationRight);
        }
    }
    // xét từng ô bên dướ
    if (row > maxBlockRow)
    {
        int caculationDown;
        for (int i = 1; i < maxBlockColumn; i++)
        {
            caculationDown = numway[maxBlockRow][i];
            caculationDown *= Combi(maxBlockRow + 1, i, row, col);
            ways += caculationDown;
        }
    }
    cout << ways;
}
void init()
{
    int t, xt, yt;
    for (int i = 0; i < LIM; i++)
    {
        for (int j = 0; j < LIM; j++)
        {
            canGo[i][j] = true;
        }
    }
    cin >> row >> col >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> xt >> yt;
        canGo[xt][yt] = false;
        maxBlockRow = max(maxBlockRow, xt);
        maxBlockColumn = max(maxBlockColumn, yt);
    }
    CaculateFrac();
}
int main()
{
    freopen("path.inp", "r", stdin);
    freopen("path.out", "w", stdout);
    init();
    process();
}