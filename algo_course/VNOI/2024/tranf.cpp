#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

vector<string> tranfs = {"", "AA", "BB", "CC", "DDDD", "BABA", "ACAC", "DABCACB"};
string str1, str2;
int maxOps = 7;
vector<pair<int, int>> bestAns;
bool found = false;

void printAns(const vector<pair<int, int>> &ans)
{
    cout << ans.size() << endl;
    for (const auto &op : ans)
    {
        cout << op.first << " " << op.second << endl;
    }
}

bool canDelete(const string &s, int pos, int type)
{
    string pattern = tranfs[type];
    if (pos + pattern.length() > s.length())
        return false;
    return s.substr(pos, pattern.length()) == pattern;
}

void dfs(string current, const vector<pair<int, int>> &ops)
{
    if (found)
        return;
    if (ops.size() > maxOps)
        return;

    if (current == str2)
    {
        bestAns = ops;
        found = true;
        return;
    }

    if (ops.size() == maxOps)
        return;

    // Thử chèn các xâu con
    for (int pos = 0; pos <= current.length(); pos++)
    {
        for (int type = 1; type <= 7; type++)
        {
            string newStr = current;
            newStr.insert(pos, tranfs[type]);

            vector<pair<int, int>> newOps = ops;
            newOps.push_back({pos + 1, type}); // +1 vì vị trí đánh từ 1

            dfs(newStr, newOps);
        }
    }

    // Thử xóa các xâu con
    for (int pos = 0; pos < current.length(); pos++)
    {
        for (int type = 1; type <= 7; type++)
        {
            if (canDelete(current, pos, type))
            {
                string newStr = current;
                newStr.erase(pos, tranfs[type].length());

                vector<pair<int, int>> newOps = ops;
                newOps.push_back({pos + 1, -type}); // +1 vì vị trí đánh từ 1, âm để biểu thị xóa

                dfs(newStr, newOps);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> str1 >> str2;

    vector<pair<int, int>> initialOps;
    dfs(str1, initialOps);

    if (found)
    {
        printAns(bestAns);
    }
    else
    {
        cout << "No solution found within " << maxOps << " operations" << endl;
    }

    return 0;
}