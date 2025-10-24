#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int k, n;
    int a, b;
    cin >> n >> k; // n film,k người
    vector<pii> film(n);
    for (auto &[a, b] : film)
        cin >> a >> b;
    sort(film.begin(), film.end(), [](auto x, auto y)
         { return x.ss < y.ss; });
    multiset<int> store;
    for (int i = 0; i < k; ++i)
        store.insert(0);
    int sum = 0;
    for (auto &[a, b] : film)
    {
        auto it = store.upper_bound(a);
        // nếu tất cả store đều >= a thì sẽ trả về  st.begin();
        if (it == store.begin())
            continue;
        it--; // đây là store[j]<ai;
        store.erase(it);
        store.insert(b);
        sum++;
    }
    cout << sum;
}
/*
    có n bộ phim (a,b) và k người xem: a là bắt đầu và b là kết thúc
        - 2  người k xem chung 1 bộ phim.
        - 1 người chỉ được xem phim khi b(i+1)>a(i)
        - tinh tổng số film k người có thể xem
    1 5
    8 10
    3 6
    2 5
    6 9
    nhận xét: ban đầu sort theo thời gian kết thúc b sẽ có lợi hơn:
    1 5
    2 5
    3 6
    7 9
    8 10
    cần 1 nơi lưu trữ thời gian kết thúc lớn nhất của k người:
    store: bắt đầu [0,0,0]// lưu thời gian kết thúc bộ phim
    1 5: [5,0,0]  tìm store[j]<=ai; thay store[j]=bi,số phim++
    2 5: [5,5,0]  tìm store[j]<=ai; thay store[j]=bi,số phim++
    3 6: [5,5,6]  tìm store[j]<=ai; thay store[j]=bi,số phim++
    7 9: [5,5,9]  tìm max store[j]<=ai; thay max(store[j])=bi,số phim++
    ...
    store có tính năng tìm max nhất < 1 số ; thêm, xóa=> dùng multiset
*/