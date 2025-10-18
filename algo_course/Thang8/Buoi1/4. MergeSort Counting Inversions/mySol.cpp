#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
int a[100005];
int t, n;
struct node
{
    ll cnt = 0;
    vector<int> sorted;
};
node merge(node &L, node &R)
{
    node cur;
    // cur->sorted
    int li = 0, ri = 0;
    while (li < (int)L.sorted.size() && ri < (int)R.sorted.size())
    {
        int l_val = L.sorted[li], r_val = R.sorted[ri];
        if (l_val <= r_val)
        {
            cur.sorted.push_back(l_val);
            li++;
        }
        else
        {
            cur.sorted.push_back(r_val);
            ri++;
        }
    }
    while (li < (int)L.sorted.size())
    {
        int l_val = L.sorted[li];
        cur.sorted.push_back(l_val);
        li++;
    }
    while (ri < (int)R.sorted.size())
    {
        int r_val = R.sorted[ri];
        cur.sorted.push_back(r_val);
        ri++;
    }

    cur.cnt = L.cnt + R.cnt;
    for (auto i : R.sorted)
    {
        auto upper = upper_bound(ALL(L.sorted), i);
        cur.cnt += (L.sorted.size() - (int)(upper - L.sorted.begin()));
    }
    return cur;
}
node solve(int L, int R)
{
    if (L == R)
    {
        node cur;
        cur.cnt = 0;
        cur.sorted = {a[L]};
        return cur;
    }
    int mid = (L + R) / 2;
    node left = solve(L, mid);
    node right = solve(mid + 1, R);
    return merge(left, right);
}
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        FOR(i, 1, n)
        {
            cin >> a[i];
        }
        cout << solve(1, n).cnt << endl;
    }
}

/*
cho a[1..n]
    in ra:
        max: chuỗi con arr;
        max: chuỗi con;
tính subsequences
    -1, 2, 3, -4, 5, 10
    chỗi con arr: 2 + 3 - 4 + 5 + 10 = 16
    chuỗi con: 2 + 3 + 5 + 10 = 20
--------------------
tính subarray:
    chia arr làm 2 phần: tính max subarray bên trái và bên phải
    cur.max = left.max || right.max || max(left.subfix) + max(right.prefix)
    node: max;
---------------------------
2 1 3 1 2
---------------------------
bên trái và bên phải:
số lượng nghịch thế = số lượng nghich thế trái + số lượng nghịch thế phải + more

node{
cnt;
sorted[];
}
node merge(){
    cur= sorted[l..r]
    cur.cnt = left.cnt + right.cnt + more
    more = 0;
    for(auto i: right){
        upper = upper_bound(all(left), i)
        more += (left.size() - (int)(upper - left.begin());
    }
}
----------------------------

*/