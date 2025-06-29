#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6 + 5;
bool is_prime[MAX_N];
int prefix[MAX_N];
long long sumK[8][MAX_N]; // K từ 1..7, lưu prefix sum của cntK

void sieve()
{
    fill(is_prime, is_prime + MAX_N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX_N; i++)
        if (is_prime[i])
            for (int j = i * i; j <= MAX_N; j += i)
                is_prime[j] = false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int q;
    cin >> q;

    // B1: sàng nguyên tố
    sieve();

    // B2: tính prefix số nguyên tố
    for (int i = 1; i <= MAX_N; i++)
        prefix[i] = prefix[i - 1] + is_prime[i];

    // B3: tiền xử lý cntK và sumK cho K = 1..7
    for (int K = 1; K <= 7; K++)
    {
        unordered_map<int, int> freq; // freq của prefix_count
        freq[0] = 1;                  // prefix[0]=0 xuất hiện 1 lần
        for (int i = 1; i <= MAX_N; i++)
        {
            int target = prefix[i] - K;
            if (freq.count(target))
                sumK[K][i] = sumK[K][i - 1] + freq[target];
            else
                sumK[K][i] = sumK[K][i - 1];
            freq[prefix[i]]++;
        }
    }

    // B4: trả lời q truy vấn
    while (q--)
    {
        int a, b, k;
        cin >> a >> b >> k;
        if (k > 7)
        {
            cout << "0\n";
            continue;
        } // k > max K → không có đoạn nào
        long long ans = sumK[k][b] - sumK[k][a - 1];
        cout << ans << '\n';
    }

    return 0;
}
