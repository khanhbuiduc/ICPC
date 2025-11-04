// Max Prize
#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef pair<char, int> pci;

int n, k;
string s, ans = "";
int f[100'005];      // Fenwick Tree: f[i] đếm số phần tử đã được chọn từ vị trí 1->i
vector<int> a[10];   // a[i]: danh sách vị trí của chữ số i trong chuỗi s
int p_cur[10] = {0}; // p_cur[i]: con trỏ đang xét đến vị trí nào của chữ số i trong a[i]

// Hàm update Fenwick Tree: cập nhật giá trị tại vị trí index
void update(int index, int vals)
{
    for (; index <= n; index += index & -index)
        f[index] += vals;
}

// Hàm get Fenwick Tree: lấy tổng từ 1->index
int get(int index)
{
    int res = 0;
    for (; index > 0; index -= index & -index)
        res += f[index];
    return res;
}

// Hàm lấy chữ số lớn nhất có thể với số bước swap còn lại
void get_dg()
{
    int u, v;
    for (int i = 9; i >= 0; --i)
    {
        if (a[i].empty() || p_cur[i] >= a[i].size())
            continue;
        u = a[i][p_cur[i]];
        v = u - get(u + 1);

        // Nếu số bước swap cần > k thì bỏ qua
        if (k < v)
            continue;
        // update
        k -= v;
        update(u + 1, 1);
        p_cur[i]++;             // Tăng con trỏ của chữ số i
        s[u] = '*';             // Đánh dấu vị trí u trong chuỗi s
        ans += (char)('0' + i); // Thêm chữ số i vào kết quả
        break;                  // Chỉ chọn 1 chữ số mỗi lần
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> s;
    n = s.size();

    // Lưu vị trí của từng chữ số trong chuỗi
    for (int i = 0; i < n; ++i)
    {
        int r = s[i] - '0';
        a[r].push_back(i);
    }

    // Chọn từng chữ số lớn nhất có thể
    while (k > 0 && ans.size() < n)
    {
        get_dg();
    }

    // Thêm các chữ số còn lại chưa được chọn
    for (int i = 0; i < n; ++i)
        if (s[i] != '*')
            ans += s[i];

    // Nếu còn k lẻ và không có 2 chữ số giống nhau liên tiếp -> đổi 2 chữ số cuối
    if (k > 0 && (k & 1))
    {
        bool fl = true;
        for (int i = 1; i < n; ++i)
            if (ans[i - 1] == ans[i])
            {
                fl = false;
                break;
            }
        if (fl)
            swap(ans[n - 1], ans[n - 2]);
    }

    cout << ans;
    return 0;
}

/*
Bài toán: MAX_PRIZE
- Cho số n (<=10^5 chữ số)
- Được đổi chỗ 2 chữ số cạnh nhau đúng k lần (k <= 10^9)
- Tìm số lớn nhất có thể
--------------
Ý tưởng:
1. Lưu vị trí của từng chữ số 0-9 trong chuỗi
2. Chọn chữ số lớn nhất có thể đưa lên đầu với số bước swap ≤ k
3. Sử dụng Fenwick Tree để tính số bước swap cần thiết:
   - v = u - get(u+1): số vị trí phía trước u đã bị chọn
   - Vị trí thực tế hiện tại của u = u - v
4. Nếu còn k lẻ và không có 2 số giống liên tiếp -> đổi 2 số cuối
*/