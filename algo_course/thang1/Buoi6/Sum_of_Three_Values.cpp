#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main()
{
    int n, x;
    cin >> n >> x;
    map<int, int> s;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int sum = a[i] + a[j];
            if (s.find(x - sum) != s.end())
            {
                cout << s[x - sum] << " " << i << " " << j;
                return 0;
            }
        }
        s.emplace(a[i], i);
    }
    cout << "IMPOSSIBLE";
}
/*
    for i 1-> (n-1);
    for j i+1->n
            kiểm tra xem trc i có val=x-(a[i]+a[j]) không
*/