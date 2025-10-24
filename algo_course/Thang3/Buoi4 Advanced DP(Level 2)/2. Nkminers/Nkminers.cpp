#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
#define inf 1'000'000'000 //
typedef pair<int, int> pii;
int f[100'005][4][4][4][4]; // xét đến pt thứ i. xét các món: thịt:1,cá:2, bánh mì:3
int shipment[100'005];
//
int cacul(int a, int b, int c)
{
    int count = 0;
    if (a == 1 || b == 1 || c == 1)
        count++;
    if (a == 2 || b == 2 || c == 2)
        count++;
    if (a == 3 || b == 3 || c == 3)
        count++;
    return count;
}
int main()
{
    int n;
    string s;
    cin >> n >> s;
    // btcs
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'M')
            shipment[i + 1] = 1;
        else if (s[i] == 'B')
            shipment[i + 1] = 2;
        else if (s[i] == 'F')
            shipment[i + 1] = 3;
    }
    for (int i = 0; i <= n; i++)
        for (int a = 0; a <= 3; a++)
            for (int b = 0; b <= 3; b++)
                for (int c = 0; c <= 3; c++)
                    for (int d = 0; d <= 3; d++)
                        f[i][a][b][c][d] = -inf;
    f[0][0][0][0][0] = 0;
    // qhd
    for (int i = 0; i < n; i++)
        for (int a = 0; a <= 3; a++)
            for (int b = 0; b <= 3; b++)
                for (int c = 0; c <= 3; c++)
                    for (int d = 0; d <= 3; d++)
                        if (f[i][a][b][c][d] != -inf)
                        {
                            // ship i+1 vào mỏ 1;
                            f[i + 1][b][shipment[i + 1]][c][d] = max(f[i + 1][b][shipment[i + 1]][c][d], f[i][a][b][c][d] + cacul(a, b, shipment[i + 1]));
                            // ship i+1 vào mỏ 2:
                            f[i + 1][a][b][d][shipment[i + 1]] = max(f[i + 1][a][b][d][shipment[i + 1]], f[i][a][b][c][d] + cacul(c, d, shipment[i + 1]));
                        }
    // kết quả
    int res = -1;
    for (int a = 0; a <= 3; a++)
        for (int b = 0; b <= 3; b++)
            for (int c = 0; c <= 3; c++)
                for (int d = 0; d <= 3; d++)
                {
                    res = max(res, f[n][a][b][c][d]);
                }
    cout << res;
}
/*
K miners

hãy thiết kế hàm để tính lượng than sinh ra khi có 3 món kề nhau là (a,b,c) (a,b,c: 0->3)

calc(a, b, c):
    dặt ret = 0
    něu a == 1 | | b == 1 || c == 1: ret++
    něu a == 2 || b == 2 || c == 2: ret++
    něu a == 3 || b == 3 || c == 3: ret++
return ret

Gọi f[i][a][b][c][d] là tổng lượng than lớn nhất khi có i đợt vận chuyển, 2 món cuối cùng trong mỏ 1 lần lượt là a và b, 2 món cuoi cùng trong mo 2 lần lượt là c
và d.

bài toan con:
    f[0][0][0][0][0] = 0, khoi tạo cac f[i][a][b][c][d] == -1
đáp án bài toan:
    max(f[n][a][b][c][d]) voi a,b,c,d: 0 -> 3

QHD: khi ta có: f[i][a][b][c][d] != -1
xét: đợt vận chuyển thứ i + 1,
    gọi là shipment[i+1]
    tình huống 1: shipment[i+1] vào mở:
        i->i+1
        a->b
        b->shipment[i+1]
        c->c
        d->d
        f[i+1][b][shipment[i+1]][c][d] = max(f[i+1][b][shipment[i+1]][c][d], f[i][a][b][c][d] +calu(a,b,shipment[i+1]) )
    tình huống 2: shipment[i+1] vào mở 2:
        i->i+1
        a->a
        b->b
        c->d
        d->shipment[i+1];
    f[i+1][a][b][d][shipment[i+1]] = max(f[i+1][a][b][d][shipment[i+1]], f[i][a][b][c][d] +calu(c,d,shipment[i+1]) )
Độ phức tạp: O(N* 4^4) = O(256 * N);
*/