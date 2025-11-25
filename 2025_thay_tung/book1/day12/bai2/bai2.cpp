#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
int x[100'005], p[100'005];
vector<tiii> net;
multiset<int> can;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, coin, maxOil, price;
    cin >> n >> coin >> maxOil;
    FOR(i, 1, n)
    {
        cin >> x[i] >> p[i];
        net.emplace_back(x[i], p[i], 1);
        net.emplace_back(x[i] + maxOil, p[i], -1);
    }
    sort(ALL(net));
    ll cur_x = 0;
    ll ans = 0;
    for (auto &[n_x, p, type] : net)
    {
        ll dist = n_x - cur_x;
        if (dist > 0)
        {
            if (can.empty())
                break;
            ll cost = *can.begin();
            if (cost * dist <= coin)
                coin -= cost * dist;
            else
            {
                dist = coin / cost;
                ans = cur_x + dist;
                break;
            }
        }
        if (type == 1)
            can.insert(p);
        else
            can.erase(can.find(p));
        cur_x = n_x;
        ans = n_x;
    }
    cout << ans << endl;
}
/*
xe {B đồng,max C lít xăng/xe}
ban thùng xăng rỗng
n trạm:
    trạm i mốc xi
    tiêu hao: 1l/ 1 chặng đơn vị
    trạm i: pi/lit, mua nguyên lit xăng
---
quãng đường max đi đc.
thêm quãng cuối 10^9 +1, 10^9 +1
ban đầu:
    s = 0
    coin = 10
    price = 3
    chặng 0->1: p = 3 < coin
        s = 1 update coin, price
    1->4: p = 3 < coin
        s= 4, udate coin = 4, price = 1

*/