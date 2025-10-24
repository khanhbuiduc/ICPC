#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define lim 300'005 //
typedef pair<int, int> pii;
typedef long long ll;
int n;
vector<vector<int>> ans;
vector<int> subset;
vector<int> a;
void backtrack(int pos)
{
    for (int choose = 0; choose <= 1; choose++)
    {
        if (choose == 1)
            subset.push_back(a[pos]);
        if (pos == n - 1)
            ans.push_back(subset);
        else
            backtrack(pos + 1);
        if (choose == 1)
            subset.pop_back();
    }
}
vector<vector<int>> subsets(vector<int> &nums)
{
    backtrack(0);
    for (auto subset : ans)
    {
        for (auto num : subset)
            cout << num << " ";
        cout << endl;
    }
}
int main()
{
    cin >> n;
    a.resize(n);
    for (auto &i : a)
        cin >> i;
    subsets(a);
}