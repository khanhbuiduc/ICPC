#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
pii it[200'005]; // val,pos.
int a[200'005];
int inf = 50;
bool compare(pii a, pii b)
{

    if (a.ff < b.ff)
        return true;
    else if (a.ff > b.ff)
        return false;
    else if (a.ss > b.ss)
        return true;
    else
        return false;
}
void build(int index, int L, int R)
{
    if (L == R)
    {
        it[index] = {a[L], L};
        return;
    }
    int mid = (L + R) / 2;
    build(2 * index, L, mid);
    build(2 * index + 1, mid + 1, R);
    it[index] = min(it[2 * index], it[2 * index + 1], compare);
}

pii get(int index, int L, int R, int pos) // tìm min: 1-> pos
{
    if (L > pos)
    {
        return {inf, inf};
    }
    if (R <= pos)
    {
        return it[index];
    }
    int mid = (L + R) / 2;
    pii vLeft = get(2 * index, L, mid, pos);
    pii vRight = get(2 * index + 1, mid + 1, R, pos);
    return min(vLeft, vRight, compare);
}
void update(int index, int L, int R, int pos, int val)
{
    if (L == R)
    {
        it[index].ff = val;
        return;
    }
    int mid = (L + R) / 2;
    if (pos <= mid)
        update(2 * index, L, mid, pos, val);
    else
        update(2 * index + 1, mid + 1, R, pos, val);
    it[index] = min(it[2 * index], it[2 * index + 1], compare);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string s;
    cin >> s;
    int n = s.size();
    FOR(i, 1, n)
    {
        a[i] = s[i - 1] - 'a';
    }
    build(1, 1, n);
    stack<int> store;
    store.push(n);
    string ans = "";
    while (!store.empty())
    {
        int top = store.top();
        auto [val, pos] = get(1, 1, n, top);
        if (val == inf)
        {
            store.pop();
            continue;
        }
        // 1->n có min.
        ans.push_back(val + 'a');
        store.push(pos);
        a[pos] = 50;
        update(1, 1, n, pos, 50);
    }
    cout << ans;
}
/*
abcbacaba

=> tìm min 1->n:
{a,9}
lưu vào stack = {9}
tìm min: 1->9
{a,7}..
lưu vào stack = {9,7,5,1}
---
tìm min 1,1 = "{" stack.pop
tìm min 1,5 = {b,4}
lưu vào stack = {9,7,5,4}


*/