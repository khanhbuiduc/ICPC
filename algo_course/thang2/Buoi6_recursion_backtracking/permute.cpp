#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define lim 300'005 //
typedef pair<int, int> pii;
typedef long long ll;
bool used[10];
int n;
vector<vector<int>> ans;
vector<int> per;
vector<int> a;
void backtrack(int pos)
{
    for (int i = 0; i < n; i++)
        if (used[i] == false)
        {
            per[pos] = a[i];
            used[i] = true;
            if (pos == n - 1)
                ans.push_back(per);
            else
                backtrack(pos + 1);
            used[i] = false;
        }
}
vector<vector<int>> permute(vector<int> &nums)
{
    backtrack(0);
    for (auto per : ans)
    {
        for (auto num : per)
            cout << num << " ";
        cout << endl;
    }
}
int main()
{
    cin >> n;
    a.resize(n);
    per.resize(n);
    for (auto &i : a)
        cin >> i;
    permute(a);
}