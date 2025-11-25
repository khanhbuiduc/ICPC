# Tháng 5: Tổng Hợp Thuật Toán

## 1. Combinatorics (Tổ Hợp)

### Công thức cơ bản

**Tổ hợp:** C(k,n) = n! / [k! × (n-k)!]

### Các phép MOD

#### Phép toán cơ bản với MOD

```cpp
// Phép cộng
(a + b) % M = (a % M + b % M) % M

// Phép trừ
(a - b) % M = (a % M - b % M + M) % M

// Phép nhân
(a × b) % M = ([a % M] × [b % M]) % M

// Phép chia (với M là số nguyên tố)
1/a % M = a^(M-2) % M

// Phép mũ: sử dụng hàm powMod
```

#### Hàm lũy thừa nhanh

```cpp
typedef long long ll;
const int MOD = 1000000007;

ll powMod(ll a, ll b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            (res *= a) %= MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
```

### Bài toán: Chia kẹo Euler

#### Đề bài

Có N viên kẹo và có M đứa nhỏ. Hỏi có bao nhiêu cách để chia toàn bộ N viên cho M đứa nhỏ sao cho mỗi đứa phải có kẹo?

#### Ví dụ

```
N = 4, M = 3
o | o | o | o o o
```

#### Công thức

**Số cách chia:** C(N-1, M-1)

#### Cài đặt tính C(n,k) % MOD

```cpp
typedef long long ll;
const int MAXN = 2000005;
const int MOD = 1000000007;

ll fact[MAXN], inv_fact[MAXN];

ll powMod(ll a, ll b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void pre_calculator() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    inv_fact[MAXN - 1] = powMod(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

ll C(ll n, ll k) {
    if (k > n || k < 0) return 0;
    return (((fact[n] * inv_fact[k]) % MOD) * inv_fact[n - k]) % MOD;
}
```

---

## 2. Lý Thuyết Trò Chơi

### Các định nghĩa state trong Dynamic Programming

#### State cơ bản

```cpp
// f[i]: khả năng thắng - thua của người hiện tại khi có i viên sỏi
bool f[i];

// f[i][j]: trạng thái thắng hoặc thua khi người hiện tại chơi vào bảng có i hàng và j cột
bool f[i][j];
```

#### State nâng cao

```cpp
// f[i][a][b]: tổng điểm lớn nhất có thể khi có i lá bài đầu tiên
// a: số lượng lá addition mà người hiện tại đang có
// b: số lượng lá addition mà người đối thủ đang có
int f[i][a][b];

// f[i][a][b]: tổng lượng hạt dẻ tối đa mà người hiện tại có thể bốc được
// i: số hạt dẻ hiện tại
// a: số hạt trong tô của người hiện tại
// b: số hạt trong tô của người đối thủ
int f[i][a][b];
```

### Nguyên tắc chung

1. **Người chơi tối ưu:** Cả hai người đều chơi với chiến thuật tối ưu nhất
2. **Trạng thái thắng/thua:** Xác định trạng thái thắng và thua dựa trên các nước đi có thể
3. **Chuyển trạng thái:** Từ trạng thái hiện tại, xét tất cả các nước đi có thể

---

## 3. Một Số Định Lý Quan Trọng

### Nguyên lý Dirichlet

**Phát biểu:** Có 4 con thỏ và muốn nhốt chúng vào 3 cái chuồng, chắc chắn phải có 1 chuồng có ít nhất 2 con.

**Tổng quát:** Nếu có n đối tượng được phân vào m nhóm với n > m, thì ít nhất một nhóm chứa nhiều hơn 1 đối tượng.

**Ứng dụng:**

- Chứng minh sự tồn tại của nghiệm
- Bài toán về số dư
- Bài toán về tổng con dãy chia hết cho k
