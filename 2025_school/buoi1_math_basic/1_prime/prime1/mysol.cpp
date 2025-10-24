#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> primes;
vector<ll> ans;
void sieve(int n)
{
    vector<char> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int p = 2; 1ll * p * p <= n; ++p)
        if (is_prime[p])
            for (ll j = 1ll * p * p; j <= n; j += p)
                is_prime[j] = false;
                
    for (int i = 2; i <= n; ++i)
        if (is_prime[i])
            primes.push_back(i);
    return;
}

void segment_sieve(ll L, ll R)
{
    int len = R - L + 1;
    vector<char> is_prime(len, true); // is_prime[i] = true thì i+L là prime

    if (L == 1)
        is_prime[0] = false;

    for (int p : primes)
    {
        ll pp = 1LL * p * p;
        ll lp = ((L + p - 1) / p) * 1LL * p;
        if (pp > R)
            break;
        ll start = max(pp, lp); // bội đầu tiên của p trong [L..R]
        for (ll j = start; j <= R; j += p)
            is_prime[j - L] = false;
    }

    for (int i = 0; i < len; ++i)
        if (is_prime[i])
            ans.push_back(L + i);
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        ll L, R;
        cin >> L >> R;
        primes.clear();
        ans.clear();

        int limit = sqrt(R) + 1;

        sieve(limit);
        segment_sieve(L, R);
        for (ll p : ans)
            cout << p << " ";
        cout << endl;
    }
}
// primes: lưu trữ số nguyên tố 1-> căn R
/*
duyệt từng số nguyên tố < căn n.
    isPrime[i] = true, số i + L là Prime;
    xét đoạn L->R.
        start =  [L..R] (max(p*p, |L/p|*p))
        duyệt j = start; j<= R; j+=p
            is_primeLR[j - L] = false
        FOR(i,start,R)
            nếu is_primeLR[i] thì lưu (i+L);
*/