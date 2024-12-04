#include <bits/stdc++.h>
using namespace std;
#define all(a) begin(a), end(a)
int main()
{
    freopen("mexes.inp", "r", stdin);
    freopen("mexes.out", "w", stdout);
    // a: vector<int>;mex:int;B:vector<int>;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    // khi có 2 phần tử giống nhau thì phần tử thứ 2 sẽ không ảnh hưởng đến tìm mex;
    // sort a và chỉ giữ lại 1 phần tử khi có nhiều phần tử giống nhau
    sort(all(a));
    a.resize(unique(all(a)) - begin(a));
    n = a.size();
    // phương án tối ưu nhất: đảo số lớn nhất của arr a lên đầu sau đó tính mex;
    a.insert(a.begin(), a.back());
    int mex = 0;
    if (a[1] != 0)
    {
        cout << "0";
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] == mex)
        {
            mex++;
            continue;
        }
        cout << ++mex;
        return 0;
    }
    // đáp án sẽ là mex[cuối] +1;
}