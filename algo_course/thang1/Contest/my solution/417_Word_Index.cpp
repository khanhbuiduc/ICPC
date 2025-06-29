#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef long long ll;
int n;
unordered_map<string, int> s;
void gen(string cur, int last_char, int max_length, int &count)
{

    if (cur.length() == max_length)
    {
        s[cur] = count++;
        return;
    }
    for (int i = last_char; i < 26; i++)
        gen(cur + char('a' + i), i + 1, max_length, count);
}
int main()
{
    int count = 1;
    for (int i = 1; i <= 5; i++)
        gen("", 0, i, count);
    string str;
    while (cin >> str)
    {
        if (s.find(str) == s.end())
        {
            cout << "0\n";
            continue;
        }
        else
        {
            cout << s[str] << "\n";
        }
    }
    return 0;
}