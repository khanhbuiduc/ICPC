#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
int n, q;
int l, r;
int a[200'005], preXor[200'005];
map<int, vector<int>> list_pos;

void initial()
{
    list_pos.clear();
    cin >> n >> q;
    preXor[0] = 0;
    list_pos[0].push_back(0);

    FOR(i, 1, n)
    {
        cin >> a[i];
        preXor[i] = preXor[i - 1] ^ a[i];
        list_pos[preXor[i]].push_back(i);
    }
}

int find_minLeft()
{
    vector<int> &position = list_pos[preXor[r]];
    int lo = 0, hi = position.size() - 1;
    int minLeft = -1;

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (position[mid] + 1 >= r)
        {
            hi = mid - 1;
        }
        else if (position[mid] + 1 > l)
        {
            minLeft = position[mid] + 1;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return minLeft;
}

int find_maxRight()
{
    vector<int> &vL = list_pos[preXor[l - 1]];
    int lo = 0, hi = vL.size() - 1;
    int maxRight = -1;

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (vL[mid] <= l)
        {
            lo = mid + 1;
        }
        else if (vL[mid] < r)
        {
            maxRight = vL[mid];
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return maxRight;
}

void solve()
{
    int Xor_lr = (preXor[r] ^ preXor[l - 1]);

    if (Xor_lr == 0)
    {
        cout << "YES\n";
        return;
    }
    int minLeft = find_minLeft();
    int maxRight = find_maxRight();

    if (minLeft != -1 && maxRight != -1 && maxRight >= minLeft)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        initial();
        while (q--)
        {
            cin >> l >> r;
            solve();
        }
        cout << endl; // In dòng trống giữa các test (theo đáp án)
    }
}
/*
cho a[1..n] chia thành k phần sao cho tất cả các phần xor bằng nhau, k>1;
xor[1..n1], xor[n1+1..n2]... xor[n(k-1)+1..nk];
---
nhận xét 1:
nếu chia đc thành n phần bằng nhau.
    - nếu xor(tất cả các phần) có 2 kết quả
        có chẵn phần: kết quả bằng 0 => chắc chắn có
        có lẻ phần kết quả bằng a => mỗi phần có xor bằng a
            => có thể chia thành 3 đoạn = nhau yes. không có thì no.
---
3 đoạn bằng nhau:
preXor[l..x] = prexor[x+1..y] = prexor[y+1..r] = prexor[l..r]

=> prexor[x]^prexor[l-1] = prexor[y] ^ prexor[x] = prexor[r]^prexor[y] = prexor[r] ^ prexor[l-1]
l<=x < y< r
=> prexor[x] = prexor[r]
=> prexor[y] = prexor[l-1]
=> position[prexor[i]] = {i}
---
x: tìm x nhỏ nhất prexor[x] = prexor[r]
    binary_search(x, L,R, position[prexor[r]]), ưu tiên vị trí nhỏ nhất. tìm min
    binary_search(y, L,R, position[prexor[l-1]]), ưu tiên tìm vị trí gần R nhất
y:
*/