# Bài 2: Các Thuật Toán Nâng Cao

## Bài toán AC4 (Autumn Contest 2020)

### Đề bài

Cho một bản nhạc gồm N nốt (Do - Re - Mi - Fa - Sol - La - Si). Một đoạn gọi là cao trào nếu đoạn đó gồm 3 nốt nhạc liên tục, trong đó nốt ở giữa có cao độ cao hơn hẳn 2 nốt còn lại hoặc nốt ở giữa có cao độ thấp hơn hẳn 2 nốt còn lại.

Một bản nhạc được gọi là hay nếu có tối thiểu M đoạn cao trào. Hỏi bản nhạc này có hay hay không?

### Thuật toán

**Mã hóa các nốt nhạc sang số:**

- Do = 0, Re = 1, ..., Si = 6

**Điều kiện cao trào:**
Xét 3 nốt i, i+1 và i+2, 3 nốt này tạo thành 1 đoạn cao trào nếu:

```cpp
(a[i+1] > a[i] && a[i+1] > a[i+2]) ||
(a[i+1] < a[i] && a[i+1] < a[i+2])
```

**Cài đặt:**

```cpp
int count = 0;
for (int i = 0; i < n-2; i++) {
    if ((a[i+1] > a[i] && a[i+1] > a[i+2]) ||
        (a[i+1] < a[i] && a[i+1] < a[i+2])) {
        count++;
    }
}
return count >= M;
```

## Bài toán: Video Cards

### Đề bài

Cho một dãy số nguyên dương a gồm N số a[1], a[2], ..., a[N].

Ta chọn một số a[i] nào đó và với các số a[j] còn lại, ta sẽ đưa số đó đến bội gần nhất của a[i] mà ≤ số đó.

Sau khi biến đổi, ta tính tổng của tất cả các số trong dãy.

Hỏi tổng lớn nhất có thể đạt được là bao nhiêu?

### Ví dụ

```
N = 6
a = [5, 2, 1, 9, 4, 6]

x = 2: [4, 2, 0, 8, 4, 6] = 24
x = 3: [3, 0, 0, 9, 3, 6] = 21
```

### Thuật toán

**Nhận xét:** 1 ≤ a[i] ≤ 200,000

**Bước 1:** Tạo count với ý nghĩa count[i] là số lượng số có giá trị ≤ i

```cpp
count[0] = 0
count[1] = 1  // số lượng số ≤ 1
count[2] = 2  // số lượng số ≤ 2
count[3] = 2  // số lượng số ≤ 3
count[4] = 3  // số lượng số ≤ 4
count[5] = 4  // số lượng số ≤ 5
count[6] = 5  // số lượng số ≤ 6
// ...
```

**Bước 2:** Biến đổi count thành prefix sum

```cpp
for (int i = 1; i <= 200000; i++) {
    count[i] += count[i-1];
}
```

**Bước 3:** Tính tổng cho mỗi x

```cpp
for (int x = 1; x <= 200000; x++) {
    long long sum = 0;
    for (int j = x; j <= 200000; j += x) {
        // Số lượng số có thể quy về j
        int cnt = count[j + x - 1] - count[j - 1];
        sum += j * cnt;
    }
    ans = max(ans, sum);
}
```

**Độ phức tạp:** O(N + N/2 + N/3 + ... + N/200000) = O(N log N)

### Bổ sung: Sàng nguyên tố Eratosthenes

```cpp
vector<bool> isPrime(1000001, true);
isPrime[1] = false;

for (int i = 2; i <= 1000000; i++) {
    if (isPrime[i]) {
        for (int j = 2 * i; j <= 1000000; j += i) {
            isPrime[j] = false;
        }
    }
}
```

## Bài toán: Good Key and Bad Key

### Đề bài

Cho N rương, rương thứ i có số đồng xu là a[i]. Ta có 2 loại chìa khóa, một loại là "good key" và loại còn lại là "bad key".

Ta phải mở rương lần lượt từ rương 1 → rương N.

**Quy tắc:**

- Nếu ta sử dụng "good key": ta sẽ mất một lượng đồng xu là C
- Nếu ta sử dụng "bad key" để mở rương i: tất cả các rương j (j: i → N), mỗi rương sẽ bị giảm số đồng xu một nửa và ta không mất xu

Hỏi: Số đồng xu tối đa ta có thể thu được là bao nhiêu?

### Ví dụ

```
a = [1, 5, 2, 5, 2, 1, 6, 3]
```

### Phân tích

**Nhận xét:** Do a[i] ≤ 1,000,000,000 → sau tối đa 30 lần chia đôi thì a[i] sẽ trở thành số 0

### Thuật toán

