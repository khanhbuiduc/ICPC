#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
bool lightOn[505][505];
ll ans = 0;
int main()
{
    int n, k;
    cin >> n >> k;
    unordered_set<int> lightOff;
    FOR(i, 1, k)
    {
        int light;
        cin >> light;
        lightOff.insert(light);
    }
    FOR(i, 1, n)
    FOR(j, 1, n)
    {
        lightOn[i][j] = true;
    }
    int index = 0;
    FOR(i, 1, n)
    FOR(j, 1, i)
    {
        index++;
        if (lightOff.count(index))
            lightOn[i][j] = false;
    }
    //--------------------------
    FOR(i, 1, n - 1)
    FOR(j, 1, i)
    FOR(h, 1, n - i)
    {
        vector<int> down, right, up;
        int cur_x = i, cur_y = j;
        FOR(i, 1, h) { down.push_back(lightOn[cur_x++][cur_y] ? 1 : 0); }
        FOR(i, 1, h) { right.push_back(lightOn[cur_x][cur_y++] ? 1 : 0); }
        FOR(i, 1, h) { up.push_back(lightOn[cur_x--][cur_y--] ? 1 : 0); }
        FOR(i, 0, h - 1) { ans += (down[i] & right[i] & up[i]); }
    }
    cout << ans;
}
/*
cho đèn tam giác có kích thước n:
số đèn: n*(n+1)/2, được đánh dấu từ 1, từ trên xuống dưới, từ trái sang phải.
(x,y)
1
2  3
4  5  6
7  8  9  10
11 12 13 14 15
-----------------
ans = 0;
duyệt đèn(x,y): (1,1) -> (n-1,n-1);
duyệt chiều cao h: 1 -> n - x;
    new_light (x,y)
    down:lưu h new_light, new_light(x--,y)  //chỉ lưu dạng bit 1 là đèn sáng, 0 là tắt đèn.
    right:lưu h new_light, new_light(x,y++)  //chỉ lưu dạng bit 1 là đèn sáng, 0 là tắt đèn.
    up  :lưu h new_light, new_light(x--,y--)//chỉ lưu dạng bít 1 là đèn sáng, 0 là tắt đèn.
ans += (down & right & up);
*/