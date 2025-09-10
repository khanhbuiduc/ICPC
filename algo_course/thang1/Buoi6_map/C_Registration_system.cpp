#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string i;
    cin >> n;
    map<string, int> s;
    while (n--)
    {
        cin >> i;
        if (s.find(i) == s.end())
        {
            cout << "OK\n";
            s[i] = 1;
        }
        else
        {
            cout << i << s[i] << "\n";
            s[i]++;
        }
    }
}
// O(nlog(n).length(s))