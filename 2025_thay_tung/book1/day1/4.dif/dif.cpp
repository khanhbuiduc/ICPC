#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int L, t;
    cin >> L >> t;
    cout << (2 * t - L);
}

/*
Đề bài:
người 1: a lít
người 2: b lít

gọi a>=b

tăng L lít trong  t giây
tốc độ đổ: 1 lít/s

--------------
n = 42; t= 24

thời gian t:
    a = t
    a + b = L
=> a - b = 2*t - L;
*/