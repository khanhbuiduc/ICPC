#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
int n;
int fw[1050][1050];
void update(int x, int y, int vals)
{
    for (int i = x; i <= n; i += i & -i)
        for (int j = y; j <= n; j += j & -j)
            fw[i][j] += vals;
}
ll get(int x, int y) // trc index có bao nhiêu số < index.
{
    ll res = 0;

    for (int i = x; i > 0; i -= i & -i)
        for (int j = y; j > 0; j -= j & -j)
        {
            res += fw[i][j];
        }
    return res;
}
int calsum(int x1, int y1, int x2, int y2)
{
    return get(x2, y2) + get(x1 - 1, y1 - 1) - get(x2, y1 - 1) - get(x1 - 1, y2);
}
int main()
{
    int type, s, x, y, x1, y1, x2, y2, val;
    cin >> type >> n;
    n++;
    while (cin >> type && type != 3)
    {
        if (type == 1)
        {
            cin >> x >> y >> val;
            x++;
            y++;
            update(x, y, val);
        }
        else if (type == 2)
        {
            cin >> x1 >> y1 >> x2 >> y2;
            x1++, x2++, y1++, y2++;
            cout << calsum(x1, y1, x2, y2) << endl;
        }
    }
}
/*

*/