Gọi f[i][j] là tổng lượng đồng xu lớn nhất khi ta có i rương đầu tiên và ta đã sử dụng j bad key.

**Bài toán cơ sở:** f[0][0] = 0, khởi tạo các f[i][j] = -1

**Đáp án bài toán:** Max(f[N][j]) với j: 0 → 30

**Công thức QHĐ:**
Khi ta có f[i][j] ≠ -1, xét rương i + 1:

**Tình huống 1:** Rương i + 1 dùng good key

```cpp
f[i+1][j] = max(f[i+1][j], f[i][j] + (a[i+1] / power2[j]) - C)
```

với power2[i] = 2^i

**Tình huống 2:** Rương i + 1 dùng bad key

```cpp
f[i+1][min(j+1, 30)] = max(f[i+1][min(j+1, 30)], f[i][j] + a[i+1] / power2[min(j+1, 30)])
```

**Lưu ý:** Khi sử dụng 30 bad key rồi thì những rương sau không có bad key nữa mà chỉ sử dụng good key.

## Bài toán: Divisor Analysis

### Đề bài

Cho N cặp p[i], x[i] với ý nghĩa: Trong cách phân tích thừa số nguyên tố của số N nào đó, có sự tồn tại của p[i]^x[i] (p[i] là số nguyên tố).

Hãy xuất ra:

1. Số lượng ước số của số N
2. Tổng các ước số của số N
3. Tích các ước số của số N

Vì kết quả rất lớn, hãy xuất ra kết quả sau khi modulo cho 1,000,000,007.

### Ví dụ

```
Input:
3
2 3
3 1
7 1

N = 2³ × 3¹ × 7¹ = 168
```

168 có các ước: 1, 2, 3, 4, 6, 7, 8, 12, 14, 21, 24, 28, 42, 56, 84, 168 → 16 ước

### Phân tích

#### 1. Số lượng ước số

```
N = 2³ × 3¹ × 7¹
Số ước = (3 + 1) × (1 + 1) × (1 + 1) = 4 × 2 × 2 = 16
```

**Công thức tổng quát:** Tích của (x[i] + 1) với mọi i

#### 2. Tổng các ước số

Tổng các ước = (p[1]⁰ + p[1]¹ + p[1]² + ... + p[1]^x[1]) ×
(p[2]⁰ + p[2]¹ + ... + p[2]^x[2]) × ... ×
(p[k]⁰ + p[k]¹ + ... + p[k]^x[k])

**Tính tổng cấp số nhân:**

```
S = 1 + x + x² + ... + x^n           (1)
x×S = x + x² + x³ + ... + x^(n+1)    (2)

(2) - (1): (x - 1)×S = x^(n+1) - 1
⟹ S = (x^(n+1) - 1) / (x - 1)
```

#### 3. Tích các ước số

**Phân tích:**

- Xét riêng p[1]: số lần xuất hiện của p[1]⁰, p[1]¹, ..., p[1]^x[1] là như nhau và cùng bằng (x[2] + 1) × (x[3] + 1) × ... × (x[k] + 1)
- Xét riêng p[2]: số lần xuất hiện của p[2]⁰, p[2]¹, ..., p[2]^x[2] là như nhau và cùng bằng (x[1] + 1) × (x[3] + 1) × ... × (x[k] + 1)

**Số mũ của p[i] trong tích:**

```
Mũ của p[i] = (0 + 1 + 2 + ... + x[i]) × ∏(x[j] + 1) với j ≠ i
            = (x[i] × (x[i] + 1) / 2) × ∏(x[j] + 1) với j ≠ i
```

### Xử lý số mũ lớn với định lý Fermat nhỏ

**Định lý Fermat nhỏ:** Với M là số nguyên tố, với mọi số a (không chia hết cho M) thì a^(M-1) % M = 1

**Áp dụng:**

```cpp
x^N % M
N = d × (M - 1) + r
x^N = x^(d × (M-1) + r) = (x^(M-1))^d × x^r ≡ x^r (mod M)
```

**Thuật toán:**

1. Tính (x[1] + 1) × (x[2] + 1) × ... × (x[k] + 1) / (x[i] + 1) cho mỗi i
2. Tạo bảng prefix[i] = (x[1] + 1) × (x[2] + 1) × ... × (x[i] + 1) % (10⁹ + 6)
3. Tạo bảng suffix[i] = (x[k] + 1) × (x[k-1] + 1) × ... × (x[i] + 1) % (10⁹ + 6)
4. Tích khi bỏ (x[i] + 1) = (prefix[i-1] × suffix[i+1]) % (10⁹ + 6)

**Lưu ý:** Sử dụng MOD = 10⁹ + 6 cho việc tính số mũ vì 10⁹ + 7 - 1 = 10⁹ + 6
