#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define lim 300'005 //
typedef pair<int, int> pii;
typedef long long ll;
pii a[105];
ll f[105][100'005]; //
int main()
{
    int n, w;
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
        cin >> a[i].ff >> a[i].ss;
    // bài toán cơ sở:
    for (int i = 0; i <= n; i++)
        f[i][0] = 0;
    for (int i = 0; i <= w; i++)
        f[0][i] = 0;
    for (int i = 1; i <= n; i++) // từng đồ vật
    {
        for (int j = 1; j <= w; j++) // từng cân nặng
        {
            // k thể bỏ i vào túi:
            if (a[i].ff > j)
                f[i][j] = f[i - 1][j];
            // có thể bỏ i vào túi:
            else
            {
                f[i][j] = max(f[i - 1][j], f[i - 1][j - a[i].ff] + a[i].ss);
            }
            // cout << f[i][j] << " ";
        }
        // cout << endl;
    }
    // đáp án:
    cout << f[n][w];
}