#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
int a[1'000'005];
int n;
typedef tuple<int, int, int, int> tiii; // cnt,indexMin,indexMax,sz;
tiii merge(tiii L, tiii R)
{
    int cnt = 0;
    auto [cnt_L, posMin_L, posMax_L, sz_L] = L;
    auto [cnt_R, posMin_R, posMax_R, sz_R] = R;
    int posMin = min(posMin_L, posMin_R), posMax = max(posMax_L, posMax_R);
    if (posMin == posMin_L && posMax == posMax_L)
        cnt = cnt_L + cnt_R + cnt_L * (sz_R);
    if (posMin == posMin_R && posMax == posMax_R)
        cnt = cnt_L + cnt_R + cnt_R * (sz_L);
    // nếu min 1 bên max 1 bên.
    return {cnt, posMin, posMax, sz_L + sz_R};
}

tiii solve(int L, int R)
{
    if (L == R)
        return {0, L, L, 1};
    int mid = (L + R) / 2;
    tiii left = solve(L, mid);
    tiii right = solve(mid + 1, R);
    return merge(left, right);
}

int main()
{
    priority_queue<int> maxheap1;
    priority_queue<int> maxheap2;
    swap(maxheap1, maxheap2);
    maxheap1.;
}

/*
    cho hoán vị p[1..n] distin
    lấy p[l..r]. minpos = index min p[l..r], maxpos = index maxp[l..r]
    đếm số chuỗi con có: maxPos > minPos

    solve(1..n) = solve(1..mid) + solve(mid+1..r) + more

    more:
    5 3 6 1 4 2
    -> min trái, max phải;
    => cặp đc thêm vào thỏa mãn: min trái phải là min của 2 bên, max phải là max 2 bên
th1: max min bên trái
    sufMinL,sufMaxL
    preMinR,preMaxR
    ---
    (li,ri) thỏa mãn:
        sufMaxL[li] > preMaxR[ri]
        sufMinL[li] < preMinR[ri]
        pos[sufMinL[li]] < pos[sufMaxL[ri]]
    duyệt li: mid->l
    nếu xác định đc ri max có thể thỏa mãn
        sufMaxL[li] > preMaxR[ri]
        sufMinL[li] < preMinR[ri]
    thì mid+1->ri cũng thỏa mãn
        nếu  li giảm thì ri cũng giảm -> dùng 2 poiter
        li thỏa mãn: pos[sufMinL[li]] < pos[sufMaxL[ri]]
        more += j - (mid +1) +1 = j - mid;
    tình huống 2: giống tình huống 1:
    tình huống 3: min bên trái, max bên phải
        sufMaxL[li] < preMaxR[ri]
        sufMinL[li] < preMinR[ri]
    FOR j: mid + 1 ->  r
        tìm vị trí x xa nhất thỏa mãn:
        tìm vị trí y gần nhất thỏa mãn:
        cnt+= (x-y+1);

    */