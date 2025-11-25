#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    string s;
    cin >> n >> s;
    if ((n & 1) == 0)
    {
        cout << "No Solution";
        return 0;
    }
    string s1, s2;
    int mid = n / 2;
    // th1: s1 là chuỗi gốc.
    s1 = s.substr(0, mid);
    s2 = s.substr(mid);
    vector<string> ans;
    int j = 0;
    int i = 0;
    int dif = 0;
    while (i < mid)
    {
        if (s1[i] != s2[j])
        {
            dif++;
            j++;
            if (dif == 2)
                break;
        }
        else
        {
            i++;
            j++;
        }
    }
    if (dif < 2)
    {
        ans.push_back(s1);
    }
    // s2 là chuỗi gốc.
    s1 = s.substr(0, mid + 1);
    s2 = s.substr(mid + 1);
    j = 0;
    i = 0;
    dif = 0;
    while (j < mid)
    {
        if (s1[i] != s2[j])
        {
            dif++;
            i++;
            if (dif == 2)
                break;
        }
        else
        {
            i++;
            j++;
        }
    }
    if (dif < 2)
    {
        ans.push_back(s2);
    }
    if (ans.size() == 0)
    {
        cout << "No Solution";
    }
    else if (ans.size() == 1)
        cout << ans[0];
    else if (ans.size() == 2 && ans[0] != ans[1])
    {
        cout << "Multiple Solutions";
    }
    else if (ans.size() == 2 && ans[0] == ans[1])
    {
        cout << ans[0];
    }
}