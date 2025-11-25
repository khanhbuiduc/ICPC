#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAX = 200200;
const int LIM = 1010;

int frac[MAX], finv[MAX];
int modPow(int x, int k)
{
    int res = 1;
    while (k > 0)
    {
        if (k & 1)
            res = (1LL * res * x) % MOD;
        x = (1LL * x * x) % MOD;
        k >>= 1;
    }
    return res;
}

void prepare()
{
    frac[0] = 1;
    for (int i = 1; i < MAX; i++)
    {
        frac[i] = (1LL * frac[i - 1] * i) % MOD;
    }
    finv[MAX - 1] = modPow(frac[MAX - 1], MOD - 2);
    for (int i = MAX - 1; i >= 1; i--)
    {
        finv[i - 1] = (1LL * finv[i] * i) % MOD;
    }
}

// Tính tổ hợp: C(n, k) = n!/(k!(n-k)!)
int comb(int n, int k)
{
    if (k > n)
        return 0;
    return (1LL * frac[n] * finv[k] % MOD) * finv[n - k] % MOD;
}

// Hàm tính số cách đi “free” từ ô (x1,y1) đến (x2,y2) (không có chặn)
int numFreeWay(int x1, int y1, int x2, int y2)
{
    if (x1 > x2 || y1 > y2)
        return 0;
    int down = x2 - x1, right = y2 - y1;
    return comb(down + right, down); // số cách sắp xếp down và right
}

// Các biến toàn cục cho dữ liệu đầu vào và quy hoạch động
int numRow, numCol, numBlocked;
bool canGo[LIM][LIM];
int numWay[LIM][LIM]; // số cách đi đến ô (i,j)
int maxBlockedRow, maxBlockedCol;

// Hàm cập nhật giá trị (tính modulo MOD)
void add(int &x, int y)
{
    x = (x + y) % MOD;
}

// Hàm đọc dữ liệu
void init()
{
    cin >> numRow >> numCol >> numBlocked;
    // Khởi tạo toàn bộ ô là được đi
    for (int i = 0; i < LIM; i++)
        for (int j = 0; j < LIM; j++)
            canGo[i][j] = true;

    // Ban đầu vùng bị ảnh hưởng là ít nhất (1,1)
    maxBlockedRow = maxBlockedCol = 1;

    // Đánh dấu các ô bị chặn và cập nhật giới hạn vùng chặn
    for (int i = 0; i < numBlocked; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x < LIM && y < LIM)
        {
            canGo[x][y] = false;
        }
        maxBlockedRow = max(maxBlockedRow, x);
        maxBlockedCol = max(maxBlockedCol, y);
    }
}

// Hàm xử lý: tính số cách đi từ (1,1) đến (numRow, numCol)
void process()
{
    // Dùng quy hoạch động trong vùng [1..maxBlockedRow] x [1..maxBlockedCol]
    memset(numWay, 0, sizeof(numWay));
    if (canGo[1][1])
        numWay[1][1] = 1;

    for (int i = 1; i <= maxBlockedRow; i++)
    {
        for (int j = 1; j <= maxBlockedCol; j++)
        {
            if (numWay[i][j] == 0)
                continue;
            // Di chuyển xuống (i+1, j) nếu trong vùng và ô đó không bị chặn
            if (i < maxBlockedRow && canGo[i + 1][j])
                add(numWay[i + 1][j], numWay[i][j]);
            // Di chuyển sang phải (i, j+1)
            if (j < maxBlockedCol && canGo[i][j + 1])
                add(numWay[i][j + 1], numWay[i][j]);
        }
    }

    // Nếu đích nằm trong vùng quy hoạch động, in luôn kết quả
    if (numRow == maxBlockedRow && numCol == maxBlockedCol)
    {
        cout << numWay[numRow][numCol] << endl;
        return;
    }

    // Nếu đích nằm ngoài vùng, dùng công thức tổ hợp để nối các đường đi “free”
    int res = 0;
    // Nếu phía bên phải vùng bị ảnh hưởng chưa đến cột đích
    if (maxBlockedCol < numCol)
    {
        for (int i = 1; i <= maxBlockedRow; i++)
        {
            if (numWay[i][maxBlockedCol] == 0)
                continue;
            int ways = numFreeWay(i, maxBlockedCol + 1, numRow, numCol);
            add(res, (1LL * numWay[i][maxBlockedCol] * ways) % MOD);
        }
    }
    // Nếu phía dưới vùng bị ảnh hưởng chưa đến hàng đích
    if (maxBlockedRow < numRow)
    {
        for (int j = 1; j <= maxBlockedCol; j++)
        {
            if (numWay[maxBlockedRow][j] == 0)
                continue;
            int ways = numFreeWay(maxBlockedRow + 1, j, numRow, numCol);
            add(res, (1LL * numWay[maxBlockedRow][j] * ways) % MOD);
        }
    }
    cout << res << endl;
}

int main()
{
    // freopen("path.inp", "r", stdin);
    // freopen("path.out", "w", stdout);
    // Chuẩn bị tiền xử lý giai thừa
    prepare();
    // Đọc dữ liệu đầu vào và khởi tạo các biến
    init();
    // Tính toán và in kết quả
    process();
    return 0;
}
