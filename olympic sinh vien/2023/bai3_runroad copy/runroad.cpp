// nhớ không được đặt biến trùng tên
#include <bits/stdc++.h>
using namespace std;
#define M 1'000'000'007
#define ff first
#define ss second
typedef vector<int> v;
vector<bool> visited;
vector<v> paths;
vector<int> h;
int n;
vector<pair<int, int>> edges;
int countLinkNode(int node)
{

    int count = 1;
    visited[node] = true;
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i : paths[cur])
            // kiểm tra từng điểm mà cur tới được. nếu chưa thăm thì thêm vào queue
            if (!visited[i])
            {
                visited[i] = true;
                edges.push_back({cur, i});
                q.push(i);
                count++;
            }
    }
    return count;
}
int counting(int num)
{
    int count = 1;
    queue<int> q;
    q.push(num);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto [u, v] : edges)
        {
            if (u == cur)
            {
                count++;
                q.push(v);
            }
        }
    }
    return count;
}
int C(int totalNode)
{
    int64_t total = 0;
    for (auto [a, b] : edges)
    {
        int c = counting(b);
        total += c * (totalNode - c) % M * (totalNode - 2) % M;
    }
    return (int)total;
}
int solve(int t)
{
    int res = 0;
    for (int i = 1; i <= n; i++)
        h[i] <= t ? visited[i] = false : visited[i] = true;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {
            edges.clear();
            int totalNode = countLinkNode(i);
            res += C(totalNode);
        }
    }
    return res;
}
int main()
{
    // freopen("runroad.inp", "r", stdin);
    // freopen("runroad.out", "w", stdout);
    int t;
    cin >> n >> t;
    h.resize(n + 1);
    paths.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    // khai báo đồ thị 2 chiều;
    int u, v;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        paths[u].push_back(v);
        paths[v].push_back(u);
    }
    cout << ((solve(t) - solve(t - 1) + M) % M);
    // total(high=h)= total(<=h)-total(<h)
    // khai báo: vector<int> h: chiều cao mỗi nút; vector<vector<int>> paths: cây 2 chiều
    // 1.dùng mảng visited để đánh dấu những node>h hoặc đã duyệt qua
    // 2.duyệt qua từng phần tử của câyl
    // 2.1điểm tổng lượng nút liên thông nodeTotal thỏa mãn đồng thời đánh dấu những nút đó là visited
    // 2.2tính tổ hợp của số lượng nút liên thông đó;
    // 2.2.1chia 1 cạnh làm 2 phần đầu a và b; tính số lượng liên thông linkA,linkB; C= LinkA*linkB*(nodeTotal-2);
}