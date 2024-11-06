#include <bits/stdc++.h>
using namespace std;
#define NAME "coloring."
ifstream fi(NAME "inp");
ofstream fo(NAME "out");

typedef long long ll;
typedef long double ld;
const ll N = 1e5, INF = 1e9 + 1000;
pair<ll, ll> seg[N * 4];
vector<ll> perm;
// tạo segment tree
void upd(int v, int l, int r, int pos, int val)
{
    if (l == r - 1)
        seg[v] = {val, pos};
    else
    {
        int mid = (l + r) / 2;
        if (pos < mid)
            upd(v * 2 + 1, l, mid, pos, val);
        else
            upd(v * 2 + 2, mid, r, pos, val);
        seg[v] = max(seg[v * 2 + 1], seg[v * 2 + 2]);
    }
}
// tìm max của đoạn từ l đến r trong segment tree
pair<ll, ll> ask(int v, int l, int r, int askl, int askr)
{
    if (l >= askr || r <= askl)
        return {};
    if (askl <= l && r <= askr)
        return seg[v];
    int mid = (l + r) / 2;
    return max(ask(v * 2 + 1, l, mid, askl, askr), ask(v * 2 + 2, mid, r, askl, askr));
}
// tìm max của đoạn l đến r và xem liệu p có phải max thứ 2 trong đoạn
vector<pair<ll, ll>> ask(int n, int askl, int askr)
{
    vector<pair<ll, ll>> mx = {ask(0, 0, n, askl, askr)};
    ll p = mx[0].second;
    mx.push_back({-INF, -INF});
    if (askl != p)
        mx.back() = max(mx.back(), ask(0, 0, n, askl, p));
    if (p + 1 != askr)
        mx.back() = max(mx.back(), ask(0, 0, n, p + 1, askr));
    if (mx.back().first == -INF)
        mx.pop_back();
    return mx;
}

int main()
{
    ll n, q;
    fi >> n >> q;
    perm.resize(n);
    for (int i = 0; i < n; i++)
    {
        fi >> perm[i];
        upd(0, 0, n, i, perm[i]);
    }
    // kiểm tra từng cặp p,k
    while (q--)
    {
        ll p, k;
        fi >> p >> k;
        // k==1: có 1 cách chọn là chọn chính số đó ở lượt đầu tiên
        if (k == 1)
        {
            fo << "1\n";
            continue;
        }
        p--;
        ll ans = 0;
        //[p,p+k-1] hình 3
        if (p + k <= n)
        {
            // tìm max trong đoạn [p,p+k-1] và [p,p+k];
            vector<pair<ll, ll>> mx = ask(n, p, p + k);
            // b) hình 3: không được chọn m
            if (p + k == n || mx[0].first < perm[p + k])
                ans += (p + k) - mx[0].second - 1;
            // a,c hình 3: đc chọn m
            if (mx[1].second < mx[0].second && (p + k == n || mx[1].first < perm[p + k]))
                ans++; // p+k-m cách chọn
        }
        //[p-k+1,p+1]
        if (p - k + 1 >= 0)
        {
            vector<pair<ll, ll>> mx = ask(n, p - k + 1, p + 1);
            if (p - k < 0 || mx[0].first < perm[p - k])
                ans += mx[0].second - (p - k + 1);
            if (mx[0].second < mx[1].second && (p - k < 0 || mx[1].first < perm[p - k]))
                ans++;
        }
        fo << ans << '\n';
    }
    fo << "\nTime: " << clock() / (double)1000 << " sec";
}
