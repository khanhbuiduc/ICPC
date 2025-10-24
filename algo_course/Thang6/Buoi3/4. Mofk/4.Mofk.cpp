#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
using namespace std;
/// template
int n;
string s, s2;
int cal_machine(string s1, string &s2)
{
    int correct = 0, incorrect = 0;
    FOR(i, 0, n - 1)
    s1[i] == s2[i] ? (correct++) : (incorrect++);
    return correct < incorrect;
}
int ask(const string &str)
{
    cout << "? " << str << endl;
    fflush(stdout);
    int ok;
    cin >> ok;
    ok = cal_machine(str, s2); // machine
    cout << ok << endl;
    return ok;
}

string flip(int position)
{
    string ret = s;
    for (int i = 0; i <= position; i++)
    {
        if (ret[i] == '0')
            ret[i] = '1';
        else
            ret[i] = '0';
    }
    return ret;
}
void make_equal()
{
    // Binary search để tìm position để khi flip số lượng vị trí đúng bằng (n+1)/2
    int lo = -1;
    int hi = n - 1;
    int position = -1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        string tmp = flip(mid);
        int ok = ask(tmp);
        if (ok == 0) // correct > wrong
        {
            position = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    s = flip(position); // correct = wrong + 1
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cin >> s2; // machine;
    s = string(n, '0');

    int ok = ask(s);
    if (ok) // correct < wrong
        s = flip(n - 1);
    make_equal();
    string ans = "";
    FOR(i, 0, n - 1)
    {
        int c = s[i] - '0';
        string tmp = s;
        // lật 1 vị trí
        tmp[i] = (c == 0 ? '1' : '0');
        ok = ask(tmp);

        if (ok == 0) // vị trí ban đầu sai
            c = !c;
        ans += (char)(c + '0');
    }

    cout << "! " << ans << endl;
    fflush(stdout);
    return 0;
}

/*
0001111

 0110110
?0000000->1
 1111111
?0001111 ->1
?0111111 ->0
?0011111 ->0
*/