#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int64_t num, res = 0;
    n--;
    for (int i = 0; i <= n; i++)
    {
        cin >> num;
        // if nCk is lẻ nếu không tồn tại
        if (!(i & (~n))) // bít 1 trong i mà tương ứng bit 0 trong n
            continue;
        res ^= num;
    }
    cout << res;
}