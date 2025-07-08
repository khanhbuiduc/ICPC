#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define lim 300'005 //
typedef pair<int, int> pii;
typedef long long ll;
ll f[3005][3005][5]; // xét đến pt thứ i, đã có j phần tử, và 5 state đã đc phân tích bên dưới
int a[3005], b[3005];
int main()
{
    int T;
    cin >> T;
    for (int step = 1; step <= T; step++)
    {
        int n, k;
        cin >> n >> k;
        for(int i=1;i<=n;i++)
        cout << endl;
    }
}
/*
Maximum Monogonosity
Cho 2 dãy số a và b gồm N số nguyên. Cho một số nguyên dương K
Nếu ta chọn 1 đoạn [l..r] thì giá trị sẽ được cộng 1 lượng là |bl-ar|+ |br-al|
Các đoạn ta chọn không được phép phủ lên nhau và tổng số lượng phần tử = K
Hỏi tổng giá trị lớn nhất có thể tạo ra là bao nhiêu ????????
7 2
1 3 7 6 4 7 2
1 5 3 2 7 4 5
Đoạn [3..3] và [4..4]
Đoạn [3..3] có chi phí: |3 - 7| + |3 - 7| - 8
Đoạn [4..4] có chi phí: |2 - 6| + |2 - 6| = 8
Đoạn [3..4] có chi phí: 16

------------------
📝 Tóm gọn dễ hiểu
Bài này bản chất là DP chọn các đoạn không giao nhau.

Mỗi đoạn có 4 kiểu giá trị khi phá trị tuyệt đối.

Ở mỗi phần tử:

    hoặc bỏ qua

    hoặc bắt đầu đoạn mới (nếu ngoài đoạn)

    hoặc tiếp tục đoạn hiện tại (nếu đang trong đoạn)
---------------

nhận xét:
    - |x - y| = max(x-y, y-x)
    - |b[l] - a[r]| + |b[r] - a[l]|
        sẽ có 4 trường hợp:(*)
            (b[l] - a[r]) + (b[r] - a[l])  = b[r] - a[r] +...
            (b[l] - a[r]) + (a[l] - b[r])  = - b[r] - a[r] + ...
            (a[r] - b[l]) + (b[r] - a[l])  = b[r] + a[r] +...
            (a[r] - b[l]) + (a[l] - b[r])  = - b[r] + a[r] +...
            ==>4 state
gọi f[i][j][state]: tổng giá trị lớn nhất
    - i: xét i phần tử ban đầu
    - j: j pt đã đc chọn trong đoạn
    - state:
        = 0 là k thuộc đoạn nào
        = 1,2,3,4 tương ứng vs 4 trạng trái nêu trên (*)
bài toán cơ sở:
    - f[0][0][0] = 0
    - f[i][j][state] = inf
kết quả:
    ans = max(f[n][K][state]) với state = 0..4

QHD:(f[i][j][state] != inf)
    không chọn pt thứ i+1
        f[i+1][j][0] = max(f[i+1][j][0], f[i][j][state])
    chọn pt thứ i+1 là đoạn mới: l=r=i+1
        f[i+1][j+1][1] = max(f[i+1][j+1][1], f[i][j][state] + cal(l,r,1))
        f[i+1][j+1][2] = ...
        f[i+1][j+1][3] = ...
        f[i+1][j+1][4] = ...
    chọn pt thứ i+1 là tiếp tục đoạn hiện tại:(state != 0) bỏ phần i và thêm phần i+1
        state = 1: f[i+1][j+1][1] = max(f[i+1][j+1][1], f[i][j][state] - (b[i] - a[i]) + (b[i+1] - a[i+1]) )
        state = 2: f[i+1][j+1][2] = max(f[i+1][j+1][2], f[i][j][state] - (- b[i] - a[i]) + (- b[i+1] - a[i+1]))
        state = 3: f[i+1][j+1][3] = max(f[i+1][j+1][3], f[i][j][state] - (b[i] + a[i]) + (b[i+1] + a[i+1]))
        state = 4: f[i+1][j+1][4] = max(f[i+1][j+1][4], f[i][j][state] - (- b[i] + a[i]) + (- b[i+1] + a[i+1]))
*/