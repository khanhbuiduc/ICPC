#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define lim 300'005 //
typedef pair<int, int> pii;
typedef long long ll;
string st;
int n;
int cnt[26];
vector<string> listString;
void backtrack(int pos)
{
    if (pos == n)
    {
        listString.push_back(st);
        return;
    }
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] > 0)
        {
            st[pos] = char(i + 'a');
            cnt[i]--;
            backtrack(pos + 1);
            cnt[i]++;
        }
    }
}
int main()
{
    string s;
    cin >> s;
    n = s.length();
    st.resize(n);
    for (auto c : s)
        cnt[c - 'a']++;
    backtrack(0);
    cout << listString.size() << "\n";
    for (auto &curs : listString)
        cout << curs << "\n";
}