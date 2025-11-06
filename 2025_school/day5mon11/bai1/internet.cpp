#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
int root[100005];
typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;
int n, m;
int adj[1000][1000];    // u->v có w
vector<tiii> listEdges; // w,u,v
long long cost = 0;
vector<tiii> ans;

// DSU
int findRoot(int u)
{
    return root[u] = (u == root[u] ? u : findRoot(root[u]));
}
void setUnion(int u, int v)
{
    int rootu = findRoot(u);
    int rootv = findRoot(v);
    if (rootu != rootv)
    {
        root[rootu] = rootv;
    }
}

void kruskal()
{
    sort(listEdges.begin(), listEdges.end());
    for (auto [w, u, v] : listEdges)
    {
        int rootu = findRoot(u);
        int rootv = findRoot(v);
        if (rootu != rootv)
        {
            cost += w;
            ans.emplace_back(w, u, v);
            setUnion(u, v);
        }
    }
}

void initial()
{
    for (int i = 1; i <= n; i++)
        root[i] = i;
}
void printKruskal()
{
    cout << "Cay khung nho nhat:\n";
    for (auto [w, u, v] : ans)
        cout << char(u - 1 + 'A') << char(v - 1 + 'A') << " : " << w << "\n";
    cout << "Chi phi: " << cost << "\n\n";
}
int main()
{
    cin >> n;
    FOR(u, 1, n)
    FOR(v, 1, n)
    {
        int w;
        cin >> w;
        adj[u][v] = w;
        if (w != 0 && u < v)
            listEdges.emplace_back(w, u, v);
    }

    // Yêu cầu 1: Tìm cây khung nhỏ nhất
    initial();
    kruskal();

    printKruskal();

    // Yêu cầu 2: Thêm đỉnh H vào đồ thị
    int numHEdges;
    cin >> numHEdges;

    int h = n + 1; // H là đỉnh n+1
    FOR(i, 1, numHEdges)
    {
        char city;
        int w;
        cin >> city >> w;
        int v = city - 'A' + 1;
        listEdges.emplace_back(w, v, h);
    }

    // Tính lại MST với đỉnh H
    n++;
    initial();
    cost = 0;
    listEdges = ans; // tối ưu bằng cách chỉ dùng các kuruscal cũ\
    ans.clear();
    kruskal();
    printKruskal();

    return 0;
}
/*
7
0 4 6 0 0 0 0
4 0 6 3 0 0 0
6 6 0 2 5 0 0
0 3 2 0 3 4 0
0 0 5 3 0 2 3
0 0 0 4 2 0 5
0 0 0 0 3 5 0
3
B 4
D 6
F 3
---output---
Cay khung nho nhat:
CD : 2
EF : 2
BD : 3
DE : 3
EG : 3
AB : 4
Chi phi: 17

Cay khung nho nhat:
CD : 2
EF : 2
BD : 3
DE : 3
EG : 3
AB : 4
CD : 2
EF : 2
BD : 3
DE : 3
EG : 3
AB : 4
Chi phi: 17
*/