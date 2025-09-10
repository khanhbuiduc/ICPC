# Chia để trị (Divide and Conquer)

**Chia để trị** là một lớp bài toán được giải bằng cách sử dụng đệ quy. Đây là lớp bài toán con của những bài toán đệ quy, trong đó ta cần giải bài toán hiện tại dựa vào lời giải của các bài toán con nhỏ hơn có cùng tính chất.

## Quy trình giải bài toán chia để trị

Để giải bài toán chia để trị, ta cần định nghĩa bài toán dựa trên 4 bước:

1. **Bước 1:** Định nghĩa bài toán hiện tại
2. **Bước 2:** Giải bài toán với trường hợp nhỏ nhất (base case)
3. **Bước 3:** Xác định đáp án bài toán
4. **Bước 4:** Tìm cách giải bài toán hiện tại dựa trên bài toán con

### Ví dụ: Tính tổng 1→N

```cpp
// B1: sum(N) là bài toán nhằm mục đích tính tổng 1→N
// B2: n=0 trả về 0
// B3: đáp án sum(N)
// B4: sum(N) = sum(N-1) + N

int sum(int N) {
    if (N == 0) return 0;      // Base case
    return sum(N-1) + N;       // Recursive case
}
```

## Các thuật toán sử dụng chia để trị

- **Thuật toán sắp xếp:** Merge Sort, Quick Sort
- **Cấu trúc dữ liệu:** Heap, Binary Search Tree
- **Tìm kiếm:** Binary Search
- **Thuật toán số học:** Fast Exponentiation

---

## 1. Lũy thừa nhanh (Fast Exponentiation)

**Bài toán:** Tính a^b mod (10^9 + 7)

### Các phép toán modulo cơ bản:

```cpp
const int MOD = 1e9 + 7;

// Phép cộng: (a + b) % M = (a % M + b % M) % M
// Phép trừ: (a - b) % M = (a % M - b % M + M) % M
// Phép nhân: (a * b) % M = ((a % M) * (b % M)) % M
// Phép chia: a / b mod M = a * (b^(M-2)) mod M (Fermat's Little Theorem)
```

### Thuật toán:

```cpp
long long power(long long x, long long n) {
    if (n == 0) return 1;                    // B2: Base case

    if (n % 2 == 1) {                        // B4: n lẻ
        return (power(x, n-1) * x) % MOD;
    } else {                                 // n chẵn
        long long ret = power(x, n/2);
        return (ret * ret) % MOD;
    }
}
```

**Độ phức tạp:** O(log n)

---

## 2. WC1: Tích tất cả trừ chính nó

**Bài toán:** Cho n và dãy a, tính a[1] + ... + a[n-1] / a[i] cho mỗi i.

### Ý tưởng ngây thơ (O(n²)):

```cpp
// Không hiệu quả
for (int i = 1; i <= n; i++) {
    long long ans = 1;
    for (int j = 1; j <= n; j++) {
        if (i != j) {
            ans = (ans * a[j]) % MOD;
        }
    }
    result[i] = ans;
}
```

### Ý tưởng đúng (O(n)):

```cpp
vector<long long> prefix(n+1), suffix(n+2);

// Tính prefix: prefix[i] = a[1] * a[2] * ... * a[i]

// Tính suffix: suffix[i] = a[i] * a[i+1] * ... * a[n]

// Kết quả cho a[i] = prefix[i-1] * suffix[i+1]
```

### Lưu ý về overflow:

```cpp
// SAI: có thể bị tràn số
int a = (int)b * (int)c % MOD;  // int * int có thể tràn trước khi gán vào long long

// ĐÚNG:
long long a = 1ll * b * c % MOD;
```

---

## 3. SC4: Tính tổng cấp số nhân

**Bài toán:** Cho 3 số nguyên x, N, M. Tính (1 + x + x² + x³ + ... + x^N) mod M

### Phân tích toán học:

Gọi S = 1 + x + x² + ... + x^N

Ta có: x × S - S = x^(N+1) - 1
⟹ S = (x^(N+1) - 1) / (x - 1)

### Thuật toán chia để trị:

**Nhận xét:**

- Nếu N lẻ: S(N) = S(N/2) × (1 + x^(N/2+1))
- Nếu N chẵn: S(N) = S(N-1) + x^N

```cpp
long long calc(long long x, long long N) {
    if (N == 0) return 1;                    // B2: Base case

    if (N % 2 == 0) {                        // N chẵn
        return (calc(x, N-1) + power(x, N)) % MOD;
    } else {                                 // N lẻ
        long long ret = calc(x, N/2);
        long long multiplier = (1 + power(x, N/2 + 1)) % MOD;
        return (ret * multiplier) % MOD;
    }
}
```

### Ví dụ với N = 9:

```
S(9) = 1 + x + x² + x³ + x⁴ + x⁵ + x⁶ + x⁷ + x⁸ + x⁹
     = (1 + x + x² + x³ + x⁴) + x⁵×(1 + x + x² + x³ + x⁴)
     = S(4) × (1 + x⁵)
```

**Độ phức tạp:** O(log N)

---

## Tóm tắt

**Chia để trị** là một kỹ thuật mạnh mẽ để:

- Giảm độ phức tạp từ O(n) xuống O(log n)
- Giải quyết các bài toán có cấu trúc đệ quy tự nhiên
- Tối ưu hóa các phép toán số học lớn

**Template cơ bản:**

```cpp
ReturnType divideConquer(InputType input) {
    if (baseCase(input)) {
        return baseSolution(input);
    }

    auto subproblems = divide(input);
    auto results = solveSubproblems(subproblems);
    return combine(results);
}
```
