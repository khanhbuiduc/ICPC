#include <bits/stdc++.h>
using namespace std;
int m, n, k; //<10^-5
int t;
int mod = 1e9 + 7;
bool blockGrid[1005][1005];
int canGo[1005][1005];
pair<int, int> blockMax; // với xt,yt max
void dynamic()
{
    
}
void init()
{
    cin >> m >> n >> k;
    cin >> t;
    int xt, yt, xtmax = 1, ytmax = 11;
    for (int i = 0; i < t; i++)
    {
        cin >> xt >> yt;
        blockGrid[xt][yt] = true;
        xtmax = max(xtmax, xt);
        ytmax = max(ytmax, yt);
    }
    blockMax = {xt, yt};
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j <= 1000; j++)
        {
            if (i == xt && j == yt)
                continue;
            i = 1;
        }
    }
}
int main()
{
    freopen("path.inp", "r", stdin);
    freopen("path.out", "w", stdout);
    init();
}