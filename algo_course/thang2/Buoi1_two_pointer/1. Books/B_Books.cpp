#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef long long ll;
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    int maxbook = 0;
    for (int &i : a)
        cin >> i;
    int l = 0, sum = 0;
    for (int r = 0; r < n; r++)
    {
        sum += a[r];
        if (sum > t)
        {
            sum -= a[l];
            l++;
        }
        maxbook = max(maxbook, r - l + 1);
    }
    cout << maxbook;
}
/* two-pointer technique (sliding window)
nx: khi tìm thấy l->r>max thì tổng của đoạn phủ l->r không thỏa mãn
//1 ≤ n ≤ 10^5
O(n)
*/