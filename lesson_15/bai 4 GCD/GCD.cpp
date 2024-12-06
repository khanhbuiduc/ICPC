#include <bits/stdc++.h>
using namespace std;
int n, p, k;
vector<int64_t> st;
vector<int64_t> a;

void buildTree()
{
    p = 1;
    while (p < k)
        p <<= 1;
    st.assign(4 * p, 0);
    for (int i = 0; i < k; i++)
    {
        st[p + i] = a[i];
    }
    for (int i = p - 1; i > 0; i--)
    {
        st[i] = __gcd(st[2 * i], st[2 * i + 1]);
    }
}

void update(int i, int64_t val)
{
    int u = p + i;
    st[u] = val;
    while (u > 1)
    {
        u >>= 1;
        st[u] = __gcd(st[2 * u], st[2 * u + 1]);
    }
}
void printArr(vector<int64_t> x)
{
    for (int64_t i : x)
        cout << i << " ";
    cout << "\n";
}
int main()
{
    freopen("GCD.inp", "r", stdin);
    freopen("GCD.out", "w", stdout);
    cin >> n >> k;
    a.resize(n);
    for (int64_t &i : a)
        cin >> i;
    buildTree();
    int64_t maxGCD = st[1];
    for (int i = k; i < n; i++)
    {
        update(i % k, a[i]);
        if (maxGCD < st[1])
            maxGCD = st[1];
    }
    cout << maxGCD << endl;
}