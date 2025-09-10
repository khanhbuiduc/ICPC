#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define MOD 1000000007
using namespace std;
typedef long long ll;

const int MAXN = 505;
ll a[MAXN][MAXN], sum_col[MAXN][MAXN], sum_row[MAXN][MAXN];
bool f[MAXN][MAXN];
int n;
ll fact[MAXN], inv_fact[MAXN];
void inital()
{
    cin >> n;
    FOR(i, 0, n)
    FOR(j, 0, n)
    {
        f[i][j] = 0;
    }
    FOR(i, 1, n)
    FOR(j, 1, n)
    {
        cin >> a[i][j];
        sum_row[i][j] = sum_row[i][j - 1] + a[i][j];
        sum_col[i][j] = sum_col[i - 1][j] + a[i][j];
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        inital();
        FOR(i, 1, n)
        FOR(j, 1, n)
        {
            // xóa hàng i
            if ((sum_row[i][j] & 1) == 0 && !f[i - 1][j])
                f[i][j] = 1;
            // xóa cột j
            if ((sum_col[i][j] & 1) == 0 && !f[i][j - 1])
                f[i][j] = 1;
        }
        cout << (f[n][n] ? "YES" : "NO") << endl;
    }
}
/*

Parigame

Cho một bảng hình vuông gồm N hàng N cột. 2 người sẽ chơi trò chơi xóa bảng. Với mỗi lượt chơi, người hiện tại chi được phép xóa hàng cuoi cùng hoặc cột cuối cùng

nếu tổng các số trên hàng đó hoặc cột đó là số chẵn. Người nào không tiếp tục thực hiện được thì người đó thua.

Hỏi người chơi đầu tiên có thẳng hay không ??????

gọi f[i][j] là trạng thái thắng hoặc thua khi bảng hiện tại đang có i hàng j cột

đáp án bài toan: f[n][n] == 1: YES, f[n][n] == 0 in ra NO
-------------------------------------
Gọi f[i][j] là trạng thái thắng hoặc thua khi người hiện tại chơi vào bảng có i hàng và j cột

đáp án bài toan: f[n][n] == 1: YES, f[n][n] == 0 in ra NO

Nếu xóa hàng i:
    Tổng các số trên hàng i (a[i][1] +a[i][2] + ..... + a[i][j] phải là số chẵn)
    Neu tổng cac số trên hang i là so chan và f[i - 1][j] == 0: f[i][j] = 1

Nếu xóa cột j
    Neu tổng cac so trên cột j là so chan và f[i][j - 1] == 0 : f[i][j] = 1
*/