#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
int n, num_query;
int a[100'005];
const int block = 320; // Tối ưu hơn
int step[100'005];
int last[100'005];

void initial()
{
    cin >> n >> num_query;
    FOR(i, 1, n)
    {
        cin >> a[i];
    }

    FORD(i, n, 1)
    {
        int block_end = ((i - 1) / block + 1) * block; // Tính 1 lần
        int next = i + a[i];

        if (next > n || next > block_end)
        {
            last[i] = i;
            step[i] = 0;
        }
        else
        {
            last[i] = last[next];
            step[i] = step[next] + 1;
        }
    }
}

void update(int pos, int val)
{
    a[pos] = val;
    int block_start = (pos - 1) / block * block + 1;
    int block_end = block_start + block - 1;

    FORD(i, pos, block_start)
    {
        int next = i + a[i];

        if (next > n || next > block_end)
        {
            last[i] = i;
            step[i] = 0;
        }
        else
        {
            last[i] = last[next];
            step[i] = step[next] + 1;
        }
    }
}

void get(int pos)
{
    int jump = 0;

    while (pos <= n)
    {
        jump += step[pos];
        pos = last[pos];

        int next = pos + a[pos];
        if (next > n)
        {
            cout << pos << ' ' << jump + 1 << '\n';
            return;
        }

        jump++;
        pos = next;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    initial();

    while (num_query--)
    {
        int type, pos, val;
        cin >> type;

        if (type == 1)
        {
            cin >> pos;
            get(pos);
        }
        else
        {
            cin >> pos >> val;
            update(pos, val);
        }
    }
}