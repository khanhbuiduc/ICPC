#include <bits/stdc++.h>
using namespace std;
// số ai đã gặp trước đó không làm thay đổi kết quả tìm mex. dồn các số đã gặp xuống cuối dãy
// dãy số bi=mex(a1,a2,...ai) không giảm
int main()
{
    freopen("mexes.inp", "r", stdin);
    freopen("mexes.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    // nhận xét
    //  Nếu sắp xếp dãy số a tăng dần
    sort(begin(a), end(a));
    // với mỗi dãy con chứa các số giống nhau chỉ giữ lại một phần tử
    auto t = unique(begin(a), end(a));
    a.resize(t - begin(a));
    // và đưa phần tử cuối lên đầu, kết quả B sẽ là tối ưu
    a.insert(a.begin(), a.back());
    a.pop_back();
    // tính mexes
    int cur = 0;
    n = a.size();
    vector<int> mexes;
    map<int, int> cnt;

    for (int i = 0; i < n; i++)
    {
        cnt[a[i]]++;     // đánh dấu phần tử đã xuất hiện
        while (cnt[cur]) // tìm phần tử chưa xuất hiện
            cur++;
        mexes.push_back(cur);
    }

    for (auto i : mexes)
        cout << i << " ";
    cout << endl;
    int k = mexes[mexes.size() - 1];
    // if (k == 0) // nếu mex bằng 0
    //     cout << "1";
    // else
    cout << mexes[k] + 1;
}