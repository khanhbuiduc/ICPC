#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> l(13);
void subtask1()
{
    int ln = l[0];
    int L, R;
    int n = s.size();
    int count;
    for (int i = 0; i < n; i++)
    {
        if (ln % 2 == 1) // lẻ
        {
            count = 1;
            L = i - 1;
            R = i + 1;
            while (-1 < L && R < n)
            {
                if (s[L] == s[R])
                    count += 2;
                else
                    break;
                if (count == ln)
                {
                    cout << "YES" << "\n";
                    return;
                }
                L--;
                R++;
            }
        }
        else
        {
            count = 0;
            L = i;
            R = i + 1;
            while (-1 < L && R < n)
            {
                if (s[L] == s[R])
                    count += 2;
                else
                    break;
                if (count == ln)
                {
                    cout << "YES" << "\n";
                    return;
                }
                L--;
                R++;
            }
        }
    }
    cout << "NO";
}
int main()
{
    // freopen("cutstring.inp", "r", stdin);
    // freopen("cutstring.out", "w", stdout);

    int T;
    cin >> s >> T;
    while (T--)
    {
        int k;
        cin >> k;
        for (int i = 0; i < k; i++)
            cin >> l[i];
        if (k == 1)
            subtask1();
    }
}