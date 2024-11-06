#include <bits/stdc++.h>
using namespace std;
ifstream fi("input.txt");
ofstream fo("output.txt");
bool recursion(int S, vector<int> &cashes, vector<int> &cur, int begin)
{
    if (S == 0)
    {
        for (int i = 0; i < cur.size(); i++)
        {
            fo << to_string(cur[i]) + " ";
        }
        return true;
    }
    if (S < 0)
        return false;
    for (int i = begin; i < cashes.size(); ++i)
    {
        cur.push_back(cashes[i]);

        if (recursion(S - cashes[i], cashes, cur, i + 1))
        {
            return true;
        }
        cur.pop_back();
    }
    return false;
}
int main()
{
    int n, S;
    fi >> n >> S;
    vector<int> cashes = {};
    vector<int> cur = {};
    for (int i = 0; i < n; i++)
    {
        int ti;
        fi >> ti;
        cashes.push_back(ti);
    }
    sort(cashes.begin(), cashes.end());

    bool isTrue = recursion(S, cashes, cur, 0);
    if (!isTrue)
    {
        fo << "-1";
    }
}