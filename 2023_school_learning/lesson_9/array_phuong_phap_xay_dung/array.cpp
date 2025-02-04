#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("array.inp", "r", stdin);
    freopen("array.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n, 0);
    int val = l | 1; // nếu n là chẵn l+1;
    int i = 0;

    while (val <= r)
    {
        // e-3
        a[i++] = val;
        // e-2
        val += 2;
        if (val <= r)
            a[i++] = val;
        // e
        val++;
        if (val <= r)
            if (!(val % 3))
                a[i++] = (val - 2) % 5 ? val - 2 : val + 2;
            else
                a[i++] = val;
        // tiếp theo tính e+1
        val++;
    }
    // nếu vẫn chưa đủ số, lặp lại 3 số cuối đến khi đủ
    vector<int> last3 = {a[i - 3], a[i - 2], a[i - 1]};
    while (i < n)
        for (int num : last3)
            if (i < n)
                a[i++] = num;
    for (int num : a)
        cout << num << " ";
}
// nhận xét: 3 số liên tiếp nhau không quá 1 số chẵn
// có không quá n/3 số chẵn cần tìm
// cứ mỗi 2 số lẻ thêm 1 số chẵn vào
// số chẵn: e thì xung quang nó: e-3,e-1,e,e+1,e+3
// ước chung chỉ có thể là 3. nên nếu e/3 thay e=e+2 hoặc e-2;
// khi đó, e-3,e-1,e+-2, e+1,e+3 có thể chia hết cho 5
// chọn e+-2 mà không chia hết cho 5;