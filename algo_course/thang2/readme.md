```cpp
//tìm x trong a
int binary_search(vector<int> a,int x)
{
    int lo = 1, hi = max;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (a[mid] == x)
            return mid;
        if (a[mid] < x)
            lo = mid + 1;
        else
            lo = mid - 1;
    }
    return -1;
}
//hàm đã sort
```

```cpp

//Nhận xét:

//Neu gioi hạn L đa thoa man chia duoc thi nhung gioi han L' > L cung se chia được.
//Neu gioi hạn L đa khong chia duợc thì nhung gioi han L' < L cung se khong chia dược.
void binary_search_on_answer()
{
    int li = 0, hi = lim;
    int ans = 0;
    while (li <= hi)
    {
        int mid = (li + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            li = mid + 1;
        }
        else
            hi = mid - 1;
    }
    cout << ans << "\n";
}
```

```cpp
void ternary_search()
{
    double lo = -10'005, hi = 10'005;
    int step = 500;
    while (step--)
    {
        double u = (2 * lo + hi) / 3
        double v = (2 * hi + lo) / 3;
        if (f(u) >= f(v))
            lo = u;
        else
            hi = v;
    }
    cout << fixed << setprecision(15) << f(lo);
}
```
