
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define lim 300'005 //
typedef pair<int, int> pii;
typedef long long ll;
int f[505][505];
int main()
{
    int a, b;
    cin >> a >> b;
    // btcs
    // for (int i = 1; i <= a && i <= b; i++)
    // {
    //     f[i][i] = 0;
    // }
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (i == j)
                continue;
            else
            {
                f[i][j] = INT32_MAX;
                for (int u = 1; u <= i - 1; u++)
                {
                    f[i][j] = min(f[i][j], f[u][j] + f[i - u][j] + 1);
                }
                for (int v = 1; v <= j - 1; v++)
                {
                    f[i][j] = min(f[i][j], f[i][v] + f[i][j - v] + 1);
                }
            }
        }
    }
    cout << f[a][b];
}
/*
    a=3, b=5
    ans=3
    gọi f[i][j] là số cách cắt tối thiểu để cắt hcn có cạnh i,j thành hình vuông

    bài toán cơ sở: f[i][i] = 0;
    đáp án: f[a][b]
    cắt ngang: i-> u và i - u
        f[i][j] = min(f[u][j] + f[i-u][j] + 1) với u: 1->i-1
    cắt dọc: j-> v và j-v;
        f[i][j] = min(f[i][v] + f[i][j - v] + 1) với v: 1->j-1
*/