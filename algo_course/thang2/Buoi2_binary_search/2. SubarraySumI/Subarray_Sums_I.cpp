#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef long long ll;
bool binary_search(int l, int r, vector<ll> &a, ll x)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] == x)
            return true;
        a[mid] > x ? r = mid - 1 : l = mid + 1;
    }
    return false;
}
int main()
{
    // freopen("input.txt", "r", stdin),
    // freopen("output.txt", "w", stdout);
    int n, x, count = 0;
    cin >> n >> x;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1];
    for (int i = 1; i <= n; i++)
    {
        if (binary_search(0, i - 1, a, a[i] - x))
            count++;
    }
    cout << count;
}
//
/*
n=5,x=7;
2 4 1 2 7
    đếm bao nhiêu mảng con có tổng = 7
    tính tổng tiền tố:
        0 2 6 7 9 16
    tìm  a[r]-a[l-1]=7=> a[l-1]=a[r]-7

    trong đoạn 0->r-1: liệu có a[l-1] mà a[l-1]=a[r]-7 (Binary search)

    ai<=10^9 thì tổng ai<10^18
    */
// đếm tổng