#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define lim 2'00'005 //
typedef pair<int, int> pii;
typedef long long ll;
int n, k;
int a[lim], b[lim];
ll sum[lim], D[lim];
bool check(int mid)
{
    for (int i = 1; i <= n; i++)
        b[i] = a[i] < mid ? 0 : 1;
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + b[i];
    for (int i = 1; i <= n; i++)
    {
        D[i] = 2 * sum[i] - i;
        // cout << D[i] << " ";
    }
    ll minL = D[0];
    for (int i = k; i <= n; i++)
    {
        if (D[i] > minL)
            return true;
        minL = min(minL, D[i - k + 1]);
    }
    return false;
}
void binary_search()
{
    int lo = 1, hi = n;
    int ans = -1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    cout << ans << "\n";
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    binary_search();
}
// n=10; length=5
// 1 9 2 2 6 7 10 3 3 4
/*
    median:{1,5} 1 9 2 2 6-> 1 2 3 6 9: ,median =3
        thay vì duyệt từng đoạn l-r rồi sort tìm median O(n^3*log(n))
    ta làm ngược lại cho trung vị  M tìm xem liệu tồn tại median>=M không
    binary search trên kết quả:
    a=1 9 2 2 6 7 10 3 3 4
    1 9 2 2 6 tồn tại median>=M không mà k cần sort
        <6:3
        >=6:2
        chỉ khi (số >=6) > (số < 6) thì mới tồn tại
    B=[0,1,0,0,1,1,1,0,0,0] b[i]=0 khi a[i]<6 và ngược lại
    sum=[0,1,1,1,2,3,4,4,4,4]
        => sum[r]-sum[l-1] > (r-l+1)- sum[r]-sum[l-1]
        => 2*(sum[r]-sum[l-1]) > (r-l+1)
        => 2*sum[r]-r > 2*sum[l-1] -(l-1)
    dặt 2*sum[i]-i =D[i]
        => D[r]>D[l-1]
    min=[D[1]]
    duyệt i: K->n
        min=min[min,D[i-k+1]]
        if(D[i]>min) return true;
    O();    
*/  