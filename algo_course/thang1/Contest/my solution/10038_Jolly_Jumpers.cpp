#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef long long ll;
int n;
int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> a(n);
        set<int> s;
        int result = 1;
        for (auto &i : a)
            cin >> i;
        for (int i = 1; i <= n - 1; i++)
        {
            int dif = abs(a[i] - a[i - 1]);
            if (dif >= n || s.find(dif) != s.end())
            {
                result = 0;
                break;
            }
            s.insert(dif);
        }
        cout << ((result == 1) ? "Jolly" : "Not jolly") << "\n";
    }
}