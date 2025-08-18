#include <bits/stdc++.h>
using namespace std;
#define NAME "gcd."
ifstream fi(NAME "inp");
ofstream fo(NAME "out");

int n, p, k, q;
vector<int64_t> a;
int64_t ans = 0, x;

void upd(int i, int64_t val)
{
    int u = p + i;
    a[u] = val;
    while (u > 0)
    {
        u >>= 1;
        a[u] = __gcd(a[2 * u], a[2 * u + 1]);
    }
}
void buildTree()
{
    // Xác định kích thước cây
    p = 1;
    while (p < k)
        p <<= 1;
    a.assign(4 * p + 5, 0);
    // buildTree
    for (int i = 0; i < k; i++)
        fi >> a[p + i];
    for (int i = p - 1; i > 0; i--)
        a[i] = __gcd(a[i * 2], a[i * 2 + 1]);
}
int main()
{
    fi >> n >> k;
    buildTree(); // build tree của k phần tử đầu
    ans = a[1];
    for (int i = k; i < n; i++) // lần lượt thế từng phần tử với x;
    {
        fi >> x;
        upd(i % k, x);
        ans = max(ans, a[1]);
    }

    fo << ans << "\n";
}