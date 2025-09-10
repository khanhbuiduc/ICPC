#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define lim 1'000'000'007
typedef pair<int, int> pii;
typedef long long ll;
int t, n, c;
int a[100'005];
bool checkArrangeCow(int x)
{
    int previodBarnI = a[1];
    int countCow = 1;
    for (int i = 2; i <= n; i++) // bò 1 đã ở chuồng 1
    {
        int curBarnI = a[i];
        if (curBarnI - previodBarnI >= x)
        {
            previodBarnI = a[i];
            countCow++;
        }
        if (countCow == c)
            return true;
    }
    return false;
}
void binary_search()
{
    int li = 0, hi = lim;
    int ans = 0;
    while (li <= hi)
    {
        int mid = (li + hi) / 2;
        if (checkArrangeCow(mid))
        {
            ans = mid;
            li = mid + 1;
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
    cin >> t;
    while (t--)
    {
        cin >> n >> c;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a, a + n);
        binary_search();
    }
}

/*
     n=5; cow=3
     a[1 2 8 4 9]

    nên sắp sếp vị trí a[1,2,4,8,9]
    [] _ _ [] _ _ _ [] []

    binary_search theo kết quả: xi[1..1*10^9]
    mid=(lo+hi)/2;
    liệu có để đặt c con bò bao chuồng sao cho 2 con bò cách nhau tối thiểu mid vị trí;
        nếu  đặt được xét khoảng trên xem thỏa mãn không
        nếu không được xét khoảng dưới
    kiểm tra có thể đặt c con bò vào n chuồng cách tối thiểu n vị trí:
        bò 1:  chuồng 1;
        bò 2->c
            duyệt lần lượt trong arr xem có vị trí thỏa mã không
            nếu không được trả về false
        trả về true;
*/