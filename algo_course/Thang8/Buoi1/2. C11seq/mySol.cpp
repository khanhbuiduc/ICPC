#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
int n, minSum, maxSum;
vector<int> a;
int merge(int L, int R)
{
}
int solve(int l, int r)
{
    if (l == r)
    {
        return 0;
    }
    int mid = (l + r) / 2;
    int left = solve(l, mid);
    int right = solve(mid + 1, r);
    vector<int> freLeft, sufRight;
    freLeft.push_back(0);
    
}
int main()
{
    cin >> n >> minSum >> maxSum;
    a.resize(n + 1);
    FOR(i, 1, n)
    cin >> a[i];
}
/*
merge Tree
cho, a[1..n]; L,R
đếm số cặp (i...j) để L<=sum(a[i..j])<=R

node quản lý đoạn l->r
    cnt
------
solve(l,r)
    với mỗi i:
    - cnt = 0
    left = solve(l,mid)
    right = soleve(mid + 1, R)
    return merge(L,R)
---------------
merge(left, right)
    cnt = left.cnt + right.cnt
    preLeft, sufLeft,preRight,subRight.
    với mỗi right bs tìm x trong left.pre:
        - x >= L - ri: lower_bound
        - y <= R - ri: upper_bound - 1;
        - nếu x<=y: cnt += (y-x);
*/