#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef long long ll;
bool isExist(int l, int r, vector<int> &a, int x)
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
    int t;
    cin >> t;
    while (t--)
    {
        int n, p, count = 0;
        cin >> n >> p;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        sort(a.begin(), a.end());
        for (int i = 1; i < n; i++)
        {
            if (isExist(0, i - 1, a, p - a[i])) // tìm trong khoảng [0,i-1];
                count++;
        }
        cout << count << "\n";
    }
}
// bs
/*
    n=4,p=12
    9 -3 4 3
    sort=> -3 3 4 9
    bs(0,i,12-a[i])
*/