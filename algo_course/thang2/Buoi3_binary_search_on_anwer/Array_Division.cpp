#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define lim 200'000'000'000'007
typedef pair<int, int> pii;
typedef long long ll;
int n, k;
int a[200'001];
bool isDivision(ll sum)
{
    int countSubArr = 1;
    ll subArrSum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > sum)
            return false;
        if (subArrSum + a[i] <= sum)
            subArrSum += a[i];
        else
        {
            subArrSum = a[i];
            countSubArr++;
        }
        if (countSubArr > k)
            return false;
    }
    return true;
}
void binary_search()
{
    ll lo = 1, hi = lim;
    ll ans = lim;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if (isDivision(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    cout << ans;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    binary_search();
    return 0;
}

/*
    binary search dựa trên kết quả:
        5 3
        2 4 7 3 5
    nhận xét:   nếu giới hạn L thỏa mãn chia dãy thành k phần thì L'>L cũng thỏa mãn
                nếu L n không chia đc thì L'<L cũng k chia đc;
                tổng [1-2*10^15]
    mid = (lo+hi)/2;
    với mid giới hạn là mid có thể chia dãy thành k phần tổng<=mid hay không;
        nếu đc lưu trữ tạm thời ans và tìm mid nhỏ hơn thỏa mãn
        nếu không tìm mid lớn hơn thỏa mãn

    kiểm tra có tách đc thành k dãy có tổng < mid không:
        total=0, count =0;
        [5,3,3,1,9,2,4,4,6,3]
        mid =18;
        total =5+3+3+1<18 count++
        total =9+2+4<18 count++;
        total = 6+3<18 count ++;
        count<3: thỏa mãn;
    lấy mid: O(log(2*10^15))=33 lần
    kiểm tra mid thỏa mãn: O(n);
    => O(n);


*/