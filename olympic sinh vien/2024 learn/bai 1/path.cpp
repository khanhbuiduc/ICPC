// Categories: Dynamic Programming
#include <bits/stdc++.h>
using namespace std;
#define LIM 1002
#define MOD 1'000'000'007 // 2^32~10^9
#define MAX 200'002
typedef long long ll;
// khởi tạo
int numRow, numCol, numBlocked, maxBlockedRow, maxBlockedCol;
int canGo[LIM][LIM];
int numWay[LIM][LIM];
// lưu giai thừa và nghịch đảo giai thừa
ll fact[MAX], finv[MAX];
// 1 tinh nghich dao modul
ll modPow(ll a, ll b)
{
    ll result = 1;
    while (b > 0)
    {
        if (b & 1)
            result = (result * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return result;
}
ll modInverse(ll a)
{
    return modPow(a, MOD - 2);
}
// tinh giai thua va nghich dao giai thua
void prepare()
{
    fact[0] = 1;
    finv[0] = 1;
    for (int i = 1; i < MAX; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
        finv[i] = modInverse(fact[i]);
    }
}
//  2 tinh to hop
ll comb(int n, int k)
{
    return ((fact[n] * finv[k]) % MOD * finv[n - k]) % MOD; // chú ý mặc dù 2 số là ll nhưng khi nhân 2 số vẫn có thể tràn;
}
ll combByCoordinates(int x1, int y1, int x2, int y2)
{
    int down = x2 - x1, right = y2 - y1;
    return comb(down + right, down);
}
// Hàm đọc dữ liệu
void init()
{
    cin >> numRow >> numCol >> numBlocked;
    // Khởi tạo toàn bộ ô là được đi
    for (int i = 0; i < LIM; i++)
    {
        for (int j = 0; j < LIM; j++)
        {
            canGo[i][j] = true;
            numWay[i][j] = 0;
        }
    }
    // Ban đầu vùng bị ảnh hưởng là ít nhất (1,1)
    maxBlockedRow = 1, maxBlockedCol = 1;
    // Đánh dấu các ô bị chặn và cập nhật giới hạn vùng chặn
    int xt, yt;
    for (int i = 1; i <= numBlocked; i++)
    {
        cin >> xt >> yt;
        canGo[xt][yt] = false;
        maxBlockedRow = max(maxBlockedRow, xt);
        maxBlockedCol = max(maxBlockedCol, yt);
    }
}

// Hàm xử lý: tính số cách đi từ (1,1) đến (numRow, numCol)
void process()
{
    // Dùng quy hoạch động trong vùng [1..maxBlockedRow] x [1..maxBlockedCol]
    numWay[1][1] = 1;
    for (int i = 1; i <= maxBlockedRow; i++)
    {
        for (int j = 1; j <= maxBlockedCol; j++)
        {
            if (!canGo[i][j])
                continue;
            // Di chuyển xuống (i+1, j) nếu trong vùng và ô đó không bị chặn
            if (canGo[i + 1][j])
            {
                numWay[i + 1][j] = (numWay[i + 1][j] + numWay[i][j]) % MOD;
            }
            // Di chuyển sang phải (i, j+1)
            if (canGo[i][j + 1])
            {
                numWay[i][j + 1] = (numWay[i][j + 1] + numWay[i][j]) % MOD;
            }
        }
    }
    // Nếu đích nằm trong vùng quy hoạch động, in luôn kết quả
    if (numRow == maxBlockedRow && numCol == maxBlockedCol)
    {
        cout << numWay[numRow][numCol];
        return;
    }
    // Nếu đích nằm ngoài vùng, dùng công thức tổ hợp để nối các đường đi “free”
    ll res = 0;
    ll ways = 0;
    // Nếu phía bên phải vùng bị ảnh hưởng chưa đến cột đích
    if (maxBlockedCol < numCol)
    {
        for (int i = 1; i <= maxBlockedRow; i++)
        {
            ways = combByCoordinates(i, maxBlockedCol + 1, numRow, numCol);
            ways = (ways * numWay[i][maxBlockedCol]) % MOD;
            res = (res + ways) % MOD;
        }
    }
    // Nếu phía dưới vùng bị ảnh hưởng chưa đến hàng đích
    if (maxBlockedRow < numRow)
    {
        for (int i = 1; i <= maxBlockedCol; i++)
        {
            ways = combByCoordinates(maxBlockedRow + 1, i, numRow, numCol);
            ways = (ways * numWay[maxBlockedRow][i]) % MOD;
            res = (res + ways) % MOD;
        }
    }
    cout << res;
}
int main()
{
    // freopen("path.inp", "r", stdin);
    // freopen("path.out", "w", stdout);
    prepare();
    init();
    process();
}
