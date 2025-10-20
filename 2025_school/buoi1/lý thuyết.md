toán cơ bản:

1. số nguyên tố và sàng eratosthenes
   bài 2.2: cho N - phân tích N thành số nguyên tố - đếm số ước của N - tính tổng các ước của N

```cpp
//sieve of Eratosthenes
bool is_prime[100001];
vector<int> primes;
vector<int> sieve(int n) {
    fill(is_prime, is_prime + n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}
```

2. gcd và lcm:
3. tập hợp
4. fibonacci
5. catalan
6. sử lý số lớn:
