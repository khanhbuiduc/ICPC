#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ff first
#define ss second
vector<int> adj[1000];
int n, m;
pii s;

char labyrinth[1005][1005];
int dx[4] = {-1, 0, 1, 0}; // U,R,D,L đây là tọa độ lập trình chứ k phải Oxy
int dy[4] = {0, 1, 0, -1};
char direction[4] = {'U', 'R', 'D', 'L'};
int trace[1005][1005]; // hướng
queue<pair<char, pii>> q;
bool in_Bound(int x, int y)
{
    return 1 <= x && x <= n && 1 <= y && y <= m;
}
bool on_Bound(int x, int y)
{
    return (x == 1 || x == n) || (y == 1 || y == m);
}
void print_step(int x, int y)
{
    string ans = "";
    while (x != s.ff || y != s.ss)
    {
        int dir = trace[x][y];
        ans += direction[dir];
        x -= dx[dir];
        y -= dy[dir];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    cout << ans;
}
void bfs()
{
    while (!q.empty())
    {
        auto [c, d] = q.front();
        auto [x, y] = d;
        q.pop();
        for (int dir = 0; dir <= 3; dir++)
        {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (in_Bound(nx, ny) && labyrinth[nx][ny] == '.')
            {
                labyrinth[nx][ny] = c;
                q.push({c, {nx, ny}});
                if (c == 'A')
                {
                    trace[nx][ny] = dir;
                    if (on_Bound(nx, ny))
                    {
                        cout << "YES" << endl;
                        print_step(nx, ny);
                        exit(0);
                    }
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string row;
        cin >> row;
        for (int j = 1; j <= m; j++)
        {
            labyrinth[i][j] = row[j - 1];
            if (labyrinth[i][j] == 'A')
                s = {i, j};
            if (labyrinth[i][j] == 'M')
                q.push({'M', {i, j}});
        }
    }

    if (on_Bound(s.ff, s.ss))
    {
        cout << "YES" << endl
             << '0' << endl;
        return 0;
    }
    q.push({'A', s});
    bfs();
    cout << "NO";
}

// lưu trữ gồm:
/*
    vị trí các ô trc, vị trí ô hiện tại.
    Monster
    - thêm khi loang quái vật đến người không cần đè quái vật lên người vì. người không thể đi qua quái vật đc.
*/