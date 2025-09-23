#include <bits/stdc++.h>
using namespace std;

struct Info
{
    string pre, suf;
    long long cnt;
};

long long countHaha(const string &s)
{
    long long res = 0;
    for (int i = 0; i + 3 < (int)s.size(); i++)
    {
        if (s.substr(i, 4) == "haha")
            res++;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<string, Info> mp;
        string lastVar;

        while (n--)
        {
            string x, op;
            cin >> x >> op;
            if (op == ":=")
            {
                string s;
                cin >> s;
                Info cur;
                cur.cnt = countHaha(s);
                cur.pre = s.substr(0, min(3, (int)s.size()));
                if ((int)s.size() <= 3)
                    cur.suf = s;
                else
                    cur.suf = s.substr(s.size() - 3);
                mp[x] = cur;
            }
            else
            {
                string a, plusSign, b;
                cin >> a >> plusSign >> b;
                Info A = mp[a], B = mp[b], cur;
                cur.cnt = A.cnt + B.cnt + countHaha(A.suf + B.pre);
                cur.pre = (A.pre + B.pre).substr(0, min(3, (int)(A.pre.size() + B.pre.size())));
                string tmp = A.suf + B.suf;
                if ((int)tmp.size() <= 3)
                    cur.suf = tmp;
                else
                    cur.suf = tmp.substr(tmp.size() - 3);
                mp[x] = cur;
            }
            lastVar = x;
        }

        cout << mp[lastVar].cnt << "\n";
    }
}
