#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("triangles.inp", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    // tam giác không suy biến
    // ai+aj>x với mọi i,j
    // x>aj-ai với mọi i,j
    //=> aj-ai<x<ai+aj
    // tìm max aj-ai và min ai+aj cách tối ưu sort a;
    sort(a.begin(), a.end());
    // max(aj-ai) = hiệu phần tử cuối và đầu;
    int max = a.back() - a[0];
    // min(ai+aj)=tổng 2 phần tử đầu tiên;
    int min = a[0] + a[1];
    // số lượng phần tử sẽ là min(ai+aj) - max(aj-ai)
    min - max <= 0 ? cout << "0" : cout << min - max - 1;
}