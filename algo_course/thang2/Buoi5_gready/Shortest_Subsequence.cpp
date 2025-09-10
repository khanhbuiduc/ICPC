#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define lim 300'005 //
typedef pair<int, int> pii;
typedef long long ll;
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string str;
    cin >> str;
    deque<int> a, c, g, t;
    for (int i = 0; i < str.length(); i++)
    {
        switch (str[i])
        {
        case 'A':
            a.push_back(i);
            break;
        case 'C':
            c.push_back(i);
            break;
        case 'G':
            g.push_back(i);
            break;
        case 'T':
            t.push_back(i);
            break;
        }
    }
    string ans = "";
    while (!a.empty() && !c.empty() && !g.empty() && !t.empty())
    {
        int maxCharIndex = max(a.front(), max(c.front(), max(g.front(), t.front())));
        ans += str[maxCharIndex];
        while (!a.empty() && a.front() <= maxCharIndex)
            a.pop_front();
        while (!c.empty() && c.front() <= maxCharIndex)
            c.pop_front();
        while (!g.empty() && g.front() <= maxCharIndex)
            g.pop_front();
        while (!t.empty() && t.front() <= maxCharIndex)
            t.pop_front();
    }
    if (a.empty())
        ans += "A";
    else if (c.empty())
        ans += "C";
    else if (g.empty())
        ans += "G";
    else if (t.empty())
        ans += "T";
    cout << ans;
}