#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
int a[1005][1005];
bool visitedA[1005][1005];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0}; // L,U,D,R
int res[1005][1005];
vector<vector<pii>> shapes; // shape loại i là list<x,y>
vector<pii> cur_shape;

void compress(vector<pii> &shape_A)
{
    if (shape_A.empty())
        return;

    int min_x = 1e9;
    int min_y = 1e9;
    for (auto &[xa, ya] : shape_A)
    {
        min_x = min(min_x, xa);
        min_y = min(min_y, ya);
    }
    for (auto &[xa, ya] : shape_A)
    {
        xa -= min_x;
        ya -= min_y;
    }
    sort(ALL(shape_A));
}

void rotate90(vector<pii> &shape_A)
{
    for (auto &[xa, ya] : shape_A)
    {
        int temp = xa;
        xa = -ya; // (x,y) -> (-y,x)
        ya = temp;
    }
    compress(shape_A);
}

void flip(vector<pii> &shape_A)
{
    for (auto &[xa, ya] : shape_A)
    {
        xa = -xa;
    }
    compress(shape_A);
}

bool shapeCompare(vector<pii> shape_A, vector<pii> shape_B)
{
    compress(shape_A);
    compress(shape_B);

    // 4 góc xoay
    FOR(i, 1, 4)
    {
        if (shape_A == shape_B)
            return true;
        rotate90(shape_A);
    }

    // Lật và 4 góc xoay
    flip(shape_A);
    FOR(i, 1, 4)
    {
        if (shape_A == shape_B)
            return true;
        rotate90(shape_A);
    }

    return false;
}

void dfs(int x, int y)
{
    cur_shape.emplace_back(x, y);
    visitedA[x][y] = true;

    FOR(dir, 0, 3)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !visitedA[nx][ny] && a[nx][ny] == 1)
        {
            dfs(nx, ny);
        }
    }
}

void dfs_res(int x, int y, int value)
{
    res[x][y] = value;

    FOR(dir, 0, 3)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m &&
            res[nx][ny] == 0 && a[nx][ny] == 1)
        {
            dfs_res(nx, ny, value);
        }
    }
}

void initial()
{
    cin >> n >> m;
    FOR(i, 1, n)
    FOR(j, 1, m)
    {
        cin >> a[i][j];
    }
}

void solve()
{
    FOR(i, 1, n)
    FOR(j, 1, m)
    {
        if (visitedA[i][j] || a[i][j] == 0)
            continue;

        cur_shape.clear();
        dfs(i, j);

        compress(cur_shape);

        FOR(si, 0, (int)shapes.size() - 1)
        {
            if (shapeCompare(cur_shape, shapes[si]))
            {
                dfs_res(i, j, si + 1);
                break;
            }
        }

        if (res[i][j] == 0)
        {
            shapes.push_back(cur_shape);
            dfs_res(i, j, shapes.size());
        }
    }

    FOR(i, 1, n)
    {
        FOR(j, 1, m)
        {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout");

    initial();
    solve();

    return 0;
}