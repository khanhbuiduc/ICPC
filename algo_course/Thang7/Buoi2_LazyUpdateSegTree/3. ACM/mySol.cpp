#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxP = 4 * 50005;

struct Node
{
    long long lazyValue = 0;
    long long sum = 0;
};

Node it[35][maxP];
vector<int> listPrimes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149};

ll powMod(ll a, ll b, int MOD)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void build(int j, int index, int L, int R)
{
    it[j][index] = {0, 0};
    if (L == R)
    {
        return;
    }
    int mid = (L + R) / 2;
    build(j, 2 * index, L, mid);
    build(j, 2 * index + 1, mid + 1, R);
}

void lazyUpdate(int j, int index, int L, int R)
{
    if (it[j][index].lazyValue != 0 && L < R)
    {
        int mid = (L + R) / 2;
        it[j][2 * index].lazyValue += it[j][index].lazyValue;
        it[j][2 * index].sum += 1ll * (mid - L + 1) * it[j][index].lazyValue;
        it[j][2 * index + 1].lazyValue += it[j][index].lazyValue;
        it[j][2 * index + 1].sum += 1ll * (R - mid) * it[j][index].lazyValue;
    }
    it[j][index].lazyValue = 0LL;
}

void update(int j, int index, int L, int R, int l, int r, long long k)
{
    lazyUpdate(j, index, L, R);
    if (L > r || l > R)
    {
        return;
    }
    if (l <= L && R <= r)
    {
        it[j][index].lazyValue += k;
        it[j][index].sum += 1ll * (R - L + 1) * k;
        lazyUpdate(j, index, L, R);
        return;
    }
    int mid = (L + R) / 2;
    update(j, 2 * index, L, mid, l, r, k);
    update(j, 2 * index + 1, mid + 1, R, l, r, k);
    it[j][index].sum = it[j][2 * index].sum + it[j][2 * index + 1].sum;
}

long long get(int j, int index, int L, int R, int l, int r)
{
    lazyUpdate(j, index, L, R);
    if (L > r || l > R)
    {
        return 0LL;
    }
    if (l <= L && R <= r)
    {
        return it[j][index].sum;
    }
    int mid = (L + R) / 2;
    long long sumLeft = get(j, 2 * index, L, mid, l, r);
    long long sumRight = get(j, 2 * index + 1, mid + 1, R, l, r);
    return sumLeft + sumRight;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numTest;
    cin >> numTest;

    for (int testCase = 1; testCase <= numTest; testCase++)
    {
        int n, numQueries;
        cin >> n >> numQueries;

        for (int j = 0; j < 35; j++)
        {
            build(j, 1, 1, n);
        }

        for (int query = 1; query <= numQueries; query++)
        {
            int type, L, R;
            cin >> type >> L >> R;

            if (type == 0)
            {
                long long mod;
                cin >> mod;
                long long ans = 1LL;

                for (int j = 0; j < 35; j++)
                {
                    if (L <= R)
                    {
                        (ans *= powMod(listPrimes[j], get(j, 1, 1, n, L, R), mod)) %= mod;
                    }
                    else
                    {
                        (ans *= powMod(listPrimes[j], get(j, 1, 1, n, L, n), mod)) %= mod;
                        (ans *= powMod(listPrimes[j], get(j, 1, 1, n, 1, R), mod)) %= mod;
                    }
                }
                cout << ans << "\n";
            }
            else if (type == 1)
            {
                int X;
                cin >> X;
                if (X == 1)
                    continue;

                for (int j = 0; j < 35; j++)
                {
                    int cnt = 0;
                    int temp = X;
                    while (temp % listPrimes[j] == 0)
                    {
                        cnt++;
                        temp /= listPrimes[j];
                    }
                    if (cnt > 0)
                    {
                        if (L <= R)
                        {
                            update(j, 1, 1, n, L, R, cnt);
                        }
                        else
                        {
                            update(j, 1, 1, n, L, n, cnt);
                            update(j, 1, 1, n, 1, R, cnt);
                        }
                    }
                }
            }
            else
            {
                int Y;
                cin >> Y;
                if (Y == 1)
                    continue;

                for (int j = 0; j < 35; j++)
                {
                    int cnt = 0;
                    int temp = Y;
                    while (temp % listPrimes[j] == 0)
                    {
                        cnt++;
                        temp /= listPrimes[j];
                    }
                    if (cnt > 0)
                    {
                        if (L <= R)
                        {
                            update(j, 1, 1, n, L, R, -cnt);
                        }
                        else
                        {
                            update(j, 1, 1, n, L, n, -cnt);
                            update(j, 1, 1, n, 1, R, -cnt);
                        }
                    }
                }
            }
        }
    }

    return 0;
}