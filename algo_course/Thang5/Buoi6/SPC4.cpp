#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define MOD 1000000007
using namespace std;
typedef long long ll;

const int MAXN = 35;
int card[35], sum_card[MAXN];
int f[35][35][35];
int n, k, t;

void inital()
{
    cin >> n >> k >> t;
    FOR(i, 0, n)
    FOR(a, 0, 31)
    FOR(b, 0, 31)
    {
        f[i][a][b] = 0;
    }

    FOR(i, 1, n)
    {
        cin >> card[i];
        sum_card[i] = sum_card[i - 1] + card[i];
    }
}

int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        inital();

        FOR(i, 1, n)
        FOR(a, 0, 31)
        FOR(b, 0, 31)
        {
            FOR(x, 0, min(a, i - 1))
            {
                int pre_a = sum_card[i - 1] - f[i - 1 - x][b][a - x];
                f[i][a][b] = max(f[i][a][b], pre_a + card[i]);
            }
        }

        int first = f[n][k][t];
        int second = sum_card[n] - first;

        if (first < second)
            cout << "LOSE" << endl;
        else if (first > second)
            cout << "WIN" << endl;
        else
            cout << "DRAW" << endl;
    }

    return 0;
}
/*
    gọi f[i][a][b] là tổng điểm lớn nhất khi có i lá bài. số lượng addition người 1 là a, người thứ 2 là b
    bài toán cơ sở: f[0][a][b] = 0;
    đáp án: f[N][K][T]: số điểm k có đc, suma[n] - f[N][K][T]: số điểm t có đc

    QHD:
        người hiện tại bốc x lá: 0 -> min(a,i-1)
        (i,a,b) -> (i - x, b, a - x)
        f[i][a][b] = max (suma[i] - f[i-x,b,a-x]) với x: 0 -> min(a,i-1)
*/