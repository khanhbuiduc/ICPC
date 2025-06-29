#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define lim 300'005 //
typedef pair<int, int> pii;
typedef long long ll;
int a[200'005];
int b[200'005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    int i = 1, j = 1;
    int count = 1;
    int previousIndex = max(a[1], b[1]);
    while (i <= n && j <= n)
    {
        while (i <= n && a[i] <= previousIndex)
            i++;
        while (j <= n && b[j] <= previousIndex)
            j++;
        if (i <= n && j <= n)
        {
            previousIndex = max(a[i], b[j]);
            count++;
        }
    }
    cout << count;
}
