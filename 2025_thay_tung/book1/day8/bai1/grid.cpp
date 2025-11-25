#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int k, w, h, t;
    cin >> k >> w >> h >> t;
    int row = (t + k) * h + t;
    int col = (t + k) * w + t;
    vector<vector<char>> res(row, vector<char>(col, '*'));

    for (int x = t; x < row; x += (k + t))
    {
        for (int y = t; y < col; y += (k + t))
        {
            // đang ở vị trí đầu 1 ô;
            FOR(ri, x, x + k - 1)
            {
                FOR(ci, y, y + k - 1)
                {
                    res[ri][ci] = '.';
                }
            }
        }
    }
    for (auto row : res)
    {
        for (auto col : row)
            cout << col;
        cout << endl;
    }
}
/*
vẽ lưới ô kích thước w*h, ô kích thước k*k, viền kích thước t
*/