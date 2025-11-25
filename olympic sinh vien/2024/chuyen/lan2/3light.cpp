#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
bool is_red[505][505];
set<int> blue;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    FOR(i, 1, k)
    {
        int b;
        cin >> b;
        blue.insert(b);
    }
    FOR(i, 1, n)
    FOR(j, 1, i)
    {
        is_red[i][j] = true;
        int cur = i * (i - 1) / 2 + j;
        if (blue.find(cur) != blue.end())
        {
            is_red[i][j] = false;
        }
    }
    FOR(i, 1, n)
    FOR(j, 1, i)
    FOR(h, 1, n - i)
    {
        vector<int> down, right, upleft;
        // xuống
        FOR(d, 0, h - 1)
        {
            is_red[i + d][j] ? down.push_back(1) : down.push_back(0);
            is_red[i + h][j + d] ? right.push_back(1) : right.push_back(0);
            is_red[i + h - d][j + h - d] ? upleft.push_back(1) : upleft.push_back(0);
        }
        FOR(d, 0, h - 1)
        {
            if (down[d] & right[d] & upleft[d])
                ans++;
        }
    }
    cout << ans;
}
/*
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
16 16 18 19 20 21
---
đếm tam giác từ mỗi đỉnh.
// tạo 2 cạnh:
cách tạo tam giác:
down = [1,1,1,1,1]
right = [1,1,1,0,1]
upleft = [1,1,1,1,1]
cnt += (down,right,upleft)
---

*/