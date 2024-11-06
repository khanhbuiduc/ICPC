#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tiii;

int main()
{
    freopen("hunting_dog.inp", "r", stdin);
    freopen("hunting_dog.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<tiii> dogs(n);
    for (auto &dog : dogs)
    {
        int w, i, v;
        cin >> w >> i >> v;
        dog = {w, i, v};
    }
    sort(dogs.begin(), dogs.end(), [](const tiii &a, const tiii &b)
         {
             if (get<0>(a) != get<0>(b))
                 return get<0>(a) > get<0>(b);
             return get<1>(a) < get<1>(b); });

    int max_sum = 0;

    // Duyệt qua từng cặp chó liên tiếp để tìm tổng giá trị lớn nhất
    for (int p = 0; p < n - 1; ++p)
    {
        int w1 = get<0>(dogs[p]), i1 = get<1>(dogs[p]), v1 = get<2>(dogs[p]);
        int w2 = get<0>(dogs[p + 1]), i2 = get<1>(dogs[p + 1]), v2 = get<2>(dogs[p + 1]);

        // Kiểm tra điều kiện để chọn cặp chó này
        if (w1 >= w2 && i1 <= i2)
        {
            max_sum = max(max_sum, v1 + v2);
        }
    }
    cout << max_sum << endl;
    return 0;
}
