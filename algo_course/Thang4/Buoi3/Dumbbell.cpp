#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<int> adj[100'005];
bitset<100'005> f[2]; // Chỉ dùng 2 bitset thay vì mảng 2 chiều

int num[100'005], low[100'005], sz[100'005];
int countDfs = 0;
int n, m;

long long caculate(int x)
{
    return 1ll * x * (x - 1) / 2 + 1ll * (n - x) * (n - x - 1) / 2 + 1 - m;
}

// lưu trữ tplt: {size, list<cầu>}
vector<vector<int>> x_tplt; // lưu trữ số lượng đỉnh 1 bên cầu của tplt thứ i
vector<int> size_tplt;      // kích thước tplt;

void dfs(vector<int> &x, int u, int father)
{
    num[u] = low[u] = ++countDfs;
    sz[u] = 1;

    for (int v : adj[u])
    {
        if (v == father)
            continue;

        if (num[v] == 0)
        {
            dfs(x, v, u);
            sz[u] += sz[v];
            low[u] = min(low[u], low[v]);
            if (low[v] == num[v])
            {
                x.push_back(sz[v]);
                x.push_back(n - sz[v]);
            }
        }
        else
            low[u] = min(low[u], num[v]);
    }
}

int main()
{
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Tìm tất cả TPLT và cầu
    for (int i = 1; i <= n; i++)
    {
        if (num[i] == 0)
        {
            countDfs = 0;
            vector<int> x;
            dfs(x, i, -1);
            x_tplt.push_back(x);
            size_tplt.push_back(countDfs);
        }
    }

    // btcs
    f[0].set(0, 1); // f[0][0] = true

    int count_tplt = size_tplt.size();
    for (int i = 0; i < count_tplt; i++)
    {
        // Xử lý state = 1 (đã chọn cầu) trước
        f[1] |= (f[1] << size_tplt[i]);

        // Sử dụng cầu trong TPLT i làm thanh quả tạ
        for (int k : x_tplt[i])
        {
            f[1] |= (f[0] << k);
        }

        // Xử lý state = 0 (chưa chọn cầu) sau
        f[0] |= (f[0] << size_tplt[i]);
    }

    // Tìm đáp án
    bitset<100'005> set_x = f[0] | f[1];
    long long ans = 1'000'000'000'000'007LL;

    for (int i = 1; i < n; i++)
    {
        if (set_x[i])
            ans = min(ans, (long long)caculate(i));
    }

    cout << (ans == 1'000'000'000'000'007LL ? -1 : ans);

    return 0;
}
/*
Dumbell:

Ta định nghĩa "đô thị hình quả tạ" là một đồ thị cấu trúc như sau:

Là mot đo thị vo huong, gom 1 thanh chan ngang va 2 phan duoc noi bang thanh nay la 2 do thi đay đủ.

Cho một đô thị ban đầu gồm N đinh, M canh. Ta cần tạo ra đo thị hình qua ta bang cach them mot so canh vao. Hỏi so canh ít nhat cần thêm vào là bao nhiêu ??????

--------------------------

nhận xét: cấu trúc hình quả tạ:
    bên trái: n đỉnh - bên phải có x-n đỉnh
1 đồ thị đầy đủ x đỉnh: left= x(x-1)/2 cạnh
..............n-x.....: right = (x-n)(x-n-1)/2
thanh ngang: 1

tổng cạnh: x(x-1)/2 + (x-n)(x-n-1)/2 + 1

tổng số cạnh cần bổ sung: x(x-1)/2 + (x-n)(x-n-1)/2 + 1 - M
--------------------------------------------------------------------------------
Gọi f[i][j][state] có thể hay không thể chọn 1 đồ thị:
    - chọn i thành phần liên thông.
    - chọn j = x(1 bên quả tạ có x đỉnh)
    - state = 0; không sử dụng cầu làm thanh quả ta. state = 1; sử dụng cầu làm thanh quả ta.

BTCS: f[0][0][0] = 0;

xét thành phần liên thông i+1:

không chấp nhận tplt i+1 vào trong vùng có j đỉnh; (thêm tplt vào bên còn lại)
    f[i+1][j][state] = true
chấp nhận tplt i+1: vào trong vùng có j đỉnh (thêm tplt vào bên có j đỉnh)
    f[i+1][j + size[i+1]][state] = true;
--------- sử dụng cầu trong thành phần liên thông i+1 làm thanh quả tạ
nếu state == 0 && v[i+1]!= rỗng ()
    nếu ta chọn số lượng đỉnh sau khi tách tplt thứ i+1 là v[i+1][k]
    f[i+1][j+ v[i+1][k]] [1] = true;

đáp án bài toán:
    x đc tạo nếu f[nComponents][x][0] == true || f[nComponents][x][1]==true

    2 <= n <= 100'000
    0 <= m <= 100'000
    =>độ phức tạp. 2*(10^10) -> TLE
-------------------------------
gọi f[i][state] là tập hợp những giá trị x khi chọn và k chọn một vài tp liên thông ban đầu và trạng thái state

state = 0: ta chưa chọn bat kỳ cạnh nao làm thanh qua tạ
state = 1: ta đa chon 1 canh nao do lam thanh qua ta roi.
-------------------------------
ta lưu f[i][state] như là các bitset, mỗi bitset gồm 100000 bit.

bài toán cơ sở: f[0][0].set(0, 1)

công thức qhđ:

với f[i][state], xét thanh phần liên thông thứ i+1

1. ta không ket nạp cac đinh trong tplt thứ i+1 vao trong cac trang thai ma f[i][state] đang luu:
    f[i+1][state] |= f[i][state]
2. ta kết nạp các đinh trong tplt thứ i+1 vào trong cac trạng thai ma f[i][state] đang luu:
    f[i+1][state] |= f[i][state] << sz[i+1]
3. nếu state == 0 và v[i+1] != rỗng, nếu chọn v[i+1][k] làm số lượng đinh kết nạp: f[i+1][1] |= f[i][state] << v[i+1][k]
đap an bai toan: Tap hop cac x thoa man la f[nComponent][0] | f[nComponent][1]

Một thao tác xử lý trong bit có độ phức tạp là 0(V/64) với V là số lượng bit

Số thao tác: 100000 * 100000 / 64
*/