
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
vector<int> a, b;
int sum, k, n;
bool f[200'005][31];
int trace[200'005][31];

void print_arr(vector<int> v)
{
    cout << "YES" << endl;
    reverse(ALL(v));
    for (auto i : v)
    {
        cout << i << ' ';
    }
    cout << endl;
}

void truy_vet(int s, int cnt)
{
    if (s == 0 && cnt == 0)
        return;

    int val = trace[s][cnt];
    if (val > 0)
    {
        a.push_back(val);
        truy_vet(s - val, cnt - 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> sum >> k;

    for (int x = 1; x * x <= sum; x++)
    {
        int val = sum - x * x;
        if (val > 0)
            b.push_back(val);
    }

    sort(ALL(b));
    b.erase(unique(ALL(b)), b.end());
    n = b.size();

    // Khởi tạo
    memset(f, false, sizeof(f));
    memset(trace, 0, sizeof(trace));

    // Base case
    f[0][0] = true;

    // Quy hoạch động
    FOR(i, 0, n - 1) // n là size của b 450*200k*30
    FOR(s, 0, sum)
    FOR(cnt, 0, k)
    {
        if (f[s][cnt] == false)
            continue;

        // Nếu sử dụng b[i]
        if (s + b[i] <= sum && cnt + 1 <= k)
        {
            if (!f[s + b[i]][cnt + 1])
            {
                f[s + b[i]][cnt + 1] = true;
                trace[s + b[i]][cnt + 1] = b[i];
            }
        }
    }

    // Kiểm tra kết quả
    if (f[sum][k])
    {
        truy_vet(sum, k);
        print_arr(a);
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
/*
// tách n thành a[1..k] sao cho:
    sum(a[1..k]) - a[i] = x^2 với mọi a[i]
---
=>
a[i] = n - x^2
duyệt x: 1-> căn n
    lưu n - x^2 vào b;
---
bài toán trở thành:
    tìm subset b[] sao cho sum = n
---
gọi f[i][s][cnt] = true/false
    i pt đầu tiên của b
    tổng = s
    đã sử dụng cnt số.
do i<=450, s<=2*10^5, cnt<=30
nên
tách f[i][s][cnt] thành

    f[s][cnt] = true/false
    trace[s][cnt] = b[i]
n=b.length();
---
btcs
    f[0][0] = true
    trace[0][0] = 0;

for i,0,n-1
for s,0,sum
for cnt, 0, k
    nếu f[s][cnt] == true
    sử dụng b[i+1]
        f[s+b[i+1]][cnt]
*/