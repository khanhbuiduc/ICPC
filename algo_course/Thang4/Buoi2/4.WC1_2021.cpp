#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int, int> tiii; // x1,x2,y1,y2
bool visited[2005];
set<int> adj[2005]; // thứ tự màu
int a[105][105];
tiii colors[2005];
set<int> usedColor;
stack<int> store;
int m, n;
void updateColor(tiii &color, int x, int y)
{
    auto &[x1, x2, y1, y2] = color;
    if (x1 == 0 || x1 > x)
        x1 = x;
    if (x2 == 0 || x2 < x)
        x2 = x;
    if (y1 == 0 || y1 > y)
        y1 = y;
    if (y2 == 0 || y2 < y)
        y2 = y;
}
void topo(int u)
{
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v])
            topo(v);
    store.push(u);
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        // reset các kho lưu trữ
        memset(visited, 0, sizeof(visited));
        for (auto &i : adj)
            i.clear();
        for (tiii &i : colors)
            i = {0, 0, 0, 0};
        usedColor.clear();
        // initial
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                usedColor.insert(a[i][j]);
                updateColor(colors[a[i][j]], i, j);
            }
        }
        // tạo thứ tự cho màu.
        for (int c : usedColor)
        {
            auto [x1, x2, y1, y2] = colors[c];
            for (int i = x1; i <= x2; i++)
            {
                for (int j = y1; j <= y2; j++)
                    if (c != a[i][j])
                        adj[a[i][j]].insert(c);
            }
        }
        // sắp xếp topo cho màu.
        for (int color : usedColor)
        {
            if (!visited[color])
                topo(color);
        }
        // in ra
        cout << store.size() << endl;
        while (!store.empty())
        {
            int c = store.top();
            store.pop();
            auto [x1, x2, y1, y2] = colors[c];
            cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << c << endl;
        }
    }
}
/*
  {x1,x2,y1,y2} và màu
Giới hạn: 1 ≤ N, M ≤ 100: 100*100=10'000
1 ≤ a[i][j] ≤ 2000

map<màu,{x1,x2,y1,y2}>
for i: 1->n
    for j: 1->m
        curColor = a[i][j];
        cập nhập  tọa độ {x1,x2,y1,y2}
        i<x1 thì x1=i
        i>x2 thì x2=i
        j<y1 thì y1=j
        j>y2 thì y2=j
----------------------
for color in colors
    color: màu, x1,x2,y1,y2
    for: i: x1->x2
        for j: y1->y2
            if(màu bên trong khác)
            adj[màu].insert[màu khác]
----------------------
topo sort.
----------------------
in ra
*/