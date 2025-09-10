#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef long long ll;
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, a, b;
    cin >> n >> a >> b;
    vector<pair<int, int>> arr(n);
    for (auto &[dis, tree] : arr)
        cin >> dis >> tree;
    sort(arr.begin(), arr.end());
    int l = 0;
    int tung = 0, truc = 0, ans = INFINITY;

    ///////////////////////
    for (int r = 0; r < n; r++)
    {
        arr[r].ss == 1 ? tung++ : truc++;

        while (tung >= a && truc >= b)
        {
            ans = min(ans, arr[r].ff - arr[l].ff);
            arr[l].ss == 1 ? tung-- : truc--;
            l++;
        }
    }
    cout << ans;
}
// sort {dis,type}
/*
    nhận xét: vị trí của cây k đc xắp sếp-> ta sắp xếp tăng dần
    nhận xét: nếu khoảng l->r đủ a cây tùng và b cây trúc thì những đoạn phủ không có ý nghĩa
    với mỗi r, tìm l gần nhất sao cho vẫn đủ tùng và trúc.
    tung là số lượng tùng, truc là số lượng trúc.
 */