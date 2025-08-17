#include <bits/stdc++.h>
using namespace std;
bool visited[1005][1005];
string a[1005];
int n, m;
int res = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool check(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    if (visited[x][y])
        return false;
    return a[x][y] == '.';
}
void dfs(int x, int y)
{
    visited[x][y] = true;
    for (int i = 0; i <= 3; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!check(nx, ny))
            continue;
        dfs(nx, ny);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!check(i, j))
                continue;
            res++;
            dfs(i, j);
        }
    }
    cout << res;
}

/*
cho bản đồ n*m của tòa nhà. đếm xem có bao nhiêu phòng
Input:

5 8
########
#..#...#
####.#.#
#..#...#
########
Output:
3
---------------------------
1<=n,m<=1000
visited[i][j] với i: 1->m;j: 1->
dx[4] =0, 1, 0, -1
dy[4] =1, 0, -1, 0

dfs(x,y)
    visited[x][y] = true;
    for i:0->3
        nx=x+dx[i]
        ny=x+dy[i]
        nếu a[nx][ny]=='.' và !visited[nx][ny]
            dfs(nx,ny);

main(){
    for i: 1->n
        for j: 1-> m
            nếu !visited[nx][ny]
                count ++;
                dfs(i,j);
}
*/