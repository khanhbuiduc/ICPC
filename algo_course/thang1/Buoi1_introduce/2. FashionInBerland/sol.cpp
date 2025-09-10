#include <bits/stdc++.h>
using namespace std;
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, ai;
    cin >> n;

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> ai;
        if (ai == 0)
        {
            count++;
            if (count > 1)
            {
                cout << "NO";
                return 0;
            }
        }
    }
    if (n == 1 && count == 1 || n != 1 && count == 0)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}