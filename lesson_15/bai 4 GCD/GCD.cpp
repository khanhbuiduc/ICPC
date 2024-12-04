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
        st[i] = __gcd(a[2 * i], a[2 * i + 1]);
    }
}

void update(int i, int64_t val)
{
    int u = p + i;
    st[u] = val;
    while (u > 0)
    {
        u >>= 1;
        st[u] = __gcd(st[2 * u], st[2 * u + 1]);
    }
}
int main()
{
    freopen("GCD.inp", "r", stdin);
    freopen("GCD.out", "w", stdout);
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    buildTree();
    int64_t max = st[0];
    for (int i = k; i < n; i++)
    {
        update(i % k, a[i]);
        if (max < st[0])
            max = st[0];
    }
    cout << max;
}