#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define lim 100'000'000 //
typedef pair<int, int> pii;
typedef long long ll;
int n;
pii a[10'005];
bool check(int x)
{
    // kiểm tra xem với x thời gian có thỏa mãn
    priority_queue<pii, vector<pii>, greater<pii>> canMove;
    priority_queue<int, vector<int>, greater<int>> s;
    for (int i = 1; i <= n; i++)
    {
        auto [ci, ti] = a[i];
        int move = x / ti;
        int l = max(ci - move, 1);
        int r = min(ci + move, n);
        canMove.push({l, r});
    }
    for (int i = 1; i <= n; i++)
    {
        while (!canMove.empty() && canMove.top().ff == i)
        {
            s.push(canMove.top().ss);
            canMove.pop();
        }
        if (!s.empty() && s.top() >= i)
            s.pop();
        else
            return false;
    }
    return true;
}
void binary_search()
{
    int lo = 1, hi = lim;
    int ans;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            // cout << ans << "\n";
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    cout << ans;
};
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].ff >> a[i].ss;
    binary_search();
}
/*
    dùng binary rearch dựa trên kết quả:
    ti ≤ 10000;n ≤ 10000=> thời gian đối đa để cs đi n ô là 10^8;
    li=1;hi=10^8;
    mid = (lo+hi)/2
        nếu thời gian mid mà cảnh sát có thể đi đến các vị trí thỏa mãn xét mid nhỏ hơn
        nếu không xét mid lớn hơn
    cảnh sát có thể đi đến các vị trí thỏa mãn trong thời gian mid không:
        b1: ta tính phạm vi di chuyển của mỗi cảnh sát trong thời gian t=10s
            5 10-> [4,6]
            3 10->  [2,4]
            3 20-> [3,3]
            2 9-> [1 4]
            2 15-> [2,2]
        B2: sort các số trên: để lần lượt lấy min
            [1 4]
            [2,2]
            [2,4]
            [3,3]
            [4,6]
            i:1->n: if(a.key==i)thêm vào queue
                1: q={4};-> min đi đc đến 4: lấy 4 ra;
                2: q={2,4}-> 2 là min lấy 2 ra;
                3: q={4,3}-> 3 là min lấy 3 ra;
                4: q={4,6}-> lấy 4 ra;
                5:........-> lấy 6 ra và kết thúc;
                ---------------------------------
                nếu không thỏa mãn:
                vd: 4: q={3,5}:min =3<4 cảnh sát không đi đến ô đó đc.
        => lưu trữ cần lấy ra đc min => min_heap;
        lưu trữ vị trí cảnh sát có thể đi, lấy đc {xi,yi} vị trí min-> min_heap
    độ phức tạo O(27*nlog(n))
*/
